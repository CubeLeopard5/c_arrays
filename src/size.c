#include "include.h"

static int size(const array_t *this);

static int size(const array_t *this)
{
    int count = 0;

    if (this->tab != NULL) {
        for (int i = 0; this->tab[i] != NULL; i++) {
            count++;
        }
    }
    return count;
}