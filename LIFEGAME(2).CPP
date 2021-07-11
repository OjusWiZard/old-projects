/*
  This is the Game of Life. The first developer of this mysterious program was a Mathematician - John Conway.
  I've remade this program in C++. :)
  It have an infinitely large 2 Dimentional grid with either living(white) or non living(black) cells.
  Since, we can't support infinite resolution, so i made it like a grid as in the Snake game. Where the top is joined to bottom and left is joined to right.
  The grid is continuously updated, where the next grid depends upon the previous one.
  Rules:-
  1. If the cell is surrounded by 2 or 3 cells, then it survives.
  2. If the cell is dead, but is surrounded by 3 cells, then it is borned.
  3. It dies in all other cases.

  Some Scientists believe that this pattern is found in the life too.
  If someone is surrounded by too many people(>3), then it dies because of over-population.
  If someone is surrounded by less people(<2), then it dies because of too less population.
  uh... no need to relate....other rules with real life.......
*/

#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>

#define Size 120

void	Initialize()			;
void	LifeGame()				;
int 	Status( int , int )		;

int life[Size][Size], n			;

void main()
{
 clrscr()		;
 Initialize()	;
 LifeGame()		;
 getch()		;
 closegraph()	;
}

void LifeGame()
{
 int tlife[Size][Size], a, b, mx, my	;
 mx = getmaxx()/Size	;
 my = getmaxy()/Size	;
 while( !kbhit() )
	{
	 for( b=0 ; b<Size ; b++ )
		{
		 for( a=0 ; a<Size ; a++ )
			{
			 if( life[a][b]==1 )
				{
				 switch( Status(a,b) )
					{
					 case 2  : tlife[a][b]=1	;	break	;
					 case 3  : tlife[a][b]=1	;	break	;
					 default : tlife[a][b]=0	;	break	;
					}
				}
			 else
				{
				 if( Status(a,b)==3 ) tlife[a][b]=1	;
				}
			}
		}
	 for( b=0 ; b<Size ; b++ )
		{
		 for( a=0 ; a<Size ; a++ )
			{
			 life[a][b] = tlife[a][b]			;

			 putpixel( 260+a , 180+b , 15*life[a][b] )	;  //<-- Either choose this one

			 //setfillstyle( 1 , 15*life[a][b] )	;      //<-- or choose these two.
			 //bar( a*mx , b*my , (a+1)*mx , (b+1)*my )	;  //<-- (putpixel) will show small but fast and (setfillstyle & bar) will show big but slow.

			}
		}
	}
}

int Status( int x , int y )
{
 n=0	;

 if( x==0 )
	{
	 if( y==0 )
		{
		 if( life[Size-1][Size-1] == 1 )	n++	;
		 if( life[Size-1][y     ] == 1 )	n++	;
		 if( life[Size-1][y+1   ] == 1 )	n++	;
		 if( life[x     ][Size-1] == 1 )	n++	;
		 if( life[x     ][y+1   ] == 1 )	n++	;
		 if( life[x+1   ][Size-1] == 1 )	n++	;
		 if( life[x+1   ][y     ] == 1 )	n++	;
		 if( life[x+1   ][y+1   ] == 1 )	n++	;
		}
	 else if( y==Size )
		{
		 if( life[Size-1][y-1   ] == 1 )	n++	;
		 if( life[Size-1][y     ] == 1 )	n++	;
		 if( life[Size-1][0     ] == 1 )	n++	;
		 if( life[x     ][y-1   ] == 1 )	n++	;
		 if( life[x     ][0     ] == 1 )	n++	;
		 if( life[x+1   ][y-1   ] == 1 )	n++	;
		 if( life[x+1   ][y     ] == 1 )	n++	;
		 if( life[x+1   ][0     ] == 1 )	n++	;
		}
	 else
		{
		 if( life[Size-1][y-1   ] == 1 )	n++	;
		 if( life[Size-1][y     ] == 1 )	n++	;
		 if( life[Size-1][y+1   ] == 1 )	n++	;
		 if( life[x     ][y-1   ] == 1 )	n++	;
		 if( life[x     ][y+1   ] == 1 )	n++	;
		 if( life[x+1   ][y-1   ] == 1 )	n++	;
		 if( life[x+1   ][y     ] == 1 )	n++	;
		 if( life[x+1   ][y+1   ] == 1 )	n++	;
		}
	}
 else if( x==Size )
	{
	 if( y==0 )
		{
		 if( life[x-1   ][Size-1] == 1 )	n++	;
		 if( life[x-1   ][y     ] == 1 )	n++	;
		 if( life[x-1   ][y+1   ] == 1 )	n++	;
		 if( life[x     ][Size-1] == 1 )	n++	;
		 if( life[x     ][y+1   ] == 1 )	n++	;
		 if( life[0     ][Size-1] == 1 )	n++	;
		 if( life[0     ][y     ] == 1 )	n++	;
		 if( life[0     ][y+1   ] == 1 )	n++	;
		}
	 else if( y==Size )
		{
		 if( life[x-1   ][y-1   ] == 1 )	n++	;
		 if( life[x-1   ][y     ] == 1 )	n++	;
		 if( life[x-1   ][0     ] == 1 )	n++	;
		 if( life[x     ][y-1   ] == 1 )	n++	;
		 if( life[x     ][0     ] == 1 )	n++	;
		 if( life[0     ][y-1   ] == 1 )	n++	;
		 if( life[0     ][y     ] == 1 )	n++	;
		 if( life[0     ][0     ] == 1 )	n++	;
		}
	 else
		{
		 if( life[x-1   ][y-1   ] == 1 )	n++	;
		 if( life[x-1   ][y     ] == 1 )	n++	;
		 if( life[x-1   ][y+1   ] == 1 )	n++	;
		 if( life[x     ][y-1   ] == 1 )	n++	;
		 if( life[x     ][y+1   ] == 1 )	n++	;
		 if( life[0     ][y-1   ] == 1 )	n++	;
		 if( life[0     ][y     ] == 1 )	n++	;
		 if( life[0     ][y+1   ] == 1 )	n++	;
		}
	}
 else
	{
	 if( life[x-1   ][y-1   ] == 1 )	n++	;
	 if( life[x-1   ][y     ] == 1 )	n++	;
	 if( life[x-1   ][y+1   ] == 1 )	n++	;
	 if( life[x     ][y-1   ] == 1 )	n++	;
	 if( life[x     ][y+1   ] == 1 )	n++	;
	 if( life[x+1   ][y-1   ] == 1 )	n++	;
	 if( life[x+1   ][y     ] == 1 )	n++	;
	 if( life[x+1   ][y+1   ] == 1 )	n++	;
	}

 return n	;
}

void Initialize()
{
 int gd=VGA, gm=VGAHI, i, j	;
 initgraph( &gd , &gm , "C:\\TurboC3\\BGI\\" )	;
 setbkcolor( BLACK )	;
 setfillstyle( 1 , 15 )	;
 randomize()	;
 for( j=0 ; j<Size ; j++ )
	{
	 for( i=0 ; i<Size ; i++ )
		{
		 life[i][j] = random(2)	;
		}
	}
}

/*
  The small clusters formed in the grid are also related to life...
  Like Races, Places, Families, etc.
*/