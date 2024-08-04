#include "include.h"
#include <criterion/criterion.h>
#include <ctype.h>
#include <string.h>

// Mock mapper function: converts string to uppercase
static char *to_uppercase(const char *str) {
    if (!str) return NULL;
    char *new_str = strdup(str);
    if (!new_str) return NULL;
    for (size_t i = 0; new_str[i]; i++) {
        new_str[i] = toupper(new_str[i]);
    }
    return new_str;
}

// Mock mapper function: reverses the string
static char *reverse_string(const char *str) {
    if (!str) return NULL;
    size_t len = strlen(str);
    char *new_str = malloc((len + 1) * sizeof(char));
    if (!new_str) return NULL;
    for (size_t i = 0; i < len; i++) {
        new_str[i] = str[len - i - 1];
    }
    new_str[len] = '\0';
    return new_str;
}

// Test case for mapping a function to all elements of the array (to_uppercase)
Test(map, map_to_uppercase) {
    array_t my_array;
    const char *elements[] = {"apple", "banana", "orange", NULL};
    array_init(&my_array, elements);

    // Apply the mapper function
    my_array.map(&my_array, to_uppercase);

    // Assert that each element in the array has been modified as expected
    cr_assert_str_eq(my_array.tab[0], "APPLE");
    cr_assert_str_eq(my_array.tab[1], "BANANA");
    cr_assert_str_eq(my_array.tab[2], "ORANGE");

    // Clean up after the test
    array_destroy(&my_array);
}

// Test case for mapping a function to all elements of the array (reverse_string)
Test(map, map_reverse_string) {
    array_t my_array;
    const char *elements[] = {"apple", "banana", "orange", NULL};
    array_init(&my_array, elements);

    // Apply the mapper function
    my_array.map(&my_array, reverse_string);

    // Assert that each element in the array has been modified as expected
    cr_assert_str_eq(my_array.tab[0], "elppa");
    cr_assert_str_eq(my_array.tab[1], "ananab");
    cr_assert_str_eq(my_array.tab[2], "egnaro");

    // Clean up after the test
    array_destroy(&my_array);
}

// Test case for mapping with a NULL mapper function
Test(map, map_with_null_mapper) {
    array_t my_array;
    const char *elements[] = {"apple", "banana", "orange", NULL};
    array_init(&my_array, elements);

    // Apply the mapper function
    array_t *result = my_array.map(&my_array, NULL);

    // Assert that the array is unchanged
    cr_assert_eq(result, &my_array);
    cr_assert_str_eq(my_array.tab[0], "apple");
    cr_assert_str_eq(my_array.tab[1], "banana");
    cr_assert_str_eq(my_array.tab[2], "orange");

    // Clean up after the test
    array_destroy(&my_array);
}

// Test case for mapping an empty array
Test(map, map_empty_array) {
    array_t my_array;
    const char *elements[] = {NULL};
    array_init(&my_array, elements);

    // Apply the mapper function
    my_array.map(&my_array, to_uppercase);

    // Assert that the array remains empty
    cr_assert_null(my_array.tab[0]);

    // Clean up after the test
    array_destroy(&my_array);
}
