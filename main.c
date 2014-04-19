#include<stdio.h>
#include "player.h"

int main(){
   
    player_t player1;
    player_t player2;
    player1.player_mana.max_mana=10;
    player2.player_mana.max_mana=10;
    int turn=1;
    //Creating first player START
    init_deck(&player1.player_deck);
    init_hand_cards(&player1.player_hand);
    //Creating first player END
    
    //Creating first player deck START
    card_t attacker1 = {"Green", 10, 10, 1};
    card_t attacker2 = {"Blue", 7, 3, 4};
    card_t attacker3 = {"Yellow", 6, 4, 5};
    card_t attacker4 = {"Red", 8, 2, 7};
    card_t attacker5 = {"Purple", 5, 8, 4};
    card_t attacker6 = {"Black", 2, 10, 2};
    card_t attacker7 = {"Brown", 3, 6, 1};
    card_t attacker8 = {"Gray", 5, 5, 3};
    card_t attacker9 = {"Orange", 6, 3, 4};
    card_t attacker10 = {"Lime", 4, 2, 3};   
    //Creating first player deck END
    //push cards START
    push_card(attacker1, &player1.player_deck);
    push_card(attacker2, &player1.player_deck);
    push_card(attacker3, &player1.player_deck);
    push_card(attacker4, &player1.player_deck);
    push_card(attacker5, &player1.player_deck);
    push_card(attacker6, &player1.player_deck);
    push_card(attacker7, &player1.player_deck);
    push_card(attacker8, &player1.player_deck);
    push_card(attacker9, &player1.player_deck);
    push_card(attacker10, &player1.player_deck);

    print_deck(player1.player_deck);
    printf("\n");
    //push cards END
    //Creating second player START
    init_deck(&player2.player_deck);
    init_hand_cards(&player2.player_hand);
    //Creating second player END
    
    //Creating second player deck START
    card_t defender1 = {"Dark_Green", 10, 10, 1};
    card_t defender2 = {"Dark_Blue", 7, 3, 4};
    card_t defender3 = {"Dark_Yellow", 6, 4, 5};
    card_t defender4 = {"Dark_Red", 8, 2, 7};
    card_t defender5 = {"Dark_Purple", 5, 8, 4};
    card_t defender6 = {"Dark_Black", 2, 10, 2};
    card_t defender7 = {"Dark_Brown", 3, 6, 1};
    card_t defender8 = {"Dark_Gray", 5, 5, 3};
    card_t defender9 = {"Dark_Orange", 6, 3, 4};
    card_t defender10 = {"Dark_Lime", 4, 2, 3}; 
    //Creatind second player deck END
    //Push cards START
    push_card(defender1, &player2.player_deck);
    push_card(defender2, &player2.player_deck);
    push_card(defender3, &player2.player_deck);
    push_card(defender4, &player2.player_deck);
    push_card(defender5, &player2.player_deck);
    push_card(defender6, &player2.player_deck);
    push_card(defender7, &player2.player_deck);
    push_card(defender8, &player2.player_deck);
    push_card(defender9, &player2.player_deck);
    push_card(defender10, &player2.player_deck);

    print_deck(player2.player_deck);
    printf("\n");
    //Push cards END
        if(turn==1){
            int counter1;
            for(counter1=0; counter1 <HAND_SIZE; counter1++){
                draw_card(player1.player_deck.deck[player1.player_deck.top], &player1.player_hand, &player1.player_deck ,0);
                draw_card(player2.player_deck.deck[player2.player_deck.top], &player2.player_hand, &player2.player_deck, 0);
            }
        }
        print_hand(player1.player_hand, player1.player_deck);
        printf("\n");
        print_hand(player2.player_hand,  player1.player_deck);
        add_mana(&player2.player_mana, 20);
        int counter123;
        for(counter123 = 0; counter123 <=4; counter123++){
        play_card_from_hand(&player2, 2);
        draw_card(player2.player_deck.deck[player2.player_deck.top], &player2.player_hand, &player2.player_deck, 0);
        printf("\n");
        print_hand(player2.player_hand,  player2.player_deck);
        printf("\n");
        printf("top is :%d\n", player2.player_deck.top);
        printf("current mana is: %d\n", player2.player_mana.current_mana);
        }
        return 0;
}