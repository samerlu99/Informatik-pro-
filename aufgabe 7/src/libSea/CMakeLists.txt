add_library(Sea
                Grid2D.inl Grid2D.h
                Object.cpp Object.h
                Coordinates.cpp Coordinates.h)

target_include_directories(Sea PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
