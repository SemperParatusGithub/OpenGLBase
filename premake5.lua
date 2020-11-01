workspace "OpenGLBase"
	architecture "x64"
	startproject "OpenGLBase"

	configurations { "Debug", "Release" }
	flags { "MultiProcessorCompile" }

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "ThirdParty"
	include "OpenGLBase/ThirdParty/GLFW"
	include "OpenGLBase/ThirdParty/Glad"
	include "OpenGLBase/ThirdParty/imgui"
group ""

project "OpenGLBase"
	location "OpenGLBase"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "On"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files { 
 		"OpenGLBase/src/**.h",
		"OpenGLBase/src/**.cpp"
	}
	includedirs { 
		"OpenGLBase/src",
		"OpenGLBase/ThirdParty/GLFW/include",
		"OpenGLBase/ThirdParty/Glad/include",
		"OpenGLBase/ThirdParty/imgui",
		"OpenGLBase/ThirdParty/glm",
		"OpenGLBase/ThirdParty/stb_image"
	}

	links { "GLFW", "Glad", "ImGui", "opengl32.lib" }
	defines { "_CRT_SECURE_NO_WARNINGS" }

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		symbols "On"
	filter "configurations:Release"
		optimize "On"