#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QtGui>
#include "fenetre.hh"


int main(int argc, char *argv[])

{

    QApplication app(argc, argv);
    fenetre f;
    f.show();
    return app.exec();
}
