#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define nil -1

struct tnode{
  struct tnode *left;
  char name[12];
  struct tnode *right;
};

struct tnode *talloc(void){
  return (struct tnode *)malloc(sizeof(struct tnode));
}

void printArray(struct tnode *p){
  if(p!=NULL)printf("%s\n",p->name);

  if(p->left!=NULL){
    printArray(p->left);
  }

  if(p->right!=NULL){
    printArray(p->right);
  }
}

int main(){

  char key[128];
  int f;
  struct tnode *root,*p,*old;

  root = talloc();

  printf("root name --> ");
  scanf("%s",root->name);
  root->left = root->right = NULL;


  while(1){

    printf("append name --> ");
    scanf("%s",key);

    if(strcmp(key,"exit")==0)break;

    p = root;

    while(p!=NULL){
      old = p;
      f = strcmp(key,p->name);
      if(f<0){
        p = p->left;
      }else{
        p = p->right;
      }
    }

    p = talloc();

    strcpy(p->name,key);

    p->left = p->right = NULL;
    strcpy(p->name,key);

    if(strcmp(key,old->name)<0){
      old->left = p;
    }else{
      old->right = p;
    }

  }

  p = root;

  printArray(p);

  return 0;
}