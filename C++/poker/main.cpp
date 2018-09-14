// main.cpp

#include "card.h"
#include "poker.h"
#include "card_deck.h"

int main(int argc, char** argv) {
	card_deck d = card_deck();

	d.shuffle();

	for (int i = 1; i <= 52; i++) {
		cout << d.deal() << endl;
	}

	cout << d;

	return(0);
}
