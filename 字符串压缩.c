#include<stdio.h>
#include<string.h>

int alpha(char a);
int isnum(char a);

int main()
{
	char str[300],letter,num=0,r=0;
	gets(str);
	
	int i,i1;
	
	for(i=0;i<strlen(str);){
		
		if(alpha(str[i])){
			letter=str[i];
			i++;
		}
		if(isnum(str[i])){
			
			for(;isnum(str[i]);i++){
				
				num*=10;
				num+=str[i]-'0';
				
			}
			
		}
		if(num&&letter){
			for(i1=0;i1<num;i1++)
			printf("%c",letter);
			num=0;letter=0;r=0;
		}
		else printf("%c",letter);
		
	}
	
	return 0;
}

int alpha(char a)
{
	return (a>='a'&&a<='z')||(a>='A'&&a<='Z');
}

int isnum(char a)
{
	return a>='0'&&a<='9';
}

