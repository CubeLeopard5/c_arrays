#include "../includes/array.h"

int my_strlen(char const *str);

static char **occurrence(const array_t *this, const char *str, size_t n);

static char **occurrence(const array_t *this, const char *str, size_t n)
{
    int idx = 0;
    size_t tab_idx = 0;
    int tab_len = 1;
    char **tab = malloc(sizeof(char *) * tab_len);

    tab[tab_idx] = NULL;
    for (int i = 0; this->tab[i] != NULL; i++) {
        for (int j = 0; this->tab[i][j] != '\0'; j++) {
            if (tab_idx == n) {
                return tab;
            }
            if (this->tab[i][j] == str[idx]) {
                idx++;
            } else if (idx == my_strlen(str)) {
                tab = realloc(tab, sizeof(char *) * (tab_len + 1));
                tab[tab_idx] = malloc(sizeof(char) * (my_strlen(this->tab[i]) + 1));
                my_strcpy(tab[tab_idx], this->tab[i]);
                tab_idx++;
                tab[tab_idx] = NULL;
                tab_len++;
                idx = 0;
            } else {
                idx = 0;
            }
        }
    }
    return tab;
}

static char *occurrence_f(const array_t *this, const char *str);

static char *occurrence_f(const array_t *this, const char *str)
{
    int idx = 0;

    for (int i = 0; this->tab[i] != NULL; i++) {
        for (int j = 0; this->tab[i][j] != '\0'; j++) {
            if (this->tab[i][j] == str[idx]) {
                idx++;
            } else if (idx == my_strlen(str)) {
                return this->tab[i];
            } else {
                idx = 0;
            }
        }
    }
    return NULL;
}