#include<stdio.h>
#include "deck.h"

void init_deck(struct deck_t *player_deck) {
    player_deck->top = -1;
}

void push_card(card_t card_to_push, struct deck_t *player_deck) {
    int top_element_deck = player_deck->top;
    if (top_element_deck != DECK_SIZE - 1) {
        player_deck->deck[++player_deck->top] = card_to_push;
    }
}

void look_card(struct deck_t *player_deck) {
    printf("-Next card:\ncard NAME: %s\ncard DAMAGE: %d\ncard HP: %d\ncard MANA: %d\n",
            player_deck->deck[player_deck->top].card_name,
            player_deck->deck[player_deck->top].card_damage,
            player_deck->deck[player_deck->top].card_hp,
            player_deck->deck[player_deck->top].card_mana);
}

void print_deck(struct deck_t player_deck) {
    int i;
    for (i = 0; i <= player_deck.top; i++) {
        printf("element %d ->  name: %s, %d, %d, %d\n", i, player_deck.deck[i].card_name, player_deck.deck[i].card_damage,
                player_deck.deck[i].card_hp, player_deck.deck[i].card_mana);
    }
}
//CARDS IN YOUR HAND

void init_hand_cards(struct hand_t *player_hand) {
    player_hand->hand_top = -1;
}

void draw_card(card_t card_to_push_hand, struct hand_t *player_hand) {

    player_hand->hand_cards[++player_hand->hand_top] = card_to_push_hand;


}

void print_hand(struct hand_t player_hand) {
    int i;
    for (i = player_hand.hand_top; i >= 0; i--) {
        printf("hand element %d ->  name: %s, %d, %d, %d\n", i, player_hand.hand_cards[i].card_name, player_hand.hand_cards[i].card_damage,
                player_hand.hand_cards[i].card_hp, player_hand.hand_cards[i].card_mana);
    }
}

int main() {
    struct hand_t player_hand;
    struct deck_t player_deck;
    init_deck(&player_deck);
    init_hand_cards(&player_hand);
    //cards
    card_t attacker = {"Green card", 10, 20, 30};
    card_t defender = {"Blue card", 30, 40, 50};
    card_t neutral = {"Black card", 60, 70, 80};
    //push card(s)
    push_card(attacker, &player_deck);
    push_card(defender, &player_deck);
    push_card(neutral, &player_deck);
    push_card(attacker, &player_deck);
    push_card(defender, &player_deck);
    push_card(neutral, &player_deck);
    //print cards in hand
    print_hand(player_hand);
    //print cards in deck
    print_deck(player_deck);
    //getting the value of top elemement of the deck
    int my_top = player_deck.top;
    int size_of_hand = HAND_SIZE; //flag
    int e; //counter
    for (e = 0; e <= my_top + player_deck.top; e++) {
        if (size_of_hand != 0) {
            draw_card(player_deck.deck[my_top], &player_hand);
            my_top--;
            size_of_hand--;
        } else {
            break;
        }

    }
    //Print cards in your hand
    print_hand(player_hand);
    //look at the next card
    look_card(&player_deck);
    return 0;
}
