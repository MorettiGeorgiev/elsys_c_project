#include<stdio.h>
#include "deck.h"

struct hand_t{
        char *hand_card_name;
        int hand_card_damage;
        int hand_card_hp;
        int hand_card_mana;
    };

void init_deck(struct deck_t *player_deck){
    player_deck->top=-1;
}
int is_deck_full(struct deck_t player_deck){
    if(player_deck.top == DECK_SIZE -1){
        return 1;
    }
    else{
        return 0;
    }
}
void push_card(card_t card_to_push, struct deck_t *player_deck){
    player_deck->deck[++player_deck->top] = card_to_push;
    
}
void draw_card(struct deck_t *player_deck, struct hand_t *hand){
    hand->hand_card_name = player_deck->deck[player_deck->top].card_name;
    hand->hand_card_damage = player_deck->deck[player_deck->top].card_damage;
    hand->hand_card_hp = player_deck->deck[player_deck->top].card_hp;
    hand->hand_card_mana = player_deck->deck[player_deck->top].card_mana;
    printf("\n-Drawed card:\ncard NAME: %s\ncard DAMAGE: %d\ncard HP: %d\ncard MANA: %d\n",
    hand->hand_card_name, hand->hand_card_damage, hand->hand_card_hp, hand->hand_card_mana);
    player_deck->top--;
    }
void look_card(struct deck_t *player_deck){
    printf("-Next card:\ncard NAME: %s\ncard DAMAGE: %d\ncard HP: %d\ncard MANA: %d\n",
            player_deck->deck[player_deck->top].card_name,
            player_deck->deck[player_deck->top].card_damage,
            player_deck->deck[player_deck->top].card_hp,
            player_deck->deck[player_deck->top].card_mana);
}

void print_deck(struct deck_t player_deck){
    int i;
    for(i=0; i<=player_deck.top; i++) {
        printf("element %d ->  name: %s, %d, %d, %d\n", i, player_deck.deck[i].card_name, player_deck.deck[i].card_damage,
                player_deck.deck[i].card_hp, player_deck.deck[i].card_mana);
    }   
}
int main() {
    struct deck_t player_deck;
    struct hand_t hand;
    //init deck
    init_deck(&player_deck);
    
    //cards
    card_t attacker={"Green card", 10, 20, 30};
    card_t defender={"Blue card", 30, 40, 50};
    card_t neutral={"Black card", 60, 70, 80};
    //push card(s)
    push_card(attacker, &player_deck);
    push_card(defender, &player_deck);
    push_card(neutral, &player_deck);
   
    //print deck
    print_deck(player_deck);
    //get top value
    int my_top =  player_deck.top;
    int e;//counter
    //print top
    printf("top is: %d\n",player_deck.top);
    //look at the next card
    look_card(&player_deck);
    //draw card(s)
    for(e=my_top; e>-1; e--){
    draw_card(&player_deck, &hand);
    }
    //print top
    printf("top is: %d", player_deck.top);
    return 0;
}
