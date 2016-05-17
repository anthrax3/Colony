# Find QT dependncies
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Qml REQUIRED)

# Do QT configuration
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Add QT resources
qt5_add_resources(RESOURCES 
                    ../resource/qml.qrc
)

# Collect source files
set(SOURCES 
        SceneNode.cpp
)
    
# Add a project library target that gathers all the sources
add_library(${PROJECT_NAME}
                ${SOURCES}
)

# Include directories
target_include_directories(${PROJECT_NAME}
                            PUBLIC
                                ./
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
                            ${PROJECT_NAME} 
                            Qt5::Core 
                            Qt5::Widgets 
                            Qt5::Qml                            
)