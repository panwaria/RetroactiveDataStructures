#include<stdio.h>
#include<iostream.h>
//#include<conio.h>
#include<malloc.h>
struct mynode
{
	int value;
	int bf;
	int time;
	struct mynode *left;
	struct mynode *right;
};
int setbf(mynode *p)
{
	int count;
	int templ,tempr;

	count = 1;

	if(p == NULL)
	{
	  return(0);
	}
	else
	{
		 int templ,tempr;
		 templ = setbf(p->left);
		 tempr = setbf(p->right);

		 if(templ < tempr)
			count = count + tempr;
		 else
			count = count + templ;
	}

	// Set the nodes balancing factor.
	p->bf = tempr - templ;

	return(count);
}



void left_rotate(mynode *p,mynode *par)
{
	struct mynode *tmp,*root;
	tmp= p->right;
	p->right=tmp->left;
	tmp->left=p;

	if(par!=NULL)
	{
		if(par->left==p)
		{
			par->left=tmp;
		}
		else
		{
			par->right=tmp;
		}
	}
	else
	{
		root=tmp;
	}
//setbf(root);
}


void right_rotate(mynode *p,mynode *par)
{
	struct mynode *tmp,*root;
	tmp= p->left;
	p->left= tmp->right;
	tmp->right= p;

	if(par!=NULL)
	{
		if(par->left==p)
		{
			par->left=tmp;
		}
		else
		{
			par->right=tmp;
		}
	}
	else
	{
		root=tmp;
	}

// Recalculate the balancing factors...
//setbf(root);

}

int timer1=0,timel1=0;
struct mynode *  insertr(struct mynode *p,int count,int value)
{
int fvalue;

if(value==1)
{
	printf("Enter the value to insert at right end:");
	scanf("%d",&fvalue);
	fflush(stdin);
}
if(count<0)
{
	printf("void deletion \n");
	return(p);
}
if(p==NULL)
{
	p=(struct mynode *)malloc(sizeof(struct mynode));
	p->value=0;
	p->left=NULL;
	p->right=NULL;
	//printf("I am in NULL \n");
}
if((p!=NULL)&&(p->left==NULL))
{
	if(value==1)
	{
		struct mynode *q;
		struct mynode *r;
		q=(struct mynode *)malloc(sizeof(struct mynode));
		r=(struct mynode *)malloc(sizeof(struct mynode));
		q->left=r;
		q->right=NULL;
		p->left=q;
		q->value=count;
		r->value=fvalue;
		r->time=(++timer1);
		r->left=NULL;
		r->right=NULL;
		//printf(" I am in lft child \n");
		return(p);
	}
	if(value==2)
	{
		printf("Void operation \n");
		return(p);
	}

}
if((p!=NULL)&&(p->right==NULL))
{
	if(value==1)
	{
		struct mynode *q;
		struct mynode *r;
		q=(struct mynode *)malloc(sizeof(struct mynode));
		r=(struct mynode *)malloc(sizeof(struct mynode));
		q->right=r;
		q->left=NULL;
		p->right=q;
		q->value=count;
		r->value=fvalue;
		r->time=(++timer1);
		r->left=NULL;
		r->right=NULL;
		//printf("I am in right child \n");
		return(p);
	}
	if(value==2)
	{
		struct mynode *q;
		struct mynode *r;
		q=(struct mynode *)malloc(sizeof(struct mynode));
		r=(struct mynode *)malloc(sizeof(struct mynode));
		q->right=r;
		q->left=NULL;
		p->right=q;
		q->value=count;
		r->value=((p->left)->left)->value;
		r->time=(++timer1);
		r->left=NULL;
		r->right=NULL;
		//printf("I am in right child \n");
		return(p);
	}
}
if(((p!=NULL)&&(p->right!=NULL))&&(p->left!=NULL))
{
	if(value==1)
	{
		struct mynode *q;
		struct mynode *r;
		struct mynode *s;
		q=(struct mynode *)malloc(sizeof(struct mynode));
		r=(struct mynode *)malloc(sizeof(struct mynode));
		s=(struct mynode *)malloc(sizeof(struct mynode));
		q->left=p;
		q->value=0;
		q->right=r;
		r->value=count;
		r->right=s;
		r->left=NULL;
		s->value=fvalue;
		s->time=(++timer1);
		s->left=NULL;
		s->right=NULL;
		p=q;
		//printf("Creating parent \n");
		return(p);
	}
	if(value==2)
	{
		struct mynode *q;
		struct mynode *r;
		struct mynode *s;
		q=(struct mynode *)malloc(sizeof(struct mynode));
		r=(struct mynode *)malloc(sizeof(struct mynode));
		s=(struct mynode *)malloc(sizeof(struct mynode));
		q->left=p;
		q->value=0;
		q->right=r;
		r->value=count;
		r->right=s;
		r->left=NULL;
		s->value=((p->right)->right)->value;
		s->time=(++timer1);
		s->left=NULL;
		s->right=NULL;
		p=q;
		//printf("Creating parent \n");
		return(p);
	}

}
}



