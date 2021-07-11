#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>


void Enter()        ;
void Check() 	    ;
void StraightLine() ;
void Circle()       ;
void Ellipse()      ;
void Parabola()     ;
void Hyperbola()    ;
void Square()       ;
void Rectangle()    ;
void Triangle()     ;
void ComeToOrigin() ;
void Axis()         ;
void GM()           ;
int  Again()        ;


int op,op1,op2,x,y,gd=0,gm,n ;
float p[7],fx,&fy=fx         ;


void main()
{
 clrscr()	    ;
 Again  	    :
 Enter()	    ;
 Check()  	    ;
 if( op1>8||op1<1 )
	{
	 goto Again ;
	}
 getch()            ;
 cleardevice()      ;
 closegraph()	    ;
 restorecrtmode()   ;
 if( Again() )
	{
	 goto Again ;
	}
}


int Again()
{
 clrscr() 		      ;
 Again 			      :
 cout<<"\nDo you want more ?"
     <<"\n\n\t1.Yes\t2.No"
     <<"\n\n\tOption : "      ;
 cin >>op2		      ;
 clrscr()                     ;
 switch( op2 )
	{
	 case 1  : return 1   ;
	 case 2  : return 0   ;
	 default : clrscr()   ;
		   goto Again ;
	}

}


void Enter()
{
 cout<<"\nWhich fo the following Graph you want ?"
     <<"\n\n\t1.Straight Line\t\t2.Circle   \t\t3.Ellipse"
     <<"\n  \t4.Parabola     \t\t5.Hyperbola\t\t6.Square"
     <<"\n  \t7.Rectangle    \t\t8.Triangle"
     <<"\n\n\n\tOption : "                                         ;
 cin >>op1                                                         ;
 clrscr()                                                          ;
}


void Check()
{
 switch( op1 )
	{
	 case 1 : StraightLine()			 ;
		  break         			 ;
	 case 2 : Circle()      			 ;
		  break         			 ;
	 case 3 : Ellipse()     			 ;
		  break         			 ;
	 case 4 : Parabola()    			 ;
		  break          			 ;
	 case 5 : Hyperbola()    			 ;
		  break          			 ;
	 case 6 : Square()       			 ;
		  break          			 ;
	 case 7 : Rectangle()    			 ;
		  break          		       	 ;
	 case 8 : Triangle()     			 ;
		  break          			 ;
	 default: cout<<"Please Enter a Valid Option ! " ;
		  getch()                                ;
		  clrscr()                               ;
	}
}


void Axis()
{
 setbkcolor(WHITE)			          ;
 settextstyle(7,0,4)                              ;
 setcolor(RED)                                    ;
 settextstyle(1,0,1)                              ;
 for(int i=0 ; i<getmaxx()&&i<getmaxy() ; i+=10 )
	{
	 if( (i/10)%2 == 0 )
		{
		 sound( 100+10+i )		  ;
		}
	 else
		{
		 sound( 100-10+i )		  ;
		}
	 ComeToOrigin()                           ;
	 outtextxy(getx()+i-4,gety()-12,"+")      ;
	 delay(20)                                ;
	 ComeToOrigin()                           ;
	 outtextxy(getx()-4,gety()-i-12,"+") 	  ;
	 delay(20)                                ;
	 ComeToOrigin()                           ;
	 outtextxy(getx()-i-4,gety()-12,"+") 	  ;
	 delay(20)                                ;
	 ComeToOrigin()                           ;
	 outtextxy(getx()-4,gety()+i-12,"+") 	  ;
	 delay(20)                                ;
	}
 settextstyle(7,0,4)                              ;
 outtextxy(10,5,"Axes")                           ;
 settextstyle(1,0,2)                              ;
 outtextxy(450,420,"Scale : 10 Pixel")            ;
 rectangle( 0 , 0 , getmaxx() , getmaxy() ) 	  ;
 nosound()					  ;
 delay(1000)                                      ;
}


void ComeToOrigin()
{
 moveto(getmaxx()/2,getmaxy()/2) 		  ;
}


void GM()
{
 clrscr()                                         ;
 initgraph(&gd,&gm,"C:\\TurboC3\\BGI\\") 	  ;
}


