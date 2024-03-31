/*
** EPITECH PROJECT, 2021
** dfghj
** File description:
** jhgfd
*/

#include "../includes/array.h"
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

int my_strlen(char const *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        nb++;
    }
    return nb;
}

void fill_array(array_t *this, const char **t)
{
    int len = 0;
    int i = 0;

    for (i = 0; t[i] != NULL; i++) {
        len = my_strlen(t[i]);
        this->tab[i] = malloc(sizeof(char) * (len + 1));
        for (int j = 0; t[i][j] != '\0'; j++) {
            this->tab[i][j] = t[i][j];
        }
        this->tab[i][len] = '\0';
    }
    this->tab[i] = NULL;
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