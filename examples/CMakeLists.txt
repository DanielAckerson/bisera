link_libraries(bisera)

set(bisera_game_SRCS
    bisera-game.cpp
    mainmenu_state.cpp)

add_executable(bisera-game
    ${bisera_game_SRCS}
    $<TARGET_OBJECTS:glad>
    $<TARGET_OBJECTS:lodepng>)
