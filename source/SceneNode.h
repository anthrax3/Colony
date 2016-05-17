/**
 *   @file: SceneNode.h
 *
 *   @date: May 15, 2016
 * @author: Mateusz Midor
 */

#ifndef SOURCE_SCENENODE_H_
#define SOURCE_SCENENODE_H_

#include <memory>
#include <vector>
#include <algorithm>
#include <typeinfo>

class SceneNode {

    SceneNode *parent;
    std::vector<std::shared_ptr<SceneNode>> children;

public:
    SceneNode();
    virtual ~SceneNode();

    /**
     * @brief: add child node to current node and set it's parent to current node.
     * @param child Node to be added
     */
    void addChild(const std::shared_ptr<SceneNode> child);

    /**
     * @brief find first occurrence of a node of type NodeType among siblings or up in the graph
     * @param NodeType Type of node we are looking for
     * @return shared_ptr if node found. Empty shared_ptr otherwise
     */
    template<class NodeType>
    std::shared_ptr<NodeType> findByType() {

        // if no parent - no siblings. Return empty pointer
        if (!parent)
            return std::shared_ptr<NodeType>();

        // check parent's children (siblings of this node) and up in the graph
        return parent->findByTypeFromChildrenUp<NodeType>();
    }

private:
    /**
     * @brief find first occurrence of a node of type NodeType among children or up in the graph
     * @param NodeType Type of node we are looking for
     * @return shared_ptr if node found. Empty shared_ptr otherwise
     */
    template<class NodeType>
    std::shared_ptr<NodeType> findByTypeFromChildrenUp() {

        // a handy shortcut for getting hash_code
        #define HASH(E) (typeid(E).hash_code())

        // check if type of object under obj_ptr is NodeType
        auto isDesiredType = [](auto obj_ptr) {return HASH(NodeType) == HASH(*obj_ptr);};

        // find a child of type NodeType
        auto result = std::find_if(children.begin(), children.end(), isDesiredType);

        // child found. Return pointer
        if (result != children.end())
            return std::static_pointer_cast < NodeType > (*result);

        // child not found. Check siblings
        if (parent)
            return parent->findByTypeFromChildrenUp<NodeType>();

        // child not found. Return empty pointer
        return std::shared_ptr<NodeType>();
    }
};

#endif /* SOURCE_SCENENODE_H_ */
