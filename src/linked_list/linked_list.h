#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
    char value;
    struct Node* next;
} Node;

typedef struct Linked_List {
    Node* head;
    Node* tail;
    size_t length;
    void (*add_to_end)(Node** head, Node** tail, size_t* length, char value);
    void (*fill_buffer)(Node* head, char* buffer);
    void (*destroy)(Node** head, Node** tail, size_t* length);
    void (*print)(Node* head);
} Linked_List;

Linked_List create_linked_list(void);

#endif 