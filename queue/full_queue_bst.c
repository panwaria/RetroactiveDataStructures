/*
written by Abhinav Shrivastava
Description: full retroactive queue using binary search tree
*/
#include<stdio.h>

float present =0;

struct node_te 
{
int data;
float time;
struct node_te *left;
struct node_te *right;
}*Fr=NULL,*B=NULL;



struct node_td
{
float time;
struct node_td *left;
struct node_td *right;
};

void insert_enque(struct node_te **ptr, int data, float time)
{
  
  struct node_te *temp;
  temp=(struct node_te *)malloc(sizeof(struct node_te));
  temp->data=data;
  temp->time=time;
  temp->left=NULL;
  temp->right=NULL;
  
  if(*ptr==NULL)
      {
                *ptr=temp;
                return;
      }   
  if(time < (*ptr)->time)
    {
          insert_enque(&((*ptr)->left), data, time);
          return;
    }
  if(time > (*ptr)->time)
    {
          insert_enque(&((*ptr)->right),data, time);
          return;
    }
}

void insert_deque(struct node_td **ptr, float time)
{
  
  struct node_td *temp;
  temp=(struct node_td *)malloc(sizeof(struct node_td));
  temp->time=time;
  temp->left=NULL;
  temp->right=NULL;
  
  if(*ptr==NULL)
      {
                *ptr=temp;
                return;
      }   
  if(time < (*ptr)->time)
    {
          insert_deque(&((*ptr)->left), time);
          return;
    }
  if(time > (*ptr)->time)
    {
          insert_deque(&((*ptr)->right), time);
          return;
    }
}

 void remove_enque(struct node_te **aRoot, float el)
        {
            struct node_te *goner, *gonerL, *gonerR, *replacement, *oldRoot, *replacementL;
            oldRoot = *aRoot;
            replacementL = NULL;
            
            //stopping condition 1
            if (*aRoot == NULL) {
                       printf("No data\n");

                return;
            }
            //stopping condition 2
            else if ((*aRoot)->time == el) { //data found - replace
                //leaf node
                if ((*aRoot)->left == NULL && (*aRoot)->right == NULL) { 
                  //  printf("Leaf node found\n");
                    goner = *aRoot;
                    *aRoot = NULL;
                    free(goner);
                    return;
                }
                //node has right branch only
                else if ((*aRoot)->left == NULL) { 
                //    printf("Node with right branch found\n");
                    goner = *aRoot;
                    *aRoot = (*aRoot)->right;
                    free(goner);
                    return;
                }
                //node has left branch only
                else if ((*aRoot)->right == NULL) { 
                  //  printf("Node with left branch found\n");
                    goner = (*aRoot);
                    *aRoot = (*aRoot)->left;
                    free(goner);
                    return ;
                }
                //node has two branches
                else {                          
                //    printf("Node with two branches found\n");
                    goner = *aRoot;              //store node to be deleted
                    gonerL = (*aRoot)->left;       //store left subtree root
                    gonerR = (*aRoot)->right;      //store right subtree root
                    
                    //search for largest value in left subtree and store in pointer replacement
                    replacement = gonerL;
                    while (replacement->right != NULL)
                        replacement = replacement->right;
                        
                    //If the node with the replacement value has a left subtree,
                    // store the address of that subtree
                    if (replacement->left != NULL)
                        replacementL = replacement->left;
                                            
                    //Start rearranging tree
                    //If target is first node, that will be replacement
                    if (*aRoot == oldRoot)
                        *aRoot = replacement;
                    else {
                        *aRoot = oldRoot;
                    
                        if (replacement->data < (*aRoot)->data)
                            (*aRoot)->left = replacement;
                        else
                            (*aRoot)->right = replacement;
                    }    
                    // make sure there are no nodes looping back
                    replacement->left = gonerL;
                    if (gonerL->right == gonerL)
                        gonerL->right = NULL;
                    if (gonerL->left == gonerL)
                        gonerL->left = NULL;
                        
                    //if there was a left subtree of the original replacement
                    //, attach it to the proper subtree of the replacement
                    if (replacementL != NULL) {
                        if (replacementL->data < replacement->data)
                            replacement->left = replacementL;
                        else
                            replacement->right = replacementL;
                    }
                    replacement->right = gonerR;
                    
                    free(goner);
                    return;
                }
            }
            //If neither stopping condition is met, search recursively for the element
            else if (el < (*aRoot)->time) {
                oldRoot = *aRoot;
                 remove_enque (&((*aRoot)->left), el);
            }
            else {
                oldRoot = *aRoot;
                remove_enque (&((*aRoot)->right), el);
            }
        }

 void remove_deque (struct node_td **aRoot, float el)
        {
            struct node_td *goner, *gonerL, *gonerR, *replacement, *oldRoot, *replacementL;
            oldRoot = *aRoot;
            replacementL = NULL;
            
            //stopping condition 1
            if (*aRoot == NULL) {
                printf("No data\n");
                return;
            }
            //stopping condition 2
            else if ((*aRoot)->time == el) { //data found - replace
                //leaf node
                if ((*aRoot)->left == NULL && (*aRoot)->right == NULL) { 
                  //  printf("Leaf node found\n");
                    goner = *aRoot;
                    *aRoot = NULL;
                    free(goner);
                    return;
                }
                //node has right branch only
                else if ((*aRoot)->left == NULL) { 
                //    printf("Node with right branch found\n");
                    goner = *aRoot;
                    *aRoot = (*aRoot)->right;
                    free(goner);
                    return;
                }
                //node has left branch only
                else if ((*aRoot)->right == NULL) { 
                  //  printf("Node with left branch found\n");
                    goner = (*aRoot);
                    *aRoot = (*aRoot)->left;
                    free(goner);
                    return ;
                }
                //node has two branches
                else {                          
                //    printf("Node with two branches found\n");
                    goner = *aRoot;              //store node to be deleted
                    gonerL = (*aRoot)->left;       //store left subtree root
                    gonerR = (*aRoot)->right;      //store right subtree root
                    
                    //search for largest value in left subtree and store in pointer replacement
                    replacement = gonerL;
                    while (replacement->right != NULL)
                        replacement = replacement->right;
                        
                    //If the node with the replacement value has a left subtree,
                    // store the address of that subtree
                    if (replacement->left != NULL)
                        replacementL = replacement->left;
                                            
                    //Start rearranging tree
                    //If target is first node, that will be replacement
                    if (*aRoot == oldRoot)
                        *aRoot = replacement;
                    else {
                        *aRoot = oldRoot;
                    
                        if (replacement->time < (*aRoot)->time)
                            (*aRoot)->left = replacement;
                        else
                            (*aRoot)->right = replacement;
                    }    
                    // make sure there are no nodes looping back
                    replacement->left = gonerL;
                    if (gonerL->right == gonerL)
                        gonerL->right = NULL;
                    if (gonerL->left == gonerL)
                        gonerL->left = NULL;
                        
                    //if there was a left subtree of the original replacement
                    //, attach it to the proper subtree of the replacement
                    if (replacementL != NULL) {
                        if (replacementL->time < replacement->time)
                            replacement->left = replacementL;
                        else
                            replacement->right = replacementL;
                    }
                    replacement->right = gonerR;
                    
                    free(goner);
                    return;
                }
            }
            //If neither stopping condition is met, search recursively for the element
            else if (el < (*aRoot)->time) {
                oldRoot = *aRoot;
                 remove_deque (&((*aRoot)->left), el);
            }
            else {
                oldRoot = *aRoot;
                remove_deque (&((*aRoot)->right), el);
            }
        }

