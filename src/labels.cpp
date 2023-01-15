#include "labels.h"



label::label(int stageid,bool visible,QWidget*parent)
    :QLabel(parent),stageid(stageid),visible(visible)
{

}
label::~label(){}
