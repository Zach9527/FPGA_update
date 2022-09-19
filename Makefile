#############################################################################
# Makefile for building: orc2213_pc
# Generated by qmake (3.1) (Qt 5.9.0)
# Project:  orc2213_pc.pro
# Template: app
# Command: E:\QT\QT\5.9\msvc2015\bin\qmake.exe -o Makefile orc2213_pc.pro -spec win32-msvc "CONFIG+=debug" "CONFIG+=qml_debug"
#############################################################################

MAKEFILE      = Makefile

first: debug
install: debug-install
uninstall: debug-uninstall
QMAKE         = E:\QT\QT\5.9\msvc2015\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = copy /y
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = copy /y
INSTALL_PROGRAM = copy /y
INSTALL_DIR   = xcopy /s /q /y /i
QINSTALL_FILE = E:\QT\QT\5.9\msvc2015\bin\qmake.exe -install qinstall file
QINSTALL_PROGRAM = E:\QT\QT\5.9\msvc2015\bin\qmake.exe -install qinstall program
QINSTALL_DIR  = E:\QT\QT\5.9\msvc2015\bin\qmake.exe -install qinstall directory
DEL_FILE      = del
SYMLINK       = $(QMAKE) -install ln -f -s
DEL_DIR       = rmdir
MOVE          = move
SUBTARGETS    =  \
		debug \
		release


debug: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_first: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug 
debug-all: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug uninstall
release: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release
release-make_first: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release 
release-all: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release uninstall

