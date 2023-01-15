#ifndef CARD_H
#define CARD_H
#include<QString>
#include<vector>
#include<ctime>
#define UNSTUDY 0
#define STUDYING 1
#define REVIEW 2


#define BLUE 1
#define GREEN 2
#define ORANGE 3
#define PINK 4
#define PURPLE 5
#define RED 6
#define NONE 0
#include <QtCore/qmath.h>
#include<QDebug>
using namespace std;
class card
{
public:
    card(){marked=false;markcolor=NONE;}
    card( QString positive,QString negative,QString label,bool visible,int state):
        positive(positive),negative(negative),label(label),visible(visible),state(state){marked=false;markcolor=NONE;diftime=60;comtime=300;easytime=600;}
    ~card(){}
public:
    QString positive;//卡片正面
    QString negative;//卡片背面
    QString label;//标签
    bool visible;//是否可见
    bool marked;//是否标记
    vector<int>studytimes;//记录每次熟练程度
    int state;//当前状态
    double r;//两次出现的时间间隔
    int lastindex;//上一次序号
    int markcolor;//旗标颜色
    int reviewtime;//复习时间
    int diftime;//困难间隔时间
    int comtime;//一般间隔时间
    int easytime;//简单间隔时间
    clock_t card_time;//卡片点击后时间
public:
    //良好或简单的次数
    int num_good(vector<int>studytimes)
    {
        int sum=0;
        for(unsigned int i=0;i<studytimes.size();i++)
        {
           if(studytimes[i]>=3)
           {
               sum+=1;
           }
        }
        return sum;
    }
    //忘记的比例
    double returnfor(vector<int>studytimes)
    {
        int sum=0;
        for(int i=0;i<studytimes.size();i++)
        {
            if(studytimes[i]==1)
            {
                sum+=1;
            }
        }
        if(studytimes.size()!=0)
        {
            return 100*sum/studytimes.size();
        }
        else
        {
            return -1;
        }
    }
    //忘记或困难的比例
    int returndif(vector<int>studytimes)
    {
        int sum=0;
        for(int i=0;i<studytimes.size();i++)
        {
            if(studytimes[i]==2)
            {
                sum+=1;
            }
        }
        if(studytimes.size()!=0)
        {
            return 100*sum/studytimes.size();
        }
        else
        {
            return -1;
        }
    }
    //计算历次点击的平均值
    double returntype(vector<int>studytimes)
    {
        double sum=0;
        for(unsigned int i=0;i<studytimes.size();i++)
        {
            sum+=studytimes[i];
        }
        return sum/studytimes.size();
    }
    //判断是否到时间复习
   bool is_ontime(clock_t now_time)
   {
       reviewtime=10000;
       if(returntype(studytimes)<2)
       {
           reviewtime=diftime;
       }
       else if(returntype(studytimes)<2.5)
       {
           reviewtime=comtime;
       }
       else if(returntype(studytimes)<3.2)
       {
           reviewtime=easytime;
       }
       r=(double)(now_time-card_time)/(double)CLOCKS_PER_SEC;
       if(r>(double)reviewtime)
       {
           return true;
       }
       else
       {
           return false;
       }
   }
};

#endif // CARD_H
