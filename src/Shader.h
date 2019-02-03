#pragma once
#include <string>
#include <unordered_map>
#include "glm/fwd.hpp"

struct ShaderProgramSource
{
    std::string vertexSource_;
    std::string fragmentSource_;
};

class Shader
{
public:
    Shader(const std::string& filepath);
    ~Shader();

    void Bind() const;
    void Unbind() const;

    void SetUniform1i(const std::string& name, int value);
    void SetUniform1f(const std::string& name, float value);
    void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
    void SetUniformMat4m(const std::string& name, const glm::mat4& matrix);
private:
    unsigned int CreateShader(const std::string& vertexShader,
        const std::string& fragmentShader);
    unsigned int CompileShader(unsigned int type, const std::string& source);
    ShaderProgramSource ParseShader(const std::string& filepath);
    int GetUniformLocation(const std::string& name);
private:
    std::string filePath_;
    unsigned int rendererID_;
    std::unordered_map<std::string, int> uniformLocationCache_;
};

