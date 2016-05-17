/**
 *   @file: SceneNode_Test.cpp
 *
 *   @date: May 17, 2016
 * @author: Mateusz Midor
 */

#include <memory>
#include "gtest/gtest.h"
#include "SceneNode.h"

// A couple of SceneNode descendants to build an interesting scene graph
class ANode: public SceneNode {
};
class BNode: public SceneNode {
};
class CNode: public SceneNode {
};
class DNode: public SceneNode {
};

using namespace std;

class SceneNode_Test: public testing::Test {
public:
    // nodes to build a scene graph from
    shared_ptr<SceneNode> root;
    shared_ptr<ANode> a;
    shared_ptr<BNode> b;
    shared_ptr<CNode> c;
    shared_ptr<DNode> d;

    // per test function
    virtual void SetUp() {
        root = make_shared<SceneNode>();
        a = make_shared<ANode>();
        b = make_shared<BNode>();
        c = make_shared<CNode>();
        d = make_shared<DNode>();

        root->addChild(a);
        a->addChild(b);
        b->addChild(c);
        b->addChild(d);

        /*
         SCENE GRAPH:

                root
                 |
                 a
                 |
                 b
                / \
               c   d
         */
    }

    // per test function
    virtual void TearDown() {
        // no need to do nothing
    }

    // per whole suite
    static void SetUpTestCase() {
        // no need to do nothing
    }

    // per whole suite
    static void TearDownTestCase() {
        // no need to do nothing
    }
};

TEST_F(SceneNode_Test, childFindParent) {
    auto found = c->findByType<BNode>();
    EXPECT_TRUE(found);
}

TEST_F(SceneNode_Test, childFindGrandparent) {
    auto found = c->findByType<ANode>();
    EXPECT_TRUE(found);
}

TEST_F(SceneNode_Test, siblingFindSibling) {
    auto found = c->findByType<DNode>();
    EXPECT_TRUE(found);
}

TEST_F(SceneNode_Test, parentCantFindChild) {
    auto found = b->findByType<CNode>();
    EXPECT_FALSE(found);
}

TEST_F(SceneNode_Test, granparentCantFindGrandchild) {
    auto found = a->findByType<CNode>();
    EXPECT_FALSE(found);
}
