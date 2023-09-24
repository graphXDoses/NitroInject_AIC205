project "AIC205_Core"
    language "C"

    targetdir ("%{wks.location}/build/bin/%{cfg.buildcfg}/")
	  objdir ("%{wks.location}/build/bin-int/")

    files
    {
        "*.h",
        "*.c"
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
