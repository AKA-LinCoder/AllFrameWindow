#ifndef SELFTOOLBAR_H
#define SELFTOOLBAR_H

#include <QWidget>
#include <QWidget>
#include <QLabel>
#include <QPushButton>


class SelfToolBar : public QWidget
{
    Q_OBJECT
public:
    explicit SelfToolBar(QWidget *parent = nullptr);

private:
    QLabel *pLogo;
    QLabel *pTitleTextLabel;
    QPushButton *setBtn;
    QPushButton *minBtn;
    QPushButton *maxBtn;
    QPushButton *closeBtn;
    void initUi();
signals:
};

#endif // TITLEBAR_H
