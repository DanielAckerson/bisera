link_libraries(bisera)

add_executable(textures
    textures.cpp
    $<TARGET_OBJECTS:glad>
    $<TARGET_OBJECTS:lodepng>)

add_executable(cube
    cube.cpp
    $<TARGET_OBJECTS:glad>
    $<TARGET_OBJECTS:lodepng>)
