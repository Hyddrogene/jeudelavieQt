#include "fenetre.hh"
#include <iostream>

//============================================================================================
//============================================================================================

fenetre::fenetre():
    NBMAXMOVE(20),plateau(41,41){
    resetlaboite();
      /* plateau.changelaviexy(18,12);
       plateau.changelaviexy(19,12);
       plateau.changelaviexy(17,12);
       plateau.changelaviexy(40,20);
       plateau.changelaviexy(39,20);
       plateau.changelaviexy(40,19);
       plateau.changelaviexy(39,19);*/

      /* plateau.changelaviexy(20, 20);
       plateau.changelaviexy(20, 21);
       plateau.changelaviexy(20, 22);
       plateau.changelaviexy( 21, 22);
      plateau.changelaviexy(22, 22);
       plateau.changelaviexy(22, 21);
      plateau.changelaviexy(22, 20);*/
       stop=true;

    resize(2000,2000);
    createSceneAndView();


    createGraphicsItems();
    createHorizontalGroupBox();

    createLayout();
   installEventFilter(this);
setWindowTitle(tr("Rubik cube projet"));
}

/*       f=static_cast<double>(view->height()) /1000;
            fenetrerubikmenu();
*/

//============================================================================================
//============================================================================================

void fenetre::createLayout(){
    QFrame *frame = new QFrame;
    QHBoxLayout *frameLayout = new QHBoxLayout(frame);
    frameLayout->addWidget(view);
    frameLayout->addWidget(lala);
    //frameLayout->addWidget(horizontalGroupBox);
    //frameLayout->setMenuBar(menuBar);
    setCentralWidget(frame);
}//endMethode

//============================================================================================
//============================================================================================

void fenetre::createSceneAndView(){
    scene = new QGraphicsScene(this);
    int y=static_cast<int>(QSize().height()*0.1);
    scene->setSceneRect(0,0,y,y);
    view = new QGraphicsView;
    view->setScene(scene);

}//endMethode

//============================================================================================
//============================================================================================

void fenetre::createcarre(int x, int y, int i,int j,int taillecaree){


    QRect rectangle(x,y,taillecaree,taillecaree);
    QPen pen(Qt::black, 1, Qt::SolidLine);
    QBrush brush(colorise( plateau.positionxy (i,j)));
    scene->addRect(rectangle, pen, brush);
}//endMethode

//============================================================================================
//============================================================================================

void fenetre::createGraphicsItems(){
    int nx(0);
    int ny(0);
    int taillecarre(20);
   // int y=static_cast<int>(QSize().height()*0.1);
       // scene->setSceneRect(200,-200,400,400);

    for (int i=0;i<plateau.gettaillex();i++){
        nx+=taillecarre;
        for(int j=0;j<plateau.gettailley();j++){
            ny+=taillecarre;
         createcarre(nx,ny, i,j,taillecarre);
    }//endFor
        ny=0;
}//endFor
   /* QRect rectangle(0,0,20,20);
    QPen pen(Qt::black, 1, Qt::SolidLine);
    QBrush brush(Qt::blue);
     scene->addRect(rectangle, pen, brush);*/
}//endMethode


//============================================================================================
//============================================================================================

void fenetre::mousePressEvent(QMouseEvent *event)
{
    m_lastPos = event->pos();
    event->localPos().x();
   if (event->localPos().x()<1040 && event->localPos().x()>10){
       std::cout<<"hello les coupaing"<<"\n";
   }
    event->localPos().y();
    std::cout<<event->x()<<" x "<<event->y()<<" y"<<std::endl;
     std::cout<< event->localPos().x()<<" x "<< event->localPos().y()<<" y"<<std::endl;
}

/*void fenetre::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - m_lastPos.x();
    int dy = event->y() - m_lastPos.y();

    if (event->buttons() & Qt::LeftButton) {

            std::cout<<"salut clique gauche \n";
          //  m_yRot=m_yRot + 0.9 * dx;
           // m_xRot=m_xRot + 0.9 * dy;
//            std::cout<<m_yRot;
    } else if (event->buttons() & Qt::RightButton) {

        m_zRot=m_zRot + 1 * dx;
        m_xRot=m_xRot + 1 * dy;
        std::cout<<"salut";


    }
    m_lastPos = event->pos();
}*/

//============================================================================================
//============================================================================================

