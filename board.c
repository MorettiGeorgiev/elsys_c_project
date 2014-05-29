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

void play(board_t *player_to_play_board, board_t *other_player_board, player_t *player_to_play, player_t *other_player, cards_flag_t *flag,int turn) {
    int card_to_attack;
    int what_to_do;
    int which_card_to_play;
    int save_current_mana;
    //print_board(player_to_play_board, player_to_play, 1, turn);
    //print_board(other_player_board, other_player, 2, turn);
    printf("\nWhat do you want to do?\n");
    printf("1: Play card\n");
    printf("2: Attack\n");
    printf("3:Skip move\n");
    printf("Your option: ");
    scanf("%d", &what_to_do);
    switch (what_to_do) {
        case 1:
            printf("Chose a card: ");
            scanf("%d", &which_card_to_play);
            if (player_to_play_board->lane1 == 0) {
                save_current_mana = player_to_play->player_mana.current_mana;
                if (can_put_card(player_to_play->player_hand.hand_cards[player_to_play->player_hand.hand_top], &player_to_play->player_mana)) {
                    player_to_play->player_mana.current_mana = save_current_mana;
                    play_card_from_hand(player_to_play, which_card_to_play);
                    player_to_play_board->lane1_card = player_to_play->player_hand.hand_cards[player_to_play->player_hand.hand_top];
                    player_to_play_board->lane1 = 1;
                    --player_to_play->player_hand.hand_top;
                } else {
                    printf("No mana to summon the card");
                }
            } else if (player_to_play_board->lane2 == 0) {
                save_current_mana = player_to_play->player_mana.current_mana;
                save_current_mana = player_to_play->player_mana.current_mana;
                if (can_put_card(player_to_play->player_hand.hand_cards[player_to_play->player_hand.hand_top], &player_to_play->player_mana)) {
                    player_to_play->player_mana.current_mana = save_current_mana;
                    play_card_from_hand(player_to_play, which_card_to_play);
                    player_to_play_board->lane2_card = player_to_play->player_hand.hand_cards[player_to_play->player_hand.hand_top];
                    player_to_play_board->lane2 = 1;
                    --player_to_play->player_hand.hand_top;
                } else {
                    printf("No mana to summon the card");
                }
            } else if (player_to_play_board->lane3 == 0) {
                save_current_mana = player_to_play->player_mana.current_mana;
                if (can_put_card(player_to_play->player_hand.hand_cards[player_to_play->player_hand.hand_top], &player_to_play->player_mana)) {
                    player_to_play->player_mana.current_mana = save_current_mana;
                    play_card_from_hand(player_to_play, which_card_to_play);
                    player_to_play_board->lane3_card = player_to_play->player_hand.hand_cards[player_to_play->player_hand.hand_top];
                    player_to_play_board->lane3 = 1;
                    --player_to_play->player_hand.hand_top;
                } else {
                    printf("No mana to summon the card");
                }
            } else if (player_to_play_board->lane4 == 0) {
                save_current_mana = player_to_play->player_mana.current_mana;
                if (can_put_card(player_to_play->player_hand.hand_cards[player_to_play->player_hand.hand_top], &player_to_play->player_mana)) {
                    player_to_play->player_mana.current_mana = save_current_mana;
                    play_card_from_hand(player_to_play, which_card_to_play);
                    player_to_play_board->lane4_card = player_to_play->player_hand.hand_cards[player_to_play->player_hand.hand_top];
                    player_to_play_board->lane4 = 1;
                    --player_to_play->player_hand.hand_top;
                } else {
                    printf("No mana to summon the card");
                }
            } else if (player_to_play_board->lane5 == 0) {
                save_current_mana = player_to_play->player_mana.current_mana;
                if (can_put_card(player_to_play->player_hand.hand_cards[player_to_play->player_hand.hand_top], &player_to_play->player_mana)) {
                    player_to_play->player_mana.current_mana = save_current_mana;
                    play_card_from_hand(player_to_play, which_card_to_play);
                    player_to_play_board->lane5_card = player_to_play->player_hand.hand_cards[player_to_play->player_hand.hand_top];
                    player_to_play_board->lane5 = 1;
                    --player_to_play->player_hand.hand_top;
                } else {
                    printf("No mana to summon the card");
                }
            }
            printf("\n");
            break;
            ;
        
            
    }
}