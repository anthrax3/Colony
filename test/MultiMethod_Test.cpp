/**
 *   @file: MultiMethod_Test.cpp
 *
 *   @date: Jun 15, 2016
 * @author: mateusz
 */

#include <memory>
#include "gtest/gtest.h"
#include "MultiMethod.h"

using namespace std;

struct Shape { virtual ~Shape() {} }; // virtual dtor ensures vtable
struct Box : Shape { };
struct Sphere : Shape { };

int rawBoxBox(const Shape* s1, const Shape* s2) {
    return 1;
}

int rawBoxSphere(const Shape* s1, const Shape* s2) {
    return 2;
}

int rawSphereSphere(const Shape* s1, const Shape* s2) {
    return 3;
}

TEST(MultiMethod_Test, dispatch_method_raw_pointer) {
    MultiMethod<const Shape*, const Shape*, int> multi_method;
    multi_method.addMethod<const Box*, const Box*>(rawBoxBox);
    multi_method.addMethod<const Box*, const Sphere*>(rawBoxSphere);
    multi_method.addMethodReverseParams<const Sphere*, const Box*>(rawBoxSphere);
    multi_method.addMethod<const Sphere*, const Sphere*>(rawSphereSphere);

    Shape* box = new Box();
    Shape* sphere = new Sphere();

    EXPECT_EQ(1, multi_method.dispatch(box, box));
    EXPECT_EQ(2, multi_method.dispatch(box, sphere));
    EXPECT_EQ(2, multi_method.dispatch(sphere, box));
    EXPECT_EQ(3, multi_method.dispatch(sphere, sphere));

    delete box;
    delete sphere;
}


int sharedBoxBox(const shared_ptr<Shape> s1, const shared_ptr<Shape> s2) {
    return 1;
}

int sharedBoxSphere(const shared_ptr<Shape> s1, const shared_ptr<Shape> s2) {
    return 2;
}

int sharedSphereSphere(const shared_ptr<Shape> s1, const shared_ptr<Shape> s2) {
    return 3;
}

TEST(MultiMethod_Test, dispatch_method_shared_pointer) {
    MultiMethod<const shared_ptr<Shape>, const shared_ptr<Shape>, int> multi_method;
    multi_method.addMethod<const shared_ptr<Box>, const shared_ptr<Box>>(sharedBoxBox);
    multi_method.addMethod<const shared_ptr<Box>, const shared_ptr<Sphere>>(sharedBoxSphere);
    multi_method.addMethodReverseParams<const shared_ptr<Sphere>, const shared_ptr<Box>>(sharedBoxSphere);
    multi_method.addMethod<const shared_ptr<Sphere>, const shared_ptr<Sphere>>(sharedSphereSphere);

    shared_ptr<Shape> box = make_shared<Box>();
    shared_ptr<Shape> sphere = make_shared<Sphere>();

    EXPECT_EQ(1, multi_method.dispatch(box, box));
    EXPECT_EQ(2, multi_method.dispatch(box, sphere));
    EXPECT_EQ(2, multi_method.dispatch(sphere, box));
    EXPECT_EQ(3, multi_method.dispatch(sphere, sphere));
}
