#include "stdafx.h"
#include<iostream>
using namespace std;
class node
{
public:
int data;
struct node *left,*right;
int ht;
};


class AVL
{
node *root;
int height(node *);
node *rotate_right(node *);
node *rotate_left(node *);
node *RR(node *);
node *LL(node *);
node *LR(node *);
node *RL(node *);
int BF(node *);
public:
AVL()
{
root=NULL;
}
node *insert(node *,int);
node *delet(node *,int);
void preorder (node *);
void inorder(node *);
};

int main()
{
AVL A;
int x,n,i,choice;
node *root=NULL;

cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t…. CREATION OF AVL TREE …";

do
{
cout<<"\n\n MENU:";
cout<<"\n\n\t1.Create\n\n\t2.Insert\n\n\t3.Delete\n\n\t4.Display\n\n\t5.Exit ";

cout<<"\n\nEnter the choice: ";
cin>>choice;
switch(choice)
{
case 1:
cout<<"\n\nEnter the number of elements: ";
cin>>n;
cout<<"\n\nEnter tree data: ";
for(i=0;i<n;i++)
{
cin>>x;
root=A.insert(root,x);
}
break;
case 2:
cout<<"\n\nEnter the data to be insert: ";
cin>>x;
A.insert(root,x);
break;
case 3:
cout<<"\n\nEnter a data which u have to delete: ";
cin>>x;
A.delet(root,x);
break;
case 4:
cout<<"\n\nPreorder Display:\n\n";
A.preorder(root);
cout<<"\n\nInorder Display:\n\n";
A.inorder(root);
break;
}
}while(choice!=5);

}

node *AVL::insert(node *T,int x)

{
if(T==NULL)
{
T=new node;
T->data=x;
T->left=NULL;
T->right=NULL;
}
else
{
if(x>T->data)
{
T->right=insert(T->right,x);
if(BF(T)==-2)
{
if(x>T->right->data)
T=RR(T);
else
T=RL(T);
}
}
else if(x<T->data)
{
T->left=insert(T->left,x);
if(BF(T)==2)
{
if(x<T->left->data)
T=LL(T);
else
T=LR(T);
}
}
}
T->ht=height(T);
return(T);
}

node *AVL::delet(node *T,int x)

{
node *p;
if(T==NULL)
return(0);
else
if(x>T->data)
{
T->right=delet(T->right,x);
if(BF(T)==2)
if(BF(T->left)>=0)
T=LL(T);
else
T=LR(T);
}
else if(x<T->data)
{
T->left=delet(T->left,x);
if(BF(T)==-2)
if(BF(T->right)<=0)
T=RR(T);
else
T=RL(T);
}
else
{
if(T->right!=NULL)
{
p=T->right;
while(p->left!=NULL)
p=p->left;
T->data=p->data;
T->right=delet(T->right,p->data);
if(BF(T)==2)
if(BF(T->left)>=0)
T=LL(T);
else
T=LR(T);
}
else
return(T->left);
}
T->ht=height(T);
return(T);
}

int AVL::height(node *T)

{
int LH,RH;
if(T==NULL)
return(0);
if(T->left==NULL)
LH=0;
else
LH=1+T->left->ht;
if(T->right==NULL)
RH=0;
else
RH=1+T->right->ht;
if(LH>RH)
return (LH);
else
return (RH);
}

int AVL::BF(node *T)

{
int LH,RH;
if(T==NULL)
return(0);
if(T->left==NULL)
LH=0;
else
LH=1+T->left->ht;
if(T->right==NULL)
RH=0;
else
RH=1+T->right->ht;
return(LH-RH);
}

node *AVL::rotate_left(node *x)

{
node *y;
y=x->right;
x->right=y->left;
y->left=x;
x->ht=height(x);
y->ht=height(y);
return(y);
}

node *AVL::rotate_right(node *x)

{
node *y;
y=x->left;
x->left=y->right;
y->right=x;
x->ht=height(x);
y->ht=height(y);
return(y);
}

node *AVL::LL(node *T)

{
T=rotate_right(T);
return(T);
}

node *AVL::RR(node *T)

{
T=rotate_left(T);
return(T);
}

node *AVL::LR(node *T)

{
T->left=rotate_left(T->left);
T=rotate_right(T);
return(T);
}

node *AVL::RL(node *T)

{
T->right=rotate_right(T->right);
T=rotate_left(T);
return(T);
}

void AVL::preorder(node *root)

{
node *T=root;
if(T!=NULL)
{
cout<<" \n"<<T->data<<" [BF= "<<BF(T)<<"]";
preorder(T->left);
preorder(T->right);
}
}

void AVL::inorder(node *root)

{
node *T=root;
if(T!=NULL)
{
inorder(T->left);
cout<<" \n"<<T->data<<" [BF= "<<BF(T)<<"]";
inorder(T->right);
}
}

 
