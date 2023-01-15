#ifndef DECKS_H
#define DECKS_H
#include"card.h"
#include"button.h"
#include<QString>
#include<vector>
using namespace std;
class deck
{
public:
    QString name;//牌组名称
    vector<card*>cards;//储存导入的所有牌
    vector<card*>unstudys;//未学习的牌
    vector<card*>studyings;//正在学习中的牌
    vector<card*>reviews;//待复习的牌
    card*currentcard;//当前牌
    bool visible;//是否可见
    int unstudy;//未学习的数量
    int studying;//正在学习的数量
    int review;//待复习的数量
    int studylen;//每日学习上限
    button*tool;//开始界面设置按钮
    int minpasstime;//通过阈值
public:
    deck(){}
    deck(QString name):name(name){
        unstudy=0;
        studying=0;
        review=0;
        studylen=20;
        minpasstime=2;
    }
    ~deck();



};
#endif // DECKS_H
