#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define MAX 100


#include "my_list.h"
#include "my_readline.c"
#include "my_str_to_int.c"
#include "my_putchar.c"
#include "my_putnbr.c"
#include "my_str_to_array.c"


// This function prints contents of linked list starting from head
void printList(linked_list_t *node)
{
    if (node == NULL)
    {
        printf("List EMPTY\n");
    }
    while (node != NULL)
    {
        printf(" %d &", node->key);
        printf(" %d,", node->data);
        node = node->next;
    }
}

linked_list_t *my_read(linked_list_t *list, char **query)
{
    int createdNodeKey = my_str_to_int(query[0]);
    linked_list_t *last = list;
    linked_list_t *prev;

    if (list == NULL)
    {
        // printf("list is NULL, so key is not found : -1 \n");
        // printf("my_crd over n' out \n======================\n");
        my_putchar('-');
        my_putchar('1');
        my_putchar('\n');

        return list;
    }
    while (last != NULL)
    {
        if (last->key == createdNodeKey)
        {
            // printf("For key : %d\n", last->key);
            // printf("Data is : %d\n", last->data);
            my_putnbr(last->data);
            my_putchar('\n');

            return list;
        }
        last = last->next;
    }
    my_putchar('-');
    my_putchar('1');
    my_putchar('\n');

    return list;
}

linked_list_t *delete (linked_list_t *list, char **query)
{

    char *queryKey = query[0];
    int createdNodeKey = my_str_to_int(queryKey);

    linked_list_t *last = list;
    linked_list_t *prev = NULL;
    while (last != NULL)
    {
        if (last->key == createdNodeKey)
        {
            // printf("Key To Delete Found. Need to update data.\n");
            if (prev != NULL)
            {
                prev->next = last->next;
            }
            prev = last;
            last = last->next;

            my_putnbr(prev->data);
            
            my_putchar('\n');

            free(prev);

            return list; // There is a problem if you want to delete head of list..
        }
        prev = last;
        last = last->next;
    }
    // If we get there we didn't find the asked key;
    my_putchar('-');
    my_putchar('1');
    my_putchar('\n');

    return list;
}

linked_list_t *create(linked_list_t *list, char **query)
{
    char *queryKey = query[0];
    char *queryData = query[1];
    int createdNodeKey = my_str_to_int(queryKey);
    int createdNodeData = my_str_to_int(queryData);
    if (list == NULL)
    {
        linked_list_t *ins_node;
        ins_node = malloc(sizeof(linked_list_t));
        ins_node->next = NULL;
        ins_node->data = createdNodeData;
        ins_node->key = createdNodeKey;
        list = ins_node;
        my_putnbr(createdNodeKey);
        my_putchar('\n');
        return list;
    }
    else // If list already initiated
    {
        linked_list_t *last = list;
        linked_list_t *prev;
        int create_new_node = 1;
        while (last != NULL)
        {

            if (last->key == createdNodeKey)
            {
                create_new_node = 0;
                last->data = createdNodeData;
                return list;
            }
            prev = last;
            last = last->next;
        }
        if (create_new_node == 1)
        {
            linked_list_t *ins_node;
            ins_node = malloc(sizeof(linked_list_t));
            ins_node->next = list;
            ins_node->data = createdNodeData;
            ins_node->key = createdNodeKey;
            list = ins_node;
            my_putnbr(createdNodeKey);
            my_putchar('\n');
            return list;
        }
    }

    return list;
}
linked_list_t *my_crd(char **query, linked_list_t *list)
{

    char *queryKey = query[0]; // This assumes key is passed as first arg
    char *queryReq = query[1]; // This assumes req is passed as second arg
    // printf("\nKeyStr is : %s\n", queryKey);
    // printf("\nDataStr is : '%s'\n\n", queryReq);

    if (queryReq == NULL || queryReq[0] == 0 || queryReq == 0) // Query is read
    {
        my_read(list, query);
    }
    else
    {
        if (48 <= queryReq[0] && queryReq[0] <= 59) //FirstCHAR is 0 to 9 ASCII
        {
            list = create(list, query);
            return list;
        }
        if (queryReq[0] == 68) //FirstCHAR is D in ASCII
        {
            list = delete(list, query);
            return list;
        }
    }
}

int main()
{

    const char *action;
    linked_list_t *list;
    list = NULL;

    action = my_readline();
    char **query = my_str_to_word_array(action);
    list = my_crd(query, list);

    while (action != NULL)
    {
        action = my_readline();
        if (action == NULL)
        {
            return 0;
        }
        query = my_str_to_word_array(action);
        list = my_crd(query, list);
    }
    return 0;
}