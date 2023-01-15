#include "mainwindow.h"
#include "editcard.h"
#include "ui_mainwindow.h"
#include "importdia.h"
#include "browse.h"
#include"statics.h"
#include<QLabel>
#include<QTextEdit>
#include<QDialog>
#include<QMessageBox>
#include<QString>
#include<QRect>
#include<QDebug>
#include "helpmanual.h"
#include"createcardset.h"
#include"exportdia.h"
#include<QFileDialog>
#include<QFontMetrics>
#include"maingui.h"
#include"button.h"
#include"labels.h"
#include "studyplan.h"
#include"card.h"
#include"decks.h"
#include"append.h"
#include<QTableView>
#include<QMouseEvent>
#include<QTextCharFormat>
#include <QtSql/QSqlDatabase>
#include<QColorDialog>
#include<QColor>
#include<ctime>
#include<QSqlQuery>
#include<QDateTime>
#include<QtCore>
#include<QSizePolicy>
#include"global.h"
#include<QStandardItemModel>
#include"mytableview.h"
#include"renamedeck.h"
#include"selectstudy.h"
#include"global.h"
#include<QDateTime>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


     stageid=STAGE_START;
     ui->setupUi(this);
     //将鼠标移动事件设为默认跟踪状态。注意，此处一定要写在setupui函数后，否则程序crashed
     ui->centralWidget->setMouseTracking(true);
     this->setMouseTracking(true);
     model = new QStandardItemModel(this);
     view=new mytableview(this);
     view->setMouseTracking(true);
     view->setModel(model);
     connect(view,SIGNAL(entered(QModelIndex)),this,SLOT(onhover(QModelIndex)));
     connect(view,SIGNAL(clicked(QModelIndex)),this,SLOT(onclicked(QModelIndex)));
     if(decks.empty())
     {
         deck *setdeck=new deck("系统预设");
         deckname=setdeck->name;
         decks.push_back(setdeck);
     }
     //初始化学习面板
     studytable=new QWidget(this);
     studytable->resize(1004,662);
     studytable->move(1000,850);
     //添加按钮

             button_create=new button(STAGE_START,true,this);
             button_create->move(370,780);
             button_create->resize(93,31);
             buttons.push_back(button_create);
             button_create->setText(QObject::tr("创建牌组"));
             button_import=new button(STAGE_START,true,this);
             button_import->move(530,780);
             button_import->resize(93,31);
             buttons.push_back(button_import);
             button_import->setText(QObject::tr("导入文件"));
             button_study=new button(STAGE_STUDY,false,this);
             button_study->move(455,780);
             buttons.push_back(button_study);
             button_study->setText(QObject::tr("学习计划"));
             button* studybutton=new button(STAGE_STUDY2,true,this);
             studybutton->move(580,210);
             studybutton->resize(93,31);
             buttons.push_back(studybutton);
             studybutton->setText(QObject::tr("现在学习"));
             button*edit=new button(STAGE_STUDYING,true,this);
             edit->move(30,800);
             edit->resize(93,31);
             edit->setText(QObject::tr("编辑"));
             buttons.push_back(edit);
             button*more=new button(STAGE_STUDYING,true,this);
             more->move(880,800);
             more->resize(93,31);
             more->setText(QObject::tr("更多"));
             buttons.push_back(more);
             button*ans=new button(STAGE_STUDYING1,true,this);
             ans->move(454,800);
             ans->resize(93,31);
             ans->setText(QObject::tr("显示答案"));
             buttons.push_back(ans);
             button*forget=new button(STAGE_STUDYING2,true,this);
             forget->move(240,800);
             forget->resize(93,31);
             forget->setText(QObject::tr("忘记"));
             buttons.push_back(forget);
             button*dif=new button(STAGE_STUDYING2,true,this);
             dif->move(380,800);
             dif->resize(93,31);
             dif->setText(QObject::tr("困难"));
             buttons.push_back(dif);
             button*good=new button(STAGE_STUDYING2,true,this);
             good->move(527,800);
             good->resize(93,31);
             good->setText(QObject::tr("良好"));
             buttons.push_back(good);
             button*easy=new button(STAGE_STUDYING2,true,this);
             easy->move(667,800);
             easy->setText(QObject::tr("简单"));
             easy->resize(93,31); 
             buttons.push_back(easy);
             button*line=new button(STAGE_STUDYING2,true,studytable);
             line->move(50,80);
             line->resize(900,1);
             line->setStyleSheet("color:##B3AEAE");
             buttons.push_back(line);
     QObject::connect(buttons[0],SIGNAL(clicked()),this,SLOT(on_button_create_triggerd()));
     QObject::connect(buttons[1],SIGNAL(clicked()),this,SLOT(on_action_I_triggered()));
     QObject::connect(studybutton,SIGNAL(clicked()),this,SLOT(on_butonstudy_clicked()));
     QObject::connect(ans,SIGNAL(clicked()),this,SLOT(on_ans_clicked()));
     QObject::connect(forget,SIGNAL(clicked()),this,SLOT(updatedeck1()));
     QObject::connect(dif,SIGNAL(clicked()),this,SLOT(updatedeck2()));
     QObject::connect(good,SIGNAL(clicked()),this,SLOT(updatedeck3()));
     QObject::connect(easy,SIGNAL(clicked()),this,SLOT(updatedeck4()));
     QObject::connect(edit,SIGNAL(clicked()),this,SLOT(on_edit()));
     QObject::connect(more,SIGNAL(clicked()),this,SLOT(initmore()));
      QObject::connect(button_study,SIGNAL(clicked()),this,SLOT(studyplans()));
     //添加label
     font=QFont("宋体",10,75);
     label_cardset=new label(STAGE_START,true,this);
     label_cardset->move(200,100);
     label_cardset->setText(QObject::tr("牌组"));
     label_cardset->setFont(font);
     label_unstudy=new label(STAGE_START,true,this);
     label_unstudy->move(400,100);
     label_unstudy->setText(QObject::tr("未学习"));
     label_unstudy->setFont(font);
     label_studying=new label(STAGE_START,true,this);
     label_studying->move(516,100);
     label_studying->setText(QObject::tr("学习中"));
     label_studying->setFont(font);
     label_ontime=new label(STAGE_START,true,this);
     label_ontime->move(632,100);
     label_ontime->setText(QObject::tr("待复习"));
     label_ontime->setFont(font);
     labels.push_back(label_cardset);
     labels.push_back(label_ontime);
     labels.push_back(label_studying);
     labels.push_back(label_unstudy);
     label* a1=new label(STAGE_STUDY1,true,this);
     a1->setText(QObject::tr("恭喜你完成了这个牌组！"));
     a1->resize(260,30);
     a1->move(360,150);
     a1->setFont(QFont("宋体",12,75));
    labels.push_back(a1);
     label*b=new label(STAGE_STUDY2,true,this);
     b->setText(QObject::tr("未学习:"));
     b->move(300,180);
     label*c=new label(STAGE_STUDY2,true,this);
     c->setText(QObject::tr("学习中:"));
     c->move(300,210);
     label*d=new label(STAGE_STUDY2,true,this);
     d->setText(QObject::tr("待复习:"));
     d->move(300,240);
     labels.push_back(b);
     labels.push_back(c);
     labels.push_back(d);
     label*forg=new label(STAGE_STUDYING2,true,this);
     forg->setText(QObject::tr("<1分"));
     forg->move(265,770);
     labels.push_back(forg);
     label*diff=new label(STAGE_STUDYING2,true,this);
     diff->setText(QObject::tr("<10分"));
     diff->move(403,770);
     labels.push_back(diff);
     label*go=new label(STAGE_STUDYING2,true,this);
     go->move(560,770);
     go->setText(QObject::tr("1天"));
     labels.push_back(go);
     label*ea=new label(STAGE_STUDYING2,true,this);
     ea->move(700,770);
     ea->setText(QObject::tr("4天"));
     labels.push_back(ea);     
     positive=new label(STAGE_STUDYING,true,studytable);
     positive->setMinimumSize(QSize(1000,50));
     negative=new label(STAGE_STUDYING2,true,studytable);
     Label=new label(STAGE_STUDYING2,true,studytable);
     markimg=new label(MARK,true,studytable);
     markimg->resize(63,63);
     markimg->setStyleSheet("background-image:url(:/image/mark.bmp);border:3px solid #FFFFFF");
     red=new label(MARK,true,studytable);
     red->resize(60,60);
     red->setStyleSheet("background-image:url(:/image/red.bmp);border:3px solid #FFFFFF");
     blue=new label(MARK,true,studytable);
     blue->resize(60,60);
     blue->setStyleSheet("background-image:url(:/image/blue.bmp);border:3px solid #FFFFFF");
     green=new label(MARK,true,studytable);
     green->resize(60,60);
     green->setStyleSheet("background-image:url(:/image/green.bmp);border:3px solid #FFFFFF");
     purple=new label(MARK,true,studytable);
     purple->resize(60,60);
     purple->setStyleSheet("background-image:url(:/image/purple.bmp);border:3px solid #FFFFFF");
     pink=new label(MARK,true,studytable);
     pink->resize(60,60);
     pink->setStyleSheet("background-image:url(:/image/pink.bmp);border:3px solid #FFFFFF");
     orange=new label(MARK,true,studytable);
     orange->resize(60,60);
     orange->setStyleSheet("background-image:url(:/image/orange.bmp);border:3px solid #FFFFFF");


}
void MainWindow::Initestage(int stageid)
{

    if(stageid==STAGE_START)
    {
        Stageid=STAGE_START;
        studytable->move(1000,850);
        //删除其他按钮和label

        for(unsigned int i=0;i<labels.size();i++)
        {
            if(labels[i]->stageid==STAGE_START)
            {
                labels[i]->show();

            }
            else
            {
                labels[i]->hide();
            }
        }
        //按钮
        for(unsigned int i=0;i<buttons.size();i++)
        {
            if(buttons[i]->stageid==STAGE_START)
            {
                buttons[i]->show();
            }
            else
            {
                buttons[i]->hide();
            }
        }
        if(decks.empty())
        {
            deck *setdeck=new deck("系统预设");
            deckname=setdeck->name;
            decks.push_back(setdeck);
        }

        // 添加表

        QFont font1=QFont("宋体",9,50);
        view->move(200,140);
        view->resize(550,30*decks.size());
        model->setColumnCount(4);
        view->setColumnWidth(0,200);
        view->setColumnWidth(1,116);
        view->setColumnWidth(2,116);
        view->setColumnWidth(3,116);
        view->setStyleSheet(QString("background-color:rgb(240,240,240);"));
        view->horizontalHeader()->setHidden(true);
        view->verticalHeader()->setHidden(true);
        view->setEditTriggers(QAbstractItemView::NoEditTriggers);
        view->setSelectionMode(QAbstractItemView::NoSelection);
        view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        model->setRowCount(decks.size());
        for(unsigned int i=0;i<decks.size();i++)
        {
            view->setRowHeight(i,30);
            QColor color = QColor(201,193,193);
            QString a=QString::number(decks[i]->unstudys.size(),10);
            QString b=QString::number(decks[i]->studyings.size(),10);
            QString c=QString::number(decks[i]->reviews.size(),10);
            model->setItem(i,0,new QStandardItem(decks[i]->name));
            model->setItem(i,1,new QStandardItem(a));
            model->setItem(i,2,new QStandardItem(b));
            model->setItem(i,3,new QStandardItem(c));
            decks[i]->tool=new button(view);
            decks[i]->tool->resize(28,28);
           decks[i]->tool->move(521,i*30+1);
            decks[i]->tool->name=decks[i]->name;
            connect(decks[i]->tool,SIGNAL(clicked()),this,SLOT(initmenu()));
            decks[i]->tool->setStyleSheet("background-image:url(://image/tool.bmp);");
           decks[i]->tool->show();

             if(a=="0")
             {
                 model->item(i,1)->setForeground(color);
             }
             else
             {
                  model->item(i,1)->setForeground(Qt::black);
             }
             if(b=="0")
             {
                 model->item(i,2)->setForeground(color);
             }
             else
             {
                 model->item(i,2)->setForeground(Qt::black);
             }
             if(c=="0")
             {
                 model->item(i,3)->setForeground(color);
             }
             else
             {
                 model->item(i,3)->setForeground(Qt::black);
             }
             setFont(font1);
        }
        view->show();
    }
     else if(stageid==STAGE_STUDY)
     {
         Stageid=STAGE_STUDY;
         studytable->move(1000,850);
                //将开始界面的表格隐藏
               view->move(2000,1000);

               //将开始界面的按钮设为不可见，将学习界面的按钮设为可见

               for(unsigned int i=0;i<buttons.size();i++)
               {
                   if(buttons[i]->stageid==STAGE_STUDY)
                   {
                       buttons[i]->visible=true;
                   }
                   else
                   {
                       buttons[i]->visible=false;
                   }
               }
               for(unsigned int i=0;i<buttons.size();i++)
               {
                   if(buttons[i]->visible)
                   {
                       buttons[i]->show();

                   }
                   else
                   {
                       buttons[i]->hide();
                   }
               }
               //判断当牌库中没有牌时
               unsigned int current;
               bool flag=true;
               for(unsigned int i=0;i<decks.size();i++)
               {
                   if(decks[i]==currentdeck)
                   {
                       current=i;
                       break;
                   }
               }
               for(unsigned int j=0;j<labels.size();j++)
               {
                   if(labels[j]->visible==false)
                   {
                       flag=false;
                   }
               }
               if(flag==true)
               {
                       label*a=new label(STAGE_STUDY2,true,this);
                       a->setText(decks[current]->name);
                       a->name="name";
                       QFont fon("宋体",10,75);
                       QRect rec=a->contentsRect();
                       a->resize(rec.width(),rec.height());
                       a->setFont(fon);
                       a->move(500-rec.width()/2,120);
                       label*e=new label(STAGE_STUDY2,false,this);
                       e->setText(QString::number(decks[current]->unstudy,10));
                       e->move(370,180);
                       e->name="unstudy";
                       e->setStyleSheet("QLabel{color:rgb(0,0,255)}");
                       label*f=new label(STAGE_STUDY2,false,this);
                       f->setText(QString::number(decks[current]->studying,10));
                       f->move(370,210);
                       f->name="studying";
                       f->setStyleSheet("QLabel{color:rgb(0,255,0)}");
                       label*g=new label(STAGE_STUDY2,false,this);
                       g->setText(QString::number(decks[current]->review,10));
                       g->move(370,240);
                       g->name="review";
                       g->setStyleSheet("QLabel{color:rgb(255,0,0)}");
                       labels.push_back(a);
                       labels.push_back(e);
                       labels.push_back(f);
                       labels.push_back(g);
                }
               else
               {
                   for(unsigned int k=0;k<labels.size();k++)
                   {
                       if(labels[k]->name=="name")
                       {
                           labels[k]->hide();
                           labels.erase(labels.begin()+k);
                           label*a=new label(STAGE_STUDY2,true,this);
                           a->setText(decks[current]->name);
                           a->name="name";
                           QFont fon("宋体",10,75);
                           QRect rec=a->contentsRect();
                           a->resize(rec.width(),rec.height());
                           a->setFont(fon);
                           a->move(500-rec.width()/2,120);
                           labels.push_back(a);
                           break;
                       }
                   }
                   for(unsigned int k=0;k<labels.size();k++)
                   {
                       if(labels[k]->name=="unstudy")
                       {
                           labels[k]->hide();
                           labels.erase(labels.begin()+k);
                           label*e=new label(STAGE_STUDY2,false,this);
                           e->setText(QString::number(decks[current]->unstudys.size(),10));
                           e->move(370,180);
                           e->name="unstudy";
                           e->setStyleSheet("QLabel{color:rgb(0,0,255)}");
                           labels.push_back(e);
                           break;
                       }
                   }
                   for(unsigned int k=0;k<labels.size();k++)
                   {
                       if(labels[k]->name=="studying")
                       {
                           labels[k]->hide();
                           labels.erase(labels.begin()+k);
                           label*f=new label(STAGE_STUDY2,false,this);
                           f->setText(QString::number(decks[current]->studyings.size(),10));
                           f->move(370,210);
                           f->name="studying";
                           f->setStyleSheet("QLabel{color:rgb(0,255,0)}");
                           labels.push_back(f);
                           break;
                       }
                   }
                   for(unsigned int k=0;k<labels.size();k++)
                   {
                       if(labels[k]->name=="review")
                       {
                           labels[k]->hide();
                           labels.erase(labels.begin()+k);
                           label*g=new label(STAGE_STUDY2,false,this);
                           g->setText(QString::number(decks[current]->reviews.size(),10));
                           g->move(370,240);
                           g->name="review";
                           g->setStyleSheet("QLabel{color:rgb(255,0,0)}");
                           labels.push_back(g);
                           break;
                       }
                   }
               }
               if(decks[current]->unstudys.size()==0&&decks[current]->reviews.size()==0&&decks[current]->studyings.size()==0)
               {
                  for(unsigned int i=0;i<labels.size();i++)
                  {
                      if(labels[i]->stageid==STAGE_STUDY1)
                      {
                          labels[i]->show();
                      }
                      else
                      {
                          labels[i]->hide();
                      }
                  }


               }
               else
               {

                   for(unsigned int i=0;i<labels.size();i++)
                   {
                       if(labels[i]->stageid==STAGE_STUDY2)
                       {
                           labels[i]->show();
                       }
                       else
                       {
                           labels[i]->hide();
                       }
                   }
                   for(unsigned int i=0;i<buttons.size();i++)
                   {
                       if(buttons[i]->stageid==STAGE_STUDY2)
                       {
                            buttons[i]->show();
                       }
                   }
               }
     }
    else if(stageid==STAGE_STUDYING)
    {
        Stageid=STAGE_STUDYING;
        studytable->move(-2,85);
        studytable->setStyleSheet("background-color:rgb(255,255,255);border:2px solid#B3AEAE;");
            if(currentdeck->currentcard!=NULL)
            {
                //添加题目正面
                QFontMetrics fm(QFont("宋体",18,75));
                QRect rec2=fm.boundingRect(currentdeck->currentcard->positive);
                positive->resize(100,rec2.height()+14);
                positive->setFont(QFont("宋体",18,75));
                positive->setText(currentdeck->currentcard->positive);
                positive->setScaledContents(true);
                positive->setStyleSheet("QLabel{background-color:rgb(255,255,255);border:2px solid#FFFFFF;}");
                positive->move((this->width()/2-rec2.width()/2),30);
                //添加题目反面
                QRect rec1=fm.boundingRect(currentdeck->currentcard->negative);
                negative->setText(currentdeck->currentcard->negative);
                positive->resize(rec1.width()+20,rec1.height()+14);
                negative->setFont(QFont("宋体",18,75));
                negative->setStyleSheet("QLabel{background-color:rgb(255,255,255);border:2px solid#FFFFFF;}");
                negative->move((this->width()/2-rec1.width()/2),100);
                labels.push_back(positive);
                labels.push_back(negative);
                //添加题目笔记
                QRect rec3=fm.boundingRect(currentdeck->currentcard->label);
                Label->setText(currentdeck->currentcard->label);
                Label->resize(rec3.width()+20,rec3.height()+14);
                Label->setFont(QFont("宋体",18,75));
                Label->setStyleSheet("QLabel{background-color:rgb(255,255,255);border:2px solid#FFFFFF;}");
                Label->move((this->width()/2-rec3.width()/2),180);
                labels.push_back(Label);
                //添加标记
                if(currentdeck->currentcard->marked==true)
                {
                    markimg->move(30,10);
                    markimg->show();
                }
                else
                {
                    markimg->hide();
                }
                //添加旗子
                if(currentdeck->currentcard->markcolor==NONE)
                {
                    red->hide();
                    blue->hide();
                    green->hide();
                    orange->hide();
                    pink->hide();
                    purple->hide();

                }
                else if(currentdeck->currentcard->markcolor==RED)
                {
                    red->show();
                    red->move(910,20);
                    blue->hide();
                    green->hide();
                    orange->hide();
                    pink->hide();
                    purple->hide();
                }
                else if(currentdeck->currentcard->markcolor==BLUE)
                {
                    red->hide();
                    blue->show();
                    blue->move(910,20);
                    green->hide();
                    orange->hide();
                    pink->hide();
                    purple->hide();
                }
                else if(currentdeck->currentcard->markcolor==GREEN)
                {
                    red->hide();
                    blue->hide();
                    green->show();
                    green->move(910,20);
                    orange->hide();
                    pink->hide();
                    purple->hide();
                }
                else if(currentdeck->currentcard->markcolor==ORANGE)
                {
                    red->hide();
                    blue->hide();
                    green->hide();
                    orange->show();
                    orange->move(910,20);
                    pink->hide();
                    purple->hide();
                }
                else if(currentdeck->currentcard->markcolor==PINK)
                {
                    red->hide();
                    blue->hide();
                    green->hide();
                    orange->hide();
                    pink->show();
                    pink->move(910,20);
                    purple->hide();
                }
                else if(currentdeck->currentcard->markcolor==PURPLE)
                {
                    red->hide();
                    blue->hide();
                    green->hide();
                    orange->hide();
                    pink->hide();
                    purple->show();
                    purple->move(910,20);
                }
             }
            else
            {
                point->Initestage(STAGE_STUDY);
                return;
            }
            //将开始界面的按钮设为不可见，将学习界面的按钮设为可见

            for(unsigned int i=0;i<buttons.size();i++)
            {
                if(buttons[i]->stageid==STAGE_STUDYING||buttons[i]->stageid==STAGE_STUDYING1)
                {
                    buttons[i]->visible=true;
                }
                else
                {
                    buttons[i]->visible=false;
                }
            }
            for(unsigned int i=0;i<buttons.size();i++)
            {
                if(buttons[i]->visible)
                {
                    buttons[i]->show();

                }
                else
                {
                    buttons[i]->hide();
                }
            }
            //将标签设为可见
            for(unsigned int i=0;i<labels.size();i++)
            {
                if(labels[i]->stageid==STAGE_STUDYING||labels[i]->stageid==STAGE_STUDYING1)
                {
                    labels[i]->show();
                }
                else
                {
                    labels[i]->hide();
                }
            }


    }
    else if(stageid==STAGE_STUDYING2)
    {

            Stageid=STAGE_STUDYING2;

            for(unsigned int i=0;i<buttons.size();i++)
            {
                if(buttons[i]->stageid==STAGE_STUDYING2||buttons[i]->stageid==STAGE_STUDYING)
                {
                    buttons[i]->show();
                }
                else
                {
                    buttons[i]->hide();
                }
            }
            for(unsigned int i=0;i<labels.size();i++)
            {
                if(labels[i]->stageid==STAGE_STUDYING2||labels[i]->stageid==STAGE_STUDYING)
                {
                    labels[i]->show();
                }
                else
                {
                    labels[i]->hide();

                }
            }
    }
}
void MainWindow::initmenu()
{
    currentbutton=(button*)sender();
    menu=new QMenu;
    QAction *click1=new QAction("重命名",this);
    QAction *click2=new QAction("删除",this);
    connect(click2,SIGNAL(triggered()),this,SLOT(deletedeck()));
    connect(click1,SIGNAL(triggered()),this,SLOT(renamedecks()));
    menu->addAction(click1);
    menu->addAction(click2);
    menu->move(this->x()+view->x()+currentbutton->x()+currentbutton->width(),this->y()+view->y()+currentbutton->y());
    menu->show();
}
void MainWindow::initmore()
{
    currentbutton=(button*)sender();
    moremenu=new QMenu;
    QAction*click1=new QAction("为卡片添加旗标",this);
    QAction*click7=new QAction("取消旗标",this);
    QAction*click2=new QAction("标记卡片",this);
    QAction*click6=new QAction("取消标记",this);
    QAction*click3=new QAction("删除笔记",this);
    QAction*click4=new QAction("暂停笔记",this);
    connect(click3,SIGNAL(triggered()),this,SLOT(deletecard()));
    connect(click2,SIGNAL(triggered()),this,SLOT(mark()));
    connect(click6,SIGNAL(triggered()),this,SLOT(unmark()));
    connect(click1,SIGNAL(hovered()),this,SLOT(flags()));
    connect(click7,SIGNAL(triggered()),this,SLOT(unflag()));
    connect(click4,SIGNAL(triggered()),this,SLOT(pause()));
    moremenu->addAction(click1);
    moremenu->addAction(click7);
    moremenu->addAction(click2);
    moremenu->addAction(click6);
    moremenu->addAction(click3);
    moremenu->addAction(click4);
    moremenu->move(this->x()+currentbutton->x()+currentbutton->width(),this->y()+currentbutton->y()-100);
    moremenu->show();
}
void MainWindow::pause()
{

    //删除此牌上一个副本
    if( currentdeck->currentcard->state==UNSTUDY)
    {
         currentdeck->unstudys.erase(currentdeck->unstudys.begin()+currentdeck->currentcard->lastindex);
    }
    else if(currentdeck->currentcard->state==STUDYING)
    {
        currentdeck->studyings.erase(currentdeck->studyings.begin()+currentdeck->currentcard->lastindex);
    }
    else if(currentdeck->currentcard->state==REVIEW)
    {
        currentdeck->reviews.erase(currentdeck->reviews.begin()+currentdeck->currentcard->lastindex);
    }
    currentdeck->reviews.push_back(currentdeck->currentcard);
    if(currentdeck->unstudys.size()!=0)
    {
        currentdeck->currentcard=currentdeck->unstudys[0];
        currentdeck->currentcard->state=UNSTUDY;
        currentdeck->currentcard->lastindex=0;

    }
    else
    {
        if(currentdeck->studyings.size()>=6)
        {
            unsigned int seed = QDateTime::currentDateTime().time().second();
            qsrand(seed);
            if(currentdeck->studyings.size()!=0)
            {
                int num=qrand()%currentdeck->studyings.size();
                currentdeck->currentcard=currentdeck->studyings[num];
                currentdeck->currentcard->state=STUDYING;
                currentdeck->currentcard->lastindex=num;
            }
            else
            {
                if(currentdeck->reviews.size()!=0)
                {
                    int num=qrand()%currentdeck->reviews.size();
                    currentdeck->currentcard=currentdeck->reviews[num];
                    currentdeck->currentcard->state=REVIEW;
                    currentdeck->currentcard->lastindex=num;
                }
                else
                {
                    currentdeck->currentcard=NULL;
                }
            }
        }
        else
        {
            if(currentdeck->studyings.size()!=0)
            {
                currentdeck->currentcard=currentdeck->studyings[0];
                currentdeck->currentcard->state=STUDYING;
                currentdeck->currentcard->lastindex=0;
            }
            else
            {
                if(currentdeck->reviews.size()!=0)
                {
                    currentdeck->currentcard=currentdeck->reviews[0];
                    currentdeck->currentcard->state=REVIEW;
                    currentdeck->currentcard->lastindex=0;
                }
                else
                {
                    currentdeck->currentcard=NULL;
                }
            }
        }
    }
    point->Initestage(STAGE_STUDYING);
}
void MainWindow::flags()
{
    flagmenu=new QMenu;
    QAction*blue=new QAction("蓝旗",this);
    QAction*red=new QAction("红旗",this);
    QAction*green=new QAction("绿旗",this);
    QAction*orange=new QAction("橙旗",this);
    QAction*pink=new QAction("粉旗",this);
    QAction*purple=new QAction("紫旗",this);
    connect(red,SIGNAL(triggered()),this,SLOT(red1()));
    connect(blue,SIGNAL(triggered()),this,SLOT(blue1()));
    connect(green,SIGNAL(triggered()),this,SLOT(green1()));
    connect(pink,SIGNAL(triggered()),this,SLOT(pink1()));
    connect(purple,SIGNAL(triggered()),this,SLOT(purple1()));
    connect(orange,SIGNAL(triggered()),this,SLOT(orange1()));
    flagmenu->addAction(blue);
    flagmenu->addAction(green);
    flagmenu->addAction(orange);
    flagmenu->addAction(pink);
    flagmenu->addAction(purple);
    flagmenu->addAction(red);
    moremenu->show();
    flagmenu->move(this->x()+currentbutton->x()+currentbutton->width()+moremenu->width(),this->y()+currentbutton->y()-100);
    flagmenu->show();
}
void MainWindow::deletedeck()
{
     for(int i=0;i<decks.size();i++)
     {
         if(decks[i]->name==currentbutton->name)
         {
             decks.erase(decks.begin()+i);
         }
     }
    point->Initestage(STAGE_START);
}
void MainWindow::mark()
{
    currentdeck->currentcard->marked=true;
    point->Initestage(STAGE_STUDYING);
}
void MainWindow::unmark()
{
    currentdeck->currentcard->marked=false;
    point->Initestage(STAGE_STUDYING);
}
void MainWindow::deletecard()
{

    for(int i=0;i<currentdeck->cards.size();i++)
    {
        if(currentdeck->cards[i]->positive==currentdeck->currentcard->positive)
        {
            if(currentdeck->cards[i]->negative==currentdeck->currentcard->negative)
            {
                if(currentdeck->cards[i]->label==currentdeck->currentcard->label)
                {
                    currentdeck->cards.erase(currentdeck->cards.begin()+i);
                }

            }

        }
    }
    if(currentdeck->currentcard->state==UNSTUDY)
    {
        for(int i=0;i<currentdeck->unstudys.size();i++)
        {
            if(currentdeck->unstudys[i]->positive==currentdeck->currentcard->positive)
            {
                if(currentdeck->unstudys[i]->negative==currentdeck->currentcard->negative)
                {
                    if(currentdeck->unstudys[i]->label==currentdeck->currentcard->label)
                    {
                        currentdeck->unstudys.erase(currentdeck->unstudys.begin()+i);
                    }

                }

            }
        }
    }
    else if(currentdeck->currentcard->state==STUDYING)
    {
        for(int i=0;i<currentdeck->studyings.size();i++)
        {
            if(currentdeck->studyings[i]->positive==currentdeck->currentcard->positive)
            {
                if(currentdeck->studyings[i]->negative==currentdeck->currentcard->negative)
                {
                    if(currentdeck->studyings[i]->label==currentdeck->currentcard->label)
                    {
                        currentdeck->studyings.erase(currentdeck->studyings.begin()+i);
                    }

                }

            }
        }
    }
    else if(currentdeck->currentcard->state==REVIEW)
    {
        for(int i=0;i<currentdeck->reviews.size();i++)
        {
            if(currentdeck->reviews[i]->positive==currentdeck->currentcard->positive)
            {
                if(currentdeck->reviews[i]->negative==currentdeck->currentcard->negative)
                {
                    if(currentdeck->reviews[i]->label==currentdeck->currentcard->label)
                    {
                        currentdeck->reviews.erase(currentdeck->reviews.begin()+i);
                    }

                }

            }
        }
    }
    selectedcard(currentdeck);
    point->Initestage(STAGE_STUDYING);
}
void MainWindow::renamedecks()
{
    renamedeck a(this);
    a.b=new QTextEdit(&a);
    a.b->resize(570,30);
    a.b->move(30,60);
    a.b->setText(currentbutton->name);
    QLabel label(&a);
    label.setText(QObject::tr("新牌组名称:"));
    label.move(15,15);
    a.setModal(true);
    a.show();
    a.exec();
   this->Initestage(stageid);
}
void MainWindow::unflag()
{
    currentdeck->currentcard->markcolor=NONE;
    point->Initestage(STAGE_STUDYING);
}
void MainWindow::red1()
{
    currentdeck->currentcard->markcolor=RED;
    point->Initestage(STAGE_STUDYING);
}
void MainWindow::blue1()
{
    currentdeck->currentcard->markcolor=BLUE;
    point->Initestage(STAGE_STUDYING);
}
void MainWindow::orange1()
{
    currentdeck->currentcard->markcolor=ORANGE;
    point->Initestage(STAGE_STUDYING);
}
void MainWindow::pink1()
{
    currentdeck->currentcard->markcolor=PINK;
    point->Initestage(STAGE_STUDYING);
}
void MainWindow::purple1()
{
    currentdeck->currentcard->markcolor=PURPLE;
    point->Initestage(STAGE_STUDYING);
}
void MainWindow::green1()
{
    currentdeck->currentcard->markcolor=GREEN;
    point->Initestage(STAGE_STUDYING);
}
void MainWindow::onhover(const QModelIndex & index)
{
   for(unsigned int i=0;i<decks.size();i++)
   {
       QFont fonts("宋体",9,50);
       fonts.setUnderline(false);
       model->item(i,0)->setFont(fonts);
   }
    if(index.column()==0)
    {
        QFont fonts("宋体",9,75);
        fonts.setUnderline(true);
        view->setCursor(QCursor(Qt::PointingHandCursor));
        model->item(index.row(),0)->setFont(fonts);
         fonts.setUnderline(false);
    }
    else
    {
        QFont fonts("宋体",9,50);
        fonts.setUnderline(false);
        view->setCursor(QCursor(Qt::ArrowCursor));
        model->item(index.row(),0)->setFont(fonts);
    }
}
void MainWindow::mouseMoveEvent(QMouseEvent*E )
{
            QFont fonts("宋体",9,50);
            fonts.setUnderline(false);
            for(unsigned int i=0;i<decks.size();i++)
            {
                model->item(i,0)->setFont(fonts);
            }
}

