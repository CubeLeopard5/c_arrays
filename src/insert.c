#include "../includes/array.h"

static void insert_c(array_t *this, size_t pos, const char *str);

int my_get_word_array_len(char **tab)
{
    int count = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        count++;
    }
    return count;
}

char **my_word_array_dup(char **src)
{
    int len = my_get_word_array_len(src);
    char **tab = malloc(sizeof(char *) * (len + 1));

    for (int i = 0; src[i] != NULL; i++) {
        tab[i] = malloc(sizeof(char) * (my_strlen(src[i]) + 1));
        my_strcpy(tab[i], src[i]);
    }
    tab[len] = NULL;
    return tab;
}

void free_word_array(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        free(tab[i]);
    }
    free(tab);
    tab = NULL;
}

static void insert_c(array_t *this, size_t pos, const char *str)
{
    size_t len = this->size(this) + 1;
    char **t = malloc(sizeof(char *) * (len + 1));
    int step = 0;

    if (pos > len) {
        pos = len;
    }
    for (size_t i = 0; this->tab[i - step] != NULL; i++) {
        if (i == pos) {
            t[i] = malloc(sizeof(char) * (my_strlen(str) + 1));
            my_strcpy(t[i], str);
            step = 1;
        } else {
            t[i] = malloc(sizeof(char) * (my_strlen(this->tab[i - step]) + 1));
            my_strcpy(t[i], this->tab[i - step]);
        }
    }
    t[len] = NULL;
    this->clear(this);
    this->tab = my_word_array_dup(t);
    free_word_array(t);
}