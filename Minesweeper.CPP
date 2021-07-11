







/*          	Use Arrow Keys to Move your Cursor.							*/
/*				Press Z to declare your position a BOMB  ...				*/
/*				Press X to declare your position a Number...				*/
/*				Stop Reading and COMPILE IT !                               */









#include <fstream.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>


#define XM   79
#define YM   19
#define EASE 100


void Frame()					;
void Update()					;
int  Check( int x , int y )		;
void Game()						;
int  Win()						;


int p[XM][YM], q[XM][YM], i, j, n, temp1, nb, hs	;
float tm	;
char temp[1]	;
ifstream	in	;


void main()
{
 clrscr()	;
 Frame()	;
 Game()		;
}


void Frame()
{
 in.open( "HS.OJ" , ios::in )	;
 in>>hs	;

 for( i=1 ; i<XM-1 ; i+=2 )
	{
	 for( j=1 ; j<YM-1 ; j+=2 )
		{
		 p[i][j] = 32	;
		}
	}

 p[0   ][0   ] = 201	;
 p[0   ][YM-1] = 200	;
 p[XM-1][0   ] = 187	;
 p[XM-1][YM-1] = 188	;

 for( i=2 ; i<XM-2 ; i+=2 )
	{
	 p[i][0   ] = 209	;
	 p[i][YM-1] = 207	;
	}

 for( j=2 ; j<YM-2 ; j+=2 )
	{
	 p[0   ][j] = 199	;
	 p[XM-1][j] = 182	;
	}

 for( i=1 ; i<XM-1 ; i+=2 )
	{
	 for( j=2 ; j<YM-2 ; j+=2 )
		{
		 p[i][j] = 196	;
		}
	}

 for( j=1 ; j<YM-1 ; j+=2 )
	{
	 for( i=2 ; i<XM-2 ; i+=2 )
		{
		 p[i][j] = 179	;
		}
	}

 for( i=1 ; i<XM-1 ; i+=2 )
	{
	 p[i][0   ] = 205	;
	 p[i][YM-1] = 205	;
	}

 for( j=1 ; j<YM-1 ; j+=2 )
	{
	 p[0   ][j] = 186	;
	 p[XM-1][j] = 186	;
	}

 for( i=2 ; i<XM-1 ; i+=2 )
	{
	 for( j=2 ; j<YM-2 ; j+=2 )
		{
		 p[i][j] = 197	;
		}
	}

 for( i=0 ; i<XM ; i++ )
	{
	 for( j=0 ; j<YM ; j++ )
		{
		 gotoxy( i+1 , j+4 )	;
		 cout<<(char)p[i][j]	;
		}
	}

 randomize()	;
 for( i=1 ; i<XM-1 ; i+=2 )
	{
	 for( j=1 ; j<YM-1 ; j+=2 )
		{
		 if( !random(EASE) )
			{
			 q[i][j] = -1	;
			 nb++	;
			}
		}
	}

 for( i=1 ; i<XM-1 ; i+=2 )
	{
	 for( j=1 ; j<YM-1 ; j+=2 )
		{
		 if( Check( i , j ) == 0 && q[i][j] != -1 )
			{
			 p[i  ][j  ] = 177	;
			 if( p[i-2][j-2] !=177 ) p[i-2][j-2] = Check( i-2 , j-2 )	;
			 if( p[i  ][j-2] !=177 ) p[i  ][j-2] = Check( i   , j-2 )	;
			 if( p[i+2][j-2] !=177 ) p[i+2][j-2] = Check( i+2 , j-2 )	;
			 if( p[i-2][j  ] !=177 ) p[i-2][j  ] = Check( i-2 , j   )	;
			 if( p[i+2][j  ] !=177 ) p[i+2][j  ] = Check( i+2 , j   )	;
			 if( p[i-2][j+2] !=177 ) p[i-2][j+2] = Check( i-2 , j+2 )	;
			 if( p[i  ][j+2] !=177 ) p[i  ][j+2] = Check( i   , j+2 )	;
			 if( p[i+2][j+2] !=177 ) p[i+2][j+2] = Check( i+2 , j+2 )	;
			}
		}
	}
}