void fenetre::createHorizontalGroupBox(){
//=============== iniatilisation ===================
    horizontalGroupBox = new QGroupBox(tr("Menus de controle  :"));

    QFormLayout *layout = new QFormLayout;
    layout->addRow(new QLabel(tr("barretoa")));
        QHBoxLayout *ptitlayout=new QHBoxLayout;
//=================================================================
//==================================

        zontetxt =new QLineEdit;
        zontetxt->setText("Exemple: L D B U L2 L' ");
        ptitlayout->addWidget(zontetxt);
        calcul =new QPushButton(tr("Go"));
        ptitlayout->addWidget(calcul);
        //connect(calcul, &QPushButton::clicked, this, &fenetrerubik::recu);
        layout->addRow(ptitlayout);

//==================================

        QPushButton *bouton1=new QPushButton(tr("Suivant"));
        QPushButton *boutonclear=new QPushButton(tr("clear"));
        layout->addRow(bouton1);
        layout->addRow(boutonclear);
        connect(bouton1,&QPushButton::clicked,this,&fenetre::suivant);
        connect(boutonclear,&QPushButton::clicked,this,[&](){resetlaboite(); creerplateau(plateau.gettaillex(),plateau.gettailley()); createGraphicsItems();});

        QPushButton *boutonstop=new QPushButton(tr("stop"));
        layout->addRow(boutonstop);
        connect(boutonstop,&QPushButton::clicked,this,&fenetre::stopp);


//==================================

         QHBoxLayout *ptitlayout2=new QHBoxLayout;
         ptitlayout2->addWidget(new QLabel(tr("Taille : ")));
         zonetxtx = new QLineEdit;
         zonetxtx->setText("10");
         ptitlayout2->addWidget(zonetxtx);
         zonetxty=new QLineEdit;
         ptitlayout2->addWidget(zonetxty);
         zonetxty->setText("10");
         QPushButton *bouton2=new QPushButton(tr("Go"));
         ptitlayout2->addWidget(bouton2);
         layout->addRow(ptitlayout2);
         connect(bouton2,&QPushButton::clicked,this,&fenetre::donnetaille);

//==================================

         QHBoxLayout *ptitlayout3=new QHBoxLayout;
         ptitlayout3->addWidget(new QLabel(tr("Change : ")));
         zonetxtx2 = new QLineEdit;
         zonetxtx2->setText("18");
         ptitlayout3->addWidget(zonetxtx2);
         zonetxty2=new QLineEdit;
         zonetxty2->setText("2");
         ptitlayout3->addWidget(zonetxty2);
         QPushButton *bouton3=new QPushButton(tr("Go"));
         ptitlayout3->addWidget(bouton3);
         layout->addRow(ptitlayout3);
         connect(bouton3,&QPushButton::clicked,this,&fenetre::changecelulle);

//==================================

         QHBoxLayout *ptitlayout4=new QHBoxLayout;
         ptitlayout4->addWidget(new QLabel(tr("Cellule vivante au hasard : ")));
         zonetxthasard = new QLineEdit;
         zonetxthasard->setText("1000");
         ptitlayout4->addWidget(zonetxthasard);
         QPushButton *bouton4=new QPushButton(tr("Go"));
         ptitlayout4->addWidget(bouton4);
         layout->addRow(ptitlayout4);
         connect(bouton4,&QPushButton::clicked,this,&fenetre::auhasard);

//==================================

         QHBoxLayout *ptitlayout5=new QHBoxLayout;
         ptitlayout5->addWidget(new QLabel(tr("Lance la vie")));

         vitesse =new QComboBox;
         vitesse->addItem("normal");
         vitesse->addItem("rapide");
         vitesse->addItem("lente");
         vitesse->addItem("très rapide");
         vitesse->addItem("tres lent");
         ptitlayout5->addWidget(vitesse);

         QPushButton *bouton5=new QPushButton(tr("Go"));
         ptitlayout5->addWidget(bouton5);
         layout->addRow(ptitlayout5);
         connect(bouton5,&QPushButton::clicked,this,&fenetre::executetour);

//==================================

         QHBoxLayout *ptitlayout6=new QHBoxLayout;
         ptitlayout6->addWidget(new QLabel(tr("Forme Basique:")));
         formedebase =new QComboBox;
         formedebase->addItem("carre");
         formedebase->addItem("baton 3");
         ptitlayout6->addWidget(formedebase);
         QPushButton *bouton6=new QPushButton;

         bouton6->setText(tr("go"));
         ptitlayout6->addWidget(new QLabel(tr("Position:")));
         zonex= new QLineEdit;
         zoney= new QLineEdit;
         zonex->setText("25");
         zoney->setText("39");
         ptitlayout6->addWidget(zonex);
         ptitlayout6->addWidget(zoney);
         ptitlayout6->addWidget(bouton6);
         connect(bouton6, &QPushButton::clicked,this,&fenetre::creercetteforme);
         layout->addRow(ptitlayout6);

//==================================


//==================================
//================= affectation des nouveaux layout =================

 horizontalGroupBox->setLayout(layout);
lala= new QScrollArea;
lala->setWidgetResizable(true);
lala->setWidget(horizontalGroupBox);
}//endMethode

