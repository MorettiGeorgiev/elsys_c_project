#include <stdio.h>
#include "card.h"

int attack (card_t *attacker, card_t *defender){
	attacker -> card_hp -= defender -> card_damage;
	defender -> card_hp -= attacker -> card_damage;
	
	if (defender -> card_hp <= 0 && attacker -> card_hp <= 0){
		return 0;
		//both cards are dead
	}
	if (defender -> card_hp <= 0 && attacker -> card_hp > 0){
		return 1;
		//attacker wins
	}
	if (defender -> card_hp > 0 && attacker -> card_hp <= 0){
		return 2;
		//defender wins
	}
	if (defender -> card_hp > 0 && attacker -> card_hp > 0){
		return 3;
		//both cards are alive
	}
}

int main(){
	card_t attacker = {"Green card",400, 300, 20};
	card_t defender = {"Yellow card", 30, 40, 20};
	 
	
	if (attack(&attacker, &defender) == 0){ 
		printf("Both cards are dead");
	}
	if (attack(&attacker, &defender) == 1){ 
		printf("Attacker won");
	}
	if (attack(&attacker, &defender) == 2){
		printf("Defender won");
	}
	if (attack(&attacker, &defender) == 3){ 
		printf("Both cards are alive");
	}
	
	return 0;
}
