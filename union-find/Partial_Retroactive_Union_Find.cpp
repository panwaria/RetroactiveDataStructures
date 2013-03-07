/* 
Author: Prakhar Panwaria
Date: 14-10-08
Description: To implement Partial-Retroactivity in Union-Find 
             Data Structure by using Hash Table.
*/

#include<iostream>
//#include<conio.h>
#include<stdio.h>
using namespace std;

struct operation
{
       float timer;
       int op;
       float x;
       float y;
       operation *right;
       operation *left;       
};
operation* head;
float timer=0;

struct node
{
       float value;
       node *parent;
       int tree;
       int rank;
};
node* tree[200];
int tree_no=0;
node* _node[200];
int node_no=0;
int hash_node[200];

int Create(float val);
int Union(float x,float y);
node* Find(node*);
int Sameset();
int Manipulate(float t);
void add_operation(int op,float x,float y);
void display_operation();
void insert_operation();
void delete_operation();

int main()
{
            
      int op=100;
      int res;
      cout<<"                 OPERATIONS\n";
      cout<<"-----------------------------------------------\n\n";
      cout<<"1. Create(x)\n";
      cout<<"2. Union(x,y)\n";
      cout<<"3. Find(x)\n";
      cout<<"4. Display operations\n";
      cout<<"5. Insert operation at time 't'\n";
      cout<<"6. Delete operation at time 't'\n";
      cout<<"7. Exit\n";
      cout<<"Enter the operation no. at time = "<<timer<<" : ";
while(op!=8)
{
      cin>>op;
      
      switch(op)
      {
                case 1:
                     float val;
                     cout<<"\n**************** CREATE(x) ********************\n";
                     cout<<"Enter the value of the node to be created : ";
                     cin>>val;
                     cout<<"\n";
                     add_operation(op,val,0);
                     break;
                case 2:
                     float x,y;
                     cout<<"\n**************** UNION(x,y) ********************\n";
                     cout<<"Enter the value of first node(x) : ";
                     cin>>x;
                     cout<<"Enter the value of second node(y) : ";
                     cin>>y;    
                     cout<<"\n";
                     add_operation(op,x,y);
                     //res=Union();
                     break;
                case 3:
                     int h;
                     Manipulate(-100);
                     cout<<"\n**************** FIND OPERATION **********************\n";
                     cout<<"Enter the value of the node whose root is to be found : ";
                     cin>>val;
                     h=hash_node[(int)val];
                     node *root;
                     root=Find(_node[h]);
                     cout<<"\nThe value of the root is : "<<root->value<<"\n\n";
                     break;
               
                case 4:
                     display_operation();
                     break;     
                case 5:
                     insert_operation();
                     break;
                case 6:
                     delete_operation();
                     break;         
                                   
                case 7:
                     exit(0);
                     break;
                default:
                     cout<<"\nEnter valid operation again.\n";
      }
      cout<<"Enter the operation no. at time = "<<timer<<" : ";
}// end of while
//getche();
return 0;
}//End of Main()

void add_operation(int op,float x,float y)
{
     operation *temp,*temp2;
     if(timer == 0)
     {
              
              temp = new operation;
              temp->timer = timer++;
              temp->op = op;
              temp->x=x;
              temp->y=y;
              temp->left = NULL;
              temp->right = NULL;
              head=temp;
     }
     else
     {
         
         temp2=head;
         while(temp2->right !=NULL)
         {
               temp2=temp2->right;
         }
         temp = new operation;
         temp->timer= timer++;
         temp->op=op;
         temp->x=x;
         temp->y=y;
         temp->left=NULL;
         temp->right=NULL;
         temp2->right=temp;
     }
}// End of add_operation()

void display_operation()
{
     operation *temp;
     temp=head;
     cout<<"\n**************** DISPLAY OPERATION ********************\n";
     while(temp != NULL)
     {
            cout<<"--["<<temp->op<<",t="<<temp->timer<<"]--";
            temp = temp->right;
     }
     cout<<"\n\n";
}//End of display_operation()

