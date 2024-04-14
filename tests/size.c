#include "include.h"
#include <criterion/criterion.h>

// Test case for getting the size of a non-empty array
Test(size, non_empty_array) {
    array_t my_array;
    const char *elements[] = {"Apple", "Banana", "Orange", NULL};
    array_init(&my_array, elements);

    // Get the size of the array
    int result = my_array.size(&my_array);
    
    // Assert that the result matches the expected size
    cr_assert_eq(result, 3);

    // Clean up after the test
    array_destroy(&my_array);
}

// Test case for getting the size of an empty array
Test(size, empty_array) {
    array_t my_array;
    array_init(&my_array, NULL); // Initialize an empty array

    // Get the size of the array
    int result = my_array.size(&my_array);
    
    // Assert that the result is 0
    cr_assert_eq(result, 0);

    // Clean up after the test
    array_destroy(&my_array);
}