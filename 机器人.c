#include<stdio.h>

int i,j;
int i1,j1;

typedef struct locate{
	int i;
	int j;
}locate;

void add(locate*l);
void move(char c);
int cmp(locate *l);

char a[100][100];
locate l[150];

int main()
{
	int n,m,c,num=0;
	scanf("%d%d%d",&n,&m,&c);
	getchar();
	c=c-1;
	
	int i0;
	for(i0=0;i0<150;i0++){
		l[i0].i=l[i0].j=-1;
	}
	
	for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	scanf(" %c",&a[i][j]);
	
	i1=0;j1=c;i=0;
	while(j1<m&&i1<n&&i1>=0&&j1>=0){
		for(i=0;i<num;i++){
			if(cmp(l+i)){
				printf("loop %d",num);break;
			}
		}
		if(cmp(l+i))break;
		num++;
		add(l+i);i++;
		move(a[i1][j1]);
	}
	
	if(!cmp(l+i))
	printf("out %d",num);
	
	return 0;
}

void move(char c)
{
	switch(c){
		case 'N':i1--;break; 
		case 'S':i1++;break;
		case 'E':j1++;break;
		case 'W':j1--;
	}
}

void add(locate*l)
{
	l->i=i1;
	l->j=j1;
}

int cmp(locate *l)
{
	if(l->i==i1&&l->j==j1)
	return 1;
	else 
	return 0;
}
