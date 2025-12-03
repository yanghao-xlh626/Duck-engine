#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include <spdlog/sinks/stdout_color_sinks.h> 
namespace Duck
{
	class DUCK_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}
//Core log macros
#define DC_CORE_TRACE(...) ::Duck::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define DC_CORE_INFO(...)  ::Duck::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DC_CORE_WARN(...)  ::Duck::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DC_CORE_ERROR(...) ::Duck::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DC_CORE_FATAL(...) ::Duck::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define DC_TRACE(...) ::Duck::Log::GetClientLogger()->trace(__VA_ARGS__)
#define DC_INFO(...)  ::Duck::Log::GetClientLogger()->info(__VA_ARGS__)
#define DC_WARN(...)  ::Duck::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DC_ERROR(...) ::Duck::Log::GetClientLogger()->error(__VA_ARGS__)
#define DC_FATAL(...) ::Duck::Log::GetClientLogger()->fatal(__VA_ARGS__)