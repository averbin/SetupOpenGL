#include "VertexArray.h"
#include "Renderer.h"

VertexArray::VertexArray()
{
    GLCall(glGenVertexArrays(1, &rendererID_));
}

VertexArray::~VertexArray()
{
    GLCall(glDeleteVertexArrays(1, &rendererID_));
}

void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
    Bind();
    vb.Bind();
    const auto& elements= layout.GetElements();
    unsigned int offset = 0;
    for (unsigned int i = 0; i != elements.size(); ++i)
    {
        const auto& element = elements.at(i);
        GLCall(glEnableVertexAttribArray(i));
        GLCall(glVertexAttribPointer(i, element.count_, element.type_, element.normalized_, layout.GetStride(), (const void*)offset));
        offset += element.count_ * VertexBufferElement::GetSizeOfType(element.type_);
    }
}

void VertexArray::Bind() const
{
    GLCall(glBindVertexArray(rendererID_));
}

void VertexArray::Unbind() const
{
    GLCall(glBindVertexArray(0));
}
