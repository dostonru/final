#include<iostream>
#include<cstdlib>
#include<Windows.h>
using namespace std;

void MAIN_MENU();

class MyRestaurant
{
private:
	string table[10], phrases[5] = {"Cool!","Okey.","Hmm..","Good!","Excellent!" };
	bool checkTable[10] = { 1,0,0,0,0,0,0,1,0,0};
	int choice = 0;
public:

	void Initialization()
	{
		for (int i = 0; i < 10; i++)
		{
			if (checkTable[i] == false)
				table[i] = "Free\t";
			else
				table[i] = "Reserved";
		}
	}
	void DisplayTable()
	{
		cout << "\n";
		for(int i = 0 ;i<10;i++)
		cout << " |> " << i + 1 << "  table\t: \t" <<table[i] << " \t<| " <<endl;
		cout << "  --------------------------------------" <<endl<<endl;
	}
	void BookingProcess()
	{
		
		cout << "\n  Which table you want to reserve? " << endl;
		cin >> choice;
		if (choice > 10 || choice < 0)
		{
			cout << "\nYou sure? Because we dont have such table.\n";
			Sleep(1000);
			BookingProcess();
		}
		if (choice == 0)
		{
			MAIN_MENU();
		}
		if (checkTable[choice - 1] == false)
		{
			
			
			checkTable[choice - 1] = true;
			cout << endl;
			cout << phrases[ rand() % 4];
			cout << "We reserved table " << choice;
			Sleep(3000);
		}
		else
		{
			cout << "\nSorry.This table is booked.\nHere is number of free tables.\n" << endl;
			Sleep(5000);
			for (int i = 0; i < 10; i++)
			{
				if (checkTable[i] == false)
				{
					cout <<" | "<<  i + 1 ;
				}
			}
			cout << endl;
			BookingProcess();
		}

		
	}
	
};

