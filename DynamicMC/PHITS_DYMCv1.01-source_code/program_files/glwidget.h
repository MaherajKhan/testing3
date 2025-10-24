#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QDialog>
//#include <QMainWindow>


//QT_BEGIN_NAMESPACE
//namespace Ui { class GLWidget; }
//QT_END_NAMESPACE

//namespace Uix { class GLWidget; }

class GLWidget : public QOpenGLWidget, public QOpenGLFunctions
{
    Q_OBJECT
public:
    GLWidget(QWidget *parent = nullptr);
    virtual ~GLWidget();

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    int sy = 0;
    int sx = 0;
    int py = 0;
    int px = 0;
    int syt = 0;
    int shy = 0;
    int shx = 0;
    int shl = 0;
    int shw = 0;
    void moveslider();
    void mousePressEvent(QMouseEvent *event);
          void collision(int sx, int sy, int px, int py, int shx, int shy, int shl, int shw);



/*
private:
        GLWidget *glwin;
*/
};

#endif // GLWIDGET_H
