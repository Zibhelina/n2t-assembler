#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

static void linked_list__add_to_end(Node** head, Node** tail, size_t* length, char value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    if(*head == NULL || *tail == NULL) {
        *head = new_node;
        *tail = new_node;
        (*length)++;
        return;
    }
    (*tail)->next = new_node;
    (*tail) = new_node;
    (*length)++;
}

static void linked_list__destroy(Node** head, Node** tail, size_t* length) {
    if(*head == NULL) return;
    while(*head != NULL) {
        Node* temp = (*head)->next;
        free(*head);
        *head = temp;
    }
    *head = NULL;
    *tail = NULL;
    *length = 0;
}

static void linked_list__fill_buffer(Node* head, char* buffer) {
    if(head == NULL) 
        return;
    while(head != NULL) {
        *buffer = head->value;
        head = head->next;
        buffer++;
    }
}

static void linked_list__print(Node* head) {
    if(head == NULL) 
        return;
    while(head != NULL) {
        printf("%c -> ", head->value);
        head = head->next;
    }
}

Linked_List create_linked_list(void) {
    Linked_List linked_list = {
        .head = NULL,
        .tail = NULL,
        .length = 0,
        .add_to_end = linked_list__add_to_end,
        .destroy = linked_list__destroy,
        .fill_buffer = linked_list__fill_buffer,
        .print = linked_list__print
    };
    return linked_list;
}