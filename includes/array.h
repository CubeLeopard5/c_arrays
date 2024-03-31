/*
** EPITECH PROJECT, 2021
** sdfghj
** File description:
** kjhgfd
*/

#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct array_s
{
    char **tab;

    void (*print)(const struct array_s *this);
    int (*size)(const struct array_s *this);
    int (*whereis)(const struct array_s *this, const char *s);
    char *(*at)(const struct array_s *this, size_t pos);
    char *(*to_string)(const struct array_s *this, const char c);
    void (*push_back)(struct array_s *this, const char *str);
    void (*insert_c)(struct array_s *this, size_t pos, const char *str);
    void (*sort)(struct array_s *this, int (*cmp)(char const *, char const *));
    void (*delete)(struct array_s *this, size_t pos);
    void (*merge_c)(struct array_s *this, char **t);
    void (*merge_t)(struct array_s *this, struct array_s *t);
    void (*clear)(struct array_s *this);
    void (*apply)(struct array_s *this, int (*f)(char *));
    void (*apply_on_match)(struct array_s *this, int (*f)(char *), const char *data_ref, int (*cmp)());
    char *(*occurrence_f)(const struct array_s *this, const char *str);
    char **(*occurrence)(const struct array_s *this, const char *str, size_t n);
} array_t;

void array_init(array_t *this, const char **t);
void array_destroy(array_t *this);

#endif