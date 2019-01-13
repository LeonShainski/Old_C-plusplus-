/*********************************************
*	Leon Shainski							 *
*	Date: April 3rd, 2017					 *
*	Dev C++ 5.11							 *
*	Purpose: Game of 21			 			 *
*	Data Dictionary: 
	
	amountDeposit: The amount they want to deposit the first time it is asked for
	amountDeposit: The amount they want to deposit the second time they are promtpted
	usercardnum1: The first user card's number (1-52)
	usercardnum2: The second user card's number (1-52) (only used in the beginning
	compcardnum1: The computer's card's number (1-52)
	balance: The user's balance
	randomNum: A randomly generated number that is used to get the cards
	usercount: The total of the users cards
	compcount: The total of the computer's cards
	betAmount: The amount the user wishes to bet on the game
	winCount: A counter counting the amount of times the user won	
	lossCount: A counter counting the amount of times the user lost
	tieCount: A counter counting the amount of times the user tied								 *
	answerDeposit: The response of the user when prompted wether or not they would like to deposit some money
	answerDeposit2: The user's response when asked wether they had changed their mind about depositing
	answerDeposit3: The user's response when asked wether they had changed their mind about depositing
	gameStartResponse: the user's response when asked wether or not they'd like to start a game
	finalResponse: The response at the end where the user is asked wether they would like to quit or not
	gameStartResponse2: The response recorded when the user is asked wether they are sure they would not like to start a game
	usercard1: The actual card name of the first card of the user
	usercard2: The actual card name of the  first card of the user
	compcard1: The actual name of the computer's card
	hitResponse: The answer recorded when the user is asked wether or not they would like to hit
	warningResponse: The response of the user when they are asked if they are ok with being in debt to the casino							 
							
*********************************************/
#include <stdio.h> 
#include <conio.h> 
#include <time.h>
#include <windows.h>
#include <iostream>

using namespace std;
int amountDeposit, amountDeposit2, usercardnum1, usercardnum2, compcardnum1, balance, randomNum, usercount, compcount, betAmount, winCount, lossCount, tieCount;
string answerDeposit, answerDeposit2, answerDeposit3,  finalResponse,  gameStartResponse,gameStartResponse2, usercard1, usercard2, compcard1, hitResponse, warningResponse;


void userIf ()
{
	if (usercardnum1 == 1 || usercardnum1 == 2 || usercardnum1 == 3 || usercardnum1 == 4)
	{
		usercard1="Two";
		usercount=usercount+2;
	}
	else if (usercardnum1 == 5 || usercardnum1 == 6 || usercardnum1 == 7 || usercardnum1 == 8)
	{
		usercard1="Three";
		usercount=usercount+3;
	}
	else if (usercardnum1 == 9 || usercardnum1 == 10 || usercardnum1 == 11 || usercardnum1 == 12)
	{
		usercard1="Four";
		usercount=usercount+4;
	}
	else if (usercardnum1 == 13 || usercardnum1 == 14 || usercardnum1 == 15 || usercardnum1 == 16)
	{
		usercard1="Five";
		usercount=usercount+5;
	}
	else if (usercardnum1 == 17 || usercardnum1 == 18 || usercardnum1 == 19 || usercardnum1 == 20)
	{
		usercard1="Six";
		usercount=usercount+6;
	}
	else if (usercardnum1 == 21 || usercardnum1 == 22 || usercardnum1 == 23 || usercardnum1 == 24)
	{
		usercard1="Seven";
		usercount=usercount+7;
	}
	else if (usercardnum1 == 25 || usercardnum1 == 26 || usercardnum1 == 27 || usercardnum1 == 28)
	{
		usercard1="Eight";
		usercount=usercount+8;
	}
	else if (usercardnum1 == 29 || usercardnum1 == 30 || usercardnum1 == 31 || usercardnum1 == 32)
	{
		usercard1="Nine";
		usercount=usercount+9;
	}
	else if (usercardnum1 == 33 || usercardnum1 == 34 || usercardnum1 == 35 || usercardnum1 == 36)
	{
		usercard1="Ten";
		usercount=usercount+10;
	}
	else if (usercardnum1 == 37 || usercardnum1 == 38 || usercardnum1 == 39 || usercardnum1 == 40)
	{
		usercard1="Jack";
		usercount=usercount+10;
	}
	else if (usercardnum1 == 41 || usercardnum1 == 42 || usercardnum1 == 43 || usercardnum1 == 44)
	{
		usercard1="Queen";
		usercount=usercount+10;
	}
	else if (usercardnum1 == 45 || usercardnum1 == 46 || usercardnum1 == 47 || usercardnum1 == 48)
	{
		usercard1="King";
		usercount=usercount+10;
	}
	else if (usercardnum1 == 49 || usercardnum1 == 50 || usercardnum1 == 51 || usercardnum1 == 52)
	{
		usercard1="Ace";
		if (usercount>11)
		{
		usercount=usercount+11;

		}
		else 
		{
		usercount=usercount+1;
		}
	}
}