struct mynode * insertl(struct mynode *p,int count,int value)
{
int fvalue;

if(value==1)
{
	printf("Enter the value to insert at left end:");
	scanf("%d",&fvalue);
	fflush(stdin);
}

if(count>0)
{
	printf("void deletion \n");
	return(p);
}
if(p==NULL)
{
	p=(struct mynode *)malloc(sizeof(struct mynode));
	p->value=0;
	p->left=NULL;
	p->right=NULL;
	//printf("I am in NULL \n");
}
if((p!=NULL)&&(p->left==NULL))
{
	if(value==1)
	{
		struct mynode *q;
		struct mynode *r;
		q=(struct mynode *)malloc(sizeof(struct mynode));
		r=(struct mynode *)malloc(sizeof(struct mynode));
		q->left=r;
		q->right=NULL;
		p->left=q;
		q->value=count;
		r->value=fvalue;
		r->time=(++timel1);
		r->left=NULL;
		r->right=NULL;
		//printf(" I am in lft child \n");
		return(p);
	}
	if(value==2)
	{
		printf("Void operation \n");
		return(p);
	}

}
if((p!=NULL)&&(p->right==NULL))
{
	if(value==1)
	{
		struct mynode *q;
		struct mynode *r;
		q=(struct mynode *)malloc(sizeof(struct mynode));
		r=(struct mynode *)malloc(sizeof(struct mynode));
		q->right=r;
		q->left=NULL;
		p->right=q;
		q->value=count;
		r->value=fvalue;
		r->time=(++timel1);
		r->left=NULL;
		r->right=NULL;
		//printf("I am in right child \n");
		return(p);
	}
	if(value==2)
	{
		struct mynode *q;
		struct mynode *r;
		q=(struct mynode *)malloc(sizeof(struct mynode));
		r=(struct mynode *)malloc(sizeof(struct mynode));
		q->right=r;
		q->left=NULL;
		p->right=q;
		q->value=count;
		r->value=((p->left)->left)->value;
		r->time=(++timel1);
		r->left=NULL;
		r->right=NULL;
		//printf("I am in right child \n");
		return(p);
	}
}
if(((p!=NULL)&&(p->right!=NULL))&&(p->left!=NULL))
{
	if(value==1)
	{
		struct mynode *q;
		struct mynode *r;
		struct mynode *s;
		q=(struct mynode *)malloc(sizeof(struct mynode));
		r=(struct mynode *)malloc(sizeof(struct mynode));
		s=(struct mynode *)malloc(sizeof(struct mynode));
		q->left=p;
		q->value=0;
		q->right=r;
		r->value=count;
		r->right=s;
		r->left=NULL;
		s->value=fvalue;
		s->time=(++timel1);
		s->left=NULL;
		s->right=NULL;
		p=q;
		//printf("Creating parent \n");
		return(p);
	}
	if(value==2)
	{
		struct mynode *q;
		struct mynode *r;
		struct mynode *s;
		q=(struct mynode *)malloc(sizeof(struct mynode));
		r=(struct mynode *)malloc(sizeof(struct mynode));
		s=(struct mynode *)malloc(sizeof(struct mynode));
		q->left=p;
		q->value=0;
		q->right=r;
		r->value=count;
		r->right=s;
		r->left=NULL;
		s->value=((p->right)->right)->value;
		s->time=(++timel1);
		s->left=NULL;
		s->right=NULL;
		p=q;
		//printf("Creating parent \n");
		return(p);
	}

}
}




