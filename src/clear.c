#include "../includes/array.h"

static void clear(array_t *this);

static void clear(array_t *this)
{
    if (this->tab != NULL) {
        for (int i = 0; this->tab[i] != NULL; i++) {
            free(this->tab[i]);
        }
        free(this->tab);
        this->tab = NULL;
    }
}