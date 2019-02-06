#include "TestClearColor.h"
#include "Renderer.h"
#include "imgui/imgui.h"

namespace test
{
    TestClearColor::TestClearColor() 
        : clearColor_{ 0.2f, 0.5f, 0.3f, 1.0f }
    {
    }

    TestClearColor::~TestClearColor()
    {
    }

    void TestClearColor::OnUpdate(float delta)
    {
    }

    void TestClearColor::OnRender()
    {
        GLCall(glClearColor(clearColor_[0], clearColor_[1],
            clearColor_[2], clearColor_[3]));
        GLCall(glClear(GL_COLOR_BUFFER_BIT));
    }

    void TestClearColor::OnImGuiRender()
    {
        ImGui::ColorEdit4("Clear Color", clearColor_);
    }
}