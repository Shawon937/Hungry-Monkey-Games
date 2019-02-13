# include "iGraphics.h"
#include<iostream>
#include<stdlib.h>
#include<exception>

 
/*
        function iDraw() is called again and again by the system.
*/

    

	int monkey_x=283,monkey_y=0;

	 int n = 1 , v =0 , len   ;   

	 int flaging = 0 ; 

	 /* the value of n controls the velocity of the falling objects in each levels */
	 /* v is a flag to detect the collision and change life / scores */
     
	 int HalfPeeled_x=rand()%630,HalfPeeled_y=601,       // initializations 
         Yellow_x=rand()%630,Yellow_y=601,               // of the co-ordinates
         Purple_x=rand()%630,Purple_y=601,               // of the falling
         Green_x=rand()%630, Green_y=601,                // objects 
         Tree_x=rand()%630,Tree_y=601,
         Bomb_x=rand()%630,Bomb_y=601;

	 char str1[100], str2[100],str3[100], str4[100],str5[100], str6[100],str7[100], str8[100] ;

	 int checking = 0 ; 


int score=0, life=5 , flag = 1 ;
int mainx=800, mainy=600;
int menu=1, count=0;
int mode , value = 0 ;

int n2 =0 ;  char ch2[1000] ;
int num=0 ;  char ch[1000] ;
int n1 =0 ;  char ch1[1000] ;

FILE *f1 ;
FILE *f2 ;
FILE *f3 ;
FILE *f4 ;
FILE *f5 ;
FILE *f6 ;
FILE *f7 ;
FILE *f8 ;
FILE *f9 ;
FILE *f10 ;
FILE *f11 ;
FILE *f12 ;
FILE *f13 ;
FILE *f14 ;
FILE *f15 ;
FILE *f16 ;
FILE *f17 ;
FILE *f18 ;
FILE *f19 ;
FILE *f20 ;
FILE *f21 ;
FILE *f22 ;
FILE *f23 ;
FILE *f24 ;
FILE *f25 ;
FILE *f26 ;

           /* count variable counts how many bananas including banana trees 
               are falling , after every five , 1 life point decreases */

void drawTextBox()
{ 
	iSetColor(150, 150, 150);         // function to draw rectangle where
	iRectangle(50, 345, 250, 30);     // player writes his/her name
}
 

//bananas
void BananaHalfPeeled()
{
 
        HalfPeeled_y-=4 * n ;
        if(HalfPeeled_y<=0)
        {
                HalfPeeled_x=rand()%630;
                HalfPeeled_y=601;
				count++ ;
			
        }
}

void BananaYellow()
{
 
        Yellow_y-=2 * n  ;
        if(Yellow_y<=0)
        {
                Yellow_x=rand()%630;
                Yellow_y=608 ;
				count++ ;
        } 
}

void BananaPurple()
{
 
        Purple_y-=2 * n ;
        if(Purple_y<=0)
        {
                Purple_x=rand()%630;
                Purple_y=615;
				count++ ;
	
        } 
}

void BananaGreen()
{
 
        Green_y-=-3 * n  ;
        if(Green_y<=0)
        {
                 Green_x=rand()%630;
                 Green_y=630;
				 count++ ;
		
        }
}

void BananaTree()
{
 
        Tree_y-=2 * n   ;
        if(Tree_y<=0)
        {
                Tree_x=rand()%630;
                Tree_y=1800;
				count++ ;
        }
}

void BOMB()
{
 
        Bomb_y-=3 * n   ;
        if(Bomb_y<=0)
        {
                Bomb_x=rand()%630;
                Bomb_y=601;
        }
}