class FOOD:public MyRestaurant
{
private:
	string soup[7], meet[5], beverage[10], basket[20];
	bool basketcheck[20] = {false};
	int choice,choice2;
	double temp = 0,sPrice[7],mPrice[5],bPrice[10],total =0;
	char cho;
public:
	FOOD()
	{
		//SOUPS 6 TYPES
		soup[0] = " | SOUP WITH MEAT\t  |";
		soup[1] = " | SOUP WITHOUT MEAT\t  |";
		soup[2] = " | CHICKEN SOUP\t\t\  |";
		soup[3] = " | TOMATO SOUP\t\t  |";
		soup[4] = " | SALMON SOUP\t\t  |";
		soup[5] = " | SOUP VERDE\t\t  |";
		soup[6] = " | HUNGARIAN SOUP\t  |";
		
		//SOUP PRICES
		sPrice[0] = 10.5;
		sPrice[1] = 9.5;
		sPrice[2] = 7.5;
		sPrice[3] = 5.5;
		sPrice[4] = 13.5;
		sPrice[5] = 11.5;
		sPrice[6] = 15.5;


		//MEATS	      
		meet[0] = " | GRILLED BEEF TENDERLOIN|";
		meet[1] = " | FLANK STEAK\t\t  |";
		meet[2] = " | CHOPPED STEAK\t  |";
		meet[3] = " | JARENNIY MEAT\t  |";
		meet[4] = " | DUCK FILLET\t\t  |";

		//MEAT PRICES
		mPrice[0] = 45.5;
		mPrice[1] = 59.5;
		mPrice[2] = 32.5;
		mPrice[3] = 10.5;
		mPrice[4] = 38.5;

		//BEVERAGES
		beverage[0] = " | COLA\t\t\t  |";
		beverage[1] = " | SPRITE\t\t  |";
		beverage[2] = " | RED VINE\t\t  |";
		beverage[3] = " | WHITE VINE\t\t  |";
		beverage[4] = " | VODKA\t\t  |";
		beverage[5] = " | JUICE\t\t  |";
		beverage[6] = " | FANTA\t\t  |";
		beverage[7] = " | TEA\t\t\t  |";
		beverage[8] = " | ESPRESSO\t\t  |";
		beverage[9] = " | LATTE\t\t  |";

		//BEVERAGE PRICES
		bPrice[0] = 1.5;
		bPrice[1] = 1.5;
		bPrice[2] = 9.5;
		bPrice[3] = 9.5;
		bPrice[4] = 9.5;
		bPrice[5] = 4.5;
		bPrice[6] = 1.5;
		bPrice[7] = 0.5;
		bPrice[8] = 3.5;
		bPrice[9] = 4.5;


	}
	~FOOD() {};
	void Basket()
	{
		string number;
		FOOD* food = new FOOD;
		do
		{
			system("cls");
			cout << " \t\tMENU\n\n | SOUPS SECTION\t|   1   |\n | BEVERAGES\t\t|   2   |\n | MEAT SECTiON\t\t|   3   |\n | BASKET\t\t|   4   |\n | EXIT\t\t\t|   5   |\n";
			cin >> choice;
			switch (choice)
			{
			case 1:
				system("cls");
				cout << " | SOUPS\t\t|\n\n";
				for (int i = 0; i < 7; i++)
				{
					cout << soup[i] <<"  "<< i + 1<<"  | "<< "   " << sPrice[i] << "\t|" << endl;
				}
				
				cout << "\n\n\tWHAT DO YOU WANT TO ADD TO YOUR BASKET?\n";
				cin >> choice2;

				for (int i = 0; i < 20; i++)
				{
					if (choice2 > 7 || choice2 < 0)
					{
						cout << "\nError!\n";
						Sleep(1000);
						break;
					}
					if (basketcheck[i] == false)
					{
						basketcheck[i] = true;
						basket[i] = soup[choice2 - 1];
						total += sPrice[choice2 - 1];
						cout << "\nADDED\n";
						Sleep(2000);
						break;
					}

				}
				break;
			case 2:
				system("cls");
				cout << " \t BEVERAGES\t\t\n";
				for (int i = 0; i < 10; i++)
				{
					cout << beverage[i] << "  " << i + 1 << "\t|" << "   " << bPrice[i] << "\t|" << endl;
				}
				
				cout << "\n\n\tWHAT DO YOU WANT TO ADD TO YOUR BASKET?\n";
				cin >> choice2;
				for (int i = 0; i < 20; i++)
				{
					if (choice2 > 10 || choice2 < 0)
					{
						cout << "\nError!\n";
						Sleep(1000);
						break;
					}
					if (basketcheck[i] == false)
					{
						basketcheck[i] = true;
						basket[i] = beverage[choice2 - 1];
						total += bPrice[choice2 - 1];
						cout << "\nADDED\n";
						Sleep(2000);
						break;
					}

				}
				break;
			case 3:
				system("cls");
				cout << " \t\t MEAT\t\t\n";
				for (int i = 0; i < 5; i++)
				{
					cout << meet[i] << "  " << i+1 << "\t|" << "   " << mPrice[i] << "\t|" << endl;
				}
				cout << "\n\n\tWHAT DO YOU WANT TO ADD TO YOUR BASKET?\n";
				cin >> choice2;
				
				for (int i = 0; i < 20; i++)
				{
					if (choice2 > 5 || choice2 < 0)
					{
						cout << "\nError!\n";
						Sleep(1000);
						break;
					}
					if (basketcheck[i] == false)
					{
						basket[i] = meet[choice2 - 1];
						total += mPrice[choice2 - 1];
						basketcheck[i] = true;
						cout << "\nADDED\n";
						Sleep(2000);
						break;
					}

				}
				break;
			case 4:
				system("cls");
				cout << "\tYOUR BASKET\t\n\n";
				
				for (int i = 0; i < 20; i++)
				{

					if (basketcheck[i] == true)
					{
						cout << basket[i] << endl;
						temp++;
					}


				}
				
				if (temp == 0)
				{
					cout << "\n\tYOUR BASKET IS EMPTY\n";
					
				}
				if (temp > 0)
				{
					cout << "\n | TOTAL : " << total << "$";
					cout << "\n\nCONTINUE SHOPPING(s) OR PURCHUASE(p)?\n";
					cin >> cho;
					if (cho == 'p')
					{
						cout << "AMOUNT OF MONEY YOU HAVE TO PAY : "  << total<< "$"<< endl;
						cout << "Enter your card number : ";
						cin >> number;
						Sleep(3000);
						delete food;
						for (int i = 0; i < 20; i++)
						{
							basketcheck[i] = false;
						}
						total = 0;
						temp = 0;
						cout << "\nYou did it!" << endl;
						Sleep(1000);
					}
				
				}
				Sleep(1000);
				break;
			case 5:
				break;
			default:
				cout << "WRONG INPUT";
				break;

			}
			

		} while (choice != 5);
	}
};

