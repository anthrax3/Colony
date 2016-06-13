# Find QT dependncies
find_package(Qt5Core REQUIRED)
find_package(Qt5Quick REQUIRED)
find_package(Qt5Qml REQUIRED)

# Do QT configuration
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Add QT resources
qt5_add_resources(RESOURCES 
                    ../resource/qml.qrc
)

# Add executable target that makes a demo
add_executable(demo
                    main.cpp 
                    ${HDR}
                    ${INT_HDR}
                    ${RESOURCES}
)

# Link project library to the executable
target_link_libraries(demo
                        PRIVATE
                            colony 
)
