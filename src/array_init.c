/*
** EPITECH PROJECT, 2021
** dfghj
** File description:
** jhgfd
*/

#include "include.h"
#include "print.c"
#include "size.c"
#include "whereis.c"
#include "at.c"
#include "to_string.c"
#include "push_back.c"
#include "insert.c"
#include "sort.c"
#include "delete.c"
#include "merge.c"
#include "clear.c"
#include "apply.c"
#include "occurrence.c"
#include "contains.c"
#include "filter.c"
#include "find_all.c"
#include "copy.c"
#include "map.c"
#include "reduce.c"
#include "reverse.c"

int get_array_length(const char **t)
{
    int count = 0;

    if (t == NULL) {
        return count;
    }
    for (int i = 0; t[i] != NULL; i++) {
        count++;
    }
    return count;
}

void fill_array(array_t *this, const char **t)
{
    int len = 0;
    int i = 0;

    for (i = 0; t[i] != NULL; i++) {
        len = strlen(t[i]);
        this->tab[i] = malloc(sizeof(char) * (len + 1));
        for (int j = 0; t[i][j] != '\0'; j++) {
            this->tab[i][j] = t[i][j];
        }
        this->tab[i][len] = '\0';
    }
    this->tab[i] = NULL;
}

char **my_word_array_dup(const char **src)
{
    int len = get_array_length(src);
    char **tab = malloc(sizeof(char *) * (len + 1));

    for (int i = 0; src[i] != NULL; i++) {
        tab[i] = malloc(sizeof(char) * (strlen(src[i]) + 1));
        strcpy(tab[i], src[i]);
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

char *word_array_to_string(char **tab, char c)
{
    int size = 0;
    char *str = NULL;
    int idx = 0;
    int count = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        size = size + strlen(tab[i]);
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

void init_struct(array_t *this)
{
    this->print = &print;
    this->size = &size;
    this->whereis = &whereis;
    this->at = &at;
    this->to_string = &to_string;
    this->push_back = &push_back;
    this->insert_c = &insert_c;
    this->sort = &sort;
    this->delete = &delete;
    this->merge_c = &merge_c;
    this->merge_t = &merge_t;
    this->clear = &clear;
    this->apply = &apply;
    this->apply_on_match = &apply_on_match;
    this->occurrence_f = &occurrence_f;
    this->occurrence = &occurrence;
    this->contains = &contains;
    this->copy = &copy;
    this->filter = &filter;
    this->find_all = &find_all;
    this->map = &map;
    this->reduce = &reduce;
    this->reverse = &reverse;
}

void array_init(array_t *this, const char **t)
{
    int count = get_array_length(t);

    if (t) {
        this->tab = malloc(sizeof(char *) * (count + 1));
        fill_array(this, t);
    } else
        this->tab = NULL;
    init_struct(this);
}