void insert_operation()
{
     float t,x,y;
     int op,flag=1;
     operation *temp1,*temp2,*temp;
     cout<<"\n**************** INSERT OPERATION ********************";
     cout<<"\nEnter the time at which operation is inserted : ";
     cin>>t;
     cout<<"Enter the operation no. to insert : ";
     cin>>op;
     while(op!=1 && op!=2)
     {
                cout<<"Enter the correct operation no. to insert : ";            
                cin>>op;
     } 
     if(op==1)
     {
                cout<<"Enter the value of the node to be created : ";
                cin>>x;
                cout<<"\n";
                y=0;
     }
     else if(op==2)
     {
                 cout<<"Enter the value of first node(x) : ";
                 cin>>x;
                 cout<<"Enter the value of second node(y) : ";
                 cin>>y;    
                 cout<<"\n";
     }     
     temp1=head;
     temp = new operation;
     temp->timer = t;
     temp->op = op;
     temp->x = x;
     temp->y = y;
     if(temp1 == NULL)
     {
           temp->left=NULL;
           temp->right=NULL;
           head=temp;
     }
     else if(temp1->right == NULL)
     {
         if(temp1->timer > t)
         {
               temp->left=NULL;
               temp->right=temp1;
               temp1->left=temp;
               head=temp;
         }
         else
         {
               temp->left=temp1;
               temp->right=NULL;
               temp1->right=temp;
         }             
     }
     else if(temp1->timer > t)
     {
           temp->left=NULL;
           temp->right=temp1;
           temp1->left=temp;
           head=temp;
     }
     else
     {
           while(temp1->right->timer < t)
           {
               temp1=temp1->right;
               if(temp1->right == NULL)
               {
                       flag=0;break;
               }
           }
           if(flag!=0)
           {
               temp2=temp1->right;
               temp->left=temp1;
               temp->right=temp2;
               temp1->right=temp;
               temp2->left=temp;
           }
           else
           {
               temp1->right=temp;
               temp->left=temp1;
               temp->right=NULL;
           }
     }
          cout<<"Now the list of operations become : \n";
          display_operation();
}//End of insert_operation().
  
void delete_operation()
{
     float t,least_time;
     int op,flag=1;
     operation *temp1,*temp2,*temp;
     cout<<"\n**************** DELETE OPERATION ********************";
     cout<<"\nEnter the time at which operation is to be deleted : ";
     cin>>t;
     temp1=head;
     if(head==NULL)
            cout<<"No Operations now...Sorry!! \n";
     else
     {
         least_time=head->timer;
         if(t!=timer && t!=least_time )
         {
             
             while(temp1->right->timer != t)
             {
                   temp1=temp1->right;               
                   if(temp1->right == NULL)
                   {
                           flag=0;break;
                   }
             }
             if(flag!=0)
             {
                 temp2 = temp1->right;
                 op = temp2->op;
                 if(temp2->right!=NULL)
                      temp2->right->left = temp1;
                 temp1->right = temp2->right; 
             }
             else
                 cout<<"\nTime="<<t<<" not found.\n";
         }  
         else if(t == least_time)
         {
              if(temp1->timer == least_time)
                      head = temp1->right;
               else
                      cout<<"\nTime=0 not found!!!.\n";
         }
         else if(t == timer)
         {
             temp1=head;
             while(temp1->right->timer != t)
             {
                   temp1=temp1->right;
             }
             temp1->right = NULL; 
         } 
     }     
      
     cout<<"Now the list of operations become : \n";
     display_operation();   
}// End of delete_operation().
                    
 
int Create(float val)
{
    hash_node[(int)val]=node_no;
    node *temp;
    temp = new node;
    temp->value = val;
    temp->parent = temp;
    temp->tree=1;
    temp->rank=0;
    
    /* Taking care of all the nodes. */
    _node[node_no++]=temp;
    /* Taking note of trees. */
    tree[tree_no++]=temp;

    return 0;    
}

int Union(float x,float y)
{ 
    node *xRoot, *yRoot;
    xRoot=Find(_node[hash_node[(int)x]]);
    yRoot=Find(_node[hash_node[(int)y]]);
    if(xRoot->rank > yRoot->rank)
    {
        yRoot->parent = xRoot;
        yRoot->tree=0;
    }
    else if(xRoot->rank < yRoot->rank) 
    {
        xRoot->parent = yRoot;
        xRoot->tree=0;
    }
    else if(xRoot->rank == yRoot->rank)
    {
        yRoot->parent = xRoot;
     	xRoot->rank = xRoot->rank + 1;
     	yRoot->tree=0;
    }
}// End of Union().

node* Find(node* temp)
{
    if(temp->parent == temp)
          return temp;
    else
    {
          temp->parent = Find(temp->parent);
          return temp->parent;
    }
}// End of Find().

                            
int Manipulate(float t)
{  
    operation *temp;
    temp = head;
    if(t == -100)
    {
        while(temp != NULL)
        {
            if(temp->op == 1)
                   Create(temp->x);
            else if(temp->op == 2)
                   Union(temp->x,temp->y);
            temp=temp->right;
        }        
    }
    else
    {
        while(temp->timer <= t && temp != NULL)
        {
            if(temp->op == 1)
               Create(temp->x);
            else if(temp->op == 2)
               Union(temp->x,temp->y);
            if(temp->right != NULL)
                temp=temp->right;
            else break;
        }
    }
    return 0;    
}//End of Manipulate.
                            
