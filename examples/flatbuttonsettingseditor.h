#ifndef FLATBUTTONSETTINGSMANAGER_H
#define FLATBUTTONSETTINGSMANAGER_H

#include "settingseditor.h"

#include "ui_flatbuttonsettingsform.h"

class QtMaterialFlatButton;

class FlatButtonSettingsEditor : public SettingsEditor
{
    Q_OBJECT

public:
    explicit FlatButtonSettingsEditor(QWidget *parent = nullptr);
    ~FlatButtonSettingsEditor() override;

protected:
    explicit FlatButtonSettingsEditor(QtMaterialFlatButton *button, QWidget *parent = nullptr);

    Ui::FlatButtonSettingsForm *const ui;

protected slots:
    void setupForm();
    void updateWidget();
    void selectColor();

private:
    void init();

    QtMaterialFlatButton *const m_button;
};

#endif  // FLATBUTTONSETTINGSMANAGER_H
