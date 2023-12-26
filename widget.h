#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPropertyAnimation>
#include <QLabel>
#include <QMediaPlayer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    void animationstart();

private slots:
    void on_pushButton_pressed();

    void on_pushButton_released();

private:
    Ui::Widget *ui;
    QLabel *m_label = nullptr;
    QPropertyAnimation *m_animation = nullptr;
    qint64 m_num = 0;
    QMediaPlayer *m_sound = nullptr;
};
#endif // WIDGET_H
