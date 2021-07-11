#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>


void Enter()		;               void FillColor()		;
void DynamicCuboid()	;               void Cuboid()			;
float Ax()		;		float Ay()			;
float Bx()		;               float By()			;
float Cx()		;               float Cy()			;
float Dx()		;               float Dy()			;
float Ex()		;               float Ey()			;
float Fx()		;               float Fy()			;
float Gx()		;               float Gy()			;
float Hx()		;               float Hy()			;


float l, b, h, x, y, z							;
int gd=0, gm,		face6[10]=
				 {
				  Ax() , Ay() 				,
				  Bx() , By()				,
				  Cx() , Cy()				,
				  Dx() , Dy()                   	,
				  Ax() , Ay()
				 }                              	,
			face5[10]=
				 {
				  Ax() , Ay()				,
				  Bx() , By()				,
				  Fx() , Fy()				,
				  Ex() , Ey()                   	,
				  Ax() , Ay()
				 }                              	,
			face4[10]=
				 {
				  Bx() , By()				,
				  Cx() , Cy()				,
				  Gx() , Gy()				,
				  Fx() , Fy()                   	,
				  Bx() , By()
				 }					,
			face3[10]=
				 {
				  Ex() , Ey()				,
				  Fx() , Fy()				,
				  Gx() , Gy()				,
				  Hx() , Hy()                   	,
				  Ex() , Ey()
				 }					,
			face2[10]=
				 {
				  Dx() , Dy()				,
				  Hx() , Hy()				,
				  Gx() , Gy()				,
				  Hx() , Hy()                   	,
				  Dx() , Dy()
				 }					,
			face1[10]=
				 {
				  Ax() , Ay()				,
				  Ex() , Ey()				,
				  Hx() , Hy()				,
				  Dx() , Dy()                   	,
				  Ax() , Ay()
				 }					;


void main()
{
 clrscr()								;
 Enter()								;
 initgraph( &gd, &gm, "C:\\TurboC3\\BGI\\")				;
 DynamicCuboid()							;
 getch()								;
 closegraph()								;
}


void Enter()
{
 cout<<"Enter the Lenght  of Cuboid : "					;
 cin >>l								;
 cout<<"Enter the Height  of Cuboid : "					;
 cin >>b								;
 cout<<"Enter the Breadth of Cuboid : "			       		;
 cin >>h								;
}


void DynamicCuboid()
{
 int key								;
 setbkcolor( WHITE )							;
 do
	{
	 key = getch()							;
	 switch( key )
		{
		 case 97  : x-=(5*M_PI)/180	; break			; // a
		 case 100 : x+=(5*M_PI)/180	; break			; // d
		 case 115 : y+=(5*M_PI)/180	; break			; // s
		 case 119 : y-=(5*M_PI)/180	; break			; // w
		 case 122 : z-=(5*M_PI)/180	; break			; // z
		 case 120 : z+=(5*M_PI)/180	; break			; // x
		}
	 cleardevice()							;
	 Cuboid()							;
	 FillColor()							;
	}
 while( key != 13 )							;
}


void Cuboid()
{
 setcolor(  RED  )	;	line( Ax() , Ay() , Bx() , By() )	;
 setcolor( GREEN )	;	line( Bx() , By() , Cx() , Cy() )	;
 setcolor( BLUE  )	;	line( Cx() , Cy() , Dx() , Dy() )	;
 setcolor( BROWN )	;	line( Dx() , Dy() , Ax() , Ay() )	;

 setcolor(  RED  )	;	line( Ex() , Ey() , Fx() , Fy() )	;
 setcolor( GREEN )	;	line( Fx() , Fy() , Gx() , Gy() )	;
 setcolor( BLUE  )	;	line( Gx() , Gy() , Hx() , Hy() )	;
 setcolor( BROWN )	;	line( Hx() , Hy() , Ex() , Ey() )	;

 setcolor(  RED  )	;	line( Ax() , Ay() , Ex() , Ey() )	;
 setcolor( GREEN )	;	line( Bx() , By() , Fx() , Fy() )	;
 setcolor( BLUE  )	;	line( Cx() , Cy() , Gx() , Gy() )	;
 setcolor( BROWN )	;	line( Dx() , Dy() , Hx() , Hy() )	;
}


void FillColor()
{
 setcolor(   RED   )	;	fillpoly( 5 , face1 )			;
 setcolor(  GREEN  )	;	fillpoly( 5 , face2 )  			;
 setcolor(  BLUE   )	;	fillpoly( 5 , face3 )       		;
 setcolor(  CYAN   )	;	fillpoly( 5 , face4 )       		;
 setcolor( MAGENTA )	;	fillpoly( 5 , face5 )       		;
 setcolor(  BROWN  )	;	fillpoly( 5 , face6 )       		;
}


float Ax()
{
 return getmaxx()/2 + pow( l*l+b*b+h*h , 1.0/3 )*( - cos(x) - cos(y) - cos(z) )/2		;
}


float Bx()
{
 return getmaxx()/2 + pow( l*l+b*b+h*h , 1.0/3 )*( + cos(x) - cos(y) - cos(z) )/2		;
}


float Cx()
{
 return getmaxx()/2 + pow( l*l+b*b+h*h , 1.0/3 )*( + cos(x) + cos(y) - cos(z) )/2		;
}


float Dx()
{
 return getmaxx()/2 + pow( l*l+b*b+h*h , 1.0/3 )*( - cos(x) + cos(y) - cos(z) )/2		;
}


float Ex()
{
 return getmaxx()/2 + pow( l*l+b*b+h*h , 1.0/3 )*( - cos(x) - cos(y) + cos(z) )/2		;
}


float Fx()
{
 return getmaxx()/2 + pow( l*l+b*b+h*h , 1.0/3 )*( + cos(x) - cos(y) + cos(z) )/2		;
}


float Gx()
{
 return getmaxx()/2 + pow( l*l+b*b+h*h , 1.0/3 )*( + cos(x) + cos(y) + cos(z) )/2		;
}


float Hx()
{
 return getmaxx()/2 + pow( l*l+b*b+h*h , 1.0/3 )*( - cos(x) + cos(y) + cos(z) )/2		;
}


float Ay()
{
 return getmaxy()/2 - pow( l*l+b*b+h*h , 1.0/3 )*( - sin(x) - sin(y) - sin(z) )/2		;
}


float By()
{
 return getmaxy()/2 - pow( l*l+b*b+h*h , 1.0/3 )*( + sin(x) - sin(y) - sin(z) )/2		;
}


float Cy()
{
 return getmaxy()/2 - pow( l*l+b*b+h*h , 1.0/3 )*( + sin(x) + sin(y) - sin(z) )/2		;
}


float Dy()
{
 return getmaxy()/2 - pow( l*l+b*b+h*h , 1.0/3 )*( - sin(x) + sin(y) - sin(z) )/2		;
}


float Ey()
{
 return getmaxy()/2 - pow( l*l+b*b+h*h , 1.0/3 )*( - sin(x) - sin(y) + sin(z) )/2		;
}


float Fy()
{
 return getmaxy()/2 - pow( l*l+b*b+h*h , 1.0/3 )*( + sin(x) - sin(y) + sin(z) )/2		;
}


float Gy()
{
 return getmaxy()/2 - pow( l*l+b*b+h*h , 1.0/3 )*( + sin(x) + sin(y) + sin(z) )/2		;
}


float Hy()
{
 return getmaxy()/2 - pow( l*l+b*b+h*h , 1.0/3 )*( - sin(x) + sin(y) + sin(z) )/2		;
}