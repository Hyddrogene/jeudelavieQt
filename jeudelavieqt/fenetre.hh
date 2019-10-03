#ifndef FENETRE_HH
#define FENETRE_HH

#include <string>
#include <QMainWindow>
#include <QtWidgets>
#include <QLineEdit>
#include <QString>
#include <QComboBox>
#include <string>
#include <QLabel>
#include <QLayout>
#include <QTextEdit>
#include <algorithm>
#include <QHBoxLayout>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QOpenGLWidget>
#include <QCheckBox>
#include <vector>
#include <QFileDialog>

#include<QTimer>
#include <iostream>
#include <unistd.h>
#include <QTime>
#include <QThread>
#include <sstream>

#include <QKeyEvent>
#include <QEvent>
#include <QSize>
#include <QApplication>
#include <stdio.h>
#include <unistd.h>

#include"stockdecelulle.hh"

#include <QMarginsF>

#include <QFile>
#include <QCoreApplication>
#include <QTextStream>
#include <QStandardPaths>

class fenetre : public QMainWindow
{
    Q_OBJECT

public:
    fenetre();
protected:
bool eventFilter(QObject *dist,QEvent *event);

//void resizeEvent(QResizeEvent* pEvent);

private slots:

    void suivant();
        void stopp();

private:
    int NBMAXMOVE;
    void createHorizontalGroupBox();

    QMenuBar *menuBar;
    QGroupBox *horizontalGroupBox;
    QColor colorise(bool  mort);
    QGraphicsView *view;
    QGraphicsScene *scene;
    void createSceneAndView();
    void createGraphicsItems();
    void createLayout();
    void fenetremenu();
    void createcarre(int x, int y, int i,int j,int taillecaree);

    QScrollArea *lala;
    QLineEdit *zontetxt;
    QPushButton *calcul;
    QLineEdit *zonetxtx;
    QLineEdit *zonetxty;
    QLineEdit *zonetxtx2;
    QLineEdit *zonetxty2;
    QLineEdit *zonetxthasard;
    QLineEdit *zonetxthasard2;
    QLineEdit *zonetxttour;
    QComboBox *formedebase;
    QLineEdit *zonex;
    QLineEdit *zoney;
    QComboBox *vitesse;

QTimer *timer = new QTimer;
    bool stop;

    QPoint m_lastPos;
    int m_xRot;
    int m_yRot;
    int m_zRot;

    stockcellule plateau;
    std::vector<std::vector<Cellule>> boite;
private:
    void resetlaboite();
    void donnetaille();
    void creerplateau(int x,int y);
    void changecelulle();
    void auhasard();
    void executetour();
    void simplifie();
    void epatemoi();
    void creercetteforme();
    void mousePressEvent(QMouseEvent *event) override;

    bool verifcontenu(QString test);
    //void mouseMoveEvent(QMouseEvent *event) override;
};


class SleeperThread : public QThread
{
    public:
    static void msleep(unsigned long msecs)
    {
        QThread::msleep(msecs);
    }
};

//et ensuite appeler

/*class filtrescene : public QObject{
    Q_OBJECT
public:
    bool eventFilter(QObject *obj,QMouseEvent *event){
        if(event->){

        }
    }
};*/


#endif // FENETRE_HH
