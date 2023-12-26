#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setFixedSize(600,800);

    m_label = new QLabel("功德+1",this);
    m_label->move(250,150);
    m_label->setStyleSheet("color: rgb(255, 255, 255);"
                           "font: 16pt Times New Roman");
    m_label->show();
    m_animation = new QPropertyAnimation(m_label,"geometry");
    m_animation->setDuration(100);
    m_animation->setStartValue(QRect(250, 320, 100, 30));
    m_animation->setEndValue(QRect(250, 150, 100, 30));

    m_sound = new QMediaPlayer(this);
    m_sound->setMedia(QUrl::fromLocalFile("E:/workspace/QT/Wooden_fish/res/1.wav"));
    m_sound->setPlaybackRate(3);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::animationstart()
{


}

void Widget::on_pushButton_pressed()
{
    if(m_sound->state() == QMediaPlayer::PlayingState)
    {
        m_sound->stop();
        m_sound->play();
    }
    else
    {
        m_sound->play();
    }
    m_animation->start();
    ++m_num;
    QString str = QString("今日功德：%1").arg(m_num);
    ui->label->setText(str);

    ui->pushButton->setGeometry(ui->pushButton->x()+5,ui->pushButton->y()+5,ui->pushButton->width()-10,ui->pushButton->height()-10);
}


void Widget::on_pushButton_released()
{
    ui->pushButton->setGeometry(ui->pushButton->x()-5,ui->pushButton->y()-5,ui->pushButton->width()+10,ui->pushButton->height()+10);
}

