#include "include.h"

static char *reduce(const array_t *this, char *(*reducer)(char *, const char *), char *initial);

static char *reduce(const array_t *this, char *(*reducer)(char *, const char *), char *initial)
{
    if (!this || !this->tab || !reducer) return initial;

    size_t size = this->size(this);
    char *accumulator = initial;

    for (size_t i = 0; i < size; ++i) {
        accumulator = reducer(accumulator, this->tab[i]);
    }
    return accumulator;
}
