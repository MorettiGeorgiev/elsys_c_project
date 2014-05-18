#include <stdio.h>
#include "board.h"

void init_board(board_t *board) {
    board->lane1 = 0;
    board->lane2 = 0;
    board->lane3 = 0;
    board->lane4 = 0;
    board->lane5 = 0;
}

void play_card(card_t *card_to_play) {
    printf("%d | %d",
            card_to_play->card_damage,
            card_to_play->card_hp
            );
}

void print_player(player_t *player, int turn) {
    printf("PLAYER: %s(%dhp), MANA %d/10, turn %d\n",
            player->player_name,
            player->player_hp,
            player->player_mana.current_mana,
            turn);
}

void print_board(board_t *board, player_t *player, int player_id, int turn) {
    if (player_id == 1) {
        print_player(player, turn);
        print_hand(&player->player_hand, &player->player_deck);
        printf("\n");
    }
    printf("# ");
    if (board->lane1 == 0) {
        printf("   ");
    } else if (board->lane1 == 1) {
        play_card(&board->lane1_card);
    }
    printf(" # ");
    if (board->lane2 == 0) {
        printf("   ");
    } else {
        play_card(&board->lane2_card);
    }
    printf(" # ");
    if (board->lane3 == 0) {
        printf("   ");
    } else {
        play_card(&board->lane3_card);
    }
    printf(" # ");
    if (board->lane4 == 0) {
        printf("   ");
    } else {
        play_card(&board->lane4_card);
    }
    printf(" # ");
    if (board->lane5 == 0) {
        printf("   ");
    } else {
        play_card(&board->lane5_card);
    }
    printf(" #\n\n");
    if (player_id == 2) {
            
        print_hand(&player->player_hand, &player->player_deck);
        print_player(player, turn);
    }
    

}
/*
void can_play_card(player_t *player,board_t *board, int card, int turn){
    print_player(player, turn);
    print_hand(&player->player_hand, &player->player_deck);
    printf("\n");
    if(board->lane1 == 0){
        board->lane1 = 1;
    }
 */
/*
    else if(board->lane2 == 0){
        board->lane2_card = player->player_hand.hand_cards[card];
        board->lane2 = 1;
    }
    else if(board->lane3 == 0){
        board->lane3_card = player->player_hand.hand_cards[card];
        board->lane3 = 1;
    }
    else if(board->lane4 == 0){
        board->lane4_card = player->player_hand.hand_cards[card];
        board->lane4 = 1;
    }
    else if(board->lane5 == 0){
       board->lane4_card = player->player_hand.hand_cards[card];
        board->lane4 = 1;
    }
 * }
 */


/*
int can_play_card(card_t card_to_put, board_t *board, player_t *player, int card) {
    int save_current_mana = player->player_mana.current_mana;
    if (can_put_card(card_to_put, &player->player_mana)) {
        return 1;
    } 

    else {
        return 0;
        player->player_mana.current_mana = save_current_mana;
    }

}
void play_card(card_t card_to_put, board_t *board, player_t *player, int card){
    if(can_play_card(card_to_put, board, player, card )){
        play_card_from_hand(player, card);
    }
    else{
        printf("Not enough mana to play the card");
    }
}
 */