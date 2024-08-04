#include "include.h"
#include <criterion/criterion.h>

// Test case for finding all occurrences of a string in the array
Test(find_all, find_all_occurrences) {
    array_t my_array;
    const char *elements[] = {"apple", "banana", "apple", "orange", "apple", NULL};
    array_init(&my_array, elements);

    size_t count;
    size_t *positions = my_array.find_all(&my_array, "apple", &count);

    // Assert that the count is correct
    cr_assert_eq(count, 3);

    // Assert that the positions are correct
    cr_assert_eq(positions[0], 0);
    cr_assert_eq(positions[1], 2);
    cr_assert_eq(positions[2], 4);

    // Clean up after the test
    free(positions);
    array_destroy(&my_array);
}

// Test case for finding no occurrences of a string in the array
Test(find_all, find_no_occurrences) {
    array_t my_array;
    const char *elements[] = {"apple", "banana", "orange", NULL};
    array_init(&my_array, elements);

    size_t count;
    size_t *positions = my_array.find_all(&my_array, "grape", &count);

    // Assert that the count is zero
    cr_assert_eq(count, 0);

    // Clean up after the test
    free(positions); // Ensure this is safe to call with a NULL pointer
    array_destroy(&my_array);
}

// Test case for finding occurrences with a NULL string
Test(find_all, find_null_string) {
    array_t my_array;
    const char *elements[] = {"apple", "banana", "orange", NULL};
    array_init(&my_array, elements);

    size_t count;
    size_t *positions = my_array.find_all(&my_array, NULL, &count);

    // Assert that the count is zero
    cr_assert_eq(count, 0);

    // Assert that the positions array is NULL
    cr_assert_null(positions);

    // Clean up after the test
    free(positions); // Ensure this is safe to call with a NULL pointer
    array_destroy(&my_array);
}

// Test case for finding all occurrences when count is NULL
Test(find_all, find_all_occurrences_count_null) {
    array_t my_array;
    const char *elements[] = {"apple", "banana", "apple", "orange", "apple", NULL};
    array_init(&my_array, elements);

    size_t *positions = my_array.find_all(&my_array, "apple", NULL);

    // Assert that the positions are correct
    cr_assert_eq(positions[0], 0);
    cr_assert_eq(positions[1], 2);
    cr_assert_eq(positions[2], 4);

    // Clean up after the test
    free(positions);
    array_destroy(&my_array);
}