int inorder(struct mynode *p)
{
	if(p==NULL)
	{
		return(0);
	}
	if(p->left!=NULL)
	{
		inorder(p->left);
	}
	if(p->value>10)
	{
		printf("Time = %d ",p->time);
	}
	printf("%d ",p->value);
	if(p->right!=NULL)
	{
		inorder(p->right);
	}
}



struct mynode * remove(struct mynode *p,int t,int count)
{
//printf("Time = %d  and count = %d \n",t,count);
struct mynode *f;
f=p;
struct mynode *r;
while(1)
{
	if(f==NULL)
	{
		printf("Couldnot delete \n");
		break;
	}
	if(((f!=NULL)&&(f->right!=NULL))&&((f->right)->right!=NULL))
	{
		//printf("In F!=NULL \n");
		struct mynode *q;
		q=(f->right)->right;
		if(q->time==t)
		{
			printf("Found operation and deleting \n");
			r->left=(f->left);
			//f->right=NULL;
			break;
		}
		if(q->time<t)
		{
			printf("void deletion \n");
			break;
		}
		if(q->time>t)
		{
			(f->right)->value=(f->right)->value+count;
			//printf("Proceed in left arm \n");
			r=f;
			f=f->left;
		}
	}
	if((f!=NULL)&&(f->right==NULL))
	{
		f=f->left;
		if(((f->left)->left)->time==t)
		{
			f->left=NULL;
			break;
		}
	}
}
return(p);
}


