// #ifndef WIDGET_H
// #define WIDGET_H

// #include <QWidget>
// #include "resizeablewindow.h"
// #include "selftoolbar.h"
// #include "border.h"
// #include <QGridLayout>
// class Widget : public QWidget
// {
//     Q_OBJECT

// public:
//     Widget(QWidget *parent = nullptr);
//     ~Widget();
// private:
//      SelfToolBar *titlebar = nullptr;
//     void initUi();

//      enum WindowAction {
//          NoAction,
//          MoveWindow,
//          ResizeWindow
//      };
//     WindowAction currentAction;
//     QPoint dragPosition;
//     QSize originalSize;
//     bool isOnEdge(const QPoint &pos) const;

//     QGridLayout *gridLayout = nullptr;

//     border *left_border = nullptr;
//     border *left_top_border = nullptr;
//     border *right_top_border = nullptr;
//     border *top_border = nullptr;
//     border *bottom_border = nullptr;
//     border *left_bottom_border = nullptr;
//     border *right_border = nullptr;
//     border *right_bottom_border = nullptr;

//     //还差一个主区域




// protected:
//      void mousePressEvent(QMouseEvent *event) override;
//      void mouseMoveEvent(QMouseEvent *event) override;
//      void mouseReleaseEvent(QMouseEvent *event) override;
// };
// #endif // WIDGET_H
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>


enum Location {
    TOP,
    BOTTOM,
    LEFT,
    RIGHT,
    TOP_LEFT,
    TOP_RIGHT,
    BOTTOM_LEFT,
    BOTTOM_RIGHT,
    CENTER

};


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
private:
    void setCursorShape(const QPoint& globalPos);
    void test();
private:
    bool isLeftPressed;
    //点击位置针对程序左上角的位置
    QPoint mouseOffset;
    Location location;
};
#endif // WIDGET_H
