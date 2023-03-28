
add_executable(game *.cpp)

target_compile_features(game PRIVATE cxx_std_17)

target_link_libraries(game PRIVATE engine)