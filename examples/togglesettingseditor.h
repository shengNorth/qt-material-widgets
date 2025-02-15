#ifndef TOGGLESETTINGSEDITOR_H
#define TOGGLESETTINGSEDITOR_H

#include "settingseditor.h"

#include "ui_togglesettingsform.h"

class QtMaterialToggle;

class ToggleSettingsEditor : public SettingsEditor
{
    Q_OBJECT

public:
    explicit ToggleSettingsEditor(QWidget *parent = nullptr);
    ~ToggleSettingsEditor() override;

protected slots:
    void setupForm();
    void updateWidget();
    void selectColor();

private:
    Ui::ToggleSettingsForm *const ui;
    QtMaterialToggle *const m_toggle;
};

#endif  // TOGGLESETTINGSEDITOR_H
