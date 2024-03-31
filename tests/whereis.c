#include "../includes/array.h"
#include <criterion/criterion.h>

// Test case for finding the index of an existing string in the array
Test(whereis, find_existing_string) {
    array_t my_array;
    const char *elements[] = {"Apple", "Banana", "Orange", NULL};
    array_init(&my_array, elements);

    // Find the index of the string "Banana"
    int result = my_array.whereis(&my_array, "Banana");
    
    // Assert that the result matches the expected index
    cr_assert_eq(result, 1);

    // Clean up after the test
    array_destroy(&my_array);
}

// Test case for finding the index of a non-existing string in the array
Test(whereis, find_non_existing_string) {
    array_t my_array;
    const char *elements[] = {"Apple", "Banana", "Orange", NULL};
    array_init(&my_array, elements);

    // Find the index of the string "Grape"
    int result = my_array.whereis(&my_array, "Grape");
    
    // Assert that the result is -1 (indicating that the string is not found)
    cr_assert_eq(result, -1);

    // Clean up after the test
    array_destroy(&my_array);
}

// Test case for finding the index of a string in an empty array
Test(whereis, find_in_empty_array) {
    array_t my_array;
    array_init(&my_array, NULL); // Initialize an empty array

    // Find the index of the string "Apple"
    int result = my_array.whereis(&my_array, "Apple");
    
    // Assert that the result is -1 (indicating that the string is not found)
    cr_assert_eq(result, -1);

    // Clean up after the test
    array_destroy(&my_array);
}