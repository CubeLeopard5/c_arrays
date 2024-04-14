#include "include.h"

static array_t *clear(array_t *this);

static array_t *clear(array_t *this)
{
    if (this->tab != NULL) {
        for (int i = 0; this->tab[i] != NULL; i++) {
            free(this->tab[i]);
        }
        free(this->tab);
        this->tab = NULL;
    }
    return this;
}