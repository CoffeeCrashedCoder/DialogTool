
set_symbols("debug")
set_optimize("none")

add_packages("nlohmann_json")

add_requires( "imgui v1.91.0-docking", { 
    configs={
        opengl3 = true,
        glfw    = true
    }})
add_requires( "glfw" )

add_requires("json")

function writeToGame()
    local gameRepoPath = "../Fork/game_project1/game/game/data/dialogs/Dialog.json"
end


target( "DialogTool" )
    set_kind( "binary" )

    add_packages( "glfw", "imgui", "nlohmann_json")
    
    add_includedirs( "source/glad/include" )
    set_basename("DialogTool_$(mode)_$(arch)")

    set_targetdir "bin"
    set_objectdir "build/obj"

    add_headerfiles( 
        "**.h",
        "**.hpp" 
        )
    add_files( "**.cpp", "**.c" )
target_end()