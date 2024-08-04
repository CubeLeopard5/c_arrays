#include "include.h"

static int length_greater_than_5(const char *str) {
    return str && strlen(str) > 5;
}

int main(void) {
    array_t my_array;
    const char *elements[] = {"apple", "banana", "avocado", "orange", NULL};
    array_init(&my_array, elements);

    // Apply the filter function
    my_array.filter(&my_array, length_greater_than_5);

    // Clean up after the test
    array_destroy(&my_array);
    return 0;
}