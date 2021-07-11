#include<iostream.h>
#include<conio.h>
#include<graphics.h>
void main()
{
 clrscr() ;
 int gd=0,gm ;
 initgraph(&gd,&gm,"c:\\turboc3\\bgi\\") ;
 int x=getmaxx()/2,y=getmaxy()/2,i=0 ;
 while( i != 13 )
	{
	 rectangle(x,y,x+10,y+10) ;
	 i=getch() ;
	 switch(i)
		{
		 case 119 : y-=4 		; break ;
		 case 115 : y+=4 		; break ;
		 case 100 : x+=4 		; break ;
		 case  97 : x-=4 		; break ;
		 case 114 : setcolor   ( RED ) 	; break ;
		 case 103 : setcolor   (GREEN) 	; break ;
		 case 98  : setcolor   (BLUE ) 	; break ;
		 case 105 : moverel    ( 0,4 )	; break ;
		 case 106 : moverel    (-4,0 )  ; break ;
		 case 107 : moverel    ( 0,-4)	; break	;
		 case 108 : moverel    ( 4,0 )	; break ;
		 case 122 : setbkcolor ( RED )  ; break ;
		 case 120 : setbkcolor (GREEN)	; break ;
		 case  99 : setbkcolor (BLUE )  ; break ;
		 case 118 : setbkcolor (WHITE)	; break ;
		 case 113 : cleardevice(     )	; break ;
		}
	}
}