#include "../includes/array.h"

static int whereis(const array_t *this, const char *s);

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
    }
    return 0;
}

static int whereis(const array_t *this, const char *s)
{
    if (this->tab != NULL) {
        for (int i = 0; this->tab[i] != NULL; i++) {
            if (my_strcmp(this->tab[i], s) == 0) {
                return i;
            }
        }
    }
    return -1;
}