//============================================================================================
//============================================================================================

QColor fenetre::colorise(bool mort){

    /*switch(mort){
    case 'O': return QColor(255,127,0);
    }*/
    if (mort){ return QColor(Qt::green);}
    else {
        return QColor(Qt::red);
    }

}//endMethode

//============================================================================================
//============================================================================================

void fenetre::resetlaboite(){

    std::vector<std::vector<Cellule>> nouvostock;
    int x=plateau.gettaillex();
    int y=plateau.gettailley();
    Cellule a;
    std::vector<Cellule> corne;
    for(int i(0);i<y;i++){corne.push_back(a);}
    corne.shrink_to_fit();
    for(int i(0);i<x;i++){nouvostock.push_back(corne);}
    nouvostock.shrink_to_fit();

    boite=nouvostock;
}//endMethode

//============================================================================================
//============================================================================================


void fenetre::creerplateau(int x,int y){

    std::vector<std::vector<Cellule>> nouvostock;
    Cellule a;
    std::vector<Cellule> corne;
    for(int i(0);i<y;i++){corne.push_back(a);}
    corne.shrink_to_fit();
    for(int i(0);i<x;i++){nouvostock.push_back(corne);}
    nouvostock.shrink_to_fit();

    plateau.changelestock(nouvostock);
    plateau.changex(x);
    plateau.changey(y);
}//endMethode

//============================================================================================
//============================================================================================


void fenetre::suivant(){
    scene->clear();
    plateau.toursuivant();

    createGraphicsItems();

}//endslot

//============================================================================================
//============================================================================================


void fenetre::donnetaille(){

     QString nombre =  zonetxtx->text();
    int nb= nombre.toInt();

     QString nombre2 =  zonetxty->text();
      int nb2= nombre.toInt();

     if(not(verifcontenu(nombre))||not(verifcontenu(nombre2))){
      return;
     }

    creerplateau(nb,nb2);
    scene->clear();
    //scene->installEventFilter();
    createGraphicsItems();
        view->setScene(scene);


}//endslot

//============================================================================================
//============================================================================================

void fenetre::changecelulle(){
    QString nombre =  zonetxtx2->text();
   int nb= nombre.toInt();
   // int nb=std::stoi(nombre.toStdString());

    QString nombre2 =  zonetxty2->text();
     int nb2= nombre.toInt();
   // int nb2=std::stoi(nombre2.toStdString());

    if(not(verifcontenu(nombre))||not(verifcontenu(nombre2))){
     return;
    }

    plateau.changelaviexy(nb,nb2);
     createGraphicsItems();

}//endslot

//============================================================================================
//============================================================================================

void fenetre::auhasard(){
   QString nombre =  zonetxthasard->text();
   int nb= nombre.toInt();

   if(nb<0 ){
    return;
   }
    unsigned int x=0;
    unsigned int y=0;
    unsigned int n=0;
     unsigned int n2=15;
    for (int k=0;k<nb;k++){
        unsigned int i=static_cast<unsigned int>(random()%plateau.gettaillex());
        unsigned int j=static_cast<unsigned int>(random()%plateau.gettailley());
        if(n==0){
            x=i;
            y=j;
            n=20;//static_cast<unsigned int>(random()%(1000));
            plateau.donnelaviexy(i,j);
            n--;
        }
        else {
            //plateau.donnelaviexy(i,j);
            unsigned int x1=x+static_cast<unsigned int>(i/n);
            unsigned int y1=y+static_cast<unsigned int>(j/n);

            if(x1>0 && y1>0 && x1<static_cast<unsigned int>(plateau.gettaillex()) && y1<static_cast<unsigned int>(plateau.gettailley())){
                    plateau.donnelaviexy(x1,y1);
            }

                    else {
                   plateau.donnelaviexy(i,j);
             }
            n--;
        }
        //plateau.donnelaviexy(i,j);
        }

    simplifie();
     createGraphicsItems();

}//endslot

//============================================================================================
//============================================================================================

void fenetre::executetour(){
        timer->blockSignals(false);
        std::string forme= vitesse->currentText().toStdString();
        if(forme=="normal"){
           timer->start(500);}
        if(forme=="rapide"){
           timer->start(250);}
        if(forme=="lente"){
           timer->start(1000);}
        if(forme=="très rapide"){
           timer->start(100);}
        if(forme=="tres lent"){
           timer->start(2000);}

        if(stop){
            timer->connect(timer, &QTimer::timeout, this,&fenetre::suivant);
            stop=false;
      }//endif
        std::cout<<"lavache \n";
}//endslot

