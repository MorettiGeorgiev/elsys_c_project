#ifndef PLAYER_H
#define	PLAYER_H
#include "card.h"
#include "manapool.h"
#include "deck.h"
#include "board.h"
typedef struct {
    char *player_name;
    int player_hp;
    manapool_t player_mana;
    struct deck_t player_deck;
    struct hand_t player_hand;
} player_t;
void play_card_from_hand(player_t *player, int card);
#endif	/* PLAYER_H */

