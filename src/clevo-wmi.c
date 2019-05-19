#define pr_fmt(fmt) KBUILD_MODNAME ": " fmt

#include <linux/dmi.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/wmi.h>

#include "clevo-wmi.h"

/*
	Use "sudo fwts wmi -" to see unsupported wmi commands
*/

// Function declarations
static int __init	check_wmi_functionality(const char* guid);
static int __init	clevo_init(void);
static int 			clevo_wmi_probe(struct platform_device* device);
static void			clevo_evaluate_wmi_method(clevo_method_id_t method_id,
												u32 arg,
												u32* return_value);
static int			clevo_wmi_remove(struct platform_device* device);
static void __exit	clevo_exit(void);

// Variable declarations
extern struct dmi_system_id 	clevo_dmi_table __initconst;
static struct platform_device	clevo_device = {
	.name	= KBUILD_MODNAME,
	.id		= PLATFORM_DEVID_NONE,

};
static struct platform_driver	clevo_driver = {
	.driver = {
		.name	= KBUILD_MODNAME,
		.owner	= THIS_MODULE,
	},
	.probe	= clevo_wmi_probe,
	.remove	= clevo_wmi_remove
};
static bool dmi_check = TRUE;


// Function definitions
static int __init check_wmi_functionality(const char* guid)
{
	int status = 0;

	if (!wmi_has_guid(guid))
	{
		pr_err("WMI GUID: %s not found\n", guid);
		status = -ENODEV;
	}

	return status;
}

static void clevo_evaluate_wmi_method(clevo_method_id_t method_id, u32 arg, u32* return_value)
{
	int status = 0;

	//TODO: Complete implementation
}

static int clevo_wmi_probe(struct platform_device* device)
{
	int status = 0;

	//status = wmi_install_notify_handler(clevo_event_guid, clevo_wmi_notice, NULL);
	pr_debug("WMI notification installation status: (%0#6x)", status);
	if(unlikely(status))
	{
		pr_err("Could not install WMI notification: (%0#6x)", status);
		goto report_status;
	}
	
	clevo_evaluate_wmi_method(GET_AP, 0, NULL);

report_status:
	return status;
}

static int clevo_wmi_remove(struct platform_device* device)
{
	int status = 0;

	platform_driver_unregister(&clevo_driver);

	return status;
}

//TODO: Use a platform_device, and then register a platform_driver to it.
static int __init clevo_init(void)
{
	int status = 0;
	
	pr_debug("Initializing %s kernel module\n", KBUILD_MODNAME);
	status = check_wmi_functionality(clevo_event_guid) | check_wmi_functionality(clevo_get_guid);
	if (status)
		goto report_status;

	if (dmi_check && (dmi_check_system(&clevo_dmi_table)))
	{
		pr_err("Device %s not supported\n", dmi_get_system_info(DMI_PRODUCT_NAME));
		status = -ENODEV;
		goto report_status;
	} else
	{
		// TODO: Format a pr_info with the relevant info needed to add to dmidecode table
		pr_warn("Bypassed DMI check, the driver may not support your device.\n");
		pr_info("Model '%s' detected\n", dmi_get_system_info(DMI_PRODUCT_NAME));
	}

	status = platform_driver_register(&clevo_driver);
	if (status)
	{
		pr_err("Driver was unable to be registered.\n");
		goto report_status;
	}

report_status:
	return status;
}

static void __exit clevo_exit(void)
{
	int status = 0;

	pr_debug("Exiting %s kernel module\n", KBUILD_MODNAME);
	status = clevo_wmi_remove(&clevo_device);
}

module_init(clevo_init)
module_exit(clevo_exit)
module_param(dmi_check, bool, 0000);

MODULE_AUTHOR("Karthik Jayakumar <valliyilkarthik@gmail.com>");
MODULE_DESCRIPTION("Clevo laptop keyboard led driver.");
MODULE_LICENSE("GPL");
MODULE_VERSION("1.0");
MODULE_PARM_DESC(dmi_check, "Controls the DMI check. (Default = TRUE)");