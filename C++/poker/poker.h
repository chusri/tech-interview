// This class models the game of Poker.

#ifndef POKER_H
#define POKER_H

#include "card.h"
#include "deck.h"

const int POKER_HAND_SIZE = 5;

class poker {
	public:
		bool is_flush(const vector<card>& hand);
		void print_hand(const vector<card>& hand);
};

// Do all the cards in the hand belong to the same suit?
bool poker::is_flush(const vector<card>& hand) {
	assert(hand.size() == POKER_HAND_SIZE);
	assert(hand[0].get_pips() >= 1 && hand[0].get_pips() <= SUIT_SIZE);

	suit s = hand[0].get_suit();

	for (int i = 1; i < hand.size(); i++) {
		assert(hand[i].get_pips() >= 1 && hand[i].get_pips() <= SUIT_SIZE);

		if (hand[i].get_suit() != s) {
			return(false);
		}
	}

	return(true);
}

// Print the hand
void poker::print_hand(const vector<card>& hand) {
	assert(hand.size() == POKER_HAND_SIZE);

	for (auto card:hand) {
		cout << card << endl;
	}
}

#endif //POKER_H
