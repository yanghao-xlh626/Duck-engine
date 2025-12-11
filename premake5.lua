 workspace "DuckEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"	
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

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
		"%{prj.name}/src/"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0"
		buildoptions { "/utf-8" }
		defines {"DC_PLATFORM_WINDOWS","DC_BUILD_DLL"}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "DC_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DC_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DC_DIST"
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
		systemversion "10.0"
		buildoptions { "/utf-8" }
		defines {"DC_PLATFORM_WINDOWS",}

	filter "configurations:Debug"
		defines "DC_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DC_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DC_DIST"
		optimize "On"

