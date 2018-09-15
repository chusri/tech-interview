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
		bool return_to_deck(const card c);

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
	assert(container.size() >= 1 && container.size() <= DECK_SIZE);

	card c = container[0];
	container.erase(container.begin());

	return(c);
}

// Shuffle the deck
void deck::shuffle(void) {
	random_shuffle(container.begin(), container.end());
}

// Return card to deck
bool deck::return_to_deck(const card c) {
	suit s = c.get_suit();
	int pips = c.get_pips();

	assert(pips >= 1 && pips <= 13);
	assert(container.size() >= 0 && container.size() <= DECK_SIZE-1);
	assert(s == suit::SPADE || s == suit::HEART || s == suit::DIAMOND ||
				 s == suit::CLUB);

	// Ignore duplicate cards
	auto it = find_if(container.begin(), container.end(), [&c](const card& c1) {
										return((c.get_pips() == c1.get_pips()) &&
													 (c.get_suit() == c1.get_suit()));
									 });

	if (it == container.end()) {
		container.push_back(c);
		return(true);
	} else {
		return(false);
	}
}

#endif //DECK_H
