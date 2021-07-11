#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <math.h>


int gd=0, gm, x=100, y=100, i, s=0, flagx=0, flagy=0, f=20	;
char ypii[20]={'Y','O','U','R',' ','P','C',' ','I','S',' ',
	       'I','N','F','E','C','T','E','D'}			;


void main()
{
 clrscr() 							;
 initgraph( &gd, &gm, "C:\\TurboC3\\BGI\\" )                    ;
 for( i=20 ; !kbhit() ; i++ )
	{
	 switch( i%5 )
		{
		 case 0   : setcolor(WHITE )	;	break	;
		 case 1   : setcolor( RED  )	; 	break	;
		 case 2   : setcolor( BLUE )	; 	break   ;
		 case 3   : setcolor( CYAN ) 	; 	break   ;
		 case 4   : setcolor(YELLOW)	; 	break	;
		}

	 switch(x)
		{
		 case 0   : flagx++		;	break	;
		 case 175 : flagx++		;	break	;
		}
	 switch(y)
		{
		 case 0   : flagy++		;	break	;
		 case 460 : flagy++		;	break	;
		}
	 if( flagx%2 )      x +=5				;
	 else		    x -=5                               ;
	 if( flagy%2 )	    y -=5				;
	 else		    y +=5                               ;

	 f = 1000*sin(i)*sin(i)+20				;
	 sound(f)						;

	 settextstyle( 0 , 0 , 3 )				;
	 outtextxy( x , y , ypii )				;
	 delay(100)						;
	 cleardevice()						;
	}
 getch() 							;
 nosound()							;
}