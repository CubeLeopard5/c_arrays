#include "include.h"
#include <criterion/criterion.h>

// Test case for clearing a non-empty array
Test(clear, non_empty_array) {
    array_t my_array;
    const char *elements[] = {"Apple", "Banana", "Orange", NULL};
    array_init(&my_array, elements);

    // Clear the array
    my_array.clear(&my_array);
    
    // Assert that the array pointer is set to NULL after clearing
    cr_assert_null(my_array.tab);

    // Clean up after the test
    // Since the array has been cleared, there's no need to call array_destroy
}

// Test case for clearing an empty array
Test(clear, empty_array) {
    array_t my_array;
    array_init(&my_array, NULL); // Initialize an empty array

    // Clear the array
    my_array.clear(&my_array);
    
    // Assert that the array pointer is set to NULL after clearing
    cr_assert_null(my_array.tab);

    // Clean up after the test
    // Since the array has been cleared, there's no need to call array_destroy
}

// Test case for clearing an already cleared array
Test(clear, already_cleared_array) {
    array_t my_array;
    const char *elements[] = {"Apple", "Banana", "Orange", NULL};
    array_init(&my_array, elements);

    // Clear the array
    my_array.clear(&my_array);
    
    // Clear the array again
    my_array.clear(&my_array);
    
    // Assert that the array pointer is still NULL
    cr_assert_null(my_array.tab);

    // Clean up after the test
    // Since the array has been cleared, there's no need to call array_destroy
}