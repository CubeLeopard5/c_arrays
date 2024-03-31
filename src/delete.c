#include "../includes/array.h"

static void delete(array_t *this, size_t pos);

static void delete(array_t *this, size_t pos)
{
    size_t len = this->size(this);
    char **t = malloc(sizeof(char *) * (len));
    int step = 0;

    if (pos > len) {
        pos = len;
    }
    for (size_t i = 0; this->tab[i] != NULL; i++) {
        if (i == pos) {
            step = 1;
        } else {
            t[i - step] = malloc(sizeof(char) * (my_strlen(this->tab[i]) + 1));
            my_strcpy(t[i - step], this->tab[i]);
        }
    }
    t[len - 1] = NULL;
    this->clear(this);
    this->tab = my_word_array_dup(t);
    free_word_array(t);
}