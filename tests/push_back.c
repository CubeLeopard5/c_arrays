#include "../includes/array.h"
#include <criterion/criterion.h>

// Test case for pushing a string to the back of the array
Test(push_back, push_string_back) {
    array_t my_array;
    const char *elements[] = {"Apple", "Banana", "Orange", NULL};
    array_init(&my_array, elements);

    // Push the string "Grape" to the back of the array
    my_array.push_back(&my_array, "Grape");
    
    // Assert that the size of the array is increased by 1
    cr_assert_eq(my_array.size(&my_array), 4);

    // Assert that the element at the last position is "Grape"
    cr_assert_str_eq(my_array.tab[3], "Grape");

    // Clean up after the test
    array_destroy(&my_array);
}