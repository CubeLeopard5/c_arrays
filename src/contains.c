#include "include.h"

static int contains(const array_t *this, const char *str);

static int contains(const array_t *this, const char *str)
{
    return this->whereis(this, str) != -1;
}
