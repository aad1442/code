#include<stdio.h>
#include<stdlib.h>

struct node{
    char value;
    int frequency;
    struct node* left;
    struct node* right;
};

int main(){
    struct node* a[4];
    a[4]=(struct node*)(malloc(sizeof(struct node)));
    for(int i=0;i<4;i++){
        scanf(" %c",&a[i].value);
        scanf("%d",&a[i]->frequency);
        a[i]->left= NULL;
        a[i]->right = NULL;

    }
    
    for(int i=0;i<4;i++){
        printf("%c\n",a[i]->value);
        printf("%d\n",a[i]->frequency);
        

    }

    
}