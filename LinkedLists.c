#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedLists.h"

int i = 0;
struct Node* head = NULL;
void remove_sn(node**head,int sn){
    node*current=(node*)malloc(sizeof(node));
    node*next=(node*)malloc(sizeof(node));
    
    if(*head==NULL){
        printf("No students in the file yet!");
        return;
    }
    current=*head;

    node*temp=(node*)malloc(sizeof(node));
    temp=*head;
    if(temp->data==sn){
            *head=temp->next;
            if(*head==NULL){
                i=0;
            }
            return;
        }
    while(temp->next!=NULL){
        if(temp->next->data==sn){
            temp->next=temp->next->next;
            if(*head==NULL){
                i=0;
            }
            return;
        }
        temp=temp->next;
    }
    
}

//Iterate through the linked list and delete all the nodes one by one.
//The main point here is not to access the next of the current pointer
//if the current pointer is deleted.
void clear_linked_list(node**head){

    node*current=(node*)malloc(sizeof(node));
    node*next=(node*)malloc(sizeof(node));
    if(*head==NULL){
        return;
    }

    current=*head;
    while(current->next!=NULL){
        next=current->next;
        free(current);
        current=next;
    }
}

bool check_sn(node**head,int sn,char op){
    //Si on a pas le "else", temp et temp->next vont pointer au meme node; newnode
    //ceci brise le programme

    //But de cette fonction: verifier si le Student number est deja utiliser
    //(rend le return type � bool si sn==temp->data)

    node*temp=(node*)malloc(9*sizeof(node));

    node*tft=(node*)malloc(sizeof(node));
    if(*head==NULL /*|| i==1*/){
        return false;
    }
    else{
        temp=*head;
        printf("%d is node and sn=%d\n",temp->data,sn);
        if(temp->data==sn){
            return true;
        }
        while(temp->next!=NULL){
            temp=temp->next;
            printf("%d is node in loop but is sn==temp->data: %d\n",temp->data,sn==temp->data);
            if(sn==temp->data){
                return true;
            }
        }
        //verifie dernier node
        // op=='s' est pour etre sur qu'on est en search mode et pas write sinon
        // la fonction va toujours retourner true!
        if(temp->data==sn && op=='s'){
            return true;
        }

    }
    return false;
}

//ajoute les sn au linked list
void add_sn(node**head,int sn){
    node*temp=(node*)malloc(sizeof(node));

    node*newnode=(node*)malloc(sizeof(node));
    newnode->data=sn;
    newnode->next=NULL;

    if(*head==NULL){
        *head=newnode;
    }
    else{
        temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
