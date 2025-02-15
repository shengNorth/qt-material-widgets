#include "qtmaterialappbar.h"

#include "lib/qtmaterialstyle.h"
#include "qtmaterialappbar_internal.h"
#include "qtmaterialappbar_p.h"

#include <QActionEvent>
#include <QGraphicsDropShadowEffect>
#include <QPainter>
#include <QWidgetAction>

/*!
 *  \class QtMaterialAppBarPrivate
 *  \internal
 */

/*!
 *  \internal
 */
QtMaterialAppBarPrivate::QtMaterialAppBarPrivate(QtMaterialAppBar *q)
    : q_ptr(q)
{
}

/*!
 *  \internal
 */
QtMaterialAppBarPrivate::~QtMaterialAppBarPrivate()
{
}

/*!
 *  \internal
 */
void QtMaterialAppBarPrivate::init()
{
    Q_Q(QtMaterialAppBar);

    navIconType = Material::NavIconNone;
    navButton = nullptr;

    titleLabel = new QLabel(q);
    titleLabel->setAttribute(Qt::WA_TranslucentBackground);
    titleLabel->setForegroundRole(QPalette::WindowText);
    titleLabel->setContentsMargins(6, 0, 0, 0);
    titleLabel->setFont(QtMaterialStyle::instance().themeFont(Material::FontHeadline3));

    iconSize = QSize(48, 48);

    useThemeColors = true;

    /*QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect;
    effect->setBlurRadius(11);
    effect->setColor(QColor(0, 0, 0, 50));
    effect->setOffset(0, 3);
    q->setGraphicsEffect(effect);*/

    layout = new QtMaterialAppBarLayout(q);
    layout->setTitleLabel(titleLabel);
    q->setLayout(layout);

    updateChildrenColor();
}

/*!
 *  \internal
 */
void QtMaterialAppBarPrivate::updateChildrenColor()
{
    Q_Q(QtMaterialAppBar);

    QPalette palette = titleLabel->palette();
    palette.setColor(titleLabel->foregroundRole(), q->foregroundColor());
    titleLabel->setPalette(palette);

    layout->updateButtons();
}

/*!
 *  \internal
 */
void QtMaterialAppBarPrivate::setIconSize(const QSize &iconSize)
{
    this->iconSize = iconSize;
    layout->updateButtons();
    layout->invalidate();
}

/*!
 *  \internal
 */
void QtMaterialAppBarPrivate::setNavIconType(Material::NavIconType type)
{
    Q_Q(QtMaterialAppBar);

    if (navButton == nullptr && type != Material::NavIconNone)
    {
        navButton = new QtMaterialIconButton(QIcon(), q);
        navButton->setIconSize(iconSize);
        navButton->setColor(q->foregroundColor());
        layout->setNavButton(navButton);
        QObject::connect(navButton, &QtMaterialIconButton::clicked, q, &QtMaterialAppBar::navIconClicked);
    }

    switch (type)
    {
        case Material::NavIconNone:
            if (navButton != nullptr)
            {
                layout->setNavButton(nullptr);
                navButton->hide();
                delete navButton;
                navButton = nullptr;
            }
            break;

        case Material::NavIconMenu:
            navButton->setIcon(QtMaterialTheme::icon(QStringLiteral("navigation"), QStringLiteral("menu")));
            break;

        case Material::NavIconPrevious:
            navButton->setIcon(QtMaterialTheme::icon(QStringLiteral("navigation"), QStringLiteral("arrow_back")));
            break;

        case Material::NavIconUpper:
            navButton->setIcon(QtMaterialTheme::icon(QStringLiteral("navigation"), QStringLiteral("expand_less")));
            break;
    }
    navIconType = type;
}

/*!
 *  \class QtMaterialAppBar
 */

QtMaterialAppBar::QtMaterialAppBar(const QString &title, QWidget *parent)
    : QWidget(parent),
      d_ptr(new QtMaterialAppBarPrivate(this))
{
    d_func()->init();

    setTitle(title);
}

