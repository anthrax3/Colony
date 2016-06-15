/**
 *   @file: MultiMethod.h
 *
 *   @date: Jun 14, 2016
 * @author: mateusz
 */

#ifndef SOURCE_MULTIMETHOD_H_
#define SOURCE_MULTIMETHOD_H_

#include <typeinfo>
#include <functional>
#include <unordered_map>
#include <cstdio>
#include <type_traits>

/**
 * @class   MultiMethod
 * @brief   An implementation for 2 argument methods
 * @note    The arguments must by of pointer type since the dispatching is based on polymorphism of argument type
 *          It can be raw pointer/shared_ptr
 */
template <class Param1Type, class Param2Type, class ResultType>
class MultiMethod {
    using HashType = long;
    using FuncType = std::function<ResultType(Param1Type,Param2Type)>;

    // here we store the function handling specific argument type combinations
    std::unordered_map<HashType, std::unordered_map<HashType, FuncType>> methods;

public:

    template <class T1, class T2>
    void addMethod(FuncType f) {
        // extract argument base type, no matter raw pointer or shared_ptr
        using T1_base_type = decltype(*std::declval<T1>());
        using T2_base_type = decltype(*std::declval<T2>());

        // get hash code of the argument base type
        auto T1_hash = typeid(T1_base_type).hash_code();
        auto T2_hash = typeid(T2_base_type).hash_code();

        // install the function
        methods[T1_hash][T2_hash] = f;
//        printf( "addMethod for : %s, %s\n", typeid(T1_base_type).name(), typeid(T2_base_type).name() );
    }

    template <class T1, class T2>
    void addMethodReverseParams(FuncType f) {
        // extract argument base type, no matter raw pointer or shared_ptr
        using T1_base_type = decltype(*std::declval<T1>());
        using T2_base_type = decltype(*std::declval<T2>());

        // get hash code of the argument base type
        auto T1_hash = typeid(T1_base_type).hash_code();
        auto T2_hash = typeid(T2_base_type).hash_code();

        // install the function with parameters reversed
        methods[T1_hash][T2_hash] = [f](auto p1, auto p2) { return f(p2, p1); };
//        printf( "addMethodReverseParams for : %s, %s\n", typeid(T1_base_type).name(), typeid(T2_base_type).name() );
    }

    template <class T1, class T2>
    ResultType dispatch(T1 p1, T2 p2) {
        // get hash code of the argument base type
        auto T1_hash = typeid(*p1).hash_code();
        auto T2_hash = typeid(*p2).hash_code();
//        printf( "dispatch for : %s, %s\n", typeid(*p1).name(), typeid(*p2).name() );

        // call the function
        return methods.at(T1_hash).at(T2_hash)(p1, p2);
    }
};

#endif /* SOURCE_MULTIMETHOD_H_ */
