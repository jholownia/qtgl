#ifndef WINDOW_H
#define WINDOW_H

#include "basicusagescene.h"

#include <QWindow>

class QOpenGLContext;

class Window : public QWindow
{
    Q_OBJECT

public:
    explicit Window(QScreen* screen = 0);
    ~Window();

protected slots:
    void resizeGl();
    void paintGl();
    void updateScene();

private:
    QOpenGLContext* context_;
    QScopedPointer<AbstractScene> scene_;

    void initializeGl();
};

#endif // WINDOW_H
