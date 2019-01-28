#pragma once

class IndexBuffer {
public:
    IndexBuffer(const unsigned int * data, unsigned int count);
    ~IndexBuffer();

    void Bind() const;
    void Unbind() const;

    inline unsigned int GetCount() const noexcept { return count_; }

private:
    unsigned int rendererID_{ 0 };
    unsigned int count_{ 0 };
};