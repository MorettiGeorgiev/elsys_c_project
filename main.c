#include<stdio.h>
#include "player.h" 
#include "board.h"
#include "deck.h"
int main() {
    player_t player1;
    player_t player2;
    player1.player_name = "Pesho";
    player2.player_name = "Gosho";
    player1.player_mana.max_mana = 10;
    player2.player_mana.max_mana = 10;
    player1.player_mana.current_mana = player1.player_mana.max_mana;
    player2.player_mana.current_mana = player2.player_mana.max_mana;
    player1.player_hp = 30;
    player2.player_hp = 30;
    board_t player1_board;
    board_t player2_board;
    int turn = 1;
    init_board(&player1_board);
    init_board(&player2_board);
    init_deck(&player1.player_deck);
    init_hand_cards(&player1.player_hand);
    init_deck(&player2.player_deck);
    init_hand_cards(&player2.player_hand);
    load_deck(&player1, "deck1.csv");
    load_deck(&player2, "deck2.csv"); 
        
    int i;
    for (i = 0; i < HAND_SIZE; i++) {
        draw_card(player1.player_deck.deck[player1.player_deck.top], &player1.player_hand, &player1.player_deck, 0);
        draw_card(player2.player_deck.deck[player2.player_deck.top], &player2.player_hand, &player2.player_deck, 0);
    }
    print_board(&player1_board, &player1, 1, turn);
    print_board(&player2_board, &player2, 2, turn);
    while (1) {
        
        play(&player1_board, &player2_board, &player1, &player2, turn);
      
        print_board(&player1_board, &player1, 1, turn);
        print_board(&player2_board, &player2, 2, turn);
        
        play(&player2_board, &player1_board, &player2, &player1, turn);
        
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        
        print_board(&player1_board, &player1, 1, turn);
        print_board(&player2_board, &player2, 2, turn);
        
        turn++;  
    }
    return 0;
}
