#include "include.h"
#include <criterion/criterion.h>
#include <string.h>
#include <stdlib.h>

// Mock reducer function: concatenates the accumulator and current string
static char *concatenate(char *accumulator, const char *str) {
    if (!accumulator || !str) return NULL;

    size_t new_len = strlen(accumulator) + strlen(str) + 1;
    char *new_str = realloc(accumulator, new_len);
    if (!new_str) return NULL;

    strcat(new_str, str);
    return new_str;
}

// Mock reducer function: computes the length of concatenated strings
static char *count_length(char *accumulator, const char *str) {
    if (!accumulator || !str) return NULL;

    size_t length = strlen(accumulator) + strlen(str);
    char *new_str = malloc(20);  // Allocate sufficient space for length as string
    if (!new_str) return NULL;

    snprintf(new_str, 20, "%ld", length);
    free(accumulator);  // Free the previous accumulator
    return new_str;
}

// Test case for reducing by concatenating strings
Test(reduce, concatenate_all_elements) {
    array_t my_array;
    const char *elements[] = {"apple", "banana", "orange", NULL};
    array_init(&my_array, elements);

    char *initial = strdup("");  // Start with an empty string
    char *result = my_array.reduce(&my_array, concatenate, initial);

    // Assert that the result is the concatenation of all strings
    cr_assert_str_eq(result, "applebananaorange");

    // Clean up after the test
    free(result);
    array_destroy(&my_array);
}

// Test case for reducing by counting the total length of concatenated strings
Test(reduce, count_total_length) {
    array_t my_array;
    const char *elements[] = {"apple", "banana", "orange", NULL};
    array_init(&my_array, elements);

    char *initial = strdup("");  // Start with an empty string
    char *result = my_array.reduce(&my_array, count_length, initial);

    // Assert that the result is the length of concatenated strings as a string
    cr_assert_str_eq(result, "16");

    // Clean up after the test
    free(result);
    array_destroy(&my_array);
}

// Test case for reducing with a NULL reducer function
Test(reduce, reduce_with_null_reducer) {
    array_t my_array;
    const char *elements[] = {"apple", "banana", "orange", NULL};
    array_init(&my_array, elements);

    char *initial = strdup("start");
    char *result = my_array.reduce(&my_array, NULL, initial);

    // Assert that the result is the same as the initial value
    cr_assert_str_eq(result, "start");

    // Clean up after the test
    free(result);
    array_destroy(&my_array);
}

// Test case for reducing an empty array
Test(reduce, reduce_empty_array) {
    array_t my_array;
    const char *elements[] = {NULL};
    array_init(&my_array, elements);

    char *initial = strdup("start");
    char *result = my_array.reduce(&my_array, concatenate, initial);

    // Assert that the result is the same as the initial value
    cr_assert_str_eq(result, "start");

    // Clean up after the test
    free(result);
    array_destroy(&my_array);
}