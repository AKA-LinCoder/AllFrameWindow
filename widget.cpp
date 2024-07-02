// #include "widget.h"
// #include <QVBoxLayout>
// #include <QWindow>
// #include <QDebug>

// Widget::Widget(QWidget *parent)
//     : QWidget(parent), currentAction(NoAction)
// {
//     this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowMinMaxButtonsHint);
//      this->setAttribute(Qt::WA_Hover);
//     initUi();

//     // connect(titlebar.mi)
// }

// Widget::~Widget() {}

// void Widget::initUi(){
//     titlebar = new SelfToolBar(this);
//     QVBoxLayout *pVlay = new QVBoxLayout(this);
//     pVlay->addWidget(titlebar);
//     QWidget *p = new QWidget(this);
//     p->setMinimumSize(800,600);
//     pVlay->addWidget(p);
//     pVlay->setContentsMargins(0,0,0,0);


//     gridLayout = new QGridLayout(this);
//     gridLayout->setSpacing(0);
//     gridLayout->setContentsMargins(10,0,10,0);


//     left_border = new border(BorderType::LeftBorder);
//     gridLayout->addWidget(left_border,1,1,1,1);

//     left_top_border = new border(BorderType::LeftTopBorder);
//     gridLayout->addWidget(left_top_border,0,1,1,1);

//     right_top_border = new border(BorderType::RightTopBorder);
//     gridLayout->addWidget(right_top_border,0,3,1,1);

//     top_border = new border(BorderType::TopBorder);
//     gridLayout->addWidget(top_border,0,2,1,1);

//     //主区域
//     gridLayout->addLayout(pVlay,1,2,1,1);


//     bottom_border = new border(BorderType::BottomBorder);
//     gridLayout->addWidget(bottom_border,2,2,1,1);


//     left_bottom_border = new border(BorderType::LeftBottomBorder);
//     gridLayout->addWidget(left_bottom_border,2,1,1,1);

//     right_border = new border(BorderType::RightBorder);
//     gridLayout->addWidget(right_border,1,3,1,1);

//     right_bottom_border = new border(BorderType::RightBottomBorder);
//     gridLayout->addWidget(right_bottom_border,2,3,1,1);


// }

// void Widget::mousePressEvent(QMouseEvent *event)
// {
//     if (event->button() == Qt::LeftButton)
//     {
//         this->windowHandle()->startSystemMove();
//     }

//     // if (event->button() == Qt::LeftButton) {
//     //     if (isOnEdge(event->pos())) {
//     //         currentAction = ResizeWindow;
//     //         originalSize = size();
//     //         this->windowHandle()->startSystemResize(Qt::Edge::TopEdge);
//     //     } else {
//     //         currentAction = MoveWindow;
//     //         dragPosition = event->globalPosition().toPoint() - frameGeometry().topLeft();
//     //     }
//     //     event->accept();
//     // }
// }
// void Widget::mouseMoveEvent(QMouseEvent *event)
// {
//     // if (currentAction == NoAction) {
//     //     if (isOnEdge(event->pos())) {
//     //         setCursor(Qt::SizeFDiagCursor);
//     //     } else {
//     //         setCursor(Qt::ArrowCursor);
//     //     }
//     // } else if (currentAction == MoveWindow) {
//     //     if (this->windowHandle()) {
//     //         this->windowHandle()->startSystemMove();
//     //     }
//     // } else if (currentAction == ResizeWindow) {
//     //     int dx = event->globalPosition().x() - dragPosition.x();
//     //     int dy = event->globalPosition().y() - dragPosition.y();
//     //     resize(originalSize.width() + dx,originalSize.height() + dy);
//     // }
//     // event->accept();
// }

// void Widget::mouseReleaseEvent(QMouseEvent *event) {
//     if (event->button() == Qt::LeftButton) {
//         currentAction = NoAction;
//         event->accept();
//     }
// }

// bool Widget::isOnEdge(const QPoint &pos) const {
//     const int edgeMargin = 10;  // 边缘检测范围
//     return pos.x() >= width() - edgeMargin && pos.y() >= height() - edgeMargin;
// }
#include "widget.h"
#include <QHBoxLayout>
#include <QDebug>
#include <QPushButton>


