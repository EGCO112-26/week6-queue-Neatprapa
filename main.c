#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"
#include "Queue.h"



//For Assg6 [Extra credit]

int main(int argc,char*argv[])
{
  int i;
  int is_closed = 0;

  if(argc<2)
  {
    printf("Usage : %s [menu_number and 'x' to dequeue]\n",argv[0]);
    return 1;
  }

  queue myQ = {NULL, NULL, 0};
  int customer_count = 1;

  for(i=1; i<argc; i++)
  {
    if(strcmp(argv[i], "x") == 0)
    {
      is_closed = 1;
      continue;
    }

    int val = atoi(argv[i]);

    if(is_closed == 0)
    {
      if(val == 2)
      { 
        if(myQ.size>0)
        {
          int total_bill = 0;
          int current_cust = myQ.head->q;
          printf("Customer no : %d\n", current_cust);
        
          while(myQ.size>0 && myQ.head->q == current_cust)
          {
            total_bill = total_bill + dequeue(&myQ);
          }
          printf("You have to pay --> %d THB <--\n",total_bill);

          int cash = 0;
          while(cash<total_bill)
          {
            int payment;
            printf("Your cash : ");
            scanf("%d",&payment);
            cash = cash + payment;
            if(cash<total_bill) printf("Sorry T^T it's not enough money we need %d more\n",total_bill-cash);
          }
          if(cash>total_bill) printf("Here! this is your change >>> %d \n",cash-total_bill);
          printf("Thank you <3<3 Enjoy!\n");
          customer_count++;
        }
      }
      else 
      {
        enqueue(&myQ, val, customer_count);
        printf("=====================================================\n");
        printf("My order is : %d\n", val);
      }
    } 
    else
    {
      if(val != 2 && val != 0) enqueue(&myQ, val, customer_count);
      else if(val == 2) customer_count++;
    }
}
printf("=====================================================\n");
printf("-->There are %d people left in the queue\n", myQ.size);
while(myQ.size>0)
  {
    order *temp = myQ.head;
    myQ.head = myQ.head->next;
    free(temp);
    myQ.size--;
  }
  return 0;

}

/*int main(int argc , char **argv) {
  NodePtr headPtr=NULL;
   NodePtr tailPtr=NULL;

  Queue  q;
   q. headPtr=NULL;
   q.tailPtr=NULL;
   q.size=0;

   int i,x;
    for(i=1;i<argc;i++){
        if(strcmp(argv[i],"x")==0){ //คือถ้าเป็น x ให้ทำการ dequeue แต่ถ้าตัวอื่นๆให้ enqueue
          if(q.size>0){
            //x=dequeue_struct(&q);
            int value=dequeue_struct(&q);
            printf("dequeing %d\n",value);
          }
          else{
            printf("Empty queue\n");
          }
        }
        else {
        enqueue_struct(&q, atoi(argv[i]));
       
      }
 }
  return 0;
}*/


