#include<stdio.h>

int a[20][5]={0};
int o[20]={0};
int k[101];

int main()
{
	int n;
	int i,j,i1,flag=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&k[i]);
	}
	
	i1=0;
	while(i1<n){
		i=0;j=0;
		for(i=0;k[i1]&&i<20;i++)
		if(5-o[i]>=k[i1]){
			for(j=0;k[i1]&&j<5;j++){
				if(!a[i][j]){
					a[i][j]=1;
				    k[i1]--;
				    printf("%d ",(i)*5+(j+1));
				    o[i]++;
				}
			}
		}
		
		if(k[i1]){
			for(i=0;k[i1]&&i<20;i++)
			for(j=0;k[i1]&&j<5;j++)
			{
				if(!a[i][j]){
					a[i][j]=1;
				    k[i1]--;
				    printf("%d ",(i)*5+(j+1));
				    o[i]++;
				}
			}
		}
		i1++;
		printf("\n");
	}
	
	return 0;
}

