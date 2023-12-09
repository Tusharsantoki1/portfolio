#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *las;
};

void insret_at_beg(struct node **head,int x){
    struct node *temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=x;
    temp->las=NULL;
    if(*head==NULL)
    {
     (*head)=temp;
    }
    else
    temp->las=(*head);
    (*head)->prev=temp;
    (*head)=temp;

}

void insert_at_last(struct node **head,int x){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=x;
    temp->las=NULL;
    temp->prev=NULL;
    if(*head==NULL){
        *head=temp;
    }
    else{
        struct node *free=*head;
        while (free->las!=NULL)
        {
            free=free->las;/* code */
        }
        temp->prev=free;
        free->las=temp;

    }
}
void delet_last_node(struct node *head){
    struct node *temp=head;
    struct node *temp1=head;
    while(temp->las!=NULL){
        temp1=temp;
        temp=temp->las;
    }
    temp1->las=NULL;
}
void deletatfront(struct node **head){
    (*head)=(*head)->las;
    (*head)->prev=NULL;
}
void inserst_node_a_sertion_potion(struct node **head,int x,int postion){
    struct node *temp=malloc(sizeof(struct node));
    temp->las=NULL;
    temp->data=x;
    temp->prev=NULL;
    struct node *temp1=*head;
    struct node *temp2=NULL;
    while(postion!=1){
        temp1=temp1->las;
        postion--;
    }
    if(temp1->las==NULL){
        temp->prev=temp1;

        temp1->las=temp;

    }
    else{
    temp2=temp1->las;
    temp->prev=temp1;
    temp->las=temp2;
    temp1->las=temp;
    temp2->prev=temp;
    }
    
}

void inserst_node_a_before_sertion_potion(struct node **head,int x,int postion){
    struct node *temp=malloc(sizeof(struct node));
    temp->las=NULL;
    temp->data=x;
    temp->prev=NULL;
    struct node *temp1=*head;
    struct node *temp2=NULL;
    while(postion>2){
        temp1=temp1->las;
        postion--;
    }
    if(postion==1){
        insret_at_beg(head,x);

    }
    else{
    temp2=temp1->las;
    temp->prev=temp1;
    temp->las=temp2;
    temp1->las=temp;
    temp2->prev=temp;
    }
    
}
void reverse(struct node **head){
    struct node *ptr1=*head;
    struct node *ptr2=(*head)->las;
    ptr1->las=NULL;
    ptr1->prev=ptr2;
    while(ptr2!=NULL){
        ptr2->prev=ptr2->las;
        ptr2->las=ptr1;
        ptr1=ptr2;
        ptr2=ptr2->prev;
    }
    *head=ptr1;
}



int main(){
    struct node *head=NULL;


    insret_at_beg(&head,90);
    insret_at_beg(&head,78);
    insret_at_beg(&head,56); 
    inserst_node_a_before_sertion_potion(&head,72368,3);
    inserst_node_a_sertion_potion(&head,676,3);
    reverse(&head);
    
   


    
    struct node *ptr=head;

    while(ptr!=NULL){
        printf("%d   ",ptr->data);
        ptr=ptr->las;
    }
}