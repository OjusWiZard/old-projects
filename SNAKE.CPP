#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>

#define MAXX 32
#define MAXY 22

#define DIFICULTYPERCENTAGE 100

void Initialize() ;
void Game() ;
void UpdateScreen() ;
void Score() ;
void Framing() ;

void main()
{
 clrscr() ;
 Initialize() ;
 Framing() ;
 Game() ;
 cleardevice() ;
 closegraph() ;
}

void Initialize()
{
 int gd=DETECT, gm								;
 initgraph( &gd , &gm , "C://TurboC3//BGI" )	;
 setbkcolor( BLACK )							;
 setcolor  ( WHITE )							;
}

void Framing()
{
 rectangle( 0, 0, getmaxx()-1, getmaxy()-1 ) ;
 line( 0, getmaxx()/20, getmaxx()-2, getmaxx()/20 ) ;
 setcolor( YELLOW )	;
 settextstyle( 0, 0, 3 )	;
 outtextxy( 255, 5, "Score:" ) ;
}


void Game()
{
 enum dir
	{
	 left='a', up='w', right='d', down='s'
	};
 int foodx, foody, grid[MAXY][MAXX], size=1, headx, heady, i, j ;
 float mx=getmaxx()-2, my=19*getmaxy()/20-9 ;
 char in=up, prev, score[4] ; ;
 for( i=0 ; i<MAXX ; i++ )
	{
	 for( j=0 ; j<MAXY ; j++ )
		{
		 grid[j][i]=0 ;
		}
	}
 randomize() ;
 foodx=random(MAXX) ;
 randomize() ;
 foody=random(MAXY) ;
 randomize() ;
 headx=random(MAXX) ;
 randomize() ;
 heady=random(MAXY) ;
 grid[heady][headx]=1 ;
 while( in!=27 )
	{
	 if(kbhit())	in=getch() ;
	 Again:
	 if( in==left && prev==right || in==up    && prev==down ||
		 in==down && prev==up    || in==right && prev==left  )	in=prev ;
	 switch( in )
		{
		 case left : if(headx==0)
						{
						 if( grid[heady][MAXX-1] != 0 )	in = 27 ;
						 else headx=MAXX-1;
						}
					 else if( grid[heady][--headx] != 0 ) in = 27 ;
					 break ;
		 case right: if(headx==MAXX-1)
						{
						 if( grid[heady][0] != 0 ) in=27 ;
						 else headx=0 	;
						}
					 else if( grid[heady][++headx] != 0 ) in=27 ;
					 break ;
		 case up   : if(heady==0)
						{
						 if( grid[MAXY-1][headx] != 0 ) in = 27 ;
						 else heady=MAXY-1 ;
						}
					 else if( grid[--heady][headx] != 0 ) in = 27 ;
					 break ;
		 case down : if(heady==MAXY-1)
						{
						 if( grid[0][headx] != 0 ) in = 27 ;
						 else heady=0 ;
						}
					 else if( grid[++heady][headx] !=0 ) in = 27 ;
					 break ;
		 case 27   : 									break ;
		 default   : in = prev ;        goto Again	;
		}
	 prev = in ;
	 grid[heady][headx]=size+1 ;
	 if( headx==foodx && heady==foody )
		{
		 randomize() ;
		 do
			{
			 foodx= random(MAXX) ;
			 foody= random(MAXY) ;
			}
		 while( grid[foody][foodx]!=0 ) ;
		 size++ ;
		 setfillstyle( SOLID_FILL, BLACK) ;
		 bar( 395, 2, 495, 29) ;
		 moveto( 400, 5) ;
		 outtext( itoa( size, score, 10)) ;
		 sound( (size+1)*20 ) ;
		}
	 for( j=0 ; j<MAXY ; j++ )
		{
		 for( i=0 ; i<MAXX ; i++ )
			{
			 if( grid[j][i]>0 )
				{
				 grid[j][i]--;
				 if( i==headx && j==heady )	setfillstyle( SOLID_FILL, YELLOW ) ;
				 else						setfillstyle( SOLID_FILL, GREEN ) ;
				}
			 else				 	setfillstyle( SOLID_FILL, BLACK ) ;
			 if(j==foody&&i==foodx) setfillstyle( SOLID_FILL, RED	) ;
			 bar( 1+i*mx/MAXX, 32+j*my/MAXY, (i+1)*mx/MAXX, 32+(j+1)*my/MAXY-1 ) ;
			}
		}
	 nosound() ;
	 delay( (100-DIFICULTYPERCENTAGE)*10 )	;
	}
 while( getch()!=27 )	;
}