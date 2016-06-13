# Find QT dependncies
find_package(Qt5Core REQUIRED)
find_package(Qt5Quick REQUIRED)
find_package(Qt5Qml REQUIRED)

# Do QT configuration
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Collect source files
set(SOURCES 
        Component.cpp
        GraphicsComponent.cpp
        LocalTransformComponent.cpp
        SceneNode.cpp
        GameObject.cpp
        TransformMatrixCombiner.cpp
        RenderItem.cpp
        SceneView.cpp
        SceneRenderer.cpp
        SceneSynchronizer.cpp
        Line2DRenderItem.cpp
        SceneBuilder.cpp
        SceneUpdater.cpp
        RotatorComponent.cpp
        Ant.cpp
        SimpleAntDriver.cpp
        TimerComponent.cpp
        AntGeneratorComponent.cpp
        AntHillBuilder.cpp
        CircleRenderItem.cpp
        GranaryComponent.cpp
        PhysicsComponent.cpp
        ColliderItem.cpp
        CircleColliderItem.cpp
        CollisionResolver.cpp
)
    
# Add a project library target that gathers all the sources
add_library(colony
                ${SOURCES}
)

# Link Qt dependencies
target_link_libraries(colony 
                        PUBLIC 
                            Qt5::Core 
                            Qt5::Quick 
                            Qt5::Qml

)
  
# Include header directories
target_include_directories(colony
                            PUBLIC
                                ./  
)