void StraightLine()
{
 cout<<"Enter the value of 'c'      : "                   ;
 cin >>p[1]                              		  ;
 cout<<"Enter the value of Slope(m) : "        		  ;
 cin >>p[2]                              		  ;
 GM()                                       		  ;
 Axis()                                     		  ;
 setcolor(BLUE) 			    		  ;
 settextstyle(7,0,4)			    		  ;
 outtextxy(10,35,"Line") 		    		  ;
 if(p[2]<1)
	{
	 for( x=0 ; x<getmaxx() ; x++ )
		{
		 ComeToOrigin() 	    		  ;
		 moverel(x,-(p[2]*x+p[1])) 	          ;
		 putpixel(getx(),gety(),BLUE)		  ;
		 ComeToOrigin() 	     		  ;
		 moverel(-x,-(p[2]*(-x)+p[1]))            ;
		 putpixel(getx(),gety(),BLUE)		  ;
		 delay(10) 		    		  ;
		}
	}
 if(p[2]>=1)
	{
	 for( y=0 ; y<getmaxy() ; y++ )
		{
		 ComeToOrigin() 	    		  ;
		 moverel((y-p[1])/p[2],-y) 	  	  ;
		 putpixel(getx(),gety(),BLUE)		  ;
		 ComeToOrigin() 	    		  ;
		 moverel((-y-p[1])/p[2],y)         	  ;
		 putpixel(getx(),gety(),BLUE)	       	  ;
		 delay(10) 		    		  ;
		}
	}
}

void Circle()
{
 cout<<"Enter the x-Coordinate(x) of The Circle : " 		     ;
 cin >>p[1] 					    		     ;
 cout<<"Enter the y-Coordinate(y) of The Circle : "    		     ;
 cin >>p[2] 					    		     ;
 cout<<"Enter the Radius      (r) of The Circle : " 		     ;
 cin >>p[3] 					   		     ;
 GM() 								     ;
 Axis()								     ;
 setcolor(BLUE) 						     ;
 settextstyle(7,0,4)					       	     ;
 outtextxy(10,35,"Circle")			    		     ;
 putpixel( getmaxx()/2 + p[1] , getmaxy()/2 - p[2] , BLUE ) 	     ;
 for( fx=0 ; fx<=360 ; fx+=0.1 )

	{
	 putpixel( getmaxx() / 2 + p[1] + p[3] * cos ( fx*M_PI/180 ) ,
		   getmaxy() / 2 - p[2] - p[3] * sin ( fx*M_PI/180 ) ,
		   BLUE                                            ) ;
	 delay(1) 						     ;
	}
}


void Ellipse()
{
 cout<<"Enter the x-Coordinate               (x) of The Ellipse : " ;
 cin >>p[1] 							    ;
 cout<<"Enter the y-Coordinate               (y) of The Ellipse : " ;
 cin >>p[2]							    ;
 cout<<"Enter the Length of Semi-Major  Axis (a) of The Ellipse : " ;
 cin >>p[3]							    ;
 cout<<"Enter the Length of Semi-Minor  Axis (b) of The Ellipse : " ;
 cin >>p[4]							    ;
 GM()								    ;
 Axis()								    ;
 setcolor(BLUE)							    ;
 settextstyle(7,0,4)						    ;
 outtextxy(10,35,"Ellipse")					    ;
 putpixel( getmaxx()/2+p[1] , getmaxy()/2-p[2] , BLUE       )	    ;
 for( fx=0 ; fx<=360 ; fx+=0.1)
	{
	 putpixel( getmaxx()/2 + p[1] + p[3]*cos(fx*M_PI/180) 	    ,
		   getmaxy()/2 - p[2] - p[4]*sin(fx*M_PI/180) 	    ,
		   BLUE                                     ) 	    ;
	 delay   (1)						    ;
	}
}


void Square()
{
 cout<<"Enter x-Coordinate(x) of the Center of The Square : " 	    ;
 cin >>p[1] 							    ;
 cout<<"Enter y-Coordinate(y) of the Center of The Square : " 	    ;
 cin >>p[2] 							    ;
 cout<<"Enter the Length  (a) of the Sides  of The Square : "	    ;
 cin >>p[3]							    ;
 GM() 								    ;
 Axis() 							    ;
 setcolor(BLUE)							    ;
 settextstyle(7,0,4)						    ;
 outtextxy(10,35,"Square") 					    ;
 putpixel( getmaxx()/2+p[1] , getmaxy()/2-p[2] , BLUE 		  ) ;
 rectangle( getmaxx()/2 + p[1]-p[3]/2 , getmaxy()/2 - p[2]-p[3]/2   ,
	    getmaxx()/2 + p[1]+p[3]/2 , getmaxy()/2 - p[2]+p[3]/2 ) ;
}


