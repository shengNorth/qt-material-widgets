#include "qtmaterialiconbutton.h"

#include "lib/qtmaterialrippleoverlay.h"
#include "lib/qtmaterialstyle.h"
#include "qtmaterialiconbutton_p.h"

#include <QEvent>
#include <QMouseEvent>
#include <QPainter>

/*!
 *  \class QtMaterialIconButtonPrivate
 *  \internal
 */

QtMaterialIconButtonPrivate::QtMaterialIconButtonPrivate(QtMaterialIconButton *q)
    : q_ptr(q)
{
}

QtMaterialIconButtonPrivate::~QtMaterialIconButtonPrivate()
{
}

void QtMaterialIconButtonPrivate::init()
{
    Q_Q(QtMaterialIconButton);

    rippleOverlay = new QtMaterialRippleOverlay(q->parentWidget());
    useThemeColors = true;

    rippleOverlay->installEventFilter(q);

    q->setStyle(&QtMaterialStyle::instance());

    QSizePolicy policy;
    policy.setWidthForHeight(true);
    q->setSizePolicy(policy);

    if (q->parentWidget() != nullptr)
    {
        rippleOverlay->show();
    }
}

void QtMaterialIconButtonPrivate::updateRipple()
{
    Q_Q(QtMaterialIconButton);

    QRect r(q->rect());
    r.setSize(QSize(q->width() * 2, q->height() * 2));
    r.moveCenter(q->geometry().center());
    rippleOverlay->setGeometry(r);
}

/*!
 *  \class QtMaterialIconButton
 */

QtMaterialIconButton::QtMaterialIconButton(const QIcon &icon, QWidget *parent)
    : QAbstractButton(parent),
      d_ptr(new QtMaterialIconButtonPrivate(this))
{
    d_func()->init();

    setIcon(icon);
}

QtMaterialIconButton::~QtMaterialIconButton()
{
}

/*!
 *  \reimp
 */
QSize QtMaterialIconButton::sizeHint() const
{
    return iconSize();
}

void QtMaterialIconButton::setUseThemeColors(bool value)
{
    Q_D(QtMaterialIconButton);

    if (d->useThemeColors == value)
    {
        return;
    }

    d->useThemeColors = value;
    update();
}

bool QtMaterialIconButton::useThemeColors() const
{
    Q_D(const QtMaterialIconButton);

    return d->useThemeColors;
}

void QtMaterialIconButton::setColor(const QColor &color)
{
    Q_D(QtMaterialIconButton);

    d->color = color;

    MATERIAL_DISABLE_THEME_COLORS
    update();
}

QColor QtMaterialIconButton::color() const
{
    Q_D(const QtMaterialIconButton);

    if (d->useThemeColors || !d->color.isValid())
    {
        return QtMaterialStyle::instance().themeColor(Material::ColorThemeText);
    }
    return d->color;
}

void QtMaterialIconButton::setDisabledColor(const QColor &color)
{
    Q_D(QtMaterialIconButton);

    d->disabledColor = color;

    MATERIAL_DISABLE_THEME_COLORS
    update();
}

QColor QtMaterialIconButton::disabledColor() const
{
    Q_D(const QtMaterialIconButton);

    if (d->useThemeColors || !d->disabledColor.isValid())
    {
        return QtMaterialStyle::instance().themeColor(Material::ColorThemeDisabled1);
    }
    return d->disabledColor;
}

QtMaterialIconButton::QtMaterialIconButton(QtMaterialIconButtonPrivate &d, QWidget *parent)
    : QAbstractButton(parent),
      d_ptr(&d)
{
    d_func()->init();
}

/*!
 *  \reimp
 */
bool QtMaterialIconButton::event(QEvent *event)
{
    Q_D(QtMaterialIconButton);

    switch (event->type())
    {
        case QEvent::Move:
        case QEvent::Resize:
            d->updateRipple();
            break;

        case QEvent::ParentChange:
        {
            QWidget *widget;
            if ((widget = parentWidget()) != nullptr)
            {
                d->rippleOverlay->setParent(widget);
                d->rippleOverlay->show();
            }
            break;
        }
        default:
            break;
    }
    return QAbstractButton::event(event);
}

/*!
 *  \reimp
 */
bool QtMaterialIconButton::eventFilter(QObject *obj, QEvent *event)
{
    if (QEvent::Resize == event->type())
    {
        Q_D(QtMaterialIconButton);

        d->updateRipple();
    }
    return QAbstractButton::eventFilter(obj, event);
}

/*!
 *  \reimp
 */
void QtMaterialIconButton::mousePressEvent(QMouseEvent *event)
{
    QAbstractButton::mousePressEvent(event);

    Q_D(QtMaterialIconButton);

    d->rippleOverlay->addRipple(QPoint(d->rippleOverlay->width(), d->rippleOverlay->height()) / 2, iconSize().width());
}

/*!
 *  \reimp
 */
void QtMaterialIconButton::mouseReleaseEvent(QMouseEvent *event)
{
    QAbstractButton::mouseReleaseEvent(event);
    if (!event->isAccepted())
    {
        return;
    }
}

/*!
 *  \reimp
 */
void QtMaterialIconButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    if (icon().isNull())
    {
        return;
    }

    QPainter painter(this);

    QPixmap pixmap = icon().pixmap(iconSize());
    QPainter icon(&pixmap);
    icon.setCompositionMode(QPainter::CompositionMode_SourceIn);
    icon.fillRect(pixmap.rect(), isEnabled() ? color() : disabledColor());

    QRect r(rect());
    const qreal w = pixmap.width();
    const qreal h = pixmap.height();
    painter.drawPixmap(QRect((r.width() - w) / 2, (r.height() - h) / 2, w, h), pixmap);
}
