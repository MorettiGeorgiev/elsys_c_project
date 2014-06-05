#include <stdio.h>
#include "player.h"

void change_hp(player_t *player, int hp, int controller) {
    if (controller == 1) {
        player->player_hp += hp;
    } else if(controller = 2) {
        player->player_hp -= hp;
    }
}
void play_card_from_hand(player_t *player, int card) {
    //creating the card that will be played
    card_t card_to_play = player->player_hand.hand_cards[card];
        //Check if there is enough mana to summon the card
    if (can_put_card(card_to_play, &player->player_mana)  && player->player_hand.hand_top != -1) {
        //Card with key "card" gets the value of the top card of the hand.
        player->player_hand.hand_cards[card] = player->player_hand.hand_cards[player->player_hand.hand_top];
        //push the card that will be played
        draw_card(card_to_play, &player->player_hand, &player->player_deck, 1);
        //pop the card that is played
    }
}
