#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode{
  int Data;
  struct tagNode* PrevNode;
  struct tagNode* NextNode;
} Node;

Node* DLL_CreateNode(int Data);
void DLL_AppendNode(Node** List, Node* NewNode);
int DLL_GetNodeCount(Node* List);
Node* DLL_GetNode(Node* List, int idx);
void DLL_InsertAfter(Node* Current, Node* NewNode);
void DLL_RemoveNode(Node** List, Node* CurrentNode);
void DLL_DestroyNode(Node* CurrentNode);

void PrintReserve(Node* Head);
