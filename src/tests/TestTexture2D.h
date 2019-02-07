#pragma once

#include "Test.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "Texture.h"
#include <memory>

namespace test 
{
    class TestTexture2D : public Test
    {
    public:
        TestTexture2D();
        ~TestTexture2D();

        void OnUpdate(float delta) override;
        void OnRender() override;
        void OnImGuiRender() override;
    private:
        std::unique_ptr<VertexArray> vertexArray_;
        std::unique_ptr<VertexBuffer> vertexBuffer_;
        std::unique_ptr<IndexBuffer> indexBuffer_;
        std::unique_ptr<Shader> shader_;
        std::unique_ptr<Texture> texture_;

        glm::vec3 translationA_;
        glm::vec3 translationB_;
        glm::mat4 proj_;
        glm::mat4 view_;
    };
}