// main.cpp

#include "poker.h"

int main(int argc, char** argv) {
	deck d;
	poker p;
	vector<card> hand;

	// Shuffle the deck
	d.shuffle();

	for (int i = 0; i < POKER_HAND_SIZE; i++) {
		hand.push_back(d.deal());
	}

	p.print_hand(hand);

	cout << p.is_flush(hand) << endl;
	cout << p.is_straight(hand) << endl;
	cout << p.is_straight_flush(hand) << endl;

	return(0);
}
