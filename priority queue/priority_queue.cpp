/* This is implimentation of retroactive priority queue
Made by : Harshit Gupta
Reg No  : 20054015
Branch  : Computer Science
Year    : Final Year
*/ 
#include<iostream>
//#include<conio.h>
#include<cmath>
#define INSERT 1
#define DEL_MIN -1
using namespace std;
struct nodeq
{
    int type;
    int val;
    float time;
    nodeq *left;
    nodeq *right;
};
struct node
{
    int val;
    node *lt,*rt;
    nodeq *link;
}*bst;
class queue
{
    nodeq *front,*back;
    float t;
    public:
        void insert_insert(int);
        void insert_insert(int,float);
        void insert_del();
        void insert_del(float);
        void del(float);
        void show_op();
        void simple_del(nodeq *);
        queue()
        {
            t=0;
            front=NULL;
            back=NULL;
        };
}q;

int find_min(node *);
void queue::simple_del(nodeq *tp)
{
    if(tp==NULL)return;
    if(tp->left!=NULL)
    {
        tp->left->right=tp->right;
    }
    if(tp->right!=NULL)
    {
        tp->right->left=tp->left;
    }
    delete(tp);
}
            
void insert_tree(node **root,int v,nodeq *ptr)
{    
    node *p=new node;
    node *temp;
    ptr->type=0;
    p->val=v;
    p->lt=NULL;
    p->rt=NULL;
    p->link=ptr;
    if(*root == NULL)
    {
        *root = p;
        return;
    }
    temp=*root;
    while(temp)
    {
        if(temp->val>=v)
        {
            if(temp->lt!=NULL)
                temp=temp->lt;
            else
            {
                temp->lt=p;
                break;
            }
        }
        else
        {
            if(temp->rt!=NULL)
                temp=temp->rt;
            else
            {
                temp->rt=p;
                break;
            }
        }
    }
}
void del_tree(node **root,int v)
{
    int found;
    node *q,*par,*x,*xsucc;
    if(*root==NULL)return;
    par=x=NULL;
    q=*root;
    found=0;
    while(q!=NULL)
    {
        if(q->val==v)
        {
            found=1;
            x=q;
            break;
        }
        par=q;
        if(q->val>v)
            q=q->lt;
        else
            q=q->rt;
    }

    if(found==0)return;
    x->link->type=1;
    if(x->lt!=NULL && x->rt!=NULL)
    {
        par=x;
        xsucc=x->rt;
        while(xsucc->lt!=NULL)
        {
            par=xsucc;
            xsucc=xsucc->lt;
        }
        x->val=xsucc->val;
        x=xsucc;
    }    
    if(par==NULL)
    {
        if(x->lt==NULL && x->rt==NULL)
        {
            *root=NULL;
        }
        else if(x->lt==NULL && x->rt!=NULL)
            {
                *root=x->rt;
                free(x);
            }
            else if(x->lt!=NULL && x->rt==NULL)
            {
                *root=x->lt;
                free(x);
            }
         return;
    }                   
    if(x->lt==NULL && x->rt==NULL)
    {
        if(par->rt==x)
            par->rt=NULL;
        else
            par->lt=NULL;
        free(x);
        return;
    }
    if(x->lt==NULL && x->rt!=NULL)
    {
        if(par->lt==x)
            par->lt=x->rt;
        else
            par->rt=x->rt;
        free(x);
        return;
    }
    if(x->lt!=NULL && x->rt==NULL)
    {
        if(par->lt==x)
            par->lt=x->lt;
        else
            par->rt=x->lt;
        free(x);
        return;
    }
}
    
void maxk(nodeq *start,nodeq *cu)
{
    nodeq *temp,*st;
    int sum=0,max;
    st=start;
    if(st==NULL)return;
    temp=NULL;
       
    while(st!=cu && st!=NULL)
    {
        sum+=st->type;
        if(sum==0)temp=st;
        st=st->right;
    }        
   if(temp==NULL)
    {        
        temp=start;
     
   }
    else temp=temp->right;
    {        
    
        if(cu->type!=-1)
            max=cu->val;
        else
            max=-32000;
        
        while(temp)
        {  
            if(temp->type==1 && temp->val>max)
            {
                cu=temp;
                max=temp->val;
            }
            temp=temp->right;
        }                
        cu->type=0;      
        insert_tree(&bst,cu->val,cu);
    }
}

void mink(nodeq *st,nodeq *cu)
{
    nodeq *temp,*temp2;
    int flag=0;
    int sum=0,min=32000;
    if(st==NULL)return;
    temp=NULL;
    temp2=NULL;
        
    while(st!=NULL)
    {
        
        if(st==cu)flag=1;
        else sum+=st->type; 
        if(sum==0 && flag==1)
        {
            temp=st;
            break;
        }
        st=st->right;
    }        
   if(temp==NULL)
    {       
        temp=cu;
        while(temp->right!=NULL)temp=temp->right;
        cout<<"temp==NULL";
    }
        
        while(temp)
        {        
            if(temp->type==0 && temp->val<min)
            {
                temp2=temp;
                min=temp->val;
            }
            temp=temp->left;
        }                
        if(temp2 != NULL)
        {
            temp2->type=1;        
            del_tree(&bst,temp2->val);
        }
        else
        {
            q.simple_del(cu);
        }
    
} 
        
void show_queue(node *root)
{
    if(root)
    {
        show_queue(root->lt);
        printf("%d -> ",root->val);
        show_queue(root->rt);
    }
}
int find_min(node *p)
{
    if(p==NULL)
    {
        //cout<<"No element in queue\n";
        return -1;
    }
    while(p->lt!=NULL)p=p->lt;
    return (p->val);
}

