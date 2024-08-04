#include "include.h"
#include <criterion/criterion.h>
#include <string.h>

// Test case for reversing the elements of the array
Test(reverse, reverse_elements) {
    array_t my_array;
    const char *elements[] = {"apple", "banana", "orange", NULL};
    array_init(&my_array, elements);

    // Reverse the array
    my_array.reverse(&my_array);

    // Assert that the elements are in reverse order
    cr_assert_str_eq(my_array.tab[0], "orange");
    cr_assert_str_eq(my_array.tab[1], "banana");
    cr_assert_str_eq(my_array.tab[2], "apple");

    // Clean up after the test
    array_destroy(&my_array);
}

// Test case for reversing an empty array
Test(reverse, reverse_empty_array) {
    array_t my_array;
    const char *elements[] = {NULL};
    array_init(&my_array, elements);

    // Reverse the array
    my_array.reverse(&my_array);

    // Assert that the array remains empty
    cr_assert_null(my_array.tab[0]);

    // Clean up after the test
    array_destroy(&my_array);
}

// Test case for reversing a single-element array
Test(reverse, reverse_single_element) {
    array_t my_array;
    const char *elements[] = {"apple", NULL};
    array_init(&my_array, elements);

    // Reverse the array
    my_array.reverse(&my_array);

    // Assert that the single element remains in place
    cr_assert_str_eq(my_array.tab[0], "apple");

    // Clean up after the test
    array_destroy(&my_array);
}

// Test case for reversing an array with NULL entries
Test(reverse, reverse_array_with_null_entries) {
    array_t my_array;
    const char *elements[] = {"apple", NULL, "banana", NULL, "orange", NULL};
    array_init(&my_array, elements);

    // Reverse the array
    my_array.reverse(&my_array);

    // Assert that the array is reversed correctly
    cr_assert_str_eq(my_array.tab[0], "orange");
    cr_assert_null(my_array.tab[1]);
    cr_assert_str_eq(my_array.tab[2], "banana");
    cr_assert_null(my_array.tab[3]);
    cr_assert_str_eq(my_array.tab[4], "apple");
    cr_assert_null(my_array.tab[5]);

    // Clean up after the test
    array_destroy(&my_array);
}