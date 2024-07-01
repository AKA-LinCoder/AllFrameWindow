#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "resizeablewindow.h"
#include "selftoolbar.h"
#include "border.h"
#include <QGridLayout>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
     SelfToolBar *titlebar = nullptr;
    void initUi();

     enum WindowAction {
         NoAction,
         MoveWindow,
         ResizeWindow
     };
    WindowAction currentAction;
    QPoint dragPosition;
    QSize originalSize;
    bool isOnEdge(const QPoint &pos) const;

    QGridLayout *gridLayout = nullptr;

    border *left_border = nullptr;
    border *left_top_border = nullptr;
    border *right_top_border = nullptr;
    border *top_border = nullptr;
    border *bottom_border = nullptr;
    border *left_bottom_border = nullptr;
    border *right_border = nullptr;
    border *right_bottom_border = nullptr;

    //还差一个主区域




protected:
     void mousePressEvent(QMouseEvent *event) override;
     void mouseMoveEvent(QMouseEvent *event) override;
     void mouseReleaseEvent(QMouseEvent *event) override;
};
#endif // WIDGET_H