void MAIN_MENU()
{
	char choice;
	string feedback;
	FOOD* food = new FOOD;
	do 
	{
		system("cls");
		cout << "\tWHAT DO YOU WANT TO DO?";
		cout << "\n\n\t| \033[37;44m\033[1mR\033[0mESERVE A TABLE |  1  |";
		cout << "  \n\t| \033[37;44m\033[1mF\033[0mOOD DELIVERY   |  2  |";
		cout << "  \n\t| FEEDBACK        |  3  |";
		cout << "  \n\t| \033[37;44m\033[1mC\033[0mONTACTS        |  4  |";
		cout << "  \n\t| \033[37;44m\033[1mA\033[0mDDRESS         |  5  |";
		cout << "  \n\t| \033[37;44m\033[1mE\033[0mXIT            |  6  |\n";
		cout << "\n\t";
		cin >> choice;
		switch (choice)
		{
		case '1':
			system("cls"); 
			cout << " |                TABLES                 |";
			food->Initialization();
			food->DisplayTable();
			food->BookingProcess();
			break;
		case '2':
			system("cls");
			food->Basket();
			break;
		case '3':
			system("cls");
			cout << "  LEFT YOUR FEEDBACK BELOW\n";
			cin >> feedback;
			cout << endl << "THANK YOU!";
			Sleep(1000);
			break;
		case '4':
			system("cls");
			cout << "\n | DOSTON   (CHIEF)      - 90 000 00 00";
			cout << "\n | SHODIYOR (DISHWASHER) - 91 135 19 37";
			Sleep(5000);
			break;
		case '5':
			system("cls");
			cout << "\n  NEAR THE AIRPORT , NEW YORK , USA \n  ZIP : 158 100\n\n  MAP\n ";
			cout << "\n  '''''''''''''''''''''''''''''|'''-''''";
			cout << "\n  ____'''''''''''''''''''''''''|'''-''''";
			cout << "\n  \\\\\\\\\\''<-SALT BAE''''''''''''|'''-''''";
			cout << "\n  ____|''''''''''''''''''''''''|'''-''''";
			cout << "\n  '''''''''''''''''''''''''''''|'''-''''";
			cout << "\n  '''''''''''''''''''''''''''''|'''-''''";
			cout << "\n  '''''''''''''''''''''''''''''|'''|''''";
			cout << "\n  '''''''''''''''''''''''''''''|''/|\\'''";
			cout << "\n  '''|RAILWAY|'''''''''''''''''|'''^''''";
			cout << "\n  ] ] ] ] ] ] ] ] ] ] ] ] ]'''''''''''''";
			cout << "\n  ''''''''''''''''''''''''''''''''''''''";
			cout << "\n  ''''''''''''''''''''''''''''''''''''''";

			cout << "\n\n\n copyright\n all rights reserved\n D&S restaurant 1980 - 2020";
			Sleep(5000);
			break;
		case '6':
			break;
		case 'r':
			system("cls");
			cout << " |                TABLES                 |";
			food->Initialization();
			food->DisplayTable();
			food->BookingProcess();
			break;
		case 'f':
			system("cls");
			food->Basket();
			break;
		case 'c':
			system("cls");
			cout << "\n | DOSTON   (CHIEF)      - 90 000 00 00";
			cout << "\n | SHODIYOR (DISHWASHER) - 91 135 19 37";
			Sleep(5000);
			break;
		case 'a':
			system("cls");
			cout << "\n  NEAR THE AIRPORT , NEW YORK , USA \n  ZIP : 158 100\n\n  MAP\n ";
			cout << "\n  '''''''''''''''''''''''''''''|'''-''''";
			cout << "\n  ____'''''''''''''''''''''''''|'''-''''";
			cout << "\n  \\\\\\\\\\''<-SALT BAE''''''''''''|'''-''''";
			cout << "\n  ____|''''''''''''''''''''''''|'''-''''";
			cout << "\n  '''''''''''''''''''''''''''''|'''-''''";
			cout << "\n  '''''''''''''''''''''''''''''|'''-''''";
			cout << "\n  '''''''''''''''''''''''''''''|'''|''''";
			cout << "\n  '''''''''''''''''''''''''''''|''/|\\'''";
			cout << "\n  '''|RAILWAY|'''''''''''''''''|'''^''''";
			cout << "\n  ] ] ] ] ] ] ] ] ] ] ] ] ]'''''''''''''";
			cout << "\n  ''''''''''''''''''''''''''''''''''''''";
			cout << "\n  ''''''''''''''''''''''''''''''''''''''";

			cout << "\n\n\n copyright\n all rights reserved\n D&S restaurant 1980 - 2020";
			Sleep(5000);
			break;
		case 'e':
			break;
		default:
			cout << "\nTry again\n";
			Sleep(600);
			break;
		}
	} while (choice != '6');

}

