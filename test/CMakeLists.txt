# Collect source files
set(SOURCES 
        main.cpp
        Dummy_Test.cpp
)
    
# Add library target that gathers all the sources
add_executable(unittest
                ${SOURCES}
)

# Link required libraries to the executable
target_link_libraries(unittest
                        PRIVATE
                            gtest_main
                            ${PROJECT_NAME}
)
                        
# Include directories
target_include_directories(unittest
                            PRIVATE
                                ./
)