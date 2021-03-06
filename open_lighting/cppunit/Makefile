#
# Copyright (C) 2011 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=cppunit
PKG_VERSION:=1.12.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@SF/cppunit
PKG_MD5SUM:=bd30e9cf5523cdfc019b94f5e1d7fd19

include $(INCLUDE_DIR)/host-build.mk
include $(INCLUDE_DIR)/package.mk

define Package/cppunit_ola
  SECTION:=devel
  CATEGORY:=Development
  TITLE:=Unit Testing Library for C++ (Makefile with OLA Patch)
  URL:=http://cppunit.sourceforge.net/
  DEPENDS:=+libstdcpp
endef

define Package/cppunit_ola/description
  Unit Testing Library for C++
endef

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR) DESTDIR="$(PKG_INSTALL_DIR)" install
endef


#<PKG_INSTALL_DIR> Variable zeigt auf 
#<openwrt_build_basis>/build_dir/<ARCH>/<PKG_NAME>-<PKG_VERSION>/ipkg-install
#e.g. /usr/src/openwrt/build_dir/target-mips_r2_uClibc-0.9.33.2/cppunit-1.12.1/ipkg-install

#<2> Variable zeigt auf <openwrt_build_basis>/staging_dir/<ARCH>/host

#Die Anwendung cppunit-config wird nicht crosscompiled und muss
#daher in das Verzeichnis fuer die Anwendungen welche auf dem
#Hostsystem ausgefuehrt werden, kopiert werden.
#In diesem Fall ist dies das Verzeichnis
#/usr/src/openwrt/staging_dir/target-mips_r2_uClibc-0.9.33.2/host/bin
#Dieses wird vom Buildsystem auch in die PATH Variable mit eingebunden
#damit sind die Anwendungen innerhalb des Verzeichnisses auch z.B.
#fuer das ./configure Script sichtbar.
#Beim Original cppunit Paket ist das ./configura Script der OLA
#Anwendung immer mit dem Fehler, dass die cppunit Anwendung nicht
#gefunden werden kann, abgebrochen. Dieses neue cppunit Paket
#behebt dieses Problem.

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include/cppunit
	$(CP) $(PKG_INSTALL_DIR)/usr/include/cppunit $(1)/usr/include
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libcppunit*so* $(1)/usr/lib/
	$(INSTALL_DIR) $(2)/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/bin/cppunit-config $(2)/bin/
endef

define Package/cppunit_ola/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libcppunit*so* $(1)/usr/lib/
endef

$(eval $(call BuildPackage,cppunit_ola))
