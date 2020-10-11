#include <iostream>
#include <ctime>
#include <conio.h>

int pCard;
int aCard;
int pSum;//player sum
int aSum;//AI sum
int pMoney = 100;
int aMoney = 100;

void pPickCard() {
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	pCard = rand() % 10 + 1;
	pSum += pCard;

}
void aPickCard() {
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	aCard = rand() % 10 + 1;
	aSum += aCard;

}

void info() {
	std::cout << "Press p to pick new card\n";
	std::cout << "Press s to stand\n";
	std::cout << "Press i to recieve info again\n";
	std::cout << "You will start with 100$, the minimum fee for starting a game is 10$\n";
 }

void AIplay() {
	aPickCard();

}

void ifAce(){
	
	int ace;
	bool valid = true;
	do {
		if (pCard == 1) {
			//system("cls");
			std::cout << "Sum : " << pSum << "\n";
			std::cout << "You picked an ace, do you want it to count as 1 or 11? ";
			std::cin >> ace;

			if (ace == 1) {
				valid = true;
				pCard = 1;
			}
			else if (ace == 11) {
				pSum += 10;
				pCard = 11;
				valid = true;
			}
			else {
				std::cout << "Not valid, try again\n";
				valid = false;
				system("pause");
			}
		}
	} while (valid == false);
}


int main() {
	bool roundDone = false;
	char input;

	std::cout << "Rules : \n\n";
	info();
	pPickCard();
	std::cout << "\n";
	system("pause");
	system("cls");
	//ifAce();
	do {
		system("cls");
		ifAce();
		
		std::cout << "You picked a " <<pCard << "\n";
		std::cout << "Sum : " << pSum << "\n";


		//game conditions
		if (pSum > 21) {
			std::cout << "Your sum is over 21, dealer wins";
			roundDone = true;
		}
		else if (pSum <= 21) {

			input = _getch();
			//player choices
			if (input == 'p') {
				pPickCard();

				
				

			}
			else if (input == 's') {
				bool aRoundDone = false;
				do {
					AIplay();

					std::cout << "Dealer picked " << aCard << "\n";
					std::cout << "Sum : " << aSum << "\n";

					if (aCard == 1) {
						std::cout << "Dealer picked an ace";

						if (aSum <= 10) {
							aSum += 10;
							std::cout << ", the dealer chooses it to count as 11\n";
						}
						else if (aSum > 11) {
							std::cout << ", the dealer chooses it to count as 1\n";
						}

					}


					if (aSum > pSum && aSum < 21) {
						std::cout << "Dealer wins! ";
						aRoundDone = true;
						roundDone = true;
					}
					else if (aSum > 21) {
						std::cout << "You win! ";
						aRoundDone = true;
						roundDone = true;
					}
					else {
						system("pause");
						//system("cls");
					}
					
				} while (aRoundDone == false);
			}
			else if (input == 'i') {
				info();
				system("pause");
			}
		}
		
	} while (roundDone == false);

}
