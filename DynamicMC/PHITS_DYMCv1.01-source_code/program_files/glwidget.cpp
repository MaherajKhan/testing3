#include "glwidget.h"
#include <QtWidgets>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iostream>
#include <stdio.h>
#include <time.h>       /* time */
#include <ctype.h>
#include <ctime>
#include <stdio.h>
#include <QMessageBox>
#include <QPixmap>
#include <sstream>
#include <GL/gl.h>
#include <QGLWidget>
#include <QDialog>


using namespace std;



GLWidget::GLWidget(QWidget *parent) : QOpenGLWidget(parent)
{







}



GLWidget::~GLWidget()
{
}
 int syj = 0;
 int sxj = 0;
  int pxj = 0;
   int pyj = 0;
   int shxj=0;
   int shyj=0;
   int shlj=0;
   int shwj=0;

void GLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.1,0.1,0.1,1);
   // glViewport(-1,-1,1,1);

}


void GLWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {

        //sy = sy + 5;
        QFile inputFile("sy.tmp");
        if (inputFile.open(QIODevice::ReadOnly))
        {
            QTextStream inp(&inputFile);
            inp >> syj;
            inputFile.close();

        }
        sy = syj;

        QFile inputFile2("sx.tmp");
        if (inputFile2.open(QIODevice::ReadOnly))
        {
            QTextStream inp2(&inputFile2);
            inp2 >> sxj;
            inputFile2.close();

        }
        sx = sxj;


        QFile inputFile3("px.tmp");
        if (inputFile3.open(QIODevice::ReadOnly))
        {
            QTextStream inp3(&inputFile3);
            inp3 >> pxj;
            inputFile3.close();

        }
        px = pxj;

        QFile inputFile4("py.tmp");
        if (inputFile4.open(QIODevice::ReadOnly))
        {
            QTextStream inp4(&inputFile4);
            inp4 >> pyj;
            inputFile4.close();

        }
        py = pyj;

//*************************************************
        QFile inputFile5("shx.tmp");
        if (inputFile5.open(QIODevice::ReadOnly))
        {
            QTextStream inp5(&inputFile5);
            inp5 >> shxj;
            inputFile5.close();

        }
        shx = shxj;

        QFile inputFile6("shy.tmp");
        if (inputFile6.open(QIODevice::ReadOnly))
        {
            QTextStream inp6(&inputFile6);
            inp6 >> shyj;
            inputFile6.close();

        }
        shy = shyj;


        QFile inputFile7("shl.tmp");
        if (inputFile7.open(QIODevice::ReadOnly))
        {
            QTextStream inp7(&inputFile7);
            inp7 >> shlj;
            inputFile5.close();

        }
        shl = shlj;

        QFile inputFile8("shw.tmp");
        if (inputFile8.open(QIODevice::ReadOnly))
        {
            QTextStream inp8(&inputFile8);
            inp8 >> shwj;
            inputFile8.close();

        }
        shw = shwj;



        update();

       // paintGL();
    }
  /*
    if (event->buttons() & Qt::RightButton) {

        sy = sy - 5;

        update();
    }
*/
}

void GLWidget::collision(int sx, int sy, int px, int py, int shx, int shy, int shl, int shw)
{
  int  collide;

    if((((sx > px-40) && (sx < px+40)) && ((sy > py-33) && (sy < py+33))) || (((sx > shx) && (sx < shx+shl)) && ((sy > shy) && (sy < shy+shw))))
    {
        collide = 1;

         }

    else if(((shx>px-40) && ((shx+shl)<px+40)) && ((shy > py-33) && ((shy+shw)<py+33)))
    {
           collide = 1;

    }

    else{
  collide =0;

    }

    const QString qPath161("collision.tmp");
    QFile qFile161(qPath161);
      if (qFile161.open(QIODevice::WriteOnly)) {
        QTextStream out161(&qFile161);
        out161 << collide;
        qFile161.close();
    }

           // cout << collide << endl;

 //   if((sy > py-60) && (sy < py+60))
 //   {
 //       collide = 1;
 //       cout << collide << endl;
 //   }

  //  update();

}



void GLWidget::moveslider()
{



            update();
}





void GLWidget::paintGL()
{
   // glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
   // glClear(GL_COLOR_BUFFER_BIT);
   // int sy = 0; // =100;
    //int k;

   // connect(this,SIGNAL(on_verticalSlider_valueChanged(int)),MainWindow,SLOT(on_verticalSlider_valueChanged(int)));


    float movx1 = sx/100.;
    float movy1 = sy/100.;

    glColor3f(1.0, 0.1, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.05+movx1, 0.05+movy1); // top left
    glVertex2f(0.05+movx1, 0.05+movy1); // top right
    glVertex2f(0.05+movx1, -0.05+movy1); // bottom right
    glVertex2f(-0.05+movx1, -0.05+movy1); // bottom left


    float movx2 = px/100.;
    float movy2 = py/100.;

    float movx3 = shx/100.;
    float movy3 = shy/100.;

    float lq = shl/100.;
    float wq = shw/100.;



  // int col=0;


    //cout << col << endl;

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.05+movx2+0.03, 0.05+movy2); // top left
    glVertex2f(0.05+movx2-0.03, 0.05+movy2); // top right
    glVertex2f(0.05+movx2, -0.05+movy2); // bottom right
    glVertex2f(-0.05+movx2, -0.05+movy2); // bottom left

    int shield = 0;
    QFile inputFile8("shield.tmp");
    if (inputFile8.open(QIODevice::ReadOnly))
    {
        QTextStream inp8(&inputFile8);
        inp8 >> shield;
        inputFile8.close();

    }


if(shield==0){

    movx3=-100;
    movy3=-100;
    lq=1;
    wq=1;


    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.05+movx3, 0.05+movy3+wq); // top left
    glVertex2f(0.05+movx3+lq, 0.05+movy3+wq); // top right
    glVertex2f(0.05+movx3+lq, -0.05+movy3); // bottom right
    glVertex2f(-0.05+movx3, -0.05+movy3); // bottom left


       collision(sx, sy, px, py,shx,shy,shl,shw);

}

else{
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.001+movx3, 0.001+movy3+wq); // top left
    glVertex2f(0.001+movx3+lq, 0.001+movy3+wq); // top right
    glVertex2f(0.001+movx3+lq, -0.001+movy3); // bottom right
    glVertex2f(-0.001+movx3, -0.001+movy3); // bottom left


       collision(sx, sy, px, py,shx,shy,shl,shw);

}






    glEnd();
}



void GLWidget::resizeGL(int w, int h)
{
    Q_UNUSED(w);
    Q_UNUSED(h);
}

