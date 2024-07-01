#include "widget.h"
#include <QVBoxLayout>
#include <QWindow>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowMinMaxButtonsHint);
     this->setAttribute(Qt::WA_Hover);
    initUi();
}

Widget::~Widget() {}

void Widget::initUi(){
    titlebar = new SelfToolBar(this);
    QVBoxLayout *pVlay = new QVBoxLayout(this);
    pVlay->addWidget(titlebar);
    QWidget *p = new QWidget(this);
    p->setMinimumSize(800,600);
    pVlay->addWidget(p);
    pVlay->setContentsMargins(0,0,0,0);
}

void Widget::mousePressEvent(QMouseEvent *event)
{

    // mouse_pos = event->globalPosition().toPoint();
    // window_pos = this->pos();
    // diff_pos = mouse_pos - window_pos;


    if(event->button() == Qt::MouseButton::LeftButton)
    {

         this->windowHandle()->startSystemMove();
    }
}
void Widget::mouseMoveEvent(QMouseEvent *event)
{

    // QPointF pos = event->globalPosition();
    // this->move(pos.toPoint() - diff_pos);
}
