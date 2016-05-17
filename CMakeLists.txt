cmake_minimum_required (VERSION 3.2)

# Executable name 
project (Colony)

# Setup project version
set(PROJECT_MAJOR_VERSION 0)
set(PROJECT_MINOR_VERSION 1)
set(PROJECT_PATCH_LEVEL 0)
set(PROJECT_VERSION ${PROJECT_MAJOR_VERSION}.${PROJECT_MINOR_VERSION}.${PROJECT_PATCH_LEVEL})

# Setup compilation flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++14")
SET(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
SET(CMAKE_CXX_FLAGS_DEBUG  "-O0 -g")

# Find QT dependncies
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Qml REQUIRED)

# Do QT configuration
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Add QT resources
qt5_add_resources(RESOURCES 
                    resource/qml.qrc
)

# Collect source files
set(SOURCES 
        source/main.cpp
        source/SceneNode.cpp
)
        
# Add executable target
add_executable(${PROJECT_NAME} 
                    ${SOURCES} 
                    ${HDR} 
                    ${INT_HDR} 
                    ${RESOURCES}
)

# Include directories
target_include_directories(${PROJECT_NAME}
                            PRIVATE
                                source/
)                                

# Link required libraries
target_link_libraries(${PROJECT_NAME} 
                        PRIVATE
                            Qt5::Core 
                            Qt5::Widgets 
                            Qt5::Qml
)

add_subdirectory(external/googletest)
