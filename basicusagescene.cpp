#include "basicusagescene.h"

#include <QObject>
#include <QOpenGLContext>

BasicUsageScene::BasicUsageScene() :
    shaderProgram_(),
    vertexPositionBuffer_(QOpenGLBuffer::VertexBuffer),
    vertexColorBuffer_(QOpenGLBuffer::VertexBuffer)
{

}

void BasicUsageScene::init()
{
    prepareShaderProgram();
    prepareVertexBuffers();
}

void BasicUsageScene::update(float t)
{
    Q_UNUSED(t);  // Avoid unused parameter warnings
}

void BasicUsageScene::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shaderProgram_.bind();

    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void BasicUsageScene::resize(int width, int height)
{
    glViewport(0, 0, width, height);
}

void BasicUsageScene::prepareShaderProgram()
{
    if (!shaderProgram_.addShaderFromSourceFile(QOpenGLShader::Vertex, ":shaders/phong.vert"))
    {
        qCritical() << "error";
    }
    if (!shaderProgram_.addShaderFromSourceFile(QOpenGLShader::Fragment, ":shaders/phong.frag"))
    {
        qCritical() << "error";
    }
    if (!shaderProgram_.link())
    {
        qCritical() << "error";
    }
}

void BasicUsageScene::prepareVertexBuffers()
{
    float positionData[] = {
        -0.8f, -0.8f, 0.0f,
        0.8f, -0.8f, 0.0f,
        0.0f, 0.8f, 0.0f
    };

    float colorData[] = {
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f
    };

    vertexPositionBuffer_.create();
    vertexPositionBuffer_.setUsagePattern(QOpenGLBuffer::StaticDraw);
    vertexPositionBuffer_.bind();
    vertexPositionBuffer_.allocate(positionData, 3 * 3 * sizeof(float));

    vertexColorBuffer_.create();
    vertexColorBuffer_.setUsagePattern(QOpenGLBuffer::StaticDraw);
    vertexColorBuffer_.bind();
    vertexColorBuffer_.allocate(colorData, 3 * 3 * sizeof(float));

    shaderProgram_.bind();

    vertexPositionBuffer_.bind();
    shaderProgram_.enableAttributeArray("vertexPosition");
    shaderProgram_.setAttributeBuffer("vertexPosition", GL_FLOAT, 0, 3);

    vertexColorBuffer_.bind();
    shaderProgram_.enableAttributeArray("vertexColor");
    shaderProgram_.setAttributeBuffer("vertexColor", GL_FLOAT, 0, 3);
}