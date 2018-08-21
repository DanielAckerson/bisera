link_libraries(bisera)

add_executable(textures
    textures.cpp
    $<TARGET_OBJECTS:glad>
    $<TARGET_OBJECTS:lodepng>)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR} )
