#include <linux/compiler.h>
#include <linux/dmi.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/wmi.h>

int clevo_dmi_matched(const struct dmi_system_id* dmi_id)
{
	int status = 0;

	pr_info("Model %s detected\n", dmi_id->ident);

	return status;
}

const struct dmi_system_id clevo_dmi_table[] __initconst = {
	{
		.ident = "Clevo P870DM",
		.matches = {
			DMI_MATCH(DMI_PRODUCT_NAME, "P870DM"),
		},
		.callback = clevo_dmi_matched,
	},
	{
		.ident = "Clevo P7xxDM(-G)",
		.matches = {
			DMI_MATCH(DMI_PRODUCT_NAME, "P7xxDM(-G)"),
		},
		.callback = clevo_dmi_matched,
	},
	{
		.ident = "Clevo P750ZM",
		.matches = {
			DMI_MATCH(DMI_PRODUCT_NAME, "P750ZM"),
		},
		.callback = clevo_dmi_matched,
	},
	{
		.ident = "Clevo P370SM-A",
		.matches = {
			DMI_MATCH(DMI_PRODUCT_NAME, "P370SM-A"),
		},
		.callback = clevo_dmi_matched,
	},
	{
		.ident = "Clevo P17SM-A",
		.matches = {
			DMI_MATCH(DMI_PRODUCT_NAME, "P17SM-A"),
		},
		.callback = clevo_dmi_matched,
	},
	{
		.ident = "Clevo P15SM1-A",
		.matches = {
			DMI_MATCH(DMI_PRODUCT_NAME, "P15SM1-A"),
		},
		.callback = clevo_dmi_matched,
	},
	{
		.ident = "Clevo P15SM-A",
		.matches = {
			DMI_MATCH(DMI_PRODUCT_NAME, "P15SM-A"),
		},
		.callback = clevo_dmi_matched,
	},
	{
		.ident = "Clevo P17SM",
		.matches = {
			DMI_MATCH(DMI_PRODUCT_NAME, "P17SM"),
		},
		.callback = clevo_dmi_matched,
	},
	{
		.ident = "Clevo P15SM",
		.matches = {
			DMI_MATCH(DMI_PRODUCT_NAME, "P15SM"),
		},
		.callback = clevo_dmi_matched,
	},
	{
		.ident = "Clevo P150EM",
		.matches = {
			DMI_MATCH(DMI_PRODUCT_NAME, "P150EM"),
		},
		.callback = clevo_dmi_matched,
	},
		{
		.ident = "Clevo P65_67RSRP",
		.matches = {
			DMI_MATCH(DMI_PRODUCT_NAME, "P65_67RSRP"),
		},
		.callback = clevo_dmi_matched,
	},
	{
		.ident = "Clevo P65xRP",
		.matches = {
			DMI_MATCH(DMI_PRODUCT_NAME, "P65xRP"),
		},
		.callback = clevo_dmi_matched,
	},
	{
		.ident = "Clevo P150EM",
		.matches = {
			DMI_MATCH(DMI_PRODUCT_NAME, "P15xEMx"),
		},
		.callback = clevo_dmi_matched,
	},
	{
		.ident = "Clevo P7xxDM2(-G)",
		.matches = {
			DMI_MATCH(DMI_PRODUCT_NAME, "P7xxDM2(-G)"),
		},
		.callback = clevo_dmi_matched,
	},
	{
		.ident = "Clevo P950HP6",
		.matches = {
			DMI_MATCH(DMI_PRODUCT_NAME, "P95_HP,HR,HQ"),
		},
		.callback = clevo_dmi_matched,
	},
	{
				.ident = "Clevo P95_HP",
				.matches = {
						DMI_MATCH(DMI_PRODUCT_NAME, "P95_HP"),
				},
				.callback = clevo_dmi_matched,
	
		},
	{
		.ident = "Clevo N850HJ",
		.matches = {
			DMI_MATCH(DMI_PRODUCT_NAME, "N85_N87"),
		},
		.callback = clevo_dmi_matched,
	},
	{
		.ident = "Clevo P775DM3(-G)",
		.matches = {
			DMI_MATCH(DMI_PRODUCT_NAME, "P775DM3(-G)"),
		},
		.callback = clevo_dmi_matched,
	},
	{
		.ident = "Clevo N850HJ",
		.matches = {
			DMI_MATCH(DMI_PRODUCT_NAME, "N85_N87"),
		},
		.callback = clevo_dmi_matched,
	},
	{
		.ident = "Clevo N870HK",
		.matches = {
			DMI_MATCH(DMI_PRODUCT_NAME, "N85_N87,HJ,HJ1,HK1"),
		},
		.callback = clevo_dmi_matched,
	},
  {
		.ident = "Clevo N870HP6",
		.matches = {
			DMI_MATCH(DMI_PRODUCT_NAME, "N85_87HP6"),
		},
		.callback = clevo_dmi_matched,
  },
	{
	.ident = "Clevo P65_67HSHP",
	.matches = {
		DMI_MATCH(DMI_PRODUCT_NAME, "P65_67HSHP"),
	},
	.callback = clevo_dmi_matched
  },
	/* Ones that don't follow the 'standard' product names above */
	{
		.ident = "Clevo P7xxDM(-G)",
		.matches = {
			DMI_MATCH(DMI_PRODUCT_NAME, "Deimos/Phobos 1x15S"),
		},
		.callback = clevo_dmi_matched,
	},
	{
		.ident = "Clevo P750ZM",
		.matches = {
			DMI_MATCH(DMI_PRODUCT_NAME, "P5 Pro SE"),
		},
		.callback = clevo_dmi_matched,
	},
	{
		.ident = "Clevo P750ZM",
		.matches = {
			DMI_MATCH(DMI_PRODUCT_NAME, "P5 Pro"),
		},
		.callback = clevo_dmi_matched,
	},
	{
		.ident = "Clevo P750ZM",
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "ECT"),
			DMI_MATCH(DMI_BOARD_NAME, "P750ZM"),
		},
		.callback = clevo_dmi_matched,
	},
	{
		.ident = "XMG A517",
		.matches = {
			DMI_MATCH(DMI_BOARD_NAME, "N85_87HP6"),
		},
		.callback = clevo_dmi_matched,
	},
	{
		.ident = "Clevo P7xxDM3(-G)",
		.matches = {
			DMI_MATCH(DMI_PRODUCT_NAME, "P7xxDM3(-G)"),
		},
		.callback = clevo_dmi_matched,
	},
	{ /* terminating NULL entry */ }
};

MODULE_DEVICE_TABLE(dmi, clevo_dmi_table);