//Point counting 
void pointcounting()
{

	 // half peeled bananas - increases score points

	if((monkey_x>=HalfPeeled_x && monkey_x<=HalfPeeled_x+32)||(monkey_x+32>=HalfPeeled_x && monkey_x+32<=HalfPeeled_x+32)){
			   if((HalfPeeled_y>=monkey_y && HalfPeeled_y<= monkey_y+98) || (HalfPeeled_y+32>=monkey_y && HalfPeeled_y<=monkey_y+98))
                {
				    	v=1 ;
                        HalfPeeled_y=601;
                        HalfPeeled_x=rand()%630;
                        if(v==1)score=score+1;  v = 0 ;     
                }
	}
	
	
	
	

	  // yellow bananas - increases score points

	if((monkey_x>=Yellow_x && monkey_x<=Yellow_x+32)||(monkey_x+32>=Yellow_x && monkey_x+32<=Yellow_x+32)){
			   if((Yellow_y>=monkey_y && Yellow_y<= monkey_y+98) || (Yellow_y+32>=monkey_y && Yellow_y<=monkey_y+98))
                {
				    	v=1 ;
                        Yellow_y=601;
                        Yellow_x=rand()%630;
                        if(v==1)score=score+1;  v = 0 ;     
                }
	}

	


        // purple bananas - increases score points

	

	if((monkey_x>=Purple_x && monkey_x<=Purple_x+32)||(monkey_x+32>=Purple_x && monkey_x+32<=Purple_x+32)){
			   if((Purple_y>=monkey_y && Purple_y<= monkey_y+98) || (Purple_y+32>=monkey_y && Purple_y<=monkey_y+98))
                {
				    	v=1 ;
                        Purple_y=601;
                        Purple_x=rand()%630;
                        if(v==1)score=score+1;  v = 0 ;     
                }
	}
	

	



	    // green bananas - increases score points

	if((monkey_x>=Green_x && monkey_x<=Green_x+32)||(monkey_x+32>=Green_x && monkey_x+32<=Green_x+32)){
			   if((Green_y>=monkey_y && Green_y<= monkey_y+98) || (Green_y+32>=monkey_y && Green_y<=monkey_y+98))
                {
				    	v=1 ;
                        Green_y=601;
                        Green_x=rand()%630;
                        if(v==1)score=score+1;  v = 0 ;     
                }
	}

	




	    // banana trees - increases life points

	
	if((monkey_x>= Tree_x && monkey_x<= Tree_x+32)||(monkey_x+32>= Tree_x && monkey_x+32<= Tree_x+32)){
			   if((Tree_y>=monkey_y && Tree_y<= monkey_y+98) || (Tree_y+32>=monkey_y && Tree_y<=monkey_y+98))
                {
				    	v=1 ;
                        Tree_y=601;
                        Tree_x=rand()%630;
                        if(v==1) life=life++;  v = 0 ;     
                }
	}





	  // bombs - decreases life points

	

	if((monkey_x>= Bomb_x && monkey_x<= Bomb_x+32)||(monkey_x+32>= Bomb_x && monkey_x+32<= Bomb_x+32)){
			   if((Bomb_y>=monkey_y && Bomb_y<= monkey_y+98) || (Bomb_y+32>=monkey_y && Bomb_y<=monkey_y+98))
                {
				    	v=1 ;
                        Bomb_y=601;
                        Bomb_x=rand()%630;
                        if(v==1) life=life--;  v = 0 ;     
                }
	}

	
	if(count==5)   /* after every 5 fallen bananas / trees , one life point is decreased */
	{
        life = life-- ;
		count = 0 ;
	}




			
}

