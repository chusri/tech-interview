// main.cpp

#include "card.h"
#include "deck.h"
#include "poker.h"

int main(int argc, char** argv) {
	deck d = deck();
	d.shuffle();

	for (int i = 1; i <= 52; i++) {
		d.deal();
	}

	cout << d.return_to_deck(card(suit::HEART, 7)) << endl;
	cout << d.return_to_deck(card(suit::HEART, 7)) << endl;
	cout << d.return_to_deck(card(suit::SPADE, 6)) << endl;
	cout << d.return_to_deck(card(suit::SPADE, 6)) << endl;

	for (int i = 1; i <= 13; i++) {
		d.return_to_deck(card(suit::SPADE, i));
		d.return_to_deck(card(suit::HEART, i));
		d.return_to_deck(card(suit::DIAMOND, i));
		d.return_to_deck(card(suit::CLUB, i));
	}

	cout << d;

	return(0);
}
