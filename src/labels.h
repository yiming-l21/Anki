#ifndef LABELS_H
#define LABELS_H
#include<QLabel>

class label:public QLabel
{
    Q_OBJECT
public:
    label(int stageid,bool visible,QWidget*parent=nullptr);
    ~label();
    int stageid;
    bool visible;
    QString name;



};

#endif // LABELS_H
