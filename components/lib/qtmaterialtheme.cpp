#include "lib/qtmaterialtheme.h"

#include "lib/qtmaterialtheme_p.h"

#include <QDebug>
#include <QString>
#include <QStringBuilder>

/*!material
 *  \class QtMaterialThemePrivate
 *  \internal
 */

QtMaterialThemePrivate::QtMaterialThemePrivate(QtMaterialTheme *q)
    : q_ptr(q)
{
}

QtMaterialThemePrivate::~QtMaterialThemePrivate()
{
}

QColor QtMaterialThemePrivate::rgba(int r, int g, int b, qreal a) const
{
    QColor color(r, g, b);
    color.setAlphaF(a);
    return color;
}

/*!
 *  \class QtMaterialTheme
 */

QtMaterialTheme::QtMaterialTheme(QObject *parent)
    : QObject(parent),
      d_ptr(new QtMaterialThemePrivate(this))
{
    setColor("primary1", Material::cyan500);
    setColor("primary2", Material::cyan700);
    setColor("primary3", Material::lightBlack);
    setColor("accent1", Material::pinkA200);
    setColor("accent2", Material::grey100);
    setColor("accent3", Material::grey500);
    setColor("text", Material::darkBlack);
    setColor("alternateText", Material::white);
    setColor("canvas", Material::white);
    setColor("border", Material::grey300);
    setColor("disabled", Material::minBlack);
    setColor("disabled2", Material::faintBlack);
    setColor("disabled3", Material::grey300);
}

QtMaterialTheme::~QtMaterialTheme()
{
}

QColor QtMaterialTheme::getColor(const QString &key) const
{
    Q_D(const QtMaterialTheme);

    if (!d->colors.contains(key))
    {
        qWarning() << "A theme color matching the key '" << key << "' could not be found.";
        return QColor();
    }
    return d->colors.value(key);
}

void QtMaterialTheme::setColor(const QString &key, const QColor &color)
{
    Q_D(QtMaterialTheme);

    d->colors.insert(key, color);
}

