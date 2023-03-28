
set(HEADER_LIST "${Perlin_SOURCE_DIR}/include/")

# Make a static library
add_library(engine SHARED 
    engine.cpp 
    Game.cpp 
    TextureManager.cpp
    GameObject.cpp
    ${HEADER_LIST})

# We need this directory, and users of our library will need it too
target_include_directories(engine PUBLIC ../include)

# All users of this library will need at least C++11
target_compile_features(engine PUBLIC cxx_std_11)

target_link_libraries(engine PUBLIC ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
