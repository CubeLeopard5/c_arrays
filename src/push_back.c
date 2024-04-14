#include "include.h"

static array_t *push_back(array_t *this, const char *str);

static array_t *push_back(array_t *this, const char *str)
{
    int len = this->size(this);

    if (this->tab != NULL) {
        this->tab = realloc(this->tab, sizeof(char *) * (len + 2));
        this->tab[len] = malloc(strlen(str) + 1);
        strcpy(this->tab[len], str);
        this->tab[len + 1] = NULL;
    }
    return this;
}