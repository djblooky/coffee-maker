/*A coffee maker must have a water reservoir and bean hopper and a bean grinder. 

A user must be able to make as many as 5 cups of coffee at once with our coffee maker

To make a cup of coffee, there must be enough beans in the hopper, and there must be enough water in the reservoir to make 
the amount of cups requested. Beans, in their natural state cannot make coffee, and they must be ground. Each step of this 
process must be checked for and verified before continuing to the next step.

Conversions =>

1 liter of water is 2 cups
25 beans -> 1 cup */

#include "stdafx.h"
#include <iostream>

double cups;
bool enoughBeans = true;
bool enoughWater = true;
bool finished = false;
bool checks = true;
bool replay = false;
double beans;
double litersOfWater;

void GrindBeans() 
{
	if (enoughBeans && enoughWater) {
		std::cout << "\tGrinding beans..." << std::endl;
		finished = true;
	}	
}

void CheckHopper(double beans)
{
	std::cout << "\tChecking hopper..." << std::endl;

	if (beans / cups < 25) { //if there arent enough beans for the desired amount of coffee cups
		checks = false;
		enoughBeans = false;
	}
}

void CheckReservoir(double litersOfWater)
{
	if (enoughBeans) {
		std::cout << "\tChecking reservoir..." << std::endl;
	}	

	if (litersOfWater < cups / 2) { //if there isnt enough water for the desired amount of coffee cups
		checks = false;
		enoughWater = false;
	}
}

void DisplayError(bool checks)
{
	if (!checks) {
		if (!enoughBeans) {
			std::cout << "\n\tNot enough beans!" << std::endl;
		}
		if (!enoughWater) {
			std::cout << "\n\tNot enough water!" << std::endl;
		}
	}
	else if (finished) {
		std::cout << "\n\tBrew success!" << std::endl;
	}
}

void Brew(int cups)
{
	CheckHopper(beans);
	DisplayError(checks); //specifies what check failed to user

	CheckReservoir(litersOfWater);
	if (enoughBeans){ //if there arent any failed checks yet
		DisplayError(checks);
	}
		

	GrindBeans();
	if (enoughWater) {
		DisplayError(checks);
	}
		
}

void Replay() //asks if user wants to use the coffee maker again
{
	int playAgain;
	std::cout << "\n\tMake more coffee?\n\t1. Yes 2. No" << std::endl;
	std::cin >> playAgain;

	if (playAgain == 1) {
		checks = true;
		enoughBeans = true;
		enoughWater = true;
		replay = true;
		finished = false;
	}
	else {
		replay = false;
	}

}

void FillMachine() 
{
	std::cout << "\tKeep in mind:\n\t1 liter of water is 2 cups\n\t 25 beans are in 1 cup" << std::endl;

	do{
		std::cout << "\n\tHow many cups would you like to brew?" << std::endl;
		std::cin >> cups;

	} while (cups <= 0);
	
	std::cout << "\tHow many beans will you put in?" << std::endl;
	std::cin >> beans;

	std::cout << "\tHow many liters of water?" << std::endl;
	std::cin >> litersOfWater;
}

int main()
{
	do { 
		FillMachine();
		Brew(cups);
		Replay();

	} while (replay);
	

    return 0;
}

