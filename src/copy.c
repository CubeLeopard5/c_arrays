#include "include.h"

static array_t *copy(const array_t *this);

static array_t *copy(const array_t *this)
{
    if (!this || !this->tab) return NULL;

    struct array_s *new_array = malloc(sizeof(struct array_s));
    if (!new_array) return NULL;

    size_t size = this->size(this);
    new_array->tab = malloc((size + 1) * sizeof(char *));
    if (!new_array->tab) {
        free(new_array);
        return NULL;
    }

    for (size_t i = 0; i < size; ++i) {
        new_array->tab[i] = strdup(this->tab[i]);
    }
    new_array->tab[size] = NULL;

    // Initialize function pointers
    // You need to copy function pointers as well
    new_array->print = this->print;
    new_array->size = this->size;
    new_array->whereis = this->whereis;
    new_array->at = this->at;
    new_array->to_string = this->to_string;
    new_array->push_back = this->push_back;
    new_array->insert_c = this->insert_c;
    new_array->sort = this->sort;
    new_array->delete = this->delete;
    new_array->merge_c = this->merge_c;
    new_array->merge_t = this->merge_t;
    new_array->clear = this->clear;
    new_array->apply = this->apply;
    new_array->apply_on_match = this->apply_on_match;
    new_array->occurrence_f = this->occurrence_f;
    new_array->occurrence = this->occurrence;

    return new_array;
}
