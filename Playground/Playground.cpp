#include <iostream>
#include "RangeBasedLoops.cpp"
#include "RangeLoopsCustomTypes.h"

int main()
{
    std::cout << "Hello World!\n";

    std::cout << "Range Based Loop!\n";
    auto rangeBasedLoopExample = RangeBasedLoops{};
    rangeBasedLoopExample.Example();

    std::cout << "Range Based Loop with a Custom Type!\n";
    RangeLoopsCustomTypes::CustomTypeExample();

}