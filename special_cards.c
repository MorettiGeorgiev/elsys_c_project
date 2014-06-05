#include <stdio.h>
#include "special_cards.h"
//function for special cards
void special_card(board_t *player_to_play_board, board_t *other_player_board, player_t *player_to_play, player_t *other_player, card_t *lane_card){
    int hp_to_steal = 5;
    card_t sheep = {"Sheep",1,1,1,0};
    switch(lane_card->special_index){
        //according to the "special_index" the card have different effect
                    case 1:
                        change_hp(player_to_play,5,1);
                        break;
                        //add 5hp
                        ;
                    case 2:
                        change_hp(other_player,5,2);
                        break;
                        //remove 5hp from the opponent
                        ;
                    case 3:
                        add_mana(&player_to_play->player_mana,1);
                        break;
                        //add 1 mana
                        ;
                    case 4:
                        change_hp(other_player,hp_to_steal,2);
                        change_hp(player_to_play,hp_to_steal,1);
                        //steal 5 hp
                        break;
                        ;
                    case 5:
                        other_player_board->lane1_card = sheep;
                        //turn one of the other player hand to sheep wit 1ad and 1 hp
                        break;
                        ;
                }
}
