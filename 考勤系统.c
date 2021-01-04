#include<stdio.h>
#include<string.h>
#include<math.h>

typedef struct Student{
	int num;
	int time;
}Student;

int main(){
	
	Student s[120],t;
	int i,n,l,i1,j,p=0,h,m,t1;
	int flag=0;
	char str[120];
	scanf("%d",&n);
	getchar();
	
	for(i=0;i<n;i++){
		gets(str);
		l=strlen(str);i1=0;t.num=0;t.time=0;
		while(str[i1]!=' '){
			t.num*=10;
			t.num+=str[i1]-'0';
			i1++;
		}
		
		h=0;m=0;i1++;flag=0;
		while(str[i1]!=' '){
			if(str[i1]==':'){
				flag=1;
				i1++;continue;
			}
			if(!flag){
				h*=10;
				h+=str[i1]-'0';
				i1++;
			}
			else {
				m*=10;
				m+=str[i1]-'0';
				i1++;
			}
		}
		
		i1++;
		flag=0;t1=0;
		while(str[i1]!=0){
			if(str[i1]==':'){
				flag=1;
				h=fabs(h-t1);
				t1=0;
				i1++;continue;
			}
			if(!flag){
				t1*=10;
				t1+=str[i1]-'0';
				i1++;
			}
			else {
				t1*=10;
				t1+=str[i1]-'0';
				i1++;
			}
		}
		
		m=t1-m;
		t.time=h*60+m;
		
		flag=0;
		for(j=0;j<p;j++){
			if(s[j].num==t.num){
				s[j].time+=t.time;flag=1;
			}
		}
		
		if(!flag){
			s[p].num=t.num;
			s[p].time=t.time;
			p++;
		} 
		
	}
	
	int k;
	for(i=0;i<p;i++){
		k=i;
		for(j=i+1;j<p;j++){
			if(s[k].time<s[j].time)k=j;
			else if(s[k].time==s[j].time){
				if(s[k].num>s[j].num)k=j;
			}
		}
		
		if(k!=j){
			t=s[k];
			s[k]=s[i];
			s[i]=t;
		}
	}
	
	for(i=0;i<p;i++){
		printf("%d %d\n",s[i].num,s[i].time);
	}
	
	return 0;
}