struct mynode * insert(struct mynode *p,int t1,int count,int value)
{
int fvalue;
printf("enter value to insert at time %d :",t1);
scanf("%d",&fvalue);
fflush(stdin);
struct mynode *f;
f=p;
struct mynode *rf=NULL;
while(1)
{
	if((f==NULL)&&(rf==NULL))
	{
		if(value==1)
		{
			//printf("Insert a  new parent \n");
			struct mynode *s;
			s=(struct mynode *)malloc(sizeof(struct mynode));
			struct mynode *r;
			r=(struct mynode *)malloc(sizeof(struct mynode));
			struct mynode *t;
			t=(struct mynode *)malloc(sizeof(struct mynode));
			s->left=r;
			s->right=NULL;
			r->left=t;
			r->right=NULL;
			t->left=NULL;
			t->right=NULL;
			t->time=1;
			t->value=fvalue;
			r->value=count;
			s->value=0;
			p=s;
		}
		if(value==2)
		{
			printf("void operation \n");
		}
		break;
	}
	if((((f!=NULL)&&(f->right!=NULL))&&((f->right)->right!=NULL))&&(rf==NULL))
	{
		struct mynode *q;
		q=(f->right)->right;
		if(q->time<=t1)
		{
			printf("Found place where to insert \n");
			struct mynode *s;
			s=(struct mynode *)malloc(sizeof(struct mynode ));
			s->left=f;
			struct mynode *t;
			t=(struct mynode *)malloc(sizeof(struct mynode));
			struct mynode *r;
			r=(struct mynode *)malloc(sizeof(struct mynode));
			s->right=t;
			t->right=r;
			t->left=NULL;
			r->left=NULL;
			r->right=NULL;
			if(value==1)
			{
				r->value=fvalue;
			}
			if(value==2)
			{
				r->value=((f->right)->right)->value;
			}
			r->time=t1;
			t->value=(f->right)->value+count;
			s->value=0;
			p=s;
			break;
		}
		if(q->time>t1)
		{
			(f->right)->value=(f->right)->value+count;
			//printf("Proceed in left arm \n");
			rf=f;
			f=f->left;
		}
	}
	if((((f!=NULL)&&(f->right!=NULL))&&((f->right)->right!=NULL))&&(rf!=NULL))
	{
		struct mynode *q;
		q=(f->right)->right;
		if(q->time<=t1)
		{
			printf("Found place where to insert \n");
			struct mynode *s;
			s=(struct mynode *)malloc(sizeof(struct mynode ));
			s->left=f;
			struct mynode *t;
			t=(struct mynode *)malloc(sizeof(struct mynode));
			struct mynode *r;
			r=(struct mynode *)malloc(sizeof(struct mynode));
			s->right=t;
			t->right=r;
			t->left=NULL;
			r->left=NULL;
			r->right=NULL;
			if(value==1)
			{
				r->value=fvalue;
			}
			if(value==2)
			{
				r->value=(((f->left)->right)->right)->value;
			}
			r->time=t1;
			t->value=(f->right)->value+count;
			s->value=0;
			rf->left=s;
			break;
		}
		if(q->time>t1)
		{
			(f->right)->value=(f->right)->value+count;
			//printf("Proceed in left arm \n");
			rf=f;
			f=f->left;
		}
	}
	if((f!=NULL)&&((f->left)->right==NULL))
	{
			struct mynode *u,*v,*x;
		u=(struct mynode *)malloc(sizeof(struct mynode));
		v=(struct mynode *)malloc(sizeof(struct mynode));
		x=(struct mynode *)malloc(sizeof(struct mynode));
		u->value=0;
		v->value=0;
		if(value==1)
		{
			x->value=fvalue;
		}
		if(value==2)
		{
			x->value=((rf->left)->left)->value;
		}
		x->time=t1;
		x->left=NULL;
		x->right=NULL;
		v->left=NULL;
		v->right=x;
		u->right=v;
		u->left=(p->left);
		p->left=u;
		break;
	}
}
return(p);
}