void Rectangle()
{
 cout<<"Enter the x-Coordinate     (x) of the Center of The Rectangle : " ;
 cin >>p[1] 								  ;
 cout<<"Enter the y-Coordinate     (y) of the Center of The Rectangle : " ;
 cin >>p[2] 								  ;
 cout<<"Enter the Horizontal Length(l)               of The Rectangle : " ;
 cin >>p[3] 								  ;
 cout<<"Enter the Verticle   Length(b)               of The Rectangle : " ;
 cin >>p[4]								  ;
 GM() 									  ;
 Axis() 								  ;
 setcolor(BLUE) 							  ;
 settextstyle(7,0,4) 							  ;
 outtextxy(10,35,"Rectangle") 						  ;
 putpixel( getmaxx()/2+p[1] , getmaxy()/2-p[2] , BLUE 		      )   ;
 rectangle( getmaxx()/2 + p[1] - p[3]/2 , getmaxy()/2 - p[2] + p[4]/2     ,
	    getmaxx()/2 + p[1] + p[3]/2 , getmaxy()/2 - p[2] - p[4]/2 )   ;
}


void Parabola()
{
 cout<<"Enter the x-Coordinate(x) of the Center of The Parabola : "	  		;
 cin >>p[1]								  		;
 cout<<"Enter the y-Coordinate(y) of the Center of The Parabola : "	  		;
 cin >>p[2] 								  		;
 cout<<"Enter the Value           of 'a'        of The Parabola : " 	  		;
 cin >>p[3]								  		;
 Type									  		:
 cout<<"\n\nWhat Type of Parabola you want ?"
       "\n\t1.Along x-Axis\t\t2.Along y-Axis "
       "\n\n\tOption : "						  		;
 cin >>op								  		;
 GM()							  		  		;
 Axis() 						 		  		;
 setcolor(BLUE)								  		;
 settextstyle(7,0,4) 					 		  		;
 outtextxy(10,35,"Parabola") 						  		;
 putpixel( getmaxx()/2+p[1] , getmaxy()/2-p[2] , BLUE )			  		;
 if( p[3]<0 )
	{
	 p[4] = -1 							  		;
	 p[3] = -p[3]									;
	}
 else
	{
	 p[4] = 1                                                         		;
	}
 switch( op )
	{
	 case 1 : for( fx=0 ; fx<getmaxx() ; fx+=0.1 )
			{
			 putpixel( getmaxx()/2 + p[1] - p[4]*p[3] + p[4]*fx  		,
				   getmaxy()/2 - p[2] + sqrt( 4*p[3]*fx     ) 		,
				   BLUE                                     ) 		;
			 putpixel( getmaxx()/2 + p[1] - p[4]*p[3] + p[4]*fx  		,
				   getmaxy()/2 - p[2] - sqrt( 4*p[3]*fx     ) 		,
				   BLUE                                     ) 		;
			 delay(1)                                         		;
			}
		  break							  		;
	 case 2 : for( fy=0 ; fy<getmaxy() ; fy+=0.1 )
			{
			 putpixel( getmaxx()/2 + p[1] + sqrt( 4*p[3]*fy     ) 		,
				   getmaxy()/2 - p[2] + p[4]*p[3] - p[4]*fy          	,
				   BLUE                                     ) 		;
			 putpixel( getmaxx()/2 + p[1] - sqrt( 4*p[3]*fy     ) 		,
				   getmaxy()/2 - p[2] + p[4]*p[3] - p[4]*fy          	,
				   BLUE                                     ) 		;
			 delay(1)                                         		;
			}
		  break 						  		;
	 default: cout<<"Please Enter a Valid Option !" 		  		;
		  clrscr() 						  		;
		  getch() 						  		;
		  goto Type 						  		;
	}
}


