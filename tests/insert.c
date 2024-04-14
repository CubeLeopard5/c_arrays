#include "include.h"
#include <criterion/criterion.h>

// Test case for inserting a string into the array at a valid position
Test(insert_c, valid_position) {
    array_t my_array;
    const char *elements[] = {"Apple", "Banana", "Orange", NULL};
    array_init(&my_array, elements);

    // Insert the string "Grape" at position 1 (index 1)
    my_array.insert_c(&my_array, 1, "Grape");
    
    // Assert that the size of the array is increased by 1
    cr_assert_eq(my_array.size(&my_array), 4);

    // Assert that the element at position 1 (index 1) is "Grape" after insertion
    cr_assert_str_eq(my_array.tab[1], "Grape");

    // Assert that the subsequent elements are shifted to the right
    cr_assert_str_eq(my_array.tab[2], "Banana");
    cr_assert_str_eq(my_array.tab[3], "Orange");

    // Clean up after the test
    array_destroy(&my_array);
}

// Test case for inserting a string into the array at the last position
Test(insert_c, last_position) {
    array_t my_array;
    const char *elements[] = {"Apple", "Banana", "Orange", NULL};
    array_init(&my_array, elements);

    // Insert the string "Grape" at the last position (index 3)
    my_array.insert_c(&my_array, 3, "Grape");
    
    // Assert that the size of the array is increased by 1
    cr_assert_eq(my_array.size(&my_array), 4);

    // Assert that the element at the last position is "Grape" after insertion
    cr_assert_str_eq(my_array.tab[3], "Grape");

    // Clean up after the test
    array_destroy(&my_array);
}

// Test case for inserting a string into the array at a position greater than the size
Test(insert_c, position_greater_than_size) {
    array_t my_array;
    const char *elements[] = {"Apple", "Banana", "Orange", NULL};
    array_init(&my_array, elements);

    // Insert the string "Grape" at a position greater than the size of the array
    my_array.insert_c(&my_array, 5, "Grape");
    
    // Assert that the size of the array is increased by 1
    cr_assert_eq(my_array.size(&my_array), 4);

    // Assert that the element at the last position is "Grape" after insertion
    cr_assert_str_eq(my_array.tab[3], "Grape");

    // Clean up after the test
    array_destroy(&my_array);
}