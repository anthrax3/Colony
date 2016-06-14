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

template <class Param1Type, class Param2Type, class ResultType>
class MultiMethod {
    using HashType = long;
    using FuncType = std::function<ResultType(Param1Type,Param2Type)>;
    std::unordered_map<HashType, std::unordered_map<HashType, FuncType>> methods;

public:

    template <class T1, class T2>
    void addMethod(FuncType f) {
        #define HASH(T) (typeid(T).hash_code())
        methods[HASH(T1)][HASH(T2)] = f;
    }

    template <class T1, class T2>
    void addMethodReverseParams(FuncType f) {
        #define HASH(T) (typeid(T).hash_code())
        methods[HASH(T1)][HASH(T2)] = [f](auto p1, auto p2) { return f(p2, p1); };
    }

    template <class T1, class T2>
    ResultType dispatch(Param1Type p1, Param2Type p2) {
        #define HASH(T) (typeid(T).hash_code())
        return methods[HASH(T1)][HASH(T2)](p1, p2);
    }
};

#endif /* SOURCE_MULTIMETHOD_H_ */
