#include "include.h"

static array_t *sort(array_t *this, int (*cmp)(char const *, char const *));

static array_t *sort(array_t *this, int (*cmp)(char const *, char const *))
{
    char *tmp = NULL;

    for (int i = 0; this->tab[i] != NULL; i++) {
        for (int j = 0; this->tab[j + 1] != NULL; j++) {
            if (cmp(this->tab[j], this->tab[j + 1]) > 0) {
                tmp = this->tab[j];
                this->tab[j] = this->tab[j + 1];
                this->tab[j + 1] = tmp;
            }
        }
    }
    return this;
}