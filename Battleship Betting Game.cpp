  /*********************************************
*	Leon Shainski							 *
*	Date: june 6th, 2017					 *
*	Dev C++ 5.11							 *
*	Purpose: Battleship game			 	 *
*	Data Dictionary: 	
	
	DesPlaceX: the beggining X co-ordinate for the destroyer
	DesPlaceY: the beggining Y co-ordinate for the destroyer
	DesOrient: the selected orientation for the destroyer
	subPlaceX: the beggining X co-ordinate for the submarine
	subPlaceY: the beggining Y co-ordinate for the submarine
	subOrient: the selected orientation for the submarine
	warPlaceX: the beggining X co-ordinate for the warship
	warPlaceY: the beggining Y co-ordinate for the warship
	warOrient: the selected orientation for the warship
	deposit: Basically acts as the balance, stored in the main function and given to several others
	bet: the amount the user would like to bet
	
	Those are the important ones. The other variables are small, local variables used for things like changing the chars into ints, changing betting amounts, etc.

*********************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>  
#include<string>
#include <windows.h>
#include <fstream>

using namespace std; 

void showBoard(string Board[][11]);
void selectShips1(string Board[][11]);
void desCheck (int&a, char&b, char&c);
void subCheck (int&a, char&b, char&c);
void warCheck (int&a, char&b, char&c);
void shipAssign(string Board[][11],int desPlaceX, char desPlaceY, char desOrient, int subPlaceX, char subPlaceY, char subOrient, int warPlaceX, char warPlaceY, char warOrient);
void compFire1(string Board[][11], float&a, float&b);
void setup(float&a);
void Betting(float&a, float&b);



main()//Coded by Leon
{
	string answerResponse, name;
	float deposit, bet;
	string Board[10][11];
	
	cout<<"What's your name, user? I'll need it for...Scientific reasons: ";
	cin>>name;
	system("cls");
	cout<<"Welcome to the game, "<<name;
	sleep(2);
	
	
	ofstream myfile;
	myfile.open("last user");
	myfile<<name<<"\n";
	myfile.close();
	
	system("cls");
	
	
	 
	
	for (int i=0; i<10; i++)
	{
		for (int j=1; j<11; j++)
		{
			Board[i][j]='O';
		}
	}
	
	showBoard(Board);
	
	selectShips1(Board);
	
	setup (deposit);
	
	while (deposit>1&&answerResponse!="exit")
	{
		Betting(deposit, bet);
	
		compFire1(Board, deposit, bet);	
		
		system("cls");
		cout<<"Would you like to keep playing or exit? (type 'exit' to exit): ";
		cin>>answerResponse;
	}
	
	
	
	
	

}

void showBoard(string Board[][11])//Coded by Leon
{
	int letterCounter=97, letterNum, topnum;
	
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), //Changing background color
															FOREGROUND_RED |
                                                            FOREGROUND_GREEN | 
                                                            FOREGROUND_INTENSITY | 
                                                            BACKGROUND_BLUE
                                                            
                          );
	
	cout<<"    ";
	
	for (int i=0; i<10; i++)
	{
		letterNum=letterCounter;//Side letters

		Board[i][0]=char(letterNum);//For the side letters
		
		
		
		topnum=letterCounter-96;//For the top
		
		
		if (i<9) //Only here to keep the table in line
		{
		cout<<" "<<topnum<<" |";	
		}
		else 
		{
			cout<<" "<<topnum<<"|";
		}
		
		
		
		letterCounter++;//Side letter
		
		
	}
	

	
	  
	
	for (int i=0; i<10; i++) //Displaying the table (the board)
	{
		cout<<"\n   -----------------------------------------\n";
		
		for (int x=0; x<11; x++)
		{
			
			
			
			if (x>0)
			{
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), //Making the background blue
															
                                                            FOREGROUND_GREEN | 
                                                            FOREGROUND_INTENSITY | 
                                                            BACKGROUND_BLUE
                                                            
                          );
                          cout<<" "<<Board[i][x]<<" |";
			}
			else 
			{
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), //Making the text white
															FOREGROUND_RED |
                                                            FOREGROUND_GREEN | 
                                                            FOREGROUND_INTENSITY | 
                                                            BACKGROUND_BLUE
                                                            );
				cout<<" "<<Board[i][x]<<" |";
			}
		}
		
		
	}
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), //Removing blue background and making text yellow
															FOREGROUND_RED |
                                                            FOREGROUND_GREEN | 
                                                            FOREGROUND_INTENSITY 
                          );
}

void selectShips1(string Board[][11])//Coded by Leon
{
	//Destroyer=3 spaces / Sub = 2 places / Warship = 5 places
	char desOrient, subOrient, warOrient;
	int desPlaceX, subPlaceX, warPlaceX, temp=0;
	char desPlaceY, subPlaceY, warPlaceY;
	
	sleep(1);
	cout<<"\nFor the following questions, please enter an X value followed by a Y value\n\n";
	
	sleep(2);//Making a delay
	cout<<"Where would you like your destroyer (3 spaces) to be? ";//Prompting user for where they would like the starting position of their ship to be
	cin>>desPlaceX>>desPlaceY;//Recording X and Y co-ordinates given by user
	
	system("cls"); //Clearing screen
	showBoard(Board); //Showing the user the board again (screen was cleared earlier to ensure that they could type while looking at the board foir reference
	
	cout<<"\nWhat orientation would you like? (type 'H' for Horizontal/'V' for Vertical"; //prompting user for the orientation which they would like the ship to face
	cin>>desOrient; //Getting the orientation
	
	desCheck (desPlaceX, desPlaceY, desOrient); //Calling on the checking function that will check if that positioning is possibile

	system("cls"); //Clearing the screen and showing board again to give the user reference while selecting positioning
	showBoard(Board); //The rest of the code bellow follows the structre above just with different variables and linking to different functions for different ships
	
	cout<<"\nWhere would you like your submarine (2 spaces) to be? ";
	cin>>subPlaceX>>subPlaceY;
	
	system("cls");
	showBoard(Board);
	
	cout<<"\nWhat orientation would you like? (type 'H' for Horizontal/'V' for Vertical"; 
	cin>>subOrient;
	
 	subCheck ( subPlaceX, subPlaceY, subOrient);

	system("cls");
	showBoard(Board);
	
	cout<<"\nWhere would you like your Warship (5 spaces) to be? ";
	cin>>warPlaceX>>warPlaceY;
	
	system("cls");
	showBoard(Board);
	
	cout<<"\nWhat orientation would you like? (type 'H' for Horizontal/'V' for Vertical"; 
	cin>>warOrient;
	
	warCheck (warPlaceX, warPlaceY, warOrient);
	
	system("cls");
	showBoard(Board);
	
		
	shipAssign(Board, desPlaceX, desPlaceY, desOrient, subPlaceX, subPlaceY, subOrient, warPlaceX, warPlaceY, warOrient);//Calling on the assign function to place the ships

	
}

void desCheck (int&a, char&b, char&c)//Coded by Leon (THIS IS THE FUNCTION THAT IS IN MY PSEUDOCODE) This function checks to make sure the destroyer can fit on the board
{									//This function will be the only function of the checking functions (the ones that check the placements of the ships) to be noted as they are all the same
	int temp=0, changeX, temp2=-1;
	char changeY;
	
	for (int i=0;i<1; i++) //Changing the orientation into upper case
	{
		c=toupper(c);
	}
	
	if (c!='H' && c!='V') //Checking that the orientation is either H for horizontal of V for vertical
	{
		
		while (c!='H' && c!='V') //A loop running while the orientation is not H or V asking the user to make it one or the other
		{
			cout<<"Please select an orientation by typing in 'H' or 'V':"; 
			cin>>c;
		}
	}
	
	if (c=='H'&&  a>8 || a<1) //Making sure the ships are not places out of the board
	{
		while (changeX>8 || changeX<1)
		{
			cout<<"There isnt enough room to place you horizontally, select a different X-value: ";
			cin>>changeX;
	
			
		}
		a=changeX;
		
	}

	temp=int(b)-97;

	if ((c=='V' && temp>8)||(c=='V' && temp<0))
	{
		while (temp2>8||temp2<0)
		{
		cout<<"There isnt enough room to place you Vertically, select a different Y-value: \n";
		cin>>changeY;
		
		temp2=int(changeY)-97;

		}
		temp2=temp2+97;
		b=char(temp2);
	}
	
}

void subCheck (int&a, char&b, char&c)//Coded by Leon
{
	int changeX, temp, temp2=-1;
	char changeY;
	for (int i=0;i<1; i++)
	{
		c=toupper(c);
	}
	

	if (c!='H' && c!='V') 
	{
		
		while (c!='H' && c!='V')
		{
			cout<<"Please select an orientation by typing in 'H' or 'V':";
			cin>>c;
		}
	}
	
	if (c=='H'&&  a>9) //Making sure the ships are not places out of the board
	{
		
		while (changeX>9 || changeX<1)
		{
			cout<<"There isnt enough room to place you horizontally, select a X-value: ";
			cin>>changeX;
			
		}
		a=changeX;
		
	}
	
	temp=int(b)-97;
	
	if ((c=='V' && temp>9)||(c=='V'&&temp<0))
	{
		while (temp2>9 && temp2<0)
		{
			cout<<"There isnt enough room to place you Vertically, select a different Y-Value: ";
			cin>>changeY;

			temp2=int(changeY)-97;
		}
		temp2=temp2+97;
		b=char(temp2);
	}
	
}

void warCheck (int&a, char&b, char&c)//Coded by Leon
{
	int temp, temp2=-1, changeX;
	char changeY;
	cout<<"Checking Warship";
	for (int i=0;i<1; i++)
	{
		c=toupper(c);
	}
	
	if (c!='H' && c!='V')
	{
		
		while (c!='H' && c!='V')
		{
			cout<<"Please select an orientation by typing in 'H' or 'V':";
			cin>>c;
		}
	}
	
	if (c=='H'&& a>5) //Making sure the ships are not places out of the board
	{
		cout<<"There isnt enough room to place you horizontally, so we will move you to 5";
		a=5;
		
	}
	
	temp=int(b);
	if ((c=='V' && temp>6)||(c=='V'&&temp<0))
	{
		while (temp2>6 || temp2<0)
		{
			cout<<"There isnt enough room to place you Vertically, select a different Y-value to start: ";
			cin>>changeY;
		
			temp2=int(changeY)-97;
		}
		temp2=temp2+97;
		b=char(temp2);
		
	}
	
	
}

void shipAssign(string Board[][11], int desPlaceX, char desPlaceY, char desOrient, int subPlaceX, char subPlaceY, char subOrient, int warPlaceX, char warPlaceY, char warOrient)//Coded by Leon
{
	int desY=0, subY=0, warY=0;
	
	desY=int (desPlaceY);//Changing the char into an int value
	 
	desY=desY-97; //Taking 97 away from it (for ASCII values)

	//I will once again only note the destroyer portion as the portions for the other ships are identical
	
	if (desOrient=='H') //If the orientation chosen was horizontal
	{
		
			for (int i=desPlaceX; i<desPlaceX+3; i++) //Making the 'O' (blank spaces) into '#' (ships)
			{
				
				Board[desY][i]= "#" ;
				
			}
	}
	else if (desOrient=='V')//If the orientation chosen was horizontal
	{
		
		for (int i=desY; i<desY+3; i++)//Making the 'O' (blank spaces) into '#' (ships)
			{
					Board[i][desPlaceX]="#";
			}
		
	}		
	
	subY=int (subPlaceY); 

	subY=subY-97;
	
	system("cls");
		
	
	if (subOrient=='H')
	{
			for (int i=subPlaceX; i<subPlaceX+2; i++)
			{
				Board[subY][i]= "#" ;
			}
	}
	else if (subOrient=='V')
	{
		
		
		for (int i=subY; i<subY+2; i++)
			{
					Board[i][subPlaceX]="#";
			}
		
	}
	
	warY=int(warPlaceY);
	
	warY=warY-97;
	
	
	if (warOrient=='H')
	{
		
			for (int i=warPlaceX; i<warPlaceX+5; i++)
			{
				
				Board[warY][i]= "#" ;
				
			}
	}
	else if (warOrient=='V')
	{
		
		for (int i=warY; i<warY+5; i++)
			{
					Board[i][warPlaceX]="#";
			}
		
	}

	
	
	showBoard (Board); //Showing the board
	
}

void compFire1(string Board[][11], float&a, float&b)//Coded by Leon, this is the function where the computer randomizes where to fire and then it is recorded wether the user wins or loses money
{
	srand(time(NULL));
	string answer;
	int randXnum, randYnum, hitCount=0, count2=0;
	char randX, randY;
	
	system("cls");
	
	randXnum=rand () %10; //Randomizing numbers for X and Y
	randYnum=rand () %11;
		
	
	
	
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), //White text on blue background
                                                            FOREGROUND_RED|
                                                            FOREGROUND_GREEN | 
                                                            FOREGROUND_BLUE| 
                                                            BACKGROUND_BLUE|
                                                            BACKGROUND_GREEN|
                                                            FOREGROUND_INTENSITY 
                          );
	
	cout<<"COMPUTER IS THINKING.\n";
	
	showBoard(Board);
	
	sleep(1);
	
	system ("cls");
	
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), //White text on blue background
                                                            FOREGROUND_RED|
                                                            FOREGROUND_GREEN | 
                                                            FOREGROUND_BLUE| 
                                                            BACKGROUND_BLUE|
                                                            BACKGROUND_GREEN|
                                                            FOREGROUND_INTENSITY 
                          );
                          
	cout<<"COMPUTER IS THINKING..\n";
	
	showBoard(Board);
	
	sleep(1);
	
	system ("cls");
	
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), //White text on blue background
                                                            FOREGROUND_RED|
                                                            FOREGROUND_GREEN | 
                                                            FOREGROUND_BLUE| 
                                                            BACKGROUND_BLUE|
                                                            BACKGROUND_GREEN|
                                                            FOREGROUND_INTENSITY 
                          );

	cout<<"COMPUTER IS THINKING...\n";
	
	showBoard(Board);
	
	sleep(1);
	
	system ("cls");
	
	
	if (Board[randXnum][randYnum]=="#") //If the computer hits a ship
	{
		
		hitCount++;
		Board[randXnum][randYnum]="X";	//Showing the hit as an X
		
	}
	else if (Board[randXnum][randYnum]=="O") //If the computer hits an empty slot
	{
	
		Board[randXnum][randYnum]="X"; //Showing the hit as an X
	
	}
	
	if (hitCount>count2) //If there are more hits than previously recorded (as in a new ship hit has been recorded)
	{
		count2=hitCount; //setting the new record straight
		a=a-b*4; //Making the loser lose 4x what they bet
		showBoard(Board); //Showing the board
		
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), //Red background and White text
                                                            FOREGROUND_RED|
                                                            FOREGROUND_GREEN | 
                                                            FOREGROUND_BLUE| 
                                                            BACKGROUND_RED|
                                                            FOREGROUND_INTENSITY 
                          );
    
		cout<<"\nYOU HAVE BEEN HIT!\n$"<<b*4<<" was lost! Your balance is now $"<<a;//Telling the user they've been hit and informing them of their new balance
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), //Setting the text back to white
                                                            FOREGROUND_RED|
                                                            FOREGROUND_GREEN | 
                                                            FOREGROUND_BLUE| 
                                                            FOREGROUND_INTENSITY 
                          );
		system("pause");
	}
	else 
	{
		a=a+b;//adding the betting amount to their balance
		showBoard(Board);//Showing the board
		
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), //Green background and white text
															
															FOREGROUND_RED|
                                                            FOREGROUND_GREEN | 
                                                            FOREGROUND_BLUE|
                                                            BACKGROUND_GREEN|
                                                            FOREGROUND_INTENSITY 
                          );
    	cout<<"\nYou're in the clear!\nYou've gained $"<<b<<", your balance is now $"<<a;//Telling the user they dodged one and showing them their balance
    	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), //Setting the text back to white
                                                            FOREGROUND_RED|
                                                            FOREGROUND_GREEN | 
                                                            FOREGROUND_BLUE| 
                                                            FOREGROUND_INTENSITY 
                          );
    	
    	system("pause");
    	
	}
	
	
	
}
void setup (float&a)//Coded by Leon, this is the setup where we get the user to agree to all the requirements of play
{
	float deposit;
	string ans, ans2;
	system ("cls");
	
	cout<<"This isn't really battleship. I forgot to tell you that. This is a betting game\n"; //Giving instuctions
	
	sleep (2);
	
	cout<<"Here's the deal. You can bet money here saying that the computer won't hit you  You may play for as long as you like\nIf you bet that the computer will not hit your ship, you win double what you bet\nIf the computer does hit when you bet against it, you lose 4x what you bet\n\nStill wanna play?";
	cin>>ans;
	
	system("cls");
	
	if (ans=="no"||ans=="No"||ans=="NO")
	{
		
		cout<<"I thought so..."; //ASCII art display if the user decided they're not interested in playing
		sleep(1);
		
		cout<<" _                     ";
		cout<<"| |                    ";
		cout<<"| | ___  ___  ___ _ __ ";
		cout<<"| |/ _ \/ __|/ _ \ '__|";
		cout<<"| | (_) \__ \  __/ |   ";
		cout<<"|_|\___/|___/\___|_|   ";
		
		exit(1);
	}
	
	cout<<"You're gonna need to deposit some money then.How much would you like to deposit? "; //getting the user to deposit money
	cin>>a; //Recording the deposit
	
	if (a<1) //If the deposit is less than 1 we kick the user out cause they're clearly not serious
	{
		system("cls");
		cout<<"I see im dealing with a jokester. This is a serious establishment.";
		exit(1);
	}
	
	cout<<"You're also going to have to agree that if you lose more than you have\nyou are in debt to us...type 'ok' if you wish to continue: "; //telling the user that they must be ok with goin ginto debt
	cin>>ans2;
	
	if (ans2!="ok"&&ans2!="OK") //If the user does not answer OK like we ask them to then they are kicked out
	{
		system("cls");
		cout<<"I could tell you didn't have what it takes anyway";
		exit (1);
	}
	
	
}
void Betting (float&a, float&b)//coded by Leon
{
	string leaveResponse;
	float deposit2; 
	int hitcount=0;
	char answer;
	system("cls");
	
	
    	cout<<"How much would you like to bet from your balance? (balance is $"<<a<<"): "; //Asking the user how much they would like to bet and recording bet amount
		cin>>b;
		
		if(b>a) //if the user does not have enough in their balance to bet then we ask them to add more money to their balance
		{
 			cout<<"\nOops doesn’t looked like ur cashed out enough to bet that much money, would you like to deposit more money? (Y/N)"; 
			cin>>answer; 
		}
		
		
		if(answer!= 'Y'&&answer!='y' && b>a) //If the user would like to deposit more then we give them the opprotunity to and then take their original bet amount from the new balance
		{
			cout<<"\n how much more money would you like to deposit?";
			cin>>deposit2;
			a= a+deposit2;
		}
		else if (answer=='N'||answer=='n') //if the user will not add more funds then we ask them to bet a lower amount
		{
			cout<<"How much would you like to bet instead, you have a $"<<a<<" balance";
			cin>>b;
			a=a-b; 
		} 

		


}




