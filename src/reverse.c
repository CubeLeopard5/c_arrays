#include "include.h"

static array_t *reverse(array_t *this);

static array_t *reverse(array_t *this)
{
    if (!this || !this->tab)
        return this;

    size_t size = this->size(this);

    for (size_t i = 0; i < size / 2; ++i) {
        char *temp = this->tab[i];
        this->tab[i] = this->tab[size - i - 1];
        this->tab[size - i - 1] = temp;
    }
    return this;
}