QtMaterialAppBar::QtMaterialAppBar(QWidget *parent)
    : QWidget(parent),
      d_ptr(new QtMaterialAppBarPrivate(this))
{
    d_func()->init();
}

QtMaterialAppBar::~QtMaterialAppBar()
{
}

const QString &QtMaterialAppBar::title() const
{
    Q_D(const QtMaterialAppBar);

    return d->title;
}

void QtMaterialAppBar::setTitle(const QString &title)
{
    Q_D(QtMaterialAppBar);

    d->title = title;
    if (d->titleLabel != nullptr)
    {
        d->titleLabel->setText(title);
    }
    updateGeometry();
}

Material::NavIconType QtMaterialAppBar::navIconType() const
{
    Q_D(const QtMaterialAppBar);

    return d->navIconType;
}

void QtMaterialAppBar::setNavIconType(Material::NavIconType navIconType)
{
    Q_D(QtMaterialAppBar);

    d->setNavIconType(navIconType);
    updateGeometry();
}

const QSize &QtMaterialAppBar::iconSize() const
{
    Q_D(const QtMaterialAppBar);

    return d->iconSize;
}

void QtMaterialAppBar::setIconSize(const QSize &iconSize)
{
    Q_D(QtMaterialAppBar);

    d->setIconSize(iconSize);
    updateGeometry();
}

void QtMaterialAppBar::setIconSize(int w, int h)
{
    setIconSize(QSize(w, h));
}

void QtMaterialAppBar::setUseThemeColors(bool value)
{
    Q_D(QtMaterialAppBar);

    if (d->useThemeColors == value)
    {
        return;
    }

    d->useThemeColors = value;
    d->updateChildrenColor();
    update();
}

bool QtMaterialAppBar::useThemeColors() const
{
    Q_D(const QtMaterialAppBar);

    return d->useThemeColors;
}

void QtMaterialAppBar::setForegroundColor(const QColor &color)
{
    Q_D(QtMaterialAppBar);

    d->foregroundColor = color;

    if (d->useThemeColors)
    {
        d->useThemeColors = false;
    }
    d->updateChildrenColor();
    update();
}

QColor QtMaterialAppBar::foregroundColor() const
{
    Q_D(const QtMaterialAppBar);

    if (d->useThemeColors || !d->foregroundColor.isValid())
    {
        return QtMaterialStyle::instance().themeColor(Material::ColorThemeAlternateText);
    }

    return d->foregroundColor;
}

void QtMaterialAppBar::setBackgroundColor(const QColor &color)
{
    Q_D(QtMaterialAppBar);

    d->backgroundColor = color;

    if (d->useThemeColors)
    {
        d->useThemeColors = false;
    }
    d->updateChildrenColor();
    update();
}

QColor QtMaterialAppBar::backgroundColor() const
{
    Q_D(const QtMaterialAppBar);

    if (d->useThemeColors || !d->backgroundColor.isValid())
    {
        return QtMaterialStyle::instance().themeColor(Material::ColorThemePrimary1);
    }

    return d->backgroundColor;
}

bool QtMaterialAppBar::event(QEvent *event)
{
    Q_D(QtMaterialAppBar);

    if (event->type() == QEvent::FontChange)
    {
        d->titleLabel->setFont(font());
        updateGeometry();
    }
    return QWidget::event(event);
}

void QtMaterialAppBar::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);

    painter.fillRect(rect(), backgroundColor());
}

void QtMaterialAppBar::actionEvent(QActionEvent *event)
{
    Q_D(QtMaterialAppBar);

    QAction *action = event->action();
    QWidgetAction *widgetAction = qobject_cast<QWidgetAction *>(action);
    switch (event->type())
    {
        case QEvent::ActionAdded:
        {
            if (widgetAction != nullptr)
            {
                widgetAction->setParent(this);
            }
            d->layout->insertAction(0, action);
            break;
        }
        case QEvent::ActionChanged:
            d->layout->updateActions();
            d->layout->invalidate();
            break;

        case QEvent::ActionRemoved:
        {
            // TODO
        }

        default:
            break;
    }
}
