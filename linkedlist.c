#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head;

void begin_insert();
void insert_at_the_end();
void position_insert();
void begin_delete();
void delete_at_the_end();
void position_delete();
void display();

int main(){
    int choice=0;
    printf("\n What do you want to perform? \n");
    printf("\n==============================\n");
    printf("\n1.Insert at the beginning\n2.Insert at the end\n3.Insert at any specified location\n4.Delete from the Beginning\n5.Delete from the end\n6.Delete node at the specified location\n7.Show\n8 Exit\n");
    while(choice!= 8){
        printf("\nEnter your choice?\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                begin_insert();
                break;
            case 2:
                insert_at_the_end(0);
                break;
            case 3:
                position_insert();
                break;
            case 4:
                begin_delete();
                break;
            case 5:
                delete_at_the_end();
                break;
            case 6:
                position_delete();
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
                break;
            default:
                printf("Please enter valid choice..\n");
        }
    }
    return 0;
}

void begin_insert(){
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node *));
    if(ptr == NULL){
        printf("\nOVERFLOW");
    }
    else{
        printf("\nEnter value\n");
        scanf("%d",&item);
        ptr->data = item;
        ptr->next = head;
        head= ptr;
        printf("\nNode inserted");
    }
}

void insert_at_the_end(){
    struct node *ptr,*temp;
    int item;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL){
        printf("\nLinked List Overflow");
    }else{
        printf("\nEnter value\n");
        scanf("%d",&item);
        ptr->data = item;
        if(head == NULL){
            ptr->next = NULL;
            head= ptr;
            printf("\nNode inserted");
        }
        else{
            temp = head;
            while (temp->next!= NULL){
                temp=temp->next;
            }
            temp->next=ptr;
            ptr->next=NULL;
            printf("\nNode inserted");
        }
    }
}

void position_insert(){
    int i,loc,item;
    struct node *ptr,*temp;

    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL){
        printf("\nLinked List OVERFLOW");
    }else{
        printf("\nEnter element value");
        scanf("%d",&item);
        ptr->data = item;
        printf("\nEnter the location after which you want to insert ");
        scanf("%d",&loc);
        temp=head;
        for(i=1;i<loc-1;i++){
            temp = temp->next;
            if(temp == NULL){
                printf("\nCan't insert the value\n");
                return;
            }
        }
        ptr->next = temp->next;
        temp->next = ptr;
        printf("\nNode is inserted");
    }
}

void begin_delete(){
    struct node *ptr;
    if(head ==NULL){
        printf("\nLinked List is empty\n");
    }else{
        ptr= head;
        head = ptr->next;
        free(ptr);
        printf("\nNode deleted from the begining...\n");
    }
}

void delete_at_the_end(){
    struct node *ptr, *ptr1;
    if(head == NULL){
        printf("\nlist is empty");
    }else if(head->next == NULL){
        head = NULL;
        free(head);
        printf("\nOnly node of the list deleted.\n");
    }else{
        ptr = head;
        while(ptr->next!= NULL){
            ptr1 = ptr;
            ptr = ptr ->next;
        }
        ptr1->next = NULL;
        free(ptr);
        printf("\nDeleted Node from the last...\n");
    }
}

void position_delete(){
    struct node *ptr,*ptr1;
    int loc,i;
    printf("\n Enter the location of the node after which you want to perform deletion \n");
    scanf("%d",&loc);
    ptr=head;
    for(i=1;i<loc;i++){
        ptr1 = ptr;
        ptr = ptr->next;
        if(ptr == NULL){
            printf("\nCan't delete");
            return;
        }
    }
    ptr1->next = ptr ->next;
    free(ptr);
    printf("\nDeleted node %d ",loc);
}

void display(){
    struct node *ptr;
    ptr = head;
    if(ptr== NULL){
        printf("\nLinked List is empty\n");
    }else{
        printf("\nprinting values.....\n");
        while (ptr!=NULL){
            printf("\n%d",ptr->data);
            ptr = ptr ->next;
        }
    }
}