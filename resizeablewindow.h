#ifndef RESIZEABLEWINDOW_H
#define RESIZEABLEWINDOW_H

#include <QWidget>
#include <QMouseEvent>

class ResizeableWindow : public QWidget
{
    Q_OBJECT
public:
    explicit ResizeableWindow(QWidget *parent = nullptr);
private:
    bool m_isResizing = false;
    //重写鼠标按下，移动的事件
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    bool isOnEdge(const QPoint &pos) const {
        const int edgeMargin = 10;  // 边缘检测范围
        return pos.x() >= width() - edgeMargin && pos.y() >= height() - edgeMargin;
    }
    QPoint m_resizePosition;
    QSize m_originalSize;

signals:
};

#endif // RESIZEABLEWINDOW_H
