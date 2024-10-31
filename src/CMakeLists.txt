# src/CMakeLists.txt

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

add_executable(datalink datalink.cpp)

target_include_directories(datalink PRIVATE classes utilities)

target_link_libraries(datalink sfml-system sfml-window sfml-graphics sfml-audio)