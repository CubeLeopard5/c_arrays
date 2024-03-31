#include "../includes/array.h"

static char *to_string(const array_t *this, const char c);

int my_strlen(char const *str);

char *word_array_to_string(char **tab, char c)
{
    int size = 0;
    char *str = NULL;
    int idx = 0;
    int count = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        size = size + my_strlen(tab[i]);
        count++;
    }
    str = malloc(sizeof(char) * (size + count + 1));
    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = 0; tab[i][j] != '\0'; j++, idx++) {
            str[idx] = tab[i][j];
        }
        if (tab[i + 1] != NULL) {
            str[idx] = c;
            idx++;
        }
    }
    str[idx] = '\0';
    return str;
}

static char *to_string(const array_t *this, const char c)
{
    if (this->tab != NULL && this->size(this) > 0) {
        for (int i = 0; this->tab[i] != NULL; i++) {
            return word_array_to_string(this->tab, c);
        }
    }
    return NULL;
}