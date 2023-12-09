#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *list;
};

void reverse(struct node **head);

void push(struct node **head,int x){
    struct node*temp=malloc(sizeof(struct node));
    temp->data=x;
    temp->list=NULL;
    if((*head)==NULL){
        (*head)=temp;
    }
    else{
        struct node *ptr=*head;
        while(ptr->list!=NULL){
            ptr=ptr->list;
        }
        ptr->list=temp;
    }
}

void criatll(struct node **head,int x){
    while(x!=0){
        push(head,x%10);
        x/=10;
    }
}
void add(struct node**head1,struct node **head2,struct node **head3){
    struct node *ptr1=*head1;
    struct node *ptr2=*head2;
    int carry=0,sum=0;

    while(ptr1||ptr2){
        sum=0;
        if(ptr1){
            sum+=ptr1->data;
        }
        if(ptr2){
            sum+=ptr2->data;
        }
        sum+=carry;
        carry=sum/10;
        sum=sum%10;
        push(head3,sum%10);
          if(ptr1){
           ptr1=ptr1->list;

        }
        if(ptr2){
            ptr2=ptr2->list;
        }

    }
    if(carry){
        push(head3,carry);}
        reverse(head3);
}



int main(){
    struct node *head1=NULL;
    struct node *head2=NULL;
    struct node *head3=NULL;
    int a,b;
    printf("Enter the 1)number:");
    scanf("%d",&a);
    printf("Enter the 2)number:");
    scanf("%d",&b);
    criatll(&head1,a);
    criatll(&head2,b);
    add(&head1,&head2,&head3);


    

   
      struct node *ptr=head3;
    while(ptr){
        printf("%d   ",ptr->data);
        ptr=ptr->list;
    }
   

}

void reverse(struct node **head){
    struct node *temp=NULL;
    struct node *temp1=NULL;
    while(*head){
        temp1=(*head)->list;
        (*head)->list=temp;
        temp=(*head);
        (*head)=temp1;
    }
    (*head)=temp;
}