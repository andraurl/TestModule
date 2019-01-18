//
//  TestVisual.hpp
//  FLTK-template
//
//  Created by Andreas Aurlien on 17/01/2019.
//  Copyright © 2019 Daniel Solberg. All rights reserved.
//

#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"

#include "Test.hpp"

#pragma once
using namespace Graph_lib;

template <typename T>
class FunctionTestsWindow : Simple_window {
    const int rightMargin = 100;
    const int leftMargin = 50;
    const int upperMargin = 50;
    const int verticalSpaceBetween = 30;
    const int sideLength = 50;

    FunctionTests<T> tests;
    Vector_ref<Rectangle> vr; // storing status for test
    Vector_ref<Text> vt;    // storing test descriptions

    void attachAllTests();

    public:
    FunctionTestsWindow(Point xy, int w, int h, const string& title, FunctionTests<T> tests);
};
template <typename T>
FunctionTestsWindow<T>::FunctionTestsWindow(Point xy, int w, int h, const string& title, FunctionTests<T> tests)
 : Simple_window(xy, w, h, title),
tests{tests}
{
    this->tests.updateAllTestsPassed();
    attachAllTests();
    wait_for_button();
};

template<typename T>
void FunctionTestsWindow<T>::attachAllTests()
{
    const int DispStatusX = x_max() - rightMargin;
    const int DispStatusY = upperMargin;
    const int DispDescriptionX =  leftMargin;
    const int DispDescriptionY =  DispStatusY + 35;
    
    fl_color(Color::black);
    fl_font(Font::helvetica_bold, 20);
    
    vr.push_back(new Rectangle{Point{DispStatusX, DispStatusY}, sideLength, sideLength});
    vt.push_back(new Text{Point{DispDescriptionX, DispDescriptionY}, "All TESTS PASSED"});
    
    vr[0].set_fill_color(Color{tests.getAllTestsPassed() + 1});
    attach(vr[0]);
    attach(vt[0]);
    
    for (Test<T>& test : tests) {
        int rowNr = vr.size();
        const int DispStatusX = x_max() - rightMargin;
        const int DispStatusY = upperMargin + (sideLength + verticalSpaceBetween) * (rowNr);
        const int DispDescriptionX =  leftMargin;
        const int DispDescriptionY =  DispStatusY + 35;
        
        vr.push_back(new Rectangle{Point{DispStatusX, DispStatusY}, sideLength, sideLength});
        vt.push_back(new Text{Point{DispDescriptionX, DispDescriptionY}, test.description});
        
        int passed = (test.answer == test.returnValue) + 1;
        vr[vr.size() - 1].set_fill_color(Color{passed});
        
        attach(vr[vr.size() - 1]);
        attach(vt[vr.size() - 1]);
    }
};