int count(struct node_te *ptr)
{
    if(ptr==NULL)
       return 0;
     else return(count(ptr->left)+1+count(ptr->right));
       
}

struct  node_te * findKthInOrder(struct node_te * t, int k) 
{ 
 if (t == NULL) 
     return NULL; 
// can't find anything, empty 
 int numLeft = count(t->left);
  if (numLeft + 1 == k) 
     { // current node 
          return t; 
     } 
  else 
       if (numLeft >= k) 
          { // in left subtree return 
               return findKthInOrder(t->left, k);
          }
       else 
          { 
               return findKthInOrder(t->right, k - (numLeft + 1)); 
          }
 } 

int pos_te(struct node_te *ptr, float time)
{
    if(ptr==NULL)
      return 0;
      
    if(ptr->time > time)
     return pos_te(ptr->left,time);
    else
     return pos_te(ptr->left,time)+1+pos_te(ptr->right,time);
}

int pos_td(struct node_td *ptr, float time)
{
    if(ptr==NULL)
      return 0;
      
    if(ptr->time > time)
     return pos_td(ptr->left,time);
    else
     return pos_td(ptr->left,time)+1+pos_td(ptr->right,time);
}

int front(struct node_te *te, struct node_td *td, float time)
{
struct node_te *temp;
int rank_td;
rank_td = pos_td(td,time);
temp=findKthInOrder(te,1+rank_td);
if(temp==NULL)
    return -1;
if(temp->time<=time)
    return(temp->data);
else 
    return -1;
}

int back(struct node_te *te, float time)
{
struct node_te *temp=findKthInOrder(te, pos_te(te,time));
if(temp==NULL)
     return(-1);
else
     return(temp->data);
}

