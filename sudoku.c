#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){  
  for(int i = 0 ; i < 9 ; i++)
  {
    int vfilas[10]={0};
    int vcolumnas[10] ={0} ;
    int vmatriz[10]={0};
     for(int j = 0 ; j < 9 ; j++){
     
      if (vfilas[n->sudo[i][j]] == 1 && n->sudo[i][j] != 0)
      {
          
         return 0;
      }
      else{
      vfilas[n->sudo[i][j]] = 1;
      }
      
      if(vcolumnas[n->sudo[j][i]] == 1 && n->sudo[j][i]!=0)
      {
        return 0;
      }
      else{
        vcolumnas[n->sudo[j][i]]=1;
      }
      int f=3*(i/3) + (j/3) ;
      int c=3*(i%3) + (j%3) ;
      if(vmatriz[n->sudo[f][c]] == 1 && n->sudo[i][j] != 0)
      {
        return 0;
      }
      else
      {
        vmatriz[n->sudo[i][j]] = 1;
      }
     } 
  }


 return 1;

}


List* get_adj_nodes(Node* n){
  List* list=createList();

  for(int i = 0 ; i < 9 ; i++){
  
    for(int j = 0 ; j < 9 ; j++){
    
      if(n->sudo[i][j]== 0){
        for(int k = 1 ; k <= 9 ; k++){
        
          Node *copyN = copy(n);
          copyN->sudo[i][j] = k;
          
          
          if(is_valid(copyN)==1)
          {
            pushBack(list,copyN);
          }
          else{
            free(copyN);
          }
        }
      }
    }
      
  }

  return list;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/