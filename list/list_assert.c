#include "list.h"
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#define TEST_ITERATIONS 1000;
int expected1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int expected2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

void list_create_test()
{
    list_t *list = list_create(NULL, NULL);
    (list != NULL) ? printf("%s success\n", __func__) : printf("%s false\n", __func__);
    free(list);
}

void list_addfirst_test()
{
    int status = 1;
    cmpfunc_t cmpfunc = NULL;
    srtfunc_t srtfunc = NULL;
    list_t *list = list_create(cmpfunc, srtfunc);
    list_iter_t *iter = list_createiter(list);
    assert(list != NULL);

    for (int i = 0; list_size(list) < 10; i++)
    {
        list_addfirst(list, &i);
        if (status &= (((uintptr_t)list_next(iter)) == (expected1[i])))
            ;
    }

    list_destroy(list);
    list_destroyiter(iter);

    (status == 1) ? printf("%s success\n", __func__) : printf("%s false\n", __func__);
}

void list_addlast_test()
{
    int status = 1;
    cmpfunc_t cmpfunc = NULL;
    srtfunc_t srtfunc = NULL;
    list_t *list = list_create(cmpfunc, srtfunc);
    list_iter_t *iter = list_createiter(list);
    assert(list != NULL);

    for (int i = 0; list_size(list) < 10; i++)
    {
        list_addfirst(list, &i);
        if (status &= (((uintptr_t)list_next(iter)) == (expected2[i])))
            ;
    }

    list_destroy(list);
    list_destroyiter(iter);

    (status == 1) ? printf("%s success\n", __func__) : printf("%s false\n", __func__);
}

int main(int argc, char *argv[])
{
    list_create_test();
    list_addfirst_test();
    list_addlast_test();
}