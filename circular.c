#include <stdio.h>
#include <conio.h>

int cqueue[20],choice,maxsize,rear,front,item,i;
void enqueue();
void dequeue();
void display();

int main(){
    front =-1;
    rear =-1;
    printf("\n Enter the size of CQUEUE[MAX=20]:");
    scanf("%d",&maxsize);
    printf("\n\t Circular QUEUE OPERATIONS USING ARRAY");
    printf("\n\t------------------------");
    printf("\n\t 1.ENQUEUE\n\t 2.DEQUEUE\n\t 3.DISPLAY\n\t 4.EXIT");
    do{
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\n\t EXIT POINT");
                break;
            
            default:
                printf("\n\t Please Enter a Valid Choice(1/2/3/4)");
        }
    }while (choice!=4);
    return 0;
}

void enqueue(){
    if(front == (rear+1)%maxsize){
        printf("Circular Queue overflow or Circular queue is full \n");
    }else{
        printf("Enter the data item to be inserted\n");
        scanf("%d",&item);
        if(front==-1){
            front = rear = 0;
        }else{
            rear = ((rear+1)%maxsize);
        }
        cqueue[rear]=item;
    }
}

void dequeue(){
    if(front == -1){
        printf("Circular Queue underflow or Circular queue is empty \n");
    }else{
        item = cqueue[front];
        printf("Deleted element is %d \n",item);
        if(front==rear){
            front = rear=-1;
        }else{
            front=((front+1)%maxsize);
        }
    }
}

void display(){
    int front_pos = front, rear_pos = rear;
    if(front==-1){
        printf("Queue is empty \n");
        return;
    }
    printf("Queue elements are: \n");
    if(front_pos<=rear_pos){
        while (front_pos<= rear_pos){
            printf("%d\n",cqueue[front_pos]);
            front_pos++;
        }
    }else{
        while (front_pos<=maxsize-1){
            printf("%d\n",cqueue[front_pos]);
            front_pos++;
        }
        front_pos=0;
        while (front_pos<=rear_pos){
            printf("%d\n",cqueue[front_pos]);
            front_pos++;
        }
    }
    printf("\n");
}