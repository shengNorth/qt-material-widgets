TEMPLATE = lib
CONFIG += staticlib
QT += core gui widgets

greaterThan(QT_MAJOR_VERSION, 5) {
    QT += statemachine
}

SOURCES = \
    $$PWD/layouts/qtmaterialslidelayout.cpp \
    $$PWD/lib/qtmaterialcheckable.cpp \
    $$PWD/lib/qtmaterialcheckable_internal.cpp \
    $$PWD/lib/qtmaterialoverlaywidget.cpp \
    $$PWD/lib/qtmaterialripple.cpp \
    $$PWD/lib/qtmaterialrippleoverlay.cpp \
    $$PWD/lib/qtmaterialstatetransition.cpp \
    $$PWD/lib/qtmaterialstyle.cpp \
    $$PWD/lib/qtmaterialtheme.cpp \
    $$PWD/qtmaterialappbar.cpp \
    $$PWD/qtmaterialappbar_internal.cpp \
    $$PWD/qtmaterialautocomplete.cpp \
    $$PWD/qtmaterialautocomplete_internal.cpp \
    $$PWD/qtmaterialavatar.cpp \
    $$PWD/qtmaterialbadge.cpp \
    $$PWD/qtmaterialbuttonlist.cpp \
    $$PWD/qtmaterialcanvas.cpp \
    $$PWD/qtmaterialcheckbox.cpp \
    $$PWD/qtmaterialcircularprogress.cpp \
    $$PWD/qtmaterialcircularprogress_internal.cpp \
    $$PWD/qtmaterialdialog.cpp \
    $$PWD/qtmaterialdialog_internal.cpp \
    $$PWD/qtmaterialdrawer.cpp \
    $$PWD/qtmaterialdrawer_internal.cpp \
    $$PWD/qtmaterialfab.cpp \
    $$PWD/qtmaterialflatbutton.cpp \
    $$PWD/qtmaterialflatbutton_internal.cpp \
    $$PWD/qtmaterialiconbutton.cpp \
    $$PWD/qtmaterialprogress.cpp \
    $$PWD/qtmaterialprogress_internal.cpp \
    $$PWD/qtmaterialradiobutton.cpp \
    $$PWD/qtmaterialscrollbar.cpp \
    $$PWD/qtmaterialscrollbar_internal.cpp \
    $$PWD/qtmaterialslider.cpp \
    $$PWD/qtmaterialslider_internal.cpp \
    $$PWD/qtmaterialsnackbar.cpp \
    $$PWD/qtmaterialsnackbar_internal.cpp \
    $$PWD/qtmaterialsystembar.cpp \
    $$PWD/qtmaterialtabs.cpp \
    $$PWD/qtmaterialtabs_internal.cpp \
    $$PWD/qtmaterialtextfield.cpp \
    $$PWD/qtmaterialtextfield_internal.cpp \
    $$PWD/qtmaterialtoggle.cpp \
    $$PWD/qtmaterialtoggle_internal.cpp

HEADERS = \
    $$PWD/layouts/qtmaterialslidelayout.h \
    $$PWD/layouts/qtmaterialslidelayout_p.h \
    $$PWD/lib/qtmaterialcheckable.h \
    $$PWD/lib/qtmaterialcheckable_internal.h \
    $$PWD/lib/qtmaterialcheckable_p.h \
    $$PWD/lib/qtmaterialoverlaywidget.h \
    $$PWD/lib/qtmaterialripple.h \
    $$PWD/lib/qtmaterialrippleoverlay.h \
    $$PWD/lib/qtmaterialstatetransitionevent.h \
    $$PWD/lib/qtmaterialstatetransition.h \
    $$PWD/lib/qtmaterialstyle.h \
    $$PWD/lib/qtmaterialstyle_p.h \
    $$PWD/lib/qtmaterialtheme.h \
    $$PWD/lib/qtmaterialtheme_p.h \
    $$PWD/qtmaterialappbar.h \
    $$PWD/qtmaterialappbar_internal.h \
    $$PWD/qtmaterialappbar_p.h \
    $$PWD/qtmaterialautocomplete.h \
    $$PWD/qtmaterialautocomplete_internal.h \
    $$PWD/qtmaterialautocomplete_p.h \
    $$PWD/qtmaterialavatar.h \
    $$PWD/qtmaterialavatar_p.h \
    $$PWD/qtmaterialbadge.h \
    $$PWD/qtmaterialbadge_p.h \
    $$PWD/qtmaterialbuttonlist.h \
    $$PWD/qtmaterialbuttonlist_p.h \
    $$PWD/qtmaterialcanvas.h \
    $$PWD/qtmaterialcanvas_p.h \
    $$PWD/qtmaterialcheckbox.h \
    $$PWD/qtmaterialcheckbox_p.h \
    $$PWD/qtmaterialcircularprogress.h \
    $$PWD/qtmaterialcircularprogress_internal.h \
    $$PWD/qtmaterialcircularprogress_p.h \
    $$PWD/qtmaterialdialog.h \
    $$PWD/qtmaterialdialog_internal.h \
    $$PWD/qtmaterialdialog_p.h \
    $$PWD/qtmaterialdrawer.h \
    $$PWD/qtmaterialdrawer_internal.h \
    $$PWD/qtmaterialdrawer_p.h \
    $$PWD/qtmaterialfab.h \
    $$PWD/qtmaterialfab_p.h \
    $$PWD/qtmaterialflatbutton.h \
    $$PWD/qtmaterialflatbutton_internal.h \
    $$PWD/qtmaterialflatbutton_p.h \
    $$PWD/qtmaterialiconbutton.h \
    $$PWD/qtmaterialiconbutton_p.h \
    $$PWD/qtmaterialprogress.h \
    $$PWD/qtmaterialprogress_internal.h \
    $$PWD/qtmaterialprogress_p.h \
    $$PWD/qtmaterialradiobutton.h \
    $$PWD/qtmaterialradiobutton_p.h \
    $$PWD/qtmaterialscrollbar.h \
    $$PWD/qtmaterialscrollbar_internal.h \
    $$PWD/qtmaterialscrollbar_p.h \
    $$PWD/qtmaterialslider.h \
    $$PWD/qtmaterialslider_internal.h \
    $$PWD/qtmaterialslider_p.h \
    $$PWD/qtmaterialsnackbar.h \
    $$PWD/qtmaterialsnackbar_internal.h \
    $$PWD/qtmaterialsnackbar_p.h \
    $$PWD/qtmaterialsystembar.h \
    $$PWD/qtmaterialsystembar_p.h \
    $$PWD/qtmaterialtabs.h \
    $$PWD/qtmaterialtabs_internal.h \
    $$PWD/qtmaterialtabs_p.h \
    $$PWD/qtmaterialtextfield.h \
    $$PWD/qtmaterialtextfield_internal.h \
    $$PWD/qtmaterialtextfield_p.h \
    $$PWD/qtmaterialtoggle.h \
    $$PWD/qtmaterialtoggle_internal.h \
    $$PWD/qtmaterialtoggle_p.h

RESOURCES += \
    $$PWD/resources.qrc
