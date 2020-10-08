// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Card.h"
#include "unit_test_framework.h"
#include <iostream>

using namespace std;


TEST(test_card_ctor) {
   
    Card c(Card::RANK_ACE, Card::SUIT_HEARTS);
    ASSERT_EQUAL(Card::RANK_ACE, c.get_rank());
    ASSERT_EQUAL(Card::SUIT_HEARTS, c.get_suit());
}

TEST(test_card_constructor) {

    Card c;
    ASSERT_EQUAL(Card::RANK_TWO, c.get_rank());
    ASSERT_EQUAL(Card::SUIT_SPADES, c.get_suit());

}

TEST(test_get_suit_trump) {
    Card c(Card::RANK_ACE, Card::SUIT_CLUBS);
    Card d(Card::RANK_JACK, Card::SUIT_CLUBS);
    Card e(Card::RANK_JACK, Card::SUIT_SPADES);

    ASSERT_EQUAL(Card::SUIT_CLUBS, c.get_suit(Card::SUIT_CLUBS));
    ASSERT_EQUAL(Card::SUIT_CLUBS, c.get_suit(Card::SUIT_CLUBS));
    ASSERT_EQUAL(Card::SUIT_CLUBS, c.get_suit(Card::SUIT_CLUBS));



}

TEST(test_is_face_function) {
    Card a(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card b(Card::RANK_KING, Card::SUIT_HEARTS);
    Card c(Card::RANK_QUEEN, Card::SUIT_HEARTS);
    Card d(Card::RANK_JACK, Card::SUIT_HEARTS);
    Card e(Card::RANK_TEN, Card::SUIT_HEARTS);

    ASSERT_EQUAL(true, a.is_face());
    ASSERT_EQUAL(true, b.is_face());
    ASSERT_EQUAL(true, c.is_face());
    ASSERT_EQUAL(true, d.is_face());
    ASSERT_EQUAL(false, e.is_face());
}

TEST(test_is_right_bower) {
    Card c(Card::RANK_JACK, Card::SUIT_HEARTS);
    ASSERT_EQUAL(true, c.is_right_bower("Hearts"));
    Card d("Jack", "Diamonds");
    ASSERT_EQUAL(false, d.is_right_bower("Hearts"));
}

TEST(test_is_left_bower) {
    Card c(Card::RANK_JACK, Card::SUIT_HEARTS);
    Card d(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    Card e(Card::RANK_JACK, Card::SUIT_CLUBS);
    ASSERT_EQUAL(true, c.is_left_bower(Card::SUIT_DIAMONDS));
    ASSERT_EQUAL(false, d.is_left_bower(Card::SUIT_DIAMONDS));
    ASSERT_EQUAL(true, e.is_left_bower(Card::SUIT_SPADES));
}

TEST(test_next_suit) {
    Card c(Card::RANK_JACK, Card::SUIT_HEARTS);
    ASSERT_EQUAL(Card::SUIT_DIAMONDS, Suit_next(c.get_suit()));
    ASSERT_EQUAL(Card::SUIT_HEARTS, Suit_next(Suit_next(c.get_suit())));
    ASSERT_EQUAL(Card::SUIT_SPADES, Suit_next(Card::SUIT_CLUBS));
}

TEST(test_is_trump) {
    Card c(Card::RANK_JACK, Card::SUIT_CLUBS);
    ASSERT_EQUAL(true, c.is_trump(Card::SUIT_CLUBS));
}

TEST(test_card_inequality) {
    Card w("Jack", "Hearts");
    Card d("Eight", "Hearts");
    Card k("King", "Hearts");
    Card a("Ace", "Hearts"); // Ace is screwed up!! Should be top of order
    Card q("Queen", Card::SUIT_DIAMONDS);

    ASSERT_EQUAL(true, q < a);
    ASSERT_EQUAL(true, k < a);
    ASSERT_EQUAL(true, w < k);
    ASSERT_EQUAL(true, q < k);

    
    
    //ASSERT_EQUAL(true, w < k);
    //ASSERT_EQUAL(true, k < a);
    //ASSERT_EQUAL(true, k < a);
    // Ranks behave accordingly 
    //ASSERT_EQUAL(true, w < k);
    //ASSERT_EQUAL(true, q < a); // Card queen is BUGGED
    //ASSERT_EQUAL(true, q.get_rank() < a.get_rank()); // Is the issue with .get_rank?
    


}
// Add more test cases here

TEST_MAIN()


