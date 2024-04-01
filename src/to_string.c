#include "../includes/array.h"

static char *to_string(const array_t *this, const char c);

static char *to_string(const array_t *this, const char c)
{
    if (this->tab != NULL && this->size(this) > 0) {
        return word_array_to_string(this->tab, c);
    }
    return NULL;
}