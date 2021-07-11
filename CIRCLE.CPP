#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>

void main()
{
 clrscr() ;
 int driver=5,oj,x,y,i ;
 float f ;
 initgraph(&driver,&oj,"c:\\turboc3\\bgi") ;
 for( x=100,i=100,f=1000 ; i>0 ; i--,x+=5 )
	{
	 settextstyle( 7 , 0 , 4 ) ;
	 outtextxy( 190 , 10 , "Collapsing Circle" ) ;
	 circle( x , 200 , i ) ;
	 sound( f ) ;
	 f -= 9.8 ;
	 delay( 20 ) ;
	 clrscr() ;
	}
 nosound() ;
 exit(1) ;
 getch() ;
 closegraph() ;
}