void QtMaterialTheme::setColor(const QString &key, Material::Color color)
{
    Q_D(QtMaterialTheme);

    static const QColor palette[] = {
        QColor(0xff, 0xeb, 0xee),    QColor(0xff, 0xcd, 0xd2), QColor(0xef, 0x9a, 0x9a), QColor(0xe5, 0x73, 0x73), QColor(0xef, 0x53, 0x50),  QColor(0xf4, 0x43, 0x36),
        QColor(0xe5, 0x39, 0x35),    QColor(0xd3, 0x2f, 0x2f), QColor(0xc6, 0x28, 0x28), QColor(0xb7, 0x1c, 0x1c), QColor(0xff, 0x8a, 0x80),  QColor(0xff, 0x52, 0x52),
        QColor(0xff, 0x17, 0x44),    QColor(0xd5, 0x00, 0x00), QColor(0xfc, 0xe4, 0xec), QColor(0xf8, 0xbb, 0xd0), QColor(0xf4, 0x8f, 0xb1),  QColor(0xf0, 0x62, 0x92),
        QColor(0xec, 0x40, 0x7a),    QColor(0xe9, 0x1e, 0x63), QColor(0xd8, 0x1b, 0x60), QColor(0xc2, 0x18, 0x5b), QColor(0xad, 0x14, 0x57),  QColor(0x88, 0x0e, 0x4f),
        QColor(0xff, 0x80, 0xab),    QColor(0xff, 0x40, 0x81), QColor(0xf5, 0x00, 0x57), QColor(0xc5, 0x11, 0x62), QColor(0xf3, 0xe5, 0xf5),  QColor(0xe1, 0xbe, 0xe7),
        QColor(0xce, 0x93, 0xd8),    QColor(0xba, 0x68, 0xc8), QColor(0xab, 0x47, 0xbc), QColor(0x9c, 0x27, 0xb0), QColor(0x8e, 0x24, 0xaa),  QColor(0x7b, 0x1f, 0xa2),
        QColor(0x6a, 0x1b, 0x9a),    QColor(0x4a, 0x14, 0x8c), QColor(0xea, 0x80, 0xfc), QColor(0xe0, 0x40, 0xfb), QColor(0xd5, 0x00, 0xf9),  QColor(0xaa, 0x00, 0xff),
        QColor(0xed, 0xe7, 0xf6),    QColor(0xd1, 0xc4, 0xe9), QColor(0xb3, 0x9d, 0xdb), QColor(0x95, 0x75, 0xcd), QColor(0x7e, 0x57, 0xc2),  QColor(0x67, 0x3a, 0xb7),
        QColor(0x5e, 0x35, 0xb1),    QColor(0x51, 0x2d, 0xa8), QColor(0x45, 0x27, 0xa0), QColor(0x31, 0x1b, 0x92), QColor(0xb3, 0x88, 0xff),  QColor(0x7c, 0x4d, 0xff),
        QColor(0x65, 0x1f, 0xff),    QColor(0x62, 0x00, 0xea), QColor(0xe8, 0xea, 0xf6), QColor(0xc5, 0xca, 0xe9), QColor(0x9f, 0xa8, 0xda),  QColor(0x79, 0x86, 0xcb),
        QColor(0x5c, 0x6b, 0xc0),    QColor(0x3f, 0x51, 0xb5), QColor(0x39, 0x49, 0xab), QColor(0x30, 0x3f, 0x9f), QColor(0x28, 0x35, 0x93),  QColor(0x1a, 0x23, 0x7e),
        QColor(0x8c, 0x9e, 0xff),    QColor(0x53, 0x6d, 0xfe), QColor(0x3d, 0x5a, 0xfe), QColor(0x30, 0x4f, 0xfe), QColor(0xe3, 0xf2, 0xfd),  QColor(0xbb, 0xde, 0xfb),
        QColor(0x90, 0xca, 0xf9),    QColor(0x64, 0xb5, 0xf6), QColor(0x42, 0xa5, 0xf5), QColor(0x21, 0x96, 0xf3), QColor(0x1e, 0x88, 0xe5),  QColor(0x19, 0x76, 0xd2),
        QColor(0x15, 0x65, 0xc0),    QColor(0x0d, 0x47, 0xa1), QColor(0x82, 0xb1, 0xff), QColor(0x44, 0x8a, 0xff), QColor(0x29, 0x79, 0xff),  QColor(0x29, 0x62, 0xff),
        QColor(0xe1, 0xf5, 0xfe),    QColor(0xb3, 0xe5, 0xfc), QColor(0x81, 0xd4, 0xfa), QColor(0x4f, 0xc3, 0xf7), QColor(0x29, 0xb6, 0xf6),  QColor(0x03, 0xa9, 0xf4),
        QColor(0x03, 0x9b, 0xe5),    QColor(0x02, 0x88, 0xd1), QColor(0x02, 0x77, 0xbd), QColor(0x01, 0x57, 0x9b), QColor(0x80, 0xd8, 0xff),  QColor(0x40, 0xc4, 0xff),
        QColor(0x00, 0xb0, 0xff),    QColor(0x00, 0x91, 0xea), QColor(0xe0, 0xf7, 0xfa), QColor(0xb2, 0xeb, 0xf2), QColor(0x80, 0xde, 0xea),  QColor(0x4d, 0xd0, 0xe1),
        QColor(0x26, 0xc6, 0xda),    QColor(0x00, 0xbc, 0xd4), QColor(0x00, 0xac, 0xc1), QColor(0x00, 0x97, 0xa7), QColor(0x00, 0x83, 0x8f),  QColor(0x00, 0x60, 0x64),
        QColor(0x84, 0xff, 0xff),    QColor(0x18, 0xff, 0xff), QColor(0x00, 0xe5, 0xff), QColor(0x00, 0xb8, 0xd4), QColor(0xe0, 0xf2, 0xf1),  QColor(0xb2, 0xdf, 0xdb),
        QColor(0x80, 0xcb, 0xc4),    QColor(0x4d, 0xb6, 0xac), QColor(0x26, 0xa6, 0x9a), QColor(0x00, 0x96, 0x88), QColor(0x00, 0x89, 0x7b),  QColor(0x00, 0x79, 0x6b),
        QColor(0x00, 0x69, 0x5c),    QColor(0x00, 0x4d, 0x40), QColor(0xa7, 0xff, 0xeb), QColor(0x64, 0xff, 0xda), QColor(0x1d, 0xe9, 0xb6),  QColor(0x00, 0xbf, 0xa5),
        QColor(0xe8, 0xf5, 0xe9),    QColor(0xc8, 0xe6, 0xc9), QColor(0xa5, 0xd6, 0xa7), QColor(0x81, 0xc7, 0x84), QColor(0x66, 0xbb, 0x6a),  QColor(0x4c, 0xaf, 0x50),
        QColor(0x43, 0xa0, 0x47),    QColor(0x38, 0x8e, 0x3c), QColor(0x2e, 0x7d, 0x32), QColor(0x1b, 0x5e, 0x20), QColor(0xb9, 0xf6, 0xca),  QColor(0x69, 0xf0, 0xae),
        QColor(0x00, 0xe6, 0x76),    QColor(0x00, 0xc8, 0x53), QColor(0xf1, 0xf8, 0xe9), QColor(0xdc, 0xed, 0xc8), QColor(0xc5, 0xe1, 0xa5),  QColor(0xae, 0xd5, 0x81),
        QColor(0x9c, 0xcc, 0x65),    QColor(0x8b, 0xc3, 0x4a), QColor(0x7c, 0xb3, 0x42), QColor(0x68, 0x9f, 0x38), QColor(0x55, 0x8b, 0x2f),  QColor(0x33, 0x69, 0x1e),
        QColor(0xcc, 0xff, 0x90),    QColor(0xb2, 0xff, 0x59), QColor(0x76, 0xff, 0x03), QColor(0x64, 0xdd, 0x17), QColor(0xf9, 0xfb, 0xe7),  QColor(0xf0, 0xf4, 0xc3),
        QColor(0xe6, 0xee, 0x9c),    QColor(0xdc, 0xe7, 0x75), QColor(0xd4, 0xe1, 0x57), QColor(0xcd, 0xdc, 0x39), QColor(0xc0, 0xca, 0x33),  QColor(0xaf, 0xb4, 0x2b),
        QColor(0x9e, 0x9d, 0x24),    QColor(0x82, 0x77, 0x17), QColor(0xf4, 0xff, 0x81), QColor(0xee, 0xff, 0x41), QColor(0xc6, 0xff, 0x00),  QColor(0xae, 0xea, 0x00),
        QColor(0xff, 0xfd, 0xe7),    QColor(0xff, 0xf9, 0xc4), QColor(0xff, 0xf5, 0x9d), QColor(0xff, 0xf1, 0x76), QColor(0xff, 0xee, 0x58),  QColor(0xff, 0xeb, 0x3b),
        QColor(0xfd, 0xd8, 0x35),    QColor(0xfb, 0xc0, 0x2d), QColor(0xf9, 0xa8, 0x25), QColor(0xf5, 0x7f, 0x17), QColor(0xff, 0xff, 0x8d),  QColor(0xff, 0xff, 0x00),
        QColor(0xff, 0xea, 0x00),    QColor(0xff, 0xd6, 0x00), QColor(0xff, 0xf8, 0xe1), QColor(0xff, 0xec, 0xb3), QColor(0xff, 0xe0, 0x82),  QColor(0xff, 0xd5, 0x4f),
        QColor(0xff, 0xca, 0x28),    QColor(0xff, 0xc1, 0x07), QColor(0xff, 0xb3, 0x00), QColor(0xff, 0xa0, 0x00), QColor(0xff, 0x8f, 0x00),  QColor(0xff, 0x6f, 0x00),
        QColor(0xff, 0xe5, 0x7f),    QColor(0xff, 0xd7, 0x40), QColor(0xff, 0xc4, 0x00), QColor(0xff, 0xab, 0x00), QColor(0xff, 0xf3, 0xe0),  QColor(0xff, 0xe0, 0xb2),
        QColor(0xff, 0xcc, 0x80),    QColor(0xff, 0xb7, 0x4d), QColor(0xff, 0xa7, 0x26), QColor(0xff, 0x98, 0x00), QColor(0xfb, 0x8c, 0x00),  QColor(0xf5, 0x7c, 0x00),
        QColor(0xef, 0x6c, 0x00),    QColor(0xe6, 0x51, 0x00), QColor(0xff, 0xd1, 0x80), QColor(0xff, 0xab, 0x40), QColor(0xff, 0x91, 0x00),  QColor(0xff, 0x6d, 0x00),
        QColor(0xfb, 0xe9, 0xe7),    QColor(0xff, 0xcc, 0xbc), QColor(0xff, 0xab, 0x91), QColor(0xff, 0x8a, 0x65), QColor(0xff, 0x70, 0x43),  QColor(0xff, 0x57, 0x22),
        QColor(0xf4, 0x51, 0x1e),    QColor(0xe6, 0x4a, 0x19), QColor(0xd8, 0x43, 0x15), QColor(0xbf, 0x36, 0x0c), QColor(0xff, 0x9e, 0x80),  QColor(0xff, 0x6e, 0x40),
        QColor(0xff, 0x3d, 0x00),    QColor(0xdd, 0x2c, 0x00), QColor(0xef, 0xeb, 0xe9), QColor(0xd7, 0xcc, 0xc8), QColor(0xbc, 0xaa, 0xa4),  QColor(0xa1, 0x88, 0x7f),
        QColor(0x8d, 0x6e, 0x63),    QColor(0x79, 0x55, 0x48), QColor(0x6d, 0x4c, 0x41), QColor(0x5d, 0x40, 0x37), QColor(0x4e, 0x34, 0x2e),  QColor(0x3e, 0x27, 0x23),
        QColor(0xec, 0xef, 0xf1),    QColor(0xcf, 0xd8, 0xdc), QColor(0xb0, 0xbe, 0xc5), QColor(0x90, 0xa4, 0xae), QColor(0x78, 0x90, 0x9c),  QColor(0x60, 0x7d, 0x8b),
        QColor(0x54, 0x6e, 0x7a),    QColor(0x45, 0x5a, 0x64), QColor(0x37, 0x47, 0x4f), QColor(0x26, 0x32, 0x38), QColor(0xfa, 0xfa, 0xfa),  QColor(0xf5, 0xf5, 0xf5),
        QColor(0xee, 0xee, 0xee),    QColor(0xe0, 0xe0, 0xe0), QColor(0xbd, 0xbd, 0xbd), QColor(0x9e, 0x9e, 0x9e), QColor(0x75, 0x75, 0x75),  QColor(0x61, 0x61, 0x61),
        QColor(0x42, 0x42, 0x42),    QColor(0x21, 0x21, 0x21), QColor(0x00, 0x00, 0x00), QColor(0xff, 0xff, 0xff), d->rgba(0, 0, 0, 0),       d->rgba(0, 0, 0, 1),
        d->rgba(0, 0, 0, 0.87),      d->rgba(0, 0, 0, 0.54),   d->rgba(0, 0, 0, 0.26),   d->rgba(0, 0, 0, 0.12),   d->rgba(255, 255, 255, 1), d->rgba(255, 255, 255, 0.87),
        d->rgba(255, 255, 255, 0.54)};

    d->colors.insert(key, palette[color]);
}

QIcon QtMaterialTheme::icon(const QString &category, const QString &icon)
{
    return QIcon(":/icons/icons/" % category % "/svg/production/ic_" % icon % "_24px.svg");
}