#define PADDING 5
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowFlags(Qt::WindowMinMaxButtonsHint|Qt::FramelessWindowHint);
    this->setMinimumSize(500,300);
    this->setStyleSheet("background:#303030");

    QHBoxLayout *qhb = new QHBoxLayout(this);
    QPushButton *btn1 = new QPushButton(this);
    QPushButton *btn2 = new QPushButton(this);
    btn1->setText("btn1");
    btn2->setText("btn2");
    btn1->setFixedSize(100,60);
    btn2->setFixedSize(100,60);
    qhb->addWidget(btn1);
    qhb->addWidget(btn2);

    isLeftPressed = false;

    //开启鼠标追踪，用于移动到边缘的时候改变鼠标样式
    this->setMouseTracking(true);

}

Widget::~Widget() {}

void Widget::mousePressEvent(QMouseEvent *event)
{

    switch (event->button()) {
    case Qt::RightButton:
        this->close();
        break;
    case Qt::LeftButton:
        isLeftPressed = true;
        mouseOffset = event->globalPosition().toPoint() -this->frameGeometry().topLeft();
        break;
    default:
        break;
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{

    QPoint globalPos = event->globalPosition().toPoint();

    //鼠标未按下
    if(!isLeftPressed){
        this->setCursorShape(globalPos);
        return;
    }
    //鼠标按下，并且在center位置
    if(location == Location::CENTER){
        move(globalPos-mouseOffset);
        return;
    }
    //缩放


}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{

    if(event->button() == Qt::LeftButton){
        isLeftPressed = false;
    }
}

void Widget::setCursorShape(const QPoint& globalPos)
{
    QRect rect = this->rect();
    QPoint topLeft = mapToGlobal(rect.topLeft());
    QPoint bottomRight = mapToGlobal(rect.bottomRight());

    int x = globalPos.x();
    int y = globalPos.y();

    if(x >= topLeft.x() && x <= topLeft.x() + PADDING && y>= topLeft.y() && y<= topLeft.y() + PADDING ){
        //左上
        location = Location::TOP_LEFT;
        this->setCursor(QCursor(Qt::SizeFDiagCursor));
    }else if(x <= bottomRight.x() && x >=bottomRight.x() -PADDING && y <= bottomRight.y() && y >= bottomRight.y() -PADDING){
        //右下
        location = Location::BOTTOM_RIGHT;
        this->setCursor(QCursor(Qt::SizeFDiagCursor));
    }else if(x >= topLeft.x() && x <=topLeft.x() +PADDING && y <= bottomRight.y() && y >= bottomRight.y() -PADDING){
        //左下
        location = Location::BOTTOM_LEFT;
        this->setCursor(QCursor(Qt::SizeBDiagCursor));
    }else if(x <= bottomRight.x() && x >=bottomRight.x() -PADDING && y >= topLeft.y() && y <= topLeft.y() +PADDING){
        //右上
        location = Location::TOP_RIGHT;
        this->setCursor(QCursor(Qt::SizeBDiagCursor));
    }else if(x >=topLeft.x() && x<=topLeft.x() + PADDING){
        //左边
        location = Location::LEFT;
        this->setCursor(QCursor(Qt::SizeHorCursor));
    }else if(x <=bottomRight.x() && x>=bottomRight.x() - PADDING){
        //右边
        location = Location::RIGHT;
        this->setCursor(QCursor(Qt::SizeHorCursor));
    }else if(y >=bottomRight.y() && y<=bottomRight.y() - PADDING){
        //下边
        location = Location::BOTTOM;
        this->setCursor(QCursor(Qt::SizeVerCursor));
    }else if(y >=topLeft.y() && y<=topLeft.y() + PADDING){
        //上边
        location = Location::TOP;
        this->setCursor(QCursor(Qt::SizeVerCursor));
    }
    else{
        location = Location::CENTER;
        this->setCursor(QCursor(Qt::ArrowCursor));

    }

}
