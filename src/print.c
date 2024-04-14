#include "include.h"

static void print(const array_t *this);

static void print(const array_t *this)
{
    if (this->tab != NULL) {
        for (int i = 0; this->tab[i] != NULL; i++) {
            for (int j = 0; this->tab[i][j] != '\0'; j++) {
                write(1, &this->tab[i][j], 1);
            }
            if (this->tab[i + 1] != NULL) {
                write(1, "\n", 1);
            }
        }
    }
}