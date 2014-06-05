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
void init_board(board_t *board);
void play_card(card_t *card_to_play);
void print_player(player_t *player, int turn);
void print_board(board_t *board, player_t *player, int player_id, int turn);
void play(board_t *player_to_play_board, board_t *other_player_board, player_t *player_to_play, player_t *other_player, int turn);
#endif	/* BOARD_H */