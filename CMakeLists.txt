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
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG  "-O0 -g --coverage")

enable_testing()
add_subdirectory(external/googletest)
add_subdirectory(source)
add_subdirectory(demo)
add_subdirectory(test)

# "coverage" make target
add_custom_target(coverage
                  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                  COMMAND make test
                  COMMAND gcovr -r ${CMAKE_BINARY_DIR}/.. -e .*external.* -e .*test.* -e .*moc_.* #--branches #-xo ${CMAKE_BINARY_DIR}/coverage.xml
)