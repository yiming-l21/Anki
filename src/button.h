#ifndef BUTTON_H
#define BUTTON_H
#include<QWidget>
#include<QPushButton>

class button:public QPushButton
{
    Q_OBJECT
public:
    button(int stageid,bool visible,QWidget*parent=nullptr);
    button(QWidget*parent):QPushButton(parent){}
    ~button();
    int stageid;
    int index;
    bool visible;
    bool is_click;
    QString name;



};
#endif // BUTTON_H