void game_over()    /* GAME OVER FUNCTION */
{
//	if(life<=0) flaging = 1 ;

	if(life<=0)
	{
		

		iPauseTimer(0);
		iPauseTimer(1);    // pauses all the functions
		iPauseTimer(2);
		iPauseTimer(3);
		iPauseTimer(4);
		iPauseTimer(5);
		flag = 0 ;         // pauses the monkey
	// 	score = 0 ; 
		

	   	HalfPeeled_x=rand()%630, HalfPeeled_y=601,       
        Yellow_x=rand()%630,     Yellow_y=601,               
        Purple_x=rand()%630,     Purple_y=601,               // initials all the variables again
        Green_x=rand()%630,      Green_y=601,                
        Tree_x=rand()%630,       Tree_y=601,
        Bomb_x=rand()%630,       Bomb_y=601;
		

		iShowBMP(0,0,"gameover.bmp");            // the game over bmp file

	drawTextBox();  // calling the function to draw the rectangle inside which player writes name

	if(mode == 1)
	{
		iSetColor(255, 255, 255);  // shows the name typing in 
		iText(55, 355, str1);    
	}

	iSetColor(123, 111, 10);
	iText(50,380,"Enter your Name:",GLUT_BITMAP_HELVETICA_18);

	iText(10, 10, "Click to activate the box, enter to finish.");


	if(value == 1 )
	{
	    	iSetColor(248, 18, 104);
	        iText(50,220,"1st Highest Score Holder:",GLUT_BITMAP_HELVETICA_18);

			   
			    if((f5 = fopen ("PlayerHighest.txt", "r")) != NULL)
				{       fscanf (f5, "%[^\n]", str3);
                        iText(270, 220 , str3 , GLUT_BITMAP_HELVETICA_18) ;
						fclose (f5);
				}
				
		    iSetColor(248, 87, 18);
	        iText(460,220,"1st Highest Score:",GLUT_BITMAP_HELVETICA_18);

		     	
				if((f6 = fopen("ScoreHighest.txt", "r")) != NULL)
				{   int number=0;
                    fscanf(f6, "%d", &number);
					sprintf( str4, "%d", number); 
                    iText(633, 220 , str4 , GLUT_BITMAP_HELVETICA_18) ;
					fclose (f6);
				}

				iSetColor(248, 18, 104);
	        iText(50,170,"2nd Highest Score Holder:",GLUT_BITMAP_HELVETICA_18);

			   
			    if((f5 = fopen ("PlayerHighestSec.txt", "r")) != NULL)
				{       fscanf (f5, "%[^\n]", str5);
                        iText(270, 170 , str5 , GLUT_BITMAP_HELVETICA_18) ;
						fclose (f5);
				}
				
		    iSetColor(248, 87, 18);
	        iText(460,170,"2nd Highest Score:",GLUT_BITMAP_HELVETICA_18);

		     	
				if((f6 = fopen("ScoreHighestSec.txt", "r")) != NULL)
				{   int number=0;
                    fscanf(f6, "%d", &number);
					sprintf( str6, "%d", number); 
                    iText(633, 170 , str6 , GLUT_BITMAP_HELVETICA_18) ;
					fclose (f6);
				}

				iSetColor(248, 18, 104);
	        iText(50,120,"3rd Highest Score Holder:",GLUT_BITMAP_HELVETICA_18);

			   
			    if((f5 = fopen ("PlayerHighestThird.txt", "r")) != NULL)
				{       fscanf (f5, "%[^\n]", str7);
                        iText(270, 120 , str7 , GLUT_BITMAP_HELVETICA_18) ;
						fclose (f5);
				}
				
		    iSetColor(248, 87, 18);
	        iText(460,120,"3rd Highest Score:",GLUT_BITMAP_HELVETICA_18);

		     	
				if((f6 = fopen("ScoreHighestThird.txt", "r")) != NULL)
				{   int number=0;
                    fscanf(f6, "%d", &number);
					sprintf( str8, "%d", number); 
                    iText(633, 120 , str8 , GLUT_BITMAP_HELVETICA_18) ;
					fclose (f6);
				}

			iSetColor(248, 18, 104);
	        iText(50,300,"Your name:",GLUT_BITMAP_HELVETICA_18);

			   
			    if((f3 = fopen ("Player.txt", "r")) != NULL)
				{       fscanf (f3, "%[^\n]", str1);
                        iText(160, 300 , str1 , GLUT_BITMAP_HELVETICA_18) ;
						fclose (fopen("Player.txt","w"));
				}
				
		    iSetColor(165, 87, 18);
	        iText(300,300,"Your Score :",GLUT_BITMAP_HELVETICA_18);

		     	
				if((f4 = fopen("Score.txt", "r")) != NULL)
				{   int number=0;
                    fscanf(f4, "%d", &number);
					sprintf( str2, "%d", number); 
                    iText(410, 300 , str2 , GLUT_BITMAP_HELVETICA_18) ;
					fclose (f4);
				}

            
	}

	}



	
}
 


//score & life score printing 
void scoring()
{
        char str[100];
 
        // score print
        iSetColor( 0, 0, 0 );
        iText( 660, 550, "SCORE:", GLUT_BITMAP_TIMES_ROMAN_24 );
        sprintf( str, "%d", score );                              // prints score
        iText( 760, 550, str, GLUT_BITMAP_TIMES_ROMAN_24 );
 
        // life print
        iText( 660, 520, "Life: ", GLUT_BITMAP_TIMES_ROMAN_24 );
        sprintf( str, "%d", life );                                // prints life 
        iText( 760, 520, str, GLUT_BITMAP_TIMES_ROMAN_24 );
        
}