int main()
{
	
	cout << ">------------------------------------------<" << endl;
	Sleep(600);
	cout << ">------------------------------------------<" << endl;
	Sleep(600);
	cout << ">------------------------------------------<" << endl;
	Sleep(600);
	cout << ">------------------------------------------<" << endl;
	Sleep(600);
	system("cls");
	cout << ">-----------------RESTAURANT---------------<" << endl;
	cout << ">------------------------------------------<" << endl;
	cout << ">------------------------------------------<" << endl;
	cout << ">------------------------------------------<" << endl;
	cout << ">------------------------------------------<" << endl;
	Sleep(600);
	system("cls");
	cout << ">---------------WELCOME-TO-OUR-------------<" << endl;
	cout << ">-----------------RESTAURANT---------------<" << endl;
	cout << ">------------------------------------------<" << endl;
	cout << ">------------------------------------------<" << endl;
	cout << ">------------------------------------------<" << endl;
	Sleep(600);
	system("cls");
	cout << ">------------------------------------------<" << endl;
	cout << ">---------------WELCOME-TO-OUR-------------<" << endl;
	cout << ">-----------------RESTAURANT---------------<" << endl;
	cout << ">------------------------------------------<" << endl;
	cout << ">------------------------------------------<" << endl;
	cout << ">------------------------------------------<" << endl;
	cout << ">------------------------------------------<" << endl;
	Sleep(600);
	system("cls");
	cout << ">------------------------------------------<" << endl;
	cout << ">------------------------------------------<" << endl;
	cout << ">---------------WELCOME-TO-OUR-------------<" << endl;
	cout << ">-----------------RESTAURANT---------------<" << endl;
	cout << ">------------------------------------------<" << endl;
	cout << ">------------------------------------------<" << endl;
	cout << ">------------------------------------------<" << endl;
	cout << ">------------------------------------------<" << endl;
	Sleep(600);
	system("cls");
	cout << ">------------------------------------------<" << endl;
	cout << ">------------------------------------------<" << endl;
	cout << ">------------------------------------------<" << endl;
	cout << ">---------------WELCOME-TO-OUR-------------<" << endl;
	cout << ">-----------------RESTAURANT---------------<" << endl;
	cout << ">------------------------------------------<" << endl;
	cout << ">------------------------------------------<" << endl;
	cout << ">------------------------------------------<" << endl;
	cout << ">------------------------------------------<" << endl;
	Sleep(600);
	system("cls");
	cout << ">------------------------------------------<" << endl;
	cout << ">------------------------------------------<" << endl;
	cout << ">------------------------------------------<" << endl;
	cout << ">------------------------------------------<" << endl;
	cout << ">---------------WELCOME-TO-OUR-------------<" << endl;
	cout << ">-----------------RESTAURANT---------------<" << endl;
	cout << ">------------------------------------------<" << endl;
	cout << ">------------------------------------------<" << endl;
	cout << ">------------------------------------------<" << endl;
	cout << ">------------------------------------------<" << endl;
	Sleep(400);
	system("cls");
	cout << "  >--------------------------------------<  " << endl;
	cout << "  >--------------------------------------<  " << endl;
	cout << "  >--------------------------------------<  " << endl;
	cout << "  >--------------------------------------<  " << endl;
	cout << "  >-------------WELCOME-TO-OUR-----------<  " << endl;
	cout << "  >---------------RESTAURANT-------------<  " << endl;
	cout << "  >--------------------------------------<  " << endl;
	cout << "  >--------------------------------------<  " << endl;
	cout << "  >--------------------------------------<  " << endl;
	cout << "  >--------------------------------------<  " << endl;
	Sleep(400);
	system("cls");
	cout << "    >----------------------------------<    " << endl;
	cout << "    >----------------------------------<    " << endl;
	cout << "    >----------------------------------<    " << endl;
	cout << "    >----------------------------------<    " << endl;
	cout << "    >-----------WELCOME-TO-OUR---------<    " << endl;
	cout << "    >-------------RESTAURANT-----------<    " << endl;
	cout << "    >----------------------------------<    " << endl;
	cout << "    >----------------------------------<    " << endl;
	cout << "    >----------------------------------<    " << endl;
	cout << "    >----------------------------------<    " << endl;
	Sleep(400);
	system("cls");
	cout << "      >------------------------------<      " << endl;
	cout << "      >------------------------------<      " << endl;
	cout << "      >------------------------------<      " << endl;
	cout << "      >------------------------------<      " << endl;
	cout << "      >---------WELCOME-TO-OUR-------<      " << endl;
	cout << "      >-----------RESTAURANT---------<      " << endl;
	cout << "      >------------------------------<      " << endl;
	cout << "      >------------------------------<      " << endl;
	cout << "      >------------------------------<      " << endl;
	cout << "      >------------------------------<      " << endl;
	Sleep(400);
	system("cls");
	cout << "        >--------------------------<        " << endl;
	cout << "        >--------------------------<        " << endl;
	cout << "        >--------------------------<        " << endl;
	cout << "        >--------------------------<        " << endl;
	cout << "        >-------WELCOME-TO-OUR-----<        " << endl;
	cout << "        >---------RESTAURANT-------<        " << endl;
	cout << "        >--------------------------<        " << endl;
	cout << "        >--------------------------<        " << endl;
	cout << "        >--------------------------<        " << endl;
	cout << "        >--------------------------<        " << endl;
	Sleep(400);
	system("cls");
	cout << "          >----------------------<          " << endl;
	cout << "          >----------------------<          " << endl;
	cout << "          >----------------------<          " << endl;
	cout << "          >----------------------<          " << endl;
	cout << "          >-----WELCOME-TO-OUR---<          " << endl;
	cout << "          >-------RESTAURANT-----<          " << endl;
	cout << "          >----------------------<          " << endl;
	cout << "          >----------------------<          " << endl;
	cout << "          >----------------------<          " << endl;
	cout << "          >----------------------<          " << endl;
	Sleep(400);
	system("cls");
	cout << "            >------------------<            " << endl;
	cout << "            >------------------<            " << endl;
	cout << "            >------------------<            " << endl;
	cout << "            >------------------<            " << endl;
	cout << "            >---WELCOME-TO-OUR-<            " << endl;
	cout << "            >-----RESTAURANT---<            " << endl;
	cout << "            >------------------<            " << endl;
	cout << "            >------------------<            " << endl;
	cout << "            >------------------<            " << endl;
	cout << "            >------------------<            " << endl;
	Sleep(400);
	system("cls");
	cout << "              >--------------<              " << endl;
	cout << "              >--------------<              " << endl;
	cout << "              >--------------<              " << endl;
	cout << "              >--------------<              " << endl;
	cout << "              >-WELCOME-TO-OU<              " << endl;
	cout << "              >---RESTAURANT-<              " << endl;
	cout << "              >--------------<              " << endl;
	cout << "              >--------------<              " << endl;
	cout << "              >--------------<              " << endl;
	cout << "              >--------------<              " << endl;
	Sleep(400);
	system("cls");
	cout << "                >----------<                " << endl;
	cout << "                >----------<                " << endl;
	cout << "                >----------<                " << endl;
	cout << "                >----------<                " << endl;
	cout << "                >ELCOME-TO-<                " << endl;
	cout << "                >-RESTAURAN<                " << endl;
	cout << "                >----------<                " << endl;
	cout << "                >----------<                " << endl;
	cout << "                >----------<                " << endl;
	cout << "                >----------<                " << endl;
	Sleep(400);
	system("cls");
	cout << "                  >------<                  " << endl;
	cout << "                  >------<                  " << endl;
	cout << "                  >------<                  " << endl;
	cout << "                  >------<                  " << endl;
	cout << "                  >COME-T<                  " << endl;
	cout << "                  >ESTAUR<                  " << endl;
	cout << "                  >------<                  " << endl;
	cout << "                  >------<                  " << endl;
	cout << "                  >------<                  " << endl;
	cout << "                  >------<                  " << endl;
	Sleep(400);
	system("cls");
	cout << "                    >--<                    " << endl;
	cout << "                    >--<                    " << endl;
	cout << "                    >--<                    " << endl;
	cout << "                    >--<                    " << endl;
	cout << "                    >ME<                    " << endl;
	cout << "                    >TA<                    " << endl;
	cout << "                    >--<                    " << endl;
	cout << "                    >--<                    " << endl;
	cout << "                    >--<                    " << endl;
	cout << "                    >--<                    " << endl;
	Sleep(400);
	system("cls");
	cout << "                     ><                     " << endl;
	cout << "                     ><                     " << endl;
	cout << "                     ><                     " << endl;
	cout << "                     ><                     " << endl;
	cout << "                     ><                     " << endl;
	cout << "                     ><                     " << endl;
	cout << "                     ><                     " << endl;
	cout << "                     ><                     " << endl;
	cout << "                     ><                     " << endl;
	cout << "                     ><                     " << endl;
	Sleep(400);
	system("cls");
	MAIN_MENU();
	system("pause");


	return 0;
}