void compIf ()
{
	//if statement to determine the card type
	if (compcardnum1 == 1 || compcardnum1 == 2 || compcardnum1 == 3 || compcardnum1 == 4)
	{
		compcard1="Two"; //Used to tell the user what card they get
		compcount=compcount+2; //Adding how much the card is worth to running total
	}
	else if (compcardnum1 == 5 || compcardnum1 == 6 || compcardnum1 == 7 || compcardnum1 == 8)
	{
		compcard1="Three";
		compcount=compcount+3;
	}
	else if (compcardnum1 == 9 || compcardnum1 == 10 || compcardnum1 == 11 || compcardnum1 == 12)
	{
		compcard1="Four";
		compcount=compcount+4;
	}
	else if (compcardnum1 == 13 || compcardnum1 == 14 || compcardnum1 == 15 || compcardnum1 == 16)
	{
		compcard1="Five";
		compcount=compcount+5;
	}
	else if (compcardnum1 == 17 || compcardnum1 == 18 || compcardnum1 == 19 || compcardnum1 == 20)
	{
		compcard1="Six";
		compcount=compcount+6;
	}
	else if (compcardnum1 == 21 || compcardnum1 == 22 || compcardnum1 == 23 || compcardnum1 == 24)
	{
		compcard1="Seven";
		compcount=compcount+7;
	}
	else if (compcardnum1 == 25 || compcardnum1 == 26 || compcardnum1 == 27 || compcardnum1 == 28)
	{
		compcard1="Eight";
		compcount=compcount+8;
	}
	else if (compcardnum1 == 29 || compcardnum1 == 30 || compcardnum1 == 31 || compcardnum1 == 32)
	{
		compcard1="Nine";
		compcount=compcount+9;
	}
	else if (compcardnum1 == 33 || compcardnum1 == 34 || compcardnum1 == 35 || compcardnum1 == 36)
	{
		compcard1="Ten";
		compcount=compcount+10;
	}
	else if (compcardnum1 == 37 || compcardnum1 == 38 || compcardnum1 == 39 || compcardnum1 == 40)
	{
		compcard1="Jack";
		compcount=compcount+10;
	}
	else if (compcardnum1 == 41 || compcardnum1 == 42 || compcardnum1 == 43 || compcardnum1 == 44)
	{
		compcard1="Queen";
		compcount=compcount+10;
	}
	else if (compcardnum1 == 45 || compcardnum1 == 46 || compcardnum1 == 47 || compcardnum1 == 48)
	{
		compcard1="King";
		compcount=compcount+10;
	}
	else if (compcardnum1 == 49 || compcardnum1 == 50 || compcardnum1 == 51 || compcardnum1 == 52)
	{
		compcard1="Ace";
		if (compcount>=11)
		{
		compcount=compcount+11;

		}
		else 
		{
		compcount=compcount+1;
		}
	}
}



