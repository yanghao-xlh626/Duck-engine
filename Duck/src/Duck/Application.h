#pragma once
#include "Core.h"

#include "Window.h"
#include "Duck/LayerStack.h"
#include "Duck/Events/Event.h"
#include "Duck/Events/ApplicationEvent.h"

namespace Duck
{
	class DUCK_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	//To be define in Client
	Application* CreateApplication();
}