void queue::show_op()
{
    nodeq *temp;
    temp=back;
    while(temp)
    {
        if(temp->type==-1)
        {
//             printf("insert(del_min() ,t=%.2f), %d\n",temp->time,temp->type);
              printf("insert(del_min() ,t=%.2f)\n",temp->time);
        }
        else
        {
//            printf("insert(insert(%2d),t=%.2f),  %d\n",temp->val,temp->time,temp->type);
            printf("insert(insert(%2d),t=%.2f)\n",temp->val,temp->time);       
        }
        temp=temp->right;
    }
}
void queue::del(float tm)
{
    nodeq *temp;
    temp=back;
    while(temp)
    {
        if(temp->time==tm)
        {
            if(temp->type==-1)
                maxk(back,temp);
            else if(temp->type==0)
                      del_tree(&bst,temp->val);
                  else
                        mink(back,temp);
            if(temp->left!=NULL)
                temp->left->right=temp->right;
            if(temp->right!=NULL)
                temp->right->left=temp->left;
            if(temp->left==NULL && temp->right!=NULL)
                back=temp->right;
            if(temp->left!=NULL && temp->right==NULL)
                front=temp->left;
            if(temp->left==NULL && temp->right==NULL)
                back=NULL;
            break;
        }
        temp=temp->right;
    }
}            
void queue::insert_insert(int v)
{
    nodeq *p;
    p=new nodeq;
    p->type=1;
    p->val=v;
    p->left=front;
    p->right=NULL;
    p->time=t;
    t=t+1;
    if(front!=NULL)front->right=p;
    front=p;
    insert_tree(&bst,v,p);
    if(back==NULL)back=front;
}
void queue::insert_insert(int v,float tm)
{
    nodeq *p=new nodeq;
    nodeq *temp;
    if(tm>t)
    {
        cout<<"exceeding current time hence no operation \n";
        return;
    }
    p->type=1;
    p->val=v;
    p->time=tm;
    if(back==NULL)
    {
        p->left=front;
        p->right=NULL;
        front=p;
        back=p;
    }
    else
    {
        temp=back;
        while(temp->time<tm && temp->right!=NULL)
            temp=temp->right;
        if(tm>temp->time && temp->right==NULL )
        {
            temp->right=p;
            p->left=temp;
            p->right=NULL;
            front=p;
        }
        else
        {
            if(temp->left==NULL)
                back=p;
            else
                temp->left->right=p;
            p->left=temp->left;
            temp->left=p;
            p->right=temp;
        }
    }
    maxk(back,p);
}
              
void queue::insert_del()
{
    nodeq *p;int i;
    if(find_min(bst)==-1)return;
    p=new nodeq;
    p->type=-1;
    p->left=front;
    p->right=NULL;
    p->time=t;
    t=t+1;
    if(front!=NULL)front->right=p;
    front=p;
    del_tree(&bst,find_min(bst));
    if(back==NULL)back=front;
}
void queue::insert_del(float tm)
{
    nodeq *p=new nodeq;
    nodeq *temp;
    if(tm>t)
    {
        cout<<"exceeding current time hence no operation \n";
        return;
    }
    p->type=-1;
    p->time=tm;
    if(back==NULL)
    {
        p->left=front;
        p->right=NULL;
        front=p;
        back=p;
    }
    else
    {
        temp=back;
        while(temp->time<tm && temp->right!=NULL)
            temp=temp->right;
        if(temp->right==NULL && temp->time<tm)
        {
            temp->right=p;
            p->left=temp;
            front=p;
            p->right=NULL;
        }
        else
        {
            if(temp->left==NULL)
                back=p;
            else
                temp->left->right=p;
            p->left=temp->left;
            temp->left=p;
            p->right=temp;
        }
    }
    mink(back,p);
}   
                              
        
        
int main()
{
    bst=NULL;

    int ch,val;
    float time;
    while(1)
    {
    cout<<"******************************************************************\n"
    <<"For normal priority queue operations: \n\n"
    <<"Enter 1 for find-min operation\n"
    <<"Enter 2 for insert operation\n"
    <<"Enter 3 for del-min operation\n\n"
    <<"For Retroactive priority queue operations: \n\n"
    <<"Enter 4 for inserting a insert operation at any given time\n"
    <<"Enter 5 for inserting a del-min operation at any given time\n"
    <<"Enter 6 for deleting any operation at any given time\n\n"
    <<"Enter 7 for quit\n\n";
    cin>>ch;
    cout<<"******************************************************************\n";
    switch(ch)
    {
        case 1 :
            if(find_min(bst)!=-1)
                cout<<"Minimum Element is : "<<find_min(bst)<<endl;
            else
                cout<<"No element in Queue"<<endl;
            break;
        case 2 :
            cout<<"Enter value for inserting\n";
            cin>>val;
            q.insert_insert(val);
            break;
        case 3 :
            q.insert_del();
            break;
        case 4 :
            cout<<"Enter value and time of inserting\n";
            cin>>val>>time;
            q.insert_insert(val,time);
            break;            
        case 5 :
            cout<<"Enter time for inserting del-min\n";
            cin>>time;
            q.insert_del(time);
            break;            
        case 6 :
            cout<<"Enter time for deletion of operation\n";
            cin>>time;
            q.del(time);
            break;
        default :
            exit(0);        
    }

    cout<<endl<<"Total list of operations are :\n";
    q.show_op();
    
    cout<<endl<<"Elements in current queue are (in increasing order):\n";
    show_queue(bst);
    cout<<endl<<endl<<endl<<endl;
    }
    
}
