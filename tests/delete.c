#include "include.h"
#include <criterion/criterion.h>

// Test case for deleting an element from the array at a valid position
Test(delete, valid_position) {
    array_t my_array;
    const char *elements[] = {"Apple", "Banana", "Orange", NULL};
    array_init(&my_array, elements);

    // Delete the element at position 1 (index 1)
    my_array.delete(&my_array, 1);
    
    // Assert that the size of the array is reduced by 1
    cr_assert_eq(my_array.size(&my_array), 2);

    // Assert that the element at position 1 (index 1) is "Orange" after deletion
    cr_assert_str_eq(my_array.tab[1], "Orange");

    // Clean up after the test
    array_destroy(&my_array);
}

// Test case for deleting an element from the array at the last position
Test(delete, last_position) {
    array_t my_array;
    const char *elements[] = {"Apple", "Banana", "Orange", NULL};
    array_init(&my_array, elements);

    // Delete the element at the last position (index 2)
    my_array.delete(&my_array, 2);
    
    // Assert that the size of the array is reduced by 1
    cr_assert_eq(my_array.size(&my_array), 2);

    // Assert that the element at the last position is NULL after deletion
    cr_assert_null(my_array.tab[2]);

    // Clean up after the test
    array_destroy(&my_array);
}

// Test case for deleting an element from the array at a position greater than the size
Test(delete, position_greater_than_size) {
    array_t my_array;
    const char *elements[] = {"Apple", "Banana", "Orange", NULL};
    array_init(&my_array, elements);

    // Delete an element at a position greater than the size of the array
    my_array.delete(&my_array, 5);
    
    // Assert that the the last element has been removed
    cr_assert_eq(my_array.size(&my_array), 2);

    // Assert that the array contents remain unchanged
    cr_assert_str_eq(my_array.tab[0], "Apple");
    cr_assert_str_eq(my_array.tab[1], "Banana");

    // Clean up after the test
    array_destroy(&my_array);
}