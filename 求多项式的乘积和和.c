#include<stdio.h>
#include<stdlib.h>

typedef struct Equal{
	int coef;
	int expo;
	struct Equal*next;
}Equal;

typedef Equal* Eptr;

Eptr Create(Eptr first);
Eptr Mul(Eptr p1,Eptr p2);
Eptr Add(Eptr p1,Eptr p2);

int main()
{
	Eptr p1=NULL,p2=NULL,first,t;
	p1=Create(p1);
	p2=Create(p2);
	t=first=Mul(p1,p2);
	
	if(first){
		     
	printf("%d %d",first->coef,first->expo);
	first=first->next;;
	free(t);
	while(first){
		printf(" %d %d",first->coef,first->expo);
		t=first;
		first=first->next;
		free(t);
	}
	
	}
	else printf("0 0");
	printf("\n");
	first=Add(p1,p2);
	if(first){
		printf("%d %d",first->coef,first->expo);
		first=first->next;
		while(first){
			printf(" %d %d",first->coef,first->expo);
			t=first;
			first=first->next;
			free(t);
		}
	}
	else printf("0 0");
		
	return 0;
} 

Eptr Create(Eptr first)
{
	int e,c,n;
	scanf("%d",&n);
	if(n==0)return NULL;
	Eptr temp=first=(Eptr)malloc(sizeof(Equal));
	while(n){
		scanf("%d%d",&c,&e);
		first->next=(Eptr)malloc(sizeof(Equal));
	    first=first->next;
	    first->coef=c;
	    first->expo=e;
	    n--;
	}
	first->next=NULL;
	first=temp->next;
	free(temp);
	return first;
}

Eptr Mul(Eptr p1,Eptr p2)
{
	Eptr front=p2,first=NULL,last=NULL;
	if(!p1||!p2)return NULL;
	first=last=(Eptr)malloc(sizeof(Equal));
	while(p2){
		last->next=(Eptr)malloc(sizeof(Equal));
		last=last->next;
		last->coef=p1->coef*p2->coef;
		last->expo=p1->expo+p2->expo;
		p2=p2->next;
	}
	last->next=NULL;
	last=first;
	first=first->next;
	free(last);
	
	Eptr t,t1;
	p1=p1->next;
	for(;p1;p1=p1->next)
	for(p2=front;p2;p2=p2->next){
		t=(Eptr)malloc(sizeof(Equal));
		t->coef=p1->coef*p2->coef;
		t->expo=p1->expo+p2->expo;
		
		t1=first;
		while(t1->next&&t->expo<t1->next->expo)t1=t1->next;
		
		if(t1->next&&t1->next->expo==t->expo){
			t1->next->coef+=t->coef;
			free(t);
			if(!t1->next->coef){
				t=t1->next;
				t1->next=t->next;
				free(t);
			}
		}
		else {
			t->next=t1->next;
			t1->next=t;
		}
	}
	
	return first;
}

Eptr Add(Eptr p1,Eptr p2)
{
	Eptr first=(Eptr)malloc(sizeof(Equal)),t;
	Eptr last=first;
	while(p1&&p2){
		if(p1->expo>p2->expo){
			last->next=(Eptr)malloc(sizeof(Equal));
			last=last->next;
			*last=*p1;
			p1=p1->next;
		}
		else if(p1->expo==p2->expo){
			last->next=(Eptr)malloc(sizeof(Equal));
			last->next->coef=p1->coef+p2->coef;
			last->next->expo=p1->expo;
			if(!(last->next->coef)){
				free(last->next);
				last->next=NULL;
			}
			p1=p1->next;
			p2=p2->next;
			if(last->next)
			last=last->next;
		}
		else {
			last->next=(Eptr)malloc(sizeof(Equal));
			last=last->next;
			*last=*p2;
			p2=p2->next;
		}
	}
	
	if(p1)last->next=p1;
	else last->next=p2;
	
	last=first;
	first=first->next;
	free(last);
	return first;
}

