#include "include.h"

static size_t *find_all(const array_t *this, const char *str, size_t *count);

static size_t *find_all(const array_t *this, const char *str, size_t *count)
{
    if (!this || !this->tab || !str) {
        if (count) *count = 0;
        return NULL;
    }

    size_t size = this->size(this);
    size_t *positions = malloc(size * sizeof(size_t));
    if (!positions) {
        if (count) *count = 0;
        return NULL;
    }

    size_t pos_count = 0;
    for (size_t i = 0; i < size; ++i) {
        if (strcmp(this->tab[i], str) == 0) {
            positions[pos_count++] = i;
        }
    }

    if (count) *count = pos_count;
    return positions;
}
