#include <stdio.h>
#include "card.h"
//Battle  between 2 cards
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
<<<<<<< HEAD
}
=======
}
>>>>>>> aec926401fb256ece5ac4cac5685bf79fe76fc77
