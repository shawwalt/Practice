#include<stdio.h>
#include<string.h>

char str[100];
char command[100];

int main()
{
	int p,i,t,i1;
	gets(str);
	gets(command);
	p=strlen(str);
	
	while(strcmp(command,"pwd"))
	{
		t=0;
		if(!strcmp(command,"cd /")){
			p=0;
			str[++p]=0;
		}
		else if(!strcmp(command,"cd ..")){
			if(p!=0){
			p--;
			while(str[p]!='/'){
				p--;
			};
			if(p!=0)
			str[p]='\0';
			else str[p+1]=0;
			if(1);}
		}
		else {
			if(command[3]=='/'){
				i1=0;
				for(i=3;command[i]!='\0';i++){
					str[i1++]=command[i];
				} 
				str[i1]=0;
				p=i1;
			}
			else {
				if(str[p-1]!='/'){
				    str[p++]='/';
				}
				
				for(i=3;command[i]!=0;i++){
					str[p++]=command[i];
				}
				str[p]=0;
			}
		}
		gets(command);
	}
	puts(str);
}
