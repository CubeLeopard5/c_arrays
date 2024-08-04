#include "include.h"
#include <criterion/criterion.h>

// Test case for checking if the array contains a specific string
Test(contains, contains_existing_element) {
    array_t my_array;
    const char *elements[] = {"apple", "banana", "orange", NULL};
    array_init(&my_array, elements);

    // Assert that the array contains "banana"
    cr_assert(my_array.contains(&my_array, "banana"));

    // Clean up after the test
    array_destroy(&my_array);
}

// Test case for checking if the array does not contain a specific string
Test(contains, does_not_contain_non_existing_element) {
    array_t my_array;
    const char *elements[] = {"apple", "banana", "orange", NULL};
    array_init(&my_array, elements);

    // Assert that the array does not contain "grape"
    cr_assert_not(my_array.contains(&my_array, "grape"));

    // Clean up after the test
    array_destroy(&my_array);
}

// Test case for checking if the array handles NULL input
Test(contains, handles_null_input) {
    array_t my_array;
    const char *elements[] = {"apple", "banana", "orange", NULL};
    array_init(&my_array, elements);

    // Assert that the array does not contain a NULL string
    cr_assert_not(my_array.contains(&my_array, NULL));

    // Clean up after the test
    array_destroy(&my_array);
}

// Test case for checking if the array handles an empty string
Test(contains, handles_empty_string) {
    array_t my_array;
    const char *elements[] = {"apple", "banana", "orange", NULL};
    array_init(&my_array, elements);

    // Assert that the array does not contain an empty string
    cr_assert_not(my_array.contains(&my_array, ""));

    // Clean up after the test
    array_destroy(&my_array);
}

// Test case for checking if the array handles empty array
Test(contains, handles_empty_array) {
    array_t my_array;
    const char *elements[] = {NULL};
    array_init(&my_array, elements);

    // Assert that the array does not contain "banana" in an empty array
    cr_assert_not(my_array.contains(&my_array, "banana"));

    // Clean up after the test
    array_destroy(&my_array);
}
