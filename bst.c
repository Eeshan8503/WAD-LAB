#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct tree{
    struct tree *left;
    struct tree *right;
    int info;
};
struct tree * create(struct tree *root){
    int item;
    int c;
    struct tree *newnode,*temp,*follow;
    printf("Enter data \n");
    scanf("%d",&item);
    while(item!=-1){
        newnode=(struct tree*)malloc(sizeof(struct tree));
        newnode->info=item;
        newnode->left=NULL;
        newnode->right=NULL;
        if(root==NULL){
            root=newnode;
            temp=root;
        }
        else{
            while(temp!=NULL){
                follow=temp;
                if(temp->info>item){
                    temp=temp->left;
                    c=0;
                }
                else{
                    temp=temp->right;
                    c=1;
                }
            }
            if(c==1){
                follow->right=newnode;
            }
            else{
                follow->left=newnode;
            }
        }
        temp=root;
        scanf("%d",&item);
    }
    return root;
}
void preorder(struct tree *root){
    if(root==NULL)
    return;
    printf("%d \n",root->info);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct tree *root){
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    printf("%d \n",root->info);
}
void inorder(struct tree *root){
    if(root==NULL)
    return;
    inorder(root->left);
    printf("%d \n",root->info);
    inorder(root->right);
}
int countleaves(struct tree *root){
    if(root==NULL)
    return 0;
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    return countleaves(root->left)+countleaves(root->right);
}
void find_max(struct tree *root){
    struct tree *temp, *max;
    temp=root;
    while(temp!=NULL){
        max=temp;
        temp=temp->right;
    }
    printf("MAX = %d ",max->info);
}
void find_min(struct tree *root){
    struct tree *temp , *min;
    temp=root;
    while(temp!=NULL){
        min=temp;
        temp=temp->left;
    }
    printf("MIN = %d ",min->info);
}
int main()
{
    
    struct tree *root;int count=0;
    root=NULL;
    root=create(root);
    printf("-------------PREORDER----------- \n");
    preorder(root);
    printf("-------------POSTORDER----------- \n");
    postorder(root);
    printf("-------------INORDER----------- \n");
    inorder(root);
    printf("-------------LEAVES----------- \n");
     count=countleaves(root);
    printf("NO of leaves = %d ",count); 
    find_min(root);
    printf("\n");
    find_max(root);
}
