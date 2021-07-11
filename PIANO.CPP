#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>


void Piano(int) ;


void main()
{
 int i ;
 clrscr() ;
 cout<<"\t\t\tPiano For Alphabet Keys ! " ;
 delay(3000) ;
 clrscr() ;
 Again :
 i = getch() ;
 if( i == 13 )
	{
	 nosound() ;
	 exit(1) ;
	}
 else
	{
	 Piano(i) ;
	}
 goto Again ;
}


void Piano(int k)
	{
	 switch(k)
		{
		 case 122 : sound (100 + 36*0 ) ;         // z
			    break 		;
		 case 120 : sound (100 + 36*1 ) ;         // x
			    break 		;
		 case 99  : sound (100 + 36*2 ) ;         // c
			    break 		;
		 case 118 : sound (100 + 36*3 ) ;         // v
			    break 		;
		 case 98  : sound (100 + 36*4 ) ;         // b
			    break		;
		 case 110 : sound (100 + 36*5 ) ;         // n
			    break		;
		 case 109 : sound (100 + 36*6 ) ;         // m
			    break 		;
		 case 97  : sound (100 + 36*7 ) ;         // a
			    break 		;
		 case 115 : sound (100 + 36*8 ) ;         // s
			    break 		;
		 case 100 : sound (100 + 36*9 ) ;         // d
			    break 		;
		 case 102 : sound (100 + 36*10) ;         // f
			    break 		;
		 case 103 : sound (100 + 36*11) ;         // g
			    break 		;
		 case 104 : sound (100 + 36*12) ;         // h
			    break 		;
		 case 106 : sound (100 + 36*13) ;         // j
			    break 		;
		 case 107 : sound (100 + 36*14) ;         // k
			    break 		;
		 case 108 : sound (100 + 36*15) ;         // l
			    break 		;
		 case 113 : sound (100 + 36*16) ;         // q
			    break 		;
		 case 119 : sound (100 + 36*17) ;         // w
			    break 		;
		 case 101 : sound (100 + 36*18) ;         // e
			    break 		;
		 case 114 : sound (100 + 36*19) ;         // r
			    break 		;
		 case 116 : sound (100 + 36*20) ;         // t
			    break 		;
		 case 121 : sound (100 + 36*21) ;         // y
			    break 		;
		 case 117 : sound (100 + 36*22) ;         // u
			    break 		;
		 case 105 : sound (100 + 36*23) ;         // i
			    break 		;
		 case 111 : sound (100 + 36*24) ;         // o
			    break 		;
		 case 112 : sound (100 + 36*25) ;         // p
			    break 		;
		}
	}