int Check( int x , int y )
{
 n=0	;
 if( x==1 && y==1 )
	{
	 if( q[x  ][y+2] == -1 ) n++	;
	 if( q[x+2][y+2] == -1 ) n++	;
	 if( q[x+2][y  ] == -1 ) n++	;
	}
 else if( x==1 && y==YM-2 )
	{
	 if( q[x+2][y-2] == -1 ) n++	;
	 if( q[x+2][y  ] == -1 ) n++	;
	 if( q[x  ][y-2] == -1 ) n++	;
	}
 else if( x==XM-2 && y==1 )
	{
	 if( q[x-2][y  ] == -1 ) n++	;
	 if( q[x-2][y+2] == -1 ) n++	;
	 if( q[x  ][y+2] == -1 ) n++	;
	}
 else if( x==XM-2 && y==YM-2 )
	{
	 if( q[x-2][y-2] == -1 ) n++	;
	 if( q[x-2][y  ] == -1 ) n++	;
	 if( q[x  ][y-2] == -1 ) n++	;
	}

 else if( x==1 )
	{
	 if( q[x  ][y-2] == -1 ) n++	;
	 if( q[x  ][y+2] == -1 ) n++	;
	 if( q[x+2][y-2] == -1 ) n++	;
	 if( q[x+2][y  ] == -1 ) n++	;
	 if( q[x+2][y+2] == -1 ) n++	;
	}
 else if( x==XM-2 )
	{
	 if( q[x  ][y+2] == -1 ) n++	;
	 if( q[x  ][y-2] == -1 ) n++	;
	 if( q[x-2][y-2] == -1 ) n++	;
	 if( q[x-2][y  ] == -1 ) n++	;
	 if( q[x-2][y+2] == -1 ) n++	;
	}
 else if( y==1 )
	{
	 if( q[x-2][y  ] == -1 ) n++	;
	 if( q[x+2][y  ] == -1 ) n++	;
	 if( q[x-2][y+2] == -1 ) n++	;
	 if( q[x  ][y+2] == -1 ) n++	;
	 if( q[x+2][y+2] == -1 ) n++	;
	}
 else if( y==YM-2 )
	{
	 if( q[x-2][y  ] == -1 ) n++	;
	 if( q[x+2][y  ] == -1 ) n++	;
	 if( q[x-2][y-2] == -1 ) n++	;
	 if( q[x  ][y-2] == -1 ) n++	;
	 if( q[x+2][y-2] == -1 ) n++	;
	}

 else if( x>2 && x<XM-3 )
	{
	 if( q[x-2][y-2] == -1 ) n++	;
	 if( q[x-2][y  ] == -1 ) n++	;
	 if( q[x-2][y+2] == -1 ) n++	;
	 if( q[x  ][y-2] == -1 ) n++	;
	 if( q[x  ][y+2] == -1 ) n++	;
	 if( q[x+2][y-2] == -1 ) n++	;
	 if( q[x+2][y  ] == -1 ) n++	;
	 if( q[x+2][y+2] == -1 ) n++	;
	}

 return n	;
}


void Update()
{
 for( i=1 ; i<XM-1 ; i+=2 )
	{
	 for( j=1 ; j<YM-1 ; j+=2 )
		{
		 gotoxy( i+1 , j+4 )		;
		 if( i%2 && j%2 && p[i][j]>=0 && p[i][j]<9 )
			{
			 textbackground( BLACK )	;
			 switch( p[i][j] )
				{
				 case 1 : textcolor( WHITE 		  )	;	break	;
				 case 2 : textcolor( YELLOW		  )	;   break	;
				 case 3 : textcolor( CYAN  		  )	;   break	;
				 case 4 : textcolor( LIGHTBLUE    )	;   break	;
				 case 5 : textcolor( LIGHTGREEN   )	;   break	;
				 case 6 : textcolor( LIGHTRED	  )	;   break	;
				 case 7 : textcolor( LIGHTMAGENTA )	;   break	;
				 case 8 : textcolor( LIGHTGRAY    )	;   break	;
				}
			 cprintf( (char*)itoa( p[i][j] , temp , 10 ) )	;
			}
		 else
			{
			 switch( p[i][j] )
				{
				 case 32  : textbackground( BLACK )	;
							break					;
				 case 127 : textcolor	  ( RED   )	;
							textbackground( GREEN ) ;
							break					;
				 case 177 : textcolor	  ( WHITE )	;
							textbackground( BLACK )	;
							break					;
				}
			 cprintf( (char*)&(char)p[i][j] )		;
			}
		}
	}
 gotoxy( 32 , 23 )	;
 cout<<"Time Elapsed : "<<(int)tm				;
 gotoxy( 32 , 24 )	;
 cout<<"Best Score   : "<<hs					;
}


