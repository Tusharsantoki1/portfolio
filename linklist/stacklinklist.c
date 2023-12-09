#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *list;
};
void push(struct node **head,int x){
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=x;
    newnode->list=*head;
    *head=newnode;
}
int pop(struct node **head ){
    int r;
    if((*head)->list==NULL){
       r=(*head)->data;
        *head=NULL;
        return r;
    }
    else if (*head==NULL)
    {
        printf("stack is empty");
    }
    else{
        r=(*head)->data;
        *head= (*head)->list;
    }
    return r;

}

int main(){
    struct node *head=NULL;
    int p;


    int choise;
    do{
        printf("1.PUSH\n2.POP\n4.EXIT\nplease enter the choise:");
        scanf("%d",&choise);
        switch (choise)
        {
        case 1:
          
            printf("Enter the push element:");
            scanf("%d",&p);
            push(&head,p);
            break;
        case 2:
           printf("POP ELEMENT IS=%d\n",pop(&head));
           break;
        case 4:
            printf("EXITED\n");
            break;
        default:
        printf("INVALID CASE\n");
            break;
        }

    }while(choise!=4);



    struct node *ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->list;
    }
}