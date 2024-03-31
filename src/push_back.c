#include "../includes/array.h"

static void push_back(array_t *this, const char *str);

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}

static void push_back(array_t *this, const char *str)
{
    int len = this->size(this);

    if (this->tab != NULL) {
        this->tab = realloc(this->tab, sizeof(char *) * (len + 2));
        this->tab[len] = malloc(my_strlen(str) + 1);
        my_strcpy(this->tab[len], str);
        this->tab[len + 1] = NULL;
    }
}