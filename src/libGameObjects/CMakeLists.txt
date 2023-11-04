add_library(GameObjects
                PlayerSea.cpp PlayerSea_output.cpp PlayerSea_stats.cpp PlayerSea.h
                Ship.cpp Ship.h
                Vortex.cpp Vortex.h
                DoubleMissile.cpp DoubleMissile.h
                TumblingMissile.cpp TumblingMissile.h
                Missile.cpp Missile.h
                Attack.h
                Constants.h
                Output.cpp Output.h)

target_include_directories(GameObjects PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(GameObjects Sea)
