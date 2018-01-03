cmake_minimum_required(VERSION 3.8)
project(bartikova_snake)

set(CMAKE_CXX_STANDARD 11)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(SOURCE_FILES main.cpp Had.cpp Had.h HraciPole.cpp HraciPole.h hra.h hra.cpp Souradnice.cpp Souradnice.h console.cpp console.h TabulkaSkore.cpp TabulkaSkore.h cas.cpp cas.h)
add_executable(bartikova_snake ${SOURCE_FILES})
target_link_libraries(bartikova_snake ${CURSES_LIBRARIES})