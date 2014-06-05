#ifndef CARD_H
	#define CARD_H
        
	typedef struct{
                
		char card_name[30];
		int card_damage;
		int card_hp;
		int card_mana;
                int special_index;
	}card_t;
	int attack (card_t *attacker, card_t *defender);
#endif
