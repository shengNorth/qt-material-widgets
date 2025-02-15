#ifndef QTMATERIALDIALOG_H
#define QTMATERIALDIALOG_H

#include "lib/qtmaterialoverlaywidget.h"

#include <QScopedPointer>

class QLayout;
class QtMaterialDialogPrivate;

class QtMaterialDialog : public QtMaterialOverlayWidget
{
    Q_OBJECT

public:
    explicit QtMaterialDialog(QWidget *parent = nullptr);
    ~QtMaterialDialog() override;

    QLayout *windowLayout() const;
    void setWindowLayout(QLayout *layout);

public slots:
    void showDialog();
    void hideDialog();

protected:
    void paintEvent(QPaintEvent *event) override;

    const QScopedPointer<QtMaterialDialogPrivate> d_ptr;

private:
    Q_DISABLE_COPY(QtMaterialDialog)
    Q_DECLARE_PRIVATE(QtMaterialDialog)
};

#endif  // QTMATERIALDIALOG_H
