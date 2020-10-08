// Project UID 1d9f47bfc76643019cfbf037641defe1

#include <cassert>
#include <iostream>
#include <string>
#include "Card.h"
// add any necessary #include or using directives here

// rank and suit names -- do not remove these
constexpr const char* const Card::RANK_TWO;
constexpr const char* const Card::RANK_THREE;
constexpr const char* const Card::RANK_FOUR;
constexpr const char* const Card::RANK_FIVE;
constexpr const char* const Card::RANK_SIX;
constexpr const char* const Card::RANK_SEVEN;
constexpr const char* const Card::RANK_EIGHT;
constexpr const char* const Card::RANK_NINE;
constexpr const char* const Card::RANK_TEN;
constexpr const char* const Card::RANK_JACK;
constexpr const char* const Card::RANK_QUEEN;
constexpr const char* const Card::RANK_KING;
constexpr const char* const Card::RANK_ACE;

constexpr const char* const Card::SUIT_SPADES;
constexpr const char* const Card::SUIT_HEARTS;
constexpr const char* const Card::SUIT_CLUBS;
constexpr const char* const Card::SUIT_DIAMONDS;

// add your code below

Card::Card():rank(RANK_TWO), suit(SUIT_SPADES) {

}

Card::Card(const std::string& rank_in, const std::string& suit_in) {
	rank = rank_in;
	suit = suit_in;
}

std::string Card::get_rank() const {
	return rank;
}

std::string Card::get_suit() const {
	return suit;
}

std::string Card::get_suit(const std::string& trump) const {
	if (this->is_left_bower(trump)) {
		return trump;
	}
	else {
		return suit;
	}
}

bool Card::is_face() const {
	if (rank == RANK_ACE) {
		return true;
	}
	else if (rank == RANK_KING) {
		return true;
	}
	else if (rank == RANK_QUEEN) {
		return true;
	}
	else if (rank == RANK_JACK) {
		return true;
	}
	else {
		return false;
	}
}

bool Card::is_right_bower(const std::string& trump) const {
	return (rank == RANK_JACK && suit == trump);
}
bool Card::is_left_bower(const std::string& trump) const {
	return (rank == RANK_JACK && Suit_next(suit) == trump);
}

bool Card::is_trump(const std::string& trump) const {
	return suit == trump;
}

bool operator<(const Card& lhs, const Card& rhs) {
	
	auto lhs_rank = lhs.get_rank();
	auto rhs_rank = rhs.get_rank();

	unsigned int i = 0;
	unsigned int j = 0;
	for (; i < sizeof(RANK_NAMES_BY_WEIGHT) / sizeof(RANK_NAMES_BY_WEIGHT[0]); i++) {
		if (lhs_rank == RANK_NAMES_BY_WEIGHT[i]) {
			break;
		}
	}
	for (; j < sizeof(RANK_NAMES_BY_WEIGHT) / sizeof(RANK_NAMES_BY_WEIGHT[0]); j++) {
		if (rhs_rank == RANK_NAMES_BY_WEIGHT[j]) {
			break;
		}
	}
	
	return i < j;
}

std::string Suit_next(const std::string& suit) {
	if (suit == Card::SUIT_HEARTS) {
		return Card::SUIT_DIAMONDS;
	}
	else if (suit == Card::SUIT_DIAMONDS) {
		return Card::SUIT_HEARTS;
	}
	else if (suit == Card::SUIT_CLUBS) {
		return Card::SUIT_SPADES;
	}
	else {
		return Card::SUIT_CLUBS;
	}
}