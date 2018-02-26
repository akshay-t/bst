#include <stdio.h>
#include <stdlib.h>

#include <string.h>

typedef struct bst {
    int data;
    struct bst *left,*right;
}bst;

typedef struct que{
    bst *node;
    struct que *next;
    
}que;
struct que *front=NULL,*rear=NULL;


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

void pre(bst *node){
    if(node){
        printf(" %d ",node->data);
        pre(node->left);
        pre(node->right);
    }
}
void post(bst *node){
    if(node){
        post(node->left);
        post(node->right);
        printf(" %d ",node->data);
    }
}

void enque(bst *node){
    
    
    if(rear){
        que *temp=malloc(sizeof(que));
        temp->node=node;
        temp->next=NULL;
        rear->next=temp;
        rear=temp;
    }
    else{
        front=malloc(sizeof(que));
        rear=front;
        front->node=node;
        front->next=NULL;
   
    }
    
}

bst * deque(){
    bst *node=front->node;
    front=front->next;
   
    return node;
}
void bfs(bst *node){
    
    //printf(" %d ",node->data);
    while(node){
        printf(" %d ",node->data);
        if(node->left)
            enque(node->left);
        if(node->right)
            enque(node->right);
        

        //break;
       if(front)
            node=deque();
        else    
            break;
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
    
   // root = del(root,5);
    
    ino(root);
    printf(" \n  Preorder \n");
    pre(root);
    printf(" \n  Postorder \n");
    post(root);
    
    printf(" \n  bfs \n");
    bfs(root);
   

    return 0;
}
