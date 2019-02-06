#include "Test.h"
#include "imgui/imgui.h"

namespace test
{
    TestMenu::TestMenu(Test*& currentTest) 
        : currentTest_(currentTest)
    {
    }

    TestMenu::~TestMenu()
    {
    }

    void TestMenu::OnUpdate(float delta)
    {

    }

    void TestMenu::OnRender()
    {

    }

    void TestMenu::OnImGuiRender()
    {
        for (auto& test : tests_)
        {
            if (ImGui::Button(test.first.c_str()))
                currentTest_ = test.second();
        }
    }
}