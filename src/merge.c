#include "../includes/array.h"

static void merge_c(array_t *this, const char **t);

static void merge_c(array_t *this, const char **t)
{
    int len1 = this->size(this);
    int len2 = get_array_length(t);
    char **tab = malloc(sizeof(char *) * (len1 + len2 + 1));
    int idx = 0;

    for (int i = 0; this->tab[i] != NULL; i++, idx++) {
        tab[idx] = malloc(sizeof(char) * (strlen(this->tab[i]) + 1));
        strcpy(tab[idx], this->tab[i]);
    }
    for (int i = 0; t[i] != NULL; i++, idx++) {
        tab[idx] = malloc(sizeof(char) * (strlen(t[i]) + 1));
        strcpy(tab[idx], t[i]);
    }
    tab[len1 + len2] = NULL;
    this->tab = my_word_array_dup((const char **)tab);
    free_word_array(tab);
}

static void merge_t(array_t *this, array_t *t);

static void merge_t(array_t *this, array_t *t)
{
    int len1 = this->size(this);
    int len2 = t->size(t);
    char **tab = malloc(sizeof(char *) * (len1 + len2 + 1));
    int idx = 0;

    for (int i = 0; this->tab[i] != NULL; i++, idx++) {
        tab[idx] = malloc(sizeof(char) * (strlen(this->tab[i]) + 1));
        strcpy(tab[idx], this->tab[i]);
    }
    for (int i = 0; t->tab[i] != NULL; i++, idx++) {
        tab[idx] = malloc(sizeof(char) * (strlen(t->tab[i]) + 1));
        strcpy(tab[idx], t->tab[i]);
    }
    tab[len1 + len2] = NULL;
    this->tab = my_word_array_dup((const char **)tab);
    free_word_array(tab);
}