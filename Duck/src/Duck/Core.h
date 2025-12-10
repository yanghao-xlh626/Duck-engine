#pragma once

#ifdef DC_PLATFORM_WINDOWS
	#ifdef DC_BUILD_DLL
		#define DUCK_API __declspec(dllexport)
	#else
		#define DUCK_API __declspec(dllimport)
	#endif
#else
	#error Duck only support Windows now!
#endif

#define BIT(x) (1<<x)