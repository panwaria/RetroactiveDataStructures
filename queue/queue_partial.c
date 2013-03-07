/*
written by Abhinav Shrivastava
Description: partial retroactive queue using doubly linked list sorted by time
*/
#include<stdio.h>

struct node 
{
       int data;
       float t;
       struct node *prev;
       struct node *next;
}*front=NULL,*back=NULL,*holder=NULL;

float present=0;

void insert_enque(int data, float time)
{
  struct node *temp,*temp1;
  temp=(struct node *)malloc(sizeof(struct node));
  temp->data=data;
  temp->t=time;
  temp->next=NULL;
  temp->prev=NULL;
  if (front==NULL)
     {        
          front =temp;
          back=temp;
          return;
     }
   if(back->t < time)
     {

          back->next=temp;
          temp->prev=back;    
          back=back->next;
          return;
     }
   if(front->t<time)
    {
       temp1=front;
       while(temp1->t<time)
            temp1=temp1->next;
       
       temp->prev=temp1->prev;
       (temp->prev)->next=temp;
       temp->next=temp1;
       temp1->prev=temp;
       return;                         
    }
    if(front->t>time)
    {   
        temp1=front;
        while((temp1->prev!=NULL) && (temp1->prev->t > time))
            temp1=temp1->prev;
        if(temp1->prev==NULL)
        {
             temp1->prev=temp;
             temp->prev=NULL;
             temp->next=temp1;
             front=front->prev;
             return;
        }
        else
        {
            temp->prev=temp1->prev;
            temp->prev->next=temp;
            temp->next=temp1;
            temp1->prev=temp;
            front=front->prev;
            return;
        }
    }
}

void insert_deque(float time)
{
    if(front==back)
	{
	holder=front;
	front=NULL;
	back=NULL;
	}
    else
	{
	front=front->next;
	}
}

void remove_deque(float time)
{
if(front==NULL)
	{
	front=holder;
	back=holder;
	}
else
	{
	front=front->prev;
	}	
}

void remove_enque(float time)
{
 
  struct node *temp1,*temp = front;
  if(time <= front->t)
	{
	while(temp&&time<temp->t)
            temp=temp->prev;
	if(temp==NULL)
		{
		printf("\nNo deque operation at time %f\n",time);
		return;
		}
	if(time>temp->t)
		{
		printf("\nno deque operation at time %f\n",time);
		return;
		}
	if(time==temp->t)
		{
		if(front==back)
		 {
		  holder=front->prev;
		  if(holder)
		  	holder->next=NULL;
                  front=NULL;
		  back=NULL;
		  return;
		 }
		front=front->next;
		if(temp->prev==NULL)
			{
			temp->next->prev=NULL;
			free(temp);
			return;
			}
		else
			{
			temp->next->prev=temp->prev;
			temp->prev->next=temp->next;
			free(temp);
			return;
			}
		}	    

	} 
    else
	{
	while((temp) && (temp->t < time))
	  temp=temp->next;
	if(temp==NULL)
  		{
		printf("\nno enque operation at time %f\n",time);
		return;
		}
	if(temp->t<time)
		{
		printf("\nno enque operation at time %f\n",time);
		return;
		}
	if(time==temp->t)
		{
		if(back==front)
		   {
			
			holder = front->prev;
			front->prev->next=NULL;
			front=NULL;
			back=NULL;
		   }
		else
		  if(temp==back)
		    {
                      temp->prev->next=NULL;
		      back=temp->prev;
		      free(temp);
 		    }
		  else
			{
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
			free(temp);
			}
		
		}
	}
	
}

int main()
{
    int choice,data;
    float time;
   // struct node *front=NULL,*back=NULL;
    while(1)
    {       
	        printf("\nRETROACTIVE OPERATIONS\n_______________________");
	        printf("\n1. Insert Enque");
            printf("\n2. Insert Deque");
            printf("\n3. Remove Deque");
            printf("\n4. Remove Enque");
	        printf("\n__________________________\nPRESENT TIME OPERATIONS\n____________________________\n");
	        printf("5. front\n");
	        printf("6. back\n");
	        printf("7. enque\n");
	        printf("8. deque\n");
            scanf("%d",&choice);
            switch(choice)
            {
              case 1: printf("enter data : ");
                      scanf("%d",&data);
                      printf("enter time : ");
                      scanf("%f",&time);
                      if(time>=present)
                        {
                                       printf("enter past time");
                                       break;
                        }
                      insert_enque(data,time);
                      break;
              case 2: 
                      printf("enter time : ");
                      scanf("%f",&time);
                      if(time>=present)
                        {
                                       printf("enter past time");
                                       break;
                        }
                      insert_deque(time);
                      break;
              case 3: 
                      printf("enter time : ");
                      scanf("%f",&time);
                      if(time>=present)
                        {
                                       printf("enter past time");
                                       break;
                        }
                      remove_deque(time);
                      break;
              case 4: 
                      printf("enter time : ");
                      scanf("%f",&time);
                      if(time>=present)
                        {
                                       printf("enter past time");
                                       break;
                        }
		              remove_enque(time);
		              break;
                      //remove_enque()
              case 5: if(front==NULL)
                   	      printf("\nempty");
                      else
			              printf("%d",front->data);
                      break;
	    
              case 6: if(front==NULL)
                        printf("\nempty");
                      else
                        printf("%d",back->data);
                      break;
              
              case 7: printf("enter data : ");
                      scanf("%d",&data);
                      
                      insert_enque(data,++present);
                      break;
              case 8:
                      insert_deque(++present);
                   
          

              default: ;             
            }
    }
}
