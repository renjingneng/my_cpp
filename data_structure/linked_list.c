#include <stdio.h>
// 单向链表

typedef struct Node
{
    int index;
    char *content;
    struct Node *next;
} Node;
typedef struct LinkedList
{
    int len;
    Node *head;
} LinkedList;
LinkedList *newLinkedList()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->len = 0;
    return list;
}
void append(LinkedList *list, int index, char *content)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->content = (char *)malloc(100 * sizeof(char));
    strcpy(new_node->content, content);
    new_node->index = index;
    new_node->next = NULL;
    if (list->head == NULL)
    {
        list->head = new_node;
    }
    else
    {
        Node *temp = list->head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    list->len++;
}
void show(LinkedList *list)
{
    printf("show start\n");
    Node *temp = list->head;
    while (temp)
    {
        printf("node:index-%d,content-%s\n", temp->index, temp->content);
        temp = temp->next;
    }
    printf("show end\n");
}

void delByIndex(LinkedList *list, int index)
{
    // 第一个特殊处理
    while (list->head && list->head->index == index)
    {
        Node *temp;
        temp = list->head;
        list->head = list->head->next;
        free(temp->content);
        free(temp);
    }

    // 剩下的常规处理
    Node *iterator = list->head;
    while (iterator)
    {
        while (iterator->next && iterator->next->index == index)
        {
            Node *temp = iterator->next;
            iterator->next = iterator->next->next;
        }
        iterator = iterator->next;
    }
}
void insert(LinkedList *list, int index, char *content, int pos)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->content = (char *)malloc(100 * sizeof(char));
    strcpy(new_node->content, content);
    new_node->index = index;
    new_node->next = NULL;

    if(pos == 1){
    new_node->next = list->head;
    list->head = new_node;
    return;
    }

    int i = 1;
    Node *node = list->head;
    while ((i + 1) != pos)
    {
        i++;
        node = node->next;
    }

    
    new_node->next = node->next;
    node->next = new_node;
}

int main()
{
    LinkedList *list = newLinkedList();
    append(list, 1, "c++1");
    append(list, 1, "c++2");
    append(list, 2, "java1");
    append(list, 1, "c++3");
    append(list, 3, "php1");
    show(list);
    delByIndex(list, 1);
    show(list);
    insert(list, 1, "c++1", 1);
    insert(list, 1, "c++2", 3);
    show(list);
}