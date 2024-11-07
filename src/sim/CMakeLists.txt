# src/sim/CMakeLists.txt

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

add_executable(airplaneSim airplaneSim.cpp)

target_include_directories(airplaneSim PRIVATE classes utilities)

target_link_libraries(airplaneSim sfml-system sfml-window sfml-graphics sfml-audio)
