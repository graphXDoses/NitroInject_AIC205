project "a9f3"
    language "C"
    cdialect "C99"
    dependson { "AIC205_Core" }

    targetdir ("%{wks.location}/build/%{prj.name}_%{cfg.buildcfg}/bin/")
	  objdir ("%{wks.location}/build/%{prj.name}_%{cfg.buildcfg}/bin-int/")

    files
    {
        "*.h",
        "*.c"
    }

    includedirs
    {
        "%{wks.location}/TestingProjects/common"
    }

    libdirs
    {
        "%{wks.location}/TestingProjects/common"
    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        kind "ConsoleApp"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        kind "ConsoleApp"
        runtime "Release"
        optimize "on"
