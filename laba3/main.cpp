#include"Menu.h"
#define EXIT_MENU_OPTIONS 6

void Menu()
{
	//Реализация функций меню
	int option;
	do
	{
		Options();
		option = Choose();

		switch (option)
		{
		case 1:
		{
			system("cls");
			DemoBook();
			break;
		}
		case 2:
		{
			system("cls");
			//DemoRoute();
			break;
		}
		case 3:
		{
			system("cls");
			DemoRectangleWithPoint();
			break;
		}
		case 4:
		{
			system("cls");
			//DemoFlightWithTime();
			break;
		}
		case 5:
		{
			system("cls");
			DemoBand();
			break;
		}
		}
	} while (option != EXIT_MENU_OPTIONS);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Menu();
	return 0;
}

void Options()
{
	cout << "================================================" << endl;
	cout << "					____________MAIN_____________" << endl;
	cout << "Focus on Experimenting, trying new things, creativity, and intrinsic pleasure of what you do." << endl;
	cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
	cout <<	"[                       CHOOSE AN OPTION!.										  ]" << endl;
	cout << "[   1. Book																	  ]" << endl;
	cout << "[   2. Route																	  ]" << endl;
	cout << "[   3. Rectangle															      ]" << endl;
	cout << "[   4. Flight																	  ]" << endl;
	cout << "[   5. Band																	  ]" << endl;
	cout << "[   6. Exit																	  ]" << endl;
	cout << "[}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}]" << endl;

}

int Choose()
{
	int number;
	while (true)
	{
		cin >> number;
		if ((cin.good()) && (number <= EXIT_MENU_OPTIONS) && (number > 0))
		{
			cin.ignore(10, '\n');
			break;
		}
		cin.clear();
		cout << "\nThe number is out of range." << endl;
		cin.ignore(10, '\n');
	}
	return number;
}
