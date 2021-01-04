#include<stdio.h>
#include<string.h>

int jointlen(char strl[],char strs[]);

char stra[200];
char strb[200];
char str[200]; 

int main()
{
	int i1,i3,i2,i4,i,max=0,len=0; 
	stra[0]=strb[0]=0;
	gets(stra);
	gets(strb);
	
	strlwr(stra);strlwr(strb);
	
	int l1,l2;
	l1=strlen(stra);
	l2=strlen(strb);
	
	for(i1=0;i1<l1;i1++){
		
		for(i2=0;i2<l2;i2++){
			
			i3=i1;i4=i2;len=0;i=0;
			while(strb[i4]&&strb[i4]==stra[i3]){
				i4++;i3++;len++;
			}
			if(len>max){
				max=len;
				i=0;
				for(i4=i2;i4<i2+max;i4++){
					str[i++]=str[i4];
				}
				str[i]=0;
			}
			
		}
		
	}
	
	double p=(double)max*2/(l1+l2);
	printf("%.3lf",p);
	return 0;
}
