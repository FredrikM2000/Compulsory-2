#include <iostream>
#include <ctime>
#include <conio.h>

int pCard;
int aCard;
int pSum;//player sum
int aSum;//AI sum

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
 }

void AIplay() {
	aPickCard();

}




int main() {
	bool roundDone = false;
	char input;

	std::cout << "Rules : \n\n";
	info();
	pPickCard();
	std::cout << "\n";
	system("pause");
	do {
		system("cls");
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
