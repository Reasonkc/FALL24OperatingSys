#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main() {
    printf("Write your Tests for your linked list implementation\n");
    list_t *test_list;
    test_list = list_alloc();
    list_print(test_list);
    list_add_to_front(test_list, 10);
    list_add_to_front(test_list, 20);
    list_add_to_front(test_list, 30);
    list_print(test_list);
    list_add_to_front(test_list, 40);
    list_add_to_front(test_list, 50);
    list_add_to_front(test_list, 60);
    list_add_to_front(test_list, 70);
    list_add_to_front(test_list, 80);
    list_add_to_front(test_list, 90);
    list_add_to_front(test_list, 100);

    if (strcmp("100->90->80->70->60->50->40->30->20->10->NULL", listToString(test_list)) != 0) {
        printf("list_add_to_front : FAILED\n");
    }

    list_print(test_list);
    list_remove_at_index(test_list, 3);
    list_print(test_list);

    if (strcmp("100->90->70->60->50->40->30->20->10->NULL", listToString(test_list)) != 0) {
        printf("list_remove_at_index : FAILED\n");
    }

    list_remove_at_index(test_list, 20);
    list_print(test_list);
    list_remove_at_index(test_list, 1);
    list_print(test_list);
    list_remove_at_index(test_list, 6);
    list_print(test_list);

    if (strcmp("90->70->60->50->40->20->10->NULL", listToString(test_list)) != 0) {
        printf("list_remove_at_index : FAILED\n");
    }

    printf("Value at %d in the list?: %d\n", 3, list_get_elem_at(test_list, 3));
    printf("Value at %d in the list?: %d\n", 5, list_get_elem_at(test_list, 5));
    printf("Value at %d in the list?: %d\n", 0, list_get_elem_at(test_list, 0));
    printf("Value at %d in the list?: %d\n", -2, list_get_elem_at(test_list, -2));
    printf("Value at %d in the list?: %d\n", 12, list_get_elem_at(test_list, 12));
    printf("Value at %d in the list?: %d\n", 7, list_get_elem_at(test_list, 7));
    printf("Index of %d?: %d\n", 70, list_get_index_of(test_list, 70));
    printf("Index of %d?: %d\n", 20, list_get_index_of(test_list, 20));
    printf("Index of %d?: %d\n", 0, list_get_index_of(test_list, 0));
    printf("Index of %d?: %d\n", 10, list_get_index_of(test_list, 10));
    printf("Index of %d?: %d\n", 90, list_get_index_of(test_list, 90));

    return 0;
}
