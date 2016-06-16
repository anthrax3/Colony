# Collect source files
set(SOURCES 
        main.cpp
        Dummy_Test.cpp
        SceneNode_Test.cpp
        GameObject_Test.cpp
        TransformMatrixCombiner_Test.cpp
        MultiMethod_Test.cpp
        CircleCircleCollider_Test.cpp
        CircleBoxCollider_Test.cpp
)
    
# Add library target that gathers all the sources
add_executable(unittest
                ${SOURCES}
)

# needed to include whole archive in the test binary because of gtest hackery
#SET (colony-whole-archive -Wl,--whole-archive colony -Wl,--no-whole-archive)

# Link required libraries to the executable
target_link_libraries(unittest
                        PRIVATE
                            #${colony-whole-archive}
                            colony
                            gtest_main
)