void Game()
{
 int in,a=2,b=5, bomb, check, t1, t2, c, d	;
 while( in != 27 )
	{
	 if( Win() )
		{
		 gotoxy( 34 , 1 )	;
		 cout<<"You Won !!!"	;
		 sound( 500 )	;
		 delay( 50 )	;
		 sound( 800 )	;
		 if( (int)tm < hs  ||  hs == 0 )
			{
			 ofstream o 	;
			 o.open( "HS.OJ" , ios::out )	;
			 o<<(int)tm	;
			 o.close()	;
			}
		 delay( 500 )	;
		 nosound()	;
		 getch()	;
		 goto End	;
		}
	 Update()	;
	 gotoxy( a , b )	;
	 t1 = a	;
	 t2 = b	;
	 while( !kbhit() )
		{
		 delay(1)		;
		 tm += 0.001	;
		}
	 in = getch()	;
	 switch( in )
		{
		 case 72  : if(b!=5	  ) b-=2	;	break	;
		 case 80  : if(b!=YM+2) b+=2	;	break	;
		 case 75  : if(a!=2   ) a-=2	;	break	;
		 case 77  : if(a!=XM-1) a+=2	;	break	;
		 case 122 : bomb = 1			;	break	;
		 case 120 : check = 1			;	break	;
		}
	 if( t1==a && t2==b )
		{
		 if( check == 1 )
			{
			 if( q[a-1][b-4] == -1 )
				{
				 sound( 700 )	;
				 gotoxy(30,1)	;
				 cout<<"You Pointed a BOMB !!!"	;
				 delay( 500 )	;
				 nosound()	;
				 textcolor( LIGHTRED + BLINK )	;
				 textbackground( BLACK )	;
				 temp1 = 234	;
				 for( c=1 ; c<XM-1 ; c+=2 )
					{
					 for( d=1 ; d<YM-1 ; d+=2 )
						{
						 if( q[c][d] == -1 )
							{
							 if( p[c][d] == 127 ) textbackground( GREEN )	;
							 else				  textbackground( BLACK )	;
							 gotoxy(c+1,d+4)    ;
							 cprintf( (char*)&(char)temp1 ) ;
							}
						}
					}
				 while( getch() != 27 )
					{
					 gotoxy( 30 , 25 )	;
					 cout<<"Press ESC to exit..."	;
					}
				 goto End	;
				}
			 else if( p[a-1][b-4] == 32 )
				{
				 p[a-1][b-4]=Check( a-1 , b-4 )				;
				}
			}
		 else if( bomb  == 1 && ( p[a-1][b-4] == 32 || p[a-1][b-4] == 127 ) )
			{
			 if( p[a-1][b-4] == 32 )
				{
				 p[a-1][b-4] = 127	;
				}
			 else
				{
				 p[a-1][b-4] = 32	;
				}
			}
		}
	 Update()			;
	 gotoxy( a , b )	;
	 check=0	;
	 bomb =0	;
	}
 End:
}

int Win()
{
 n=0	;
 for( i=1 ; i<XM-1 ; i+=2 )
	{
	 for( j=1 ; j<YM-1 ; j+=2 )
		{
		 if( q[i][j] == -1 && p[i][j] == 127 )
			{
			 n++	;
			}
		}
	}
 if(n==nb)	return 1	;
 else		return 0	;
}


/*						    That's All... Folks...							*/