void MainWindow::onclicked(const QModelIndex &index)
{
    if(index.column()==0)
    {
        currentdeck=decks[index.row()];
        Stageid=STAGE_STUDY;
        this->Initestage(Stageid);
        this->show();
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::updatedeck0()
{
        if(currentdeck->unstudys.size()>0)
        {
            currentdeck->currentcard=currentdeck->unstudys[0];
            currentdeck->currentcard->state=UNSTUDY;
            currentdeck->currentcard->lastindex=0;
        }
        else if(currentdeck->studyings.size()>0)
        {
            currentdeck->currentcard=currentdeck->studyings[0];
            currentdeck->currentcard->state=STUDYING;
            currentdeck->currentcard->lastindex=0;
        }
        else if(currentdeck->reviews.size()>0)
        {
            currentdeck->currentcard=currentdeck->reviews[0];
            currentdeck->currentcard->state=REVIEW;
            currentdeck->currentcard->lastindex=0;
        }
    this->Initestage(STAGE_STUDYING);
}
void MainWindow::updatedeck1()
{
    //然后删除该牌在上一个牌库中的位置的副本
    if( currentdeck->currentcard->state==UNSTUDY)
    {
         currentdeck->unstudys.erase(currentdeck->unstudys.begin()+currentdeck->currentcard->lastindex);
    }
    else if(currentdeck->currentcard->state==STUDYING)
    {
        currentdeck->studyings.erase(currentdeck->studyings.begin()+currentdeck->currentcard->lastindex);
    }
    else if(currentdeck->currentcard->state==REVIEW)
    {
        currentdeck->reviews.erase(currentdeck->reviews.begin()+currentdeck->currentcard->lastindex);
    }
    /*处理上一张牌，当用户忘记一张牌时，直接将该牌置为学习中*/
    currentdeck->currentcard->studytimes.push_back(1);
    currentdeck->currentcard->card_time=clock();
    currentdeck->currentcard->state=STUDYING;
    currentdeck->currentcard->lastindex=currentdeck->studyings.size();
    currentdeck->studyings.push_back(currentdeck->currentcard);

    /*然后下面就要将currentcard赋值，其中推荐顺序由推荐函数给出*/
    selectedcard(currentdeck);
    this->Initestage(STAGE_STUDYING);
}
void MainWindow::updatedeck2()
{
    //然后删除该牌在上一个牌库中的位置的副本
    if( currentdeck->currentcard->state==UNSTUDY)
    {
         currentdeck->unstudys.erase(currentdeck->unstudys.begin()+currentdeck->currentcard->lastindex);
    }
    else if(currentdeck->currentcard->state==STUDYING)
    {
        currentdeck->studyings.erase(currentdeck->studyings.begin()+currentdeck->currentcard->lastindex);
    }
    else if(currentdeck->currentcard->state==REVIEW)
    {
        currentdeck->reviews.erase(currentdeck->reviews.begin()+currentdeck->currentcard->lastindex);
    }

    /*处理上一张牌，当用户认为此牌困难时，直接置为学习中*/
    currentdeck->currentcard->studytimes.push_back(2);
    currentdeck->currentcard->card_time=clock();
    currentdeck->currentcard->state=STUDYING;
    currentdeck->currentcard->lastindex=currentdeck->studyings.size();
    currentdeck->studyings.push_back(currentdeck->currentcard);

    /*然后下面就要将currentcard赋值，其中推荐顺序由推荐函数给出*/
    selectedcard(currentdeck);
    this->Initestage(STAGE_STUDYING);


}
void MainWindow::updatedeck3()
{
    //然后删除该牌在上一个牌库中的位置的副本
    if( currentdeck->currentcard->state==UNSTUDY)
    {
         currentdeck->unstudys.erase(currentdeck->unstudys.begin()+currentdeck->currentcard->lastindex);
    }
    else if(currentdeck->currentcard->state==STUDYING)
    {
        currentdeck->studyings.erase(currentdeck->studyings.begin()+currentdeck->currentcard->lastindex);
    }
    else if(currentdeck->currentcard->state==REVIEW)
    {
        currentdeck->reviews.erase(currentdeck->reviews.begin()+currentdeck->currentcard->lastindex);
    }
    /*处理上一张牌，此时将上一张牌归入待复习或者学习中的方法是看这种牌
    的studytimes这个数字vector的平均值是否达到了标准。如果在2.5以下
    ，则置为学习中，如果在2.5以上3.2以下则置为待复习,否则删除该牌（后期可能会标记该牌下次
      复习的时间，并归还数据库中）*/
    currentdeck->currentcard->studytimes.push_back(3);
    currentdeck->currentcard->card_time=clock();
    double average=currentdeck->currentcard->returntype(currentdeck->currentcard->studytimes);
    if(average<2.5&&currentdeck->currentcard->num_good(currentdeck->currentcard->studytimes)<currentdeck->minpasstime)
    {
        currentdeck->currentcard->state=STUDYING;
        currentdeck->currentcard->lastindex=currentdeck->studyings.size();
        currentdeck->studyings.push_back(currentdeck->currentcard);
    }
    else if(average<3.2&&currentdeck->currentcard->num_good(currentdeck->currentcard->studytimes)<currentdeck->minpasstime)
    {
        currentdeck->currentcard->state=REVIEW;
        currentdeck->currentcard->lastindex=currentdeck->reviews.size();
        currentdeck->reviews.push_back(currentdeck->currentcard);
    }

    /*然后下面就要将currentcard赋值，其中推荐顺序由推荐函数给出*/
    selectedcard(currentdeck);
    this->Initestage(STAGE_STUDYING);
}
void MainWindow::updatedeck4()
{
    //然后删除该牌在上一个牌库中的位置的副本
    if( currentdeck->currentcard->state==UNSTUDY)
    {
         currentdeck->unstudys.erase(currentdeck->unstudys.begin()+currentdeck->currentcard->lastindex);
    }
    else if(currentdeck->currentcard->state==STUDYING)
    {

        currentdeck->studyings.erase(currentdeck->studyings.begin()+currentdeck->currentcard->lastindex);
    }
    else if(currentdeck->currentcard->state==REVIEW)
    {
        currentdeck->reviews.erase(currentdeck->reviews.begin()+currentdeck->currentcard->lastindex);
    }
    /*处理上一张牌，此时将上一张牌归入待复习或者学习中的方法是看这种牌
    的studytimes这个数字vector的平均值是否达到了标准。如果在2.5以下
    ，则置为学习中，如果在2.5以上3.2以下则置为待复习,否则删除该牌（后期可能会标记该牌下次
      复习的时间，并归还数据库中）*/
    currentdeck->currentcard->studytimes.push_back(4);
    currentdeck->currentcard->card_time=clock();
    double average=currentdeck->currentcard->returntype(currentdeck->currentcard->studytimes);
    if(average<2.5&&currentdeck->currentcard->num_good(currentdeck->currentcard->studytimes)<currentdeck->minpasstime)
    {
        currentdeck->currentcard->state=STUDYING;
        currentdeck->currentcard->lastindex=currentdeck->studyings.size();
        currentdeck->studyings.push_back(currentdeck->currentcard);
    }
    else if(average<3.2&&currentdeck->currentcard->num_good(currentdeck->currentcard->studytimes)<currentdeck->minpasstime)
    {
        currentdeck->currentcard->state=REVIEW;
        currentdeck->currentcard->lastindex=currentdeck->reviews.size();
        currentdeck->reviews.push_back(currentdeck->currentcard);
    }

    /*然后下面就要将currentcard赋值，其中推荐顺序由推荐函数给出*/
    selectedcard(currentdeck);
    this->Initestage(STAGE_STUDYING);
}
void MainWindow::selectedcard(deck*currentdeck)
 {
     /*推荐算法的答题思路如下，首先遍历studying和review这两个vector中的元素，
      看其是否到时间应该复习，如果该复习则返回该元素，否则将从unstudyvector中
     选择一个元素。如果unstudy中元素为空，则依次从studying和review这两个vector
     中随机选择一个元素返回，若两者皆为空，则返回NULL*/
     for(unsigned int i=0;i<currentdeck->studyings.size();i++)
     {

         if(currentdeck->studyings[i]->is_ontime(clock())==true)
         {
             currentdeck->currentcard=currentdeck->studyings[i];
             currentdeck->currentcard->state=STUDYING;
             currentdeck->currentcard->card_time=clock();
             currentdeck->currentcard->lastindex=i;
             return;
         }
     }
     for(unsigned int i=0;i<currentdeck->reviews.size();i++)
     {
         if(currentdeck->reviews[i]->is_ontime(clock())==true)
         {
             currentdeck->currentcard=currentdeck->reviews[i];
             currentdeck->currentcard->state=REVIEW;
             currentdeck->currentcard->card_time=clock();
             currentdeck->currentcard->lastindex=i;
             return;
         }
     }
     //如果这两个容器中的牌都还没有到时间，则：
     if(currentdeck->unstudys.size()!=0)
     {
         currentdeck->currentcard=currentdeck->unstudys[0];
         currentdeck->currentcard->state=UNSTUDY;
         currentdeck->currentcard->lastindex=0;
         return;

     }
     else
     {
         if(currentdeck->studyings.size()>=6)
         {
             unsigned int seed = QDateTime::currentDateTime().time().second();
             qsrand(seed);
             if(currentdeck->studyings.size()!=0)
             {
                 int num=qrand()%currentdeck->studyings.size();
                 currentdeck->currentcard=currentdeck->studyings[num];
                 currentdeck->currentcard->state=STUDYING;
                 currentdeck->currentcard->lastindex=num;
                 return;
             }
             else
             {
                 if(currentdeck->reviews.size()!=0)
                 {
                     int num=qrand()%currentdeck->reviews.size();
                     currentdeck->currentcard=currentdeck->reviews[num];
                     currentdeck->currentcard->state=REVIEW;
                     currentdeck->currentcard->lastindex=num;
                 }
                 else
                 {
                     currentdeck->currentcard=NULL;
                 }
             }
         }
         else
         {
             if(currentdeck->studyings.size()!=0)
             {
                 currentdeck->currentcard=currentdeck->studyings[0];
                 currentdeck->currentcard->state=STUDYING;
                 currentdeck->currentcard->lastindex=0;
                 return;
             }
             else
             {
                 if(currentdeck->reviews.size()!=0)
                 {
                     currentdeck->currentcard=currentdeck->reviews[0];
                     currentdeck->currentcard->state=REVIEW;
                     currentdeck->currentcard->lastindex=0;
                 }
                 else
                 {
                     currentdeck->currentcard=NULL;
                 }
             }
         }
     }

 }
void MainWindow::on_edit()
{
    editcard a(this);
    a.show();
    a.exec();
}
void MainWindow::on_butonstudy_clicked()
{
    this->updatedeck0();
    Stageid=STAGE_STUDYING;
}
void MainWindow::on_ans_clicked()
{
    Stageid=STAGE_STUDYING2;
    point->Initestage(Stageid);
}
void MainWindow::on_action_X_triggered()
{

    close();
}

void MainWindow::on_action_G_triggered()
{
   helpmanual help(this);
   help.setModal(true);
   help.show();
   help.exec();

}

void MainWindow::on_action_I_triggered()
{
   QFileDialog *fileDialog = new QFileDialog(this);
   fileDialog->setWindowTitle(tr("导入"));
   fileDialog->setDirectory(".");
   QStringList filters;
   filters<<QString("*.txt");
   fileDialog->setNameFilters(filters);
   if(fileDialog->exec() == QDialog::Accepted)
   {
       int num=0;
        QString path = fileDialog->selectedFiles()[0];
        QFile file(path);
        QFileInfo fi(file);
        deck*newdeck=new deck(fi.baseName());
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                QString line;
                QTextStream in(&file);  //用文件构造流
                line = in.readLine();//读取一行放到字符串
                while(!line.isNull())//字符串有内容
                {
                    QStringList list=line.split(QRegExp("\\s+"));
                    card*newcard=new card;
                    if(list.size()>=3)
                    {
                        newcard->positive=list[0];
                        newcard->negative=list[1];
                        newcard->label=list[2];
                    }
                    else if(list.size()==2)
                    {
                        newcard->positive=list[0];
                        newcard->negative=list[1];
                        newcard->label="";
                    }
                    else if(list.size()==1)
                    {
                         newcard->positive=list[0];
                         newcard->label="";

                    }
                    if(newdeck->unstudys.size()<newdeck->studylen)
                    {
                         newdeck->unstudys.push_back(newcard);
                         newcard->state=UNSTUDY;
                         newcard->lastindex=newdeck->unstudys.size()-1;
                         newdeck->unstudy+=1;

                    }
                    newdeck->cards.push_back(newcard);
                    line=in.readLine();//循环读取下行
                    num++;
                }

                decks.push_back(newdeck);
            }
        point->Initestage(STAGE_START);
        importdia*a=new importdia(this);
        a->textEdit->setText(tr("文件中找到的笔记 : ")+QString::number(num,10));
        for(int i=0;i<num;i++)
        {
            a->textEdit->append(tr("[已添加] ")+newdeck->cards[i]->positive+tr(" ")+newdeck->cards[i]->negative+tr(" ")+newdeck->cards[i]->label);
        }
        a->show();
        a->exec();

   }



}
void MainWindow::on_button_create_triggerd()
{
    createcardset create(this);
    QLabel label(&create);
    label.setText(QObject::tr("新牌组名称:"));
    label.move(15,15);
    create.setModal(true);
    create.show();
    create.exec();
    this->Initestage(stageid);

}

void MainWindow::on_action_E_triggered()
{
    EXPORTDIA exportdialog(this);
    QLabel label1(&exportdialog);
    label1.setText(QObject::tr("导出格式:"));
    label1.move(30,15);
    QLabel label2(&exportdialog);
    label2.setText(QObject::tr("包含:"));
    label2.move(30,60);
    exportdialog.setModal(true);
    exportdialog.show();
    exportdialog.exec();
}

void MainWindow::on_toolButton_clicked()
{
    append app;
    app.move(600,280);
    app.setModal(true);
    QLabel label(&app);
    label.move(33,170);
    label.setText(QObject::tr("反面"));
    QLabel label2(&app);
    label2.move(33,58);
    label2.setText(QObject::tr("正面"));
    QLabel label3(&app);
    label3.move(20,20);
    label3.setText(QObject::tr("牌组:"));
    QLabel label4(&app);
    label4.move(20,403);
    label4.setText(QObject::tr("标签:"));
    app.show();
    app.cardbutton->setText(deckname);

    app.exec();
}

void MainWindow::on_toolButton_2_clicked()
{
    stageid=STAGE_START;
    point->Initestage(STAGE_START);
}


void MainWindow::on_action_triggered()
{

    selectstudy a(this);
    a.setModal(true);
    a.setWindowTitle(tr("选择牌组"));
    if(a.input=="")
    {
        a.showstage();
    }

    a.show();
    a.exec();
}

void MainWindow::studyplans()
{
    studyplan studyplan1(this);
    studyplan1.show();
    studyplan1.exec();
}

void MainWindow::on_action_4_triggered()
{
    studyplan studyplan1(this);
    studyplan1.show();
    studyplan1.exec();
}

void MainWindow::on_toolButton_3_clicked()
{
    browse a;
    a.show();
    a.exec();
}

void MainWindow::on_toolButton_4_clicked()
{
    statics a;
    a.show();
    a.exec();
}
