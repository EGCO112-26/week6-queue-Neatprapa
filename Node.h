//
//  linkedlist.h
//  LinkedList_simple
//
//  Created by Mingmanas Sivaraksa on 5/2/2566 BE.
//
#ifndef Node_h
#define Node_h

struct node
{
    int data;
    struct node *nextPtr;
};

typedef struct node Node;
typedef struct node* NodePtr;




void enqueue(NodePtr * head, NodePtr* tail, int x){
  Node* new_node=(NodePtr) malloc(sizeof(Node)); //ได้Nodeเปล่าๆมมา 1 node แล้ว
if(new_node){
  new_node->data=x;
  new_node->nextPtr=NULL;  
  /* Finish queue*/
  if((*head)==NULL){//not the same head it's different variable //หัวแถว check ว่าหัวแถวไหม หัวแถวถูกเปลี่ยนแค่ครั้งแรกครั้งเดียว 
    *head=new_node;
  }
  else{//ต่อแถว
    (*tail)->nextPtr=new_node;
  }
  *tail=new_node; //หลังจากเชื่อมก็เปลี่ยน tail
 }
}


int dequeue(NodePtr* head, NodePtr* tail){
  NodePtr t=*head;
   if(t){
   int value= t->data;
   /* Finish dequeue*/
   //Normal Case ต้องเปลี่ยน head เสมอ

          *head=t->nextPtr; //เปลี่ยน head

   //Last Node อันนี้จะพิเศษกว่า Normal case นิดหน่อย

          if((*head)==NULL){ //กลับมาแแก้ด้วย
            *tail=NULL;
          } 
          free(t);
   return value;
   }
   printf("Empty queue");
   return 0;
}



#endif
