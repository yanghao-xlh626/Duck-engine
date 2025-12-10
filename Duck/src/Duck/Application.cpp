#include "Application.h"

#include "Duck/Events/ApplicationEvent.h"
#include "Duck/Log.h"

namespace Duck
{
	Application::Application()
	{}

	Application::~Application()
	{}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			DC_TRACE(e.ToString());
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			DC_TRACE(e.ToString());
		}
		while (true);
	}

}
