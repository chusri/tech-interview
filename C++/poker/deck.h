// This class models a deck of cards.

#ifndef DECK_H
#define DECK_H

#include "card.h"
#include<vector>
#include<algorithm>

const int SUIT_SIZE = 13;
const int DECK_SIZE = 52;

class deck {
	private:
		vector<card> container;

	public:
		deck(void);
		card deal(void);
		void shuffle(void);

		// Overload the << operator
		friend ostream& operator<< (ostream& out, const deck& d) {
			for_each(d.container.begin(), d.container.end(),
							 [&out](const card c){out << c << endl;});
			return(out);
		}
};

// Constructor
deck::deck(void) {
	vector<suit> v = {suit::SPADE, suit::HEART, suit::DIAMOND, suit::CLUB};

	for_each(v.begin(), v.end(), [this](const suit s) {
		for (int i = 1; i <= SUIT_SIZE; i++) {
			this->container.push_back(card(s, i));
		}
	});
}

// Return the card on top of the deck
card deck::deal(void) {
	assert(container.size() >= 1 && container.size() <= 52);

	card c = container[0];
	container.erase(container.begin());

	return(c);
}

// Shuffle the deck
void deck::shuffle(void) {
	random_shuffle(container.begin(), container.end());
}

#endif //DECK_H
