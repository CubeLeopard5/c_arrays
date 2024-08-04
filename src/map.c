#include "include.h"

static array_t *map(array_t *this, char *(*mapper)(const char *));

static array_t *map(array_t *this, char *(*mapper)(const char *))
{
    if (!this || !this->tab || !mapper)
        return this;

    size_t size = this->size(this);

    for (size_t i = 0; i < size; ++i) {
        char *new_str = mapper(this->tab[i]);
        free(this->tab[i]);
        this->tab[i] = new_str;
    }
    return this;
}
