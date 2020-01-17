cmake_minimum_required(VERSION 2.4)

project(madness)

set(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})

add_executable(madness
   src/madness.cpp
   src/entity.cpp
   src/mob.cpp
   src/player.cpp
   src/cultist.cpp
)

if(MSVC)
    target_compile_options(madness PRIVATE /W4 /WX)
else()
    target_compile_options(madness PRIVATE -Wall -Wextra -pedantic)
endif()

target_link_libraries(madness ${CURSES_LIBRARIES}) 
