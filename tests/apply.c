#include "include.h"
#include <criterion/criterion.h>
#include <ctype.h>

// Mock function to be applied on each element
static int mock_function(char *element) {
    // We are just marking the element by changing the first character to uppercase
    if (element != NULL && *element != '\0') {
        *element = toupper(*element);
        return 0;
    }
    return -1; // Error
}

// Test case for applying a function to all elements of the array
Test(apply, apply_function_to_all_elements) {
    array_t my_array;
    const char *elements[] = {"apple", "banana", "orange", NULL};
    array_init(&my_array, elements);

    // Apply the mock function to all elements
    my_array.apply(&my_array, mock_function);
    
    // Assert that each element in the array has been modified as expected
    cr_assert_str_eq(my_array.tab[0], "Apple");
    cr_assert_str_eq(my_array.tab[1], "Banana");
    cr_assert_str_eq(my_array.tab[2], "Orange");

    // Clean up after the test
    array_destroy(&my_array);
}

// Test case for applying a function only on elements matching a specific criterion
Test(apply_on_match, apply_function_on_match) {
    array_t my_array;
    const char *elements[] = {"apple", "banana", "orange", NULL};
    array_init(&my_array, elements);

    // Apply the mock function only to elements starting with 'b'
    my_array.apply_on_match(&my_array, mock_function, "banana", strcmp);
    
    // Assert that only the second element has been modified as expected
    cr_assert_str_eq(my_array.tab[0], "apple");
    cr_assert_str_eq(my_array.tab[1], "Banana");
    cr_assert_str_eq(my_array.tab[2], "orange");

    // Clean up after the test
    array_destroy(&my_array);
}