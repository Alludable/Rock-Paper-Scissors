#include <iostream>
#include <ctime>

using namespace std;

char showWinner(char player, char computer, int comp_tally, int player_tally);
char getUserChoice();
char getComputerChoice();
void showChoice(char choice);

int main() {
    char player;
    char computer;
    int comp_tally = 0;
    int player_tally = 0;
    int rounds = 5;
    char result;

    int i = 1;

    do {
    player = getUserChoice();
    cout << "Player choice: ";
    showChoice(player);
    
    cout << "Computer's Turn " << endl;

    computer = getComputerChoice();
    cout << "Computer choice: ";
    showChoice(computer);

    result = showWinner(player, computer, comp_tally, player_tally);
    
    if (result == 'p') {
        player_tally += 1;
    } else if (result == 'c'){
        comp_tally += 1;
    }

    cout << "Player Wins: " << player_tally << endl;
    cout << "Computer Wins: " << comp_tally << endl;

    i++;

    } while (i <= rounds);

    if (player_tally > comp_tally) {
        cout << "You won against the computer! " << endl;
    } else if (comp_tally > player_tally) {
        cout << "Sorry, the computer won. " << endl;
    } else {
        cout << "You and the computer have tied! " << endl;
    }

    return 0;
}

char getComputerChoice() {
    srand(time(0));
    int computer_num = rand() % 3 + 1;
    char computer_choice;

    switch (computer_num) {
        case 1:
            computer_choice = 'r';
            break;
        
        case 2:
            computer_choice = 'p';
            break;
        
        case 3:
            computer_choice = 's';
            break;
    }
    return computer_choice;
}

char getUserChoice() {
    char player_choice;

    do {
    cout << "Rock, Paper, or Scissors: (Input 'r', 'p', or 's') " << endl;
    cin >> player_choice;

    if (player_choice != 'r' && player_choice != 'p' && player_choice != 's') {
        cout << "Please choose a valid choice." << endl;
    } else {
        continue;
    }

    }while (player_choice != 'r' && player_choice != 'p' && player_choice != 's');

    return player_choice;
}

void showChoice(char choice) {
    switch(choice) {
        case 'r':
            cout << "Rock" << endl;
            break;

        case 'p':
            cout << "Paper" << endl;
            break;

        case 's':
            cout << "Scissors" << endl;
            break;
    }
}

char showWinner(char player, char computer, int comp_tally, int player_tally) {

    if (player == 'r' && computer == 's') {
        cout << "Rock crushes scissors! Player wins!" << endl;
        player_tally += 1;
    } else if (player == 'p' && computer == 'r') {
        cout << "Paper covers rock! Player wins!" << endl;
        player_tally += 1;
    } else if (player == 's' && computer == 'p') {
        cout << "Scissors cuts paper! Player wins!" << endl;
        player_tally += 1;
    } else  if (computer == 'r' && player == 's') {
        cout << "Rock crushes scissors! Computer wins!" << endl;
        comp_tally += 1;
    } else if (computer == 'p' && player == 'r') {
        cout << "Paper covers rock! Computer wins!" << endl;
        comp_tally += 1;
    } else if (computer == 's' && player == 'p') {
        cout << "Scissors cuts paper! Computer wins!" << endl;
        comp_tally += 1;
    } else {
        cout << "Tie game! Next round " << endl;
    }

    if (player_tally > comp_tally) {
        return 'p';
    } else if (comp_tally > player_tally) {
        return 'c';
    }
}