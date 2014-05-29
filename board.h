#ifndef BOARD_H
#define	BOARD_H
#include "card.h"
#include "player.h"
typedef struct{
    int lane1;
    int lane2;
    int lane3;
    int lane4;
    int lane5;
    
    card_t lane1_card;
    card_t lane2_card;
    card_t lane3_card;
    card_t lane4_card;
    card_t lane5_card;
}board_t;
#endif	/* BOARD_H */