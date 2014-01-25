#ifndef BASICUSAGESCENE_H
#define BASICUSAGESCENE_H

#include "abstractscene.h"

#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>

class BasicUsageScene : public AbstractScene
{
public:
    BasicUsageScene();

    virtual void init();
    virtual void update(float t);
    virtual void render();
    virtual void resize(int width, int height);

private:
    QOpenGLShaderProgram shaderProgram_;
    QOpenGLBuffer vertexPositionBuffer_;
    QOpenGLBuffer vertexColorBuffer_;

    void prepareShaderProgram();
    void prepareVertexBuffers();
};

#endif // BASICUSAGESCENE_H
