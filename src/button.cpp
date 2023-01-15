#include "button.h"

button::button(int stageid,bool visible,QWidget*parent)
    :QPushButton(parent),stageid(stageid),visible(visible)
{

}
button::~button(){}
