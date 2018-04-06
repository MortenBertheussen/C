#include "list.h"

list_t *list_create(cmpfunc_t cmpfunc, srtfunc_t srtfunc)
{
    return NULL;
}

void list_destroy(list_t *list)
{

}

int_fast8_t list_size(list_t *list)
{
    return 0;
}

void list_addfirst(list_t *list, void *elem)
{

}

void list_addlast(list_t *list, void *elem)
{

}

void *list_popfirst(list_t *list)
{
    return NULL;
}

void *list_poplast(list_t *list)
{
    return NULL;
}

int_fast8_t list_contains(list_t *list, void *elem)
{
    return 0;
}

void list_sort(list_t *list)
{

}

struct list_iter;
typedef struct list_iter list_iter_t;

list_iter_t *list_createiter(list_t *list)
{
    return NULL;
}

void list_destroyiter(list_iter_t *iter)
{

}

int_fast8_t list_hasnext(list_iter_t *iter)
{
    return 0;
}

void *list_next(list_iter_t *iter)
{
    return NULL;
}
