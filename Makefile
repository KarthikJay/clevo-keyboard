KERNEL_DIR ?= /lib/modules/$(shell uname -r)
SOURCE_DIR = $(CURDIR)/src
BUILD_DIR ?= $(CURDIR)/build
MODULE_NAME = clevo-keyboard
DMI_CHECK = yes

.PHONY: install uninstall setup clean
.IGNORE: setup uninstall

default: compile

setup:
	mkdir -p $(BUILD_DIR)
	ln -s $(CURDIR)/Makefile $(BUILD_DIR)/Makefile

compile: setup
	make -C $(KERNEL_DIR)/build M=$(BUILD_DIR) src=$(SOURCE_DIR) modules

# Need to run the following targets with root permissions
install:
	cp $(BUILD_DIR)/$(MODULE_NAME).ko $(KERNEL_DIR)/extra
	depmod -A
	modprobe $(MODULE_NAME) dmi_check=$(DMI_CHECK)

uninstall:
	modprobe -r $(MODULE_NAME)
	depmod -A

clean: uninstall
	rm -rf $(BUILD_DIR)
	rm -rf $(KERNEL_DIR)/extra/$(MODULE_NAME).ko