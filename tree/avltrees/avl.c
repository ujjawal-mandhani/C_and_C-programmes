#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node * lchild;
	struct node * rchild;
	int data;
	int height;
}* root=NULL;

struct node * Rinsert(struct node * p,int key)
{
	struct node * t=NULL;
	if(p==NULL)
	{
		t=(struct node *)malloc(sizeof(struct node));
		t->data=key;
		t->height=1;
		t->lchild=t->rchild=NULL;
		return t;
	}
	else if(key < p->data)
		p->lchild=Rinsert(p->lchild,key);

	else if(key > p->data)
		p->rchild=Rinsert(p->rchild,key);

	p->height=Nodeheight(p);
	if(Balancefactor(p)==2 && Balancefactor(p->lchild)==1)
		return LLrotation(p);

	else if(Balancefactor(p)==2 && Balancefactor(p->lchild)==-1)
		return LRrotation(p);

	else if(Balancefactor(p)==-2 && Balancefactor(p->rchild)==-1)
		return RRrotation(p);

	else if(Balancefactor(p)==-2 && Balancefactor(p->rchild)==1)
		return RLrotation(p);

	return p;
}

int Nodeheight(struct node * p)
{
	int hl,hr;
	hl=p && p->lchild ? p->lchild->height : 0;
	hr=p && p->rchild ? p->rchild->height : 0;
	return hl > hr ? hl + 1 : hr + 1;
}

int Balancefactor(struct node * p)
{
	int hl,hr;
	hl=p && p->lchild->height : 0;
	hr=p && p->rchild->height : 0;
	return hl-hr;
}

struct node * LLrotation(struct node * p)
{
	struct node * pl=p->lchild;
	struct node * plr=pl->rchild;
	pl->rchild=p;
	p->lchild=plr;
	p->height=Nodeheight(p);
	pl->height=Nodeheight(pl);

	if(root==pl)
	{
		root=pl;
	}
	return pl;
}

struct node * LRrotation(struct node * p)
{
	struct node * pl=p->lchild;
	struct node * plr=pl->rchild;
	pl->rchild=plr->lchild;
	p->lchild=plr->rchild;
	plr->lchild=pl;
	plr->rchild=p;

	pl->height=Nodeheight(pl);
	p->height=Nodeheight(p);
	plr->height=Nodeheight(plr);
	if(root == p)
		root=plr;
	return plr;
}

