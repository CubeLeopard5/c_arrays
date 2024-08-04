#include "include.h"
#include <criterion/criterion.h>
#include <ctype.h>

// Mock filter function: returns 1 if the string starts with 'a', 0 otherwise
static int starts_with_a(const char *str) {
    return str && str[0] == 'a';
}

// Mock filter function: returns 1 if the string length is greater than 5, 0 otherwise
static int length_greater_than_5(const char *str) {
    return str && strlen(str) > 5;
}

// Test case for filtering elements starting with 'a'
Test(filter, filter_elements_starting_with_a) {
    array_t my_array;
    const char *elements[] = {"apple", "banana", "avocado", "orange", NULL};
    array_init(&my_array, elements);

    // Apply the filter function
    my_array.filter(&my_array, starts_with_a);

    // Assert that the array only contains elements starting with 'a'
    cr_assert_eq(my_array.size(&my_array), 2);
    cr_assert_str_eq(my_array.tab[0], "apple");
    cr_assert_str_eq(my_array.tab[1], "avocado");
    cr_assert_null(my_array.tab[2]);

    // Clean up after the test
    array_destroy(&my_array);
}

// Test case for filtering elements with length greater than 5
Test(filter, filter_elements_length_greater_than_5) {
    array_t my_array;
    const char *elements[] = {"apple", "banana", "avocado", "orange", NULL};
    array_init(&my_array, elements);

    // Apply the filter function
    my_array.filter(&my_array, length_greater_than_5);

    // Assert that the array only contains elements with length greater than 5
    cr_assert_eq(my_array.size(&my_array), 2);
    cr_assert_str_eq(my_array.tab[0], "banana");
    cr_assert_str_eq(my_array.tab[1], "avocado");
    cr_assert_null(my_array.tab[2]);

    // Clean up after the test
    array_destroy(&my_array);
}

// Test case for filtering with a NULL function
Test(filter, filter_with_null_function) {
    array_t my_array;
    const char *elements[] = {"apple", "banana", "avocado", "orange", NULL};
    array_init(&my_array, elements);

    // Apply the filter function
    array_t *result = my_array.filter(&my_array, NULL);

    // Assert that the array is unchanged
    cr_assert_eq(result, &my_array);
    cr_assert_eq(my_array.size(&my_array), 4);
    cr_assert_str_eq(my_array.tab[0], "apple");
    cr_assert_str_eq(my_array.tab[1], "banana");
    cr_assert_str_eq(my_array.tab[2], "avocado");
    cr_assert_str_eq(my_array.tab[3], "orange");

    // Clean up after the test
    array_destroy(&my_array);
}

// Test case for filtering an empty array
Test(filter, filter_empty_array) {
    array_t my_array;
    const char *elements[] = {NULL};
    array_init(&my_array, elements);

    // Apply the filter function
    my_array.filter(&my_array, starts_with_a);

    // Assert that the array remains empty
    cr_assert_eq(my_array.size(&my_array), 0);
    cr_assert_null(my_array.tab[0]);

    // Clean up after the test
    array_destroy(&my_array);
}

// Test case for filtering an array with no matching elements
Test(filter, filter_no_matching_elements) {
    array_t my_array;
    const char *elements[] = {"banana", "orange", "grape", NULL};
    array_init(&my_array, elements);

    // Apply the filter function
    my_array.filter(&my_array, starts_with_a);

    // Assert that the array is empty after filtering
    cr_assert_eq(my_array.size(&my_array), 0);
    cr_assert_null(my_array.tab[0]);

    // Clean up after the test
    array_destroy(&my_array);
}