int find(struct mynode *p,int t,int r,int ch)
{
int m=0;
	if(ch==0)
	{
		//printf("I want to look for the right element \n");
	}
	if(ch==1)
	{
		//printf("I want to look for the left element \n");
		r=-1*r;
	}
struct mynode *q;
q=p;
	while(1)
	{
		if(p==NULL)
		{
			printf("void operation no element existed at this point \n");
			return(0);
		}
		if(((p!=NULL)&&(p->right!=NULL))&&((p->right)->right!=NULL))
		{
			struct mynode *r1;
			r1=(p->right)->right;
			if((r1->time==t)&&((p->right)->value==r))
			{
				m=(r1->value);
				break;
			}
			if((p->right)->value<r)
			{
			  printf("No operation \n");
			  break;
			}
			if(r1->time>t)
			{
				p=p->left;
			}
			if(r1->time<t)
			{
				printf("No operation at this time \n");
				break;
			}
		}
		if((p!=NULL)&&(p->right==NULL))
		{
			struct mynode *s;
			s=p;
			if((p->value==r)&&((p->left)->time==t))
			{
				m=(p->left)->value;
			}
			else
			{
				printf("Void deletion \n");
				return(0);
				break;
			}
		}
	}
return(m);
}
int main()
{
struct mynode *pr,*pl;
pr=NULL;
pl=NULL;
int countr=0,countl=0;
	while(1)
	{
		int ch;
		int value;
		printf("\nenter 1 to pushR(x) operation \n");
		printf("enter 2 to popR(x) operation  \n");
		printf("enter 3 to quit \n");
		scanf("%d",&ch);
		fflush(stdin);
		if(ch==1)
		{
			countr=countr+1;
			value=1;
		}
		if(ch==2)
		{
			countr=countr-1;
			value=2;
		}
		if(ch==3)
		{
			break;
		}
		pr=insertr(pr,countr,value);
		printf("\n");
		printf("\n");
	}
inorder(pr);

while(1)
{
int ch;
int value;
printf("\nenter 1 to pushL(x) operation \n");
printf("enter 2 to popL(x) operation  \n");
printf("enter 3 to quit \n");
scanf("%d",&ch);
fflush(stdin);
	if(ch==1)
	{
		countl=countl-1;
		value=1;
	}
	if(ch==2)
	{
		countl=countl+1;
		value=2;
	}
	if(ch==3)
	{
		break;
	}
pl=insertl(pl,countl,value);
//printf("\n");
}
inorder(pl);
printf("\n");
printf("\n");

while(1)
{
int ch;
int count1;
printf("\nenter 1 to remove pushR(x) operation \n");
printf("enter 2 to remove popR(x) operation  \n");
printf("enter 3 to remove pushL(x) operation \n");
printf("enter 4 to remove popL(x) operation \n");
printf("enter 5 to quit \n");
scanf("%d",&ch);
fflush(stdin);
	if(ch==1)
	{
		int t;
		printf("Enter time :");
		scanf("%d",&t);
		fflush(stdin);
		pr=remove(pr,t,-1);
	}
	if(ch==2)
	{
		int t;
		printf("Enter time :");
		scanf("%d",&t);
		fflush(stdin);
		pr=remove(pr,t,1);
	}
	if(ch==3)
	{
		int t;
		printf("Enter time :");
		scanf("%d",&t);
		fflush(stdin);
		pl=remove(pl,t,1);
	}
	if(ch==4)
	{
		int t;
		printf("Enter time :");
		scanf("%d",&t);
		fflush(stdin);
		pl=remove(pl,t,-1);
	}
	if(ch==5)
	{
		break;
	}
}
printf("\n");
inorder(pr);
printf("\n");
inorder(pl);
printf("\n");

while(1)
{
int ch;
printf("\nenter 1 to insert pushR(x) operation \n");
printf("enter 2 to insert popR(x) operation  \n");
printf("enter 3 to insert pushL(x) operation \n");
printf("enter 4 to insert popL(x) operation \n");
printf("enter 5 to quit \n");
scanf("%d",&ch);
fflush(stdin);
	if(ch==1)
	{
		int t;
		printf("Enter time :");
		scanf("%d",&t);
		fflush(stdin);
		pr=insert(pr,t,1,1);
	}
	if(ch==2)
	{
		int t;
		printf("Enter time :");
		scanf("%d",&t);
		fflush(stdin);
		pr=insert(pr,t,-1,2);
	}
	if(ch==3)
	{
		int t;
		printf("Enter time :");
		scanf("%d",&t);
		fflush(stdin);
		pl=insert(pl,t,-1,1);
	}
	if(ch==4)
	{
		int t;
		printf("Enter time :");
		scanf("%d",&t);
		fflush(stdin);
		pl=insert(pl,t,1,2);
	}
	if(ch==5)
	{
		break;
	}
}
printf("\n");
inorder(pr);
printf("\n");
inorder(pl);
printf("\n");
while(1)
{
int ch;
printf("\nEnter 1 to see to right part of queue :\n");
printf("Enter 2 to see to left part of queue :\n");
printf("enter 3 to quit \n");
scanf("%d",&ch);
fflush(stdin);
	if(ch==1)
	{
		int r,t,m;
		printf("Enter time to look at :\n");
		scanf("%d",&t);
		fflush(stdin);
		printf("Enter value of r :\n");
		scanf("%d",&r);
		fflush(stdin);
		m=find(pr,t,r,0);
		printf("Value found = %d\n",m);
	}
	if(ch==2)
	{
		int r,t,m;
		printf("Enter time to look at :\n");
		scanf("%d",&t);
		fflush(stdin);
		printf("Enter value of l :\n");
		scanf("%d",&r);
		fflush(stdin);
		m=find(pl,t,r,1);
		printf("Value found = %d\n",m);
	}
	if(ch==3)
	{
		break;
	}
}
printf("\n");
inorder(pr);
printf("\n");
inorder(pl);
printf("\n");

}

