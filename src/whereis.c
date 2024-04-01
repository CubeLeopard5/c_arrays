#include "../includes/array.h"

static int whereis(const array_t *this, const char *s);

static int whereis(const array_t *this, const char *s)
{
    if (this->tab != NULL) {
        for (int i = 0; this->tab[i] != NULL; i++) {
            if (strcmp(this->tab[i], s) == 0) {
                return i;
            }
        }
    }
    return -1;
}