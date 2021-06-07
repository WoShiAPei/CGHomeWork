#include "myitem.h"
#include <QPainter>
#include <QCursor>
#include <QKeyEvent>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>


MyItem::MyItem(QGraphicsItem *parent) :
    QGraphicsObject(parent)
{

    setFlag(QGraphicsItem::ItemIsFocusable);
    setFlag(QGraphicsItem::ItemIsMovable);
    setAcceptHoverEvents(true);
    setFocus();
    animation = new QPropertyAnimation(this, "rotation");
    animation->setDuration(20000);
    animation->setStartValue(0);
    animation->setEndValue(360);
    status = 0;
}
QRectF MyItem::boundingRect() const
{
    return QRectF(-10 - 0.5, -10 - 0.5, 20 + 1, 20 + 1);
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *,
                   QWidget *)
{
    painter->drawRect(-10, -10, 20, 20);
}
// 鼠标按下事件处理函数，设置被点击的图形项获得焦点，并改变光标外观
void MyItem::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    setFocus();
    setCursor(Qt::ClosedHandCursor);
}
// 键盘按下事件处理函数，判断是否是向下方向键，如果是，则向下移动图形项
void MyItem::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_S){
        animation->start();
    }
    if (event->key() == Qt::Key_E){
        animation->stop();
    }
    if (event->key() == Qt::Key_P){
        animation->pause();
    }
    if (event->key() == Qt::Key_R){
        animation->stop();
        animation->start();
        animation->pause();
    }
}