void iDraw()
{


	    
        
        if(menu==1)   // HUNGRY MONKEY
		{
           iShowBMP(0, 0, "cover.bmp");
	  	   iSetColor(255,80,0);
		   iText(280, 250, "Click Anywhere to Continue", GLUT_BITMAP_TIMES_ROMAN_24);

		}

		if(menu==2)  // Menu - Option Selections 
		{
			iClear();
            iShowBMP(0, 0, "menu.bmp");
			iSetColor(0, 0, 0);
			iText(350, 400, "New Game", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(350, 340, "High Score", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(350, 280, "Help", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(350, 220, "About", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(380, 140, "Exit", GLUT_BITMAP_TIMES_ROMAN_24);
		//	iText(600, 500, "About", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		
		if(menu==3)  //  easy level 
		{
				   iClear();


		iSetColor(255, 255, 255);
        iFilledRectangle(0, 0, 650, 600);
		iSetColor(0, 0, 0);
		iFilledRectangle(651, 0, 4, 600);
		iSetColor(255, 255, 255);
        iFilledRectangle(655, 0 , 145, 600);

        iShowBMP(monkey_x,monkey_y,"Monkey.bmp");
        
        iShowBMP(HalfPeeled_x,HalfPeeled_y,"BananaHalfPeeled.bmp");
		iShowBMP(Green_x,Green_y,"BananaGreen.bmp");
		iShowBMP(Tree_x,Tree_y,"BananaTree.bmp");
		iShowBMP(Bomb_x,Bomb_y,"BOMB.bmp");
	

		scoring();
        pointcounting();
		game_over();
	

	

		}

		if(menu==4||score>=50) // medium level and score up and equal 50
		{
				   iClear();


		iSetColor(255, 255, 255);
        iFilledRectangle(0, 0, 650, 600);
		iSetColor(0, 0, 0);
		iFilledRectangle(651, 0, 4, 600);
		iSetColor(255, 255, 255);
        iFilledRectangle(655, 0 , 145, 600);

        iShowBMP(monkey_x,monkey_y,"Monkey.bmp");
        
        iShowBMP(HalfPeeled_x,HalfPeeled_y,"BananaHalfPeeled.bmp");
	    iShowBMP(Purple_x,Purple_y,"BananaPurple.bmp");
		iShowBMP(Green_x,Green_y,"BananaGreen.bmp");
		iShowBMP(Tree_x,Tree_y,"BananaTree.bmp");
		iShowBMP(Bomb_x,Bomb_y,"BOMB.bmp");
	

		scoring();
        pointcounting();
		game_over();
		

	

		}

		if(menu==5||score>=250)  // hard level and score up and equal 250
		{
		   iClear();


		iSetColor(255, 255, 255);
        iFilledRectangle(0, 0, 650, 600);
		iSetColor(0, 0, 0);
		iFilledRectangle(652, 0, 3, 600);
		iSetColor(255, 255, 255);
        iFilledRectangle(655, 0 , 145, 600);

        iShowBMP(monkey_x,monkey_y,"Monkey.bmp");
        
        iShowBMP(HalfPeeled_x,HalfPeeled_y,"BananaHalfPeeled.bmp");
		iShowBMP(Yellow_x,Yellow_y,"BananaYellow.bmp");
		iShowBMP(Purple_x,Purple_y,"BananaPurple.bmp");
		iShowBMP(Green_x,Green_y,"BananaGreen.bmp");
		iShowBMP(Tree_x,Tree_y,"BananaTree.bmp");
		iShowBMP(Bomb_x,Bomb_y,"BOMB.bmp");
	

		scoring();
        pointcounting();
		game_over();
		

		}

		if(menu==6)  // level selections 
		{
           iClear();
            iShowBMP(0, 0, "menu.bmp");
			iSetColor(248, 18, 104);
			iText(220, 450 , "SELECT YOUR LEVEL TO PLAY",GLUT_BITMAP_TIMES_ROMAN_24) ; 

			iSetColor(0, 0, 0);
			iText(350, 400, "Easy", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(350, 340, "Medium", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(350, 280, "Hard", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(380, 200, "Back", GLUT_BITMAP_TIMES_ROMAN_24);

		}

		if(menu==7)    // help page 
		{
			iClear();
            iShowBMP(0, 0, "menu.bmp");
			iSetColor(0, 0, 0);
			iText(380, 500, "HELP ", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(120, 450, "# Press Left and Right arrow keys to move the monkey.", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(120, 400, "# Eat colored bananas to score.", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(120, 350, "# Eating banana tree will give life,eating bomb will", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(120, 327, "   decrease life points.", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(120, 277, "# After every 5 bananas/banana tree,one life point will", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(120, 254, "   decrease.", GLUT_BITMAP_TIMES_ROMAN_24);
			
			iText(380, 120, "Back", GLUT_BITMAP_TIMES_ROMAN_24);
		}

		if(menu==8)   // about page 
		{
			iClear();
            iShowBMP(0, 0, "menu.bmp");
			iSetColor(0, 0, 0);
			iText(380, 500, "About ", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(200, 420, "Project by ", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(200, 370, "Istiak Ahmed     14-02-04-081", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(200, 320, "Md. Siam Ansary  14-02-04-104", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(200, 250, "Ahsanullah University of Science & Technology", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(200, 200, "CSE 34th Batch", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(380, 120, "Back", GLUT_BITMAP_TIMES_ROMAN_24);
		} 

		if(menu == 9) // highscore page 
		{
			iClear() ;
			iShowBMP(0, 0, "highscore.bmp");

			iSetColor(60 , 30 , 0);
	        iText(50,400,"Highest Score Holders",GLUT_BITMAP_TIMES_ROMAN_24);

			   
			    if((f5 = fopen ("PlayerHighest.txt", "r")) != NULL)
				{
				     	iText(55, 350, "(i)", GLUT_BITMAP_TIMES_ROMAN_24);
						fscanf (f5, "%[^\n]", str3);
                        iText(98, 350 , str3 , GLUT_BITMAP_TIMES_ROMAN_24) ;
						fclose (f5);

				}

				if((f5 = fopen ("PlayerHighestSec.txt", "r")) != NULL)
				{
				     	iText(55, 300, "(ii)", GLUT_BITMAP_TIMES_ROMAN_24);
						fscanf (f5, "%[^\n]", str5);
                        iText(98, 300 , str5 , GLUT_BITMAP_TIMES_ROMAN_24) ;
						fclose (f5);

				}

				if((f5 = fopen ("PlayerHighestThird.txt", "r")) != NULL)
				{
				     	iText(55, 250, "(iii)", GLUT_BITMAP_TIMES_ROMAN_24);
						fscanf (f5, "%[^\n]", str7);
                        iText(98, 250 , str7 , GLUT_BITMAP_TIMES_ROMAN_24) ;
						fclose (f5);

				}
				

			


			
	        iText(400,400,"Highest Scores",GLUT_BITMAP_TIMES_ROMAN_24);

		     	
				
				if((f6 = fopen("ScoreHighest.txt", "r")) != NULL)
				{
					
					int number=0;
                    fscanf(f6, "%d", &number);
					sprintf( str4, "%d", number); 
                    iText(420, 350 , str4 , GLUT_BITMAP_TIMES_ROMAN_24) ;
					fclose (f6);
				}

				if((f6 = fopen("ScoreHighestSec.txt", "r")) != NULL)
				{
					
					int number=0;
                    fscanf(f6, "%d", &number);
					sprintf( str6, "%d", number); 
                    iText(420, 300 , str6 , GLUT_BITMAP_TIMES_ROMAN_24) ;
					fclose (f6);
				}

				if((f6 = fopen("ScoreHighestThird.txt", "r")) != NULL)
				{
					
					int number=0;
                    fscanf(f6, "%d", &number);
					sprintf( str8, "%d", number); 
                    iText(420, 250 , str8 , GLUT_BITMAP_TIMES_ROMAN_24) ;
					fclose (f6);
				}

               iSetColor(0 , 0, 0);
               iText(380, 100, "Back", GLUT_BITMAP_TIMES_ROMAN_24);

		}

	}

	void iKeyboard(unsigned char key)
{
        if(key == 'p')
	{
		iPauseTimer(0) ;  // pause half-peeled
		iPauseTimer(1) ;  // pause yellow
		iPauseTimer(2) ;  // pause purple
		iPauseTimer(3) ;  // pause green
		iPauseTimer(4) ;  // pause tree
		iPauseTimer(5) ;  // pause bomb
		flag = 0 ;
		
		
	}

	if(key == 'r')
	{
		iResumeTimer(0);  // resume half-peeled
		iResumeTimer(1);  // resume yellow
		iResumeTimer(2);  // resume purple 
		iResumeTimer(3);  // resume green
		iResumeTimer(4);  // resume tree
		iResumeTimer(5);  // resume bomb 
		flag = 1 ; 
		     
	}

	
	if(mode == 1)
	{
		int i;

		if(key == '\r')
		{
			value = 1 ;

			mode = 0;
			strcpy(str2, str1);

            f1 = fopen ("Player.txt", "w");
            fprintf (f1, "%s", str2);
            fclose (f1);

			f2 = fopen ("Score.txt", "w");
            fprintf (f2, "%d", score);
            fclose (f2);

		
            f4 = fopen("ScoreHighest.txt", "r");
            int number;
            fscanf(f4, "%d", &number);fclose(f4) ;

			f7 =fopen("ScoreHighestSec.txt", "r") ;

			int number2 =0 ;

			fscanf(f7 , "%d" , &number2) ; fclose(f7) ;

			f13 = fopen("ScoreHighestThird.txt", "r") ; int num3 =0 ;
			fscanf(f13 , "%d" , &num3) ;  fclose(f13) ;

			if(number<score && score>number2 && score>num3)
			{
			
                 
				f14 = fopen ("PlayerHighestSec.txt", "r");
                fscanf (f14, "%s", ch1); fclose (f14);
				f15 = fopen ("PlayerHighestThird.txt", "w");
                fprintf (f15, "%s", ch1); fclose (f15);

				f16 = fopen ("ScoreHighestSec.txt", "r");
                fscanf (f16, "%d", &n1); fclose (f16);
				f17 = fopen ("ScoreHighestThird.txt", "w");
                fprintf (f17, "%d", n1); fclose (f17); 
				

				f9 = fopen ("PlayerHighest.txt", "r");
                fscanf (f9, "%s", ch); fclose (f9);
				f10 = fopen ("PlayerHighestSec.txt", "w");
                fprintf (f10, "%s", ch); fclose (f10);

                f11 = fopen ("ScoreHighest.txt", "r");
                fscanf (f11, "%d", &num); fclose (f11);
				f12 = fopen ("ScoreHighestSec.txt", "w");
                fprintf (f12, "%d", num); fclose (f12);     



				f3 = fopen ("PlayerHighest.txt", "w");
                fprintf (f3, "%s", str2);
                fclose (f3);

		    	f4 = fopen ("ScoreHighest.txt", "w");
                fprintf (f4, "%d", score);
                fclose (f4);

			}

			else if(score > number2 && score<number && score>num3)
			{
				

				f18 = fopen ("PlayerHighestSec.txt", "r");
                fscanf (f18, "%s", ch2); fclose (f18);
				f19 = fopen ("PlayerHighestThird.txt", "w");
                fprintf (f19, "%s", ch2); fclose (f19);

				f20 = fopen ("ScoreHighestSec.txt", "r");
                fscanf (f20, "%d", &n2); fclose (f20);
				f21 = fopen ("ScoreHighestThird.txt", "w");
                fprintf (f21, "%d", n2); fclose (f21); 


				f8 = fopen("PlayerHighestSec.txt", "w");
				fprintf (f8, "%s", str2);
                fclose (f8);

				f7 = fopen ("ScoreHighestSec.txt", "w");
                fprintf (f7, "%d", score);
                fclose (f7);

			}
			else if(score > num3 && score<number2 && score<number)
			{
				f22 = fopen("PlayerHighestThird.txt", "w");
				fprintf (f22, "%s", str2);
                fclose (f22);

				f23 = fopen ("ScoreHighestThird.txt", "w");
                fprintf (f23, "%d", score);
                fclose (f23);

			}
                        

		
			
			score = 0 ; 
			for(i = 0; i < len; i++)
				str1[i] = 0;
			len = 0;

			checking = 1 ;
		}
		else
		{
			str1[len] = key;
			len++;
		}
	}

	
        //place your codes for other keys here
}


	    
 
        
		

 
/*
        function iMouseMove() is called when the user presses and drags the mouse.
        (mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
        //place your codes here
}
 
/*
        function iMouse() is called when the user presses/releases the mouse.
        (mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            //main menu
			if (mx>=0&&mx<=800 && my>=0&&my<=600 && menu==1)
			{menu=2;}  //cover
			else if (mx>=350&&mx<=470 && my>=390&&my<=430 && menu==2)
			menu=6 ;  //levels selection
			else if (mx>=350&&mx<=470 && my>=330&&my<=370 && menu==2)
			menu=9;  //high score

			else if (mx>=365&&mx<=430 && my>=270&&my<=310 && menu==2)
			menu=7; //help
			else if (mx>=370&&mx<=425 && my>=130&&my<=170 && menu==2)
			exit(2);  //exit
			
			
			else if (mx>=365&&mx<=430 && my>=210&&my<=250 && menu==2)
			menu=8; // about
			else if (mx>=370&&mx<=425 && my>=110&&my<=170 && menu==8)
			menu=2;  //back

			//level select menu
			else if (mx>=350&&mx<=470 && my>=390&&my<=430 && menu==6)
			{menu=3;n=1;life=5;value = 0;	fclose (fopen("Player.txt","w"));
			iResumeTimer(0);  // resume half-peeled
		iResumeTimer(1);  // resume yellow
		iResumeTimer(2);  // resume purple 
		iResumeTimer(3);  // resume green
		iResumeTimer(4);  // resume tree
		iResumeTimer(5);  // resume bomb 
		flag = 1 ;count=0 ; } //easy
			else if (mx>=350&&mx<=470 && my>=330&&my<=370 && menu==6)
			{menu=4;n=2;life=3;value = 0;	fclose (fopen("Player.txt","w"));
			iResumeTimer(0);  // resume half-peeled
		iResumeTimer(1);  // resume yellow
		iResumeTimer(2);  // resume purple 
		iResumeTimer(3);  // resume green
		iResumeTimer(4);  // resume tree
		iResumeTimer(5);  // resume bomb 
		flag = 1 ;count=0 ; }  //med
			else if (mx>=350&&mx<=470 && my>=270&&my<=310 && menu==6)
			{menu=5;n=3;life=2;value = 0;	fclose (fopen("Player.txt","w"));
			iResumeTimer(0);  // resume half-peeled
		iResumeTimer(1);  // resume yellow
		iResumeTimer(2);  // resume purple 
		iResumeTimer(3);  // resume green
		iResumeTimer(4);  // resume tree
		iResumeTimer(5);  // resume bomb 
		flag = 1 ; count=0 ; } //hard
			else if (mx>=370&&mx<=425 && my>=190&&my<=230 && menu==6)
			menu=2;  //back to option page

			//help menu
			else if (mx>=370&&mx<=425 && my>=110&&my<=150 && menu==7)
			menu=2;  //back to option page

			else if(mx >= 50 && mx <= 300 && my >= 345 && my <= 380 && mode == 0)
			{mode = 1;	fclose (fopen("Player.txt","w"));for(int i=0 ; i<100 ; i++) str1[i]=NULL ; }

			else if (mx>=370&&mx<=425 && my>=90&&my<=130 && menu==9)
			menu=2;  //back to option page

        }

	

        if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        {
                //place your codes here
        }
}
 
/*
        function iKeyboard() is called whenever the user hits a key in keyboard.
        key- holds the ASCII value of the key pressed.
*/

 
/*
        function iSpecialKeyboard() is called whenver user hits special keys like-
        function keys, home, end, pg up, pg down, arraows etc. you have to use
        appropriate constants to detect them. A list is:
        GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
        GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
        GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
        GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
    if(key == GLUT_KEY_LEFT)
        {
		    if(flag == 1)
			{
				if(monkey_x>16)
				{
					monkey_x-=10;  // moves the monkey to left 
				}

			}
                

        }

        if(key == GLUT_KEY_RIGHT)
        {
               if(flag == 1)
			   {
				    if(monkey_x<614)
				{
					monkey_x+=10;  // moves the monkey to right 
				}

			   }
        }

		if(key == GLUT_KEY_F1)
		{
			menu=2; 	fclose (fopen("Player.txt","w")); flaging = 0 ;
		}

		if( key == GLUT_KEY_END)
		{
                exit(1) ; 
		}
 
       
	
}
 
int main()
{
        //place your own initialization codes here.
 
        len = 0;
    	mode = 0;
    	str1[0]= 0;
       
        iSetTimer(20, BananaHalfPeeled);
		iSetTimer(19, BananaYellow);
		iSetTimer(18, BananaPurple);
		iSetTimer(17, BananaGreen);
		iSetTimer(16, BananaTree);
		iSetTimer(19, BOMB); 
		


        iInitialize(mainx,mainy, "HUNGRY MONKEY");
        return 0;
}



 

     