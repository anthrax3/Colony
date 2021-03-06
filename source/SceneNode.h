/**
 *   @file: SceneNode.h
 *
 *   @date: May 15, 2016
 * @author: Mateusz Midor
 */

#ifndef SOURCE_SCENENODE_H_
#define SOURCE_SCENENODE_H_

#include <memory>
#include <typeinfo>
#include <vector>
#include <algorithm>

class SceneNode {


	/**
	 * @name	findByTypeFromChildrenUp
	 * @brief	Find first occurrence of a node of type NodeType among children or up in the graph
	 * @param	NodeType Type of desired node
	 * @return	Pointer to node, if exists. Empty pointer otherwise
	 */
	template<class NodeType>
	std::shared_ptr<NodeType> findNodeByTypeFromChildrenUp() {

		// a handy shortcut for getting hash_code
		#define HASH(E) (typeid(E).hash_code())

		// check if type of object under obj_ptr is NodeType
		auto isDesiredType = [](auto obj_ptr) { return HASH(NodeType) == HASH(*obj_ptr); };

		// find a child of type NodeType
		auto result = std::find_if(children.begin(), children.end(), isDesiredType);

		// child found. Return pointer
		if (result != children.end())
			return std::static_pointer_cast<NodeType>(*result);

		// child not found. Check siblings
		if (parent)
			return parent->findNodeByTypeFromChildrenUp<NodeType>();

		// child not found. Return empty pointer
		return std::shared_ptr<NodeType>();
	}

    template<class NodeType>
    std::shared_ptr<NodeType> findNodeByTypeFromChildrenDown() {

        // a handy shortcut for getting hash_code
        #define HASH(E) (typeid(E).hash_code())

        // check if type of object under obj_ptr is NodeType
        auto isDesiredType = [](auto obj_ptr) { return HASH(NodeType) == HASH(*obj_ptr); };

        // check every child
        for (const auto child : children) {
            if (isDesiredType(child))
                return std::static_pointer_cast<NodeType>(child);

            if (auto found = child->findNodeByTypeFromChildrenDown<NodeType>())
                return found;
        }

        // node not found. Return empty pointer
        return std::shared_ptr<NodeType>();
    }

    SceneNode* findRoot(SceneNode *node) {
        while (node->parent)
            node = node->parent;

        return node;
    }

public:
	// super-node
	SceneNode *parent;

	// sub-nodes
	std::vector<std::shared_ptr<SceneNode>> children;
	std::vector<std::shared_ptr<SceneNode>> buffer_add;

public:
	SceneNode();
	virtual ~SceneNode();

	void addChild(const std::shared_ptr<SceneNode> child);
	void bufferedAddChild(const std::shared_ptr<SceneNode> child);
	void bufferSync();

	/**
	 * @name	findNodeByType
	 * @brief	Find first occurrence of a node of type NodeType among siblings or up in the graph
	 * @param	NodeType Type of desired node
	 * @return	Pointer to node, if exists. Empty pointer otherwise
	 */
	template<class NodeType>
	std::shared_ptr<NodeType> findNodeByType() {

		// if no parent - no siblings. Return empty pointer
		if (!parent)
			return std::shared_ptr<NodeType>();

		// check parent's children (siblings of this node) and up in the graph
		return parent->findNodeByTypeFromChildrenUp<NodeType>();
	}

    /**
     * @name    findNodeByTypeEverywhere
     * @brief   Find first occurrence of a node of type NodeType among root children or down in the graph
     * @param   NodeType Type of desired node
     * @return  Pointer to node, if exists. Empty pointer otherwise
     */
    template<class NodeType>
    std::shared_ptr<NodeType> findNodeByTypeEverywhere() {

        // first - find the root node
        auto root = findRoot(this);

        // check root children and down in the graph
        return root->findNodeByTypeFromChildrenDown<NodeType>();
    }
};

#endif /* SOURCE_SCENENODE_H_ */
