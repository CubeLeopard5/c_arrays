#include "../includes/array.h"

static void insert_c(array_t *this, size_t pos, const char *str);

static void insert_c(array_t *this, size_t pos, const char *str)
{
    size_t len = this->size(this) + 1;
    char **t = malloc(sizeof(char *) * (len + 1));
    int step = 0;

    if (pos > len) {
        pos = len - 1;
    }
    for (size_t i = 0; i < len; i++) {
        if (i == pos) {
            t[i] = malloc(sizeof(char) * (strlen(str) + 1));
            strcpy(t[i], str);
            step = 1;
        } else {
            t[i] = malloc(sizeof(char) * (strlen(this->tab[i - step]) + 1));
            strcpy(t[i], this->tab[i - step]);
        }
    }
    t[len] = NULL;
    this->clear(this);
    this->tab = my_word_array_dup((const char **)t);
    free_word_array(t);
}