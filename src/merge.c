#include "../includes/array.h"

static void merge_c(array_t *this, char **t);

static void merge_c(array_t *this, char **t)
{
    int len1 = this->size(this);
    int len2 = my_get_word_array_len(t);
    char **tab = malloc(sizeof(char *) * (len1 + len2 + 1));
    int idx = 0;

    for (int i = 0; this->tab[i] != NULL; i++, idx++) {
        tab[idx] = malloc(sizeof(char) * (my_strlen(this->tab[i]) + 1));
        my_strcpy(tab[idx], this->tab[i]);
    }
    for (int i = 0; t[i] != NULL; i++, idx++) {
        tab[idx] = malloc(sizeof(char) * (my_strlen(t[i]) + 1));
        my_strcpy(tab[idx], t[i]);
    }
    tab[len1 + len2] = NULL;
    this->tab = my_word_array_dup(tab);
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
        tab[idx] = malloc(sizeof(char) * (my_strlen(this->tab[i]) + 1));
        my_strcpy(tab[idx], this->tab[i]);
    }
    for (int i = 0; t->tab[i] != NULL; i++, idx++) {
        tab[idx] = malloc(sizeof(char) * (my_strlen(t->tab[i]) + 1));
        my_strcpy(tab[idx], t->tab[i]);
    }
    tab[len1 + len2] = NULL;
    this->tab = my_word_array_dup(tab);
    free_word_array(tab);
}