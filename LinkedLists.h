#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

extern int i;
extern struct Node* head;

typedef struct Node{
    int data;
    struct Node *next;
}node;

//check if student number is in the linked list (for searching and removing)
bool check_sn(node**,int,char);

//add student numbers to linked list as node
void add_sn(node**,int);

//free the student numbers linked list nodes 1 by 1
void clear_linked_list(node**);

//remove student number node from linked list
void remove_sn(node**,int);

#endif
