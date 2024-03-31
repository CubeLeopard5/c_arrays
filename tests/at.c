#include "../includes/array.h"
#include <criterion/criterion.h>

// Test case for accessing an element at a valid position
Test(at, valid_position) {
    array_t my_array;
    const char *elements[] = {"Apple", "Banana", "Orange", NULL};

    array_init(&my_array, elements);

    char *result = my_array.at(&my_array, 0);

    cr_assert_str_eq(result, "Apple");

    array_destroy(&my_array);
}

// Test case for accessing an element at an invalid position (position >= size)
Test(at, invalid_position_greater_than_size) {
    array_t my_array;
    const char *elements[] = {"Apple", "Banana", "Orange", NULL};

    array_init(&my_array, elements);

    char *result = my_array.at(&my_array, 5);

    cr_assert_null(result);

    array_destroy(&my_array);
}

// Test case for accessing an element at an invalid position (negative position)
Test(at, invalid_negative_position) {
    array_t my_array;
    const char *elements[] = {"Apple", "Banana", "Orange", NULL};

    array_init(&my_array, elements);

    char *result = my_array.at(&my_array, -1);

    cr_assert_null(result);

    array_destroy(&my_array);
}