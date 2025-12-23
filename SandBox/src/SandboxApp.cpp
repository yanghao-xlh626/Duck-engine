#include <Duck.h>

class ExampleLayer : public Duck::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{
	}

	void OnUpdate() override
	{
		DC_INFO("ExampleLayer::Update");
	}

	void OnEvent(Duck::Event& event) override
	{
		DC_TRACE("{0}", event.ToString());
	}

};



class Sandbox :public Duck::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}
	~Sandbox()
	{

	}
};

Duck::Application* Duck::CreateApplication()
{
	return new Sandbox();
}