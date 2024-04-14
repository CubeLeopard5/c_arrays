#include "../includes/array.h"

static array_t *apply_on_match(array_t *this, int (*f)(char *), const char *data_ref, int (*cmp)());

static array_t *apply_on_match(array_t *this, int (*f)(char *), const char *data_ref, int (*cmp)())
{
    for (int i = 0; this->tab[i] != NULL; i++) {
        if ((*cmp)(data_ref, this->tab[i]) == 0) {
            (*f)(this->tab[i]);
        }
    }
    return this;
}

static array_t *apply(array_t *this, int (*f)(char *));

static array_t *apply(array_t *this, int (*f)(char *))
{
    for (int i = 0; this->tab[i] != NULL; i++) {
        (*f)(this->tab[i]);
    }
    return this;
}