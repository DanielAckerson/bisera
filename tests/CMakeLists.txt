set(DEPS "${PROJECT_SOURCE_DIR}/deps")

set(GLAD "${DEPS}/glad/glad.h"
    "${DEPS}/glad.c")

set(LODEPNG "${DEPS}/lodepng.h"
    "${DEPS}/lodepng.cpp")

add_executable(loadtextures loadtextures.cpp ${GLAD} ${LODEPNG})
target_include_directories(loadtextures PRIVATE ${DEPS})
target_link_libraries(loadtextures glfw ${CMAKE_DL_LIBS})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR} )
