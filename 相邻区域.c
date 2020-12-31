#include<stdio.h>

int main()
{
	int n,m,k,t,flag=0;
	int x1=-1,y1=-1,x2=-1,y2=-1;
	int i,j;
	
	scanf("%d%d%d%d",&n,&m,&k,&t);
	
	int a[21][21],num=0,temp;
	
	for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	scanf("%1d",&a[i][j]);
	
	for(i=0;i<n;i++){
		
		for(j=0;j<m;j++)
	    if(a[i][j]==t){
		
	      	x1=i;
		    y1=j;
	    	break;
		
	    }
	    if(x1>=0&&y1>=0)
		break;
	} 
	
	for(i=n-1;i>=0;i--){
		
		for(j=m-1;j>=0;j--){
			
			if(a[i][j]==t){
				
				x2=i;
				y2=j;
				break;
				
			}
			
		}
		if(x2>=0&&y2>=0)
		break;
	} 
	
	if(x1>0){
		i=x1-1;
		temp=a[i][y1];
		num++;
		for(j=y1;j<y2;j++){
			if(a[i][j]!=temp){
				temp=a[i][j];
				num++;
			}
		}
	}
	if(x2<n-1){
		i=x2+1;
		temp=a[i][y1];
		num++;
		for(j=y1;j<y2;j++){
			if(a[i][j]!=temp){
				temp=a[i][j];
				num++;
			}
		}
	}
	if(y1>0){
		j=y1-1;
		temp=a[x1][j];
		num++;
		for(i=x1;i<x2;i++){
		    if(a[i][j]!=temp){
				temp=a[i][j];
				num++;
			}
	    }
	}
	if(y2<m-1){
		j=y2+1;
		temp=a[x1][j];
		num++;
		for(i=x1;i<x2;i++){
		    if(a[i][j]!=temp){
				temp=a[i][j];
				num++;
			}
	    }
	}
	printf("%d",num);
	return 0;
} 
