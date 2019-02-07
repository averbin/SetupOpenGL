#include "TestTexture2D.h"

#include "imgui/imgui.h"

#include "IndexBuffer.h"
#include "Renderer.h"
#include "Shader.h"
#include "Texture.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

namespace test
{
    TestTexture2D::TestTexture2D()
        : translationA_(200, 200, 0),
        translationB_(400, 200, 0),
        proj_(glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f)),
        view_(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)))
    {
        float position[] = {
           -50.0f, -50.0f, 0.0f, 0.0f,
           50.0f, -50.0f, 1.0f, 0.0f,
           50.0f, 50.0f, 1.0f, 1.0f,
           -50.0f, 50.0f, 0.0f, 1.0f
        };

        unsigned int indices[] = {
            0, 1, 2,
            2, 3, 0
        };

        GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
        GLCall(glEnable(GL_BLEND));

        vertexArray_ = std::make_unique<VertexArray>();
 
        vertexBuffer_ = std::make_unique<VertexBuffer>(position, 4 * 4 * sizeof(float));
        VertexBufferLayout layout;
        layout.Push<float>(2);
        layout.Push<float>(2);
        vertexArray_->AddBuffer(*vertexBuffer_, layout);

        indexBuffer_ = std::make_unique<IndexBuffer>(indices, 6);

        shader_ = std::make_unique<Shader>("res/shaders/Basic.shader");
        shader_->Bind();
        shader_->SetUniform4f("u_Color", 1.0f, 0.5f, 0.8f, 1.0f);

        texture_ = std::make_unique<Texture>("res/img/pirate.png");
        //texture_->Bind();
        shader_->SetUniform1i("u_Texture", 0);

        //vertexArray_->Unbind();
        //shader_->Unbind();
        //vb.Unbind();
        //indexBuffer_->Unbind();
    }

    TestTexture2D::~TestTexture2D()
    {
    }

    void TestTexture2D::OnUpdate(float delta)
    {
        GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
        GLCall(glClear(GL_COLOR_BUFFER_BIT));

        Renderer renderer;

        texture_->Bind();

        {
            glm::mat4 model = glm::translate(glm::mat4(1.0f), translationA_);
            glm::mat4 mvp = proj_ * view_ * model;
            shader_->Bind();
            shader_->SetUniformMat4m("u_MVP", mvp);
            renderer.Draw(*vertexArray_, *indexBuffer_, *shader_);
        }

        {
            glm::mat4 model = glm::translate(glm::mat4(1.0f), translationB_);
            glm::mat4 mvp = proj_ * view_ * model;
            shader_->Bind();
            shader_->SetUniformMat4m("u_MVP", mvp);
            renderer.Draw(*vertexArray_, *indexBuffer_, *shader_);
        }

    }

    void TestTexture2D::OnRender()
    {

    }

    void TestTexture2D::OnImGuiRender()
    {
        ImGui::SliderFloat3("Translation A", &translationA_.x, 0.0f, 960.0f);
        ImGui::SliderFloat3("Translation B", &translationB_.x, 0.0f, 960.0f);
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    }
}