// main.cpp

#include "card.h"
#include "deck.h"
#include "poker.h"

int main(int argc, char** argv) {
	deck d = deck();

	d.shuffle();

	for (int i = 1; i <= 52; i++) {
		cout << d.deal() << endl;
	}

	cout << d;

	return(0);
}
