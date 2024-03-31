#include "../includes/array.h"

static char *at(const array_t *this, size_t pos);

static char *at(const array_t *this, size_t pos)
{
    if (this->tab != NULL && this->size(this) > 0) {
        return this->tab[pos];
    }
    return NULL;
}