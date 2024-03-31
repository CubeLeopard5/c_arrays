#include "../includes/array.h"
#include <criterion/criterion.h>

// Test case for converting the array to a string with a specified delimiter
Test(to_string, convert_to_string) {
    array_t my_array;
    const char *elements[] = {"apple", "banana", "orange", NULL};
    array_init(&my_array, elements);

    // Convert the array to a string with a comma as the delimiter
    char *result = my_array.to_string(&my_array, ',');
    
    // Assert that the result matches the expected string
    cr_assert_str_eq(result, "apple,banana,orange");

    // Clean up after the test
    free(result);
    array_destroy(&my_array);
}

// Test case for converting an empty array to a string
Test(to_string, empty_array) {
    array_t my_array;
    array_init(&my_array, NULL); // Initialize an empty array

    // Convert the array to a string with a comma as the delimiter
    char *result = my_array.to_string(&my_array, ',');
    
    // Assert that the result is NULL
    cr_assert_null(result);

    // Clean up after the test
    array_destroy(&my_array);
}