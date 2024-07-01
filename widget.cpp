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


    gridLayout = new QGridLayout(this);
    gridLayout->setSpacing(0);
    gridLayout->setContentsMargins(10,0,10,0);


    left_border = new border(BorderType::LeftBorder);
    gridLayout->addWidget(left_border,1,1,1,1);

    left_top_border = new border(BorderType::LeftTopBorder);
    gridLayout->addWidget(left_top_border,0,1,1,1);

    right_top_border = new border(BorderType::RightTopBorder);
    gridLayout->addWidget(right_top_border,0,3,1,1);

    top_border = new border(BorderType::TopBorder);
    gridLayout->addWidget(top_border,0,2,1,1);

    //主区域
    gridLayout->addLayout(pVlay,1,2,1,1);


    bottom_border = new border(BorderType::BottomBorder);
    gridLayout->addWidget(bottom_border,2,2,1,1);


    left_bottom_border = new border(BorderType::LeftBottomBorder);
    gridLayout->addWidget(left_bottom_border,2,1,1,1);

    right_border = new border(BorderType::RightBorder);
    gridLayout->addWidget(right_border,1,3,1,1);

    right_bottom_border = new border(BorderType::RightBottomBorder);
    gridLayout->addWidget(right_bottom_border,2,3,1,1);


}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        this->windowHandle()->startSystemMove();
    }

    // if (event->button() == Qt::LeftButton) {
    //     if (isOnEdge(event->pos())) {
    //         currentAction = ResizeWindow;
    //         originalSize = size();
    //         this->windowHandle()->startSystemResize(Qt::Edge::TopEdge);
    //     } else {
    //         currentAction = MoveWindow;
    //         dragPosition = event->globalPosition().toPoint() - frameGeometry().topLeft();
    //     }
    //     event->accept();
    // }
}
void Widget::mouseMoveEvent(QMouseEvent *event)
{
    // if (currentAction == NoAction) {
    //     if (isOnEdge(event->pos())) {
    //         setCursor(Qt::SizeFDiagCursor);
    //     } else {
    //         setCursor(Qt::ArrowCursor);
    //     }
    // } else if (currentAction == MoveWindow) {
    //     if (this->windowHandle()) {
    //         this->windowHandle()->startSystemMove();
    //     }
    // } else if (currentAction == ResizeWindow) {
    //     int dx = event->globalPosition().x() - dragPosition.x();
    //     int dy = event->globalPosition().y() - dragPosition.y();
    //     resize(originalSize.width() + dx,originalSize.height() + dy);
    // }
    // event->accept();
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