int i, number [52];
main()
{
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), //Setting background color to green
                                                            
                                                            BACKGROUND_GREEN
                                                            );
	system("cls"); //Clearing screen so that the background change goes into effect
	srand (time(NULL));
	cout<<"Welcome to Jack Black's Black Jack game!\n\nYou seem like a nice fella, you can start with $50 on us!";
	balance=50;//setting user's starting balance at 50 (on the house)
	
	//Loop to ask about deposits
	while (answerDeposit!="no" )
	{
		cout<<"\nWould you like to deposit some more money? ";
		cin>>answerDeposit;
		
		if (answerDeposit=="yes")
		{
		
			cout<<"How much would you like to deposit? ";
			cin>>amountDeposit;
			balance=balance+amountDeposit;
			
		}
		else if (answerDeposit=="no")
		{
			cout<<"Alright, good luck to ya! ";
		}
		else 
		{
			cout<<"Sorry I didn't catch that, please respond with 'yes' or 'no'";
		}
	}

	//Filling the Array
	for (i=0; i<52; i++)
	{
		number[i]=i % 52 + 1;
	}
	
	
	while (lossCount<10) //*LOOP THAT BEGINS THE GAME< GOES ON FOR 10 TIMES*************//
	{
	//Generating the numbers to be given to the user and computer
	do 
	{
		randomNum = rand() % 52;
		
	} while (number[randomNum]==0);
	compcardnum1=number[randomNum];
	
	do 
	{
		randomNum = rand() % 52;
		
	} while (number[randomNum]==0);
	usercardnum1=number[randomNum];

	do 
	{
		randomNum = rand() % 52;
		
	} while (number[randomNum]==0);
	usercardnum2=number[randomNum];
	//****main part of the game****
	
	number[randomNum]=0; //Getting rid of the number that was used to avoid using it twice


	system ("cls");
	cout<<"Would you like to start a game?\n";
	cin>>gameStartResponse;

	//Asking user if they want to begin (although it's a trick question
	if (gameStartResponse=="yes")
	{
		system ("cls");
	}
	else if (gameStartResponse=="no")
	{
		cout<<"\nAre you sure?";
		cin>>gameStartResponse2;
		
		if (gameStartResponse2=="yes")
		{
			system("cls");
			cout<<"Well thanks for coming!";
			exit (1);
		}
		else if (gameStartResponse2=="no")
		{
			cout<<"ok then, let's get started";
		}
		else 
		{
			cout<<"I didn't quite catch that, so Ill assume you said yes!";
		}
	}
	
	//*main game loop*
	
	usercount=0;//Declaring user count as 0
	compcount=0;//Declaring comp count as 0
	
	//if statement to determine the card type
	if (compcardnum1 == 1 || compcardnum1 == 2 || compcardnum1 == 3 || compcardnum1 == 4)
	{
		compcard1="Two"; //Used to tell the user what card they get
		compcount=compcount+2; //Adding how much the card is worth to running total
	}
	else if (compcardnum1 == 5 || compcardnum1 == 6 || compcardnum1 == 7 || compcardnum1 == 8)
	{
		compcard1="Three";
		compcount=compcount+3;
	}
	else if (compcardnum1 == 9 || compcardnum1 == 10 || compcardnum1 == 11 || compcardnum1 == 12)
	{
		compcard1="Four";
		compcount=compcount+4;
	}
	else if (compcardnum1 == 13 || compcardnum1 == 14 || compcardnum1 == 15 || compcardnum1 == 16)
	{
		compcard1="Five";
		compcount=compcount+5;
	}
	else if (compcardnum1 == 17 || compcardnum1 == 18 || compcardnum1 == 19 || compcardnum1 == 20)
	{
		compcard1="Six";
		compcount=compcount+6;
	}
	else if (compcardnum1 == 21 || compcardnum1 == 22 || compcardnum1 == 23 || compcardnum1 == 24)
	{
		compcard1="Seven";
		compcount=compcount+7;
	}
	else if (compcardnum1 == 25 || compcardnum1 == 26 || compcardnum1 == 27 || compcardnum1 == 28)
	{
		compcard1="Eight";
		compcount=compcount+8;
	}
	else if (compcardnum1 == 29 || compcardnum1 == 30 || compcardnum1 == 31 || compcardnum1 == 32)
	{
		compcard1="Nine";
		compcount=compcount+9;
	}
	else if (compcardnum1 == 33 || compcardnum1 == 34 || compcardnum1 == 35 || compcardnum1 == 36)
	{
		compcard1="Ten";
		compcount=compcount+10;
	}
	else if (compcardnum1 == 37 || compcardnum1 == 38 || compcardnum1 == 39 || compcardnum1 == 40)
	{
		compcard1="Jack";
		compcount=compcount+10;
	}
	else if (compcardnum1 == 41 || compcardnum1 == 42 || compcardnum1 == 43 || compcardnum1 == 44)
	{
		compcard1="Queen";
		compcount=compcount+10;
	}
	else if (compcardnum1 == 45 || compcardnum1 == 46 || compcardnum1 == 47 || compcardnum1 == 48)
	{
		compcard1="King";
		compcount=compcount+10;
	}
	else if (compcardnum1 == 49 || compcardnum1 == 50 || compcardnum1 == 51 || compcardnum1 == 52)
	{
		compcard1="Ace";
		if (compcount>=11)
		{
		compcount=compcount+11;

		}
		else 
		{
		compcount=compcount+1;
		}
	}
	
	//If Statement for determining the first user number
	
	if (usercardnum1 == 1 || usercardnum1 == 2 || usercardnum1 == 3 || usercardnum1 == 4)
	{
		usercard1="Two";
		usercount=usercount+2;
	}
	else if (usercardnum1 == 5 || usercardnum1 == 6 || usercardnum1 == 7 || usercardnum1 == 8)
	{
		usercard1="Three";
		usercount=usercount+3;
	}
	else if (usercardnum1 == 9 || usercardnum1 == 10 || usercardnum1 == 11 || usercardnum1 == 12)
	{
		usercard1="Four";
		usercount=usercount+4;
	}
	else if (usercardnum1 == 13 || usercardnum1 == 14 || usercardnum1 == 15 || usercardnum1 == 16)
	{
		usercard1="Five";
		usercount=usercount+5;
	}
	else if (usercardnum1 == 17 || usercardnum1 == 18 || usercardnum1 == 19 || usercardnum1 == 20)
	{
		usercard1="Six";
		usercount=usercount+6;
	}
	else if (usercardnum1 == 21 || usercardnum1 == 22 || usercardnum1 == 23 || usercardnum1 == 24)
	{
		usercard1="Seven";
		usercount=usercount+7;
	}
	else if (usercardnum1 == 25 || usercardnum1 == 26 || usercardnum1 == 27 || usercardnum1 == 28)
	{
		usercard1="Eight";
		usercount=usercount+8;
	}
	else if (usercardnum1 == 29 || usercardnum1 == 30 || usercardnum1 == 31 || usercardnum1 == 32)
	{
		usercard1="Nine";
		usercount=usercount+9;
	}
	else if (usercardnum1 == 33 || usercardnum1 == 34 || usercardnum1 == 35 || usercardnum1 == 36)
	{
		usercard1="Ten";
		usercount=usercount+10;
	}
	else if (usercardnum1 == 37 || usercardnum1 == 38 || usercardnum1 == 39 || usercardnum1 == 40)
	{
		usercard1="Jack";
		usercount=usercount+10;
	}
	else if (usercardnum1 == 41 || usercardnum1 == 42 || usercardnum1 == 43 || usercardnum1 == 44)
	{
		usercard1="Queen";
		usercount=usercount+10;
	}
	else if (usercardnum1 == 45 || usercardnum1 == 46 || usercardnum1 == 47 || usercardnum1 == 48)
	{
		usercard1="King";
		usercount=usercount+10;
	}
	else if (usercardnum1 == 49 || usercardnum1 == 50 || usercardnum1 == 51 || usercardnum1 == 52)
	{
		usercard1="Ace";
		if (usercount>11)
		{
		usercount=usercount+11;

		}
		else 
		{
		usercount=usercount+1;
		}
	}
	
	//If statements determining the user's second card
	
	if (usercardnum2 == 1 || usercardnum2 == 2 || usercardnum2 == 3 || usercardnum2 == 4)
	{
		usercard2="Two";
		usercount=usercount+2;
	}
	else if (usercardnum2 == 5 || usercardnum2 == 6 || usercardnum2 == 7 || usercardnum2 == 8)
	{
		usercard2="Three";
		usercount=usercount+3;
	}
	else if (usercardnum2 == 9 || usercardnum2 == 10 || usercardnum2 == 11 || usercardnum2 == 12)
	{
		usercard2="Four";
		usercount=usercount+4;
	}
	else if (usercardnum2 == 13 || usercardnum2 == 14 || usercardnum2 == 15 || usercardnum2 == 16)
	{
		usercard2="Five";
		usercount=usercount+5;
	}
	else if (usercardnum2 == 17 || usercardnum2 == 18 || usercardnum2 == 19 || usercardnum2 == 20)
	{
		usercard2="Six";
		usercount=usercount+6;
	}
	else if (usercardnum2 == 21 || usercardnum2 == 22 || usercardnum2 == 23 || usercardnum2 == 24)
	{
		usercard2="Seven";
		usercount=usercount+7;
	}
	else if (usercardnum2 == 25 || usercardnum2 == 26 || usercardnum2 == 27 || usercardnum2 == 28)
	{
		usercard2="Eight";
		usercount=usercount+8;
	}
	else if (usercardnum2 == 29 || usercardnum2 == 30 || usercardnum2 == 31 || usercardnum2 == 32)
	{
		usercard2="Nine";
		usercount=usercount+9;
	}
	else if (usercardnum2 == 33 || usercardnum2 == 34 || usercardnum2 == 35 || usercardnum2 == 36)
	{
		usercard2="Ten";
		usercount=usercount+10;
	}
	else if (usercardnum2 == 37 || usercardnum2 == 38 || usercardnum2 == 39 || usercardnum2 == 40)
	{
		usercard2="Jack";
		usercount=usercount+10;
	}
	else if (usercardnum2 == 41 || usercardnum2 == 42 || usercardnum2 == 43 || usercardnum2 == 44)
	{
		usercard2="Queen";
		usercount=usercount+10;
	}
	else if (usercardnum2 == 45 || usercardnum2 == 46 || usercardnum2 == 47 || usercardnum2 == 48)
	{
		usercard2="King";
		usercount=usercount+10;
	}
	else if (usercardnum2 == 49 || usercardnum2 == 50 || usercardnum2 == 51 || usercardnum2 == 52)
	{
		if (usercount>11)
		{
		usercount=usercount+11;

		}
		else 
		{
		usercount=usercount+1;
		}
	}
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), //Background for first line
	 														FOREGROUND_RED |
                                                            FOREGROUND_GREEN | 
                                                            FOREGROUND_INTENSITY | 
                                                            BACKGROUND_RED
                          );
	cout<<"Computer's starting card:";
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), //Setting background back to green
                                                            BACKGROUND_GREEN
                          );
	cout<<"\n\n"<<compcard1;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), //Background for comp total
	 														FOREGROUND_RED |
                                                            FOREGROUND_GREEN | 
                                                            FOREGROUND_INTENSITY | 
                                                            BACKGROUND_RED
                          );
	cout<<"\n\nComputer Total: "<<compcount;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), //Background outlining your cards
															FOREGROUND_RED |
                                                            FOREGROUND_GREEN | 
                                                            FOREGROUND_INTENSITY | 
                                                            BACKGROUND_BLUE
                                                            
                          );
	
	cout<<"\n\nYour cards:\n\n";
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), //Setting background back to green
                                                            BACKGROUND_GREEN
                          );
	cout<<usercard1<<"\n"<<usercard2;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), //Background outlining user total
															FOREGROUND_RED |
                                                            FOREGROUND_GREEN | 
                                                            FOREGROUND_INTENSITY | 
                                                            BACKGROUND_BLUE
                                                            );
	cout<<"\n\nYour total: "<<usercount;
	
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), //Setting background back to green
                                                            BACKGROUND_GREEN
                          );
                          
    
	
    cout<<"\n\nHow much would you like to bet? $";
	cin>>betAmount; //Determining how much they want to bet	
	
	if (betAmount > balance)//Making sure the user does not go into debt without concent
			{
				
				
				cout<<"\n\nWarning, your balance is only $"<<balance<<". By betting you will be in debt to the casino\nIf you wish to continue type 'OK'. If not type 'NO'";
				cin>>warningResponse;
				
				if (warningResponse=="No"||warningResponse=="no"||warningResponse=="No")
				{
					
					//Loop to ask about deposits***WHOLE LOOP KEEPS GETTING SKIPPED***
					while (answerDeposit2!="no" /*&& answerDeposit3=="no"*/)
					{
						cout<<"\nWould you like to deposit some more money?";
						cin>>answerDeposit2;
		
						if (answerDeposit2=="yes")//If user decided to deposit more money
						{
		
							cout<<"How much would you like to deposit?";
							cin>>amountDeposit2;//taking the new deposit from user and adding it to balance
							balance=balance+amountDeposit2;
			
						}
						else if (answerDeposit2=="no") //If user does not want to deposit more money
						{
							cout<<"Alright, good luck!";
							
						}
						else 
						{
							cout<<"Sorry I didn't catch that, please respond with 'yes' or 'no'";
						}
						
						if (answerDeposit2=="no" && balance<betAmount)
						{
							system ("cls");
							cout<<"Alright man im done with you, get out of my casino!";
							exit(1);
						
							
					
						}
					}
					
				}
				cout<<"So with that in mind, how much would you like to bet?";
				cin>>betAmount; //Determining how much they want to bet
				
				balance=balance-betAmount;//Taking bet amount out of balance

			}
			
			else if (betAmount>=balance)
			{
			balance=balance-betAmount;//Taking bet amount out of balance

			}
						                    
	
											  
	while (usercount < 21 && compcount < 21)
	{
			
				
		
			
			
			
			cout<<"\n\nWould you like to hit or stand?";
			cin>>hitResponse; //Getting a response about wether to hit or not			
			
			if (hitResponse == "hit" || hitResponse == "Hit" || hitResponse == "HIT") //if user chooses hit
			{
				system ("cls");
				
				do //Regenerates usercardnum1 into a random number
				{
					randomNum = rand() % 52;
		
				} while (number[randomNum]==0);
				usercardnum1=number[randomNum];
				
				userIf();
				
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), //Background outlining your cards
															FOREGROUND_RED |
                                                            FOREGROUND_GREEN | 
                                                            FOREGROUND_INTENSITY | 
                                                            BACKGROUND_BLUE
                                                            
                          );
				cout<<"Card Recieved: \n\n";
				
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), //Setting background back to green
                                                            BACKGROUND_GREEN
                          );
				cout<<usercard1;
				
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), //Background outlining your cards
															FOREGROUND_RED |
                                                            FOREGROUND_GREEN | 
                                                            FOREGROUND_INTENSITY | 
                                                            BACKGROUND_BLUE
                                                            
                          );
				cout<<"\n\nYour total is: "<<usercount;
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), //Setting background back to green
                                                            BACKGROUND_GREEN
                          );
				
	
				
			}
			else if (hitResponse=="stand"||hitResponse=="STAND"||hitResponse=="Stand"||usercardnum1==21) 
			{
				system("cls");
				
				while (compcount < usercount && compcount < 21) //A loop making the computer continue to get cards until their cards are larger than the user's number
				{
					
				
					do //Regenerates compcardnum1 into a random number
					{
						randomNum = rand() % 52;
			
					} while (number[randomNum]==0);
					compcardnum1=number[randomNum];
					
					compIf();
					
					SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), //Background for first line
	 														FOREGROUND_RED |
                                                            FOREGROUND_GREEN | 
                                                            FOREGROUND_INTENSITY | 
                                                            BACKGROUND_RED
                                                            
                          );
					
					cout<<"\n\nCards Recieved by computer: \n\n";
					
						SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), //Setting background back to green
                                                            BACKGROUND_GREEN
                          );
                        
					cout<<compcard1;
					
					SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), //Background for first line
	 														FOREGROUND_RED |
                                                            FOREGROUND_GREEN | 
                                                            FOREGROUND_INTENSITY | 
                                                            BACKGROUND_RED
                                                            );
					cout<<"\n\nComputer total: "<<compcount;
					
						SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), //Setting background back to green
                                                            BACKGROUND_GREEN
                          );
                          
				
					
			
				}	
				if (compcount>usercount )
				{
					usercount=usercount+42;
				}
				else if (compcount < usercount)
				{
					compcount=compcount+25;
				}
				else if (compcount == usercount)
				{
					compcount+23;
					usercount+23;
				}
			}
			else 
			{
				cout<<"Sorry I didn't quite catch that, 'hit' or 'stand'?";
			}

	}
	 	
	
		if (usercount > compcount && usercount < 22 || compcount > 21)//Condition if user has larger score
			{
				balance=balance+betAmount*2; //Giving the user the money they win
				cout<<"\n\nYou Win!";
				winCount++;
			}
			else if (usercount < compcount || usercount > 21 )
			{
			
				cout<<"\n\nYou lose :("; //Informing users they lost
				lossCount++;
			}
			else if (usercount == compcount) 
			{
				cout<<"\n\nIt's a tie!"; //Informing the user it is a tie
				tieCount++;;
			}

	cout<<"Scores:\n\nWins: "<<winCount<<"\nLosses: "<<lossCount<<"\nTies: "<<tieCount<<"\n\nWould you like to quit or continue (type 'quit' to quit)?";
	cin>>finalResponse;
	
	if (finalResponse=="quit"||finalResponse=="QUIT"||finalResponse=="Quit") //Giving the user the option to leave
	{
		system ("cls");
		cout<<"Thanks for playing! You get to take home $"<<balance;
		exit(1);
	}
}
	
}


	
	

	



