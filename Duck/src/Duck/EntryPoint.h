#pragma once

#ifdef DC_PLATFORM_WINDOWS

extern Duck::Application* Duck::CreateApplication();


int main(int argc,char** argv)
{
	Duck::Log::Init();
	DC_CORE_WARN("Initialized Log!");
	int a = 5;
	DC_INFO("Hello! Var={0}", a);


	auto app = Duck::CreateApplication();
	app->Run();
	delete app;
}
#endif