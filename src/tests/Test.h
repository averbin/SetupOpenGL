#pragma once
#include <functional>
#include <vector>

namespace test {

    class Test
    {
    public:
        Test() = default;
        virtual ~Test() = default;

        virtual void OnUpdate(float delta) {}
        virtual void OnRender() {}
        virtual void OnImGuiRender() {}
    };

    class TestMenu : public Test
    {
    public:
        TestMenu(Test*& currentTest);
        ~TestMenu();

        void OnUpdate(float delta) override;
        void OnRender() override;
        void OnImGuiRender() override;

        template<typename T>
        void RegisterTest(const std::string& name)
        {
            std::cout << "Registering test " << name << std::endl;

            tests_.push_back(std::make_pair(name, []() { return new T(); }));
        }
    private:
        Test*& currentTest_;
        std::vector<std::pair<std::string, std::function<Test*()>>> tests_;
    };
}