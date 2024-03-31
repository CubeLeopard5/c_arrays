#include "./includes/array.h"

int main(void)
{
    array_t arr;

    const char *t[5] = { "Hello", "World", "Test", "toto", NULL };

    array_init(&arr, t);
    arr.print(&arr);
    array_destroy(&arr);
    return 0;
}