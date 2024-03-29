#include "CircularDoublyLinkedList.h"

int main(){
  int i = 0;
  int Count = 0;
  Node* List = NULL;
  Node* NewNode = NULL;
  Node* Current = NULL;

  //add 5 nodes
  for (i =0; i<5; i++){
    NewNode = CDLL_CreateNode(i);
    CDLL_AppendNode(&List, NewNode);
  }

  //print list
  CDLL_PrintNodes(List);

  printf("\nInserting 3000 After [2] ... \n\n");

  NewNode = CDLL_CreateNode(3000);
  Current = CDLL_GetNodeAt(List, 2);
  CDLL_InserAfter(Current, NewNode);

  //print List
  Count = CDLL_GetNodeCount(List);
  for(i=0; i<Count*2; i++){
    if(i==0)
      Current = List;
    else
      Current=Current->NextNode;

    printf("List[%d] - %d\n", i, Current->Data);
  }

  printf("Destroy All Lists...\n\n");

  DeleteAllNode(&List);

  return 0;
}
