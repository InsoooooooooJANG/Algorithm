#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode{
  int Data;
  struct tagNode* PrevNode;
  struct tagNode* NextNode;
} Node;

Node* CDLL_CreateNode(int Data);
void CDLL_AppendNode(Node** List, Node* NewNode);
void CDLL_PrintNodes(Node* List);
Node* CDLL_GetNodeAt(Node* Head, int idx);
void CDLL_InserAfter(Node* Current, Node* NewNode);
int CDLL_GetNodeCount(Node* List);
void DeleteAllNode(Node** List);
void DestroyNode(Node* DelNode);
