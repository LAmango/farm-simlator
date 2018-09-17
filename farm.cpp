//main.cpp

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

void mainMenu()
{
	std::cout << "What would you like to do?\n";
	std::cout << "Start: s\nShow Total: t\nReset: r\n";
}

int main(){

	std::ofstream fileout;
	std::ifstream filein;
	filein.open("chart.txt");

	int random;
	int ct = 0;
	srand(time(0));
	int chart[9] = {0};
	int temp[9] = {0};
	int num[9];
	char choice;

	//load in the saved frequencies
	while(ct < 9)
	{
		filein 	>> temp[ct];
		ct++;
	}
	filein.close();

	//main menu
	mainMenu();
	std::cin >> choice;  

	switch(choice) {
		case 's':
		while(choice != '\n') {
			fileout.open("chart.txt");
		
	std::cout << "dice rolled: " <<std::endl;
	std::cout << "******************************" << std::endl;

	for (int i = 0; i < 9; ++i)
	{
		random = (rand() % 9);
		if(random == 1)
			chart[i]++;
	}
	std::cout << "N|F" << std::endl;
	for(int j = 0; j < 9; ++j)
	{
		std::cout << j+1 << "|" << chart[j] << std::endl;
		num[j] = chart[j] + temp[j];
		fileout << " " << num[j];
	}

	fileout.close();
	std::cin.get(choice);
	}
	break;
	case 'r':
		fileout.open("chart.txt");

		for (int i = 0; i < 9; ++i)
		{
			fileout << " " << 0;
		}

		fileout.close();
		break;
	case 't':
		for (int i = 0; i < 9; ++i)
		{
			std::cout << temp[i] << "\n";
		}
	default:
	break;
	}

	return 0;
}
