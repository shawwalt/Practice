#include<stdio.h>
#include<stdlib.h> 

typedef struct Equal{
	int a;
	int x;
	struct Equal *next;
}Equal;

Equal *add;
Equal *mul;

int main()
{
	Equal *a=NULL,*b=NULL,*p,*q1,*q2;
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
	    p=(Equal*)malloc(sizeof(Equal));
	    scanf("%d%d",&p->a,&p->x);
		p->next=NULL;
		
		if(!a){
		    q1=a=p;
		}
		else {
			q1->next=p;
			q1=q1->next;
		}
	}
	
	scanf("%d",&m);
	for(int i=0;i<m;i++){
	    p=(Equal*)malloc(sizeof(Equal));
	    scanf("%d%d",&p->a,&p->x);
		p->next=NULL;
		
		if(!b){
		    q2=b=p;
		}
		else {
			q2->next=p;
			q2=q2->next;
		}
	}
	
	Equal *t;
	p=mul=(Equal*)malloc(sizeof(Equal));
	p->next=NULL;
	for(q1=a;q1!=NULL;q1=q1->next)
	for(q2=b;q2!=NULL;q2=q2->next){
		t=(Equal*)malloc(sizeof(Equal));
		t->a=(q1->a)*(q2->a);
		t->x=(q1->x)+(q2->x);
		t->next=NULL;
		while(p){
			
			if(p&&p->x==t->x){
				p->a+=t->a;
				free(t);break;
			}else if(p->next&&t->x>p->next->x){
				t->next=p->next;
				p->next=t;break;
			}else if(!p->next){
				(*p)=(*t);
				free(t);
				p->next=(Equal*)malloc(sizeof(Equal));
				p=p->next;
				p->next=NULL;
				p=mul;break;
			}else p=p->next;
			
		}
	}
	
	q1=a;q2=b;
	p=add=(Equal*)malloc(sizeof(Equal));
	p->next=NULL;
	while(q1||q2){
		if(q1&&q2){
			if(q1->x>q2->x){
				(*p)=(*q1);
				q1=q1->next;
				p->next=(Equal*)malloc(sizeof(Equal));
				p=p->next;
				p->next=NULL;
			}else if(q1->x<q2->x){
				(*p)=(*q2);
				q2=q2->next;
				p->next=(Equal*)malloc(sizeof(Equal));
				p=p->next;
				p->next=NULL;
			}else {
				p->x=q1->x;
				p->a=(q1->a)+(q2->a);
				q1=q1->next;
				q2=q2->next;
				p->next=(Equal*)malloc(sizeof(Equal));
				p=p->next;
				p->next=NULL;
			}
		}
		else{
			if(q1){
				(*p)=(*q1);
				q1=q1->next;
				p->next=(Equal*)malloc(sizeof(Equal));
				p=p->next;
				p->next=NULL;
			}
			else if(q2){
				(*p)=(*q2);
				q2=q2->next;
				p->next=(Equal*)malloc(sizeof(Equal));
				p=p->next;
				p->next=NULL;
			}
		}
	}
	p=mul;
	printf("%d %d",p->a,p->x);
	p=p->next;
	for(;p->next;p=p->next){
		printf(" ");
		printf("%d %d",p->a,p->x);
	}
	printf("\n");
	p=add;
	printf("%d %d",p->a,p->x);
	p=p->next;
	for(;p->next;p=p->next){
		printf(" ");
		printf("%d %d",p->a,p->x);
	}
	return 0;
}
