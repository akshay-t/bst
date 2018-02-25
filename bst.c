#include <stdio.h>
#include <stdlib.h>

#include <string.h>

typedef struct bst {
    int data;
    struct bst *left,*right;
}bst;

bst * insert(bst *node,int d){
    if(!node){
        node=malloc(sizeof(bst));
        node->left=NULL;
        node->right=NULL;
        node->data=d;
        
        return node;
    }
    else if(node->data > d)
            node->left=insert(node->left,d);
        else
            node->right=insert(node->right,d);
}

void ino(bst *node){
    if(node){
        ino(node->left);
        printf(" %d ",node->data);
        ino(node->right);
    }
}

bst * min(bst *node){
    if(node->left){
        node=min(node->left);
    }  
    return node;
}

bst * del(bst*node,int d){
    if(node->data>d)
        node->left=del(node->left,d);
    else if(node->data<d)
            node->right=del(node->right,d);
    if(node->data==d){
        if(node->left==NULL){
            bst *t=node->right;
            free(node);
            return t;
        }
        if(node->right==NULL){
            bst *t=node->left;
            free(node);
            return t;
        }
        
        bst *t = min(node->right);
        node->data=t->data;
        node->right=del(node->right,t->data);
        
    }
    return node;
}

int main()
{   bst *root;
    //root=malloc(sizeof(bst));
    
    root=insert(root,10);
    root=insert(root,5);
    root=insert(root,15);
    root=insert(root,3);
    root=insert(root,6);
    root=insert(root,2);
    root=insert(root,12);
    root=insert(root,11);
    root=insert(root,13);
    
    ino(root);
    
    printf(" \n");
    root = del(root,5);
    
    
    ino(root);
    return 0;
}
