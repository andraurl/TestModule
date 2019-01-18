// Lec2Ex1c.cpp, an improvement of Lec2Ex1c.cpp

#include "std_lib_facilities.h"

#include "TestVisual.hpp"
#include "Test.hpp"

int sum(int n, int m) {
    return n+m;
}

int main() {
    // Graphic part constants
    
    
    FunctionTests<int> testsSum{};
    
    testsSum.addTest(5, sum(2,3), "Adding sums");
    testsSum.addTest(2, sum(1,1), "Adding sums part 2");
    
    constexpr int win_w = 400;
    constexpr int win_h = 855;
    
    FunctionTestsWindow<int> sumTests{Point{1040, 45}, win_w, win_h, "Sum tests", testsSum};
};
