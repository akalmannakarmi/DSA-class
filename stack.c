#include <stdio.h>
#include <conio.h>
int stack[20],choice,n,top,x,i;
void push();
void pop();
void display();
int main(){
    top=-1;
    printf("\nEnter the size of STACK[MAX 20]:");
    scanf("%d",&n);
    printf("\n\tSTACK OPERATIONS USING ARRAY");
    printf("\n\t-----------------------------");
    printf("\n\t1.PUSH\n\t2.POP\n\t3.DISPLAY\n\t4.EXIT");
    do{
        printf("\nEnter the Choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\n\tEXIT POINT");
            break;
        default:
            printf("\n\tPlease Enter a valid choice(1/2/3/4)");
        }
    }while (choice!=4);
    return 0;
}

void push(){
    if(top>=n-1){
        printf("\n\tSTACK Overflow or Stack is Full\n");
    }else{
        printf("Enter a value to be pushed or inserted:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void pop(){
    if(top<=-1){
        printf("\n\tSTACK Underflow or Stack is Empty\n");
    }else{
        printf("\n\tThe poped element is %d",stack[top]);
        top--;
    }
}
void display(){
    if(top>=0){
        printf("\nThe elements in stack:\n");
        for(i=top;i>=0;i--){
            printf("\n%d",stack[i]);
        }
        printf("\nElement at top of the stack is %d\n",stack[top]);
    }else{
        printf("\nThe STACK is empty\n");
    }
}