#include<stdio.h>
#include <string.h>
#include "deck.h"
#include "manapool.h"
#include "player.h"
//Init deck
void init_deck(struct deck_t *player_deck) {
    player_deck->top = -1;
}
//Push a card to the top of the deck | this function is NOT used
void push_card(card_t card_to_push, struct deck_t *player_deck) {
    int top_element_deck = player_deck->top;
    if (top_element_deck != DECK_SIZE - 1) {
        player_deck->deck[++player_deck->top] = card_to_push;
    }
}
//print the cards in the deck | this function is NOT used

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
    player_hand->hand_top = -1  ;
}
//Draw card from the top of the deck to your hand
void draw_card(card_t card_to_push_hand, struct hand_t *player_hand, struct deck_t *player_deck, int modifier) {
    int top_element_hand= player_hand->hand_top;
    if(top_element_hand != HAND_SIZE - 1 && modifier==0){
    player_hand->hand_cards[++player_hand->hand_top] = card_to_push_hand;
    --player_deck->top;
    
    }
    //Push the card that will be played on top of the hand
    else if(modifier==1){
    player_hand->hand_cards[player_hand->hand_top] = card_to_push_hand;
    }


}
//print all the cards in your hand
void print_hand(struct hand_t *player_hand, struct deck_t *player_deck) {
    int i;
    for (i = player_hand->hand_top; i >= 0; i--) {
        if(player_hand->hand_cards[i].special_index == 0){
        printf("%s %d,%d,%d | ",player_hand->hand_cards[i].card_name, player_hand->hand_cards[i].card_damage,
                player_hand->hand_cards[i].card_hp, player_hand->hand_cards[i].card_mana);
        }else{
            printf("SPECIAL | ");
        }
        
    }
    printf("\n");
}
//function to load the deck from file
int load_deck(player_t *player, char *filename){
    FILE *fp = fopen(filename, "r");
  char str[2000];
  char *token;
  if(fp == NULL){ return 0;}
  while(fgets(str, 2000, fp)){
      ++player->player_deck.top;
      token = strtok(str, ",");
      sscanf(token, "%s", player->player_deck.deck[player->player_deck.top].card_name);
      token = strtok(NULL, ",");
      sscanf(token, "%d", &player->player_deck.deck[player->player_deck.top].card_damage);
      token = strtok(NULL, ",");
      sscanf(token, "%d", &player->player_deck.deck[player->player_deck.top].card_hp);
      token = strtok(NULL, ",");
      sscanf(token, "%d", &player->player_deck.deck[player->player_deck.top].card_mana);
      token = strtok(NULL, ",");
      sscanf(token, "%d", &player->player_deck.deck[player->player_deck.top].special_index);
  }
  fclose(fp);
  return 1;
}
