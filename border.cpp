#include "border.h"

border::border(BorderType type,QWidget *parent)
    : QWidget{parent}
{
    borderType = type;
}

void border::mousePressEvent(QMouseEvent *event) {
    if (isMaximized()) {
        return QWidget::mousePressEvent(event);
    }
    if (event->button() == Qt::LeftButton) {
        switch (borderType) {
        case BorderType::TopBorder:
            this->windowHandle()->startSystemResize(Qt::TopEdge);
            break;
        case BorderType::BottomBorder:
            this->windowHandle()->startSystemResize(Qt::BottomEdge);
            break;
        case BorderType::LeftBorder:
            this->windowHandle()->startSystemResize(Qt::LeftEdge);
            break;
        case BorderType::RightBorder:
            this->windowHandle()->startSystemResize(Qt::RightEdge);
            break;
        case BorderType::LeftTopBorder:
            this->windowHandle()->startSystemResize(Qt::LeftEdge | Qt::TopEdge);
            break;
        case BorderType::RightBottomBorder:
            this->windowHandle()->startSystemResize(Qt::RightEdge | Qt::BottomEdge);
            break;
        case BorderType::LeftBottomBorder:
            this->windowHandle()->startSystemResize(Qt::LeftEdge | Qt::BottomEdge);
            break;
        case BorderType::RightTopBorder:
           this->windowHandle()->startSystemResize(Qt::RightEdge | Qt::TopEdge);
            break;
        }
    }
    QWidget::mousePressEvent(event);
}

void border::mouseMoveEvent(QMouseEvent *event) {
    if (isMaximized()) {
        setCursor(Qt::ArrowCursor);
        return QWidget::mouseMoveEvent(event);
    }
    switch (borderType) {
    case BorderType::TopBorder:
    case BorderType::BottomBorder:
        setCursor(Qt::SizeVerCursor);
        break;
    case BorderType::LeftBorder:
    case BorderType::RightBorder:
        setCursor(Qt::SizeHorCursor);
        break;
    case BorderType::LeftTopBorder:
    case BorderType::RightBottomBorder:
        setCursor(Qt::SizeFDiagCursor);
        break;
    case BorderType::LeftBottomBorder:
    case BorderType::RightTopBorder:
        setCursor(Qt::SizeBDiagCursor);
        break;
    }
    QWidget::mouseMoveEvent(event);
}

void border::FixedSize() {
    switch (borderType) {
    case BorderType::TopBorder:
    case BorderType::BottomBorder:
        setFixedHeight(borderWidth);
        break;
    case BorderType::LeftBorder:
    case BorderType::RightBorder:
        setFixedWidth(borderWidth);
        break;
    default:
        this->setFixedSize(borderWidth, borderWidth);
        break;
    }
}

bool border::isMaximized() const {
    return window()->windowState() & Qt::WindowMaximized;
}

