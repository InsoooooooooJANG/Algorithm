#include "CircularDoublyLinkedList.h"

Node* CDLL_CreateNode(int Data){
  Node* NewNode = (Node*) malloc (sizeof(Node));
  NewNode->Data = Data;
  NewNode->PrevNode = NULL;
  NewNode->NextNode = NULL;
  return NewNode;
}
void CDLL_AppendNode(Node** List, Node* NewNode){
  if((*List) == NULL){
    (*List) = NewNode;
    NewNode->NextNode = (*List);
    NewNode->PrevNode = (*List);
  }else{
    Node* Tail = (*List)->PrevNode;

    Tail->NextNode->PrevNode = NewNode;
    Tail->NextNode = NewNode;

    NewNode->NextNode = (*List);
    NewNode->PrevNode = Tail;

  }
}
void CDLL_PrintNodes(Node* List){
  int Count = CDLL_GetNodeCount(List);
  int i =0;

  for(i = 0; i < Count; i++){
    printf("List[%d] -> %d\n", i, CDLL_GetNodeAt(List, i)->Data);
  }
}
Node* CDLL_GetNodeAt(Node* Head, int idx){
  Node* Current = Head;
  while(Current!=NULL && --idx >= 0){
    Current = Current->NextNode;
  }
  return Current;
}
void CDLL_InserAfter(Node* Current, Node* NewNode){
  NewNode->NextNode = Current->NextNode;
  NewNode->PrevNode = Current;
  Current->NextNode->PrevNode = NewNode;
  Current->NextNode = NewNode;

}
int CDLL_GetNodeCount(Node* List){
  int i = 0;
  Node* Current = List;
  while(Current!=NULL){
    i++;
    Current= Current->NextNode;

    if(Current == List)
      break;
  }

  return i;
}
void DeleteAllNode(Node** List){
  int i =0;
  int Count = CDLL_GetNodeCount(*List);
  Node* DelNode = NULL;

  for(i=0; i<Count; i++){
    DelNode = CDLL_GetNodeAt(*List, 0);

    if(DelNode == (*List)){
      Node* NewHead = DelNode->NextNode;

      if(NewHead == (*List)){
        (*List)->NextNode= NULL;
        (*List)->PrevNode = NULL;
        DestroyNode(DelNode);
        continue;
      }

      (*List) = NewHead;

      DelNode->PrevNode->NextNode = NewHead;
      NewHead->PrevNode = DelNode->PrevNode;
    }else{
      Node* Temp = DelNode;
      DelNode->PrevNode->NextNode = Temp->NextNode;
      DelNode->NextNode->PrevNode = Temp->PrevNode;

    }

    DelNode->PrevNode = NULL;
    DelNode->NextNode = NULL;
    DestroyNode(DelNode);
  }
}
void DestroyNode(Node* DelNode){
  free(DelNode);
}
