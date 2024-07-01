#ifndef BORDER_H
#define BORDER_H

#include <QWidget>
#include <QMouseEvent>
#include <QWindow>

enum class BorderType {
    TopBorder = 1,
    BottomBorder,
    LeftBorder,
    RightBorder,
    LeftTopBorder,
    RightTopBorder,
    LeftBottomBorder,
    RightBottomBorder
};



class border : public QWidget
{
    Q_OBJECT
public:
    explicit border(BorderType borderType,QWidget *parent = nullptr);


protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    BorderType borderType;
    int borderWidth;
    void FixedSize();
    bool isMaximized() const;

signals:
};

#endif // BORDER_H
