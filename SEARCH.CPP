#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>


void Enter(void)   ;
void Result(void)  ;
int  Check(void)   ;


int  i,pos=0,strl,seal,s,k,mark=0,sd ;
char sea[32],str[512]             ;


void main()
{
 clrscr() ;
 Enter()  ;
 Result() ;
 getch()  ;
}


void Enter()
{
 cout<<"\nEnter The String : "         ;
 gets(str)                             ;
 cout<<"\nEnter The Search Keyword : " ;
 gets(sea)                             ;
}


void Result()
{
 if(Check())
	{
	 cout<<"\n\nKeyword Found at Position : "<<pos ;
	}
 else
	{
	 cout<<"\n\nKeyword NOT Found !"               ;
	}
}


int Check()
{
	 strl = strlen(str)   ;
	 seal = strlen(sea)   ;
	 s=sd=k=0             ;
	 next :
	 if( s==strl-seal+2 )
		{
		 return 0     ;
		}
	 mark=0               ;
	 for( k=0 ; k<seal ; ++k,++sd )
		{
		 if( sea[k] == str[sd] )
			{
			 mark+=1   ;
			}
		 if( mark == seal )
			{
			 pos = s+1 ;
			 return 1  ;
			}
		}
	 s++         ;
	 sd-=seal-1  ;
	 goto next   ;
}