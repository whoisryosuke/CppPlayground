#pragma once
#include <iostream>
#include "RangeLoopsCustomTypes.h"

/// <summary>
/// This is how to create a custom type (class, struct, etc) that implements a range.
/// It basically requires a `begin()` and `end()` methods to the type.
/// </summary>
namespace RangeLoopsCustomTypes {

	void CustomTypeExample() {
		dummy_array<int, 3> arr; 
		arr.SetAt(0, 1);
		arr.SetAt(1, 2); 
		arr.SetAt(2, 3);
        for (auto&& e : arr)
        {
            std::cout << e << '\n';
        }

		// We pass the custom array to a method that takes a `const` parameter,
		// meaning it won't mutate it (and might be more performant)
		print_dummy_array(arr);
	}


};