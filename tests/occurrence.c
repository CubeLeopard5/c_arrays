#include "../includes/array.h"
#include <criterion/criterion.h>

void free_word_array(char **tab);

// Test case for finding occurrences of a substring within the array using occurrence
Test(occurrence, find_occurrences) {
    array_t my_array;
    const char *elements[] = {"apple", "banana", "orange", NULL};
    array_init(&my_array, elements);

    // Find occurrences of the substring "an" within the array
    char **result = my_array.occurrence(&my_array, "an", 2);
    
    // Assert that the result contains the expected occurrences
    cr_assert_str_eq(result[0], "banana");
    cr_assert_str_eq(result[1], "orange");

    // Clean up after the test
    free_word_array(result);
    array_destroy(&my_array);
}

// Test case for finding the first occurrence of a substring within the array using occurrence_f
Test(occurrence_f, find_first_occurrence) {
    array_t my_array;
    const char *elements[] = {"apple", "banana", "orange", NULL};
    array_init(&my_array, elements);

    // Find the first occurrence of the substring "an" within the array
    char *result = my_array.occurrence_f(&my_array, "an");
    
    // Assert that the result matches the expected occurrence
    cr_assert_str_eq(result, "banana");

    // Clean up after the test
    array_destroy(&my_array);
}
