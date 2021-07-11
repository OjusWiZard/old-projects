/*	My 1st 3D Graphics Program :D
	Use arrow-keys to move left, right, up, down
	and 'w' and 's' to move back & forth
	You can also adjusts 'Size' and 'FOV' constants below.
	Enjoy!
*/

#include <graphics.h>
#include <iostream.h>
#include <conio.h>
#include <math.h>

#define UP    72
#define DOWN  80
#define LEFT  75
#define RIGHT 77

// Settings
#define Size 10
#define FOV  90		//in Degrees

void Initialize()	;
void Field()		;
int  nx( int, int )	;
int  ny( int, int )	;

void main()
{
 clrscr()			;
 Initialize()		;
 Field()			;
 closegraph()		;
}

void Initialize()
{
 int gd=DETECT, gm								;
 initgraph( &gd , &gm , "C://TurboC3//BGI" )	;
 setbkcolor( BLACK )							;
 setcolor  ( WHITE )							;
}

void Field()
{
 int cx, cy, cz=100, s=Size/2, in											;
 while( in!=27 )		//27 = Esc
	{
	 cleardevice()															;

	 line( nx(cx-s,cz-s) , ny(cy-s,cz-s) , nx(cx-s,cz+s) , ny(cy-s,cz+s) )	;	//Draws all four lines parallel to z-axis
	 line( nx(cx-s,cz-s) , ny(cy+s,cz-s) , nx(cx-s,cz+s) , ny(cy+s,cz+s) )	;
	 line( nx(cx+s,cz-s) , ny(cy-s,cz-s) , nx(cx+s,cz+s) , ny(cy-s,cz+s) )	;
	 line( nx(cx+s,cz-s) , ny(cy+s,cz-s) , nx(cx+s,cz+s) , ny(cy+s,cz+s) )	;

	 line( nx(cx-s,cz-s) , ny(cy-s,cz-s) , nx(cx-s,cz-s) , ny(cy+s,cz-s) )	;	//Draws the square which is towards you
	 line( nx(cx-s,cz-s) , ny(cy-s,cz-s) , nx(cx+s,cz-s) , ny(cy-s,cz-s) )	;
	 line( nx(cx+s,cz-s) , ny(cy+s,cz-s) , nx(cx+s,cz-s) , ny(cy-s,cz-s) )	;
	 line( nx(cx+s,cz-s) , ny(cy+s,cz-s) , nx(cx-s,cz-s) , ny(cy+s,cz-s) )	;

	 line( nx(cx-s,cz+s) , ny(cy-s,cz+s) , nx(cx-s,cz+s) , ny(cy+s,cz+s) )	;	//Draws the square which is away from you
	 line( nx(cx-s,cz+s) , ny(cy-s,cz+s) , nx(cx+s,cz+s) , ny(cy-s,cz+s) )	;
	 line( nx(cx+s,cz+s) , ny(cy+s,cz+s) , nx(cx+s,cz+s) , ny(cy-s,cz+s) )	;
	 line( nx(cx+s,cz+s) , ny(cy+s,cz+s) , nx(cx-s,cz+s) , ny(cy+s,cz+s) )	;

	 in = getch()															;
	 switch( in )	//if statments don't let it go out of your view
		 {
		  case UP		: if(ny((cy-1)-s,cz-s)>1									   ) cy--	;	break	;
		  case DOWN		: if(ny((cy+1)+s,cz-s)<getmaxy()							   ) cy++	;	break	;
		  case LEFT		: if(nx((cx-1)-s,cz-s)>1									   ) cx--	;	break	;
		  case RIGHT	: if(nx((cx+1)+s,cz-s)<getmaxx()							   ) cx++	;	break	;
		  case 's'   	: if(nx(cx-s,(cz-1)-s)>1 		 && ny(cy-s,(cz-1)-s)>1  	 &&
							 nx(cx+s,(cz-1)-s)<getmaxx() && ny(cy+s,(cz-1)-s)<getmaxy()) cz--	;	break	;
		  case 'w'		: 																 cz++	;   break	;
		  default    	: 	  																		break	;
		 }
	}
}

int nx( int l, int n )
{
 return l*getmaxx()/(n*tan(M_PI*FOV/360)) + getmaxx()/2	;	//The biggest obstacle-formula to derive(for me specially)
}

int ny( int m, int n )
{
 return m*getmaxx()/(n*tan(M_PI*FOV/360)) + getmaxy()/2	;	//Unfortunately, I can't explain this without any diagram.
}

/*
    Picture you saw in the video :- https://drive.google.com/open?id=1Z5o919qBO0euxzDW6HwalnUypLVydfeQ
	Meaning of variables/Constants/Functions that i used...
		Size			Length of Cube in pixels.
		FOV				Field Of View (used it in my rough, so i initialized here too).
		nx/ny			Functions takes in two original values of x/y and z, and returns the apparent x/y values that could directly be used on screen.
		gd				Graphics Driver
		gm				Graphics Mode
		cx/cy/cz		The correct (x,y,z) coordinates that are original and are used in our visulization.
		in				Input
		l/m/n			cx/cy/cz values used inside nx/ny function.
*/

/*
	I'm happy to see you at bottom :)
	Please don't ask me about any type of technique I used.
	I have no idea about any theoretical aspects of it
	and i have made this all alone without any tutorial or help.
	also its my first one, so bugs are pretty normal things.

	Happy Coding
*/