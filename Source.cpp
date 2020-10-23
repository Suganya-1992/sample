/***************************************************************************/
/**************Poker_game-for_2_players*************************************/
/**************Author-Suganya***********************************************/
/**************Language-C/C++***********************************************/
/***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
//Structure is created for the players holding value and color.
struct card {
    int value;
    char color;
};
//For 2 players structure is created

struct card player1_card[5] = { NULL };
struct card player2_card[5] = { NULL };
static int player1_counter = 0, player2_counter = 0;

//function declaration
void sort_player1();
void sort_player2();
int check_player(int);
int is_straight_flush(int);
int is_fourofkind(int);
int is_fullhouse(int);
int is_flush(int);
int is_straight(int);
int is_tok(int);
int is_twopair(int);
int is_onepair(int);
int check_three(int,int,int);
int is_royal_flush(int);
int is_onepair_check();
int is_twopair_check();
int is_tok_check();
int is_fullhouse_check();
int is_straight_check();
int is_check();
int is_flush_check();
int is_straight_flush_check();
int is_fourofkind_check();
void inputstream(int);

//main() function starts
int main() {
    int i,result,num,num2;
    int player1_result,player2_result;
    char player1_cardvalue[5] = { NULL }, player2_cardvalue[5] = { NULL };

    cout<<" \n Follow the Input format as below. \n \n Enter the value followed by suits \n";
    cout<<"\n Ace->A ; Jack->J ; Queen->Q; King->K ; 10->T; 2 ; 3; 4; 5; 6; 7; 8; 9\n ";
    cout << "\n Spade->'S'; Hearts-> 'H' ; Clubs-> 'C' ; Diamonds-> 'D'\n";
    cout<<"\n Lets start the game \n";
    cout << "\n Please Enter how many streams you want to enter the input cards: ";
    cin >> num;
    for (i = 0; i < num; i++) {
        inputstream(i);
    }
    // Printing the output
    cout << "\n Number of hands won by player1 and player2\n";
    cout << "\n Player 1: " << player1_counter << " Hands" << "\n Player 2: " << player2_counter << " Hands\n";

    cout << "\n Do you want to continue the game again :\n Type '1' to continue \t '0' to exit.\n";
    cin >> num2;
    while (num2 != 0) {
        num = 0;
        player1_counter = 0; player2_counter = 0;
        cout << "\n Please Enter how many streams you want to enter the input cards: ";
        cin >> num;
        for (i = 0; i < num; i++) {
            inputstream(i);
        }
        // Printing the output
        cout << "\n Number of hands won by player1 and player2\n";
        cout << "\n Player 1: " << player1_counter << " Hands" << "\n Player 2: " << player2_counter << " Hands\n";

        cout << "\n Do you want to continue again :\n Type '1' to continue \t '0' to exit.\n";
        cin >> num2;
    }

}

void inputstream(int p) {
    int result;
    int player1_result, player2_result;
    char player1_cardvalue[5] = { NULL }, player2_cardvalue[5] = { NULL };

    printf("\n Enter the stream %d cards: ", p + 1);
    for (int j = 0; j < 5; j++) {
        cin >> player1_cardvalue[j];
        cin >> &player1_card[j].color;
    }
    for (int j = 0; j < 5; j++) {
        cin >> player2_cardvalue[j] >> &player2_card[j].color;
    }
    // Values like 'A','J','Q','K','L','T' are replaced by integer 14,11,12,13,10 respectively- Player1
    for (int k = 0; k < 5; k++) {
        if (player1_cardvalue[k] == 'A')
            player1_card[k].value = 14;
        else if (player1_cardvalue[k] == 'J')
            player1_card[k].value = 11;
        else if (player1_cardvalue[k] == 'K')
            player1_card[k].value = 13;
        else if (player1_cardvalue[k] == 'Q')
            player1_card[k].value = 12;
        else if (player1_cardvalue[k] == '1')
            player1_card[k].value = 1;
        else if (player1_cardvalue[k] == '2')
            player1_card[k].value = 2;
        else if (player1_cardvalue[k] == '3')
            player1_card[k].value = 3;
        else if (player1_cardvalue[k] == '4')
            player1_card[k].value = 4;
        else if (player1_cardvalue[k] == '5')
            player1_card[k].value = 5;
        else if (player1_cardvalue[k] == '6')
            player1_card[k].value = 6;
        else if (player1_cardvalue[k] == '7')
            player1_card[k].value = 7;
        else if (player1_cardvalue[k] == '8')
            player1_card[k].value = 8;
        else if (player1_cardvalue[k] == '9')
            player1_card[k].value = 9;
        else if (player1_cardvalue[k] == 'T')
            player1_card[k].value = 10;

    }
    // Values like 'A','J','Q','K','L','T' are replaced by integer 14,11,12,13,10 respectively- Player2
    for (int k = 0; k < 5; k++) {
        if (player2_cardvalue[k] == 'A')
            player2_card[k].value = 14;
        else if (player2_cardvalue[k] == 'J')
            player2_card[k].value = 11;
        else if (player2_cardvalue[k] == 'K')
            player2_card[k].value = 13;
        else if (player2_cardvalue[k] == 'Q')
            player2_card[k].value = 12;
        else if (player2_cardvalue[k] == '1')
            player2_card[k].value = 1;
        else if (player2_cardvalue[k] == '2')
            player2_card[k].value = 2;
        else if (player2_cardvalue[k] == '3')
            player2_card[k].value = 3;
        else if (player2_cardvalue[k] == '4')
            player2_card[k].value = 4;
        else if (player2_cardvalue[k] == '5')
            player2_card[k].value = 5;
        else if (player2_cardvalue[k] == '6')
            player2_card[k].value = 6;
        else if (player2_cardvalue[k] == '7')
            player2_card[k].value = 7;
        else if (player2_cardvalue[k] == '8')
            player2_card[k].value = 8;
        else if (player2_cardvalue[k] == '9')
            player2_card[k].value = 9;
        else if (player2_cardvalue[k] == 'T')
            player2_card[k].value = 10;

    }

    //Before checking player 1 and player2 cards, sorting the values 
    sort_player1();
    sort_player2();
    //Getting the rank value for player 1 and player 2
    player1_result = check_player(1);
    player2_result = check_player(2);
    // To get the player1 hands and player2 hands; player1_counter and player2_counter incremented
    if (player1_result > player2_result) {
        player1_counter++;
    }
    //Tie break when player1 and player2 rank 1 i.e. High Card
    else if (player1_result == 1 && player2_result == 1) {
        result = is_check();
        if (result == 1) {
            player1_counter++;
        }
        else {
            player2_counter++;
        }
    }
    //Tie break when player1 and player2 rank 2 i.e. One pair
    else if (player1_result == 2 && player2_result == 2) {
        result = is_onepair_check();
        if (result == 1) {
            player1_counter++;
        }
        else {
            player2_counter++;
        }
    }
    //Tie break when player1 and player2 rank 3 i.e. Two pair
    else if (player1_result == 3 && player2_result == 3) {
        result = is_twopair_check();
        if (result == 1) {
            player1_counter++;
        }
        else {
            player2_counter++;
        }
    }
    //Tie break when player1 and player2 rank 4 i.e. three of kind
    else if (player1_result == 4 && player2_result == 4) {
        result = is_tok_check();
        if (result == 1) {
            player1_counter++;
        }
        else {
            player2_counter++;
        }
    }
    //Tie break when player1 and player2 rank 5 i.e. Straight
    else if (player1_result == 5 && player2_result == 5) {
        result = is_straight_check();
        if (result == 1) {
            player1_counter++;
        }
        else {
            player2_counter++;
        }
    }
    //Tie break when player1 and player2 rank 6 i.e. Flush
    else if (player1_result == 6 && player2_result == 6) {
        result = is_flush_check();
        if (result == 1) {
            player1_counter++;
        }
        else {
            player2_counter++;
        }
    }
    //Tie break when player1 and player2 rank 7 i.e. Full House
    else if (player1_result == 7 && player2_result == 7) {
        result = is_fullhouse_check();
        if (result == 1) {
            player1_counter++;
        }
        else {
            player2_counter++;
        }
    }
    //Tie break when player1 and player2 rank 8 i.e. Four of Kind
    else if (player1_result == 8 && player2_result == 8) {
        result = is_fourofkind_check();
        if (result == 1) {
            player1_counter++;
        }
        else {
            player2_counter++;
        }
    }
    //Tie break when player1 and player2 rank 9 i.e. Straight Flush
    else if (player1_result == 9 && player2_result == 9) {
        result = is_straight_flush_check();
        if (result == 1) {
            player1_counter++;
        }
        else {
            player2_counter++;
        }
    }
    //If all above tie condition fails then player 2 is winner
    else {
        player2_counter++;
    }

    // After each set of stream is completed, players cards are reset to NULL
    struct card player1_card[5] = { NULL };
    struct card player2_card[5] = { NULL };

    for (int j = 0; j < 5; j++) {
        player1_cardvalue[j] = 0;
        player2_cardvalue[j] = 0;
    }

}
//Sorting player 1 values
void sort_player1() {
    int temp_v;
 //   Sort the player1 values
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (player1_card[i].value > player1_card[j].value) {
                temp_v = player1_card[i].value;
                player1_card[i].value = player1_card[j].value;
                player1_card[j].value = temp_v;
            }
        }
    }
}
//Sorting player 2 values
void sort_player2() {
    int temp_v;
    //   Sort the player1 values
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (player2_card[i].value > player2_card[j].value) {
                temp_v = player2_card[i].value;
                player2_card[i].value = player2_card[j].value;
                player2_card[j].value = temp_v;
            }
        }
    }
}

//function to check combination of player
//functions returns 1 for high card, 2->One pair and so on.

int check_player(int player) {
    int result = 1;
    if (is_royal_flush(player) == 1) {
        result = 10;
    }
    if (is_straight_flush(player) == 1) {
        result = 9;
    }
    else if (is_fourofkind(player) == 1) {
        result = 8;
    }
    else if (is_fullhouse(player) == 1) {
        result = 7;
    }
    else if (is_flush(player) == 1) {
        result = 6;
    }
    else if (is_straight(player) == 1) {
        result = 5;
    }
    else if (is_tok(player) == 1) {
        result = 4;
    }
    else if (is_twopair(player) == 1) {
        result = 3;
    }
    else if (is_onepair(player) == 1) {
        result = 2;
    }
    return result;

}
//Function to check straight flush for each player
int is_straight_flush(int player) {
    if (player == 1) {
        if ((is_flush(1) == 1) && (is_straight(1) == 1)) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        if ((is_flush(2) == 1) && (is_straight(2) == 1)) {
            return 1;
        }
        else {
            return 0;
        }
    }
}
//Function to check royal flush for each player
int is_royal_flush(int player) {
    if (player == 1) {
        char color_a, color_b, color_c, color_d, color_e;
        int a, b, c, d,e;
        color_a = player1_card[0].color;
        color_b = player1_card[1].color;
        color_c = player1_card[2].color;
        color_d = player1_card[3].color;
        color_e = player1_card[4].color;
        a = player1_card[0].value ;
        b = player1_card[1].value ;
        c = player1_card[2].value ;
        d = player1_card[3].value ;
        e = player1_card[4].value;
        if (color_a == color_b && color_a == color_c && color_a == color_d && color_a == color_e && 
            a == 10 && b == 11 && c == 12 && d == 13 && d == 14)
            return 1;
        else
            return 0;

    }
    else {
        char color_a, color_b, color_c, color_d, color_e;
        int a, b, c, d, e;
        color_a = player2_card[0].color;
        color_b = player2_card[1].color;
        color_c = player2_card[2].color;
        color_d = player2_card[3].color;
        color_e = player2_card[4].color;
        a = player2_card[0].value;
        b = player2_card[1].value;
        c = player2_card[2].value;
        d = player2_card[3].value;
        e = player2_card[4].value;
        if (color_a == color_b && color_a == color_c && color_a == color_d && color_a == color_e && 
            a == 10 && b == 11 && c == 12 && d == 13 && d == 14)
            return 1;
        else
            return 0;

    }
}
//function to check straight for each player
int is_straight(int player) {
    if (player == 1) {
        int a, b, c, d;
        a = player1_card[0].value + 4;
        b = player1_card[1].value + 3;
        c = player1_card[2].value + 2;
        d = player1_card[3].value + 1;
        if (a == b && b == c && c == d && d == player1_card[4].value) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        int a, b, c, d;
        a = player2_card[0].value + 4;
        b = player2_card[1].value + 3;
        c = player2_card[2].value + 2;
        d = player2_card[3].value + 1;
        if (a == b && b == c && c == d && d == player2_card[4].value) {
            return 1;
        }
        else {
            return 0;
        }
    }
}
//Function to check flush for each player
int is_flush(int player) {
    if (player == 1) {
        int a, b, c, d;
        a = player1_card[0].color;
        b = player1_card[1].color;
        c = player1_card[2].color;
        d = player1_card[3].color;
        if (a == b && b == c && c == d && d == player1_card[4].color) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        int a, b, c, d;
        a = player2_card[0].color;
        b = player2_card[1].color;
        c = player2_card[2].color;
        d = player2_card[3].color;
        if (a == b && b == c && c == d && d == player2_card[4].color) {
            return 1;
        }
        else {
            return 0;
        }
    }
}
//Function to check four of kind for each player
int is_fourofkind(int player) {
    if (player == 1) {
        int a, b, c, d, e;
        a = player1_card[0].value;
        b = player1_card[1].value;
        c = player1_card[2].value;
        d = player1_card[3].value;
        e = player1_card[4].value;
        if ((a == b && b == c && c == d) || (b == c && c == d && d == e) || (c == d && d == e && e == a) || 
            (d == e && e == a && a == b) || (e == a && a == b && b == c)) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        int a, b, c, d, e;
        a = player2_card[0].value;
        b = player2_card[1].value;
        c = player2_card[2].value;
        d = player2_card[3].value;
        e = player2_card[4].value;
        if ((a == b && b == c && c == d) || (b == c && c == d && d == e) || (c == d && d == e && e == a) || 
            (d == e && e == a && a == b) || (e == a && a == b && b == c)) {
            return 1;
        }
        else {
            return 0;
        }
    }
}
//Function to check full house for each player
int is_fullhouse(int player) {
    if (player == 1) {
        if ((is_tok(1) == 1) && (is_onepair(1) == 1)) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        if ((is_tok(2) == 1) && (is_onepair(2) == 1)) {
            return 1;
        }
        else {
            return 0;
        }
    }
}
//Function to check three of kind for each player
int is_tok(int player) {
    if (player == 1) {
        int a, b, c, d, e;
        a = player1_card[0].value;
        b = player1_card[1].value;
        c = player1_card[2].value;
        d = player1_card[3].value;
        e = player1_card[4].value;
        if ((a == b && b == c) || (a == b && b == d) || (a == b && b == e) || (a == c && c == d) || (a == c && c == e) || (a == d && d == e) || (b == c && c == d) || (b == c && c == e) || (b == d && d == e) || (c == d && d == e)) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        int a, b, c, d, e;
        a = player2_card[0].value;
        b = player2_card[1].value;
        c = player2_card[2].value;
        d = player2_card[3].value;
        e = player2_card[4].value;
        if ((a == b && b == c) || (a == b && b == d) || (a == b && b == e) || (a == c && c == d) || (a == c && c == e) || (a == d && d == e) || (b == c && c == d) || (b == c && c == e) || (b == d && d == e) || (c == d && d == e)) {
            return 1;
        }
        else {
            return 0;
        }
    }
}
//Function to check one pair for each player
int is_onepair(int player) {
    if (player == 1) {
        int a, b, c, d, e;
        a = player1_card[0].value;
        b = player1_card[1].value;
        c = player1_card[2].value;
        d = player1_card[3].value;
        e = player1_card[4].value;
        if (a == b && a != c && a != d && a != e)
            return 1;
        else if (b == c && b != a && b != d && b != e)
            return 1;
        else if (c == d && c != a && c != b && c != e)
            return 1;
        else if (d == e && d != a && d != b && d != c)
            return 1;
        else {
            return 0;
        }
    }
    else {
        int a, b, c, d, e;
        a = player2_card[0].value;
        b = player2_card[1].value;
        c = player2_card[2].value;
        d = player2_card[3].value;
        e = player2_card[4].value;
        if (a == b && a != c && a != d && a != e)
            return 1;
        else if (b == c && b != a && b != d && b != e)
            return 1;
        else if (c == d && c != a && c != b && c != e)
            return 1;
        else if (d == e && d != a && d != b && d != c)
            return 1;
        else {
            return 0;
        }
    }
}
//Function to check two pair for each player
int is_twopair(int player) {
    if (player == 1) {
        int a, b, c, d, e;
        a = player1_card[0].value;
        b = player1_card[1].value;
        c = player1_card[2].value;
        d = player1_card[3].value;
        e = player1_card[4].value;
        if ((a == b) && (check_three(c, d, e) == 1)) {
            return 1;
        }
        else if ((a == c) && (check_three(b, d, e) == 1)) {
            return 1;
        }
        else if ((a == d) && (check_three(c, b, e) == 1)) {
            return 1;
        }
        else if ((a == e) && (check_three(b, c, d) == 1)) {
            return 1;
        }
        else if ((b == c) && (check_three(a, d, e) == 1)) {
            return 1;
        }
        else if ((b == d) && (check_three(a, c, e) == 1)) {
            return 1;
        }
        else if ((b == e) && (check_three(a, c, d) == 1)) {
            return 1;
        }
        else if ((c == d) && (check_three(a, b, e) == 1)) {
            return 1;
        }
        else if ((c == e) && (check_three(a, b, d) == 1)) {
            return 1;
        }
        else if ((d == e) && (check_three(a, b, c) == 1)) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        int a, b, c, d, e;
        a = player2_card[0].value;
        b = player2_card[1].value;
        c = player2_card[2].value;
        d = player2_card[3].value;
        e = player2_card[4].value;
        if ((a == b) && (check_three(c, d, e) == 1)) {
            return 1;
        }
        else if ((a == c) && (check_three(b, d, e) == 1)) {
            return 1;
        }
        else if ((a == d) && (check_three(c, b, e) == 1)) {
            return 1;
        }
        else if ((a == e) && (check_three(b, c, d) == 1)) {
            return 1;
        }
        else if ((b == c) && (check_three(a, d, e) == 1)) {
            return 1;
        }
        else if ((b == d) && (check_three(a, c, e) == 1)) {
            return 1;
        }
        else if ((b == e) && (check_three(a, c, d) == 1)) {
            return 1;
        }
        else if ((c == d) && (check_three(a, b, e) == 1)) {
            return 1;
        }
        else if ((c == e) && (check_three(a, b, d) == 1)) {
            return 1;
        }
        else if ((d == e) && (check_three(a, b, c) == 1)) {
            return 1;
        }
        else {
            return 0;
        }
    }
}
int check_three(int x, int y, int z) {
    if (x == y || x == z || y == z) {
        return 1;
    }
    else {
        return 0;
    }
}

//Functions to check Tie brake
//Function for Tie break when player1 and player2 rank 2 i.e. One pair
int is_onepair_check() {
    int i, j, k = 0, one_pair_value1, one_pair_value2;
    int player1[5] = { NULL }, player2[5] = { NULL };
    int non_repeating_value1[3] = { NULL }, non_repeating_value2[3] = { NULL };

    //storing the player1 card values to an array variable.
    for (i = 0; i < 5; i++) {
        player1[i] = player1_card[i].value;
        player2[i] = player2_card[i].value;
    }

    for (i = 0; i < 5; i++) {
        for (j = i + 1; j < 5; j++) {
            if ((1<j<4)&& (player1[i] != player1[j-2])&&(player1[i] == player1[j])&&(player1[i] != player1[j+1]))
                one_pair_value1 = player1[i];
        }
    }
    //cout << one_pair_value1 << "\n";

    for (i = 0; i < 5; i++) {
        for (j = i + 1; j < 5; j++) {
            if ((1<j < 4) && (player2[i] != player2[j - 2]) && (player2[i] == player2[j]) && (player2[i] != player2[j+1]))
                one_pair_value2 = player2[i];
        }
    }
    k = 0;
    //  checking the least card value of player1 and player2
    while (k < 3) {
        for (i = 0; i < 5; i++) {
            int m;
            for (m = 0; m < 5; m++)
                if (i != m && player1[i] == player1[m])
                    break;
            if (m == 5) {
                non_repeating_value1[k] = player1[i];
                k++;
            }
        }
        k++;
    }
    k = 0;
    while (k < 3) {
        for (i = 0; i < 5; i++) {
            int m;
            for (m = 0; m < 5; m++)
                if (i != m && player2[i] == player2[m])
                    break;
            if (m == 5) {
                non_repeating_value2[k] = player2[i];
                k++;
            }
        }
        k++;
    }

    if (one_pair_value1 > one_pair_value2|| non_repeating_value2[0]==0|| non_repeating_value2[1]==0|| non_repeating_value2[2]==0||
        non_repeating_value1[0]==0|| non_repeating_value1[1]==0|| non_repeating_value1[2]==0)
        return 1;
    else if ((one_pair_value1 == one_pair_value2) && (non_repeating_value1[2] > non_repeating_value2[2]))
        return 1;
    else if ((one_pair_value1 == one_pair_value2) && (non_repeating_value1[2] == non_repeating_value2[2])&&(non_repeating_value1[1] > non_repeating_value2[1]))
        return 1;
    else if ((one_pair_value1 == one_pair_value2) && (non_repeating_value1[2] == non_repeating_value2[2]) && 
        (non_repeating_value1[1] == non_repeating_value2[1])&& (non_repeating_value1[0] > non_repeating_value2[0]))
        return 1;
    else
        return 2;
}
//Function for Tie break when player1 and player2 rank 3 i.e. Two pair
int is_twopair_check() {
    int i, j, k=0,one_pair_value1, one_pair_value2, non_repeating_value1=0, non_repeating_value2 = 0;
    int value1[5] = { NULL }, value2[5] = { NULL };
    int player1[5] = { NULL }, player2[5] = { NULL };
   
    //storing the player1 card values to an array variable.
    for (i = 0; i < 5; i++) {
        player1[i] = player1_card[i].value;
        player2[i] = player2_card[i].value;
    }

    while (k < 2) {
        for (i = 0; i < 5; i++) {
            for (j = i + 1; j < 5; j++) {
                if (player1[i] == player1[j]) {
                    value1[k] = player1[i];
                    k++; i++; j++;
                    continue;
                }
            }
        }
    }
    k = 0;
    while (k < 2) {
        for (i = 0; i < 5; i++) {
            for (j = i + 1; j < 5; j++) {
                if (player2[i] == player2[j]) {
                    value2[k] = player2[i];
                    k++; i++; j++;
                    continue;
                }
            }
        }
    }

  //  checking the least card value of player1 and player2
    for (i = 0; i < 5; i++) {
        int m;
        for (m = 0; m < 5; m++) 
            if (i != m && player1[i] == player1[m])
                break;
            if (m == 5)
                non_repeating_value1 = player1[i];
        
    }
    for (i = 0; i < 5; i++) {
        int m;
        for (m = 0; m < 5; m++)
            if (i != m && player2[i] == player2[m])
                break;
        if (m == 5)
            non_repeating_value2 = player2[i];

    }

 
    if ((value1[1] == value2[1]) && (value1[1] > value2[1])) 
        return 1;
    else if ((value1[0] == value2[0]) && value1[0] > value2[0]) 
        return 1;
    else if ((value1[1] == value2[1]) && (value1[0] == value2[0]) && (non_repeating_value1 > non_repeating_value2))
        return 1;
    else
        return 2;
}
//Function for Tie break when player1 and player2 rank 4 i.e. Three of Kind
int is_tok_check() {
    int i, j, k = 0, tok_pair_value1, tok_pair_value2;
    int player1[5], player2[5];
    int non_repeating_value1[3], non_repeating_value2[3];
    int counter1=0, counter2=0;

    //storing the player1 card values to an array variable.

    for (i = 0; i < 5; i++) {
        for (j = i + 1; j < 5; j++) {
            if ((player1_card[i].value == player1_card[j].value)&&(player1_card[i].value == player1_card[j+1].value)) {
                tok_pair_value1 = player1_card[i].value;
            }
        }
    }
    for (i = 0; i < 5; i++) {
        for (j = i + 1; j < 5; j++) {
            if ((player2_card[i].value == player2_card[j].value) && (player2_card[i].value == player2_card[j + 1].value))
                tok_pair_value2 = player2_card[i].value;
        }
    }

 
    if (tok_pair_value1 > tok_pair_value2)
        return 1;
    else
        return 2;
}
//Function for Tie break when player1 and player2 rank 7 i.e. Full House
int is_fullhouse_check() {
    int tok_check, onepair_check;
    tok_check = is_tok_check();
    onepair_check = is_onepair_check();


    if (tok_check == 1 && onepair_check == 1)
        return 1;
    else
        return 2;

}
//Function for Tie break when player1 and player2 rank 5 i.e. Straight
int is_straight_check() {
    int i, j, k = 0, one_pair_value1, one_pair_value2, non_repeating_value1 = 0, non_repeating_value2 = 0;
    int value1[5] = { NULL }, value2[5] = { NULL };
    int player1[5] = { NULL }, player2[5] = { NULL };

    //storing the player1 card values to an array variable.
    for (i = 0; i < 5; i++) {
        player1[i] = player1_card[i].value;
        player2[i] = player2_card[i].value;
    }

    if (player1[4] > player2[4])
        return 1;
    else if ((player1[4] == player2[4]) && (player1[3] > player2[3]))
        return 1;
    else if ((player1[4] == player2[4]) && (player1[3] == player2[3]) && (player1[2] > player2[2]))
        return 1;
    else if ((player1[4] == player2[4]) && (player1[3] == player2[3]) && (player1[2] == player2[2]) && (player1[1] > player2[1]))
        return 1;
    else if ((player1[4] == player2[4]) && (player1[3] == player2[3]) && (player1[2] == player2[2]) && (player1[1] == player2[1]) && (player1[0] > player2[0]))
        return 1;
    else
        return 2;

}
//Function for Tie break when player1 and player2 rank 1 i.e. High card
int is_check() {
    int i, j, k = 0, one_pair_value1, one_pair_value2, non_repeating_value1 = 0, non_repeating_value2 = 0;
    int value1[5] = { NULL }, value2[5] = { NULL };
    int player1[5] = { NULL }, player2[5] = { NULL };

    //storing the player1 card values to an array variable.
    for (i = 0; i < 5; i++) {
        player1[i] = player1_card[i].value;
        player2[i] = player2_card[i].value;
    }

    if (player1[4] > player2[4])
        return 1;
    else if ((player1[4] == player2[4]) && (player1[3] > player2[3]))
        return 1;
    else if ((player1[4] == player2[4]) && (player1[3] == player2[3]) && (player1[2] > player2[2]))
        return 1;
    else if ((player1[4] == player2[4]) && (player1[3] == player2[3]) && (player1[2] == player2[2]) && (player1[1] > player2[1]))
        return 1;
    else if ((player1[4] == player2[4]) && (player1[3] == player2[3]) && (player1[2] == player2[2]) && (player1[1] == player2[1]) && (player1[0] > player2[0]))
        return 1;
    else
        return 2;

}
//Function for Tie break when player1 and player2 rank 6 i.e. Is Flush
int is_flush_check() {
    int i;
    char player1[5] = { NULL }, player2[5] = { NULL };
    int player1_v[5] = { NULL }, player2_v[5] = { NULL };

    //storing the player1 card values to an array variable.
    for (i = 0; i < 5; i++) {
        player1[i] = player1_card[i].color;
        player2[i] = player2_card[i].color;
        player1_v[i] = player1_card[i].value;
        player2_v[i] = player2_card[i].value;
    }

    if (player1[0] == player2[0] && player1[1] == player2[1] && player1[2] == player2[2] && player1[3] == player2[3] && player1[4] == player2[4])
        if (player1_v[4] > player2_v[4])
            return 1;
        else
            return 2;


}
//Function for Tie break when player1 and player2 rank 9 i.e. Is straight flush
int is_straight_flush_check() {
    int straight_check, flush_check;
    straight_check = is_straight_check();

    flush_check = is_flush_check();

    if (straight_check == 1 && flush_check == 1)
        return 1;
    else
        return 2;

}
//Function for Tie break when player1 and player2 rank 8 i.e. Four of Kind
int is_fourofkind_check() {
    int i, j, k = 0, four_pair_value1, four_pair_value2, non_repeating_value1, non_repeating_value2;
    int player1[5], player2[5];
    int counter1 = 0, counter2 = 0;

    for (i = 0; i < 5; i++) {
        player1[i] = player1_card[i].value;
        player2[i] = player2_card[i].value;
    }

    //storing the player1 card values to an array variable.

    for (i = 0; i < 2; i++) {
        for (j = i + 1; j < 5; j++) {
            if ((player1_card[i].value == player1_card[j].value) && (player1_card[i].value == player1_card[j + 1].value)&&
                (player1_card[i].value == player1_card[j + 2].value)) {
                four_pair_value1 = player1_card[i].value;
            }
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = i + 1; j < 5; j++) {
            if ((player2_card[i].value == player2_card[j].value) && (player2_card[i].value == player2_card[j + 1].value)&&
                (player2_card[i].value == player2_card[j + 2].value))
                four_pair_value2 = player2_card[i].value;
        }
    }

    for (i = 0; i < 5; i++) {
        int m;
        for (m = 0; m < 5; m++)
            if (i != m && player1[i] == player1[m])
                break;
        if (m == 5)
            non_repeating_value1 = player1[i];

    }
    for (i = 0; i < 5; i++) {
        int m;
        for (m = 0; m < 5; m++)
            if (i != m && player2[i] == player2[m])
                break;
        if (m == 5)
            non_repeating_value2 = player2[i];

    }

 
    if (four_pair_value1 > four_pair_value2)
        return 1;
    else if (four_pair_value1 == four_pair_value2 && non_repeating_value1 > non_repeating_value2)
        return 1;
    else
        return 2;

}