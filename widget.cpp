#include "widget.h"
#include <QVBoxLayout>
#include <QWindow>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent), currentAction(NoAction)
{
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowMinMaxButtonsHint);
     this->setAttribute(Qt::WA_Hover);
    initUi();

    // connect(titlebar.mi)
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

    if (event->button() == Qt::LeftButton) {
        if (isOnEdge(event->pos())) {
            currentAction = ResizeWindow;
            originalSize = size();
        } else {
            currentAction = MoveWindow;
            dragPosition = event->globalPosition().toPoint() - frameGeometry().topLeft();
        }
        event->accept();
    }
}
void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if (currentAction == NoAction) {
        if (isOnEdge(event->pos())) {
            setCursor(Qt::SizeFDiagCursor);
        } else {
            setCursor(Qt::ArrowCursor);
        }
    } else if (currentAction == MoveWindow) {
        if (this->windowHandle()) {
            this->windowHandle()->startSystemMove();
        }
    } else if (currentAction == ResizeWindow) {
        int dx = event->globalPosition().x() - dragPosition.x();
        int dy = event->globalPosition().y() - dragPosition.y();
        resize(originalSize.width() + dx,originalSize.height() + dy);
    }
    event->accept();
}

void Widget::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        currentAction = NoAction;
        event->accept();
    }
}

bool Widget::isOnEdge(const QPoint &pos) const {
    const int edgeMargin = 10;  // 边缘检测范围
    return pos.x() >= width() - edgeMargin && pos.y() >= height() - edgeMargin;
}
