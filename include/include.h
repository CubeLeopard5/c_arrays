/*
** EPITECH PROJECT, 2021
** c_array
** File description:
** include file
*/

#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct array_s
{
    char **tab;

    void (*print)(const struct array_s *this);
    int (*size)(const struct array_s *this);
    int (*whereis)(const struct array_s *this, const char *s);
    char *(*at)(const struct array_s *this, size_t pos);
    char *(*to_string)(const struct array_s *this, const char c);
    struct array_s *(*push_back)(struct array_s *this, const char *str);
    struct array_s *(*insert_c)(struct array_s *this, size_t pos, const char *str);
    struct array_s *(*sort)(struct array_s *this, int (*cmp)(char const *, char const *));
    struct array_s *(*delete)(struct array_s *this, size_t pos);
    struct array_s *(*merge_c)(struct array_s *this, const char **t);
    struct array_s *(*merge_t)(struct array_s *this, struct array_s *t);
    struct array_s *(*clear)(struct array_s *this);
    struct array_s *(*apply)(struct array_s *this, int (*f)(char *));
    struct array_s *(*apply_on_match)(struct array_s *this, int (*f)(char *), const char *data_ref, int (*cmp)());
    char *(*occurrence_f)(const struct array_s *this, const char *str);
    char **(*occurrence)(const struct array_s *this, const char *str, size_t n);
    struct array_s *(*reverse)(struct array_s *this);
    struct array_s *(*filter)(struct array_s *this, int (*func)(const char *));
    struct array_s *(*map)(struct array_s *this, char *(*mapper)(const char *));
    char *(*reduce)(const struct array_s *this, char *(*reducer)(char *, const char *), char *initial);
    int (*contains)(const struct array_s *this, const char *str);
    struct array_s *(*copy)(const struct array_s *this);
    size_t *(*find_all)(const struct array_s *this, const char *str, size_t *count);
} array_t;

void array_init(array_t *this, const char **t);
void array_destroy(array_t *this);
int get_array_length(const char **t);
void fill_array(array_t *this, const char **t);
char **my_word_array_dup(const char **src);
void free_word_array(char **tab);
char *word_array_to_string(char **tab, char c);

#endif