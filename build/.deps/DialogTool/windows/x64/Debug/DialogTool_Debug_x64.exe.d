{
    files = {
        [[build\obj\DialogTool\windows\x64\Debug\source\main.cpp.obj]],
        [[build\obj\DialogTool\windows\x64\Debug\source\Tutorial.cpp.obj]],
        [[build\obj\DialogTool\windows\x64\Debug\source\glad\src\glad.c.obj]]
    },
    values = {
        [[C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.42.34433\bin\HostX64\x64\link.exe]],
        {
            "-nologo",
            "-dynamicbase",
            "-nxcompat",
            "-machine:x64",
            [[-libpath:C:\Users\sebalund\AppData\Local\.xmake\packages\i\imgui\v1.91.0-docking\d9e9ddef3ba745949021bac4dd6b3d57\lib]],
            [[-libpath:C:\Users\sebalund\AppData\Local\.xmake\packages\g\glfw\3.4\fc47358da159466996f7d289b4cf1b4e\lib]],
            "-debug",
            [[-pdb:bin\DialogTool_Debug_x64.pdb]],
            "imgui.lib",
            "glfw3.lib",
            "opengl32.lib",
            "imm32.lib",
            "user32.lib",
            "shell32.lib",
            "gdi32.lib"
        }
    }
}