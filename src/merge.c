#include "include.h"

static array_t *merge_c(array_t *this, const char **to_merge);

static array_t *merge_c(array_t *this, const char **to_merge)
{
    int len1 = this->size(this);
    int len2 = get_array_length(to_merge);
    char **tab = malloc(sizeof(char *) * (len1 + len2 + 1));
    int idx = 0;

    for (int i = 0; this->tab[i] != NULL; i++, idx++) {
        tab[idx] = malloc(sizeof(char) * (strlen(this->tab[i]) + 1));
        strcpy(tab[idx], this->tab[i]);
    }
    for (int i = 0; to_merge[i] != NULL; i++, idx++) {
        tab[idx] = malloc(sizeof(char) * (strlen(to_merge[i]) + 1));
        strcpy(tab[idx], to_merge[i]);
    }
    tab[len1 + len2] = NULL;
    this->tab = my_word_array_dup((const char **)tab);
    free_word_array(tab);
    return this;
}

static array_t *merge_t(array_t *this, array_t *to_merge);

static array_t *merge_t(array_t *this, array_t *to_merge)
{
    int len1 = this->size(this);
    int len2 = to_merge->size(to_merge);
    char **tab = malloc(sizeof(char *) * (len1 + len2 + 1));
    int idx = 0;

    for (int i = 0; this->tab[i] != NULL; i++, idx++) {
        tab[idx] = malloc(sizeof(char) * (strlen(this->tab[i]) + 1));
        strcpy(tab[idx], this->tab[i]);
    }
    for (int i = 0; to_merge->tab[i] != NULL; i++, idx++) {
        tab[idx] = malloc(sizeof(char) * (strlen(to_merge->tab[i]) + 1));
        strcpy(tab[idx], to_merge->tab[i]);
    }
    tab[len1 + len2] = NULL;
    this->tab = my_word_array_dup((const char **)tab);
    free_word_array(tab);
    return this;
}