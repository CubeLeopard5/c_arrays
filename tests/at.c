#include "../includes/array.h"
#include <criterion/criterion.h>

Test(at, at)
{
    array_t arr;

    const char *t[5] = { "Hello", "World", "Test", "toto", NULL };

    array_init(&arr, t);

    char *result = arr.at(&arr, 0);
    char *expected = "Hello";

    cr_assert_str_eq(result, expected, "Expected: %s, Got: %s", expected, result);
    free(result);
}
