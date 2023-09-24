project "AIC205_Core"
    language "C"
    cdialect "C99"

    defines { "_CRT_SECURE_NO_WARNINGS" }
    targetname "aic205"

    targetdir ("%{wks.location}/build/%{prj.name}_%{cfg.buildcfg}/bin/")
	  objdir ("%{wks.location}/build/%{prj.name}_%{cfg.buildcfg}/bin-int/")

    files
    {
        "src/**.h",
        "src/**.c"
    }

    includedirs
    {
        "src"
    }

    postbuildcommands {
      "if not exist $(SolutionDir)\\TestingProjects\\common mkdir $(SolutionDir)\\TestingProjects\\common",
      "{COPY} %{prj.location}src/aic205.h $(SolutionDir)\\TestingProjects\\common",
      "{COPY} %{cfg.targetdir}/aic205.lib $(SolutionDir)\\TestingProjects\\common"
    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        kind "StaticLib"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        kind "StaticLib"
        runtime "Release"
        optimize "on"
        symbols "off"
