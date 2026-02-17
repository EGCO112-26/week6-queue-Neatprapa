//For Assg6 [Extra credit]

typedef struct node{
  struct node* next;
  int order_number;
  int q;
}order;

typedef struct Queue{
  order *head,*tail;
  int size;
}queue;


void enqueue(queue *q, int menu_num, int cutomer_num)
{
  order *new_node = (order*)malloc(sizeof(order));
  if(new_node)
  {
    new_node->order_number = menu_num;
    new_node->q = cutomer_num;
    new_node->next = NULL;
    
    if(q->head == 0)
    {
      q->head = new_node;
    }
    else q->tail->next = new_node;
    q->tail = new_node;
    q->size++;
  }
}

int dequeue(queue *q)
{
  if(q->size == 0) return 0;
  order *temp = q->head;
  int price = 0;
  
  if(temp->order_number == 1) price = 650;
  else if(temp->order_number == 3) price = 575;
  else if(temp->order_number == 4) price = 450;
  
  q->head = q->head->next;
  if(q->head == NULL) q->tail = NULL;
  free(temp);
  q->size--;

  return price;
}


/*typedef struct {
	 NodePtr headPtr,tailPtr;
	int size;
}Queue;


void enqueue_struct(Queue* q, int x){
  Node *new_node=(Node*) malloc(sizeof(Node));
if(new_node){ 
  new_node->data=x;
  new_node->nextPtr=NULL;

  if(q->size==0) q->headPtr=new_node;
  else q->tailPtr->nextPtr=new_node;
  q->tailPtr=new_node;
  q->size++;
 }
}


int dequeue_struct(Queue *q){
   NodePtr t=q->headPtr;
   if(t){
   int value= t->data;
   q->headPtr=t->nextPtr;
   if(q->headPtr==NULL) q->tailPtr=NULL;
   q->size--;
   free(t);
   return value;
   }
   //printf("empty queue\n");
   return -1;
}*/



