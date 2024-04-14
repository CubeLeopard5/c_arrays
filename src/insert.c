#include "../includes/array.h"

static array_t *insert_c(array_t *this, size_t pos, const char *str);

static array_t *insert_c(array_t *this, size_t pos, const char *str)
{
    size_t len = this->size(this) + 1;
    char **tmp = malloc(sizeof(char *) * (len + 1));
    int step = 0;

    if (pos > len) {
        pos = len - 1;
    }
    for (size_t i = 0; i < len; i++) {
        if (i == pos) {
            tmp[i] = malloc(sizeof(char) * (strlen(str) + 1));
            strcpy(tmp[i], str);
            step = 1;
        } else {
            tmp[i] = malloc(sizeof(char) * (strlen(this->tab[i - step]) + 1));
            strcpy(tmp[i], this->tab[i - step]);
        }
    }
    tmp[len] = NULL;
    this->clear(this);
    this->tab = my_word_array_dup((const char **)tmp);
    free_word_array(tmp);
    return this;
}