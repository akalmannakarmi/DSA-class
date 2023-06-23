#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    struct node *next;
    int data;
};

struct node *head;

void insertion_begining();
void insertion_last();
void deletion_begining();
void deletion_last();
void display();

int main(){
    int choice=0;
    printf("\n What do you want to perform.....\n");
    printf("\n ================================================\n");
    printf("\n 1.Insert at the begining\n 2.Insert at the last\n 3.Delete from begining\n 4.Delete from last\n 5.Show\n 6.Exit\n");
    while(choice!=6){
        printf("\n Enter your choice?\n");
        scanf("\n %d",&choice);
        switch(choice){
        case 1:
            insertion_begining();
            break;
        case 2:
            insertion_last();
            break;
        case 3:
            deletion_begining();
            break;
        case 4:
            deletion_last();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
            break;
        default:
        printf("Please Enter valid choice...");
        }
    }
    return 0;
}

void insertion_begining(){
    struct node *ptr;
    int item;
    ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("\n Cant insert data");
    }else{
        printf("\n Enter the data to be inserted ");
        scanf("%d",&item);

        if(head== NULL){
            ptr->next = NULL;
            ptr->prev=NULL;
            ptr->data=item;
            head=ptr;
        }else{
            ptr->data=item;
            ptr->prev=NULL;
            ptr->next=head;
            head->prev=ptr;
            head=ptr;
        }
        printf("\n node inserted\n");
    }
}

void insertion_last(){
    struct node *ptr, *temp;
    int item;
    ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("\n Cant insert data");
    }else{
        printf("\n Enter the data to be inserted");
        scanf("%d",&item);
        ptr->data=item;
        if(head==NULL){
            ptr->next= NULL;
            ptr->prev=NULL;
            head-ptr;
        }else{
            temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=ptr;
            ptr->prev=temp;
            ptr->next=NULL;
        }
    }
    printf("\n node inserted\n");
}

void deletion_begining(){
    struct node *ptr;
    if(head == NULL){
        printf("\n Linked List is empty");
    }else if(head->next == NULL){
        head = NULL;
        free(head);
        printf("\nnode deleted\n");
    }else{
        ptr = head;
        head=head -> next;
        head -> prev = NULL;
        free(ptr);
        printf("\nnode deleted\n");
    }
}
void deletion_last(){
    struct node *ptr;
    if(head == NULL){
        printf("\n Linked List is empty");
    }else if(head->next == NULL){
        head = NULL;
        free(head);
        printf("\nnode deleted\n");
    }else{
        ptr = head;
        if(ptr->next!= NULL){
            ptr=ptr ->next;
        }
        ptr -> prev->next = NULL;
        free(ptr);
        printf("\nnode deleted\n");
    }
}

void display(){
    struct node* last;
    struct node *ptr;
    printf("\n Displaying from head...\n");
    ptr = head;
    while(ptr != NULL){
        printf("%d\n",ptr->data);
        last = ptr;
        ptr=ptr->next;
    }

    printf("\n Displaying from tail... \n");
    while(last!= NULL){
        printf("%d\n",last->data);
        last=last->prev;
    }
}