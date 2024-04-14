#include "include.h"

void array_destroy(array_t *this)
{
    if (this->tab != NULL) {
        for (int i = 0; this->tab[i] != NULL; i++) {
            free(this->tab[i]);
        }
        free(this->tab);
        this->tab = NULL;
    }
}