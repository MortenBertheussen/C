#include "list.h"

struct listnode;

typedef struct listnode node_t;

struct listnode
{
    node_t *next;
    node_t *prev;
    void *elem;
};

struct list
{
    node_t *head;
    node_t *tail;
    int size;
    cmpfunc_t cmpfunc;
    srtfunc_t srtfunc;
};

struct list_iter
{
    node_t *node;
};

node_t *_new_node(void *elem)
{
    node_t *node;
    if ((node = malloc(sizeof(node_t))) != NULL)
    {
        node = &(node_t){.next = NULL, .prev = NULL, .elem = elem};
    }
    else
    {
        //TODO: ERROR
    }
    return node;
}

list_t *list_create(cmpfunc_t cmpfunc, srtfunc_t srtfunc)
{
    list_t *list;
    if ((list = malloc(sizeof(node_t))) != NULL)
    {
        list = &(list_t){.head = NULL, .tail = NULL, .size = NULL, .cmpfunc = cmpfunc, .srtfunc = srtfunc};
    }
    else
    {
        //TODO: ERROR
    }
    return list;
}

void list_destroy(list_t *list)
{
    node_t *tmp, *node = list->head;
    while (node != NULL)
    {
        tmp = node;
        node = node->next;
        free(tmp);
    }
    free(list);
}

int_fast8_t list_size(list_t *list)
{
    return list->size;
}

void list_addfirst(list_t *list, void *elem)
{
    node_t *node = _newnode(elem);
    if (list->head == NULL)
    {
        list->head = list->tail = node;
    }
    else
    {
        list->head->prev = node;
        node->next = list->head;
        list->head = node;
    }
    list->size++;
}

void list_addlast(list_t *list, void *elem)
{
    node_t *node = _newnode(elem);
    if (list->head == NULL)
    {
        list->head = list->tail = node;
    }
    else
    {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
    }
    list->size++;
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
