#include "DoublyLinkedList.h"

Node* DLL_CreateNode(int Data){
  Node* newNode = (Node*) malloc (sizeof(Node));
  newNode->Data = Data;
  newNode->PrevNode = NULL;
  newNode->NextNode = NULL;
  return newNode;
}
void DLL_AppendNode(Node** List, Node* NewNode){
  if((*List)==NULL){
    (*List) = NewNode;
  }else{
    Node* Tail = (*List);
    while(Tail->NextNode != NULL){
      Tail = Tail->NextNode;
    }

    Tail->NextNode = NewNode;
    NewNode->PrevNode = Tail;
  }
}
int DLL_GetNodeCount(Node* List){
  int i = 0;
  Node* Tail= List;
  while(Tail->NextNode != NULL){
    Tail=Tail->NextNode;
    i++;
  }
  i++;
  return i;
}
Node* DLL_GetNode(Node* List, int idx){
  int i =0;
  Node* Current=List;

  while(i<idx){
    Current = Current->NextNode;
    i++;
  }

  return Current;
}
void DLL_InsertAfter(Node* Current, Node* NewNode){
  Current->NextNode->PrevNode = NewNode;
  NewNode->NextNode = Current->NextNode;
  Current->NextNode= NewNode;
  NewNode->PrevNode = Current;
}

void DLL_RemoveNode(Node** List, Node* CurrentNode){
  if((*List)==CurrentNode){
    (*List) = CurrentNode->NextNode;

  }else{
    Node* Temp = CurrentNode;
    if(CurrentNode->PrevNode!=NULL){
      CurrentNode->PrevNode->NextNode= Temp->NextNode;
    }

    if(CurrentNode->NextNode != NULL){
      CurrentNode->NextNode->PrevNode = Temp->PrevNode;
    }
  }

  CurrentNode->PrevNode = NULL;
  CurrentNode->NextNode = NULL;

}
void DLL_DestroyNode(Node* CurrentNode){
  free(CurrentNode);
}

void PrintReserve(Node* Head){
  Node* Tail=Head;
  int i = 0;
  if(Tail==NULL){
    return;
  }

  while(Tail->NextNode!=NULL){
    Tail = Tail->NextNode;
    i++;
  }

  while(Tail->PrevNode != NULL){
    printf("List[%d] -> %d\n", i, Tail->Data);
    Tail = Tail->PrevNode;
    i--;
  }

  printf("List[%d] -> %d\n", i, Tail->Data);
}
