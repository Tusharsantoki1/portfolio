#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct bstnode{
    struct bstnode *left;
    int data;
    struct bstnode *right;
};
struct bstnode *getnewnode(int x){
    struct bstnode *temp=malloc(sizeof(struct bstnode));
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void Insert(struct bstnode **head,int x){
    
    if((*head)==NULL){

        (*head)=getnewnode(x);
    }
    else if (x<=(*head)->data)
    {
        (*head)->left=Insert((*head)->left,x);
    }
    else{
        (*head)->right=Insert((*head)->right,x);
    }
    

}
bool search(struct bstnode *head,int x){
    if(head==NULL){
        return false;
    }
    else if (head->data==x)
    {
        /* code */return true;
    }
    else if (head->data>=x)
    {
        /* code */search(head->left,x);
    }
    else{
        search(head->right,x);
    }
    
    
}



int main(){
    struct bstnode * head=NULL;

}