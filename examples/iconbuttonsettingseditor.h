#ifndef ICONBUTTONSETTINGSMANAGER_H
#define ICONBUTTONSETTINGSMANAGER_H

#include "settingseditor.h"

#include "ui_iconbuttonsettingsform.h"

class QtMaterialIconButton;

class IconButtonSettingsEditor : public SettingsEditor
{
    Q_OBJECT

public:
    explicit IconButtonSettingsEditor(QWidget *parent = nullptr);
    ~IconButtonSettingsEditor() override;

protected:
    explicit IconButtonSettingsEditor(QtMaterialIconButton *button, QWidget *parent = nullptr);

    Ui::IconButtonSettingsForm *const ui;

protected slots:
    void setupForm();
    void updateWidget();
    void selectColor();

private:
    void init();

    QtMaterialIconButton *const m_button;
};

#endif  // ICONBUTTONSETTINGSMANAGER_H
