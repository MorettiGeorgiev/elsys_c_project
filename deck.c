#include<stdio.h>
#include "deck.h"
#include "manapool.h"
//Init deck
void init_deck(struct deck_t *player_deck) {
    player_deck->top = -1;
}
//Push a card to the top of the deck
void push_card(card_t card_to_push, struct deck_t *player_deck) {
    int top_element_deck = player_deck->top;
    if (top_element_deck != DECK_SIZE - 1) {
        player_deck->deck[++player_deck->top] = card_to_push;
    }
}
//look at the next card that is in the deck
void look_card(struct deck_t *player_deck) {
    printf("-Next card:\ncard NAME: %s\ncard DAMAGE: %d\ncard HP: %d\ncard MANA: %d\n",
            player_deck->deck[player_deck->top].card_name,
            player_deck->deck[player_deck->top].card_damage,
            player_deck->deck[player_deck->top].card_hp,
            player_deck->deck[player_deck->top].card_mana);
}
//print the cards in the deck
void print_deck(struct deck_t player_deck) {
    int i;
    for (i = 0; i <= player_deck.top; i++) {
        printf("element %d ->  name: %s, %d, %d, %d\n", i, player_deck.deck[i].card_name, player_deck.deck[i].card_damage,
                player_deck.deck[i].card_hp, player_deck.deck[i].card_mana);
    }
}
//CARDS IN YOUR HAND
//Init cards
void init_hand_cards(struct hand_t *player_hand) {
    player_hand->hand_top = -1;
}
//Draw card from the top of the deck to your hand
void draw_card(card_t card_to_push_hand, struct hand_t *player_hand, struct deck_t *player_deck, int modifier) {
    int top_element_hand= player_hand->hand_top;
    if(top_element_hand != HAND_SIZE - 1 && modifier==0){
    player_hand->hand_cards[++player_hand->hand_top] = card_to_push_hand;
    --player_deck->top;
    
    }
    else if(modifier==1){
    player_hand->hand_cards[player_hand->hand_top] = card_to_push_hand;
    }


}
//print all the cards in your hand
void print_hand(struct hand_t player_hand, struct deck_t player_deck) {
    int i;
    for (i = player_hand.hand_top; i >= 0; i--) {
        printf("hand element %d ->  name: %s, %d, %d, %d\n", i, player_hand.hand_cards[i].card_name, player_hand.hand_cards[i].card_damage,
                player_hand.hand_cards[i].card_hp, player_hand.hand_cards[i].card_mana);
    }
    
}