void Hyperbola()
{
 cout<<"Enter the x-Coordinate(x) of the Center of The Hyperbola : " 			   ;
 cin >>p[1] 									       	   ;
 cout<<"Enter the y-Coordinate(y) of the Center of The Hyperbola : " 			   ;
 cin >>p[2] 										   ;
 cout<<"Enter the Value           of 'a'        of The Hyperbola : " 			   ;
 cin >>p[3] 										   ;
 cout<<"Enter the Value           of 'b'        of The Hyperbola : " 			   ;
 cin >>p[4] 										   ;
 Type 											   :
 cout<<"\n\nWhat Type of Hyperbola you want ?"
       "\n\t1.Along x-Axis\t\t2.Along y-Axis "
       "\n\n\tOption : " 								   ;
 cin >>op 										   ;
 GM() 											   ;
 Axis()											   ;
 setcolor(BLUE)										   ;
 settextstyle(7,0,4) 									   ;
 outtextxy(10,35,"Hyperbola") 								   ;
 putpixel( getmaxx()/2+p[1] , getmaxy()/2-p[2] , BLUE )					   ;
 switch( op )
	{
	 case  1 : for( fx=p[3] ; fx<getmaxx() ; fx+=0.1 )
			{
			 putpixel( getmaxx()/2 + p[1] + fx 				   ,
				   getmaxy()/2 - p[2] - p[4]*sqrt(((fx*fx)/(p[3]*p[3]))-1) ,
				   BLUE                                                  ) ;
			 putpixel( getmaxx()/2 + p[1] + fx 				   ,
				   getmaxy()/2 - p[2] + p[4]*sqrt(((fx*fx)/(p[3]*p[3]))-1) ,
				   BLUE                                                  ) ;
			 putpixel( getmaxx()/2 + p[1] - fx 				   ,
				   getmaxy()/2 - p[2] - p[4]*sqrt(((fx*fx)/(p[3]*p[3]))-1) ,
				   BLUE                                                  ) ;
			 putpixel( getmaxx()/2 + p[1] - fx 				   ,
				   getmaxy()/2 - p[2] + p[4]*sqrt(((fx*fx)/(p[3]*p[3]))-1) ,
				   BLUE                                                  ) ;
			 delay(1) 							   ;
			}
		   break								   ;
	 case  2 : for( fy=p[3] ; fy<getmaxx() ; fy+=0.1 )
			{
			 putpixel( getmaxx()/2 + p[1] + p[4]*sqrt(((fy*fy)/(p[3]*p[3]))-1) ,
				   getmaxy()/2 - p[2] - fy                                 ,
				   BLUE                                                  ) ;
			 putpixel( getmaxx()/2 + p[1] + p[4]*sqrt(((fy*fy)/(p[3]*p[3]))-1) ,
				   getmaxy()/2 - p[2] + fy                                 ,
				   BLUE                                                  ) ;
			 putpixel( getmaxx()/2 + p[1] - p[4]*sqrt(((fy*fy)/(p[3]*p[3]))-1) ,
				   getmaxy()/2 - p[2] - fy                                 ,
				   BLUE                                                  ) ;
			 putpixel( getmaxx()/2 + p[1] - p[4]*sqrt(((fy*fy)/(p[3]*p[3]))-1) ,
				   getmaxy()/2 - p[2] + fy                                 ,
				   BLUE                                                  ) ;
			 delay(1)							   ;
			}
		   break 								   ;
	 default : cout<<"Please Enter a Valid Option !" 				   ;
		   clrscr() 								   ;
		   getch() 								   ;
		   goto Type 								   ;
	}
}


void Triangle()
{
 cout<<"Enter the x-Coordinate(x1) of the First  Point of The Triangle : " 	     ;
 cin >>p[1] 									     ;
 cout<<"Enter the y-Coordinate(y1) of the First  Point of The Triangle : " 	     ;
 cin >>p[2] 									     ;
 cout<<"Enter the x-Coordinate(x2) of the Second Point of The Triangle : " 	     ;
 cin >>p[3] 									     ;
 cout<<"Enter the y-Coordinate(y2) of the Second Point of The Triangle : " 	     ;
 cin >>p[4] 									     ;
 cout<<"Enter the x-Coordinate(x3) of the Third  Point of The Triangle : " 	     ;
 cin >>p[5] 									     ;
 cout<<"Enter the y-Coordinate(y3) of the Third  Point of The Triangle : " 	     ;
 cin >>p[6] 									     ;
 GM() 										     ;
 Axis() 									     ;
 setcolor(BLUE) 								     ;
 settextstyle(7,0,4) 								     ;
 outtextxy(10,35,"Triangle") 							     ;
 putpixel( getmaxx()/2+(p[1]+p[3]+p[5])/3  , getmaxy()/2-(p[2]+p[4]+p[6])/3 , BLUE ) ;
 line( getmaxx()/2+p[1] , getmaxy()/2-p[2] , getmaxx()/2+p[3] , getmaxy()/2-p[4]   ) ;
 line( getmaxx()/2+p[3] , getmaxy()/2-p[4] , getmaxx()/2+p[5] , getmaxy()/2-p[6]   ) ;
 line( getmaxx()/2+p[5] , getmaxy()/2-p[6] , getmaxx()/2+p[1] , getmaxy()/2-p[2]   ) ;
}