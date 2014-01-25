#ifndef ABSTRACTSCENE_H
#define ABSTRACTSCENE_H

class QOpenGLContext;

class AbstractScene
{
public:
    AbstractScene() { }

    void setContext(QOpenGLContext* context) { context_ = context; }
    QOpenGLContext* context() const { return context_; }

    virtual void init() = 0;
    virtual void update(float t) = 0;
    virtual void render() = 0;
    virtual void resize(int width, int height) = 0;

protected:
    QOpenGLContext* context_;
};


#endif // ABSTRACTSCENE_H
