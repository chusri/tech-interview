// This class models a deck of cards.

#ifndef CARD_DECK_H
#define CARD_DECK_H

#include "card.h"
#include<vector>
#include<algorithm>

const int SUIT_SIZE = 13;
const int DECK_SIZE = 52;

class card_deck {
	private:
		vector<card> deck;

	public:
		card_deck(void);
		card deal(void);
		void shuffle(void);

		// Overload the << operator
		friend ostream& operator<< (ostream& out, const card_deck& d) {
			for_each(d.deck.begin(), d.deck.end(),
							 [&out](const card c){out << c << endl;});
			return(out);
		}
};

// Constructor
card_deck::card_deck(void) {
	vector<suit> v = {suit::SPADE, suit::HEART, suit::DIAMOND, suit::CLUB};

	for_each(v.begin(), v.end(), [this](const suit s) {
		for (int i = 1; i <= SUIT_SIZE; i++) {
			this->deck.push_back(card(s, i));
		}
	});
}

#endif //CARD_DECK_H
