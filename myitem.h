#ifndef MYITEM_H
#define MYITEM_H

#include <QGraphicsObject>
#include <QPropertyAnimation>
class MyItem : public QGraphicsObject
{
public:
    MyItem(QGraphicsItem *parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget);
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    int status;
    QPropertyAnimation *animation;
};

#endif // MYITEM_H
