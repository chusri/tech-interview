// This class models the game of Poker.

#ifndef POKER_H
#define POKER_H

#include "card.h"
#include "deck.h"

const int POKER_HAND_SIZE = 5;

class poker {
	public:
		bool is_flush(const vector<card>& hand);
		bool is_straight(const vector<card>& hand);
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

// Is the poker hand a straight?
bool poker::is_straight(const vector<card>& hand) {
	assert(hand.size() == POKER_HAND_SIZE);

	vector<int> pips;

	for_each(hand.begin(), hand.end(), [&pips](const card c) {
			assert(c.get_pips() >= 1 && c.get_pips() <= SUIT_SIZE);
			pips.push_back(c.get_pips());
	});

	sort(pips.begin(), pips.end());

	if (pips[0] != 1) {
		// non-Aces
		return(pips[0] == pips[1]-1 && pips[1] == pips[2]-1 &&
					 pips[2] == pips[3]-1 && pips[3] == pips[4]-1);
	} else {
		// Aces need special logic
		return((pips[0] == pips[1]-1 && pips[1] == pips[2]-1  &&
						pips[2] == pips[3]-1 && pips[3] == pips[4]-1) ||
					 (pips[1] == 10 && pips[2] == 11 && pips[3] == 12 && pips[4] == 13));
	}
}

// Print the hand
void poker::print_hand(const vector<card>& hand) {
	assert(hand.size() == POKER_HAND_SIZE);

	for (auto card:hand) {
		cout << card << endl;
	}
}

#endif //POKER_H
