#include <stdio.h>
#include "player.h"

void change_hp(player_t *player, int hp, int controller) {
    if (controller == 1) {
        player->player_hp += hp;
    } else {
        player->player_hp -= hp;
    }
}

void play_card_from_hand(player_t *player, int card) {
    //creating the card that will be played
    card_t card_to_play = player->player_hand.hand_cards[card];
        //Check if there is enough mana to summon the card
    if (can_put_card(card_to_play, &player->player_mana)  && player->player_deck.top != -1) {
        //Card with key "card" gets the value of the top card of the hand.
        player->player_hand.hand_cards[card] = player->player_hand.hand_cards[player->player_hand.hand_top];
        //push the card that will be played
        draw_card(card_to_play, &player->player_hand, &player->player_deck, 1);
        printf("-Played card:\ncard NAME: %s\ncard DAMAGE: %d\ncard HP: %d\ncard MANA: %d\n",
            player->player_hand.hand_cards[player->player_hand.hand_top].card_name,
            player->player_hand.hand_cards[player->player_hand.hand_top].card_damage,
            player->player_hand.hand_cards[player->player_hand.hand_top].card_hp,
            player->player_hand.hand_cards[player->player_hand.hand_top].card_mana);
        //pop the card that is played
    --player->player_hand.hand_top;
    }
    else if(!can_put_card(card_to_play, &player->player_mana)){
        printf("There isn't enough mana to summon the card");
    }
    else{
        printf("An error occured\n");
    }
}