#ifndef CARD_H
	#define CARD_H
        
	typedef struct{
                
		char *card_name;
		int card_damage;
		int card_hp;
		int card_mana;
                int special_index;
	}card_t;
	int attack (card_t *attacker, card_t *defender);
#endif
