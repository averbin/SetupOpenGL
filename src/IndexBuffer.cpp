#include "IndexBuffer.h"
#include "Renderer.h"

IndexBuffer::IndexBuffer(const unsigned int * data, unsigned int count)
{
    ASSERT(sizeof(unsigned int) == sizeof(GLint));
    GLCall(glGenBuffers(1, &rendererID_));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererID_));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer()
{
    GLCall(glDeleteBuffers(1, &rendererID_));
}

void IndexBuffer::Bind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, rendererID_));
}

void IndexBuffer::Unbind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}