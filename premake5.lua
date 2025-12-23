 workspace "DuckEngine"
	architecture "x64"

	startproject "Sandbox"
	configurations
	{
		"Debug",
		"Release",
		"Dist"	
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- 包含相对与根目录(解决方法路径)的目录
IncludeDir = {}
IncludeDir["GLFW"] = "Duck/vendor/GLFW/include"

-- 包含GLFW中的premake5.lua
include "Duck/vendor/GLFW" 

project "GLFW"
    staticruntime "on"

project "Duck"
	location "Duck"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/"..outputdir .. "/%{prj.name}")
	objdir ("bin-int/"..outputdir .. "/%{prj.name}")

	pchheader "dcpch.h"
	pchsource "Duck/src/dcpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src/",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		buildoptions { "/utf-8" }
		defines {"DC_PLATFORM_WINDOWS","DC_BUILD_DLL"}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "DC_DEBUG"
		buildoptions "/MDd"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "DC_RELEASE"
		buildoptions "/MD"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "DC_DIST"
		buildoptions "/MD"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"

	language "C++"
	
	targetdir ("bin/"..outputdir .. "/%{prj.name}")
	objdir ("bin-int/"..outputdir .. "%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	includedirs
	{
		"Duck/vendor/spdlog/include",
		"Duck/src/"
	}

	links
	{
		"Duck"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		buildoptions { "/utf-8" }

		defines {"DC_PLATFORM_WINDOWS",}

	filter "configurations:Debug"
		defines "DC_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "DC_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "DC_DIST"
		buildoptions "/MD"
		optimize "On"

