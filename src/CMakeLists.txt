# src/CMakeLists.txt

add_executable(datalink datalink.cpp)

target_include_directories(datalink PRIVATE classes utilities)

target_link_libraries(datalink)

add_subdirectory(sim)
