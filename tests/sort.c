#include "include.h"
#include <criterion/criterion.h>

// Comparison function for sorting in ascending order
int cmp_asc(const char *a, const char *b) {
    return strcmp(a, b);
}

// Comparison function for sorting in descending order
int cmp_desc(const char *a, const char *b) {
    return strcmp(b, a);
}

// Test case for sorting the array in ascending order
Test(sort, ascending_order) {
    array_t my_array;
    const char *elements[] = {"Orange", "Apple", "Banana", NULL};
    array_init(&my_array, elements);

    // Sort the array in ascending order
    my_array.sort(&my_array, cmp_asc);
    
    // Assert that the elements are sorted in ascending order
    cr_assert_str_eq(my_array.tab[0], "Apple");
    cr_assert_str_eq(my_array.tab[1], "Banana");
    cr_assert_str_eq(my_array.tab[2], "Orange");

    // Clean up after the test
    array_destroy(&my_array);
}

// Test case for sorting the array in descending order
Test(sort, descending_order) {
    array_t my_array;
    const char *elements[] = {"Orange", "Apple", "Banana", NULL};
    array_init(&my_array, elements);

    // Sort the array in descending order
    my_array.sort(&my_array, cmp_desc);
    
    // Assert that the elements are sorted in descending order
    cr_assert_str_eq(my_array.tab[0], "Orange");
    cr_assert_str_eq(my_array.tab[1], "Banana");
    cr_assert_str_eq(my_array.tab[2], "Apple");

    // Clean up after the test
    array_destroy(&my_array);
}
