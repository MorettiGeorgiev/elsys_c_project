#include<stdio.h>
#include "manapool.h"
void can_put_card(card_t card_to_put,manapool_t *pool){
    pool->max_mana=1;
    pool->current_mana=pool->max_mana;
    pool->current_mana -= card_to_put.card_mana;
    int flag;
    if(pool->current_mana>0){
        flag=1;
    }
    else{
        flag=0;
    }
    if(flag==1){
        printf("You have enough mana to summon the card");
    }
    else{
        printf("You don't have enough mana to summon the card");
    }
}
 void add_mana(manapool_t *pool, int mana_to_add){
     pool->max_mana + mana_to_add;
    }

int main(){
    card_t attacker={"Green card", 10, 20, 1};
    manapool_t pool;
    int mana_to_add;
    printf("Add mana: ");
    scanf("%d", &mana_to_add);
    add_mana(&pool, mana_to_add);
    can_put_card(attacker, &pool);
    return 0;
}