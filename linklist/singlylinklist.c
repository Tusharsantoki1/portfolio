#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *list;

};
void insert_at_front(struct node**head,int x){
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=x;
    newnode->list=*head;
    *head=newnode;
}
void insert_at_end(struct node *head, int x){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=x;
    temp->list=NULL;
    if(head==NULL){
        return ;
    }
    else {
        while (head->list!=NULL)
        {
            head=head->list;
        }
        head->list=temp;
        
    }
}
void delet_at_fornt(struct node **head ){
    *head=(*head)->list;
}

void delet_at_last(struct node *head){
    if(head->list==NULL){
        head=NULL;
    }
    else{
        struct node *temp;
        struct node *temp1;
        temp=head;
        temp1=head;

        while(temp->list!=NULL){
            temp1=temp;
            temp=temp->list;
        }
        temp1->list=NULL;
        free(temp);
    }
}

void bubbleshort(struct node **head){
    int x;
    struct node *i;
    struct node *j;
    for(i=(*head);i->list!=NULL;i=i->list){
        for(j=i->list;j->list!=NULL;j=j->list){
            if(i->data>j->data){
                x=j->data;
                j->data=i->data;
                i->data=x;
            }
        }
    }
}
void reverese(struct node **head){
    struct node *temp=NULL;
    struct node *temp1=NULL;
    while ((*head)!=NULL)
    {
        temp1=(*head)->list;
        (*head)->list=temp;
        temp=(*head);
        (*head)=temp1;
    }
    *head=temp;
}
int main(){
    struct node *head=NULL;
    insert_at_front(&head,10);
    insert_at_front(&head,-56);
    insert_at_front(&head,8);
    insert_at_front(&head,90);
   bubbleshort(&head);
 reverese(&head);


    struct node *ptr=head;
    while(ptr!=NULL){
        printf("%d   ",ptr->data);
        ptr=ptr->list;
    }
    
}