void setfront(struct node_te *te, struct node_td *td)
{
struct node_te *temp=NULL;
int rank;
rank = pos_td(td,present);
temp=findKthInOrder(te,1+rank);
Fr=temp;
}

void setback(struct node_te *te)
{
     struct node_te *temp=findKthInOrder(te, pos_te(te,present));
     B=temp;
}

int isexists_te(struct node_te *ptr, float time)
{
    static int flag = 0;
    if(ptr==NULL)
         return flag;
    
    if(ptr->time==time)
         {
            flag=1;
            return flag;
         }
    if(flag==1)
        return flag;
    isexists_te(ptr->left,time);
    if(flag==1)
        return flag;
     isexists_te(ptr->right,time);
    if(flag==1)
        return flag;
    return flag;        
}

int isexists_td(struct node_td *ptr, float time)
{
    static int flag = 0;
    if(ptr==NULL)
         return flag;
    
    if(ptr->time==time)
         {
            flag=1;
            return flag;
         }
    if(flag==1)
        return flag;
    isexists_td(ptr->left,time);
    if(flag==1)
        return flag;
     isexists_td(ptr->right,time);
    if(flag==1)
        return flag;
    return flag;        
}

int main()
{
    int choice,data,k;
    float time;
    struct node_te *te=NULL;
    struct node_td *td=NULL;
   // struct node *front=NULL,*back=NULL;
    while(1)
    {       
	     printf("\nRETROACTIVE OPERATIONS\n_______________________");
	        printf("\n1. Insert Enque");
            printf("\n2. Insert Deque");
            printf("\n3. Remove Deque");
            printf("\n4. Remove Enque");
	        printf("\n5. front");
	        printf("\n6. back\n");
	        printf("\n__________________________\nPRESENT TIME OPERATIONS\n____________________________\n");
	        printf("7. front\n");
	        printf("8. back\n");
	        printf("9. enque\n");
	        printf("10. deque\n");
            scanf("%d",&choice);
   
            switch(choice)
            {
              case 1: 
                      printf("enter time : ");
                      scanf("%f",&time);
                      printf("enter data : ");
                      scanf("%d",&data);
                       if(time>=present)
                        {
                                       printf("enter past time");
                                       break;
                        }
                       if(isexists_te(te,time)||isexists_td(td,time))
                       {
                          printf("operation already exists");
                          break;
                       }
                      insert_enque(&te, data,time);
                      setfront(te, td);
                      setback(te);
                      break;
              case 2: 
                      printf("enter time : ");
                      scanf("%f",&time);
                       if(time>=present)
                        {
                                       printf("enter past time");
                                       break;
                        }
                      if(isexists_te(te,time)||isexists_td(td,time))
                       {
                          printf("operation already exists");
                          break;
                       }
                      insert_deque(&td,time);
                      setfront(te, td);
                      setback(te);
                      break;
              case 3: 
                      printf("enter time : ");
                      scanf("%f",&time);
                       if(time>=present)
                        {
                                       printf("enter past time");
                                       break;
                        }
		              remove_deque(&td,time);
		              setfront(te, td);
                      setback(te);
                      break;
              case 4: 
                      printf("enter time : ");
                      scanf("%f",&time);
                       if(time>=present)
                        {
                                       printf("enter past time");
                                       break;
                        }
		              remove_enque(&te,time);
		              setfront(te, td);
                      setback(te);
		              break;
                      //remove_enque()
              case 5:  
		               printf("enter time : ");
                       scanf("%f",&time);
                        if(time>present)
                        {
                                       printf("enter past time");
                                       break;
                        }
                       k=front(te,td,time);
                       if(k!=-1)
			                    printf("\nfront:%d\n",k);
                       else
                                printf("\nno data\n");
			           break;
	    
               case 6:  printf("enter time");
			            scanf("%f",&time);
			             if(time>present)
                        {
                                       printf("enter past time");
                                       break;
                        }
			            k=back(te,time);
			            if(k!=-1)
			                    printf("\nback :%d\n",k);
                         else
                                printf("\nno data\n");
			            break;
             case 7:  if(Fr!=NULL)
                                 printf("front :%d",Fr->data);
                      else
                                 printf("empty");          
                       break; 
                  
             case 8:  if(B!=NULL)
                                 printf("back :%d",B->data);
                      else
                                 printf("empty");           
                      break;
             
             case 9:  printf("enter data : ");
                      scanf("%d",&data);
                      insert_enque(&te, data,++present);
                      setfront(te, td);
                      setback(te);
                      break;
             
             case 10:  
                       insert_deque(&td,++present);
     
                       setfront(te, td);
                       setback(te);
                      break;
              default: ;             
            }
    }
}
