#
# Copyright (C) 2012 Christoph Thelen
# Copyright (C) 2008 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk

PKG_NAME:=dmx_usb_module
PKG_VERSION:=0.4
PKG_REV:=74a4067667b4d009d33ce7f52045786735b0a137
PKG_SOURCE_URL:=git://github.com/lowlander/dmx_usb_module.git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_PROTO:=git

include $(INCLUDE_DIR)/package.mk

define KernelPackage/dmx_usb_module
	SUBMENU:=USB Support
	TITLE:=DMX USB Module for the FTDI RS485 USB chip
	FILES:=$(PKG_BUILD_DIR)/dmx_usb.$(LINUX_KMOD_SUFFIX)
	AUTOLOAD:=$(call AutoLoad,65,dmx_usb)	
	KCONFIG:=
endef

define KernelPackage/dmx_usb_module/description
	Modul to communicate with a DMX Dongle
	based on the FTDI RS485 USB chip.
endef

EXTRA_KCONFIG:= \
	
EXTRA_CFLAGS:= \
	

DMX_MAKE_OPTS:= -C $(PKG_BUILD_DIR) \
	PATH="$(TARGET_PATH)" \
	ARCH="$(LINUX_KARCH)" \
	CROSS_COMPILE="$(TARGET_CROSS)" \
	TARGET="$(HAL_TARGET)" \
	TOOLPREFIX="$(KERNEL_CROSS)" \
	TOOLPATH="$(KERNEL_CROSS)" \
	KERNELPATH="$(LINUX_DIR)" \
	LDOPTS=" " \
	EXTRA_CFLAGS="$(EXTRA_CFLAGS)" \
	$(EXTRA_KCONFIG)

define Build/Compile
	$(MAKE) $(DMX_MAKE_OPTS) M=$(PKG_BUILD_DIR) modules
endef

$(eval $(call KernelPackage,dmx_usb_module))
