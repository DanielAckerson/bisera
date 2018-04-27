set(DEPS "${CMAKE_SOURCE_DIR}/deps")
set(GLAD "${DEPS}/glad/glad.h"
    "${DEPS}/glad.c")
set(LODEPNG "${DEPS}/lodepng.h"
    "${DEPS}/lodepng.cpp")

file(GLOB bisera_SRC
    "src/*.h"
    "src/*.cpp")

add_executable(bisera-client ${bisera_SRC} ${GLAD} ${LODEPNG})
target_include_directories(bisera-client PRIVATE "${DEPS}")
target_link_libraries(bisera-client glfw ${CMAKE_DL_LIBS})
