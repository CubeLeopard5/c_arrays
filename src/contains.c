#include "include.h"

static int contains(const array_t *this, const char *str);

static int contains(const array_t *this, const char *str)
{
    if (!this || !this->tab || !str)
        return 0;
    return this->whereis(this, str) != -1;
}
