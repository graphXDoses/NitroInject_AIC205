workspace "NitroInject_AIC205"
    architecture "x64"

    configurations
    {
        "Debug", "Release"
    }

include "AIC205_Core"
group "Testing Projects"
    include "TestingProjects/a2f4r"
    include "TestingProjects/a8f3"
    include "TestingProjects/a9f3"
    include "TestingProjects/a12f3"
    include "TestingProjects/a14f3"
group ""
