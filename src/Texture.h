#pragma once

#include "Renderer.h"
#include <string>

class Texture
{
public:
    Texture(const std::string& path);
    ~Texture();

    void Bind(unsigned int slot = 0) const;
    void Unbind() const;

    inline int GetWidth() const { return width_; }
    inline int GetHeight() const { return height_; }

private:
    unsigned int rendererID_{ 0 };
    std::string filePath_;
    unsigned char* localBuffer_{ nullptr };
    int width_{ 0 };
    int height_{ 0 };
    int bpp_{ 0 };
};

