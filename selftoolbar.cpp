#include "selftoolbar.h"
#include <QHBoxLayout>

SelfToolBar::SelfToolBar(QWidget *parent)
    : QWidget{parent}
{
    initUi();
}
void SelfToolBar::initUi()
{


    //禁止父窗口影响子窗口样式
    this->setAttribute(Qt::WA_StyledBackground);
    this->setFixedHeight(32+5*2);
    this->setStyleSheet("background-color:rgb(54,54,54)");
    pLogo = new QLabel(this);
    pLogo->setFixedSize(32,32);
    pTitleTextLabel = new QLabel(this);
    pTitleTextLabel->setText("我是标题");
    pTitleTextLabel->setFixedWidth(120);
    setBtn = new QPushButton(this);
    minBtn = new QPushButton(this);
    maxBtn = new QPushButton(this);
    closeBtn = new QPushButton(this);
    setBtn->setFixedSize(32,32);
    minBtn->setFixedSize(32,32);
    maxBtn->setFixedSize(32,32);
    closeBtn->setFixedSize(32,32);

    QHBoxLayout *hlay = new QHBoxLayout(this);
    hlay->addWidget(pLogo);
    hlay->addWidget(pTitleTextLabel);
    hlay->addStretch();
    hlay->addWidget(setBtn);
    hlay->addWidget(minBtn);
    hlay->addWidget(maxBtn);
    hlay->addWidget(closeBtn);

    hlay->setContentsMargins(5,5,5,5);
}
