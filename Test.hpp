//
//  Tests.hpp
//  FLTK-template
//
//  Created by Andreas Aurlien on 17/01/2019.
//  Copyright © 2019 Daniel Solberg. All rights reserved.
//

#include "std_lib_facilities.h"

#pragma once

template <typename T>
struct Test {
    T answer;
    T returnValue;
    string description;
    bool passed;
};

template <typename T>
class FunctionTests {
    vector<Test<T>> tests;
    bool allTestsPassed;

public:
    FunctionTests() : allTestsPassed(false) {};
    void addTest(T answer, T returnValue, string description) {
        tests.push_back(Test<T>{answer, returnValue, description, (answer == returnValue)});
    };
    bool checkAllTestsPassed();
    void updateAllTestsPassed() {this->allTestsPassed = checkAllTestsPassed();};
    bool getAllTestsPassed() const {return allTestsPassed;};
    Test<T>* begin() {return &tests[0];};
    Test<T>* end() {return &tests[tests.size()-1] + 1;};
};
template <typename T>
 bool FunctionTests<T>::checkAllTestsPassed() {
    for (auto& test : tests) {
        if (!test.passed) {
            return false;
        }
    }
    return true;
 };