Makefile: orc2213_pc.pro ..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\win32-msvc\qmake.conf ..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\spec_pre.prf \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\common\angle.conf \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\common\msvc-desktop.conf \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\qconfig.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3danimation.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3danimation_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dcore.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dcore_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dextras.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dextras_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dinput.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dinput_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dlogic.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dlogic_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dquick.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dquick_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dquickanimation.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dquickanimation_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dquickextras.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dquickextras_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dquickinput.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dquickinput_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dquickrender.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dquickrender_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dquickscene2d.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dquickscene2d_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3drender.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3drender_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_accessibility_support_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_axbase.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_axbase_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_axcontainer.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_axcontainer_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_axserver.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_axserver_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_bluetooth.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_bluetooth_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_bootstrap_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_charts.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_charts_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_concurrent.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_concurrent_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_core.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_core_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_datavisualization.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_datavisualization_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_dbus.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_dbus_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_designer.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_designer_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_designercomponents_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_devicediscovery_support_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_egl_support_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_eventdispatcher_support_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_fb_support_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_fontdatabase_support_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_gamepad.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_gamepad_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_gui.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_gui_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_help.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_help_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_location.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_location_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_multimedia.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_multimedia_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_multimediawidgets.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_multimediawidgets_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_network.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_network_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_networkauth.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_networkauth_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_nfc.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_nfc_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_opengl.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_opengl_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_openglextensions.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_openglextensions_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_packetprotocol_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_platformcompositor_support_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_positioning.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_positioning_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_printsupport.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_printsupport_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_purchasing.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_purchasing_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_qml.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_qml_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_qmldebug_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_qmldevtools_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_qmltest.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_qmltest_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_qtmultimediaquicktools_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_quick.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_quick_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_quickcontrols2.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_quickcontrols2_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_quickparticles_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_quicktemplates2_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_quickwidgets.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_quickwidgets_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_remoteobjects.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_remoteobjects_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_repparser.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_repparser_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_script.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_script_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_scripttools.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_scripttools_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_scxml.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_scxml_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_sensors.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_sensors_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_serialbus.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_serialbus_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_serialport.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_serialport_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_sql.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_sql_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_svg.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_svg_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_testlib.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_testlib_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_texttospeech.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_texttospeech_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_theme_support_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_uiplugin.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_uitools.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_uitools_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_webchannel.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_webchannel_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_webengine.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_webengine_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_webenginecore.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_webenginecore_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_webenginecoreheaders_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_webenginewidgets.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_webenginewidgets_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_websockets.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_websockets_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_webview.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_webview_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_widgets.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_widgets_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_winextras.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_winextras_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_xml.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_xml_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_xmlpatterns.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_xmlpatterns_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_zlib_private.pri \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\qt_functions.prf \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\qt_config.prf \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\win32-msvc\qmake.conf \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\spec_post.prf \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\exclusive_builds.prf \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\common\msvc-version.conf \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\toolchain.prf \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\default_pre.prf \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\win32\default_pre.prf \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\resolve_config.prf \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\exclusive_builds_post.prf \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\default_post.prf \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\qml_debug.prf \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\precompile_header.prf \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\warn_on.prf \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\qt.prf \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\resources.prf \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\moc.prf \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\win32\opengl.prf \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\uic.prf \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\qmake_use.prf \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\file_copies.prf \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\win32\windows.prf \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\testcase_targets.prf \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\exceptions.prf \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\yacc.prf \
		..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\lex.prf \
		orc2213_pc.pro \
		..\..\..\..\QT\QT\5.9\msvc2015\lib\qtmaind.prl \
		..\..\..\..\QT\QT\5.9\msvc2015\lib\Qt5Widgets.prl \
		..\..\..\..\QT\QT\5.9\msvc2015\lib\Qt5Gui.prl \
		..\..\..\..\QT\QT\5.9\msvc2015\lib\Qt5Network.prl \
		..\..\..\..\QT\QT\5.9\msvc2015\lib\Qt5Core.prl
	$(QMAKE) -o Makefile orc2213_pc.pro -spec win32-msvc "CONFIG+=debug" "CONFIG+=qml_debug"
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\spec_pre.prf:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\common\angle.conf:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\common\msvc-desktop.conf:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\qconfig.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3danimation.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3danimation_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dcore.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dcore_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dextras.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dextras_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dinput.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dinput_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dlogic.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dlogic_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dquick.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dquick_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dquickanimation.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dquickanimation_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dquickextras.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dquickextras_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dquickinput.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dquickinput_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dquickrender.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dquickrender_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dquickscene2d.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3dquickscene2d_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3drender.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_3drender_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_accessibility_support_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_axbase.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_axbase_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_axcontainer.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_axcontainer_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_axserver.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_axserver_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_bluetooth.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_bluetooth_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_bootstrap_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_charts.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_charts_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_concurrent.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_concurrent_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_core.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_core_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_datavisualization.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_datavisualization_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_dbus.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_dbus_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_designer.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_designer_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_designercomponents_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_devicediscovery_support_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_egl_support_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_eventdispatcher_support_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_fb_support_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_fontdatabase_support_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_gamepad.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_gamepad_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_gui.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_gui_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_help.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_help_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_location.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_location_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_multimedia.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_multimedia_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_multimediawidgets.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_multimediawidgets_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_network.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_network_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_networkauth.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_networkauth_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_nfc.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_nfc_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_opengl.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_opengl_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_openglextensions.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_openglextensions_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_packetprotocol_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_platformcompositor_support_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_positioning.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_positioning_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_printsupport.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_printsupport_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_purchasing.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_purchasing_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_qml.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_qml_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_qmldebug_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_qmldevtools_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_qmltest.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_qmltest_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_qtmultimediaquicktools_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_quick.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_quick_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_quickcontrols2.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_quickcontrols2_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_quickparticles_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_quicktemplates2_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_quickwidgets.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_quickwidgets_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_remoteobjects.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_remoteobjects_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_repparser.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_repparser_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_script.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_script_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_scripttools.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_scripttools_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_scxml.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_scxml_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_sensors.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_sensors_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_serialbus.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_serialbus_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_serialport.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_serialport_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_sql.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_sql_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_svg.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_svg_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_testlib.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_testlib_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_texttospeech.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_texttospeech_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_theme_support_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_uiplugin.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_uitools.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_uitools_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_webchannel.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_webchannel_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_webengine.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_webengine_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_webenginecore.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_webenginecore_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_webenginecoreheaders_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_webenginewidgets.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_webenginewidgets_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_websockets.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_websockets_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_webview.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_webview_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_widgets.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_widgets_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_winextras.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_winextras_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_xml.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_xml_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_xmlpatterns.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_xmlpatterns_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\modules\qt_lib_zlib_private.pri:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\qt_functions.prf:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\qt_config.prf:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\win32-msvc\qmake.conf:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\spec_post.prf:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\exclusive_builds.prf:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\common\msvc-version.conf:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\toolchain.prf:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\default_pre.prf:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\win32\default_pre.prf:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\resolve_config.prf:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\exclusive_builds_post.prf:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\default_post.prf:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\qml_debug.prf:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\precompile_header.prf:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\warn_on.prf:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\qt.prf:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\resources.prf:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\moc.prf:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\win32\opengl.prf:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\uic.prf:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\qmake_use.prf:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\file_copies.prf:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\win32\windows.prf:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\testcase_targets.prf:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\exceptions.prf:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\yacc.prf:
..\..\..\..\QT\QT\5.9\msvc2015\mkspecs\features\lex.prf:
orc2213_pc.pro:
..\..\..\..\QT\QT\5.9\msvc2015\lib\qtmaind.prl:
..\..\..\..\QT\QT\5.9\msvc2015\lib\Qt5Widgets.prl:
..\..\..\..\QT\QT\5.9\msvc2015\lib\Qt5Gui.prl:
..\..\..\..\QT\QT\5.9\msvc2015\lib\Qt5Network.prl:
..\..\..\..\QT\QT\5.9\msvc2015\lib\Qt5Core.prl:
qmake: FORCE
	@$(QMAKE) -o Makefile orc2213_pc.pro -spec win32-msvc "CONFIG+=debug" "CONFIG+=qml_debug"

qmake_all: FORCE

make_first: debug-make_first release-make_first  FORCE
all: debug-all release-all  FORCE
clean: debug-clean release-clean  FORCE
	-$(DEL_FILE) orc2213_pc.exp
	-$(DEL_FILE) orc2213_pc.vc.pdb
	-$(DEL_FILE) orc2213_pc.ilk
	-$(DEL_FILE) orc2213_pc.idb
distclean: debug-distclean release-distclean  FORCE
	-$(DEL_FILE) Makefile
	-$(DEL_FILE) .qmake.stash orc2213_pc.lib orc2213_pc.pdb

debug-mocclean:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug mocclean
release-mocclean:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release mocclean
mocclean: debug-mocclean release-mocclean

debug-mocables:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug mocables
release-mocables:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release mocables
mocables: debug-mocables release-mocables

check: first

benchmark: first
FORCE:

$(MAKEFILE).Debug: Makefile
$(MAKEFILE).Release: Makefile
