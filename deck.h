<<<<<<< HEAD
#ifndef DECK_H
#define	DECK_H
#define DECK_SIZE 30
#define HAND_SIZE 5
#include "card.h"
#include "manapool.h"    

struct hand_t {
    int hand_top;
    card_t hand_cards[HAND_SIZE];
};

struct deck_t {
    int top;
    card_t deck [DECK_SIZE];
};
void init_deck(struct deck_t *player_deck);
void push_card(card_t card_to_push, struct deck_t *player_deck);
void look_card(struct deck_t *player_deck);
void print_deck(struct deck_t player_deck);
void init_hand_cards(struct hand_t *player_hand);
void draw_card(card_t card_to_push_hand, struct hand_t *player_hand, struct deck_t *player_deck, int modifier);
void print_hand(struct hand_t *player_hand, struct deck_t *player_deck);
#endif

=======
#ifndef DECK_H
#define	DECK_H
#define DECK_SIZE 30
#define HAND_SIZE 5
#include "card.h"
#include "manapool.h"    

struct hand_t {
    int hand_top;
    card_t hand_cards[HAND_SIZE];
};

struct deck_t {
    int top;
    card_t deck [DECK_SIZE];
};
void init_deck(struct deck_t *player_deck);
void push_card(card_t card_to_push, struct deck_t *player_deck);
void look_card(struct deck_t *player_deck);
void print_deck(struct deck_t player_deck);
void init_hand_cards(struct hand_t *player_hand);
void draw_card(card_t card_to_push_hand, struct hand_t *player_hand, struct deck_t *player_deck, int modifier);
void print_hand(struct hand_t player_hand, struct deck_t player_deck);
#endif

>>>>>>> aec926401fb256ece5ac4cac5685bf79fe76fc77
