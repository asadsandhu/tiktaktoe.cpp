#include <iostream>
using namespace std;

void displayBoard(char box[][3]) {
    system("cls");
    cout << "\n\t\t  Tic Tac Toe\n\n";
    cout << "Player 1 (X)  -  Player 2 (O)\n\n";
    cout << "     |     |     \n";
    cout << "  " << box[0][0] << "  |  " << box[0][1] << "  |  " << box[0][2] << endl;
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << box[1][0] << "  |  " << box[1][1] << "  |  " << box[1][2] << endl;
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << box[2][0] << "  |  " << box[2][1] << "  |  " << box[2][2] << endl;
    cout << "     |     |     \n\n";
}

bool checkWin(char box[][3], char player) {
    // Check rows, columns, and diagonals
    for(int i = 0; i < 3; i++) {
        if(box[i][0] == player && box[i][1] == player && box[i][2] == player) return true;
        if(box[0][i] == player && box[1][i] == player && box[2][i] == player) return true;
    }
    if(box[0][0] == player && box[1][1] == player && box[2][2] == player) return true;
    if(box[0][2] == player && box[1][1] == player && box[2][0] == player) return true;
    return false;
}

bool checkDraw(char box[][3]) {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(box[i][j] >= '1' && box[i][j] <= '9') return false;
    return true;
}

void playGame() {
    char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    int currentPlayer = 1;
    char mark;
    int choice;
    char input;

    do {
        displayBoard(board);
        currentPlayer = (currentPlayer % 2) ? 1 : 2;
        mark = (currentPlayer == 1) ? 'X' : 'O';
        
        cout << "Player " << currentPlayer << " (" << mark << "), enter a number: ";
        cin >> input;
        
        // Validate input
        if(!isdigit(input) || (choice = input - '0') < 1 || choice > 9) {
            cout << "Invalid input! Please try again.";
            cin.ignore();
            cin.get();
            continue;
        }

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if(board[row][col] >= '1' && board[row][col] <= '9') {
            board[row][col] = mark;
            currentPlayer++;
        } else {
            cout << "Position already occupied!";
            cin.ignore();
            cin.get();
        }

        if(checkWin(board, mark)) {
            displayBoard(board);
            cout << "Player " << (currentPlayer - 1) << " (" << mark << ") wins!\n";
            return;
        }
    } while(!checkDraw(board));

    displayBoard(board);
    cout << "Game draw!\n";
}

void showRules() {
    system("cls");
    cout << "Game Rules:\n";
    cout << "1. The game is played on a 3x3 grid\n";
    cout << "2. Players take turns (X starts first)\n";
    cout << "3. Win by placing 3 marks in a row/column/diagonal\n";
    cout << "4. Game ends in draw if all positions are filled\n";
    cout << "\nPress any key to return to menu...";
    cin.ignore();
    cin.get();
}

int main() {
    char choice;
    
    do {
        system("cls");
        cout<<"\t\t-------------------------------------------------------------------------\n";
		cout<<"\t\t-------------------------------Tik Tak Toe-------------------------------\n";
		cout<<"\t\t-------------------------------------------------------------------------\n";
        cout << "1. Play Game\n";
        cout << "2. Game Rules\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case '1':
                playGame();
                cout << "\nPress any key to return to menu...";
                cin.ignore();
                cin.get();
                break;
            case '2':
                showRules();
                break;
            case '3':
                cout << "Exiting game...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
                cin.ignore();
                cin.get();
        }
    } while(choice != '3');

    return 0;
}