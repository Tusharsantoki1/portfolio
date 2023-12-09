#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *list;
};

struct node *add_to_empty(int x){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=x;
    temp->list=temp;
    return temp;

}
struct node *insert_at_bag(struct node *tail,int x){
    struct node *newp=malloc(sizeof(struct node));
    newp->data=x;
    newp->list=tail->list;
    tail->list=newp;
    return tail;
}

int main(){
    struct node *tail=NULL;
    tail=add_to_empty(56);
    tail=insert_at_bag(tail,67);

    struct node *ptr=tail->list;
   do{
        printf("%d ",ptr->data);
         ptr=ptr->list;
    } while(ptr!=tail->list);
}