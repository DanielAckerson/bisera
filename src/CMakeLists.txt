set(bisera_SRCS
    game.cpp
    mainwindow.cpp
    mesh.cpp
    shader.cpp
    texture.cpp)

add_library(bisera ${bisera_SRCS}
    $<TARGET_OBJECTS:glad>
    $<TARGET_OBJECTS:lodepng>)

target_link_libraries(bisera glfw ${CMAKE_DL_LIBS})
