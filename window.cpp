#include "window.h"

#include <QOpenGLContext>
#include <QTimer>

Window::Window(QScreen *screen) :
    QWindow (screen),
    scene_  (new BasicUsageScene)
{
    setSurfaceType(OpenGLSurface);

    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setMajorVersion(3);
    format.setMinorVersion(3);
    format.setSamples(4);
    format.setProfile(QSurfaceFormat::CoreProfile);

    resize(800, 600);
    setFormat(format);
    create();

    context_ = new QOpenGLContext();
    context_->setFormat(format);
    context_->create();

    scene_->setContext(context_);
    initializeGl();

    connect(this, SIGNAL(widthChanged(int)), this, SLOT(resizeGl()));
    connect(this, SIGNAL(heightChanged(int)), this, SLOT(resizeGl()));
    resizeGl();

    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateScene()));
    timer->start(16);
}

Window::~Window()
{

}

void Window::initializeGl()
{
    context_->makeCurrent(this);
    scene_->init();
}

void Window::paintGl()
{
    context_->makeCurrent(this);
    scene_->render();
    context_->swapBuffers(this);
}

void Window::resizeGl()
{
    context_->makeCurrent(this);
    scene_->resize(width(), height());
}

void Window::updateScene()
{
    scene_->update(0.0f);
    paintGl();
}
