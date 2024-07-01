#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "resizeablewindow.h"
#include "selftoolbar.h"
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
     SelfToolBar *titlebar = nullptr;
    void initUi();
     void mousePressEvent(QMouseEvent *event) override;
     void mouseMoveEvent(QMouseEvent *event) override;
};
#endif // WIDGET_H
