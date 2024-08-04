#include "include.h"

static array_t *filter(array_t *this, int (*func)(const char *));

static array_t *filter(array_t *this, int (*func)(const char *))
{
    if (!this || !this->tab || !func)
        return this;

    size_t size = this->size(this);
    char **new_tab = malloc((size + 1) * sizeof(char *));
    size_t new_size = 0;

    for (size_t i = 0; i < size; ++i) {
        if (func(this->tab[i])) {
            new_tab[new_size++] = strdup(this->tab[i]);
        }
    }
    new_tab[new_size] = NULL;

    for (size_t i = 0; i < size; ++i) {
        free(this->tab[i]);
    }
    free(this->tab);

    this->tab = new_tab;
    return this;
}
