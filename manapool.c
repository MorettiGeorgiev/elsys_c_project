#include<stdio.h>
#include "manapool.h"
//Check if the there is enough mana to summon a card
int can_put_card(card_t card_to_put, manapool_t *pool) {
    pool->current_mana -= card_to_put.card_mana;
    if(pool->current_mana > 0 ){
        return 1;
        
    }
    else{
        return 0;
    }
}
//Function to add mana
void add_mana(manapool_t *pool, int mana_to_add) {
    pool->current_mana += mana_to_add;
}
//Function to remove mana
void remove_mana(manapool_t *pool, int mana_to_remove) {

    pool->current_mana -= mana_to_remove;
}