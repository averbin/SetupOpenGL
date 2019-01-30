#include "Texture.h"
#include "GL/glew.h"
#include "vendor/stb_image/stb_image.h"

Texture::Texture(const std::string& path)
    : filePath_(path)
{
    stbi_set_flip_vertically_on_load(1);

    localBuffer_ = stbi_load(filePath_.c_str(), &width_, &height_, &bpp_, 4);
    GLCall(1, &rendererID_);
    GLCall(glBindTexture(GL_TEXTURE_2D, rendererID_));

    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

    GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width_, height_, 0, GL_RGBA, GL_UNSIGNED_BYTE, localBuffer_));
    GLCall(glBindTexture(GL_TEXTURE_2D, 0));

    if (localBuffer_)
    {
        stbi_image_free(localBuffer_);
    }
}


Texture::~Texture()
{
    GLCall(glDeleteTextures(1, &rendererID_));
}

void Texture::Bind(unsigned int slot) const
{
    GLCall(glActiveTexture(GL_TEXTURE0 + slot));
    GLCall(glBindTexture(GL_TEXTURE_2D, rendererID_));
}

void Texture::Unbind() const
{
    GLCall(glBindTexture(GL_TEXTURE_2D, 0));
}
