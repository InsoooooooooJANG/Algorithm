#include "DoublyLinkedList.h"

int main(){
  int i = 0;
  int Count = 0;
  Node* List = NULL;
  Node* NewNode = NULL;
  Node* Current = NULL;

  for(i=0; i<5; i++){
    NewNode = DLL_CreateNode(i);
    DLL_AppendNode(&List, NewNode);
  }

  //print
  Count = DLL_GetNodeCount(List);
  for(i=0; i < Count; i++){
    Current=DLL_GetNode(List, i);
    printf("List[%d] : %d\n", i, Current->Data);
  }

  printf("\nInserting 3000 After [2] ...\n\n");

  Current=DLL_GetNode(List, 2);
  NewNode = DLL_CreateNode(3000);
  DLL_InsertAfter(Current, NewNode);

  //print
  Count=DLL_GetNodeCount(List);
  for(i=0; i<Count; i++){
    Current=DLL_GetNode(List, i);
    printf("List[%d] : %d\n", i, Current->Data);
  }

  printf("\nPrint Reverse..\n");
  //print reverse
  PrintReserve(List);

  //delete
  printf("\nDestroying Lists...\n");

  Count=DLL_GetNodeCount(List);
  for(i=0; i<Count; i++){
    Current=DLL_GetNode(List, 0);
    if(Current!=NULL){
      DLL_RemoveNode(&List, Current);
      DLL_DestroyNode(Current);
    }
  }

  return 0;
}
