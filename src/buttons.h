#ifndef BUTTONS_H
#define BUTTONS_H
#include<QPushButton>
namespace Ui {
class button;
}
class button: public QPushButton
{
    Q_OBJECT
public:
    bool visible;
    int stageid;
    explicit button(QPushButton *parent = 0);
    ~button();

private:
    Ui::button *ui;

};
#endif // BUTTONS_H
