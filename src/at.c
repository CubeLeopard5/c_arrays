#include "../includes/array.h"

static char *at(const array_t *this, size_t pos);

static char *at(const array_t *this, size_t pos)
{
    size_t size = this->size(this);

    if (this->tab != NULL && size > 0 && pos < size) {
        return this->tab[pos];
    }
    return NULL;
}