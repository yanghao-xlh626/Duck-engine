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

#ifdef DC_ENABLE_ASSERTS
	#define DC_ASSERT(x, ...) {if(!(x)) {DC_ERROR("Assertion Failed:{0}",__VA_ARGS__);__debugbreak();}}
	#define DC_CORE_ASSERT(x, ...) {if(!(x)) {DC_CORE_ERROR("Assertion Failed:{0}",__VA_ARGS__);__debugbreak();}}
#else
	#define DC_ASSERT(x, ...)
	#define DC_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1<<x)