#include "resizeablewindow.h"

ResizeableWindow::ResizeableWindow(QWidget *parent)
    : QWidget{parent}
{
    //去掉窗口边框
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setMinimumSize(200,200);
    //启动鼠标追踪
    this->setMouseTracking(true);
    m_isResizing = false;
}

void ResizeableWindow::mousePressEvent(QMouseEvent *event)
{
    if (isOnEdge(event->pos())) {
        m_isResizing = true;
        m_resizePosition = event->globalPosition().toPoint();
        m_originalSize = size();
        event->accept();
    }
}

void ResizeableWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (m_isResizing) {
        int dx = event->globalPosition().x() - m_resizePosition.x();
        int dy = event->globalPosition().y() - m_resizePosition.y();
        resize(m_originalSize.width() + dx, m_originalSize.height() + dy);
        event->accept();
    } else {
        if (isOnEdge(event->pos())) {
            setCursor(Qt::SizeFDiagCursor);
        } else {
            setCursor(Qt::ArrowCursor);
        }
    }
}

void ResizeableWindow::mouseReleaseEvent(QMouseEvent *event)
{

    if (m_isResizing) {
        m_isResizing = false;
        event->accept();
    }
}
