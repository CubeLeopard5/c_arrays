#include "include.h"
#include <criterion/criterion.h>

// Test case for merging two arrays (char**)
Test(merge_c, merge_char_arrays) {
    array_t my_array1, my_array2;
    const char *elements1[] = {"Apple", "Banana", "Orange", NULL};
    const char *elements2[] = {"Grape", "Kiwi", "Mango", NULL};
    array_init(&my_array1, elements1);
    array_init(&my_array2, elements2);

    // Merge the two arrays
    my_array1.merge_c(&my_array1, (const char **)my_array2.tab);
    
    // Assert that the size of the resulting array is correct
    cr_assert_eq(my_array1.size(&my_array1), 6);

    // Assert that the elements of the resulting array are correct
    cr_assert_str_eq(my_array1.tab[0], "Apple");
    cr_assert_str_eq(my_array1.tab[1], "Banana");
    cr_assert_str_eq(my_array1.tab[2], "Orange");
    cr_assert_str_eq(my_array1.tab[3], "Grape");
    cr_assert_str_eq(my_array1.tab[4], "Kiwi");
    cr_assert_str_eq(my_array1.tab[5], "Mango");

    // Clean up after the test
    array_destroy(&my_array1);
}

// Test case for merging two arrays (array_t*)
Test(merge_t, merge_array_structs) {
    array_t my_array1, my_array2;
    const char *elements1[] = {"Apple", "Banana", "Orange", NULL};
    const char *elements2[] = {"Grape", "Kiwi", "Mango", NULL};
    array_init(&my_array1, elements1);
    array_init(&my_array2, elements2);

    // Merge the two arrays
    my_array1.merge_t(&my_array1, &my_array2);
    
    // Assert that the size of the resulting array is correct
    cr_assert_eq(my_array1.size(&my_array1), 6);

    // Assert that the elements of the resulting array are correct
    cr_assert_str_eq(my_array1.tab[0], "Apple");
    cr_assert_str_eq(my_array1.tab[1], "Banana");
    cr_assert_str_eq(my_array1.tab[2], "Orange");
    cr_assert_str_eq(my_array1.tab[3], "Grape");
    cr_assert_str_eq(my_array1.tab[4], "Kiwi");
    cr_assert_str_eq(my_array1.tab[5], "Mango");

    // Clean up after the test
    array_destroy(&my_array1);
}
