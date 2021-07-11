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
#include <stdlib.h>
#include <graphics.h>
#include <dos.h>

#define Speed 100
#define xSize 60
#define ySize 60

void	Initialize()			;
void	LifeGame()				;
int 	Status( int , int )		;

int life[xSize][ySize], n			;

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
 int tlife[xSize][ySize], a, b, csx, csy	;
 csx = getmaxx()/xSize	;
 csy = getmaxy()/ySize	;
 while( !kbhit() )
	{
	 for( b=0 ; b<ySize ; b++ )
		{
		 for( a=0 ; a<xSize ; a++ )
			{
			 if( life[a][b]==1 )
				{
				 switch( Status(a,b) )
					{
					 case 2  : tlife[a][b]=1	;	break	;
					 case 3  : tlife[a][b]=1	;	break	;
					 default : tlife[a][b]=0	;
					}
				}
			 else
				{
				 if( Status(a,b)==3 ) tlife[a][b]=1	;
				}
			}
		}
	 delay( 1000 - Speed*10 )	;
	 for( b=0 ; b<ySize ; b++ )
		{
		 for( a=0 ; a<xSize ; a++ )
			{
			 life[a][b] = tlife[a][b]			;
			 //gotoxy(a+1,b+1)					;
			 switch( life[a][b] )
				{
				 case 0  : setfillstyle(1,8)	;	/*cout<<" "				;*/ break	;
				 case 1  : setfillstyle(1,15)	;/*cout<<char(219)		;*/     break	;
				}
			 bar( a*csx , b*csy , (a+1)*csx , (b+1)*csy )	;//gotoxy(80,b+1)						;
			 //cout<<" "							;
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
		 if( life[xSize-1][ySize-1] == 1 )	n++	;
		 if( life[xSize-1][y      ] == 1 )	n++	;
		 if( life[xSize-1][y+1    ] == 1 )	n++	;
		 if( life[x      ][ySize-1] == 1 )	n++	;
		 if( life[x      ][y+1    ] == 1 )	n++	;
		 if( life[x+1    ][ySize-1] == 1 )	n++	;
		 if( life[x+1    ][y      ] == 1 )	n++	;
		 if( life[x+1    ][y+1    ] == 1 )	n++	;
		}
	 else if( y==ySize-1 )
		{
		 if( life[xSize-1][y-1   ] == 1 )	n++	;
		 if( life[xSize-1][y     ] == 1 )	n++	;
		 if( life[xSize-1][0     ] == 1 )	n++	;
		 if( life[x      ][y-1   ] == 1 )	n++	;
		 if( life[x      ][0     ] == 1 )	n++	;
		 if( life[x+1    ][y-1   ] == 1 )	n++	;
		 if( life[x+1    ][y     ] == 1 )	n++	;
		 if( life[x+1    ][0     ] == 1 )	n++	;
		}
	 else
		{
		 if( life[xSize-1][y-1   ] == 1 )	n++	;
		 if( life[xSize-1][y     ] == 1 )	n++	;
		 if( life[xSize-1][y+1   ] == 1 )	n++	;
		 if( life[x      ][y-1   ] == 1 )	n++	;
		 if( life[x      ][y+1   ] == 1 )	n++	;
		 if( life[x+1    ][y-1   ] == 1 )	n++	;
		 if( life[x+1    ][y     ] == 1 )	n++	;
		 if( life[x+1    ][y+1   ] == 1 )	n++	;
		}
	}
 else if( x==xSize-1 )
	{
	 if( y==0 )
		{
		 if( life[x-1   ][ySize-1] == 1 )	n++	;
		 if( life[x-1   ][y      ] == 1 )	n++	;
		 if( life[x-1   ][y+1    ] == 1 )	n++	;
		 if( life[x     ][ySize-1] == 1 )	n++	;
		 if( life[x     ][y+1    ] == 1 )	n++	;
		 if( life[0     ][ySize-1] == 1 )	n++	;
		 if( life[0     ][y      ] == 1 )	n++	;
		 if( life[0     ][y+1    ] == 1 )	n++	;
		}
	 else if( y==ySize-1 )
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
 int i, j, gd=DETECT, gm	;
 initgraph( &gd , &gm , "C://TurboC3//BGI//" )	;
 setbkcolor( BLACK )	;
 randomize()	;
 for( j=0 ; j<ySize ; j++ )
	{
	 for( i=0 ; i<xSize ; i++ )
		{
		 life[i][j] = random(2)	;
		}
	}
}

/*
  The small clusters formed in the grid are also related to life...
  Like Races, Places, Families, etc.
*/