#include "../includes/array.h"

static array_t *delete(array_t *this, size_t pos);

static array_t *delete(array_t *this, size_t pos)
{
    size_t len = this->size(this);
    char **tmp = malloc(sizeof(char *) * (len));
    int step = 0;

    if (pos > len) {
        pos = len;
    }
    for (size_t i = 0; this->tab[i] != NULL; i++) {
        if (i == pos) {
            step = 1;
        } else {
            tmp[i - step] = malloc(sizeof(char) * (strlen(this->tab[i]) + 1));
            strcpy(tmp[i - step], this->tab[i]);
        }
    }
    tmp[len - 1] = NULL;
    this->clear(this);
    this->tab = my_word_array_dup((const char **)tmp);
    free_word_array(tmp);
    return this;
}