//============================================================================================
//============================================================================================

void fenetre::creercetteforme(){
    std::string forme= formedebase->currentText().toStdString();

    QString nombre =  zonex->text();
   int nb= nombre.toInt();
   // int nb=std::stoi(nombre.toStdString());

    QString nombre2 =  zoney->text();
     int nb2= nombre2.toInt();
   // int nb2=std::stoi(nombre2.toStdString());
    std::cout<<nb<<" "<<nb2<<std::endl;
    if(verifcontenu(nombre)||verifcontenu(nombre2)){
     return;
    }

    if (forme=="carre"){
        plateau.changelaviexy(nb,nb2);
        plateau.changelaviexy(nb+1,nb2);
        plateau.changelaviexy(nb,nb2-1);
        plateau.changelaviexy(nb+1,nb2-1);
        createGraphicsItems();
    }
    if(forme=="baton 3"){
        plateau.changelaviexy(nb,nb2);
        plateau.changelaviexy(nb,nb2-1);
        plateau.changelaviexy(nb,nb2-2);
        createGraphicsItems();
    }
}//endslot


void fenetre::stopp(){
                     //timer->stop();
                     timer->blockSignals(true);
                    }

//============================================================================================
//============================================================================================

bool fenetre::verifcontenu(QString test){
    if (test.size()<=0){
        return false;
    }
    int nb=test.toInt();
    if(nb<=0){return false;}

    if(nb<plateau.gettaillex()){return false;}
     if(nb<plateau.gettailley()){return false;}
    return true;
}

//============================================================================================
//============================================================================================

void fenetre::simplifie(){
    for(int i=0;i<plateau.gettaillex();i++){
        for(int j=0;j<plateau.gettailley();j++){
            if(plateau.compteur(static_cast<unsigned int>(i),static_cast<unsigned int>(j))<=3){
                plateau.donnelamortxy(static_cast<unsigned int>(i),static_cast<unsigned int>(j));
            }
    }
    }

}

//============================================================================================
//============================================================================================

bool fenetre::eventFilter(QObject *dist,QEvent *event)
{
 if( event->type() == QEvent::KeyPress)
 {
      QKeyEvent *keyEvent = static_cast<QKeyEvent*>( event );
      if( QString("^").indexOf( keyEvent->text() ) != -1 ){
      return true;}

      if( QString("dD").indexOf( keyEvent->text() ) != -1 ){
          executetour();
      return true;}
      if( QString("sS").indexOf( keyEvent->text() ) != -1 ){
        suivant();
      return true;}
     /* if( QString("rR").indexOf( keyEvent->text() ) != -1 ){
          setaffichage4();
      return true;}
      if( QString("fF").indexOf( keyEvent->text() ) != -1 ){
          setaffichage5();
      return true;}
      if( QString("bB").indexOf( keyEvent->text() ) != -1 ){
          setaffichage6();
      return true;}
      if( QString("mM").indexOf( keyEvent->text() ) != -1 ){
          melangecube();
      return true;}
      if( QString("aA").indexOf( keyEvent->text() ) != -1 ){
          reset();
      return true;}
      if( QString("&").indexOf( keyEvent->text() ) != -1 ){
          resolutiong1();
      return true;}
      if( QString("é").indexOf( keyEvent->text() ) != -1 ){
          resolutiong2();
      return true;}
      if( QString("\"").indexOf( keyEvent->text() ) != -1 ){
          resolutiong3();
      return true;}
      if( QString("'").indexOf( keyEvent->text() ) != -1 ){
          resolutiong4();
      return true;}
      if( QString("(").indexOf( keyEvent->text() ) != -1 ){
          resolutiongdirectfin();
      return true;}

      if( QString("uU").indexOf( keyEvent->text() ) != -1 ){
          setaffichage();
      return true;}*/


 }
return false;
}


//QTime *time=new QTime;
//time->start();
//QThread *th=new QThread;
//th->sleep(10);
//SleeperThread::msleep(1000);

// th->msleep(500);
/* clock_t t1, t2;
 float temps=0;
 t1 = clock();
 while(temps<1){
 t2 = clock();
 temps = static_cast<float>(t2-t1)/CLOCKS_PER_SEC;
 //std::cout<<temps<<" \n";
}
 std::cout<<"vache \n";*/
// suivant();
// connect( SleeperThread::msleep(1000),&QThread::terminate,this,&fenetre::suivant);
