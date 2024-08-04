#include "include.h"
#include <criterion/criterion.h>

// Test case for copying an array
Test(copy, copy_array) {
    array_t my_array;
    const char *elements[] = {"apple", "banana", "orange", NULL};
    array_init(&my_array, elements);

    array_t *copied_array = my_array.copy(&my_array);

    // Assert that the copied array is not NULL
    cr_assert_not_null(copied_array);

    // Assert that the copied array has the same size as the original
    cr_assert_eq(copied_array->size(copied_array), my_array.size(&my_array));

    // Assert that each element in the copied array matches the original array
    for (int i = 0; i < my_array.size(&my_array); ++i) {
        cr_assert_str_eq(copied_array->tab[i], my_array.tab[i]);
    }

    // Clean up after the test
    array_destroy(&my_array);
    array_destroy(copied_array);
    free(copied_array);
}

// Test case for copying an empty array
Test(copy, copy_empty_array) {
    array_t my_array;
    const char *elements[] = {NULL};
    array_init(&my_array, elements);

    array_t *copied_array = my_array.copy(&my_array);

    // Assert that the copied array is not NULL
    cr_assert_not_null(copied_array);

    // Assert that the copied array has the same size as the original
    cr_assert_eq(copied_array->size(copied_array), my_array.size(&my_array));

    // Assert that the copied array is empty
    cr_assert_null(copied_array->tab[0]);

    // Clean up after the test
    array_destroy(&my_array);
    array_destroy(copied_array);
    free(copied_array);
}

// Helper function to create an array with a single element
static array_t *create_single_element_array(const char *element) {
    array_t *arr = malloc(sizeof(array_t));
    const char *elements[] = {element, NULL};
    array_init(arr, elements);
    return arr;
}

// Test case for copying an array with a single element
Test(copy, copy_single_element_array) {
    array_t *my_array = create_single_element_array("apple");

    array_t *copied_array = my_array->copy(my_array);

    // Assert that the copied array is not NULL
    cr_assert_not_null(copied_array);

    // Assert that the copied array has the same size as the original
    cr_assert_eq(copied_array->size(copied_array), my_array->size(my_array));

    // Assert that the element in the copied array matches the original array
    cr_assert_str_eq(copied_array->tab[0], my_array->tab[0]);

    // Clean up after the test
    array_destroy(my_array);
    array_destroy(copied_array);
    free(my_array);
    free(copied_array);
}
