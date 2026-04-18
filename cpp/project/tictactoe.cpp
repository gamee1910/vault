#include <algorithm>
#include <array>
#include <endian.h>
#include <ios>
#include <iostream>
#include <limits>

using namespace std;
using Board = std::array<char, 9>;

void printBoard(const Board &board) {
  cout << "\n";
  for (int i = 0; i < 9; i++) {
    char cell = board[i];
    if (cell == ' ') {
      cout << (i + 1);
    } else {
      cout << cell;
    }

    if ((i + 1) % 3 == 0) {
      cout << "\n";
    } else {
      cout << "|";
    }
  }
  std::cout << "\n";
}

bool checkWin(const Board &board, char player) {
  constexpr array<array<int, 3>, 8> lines = {{{0, 1, 2},
                                              {3, 4, 5},
                                              {6, 7, 8}, // rows
                                              {0, 3, 6},
                                              {1, 4, 7},
                                              {2, 5, 8}, // cols
                                              {0, 4, 8},
                                              {2, 4, 6}}};

  for (auto &line : lines) {
    if (board[line[0]] == player && board[line[1]] == player &&
        board[line[2]] == player) {
      return true;
    }
  }
  return false;
}

bool isDraw(const Board &board) {
  for (char c : board) {
    if (c == ' ')
      return false;
  }
  return true;
}

// MiniMax AI
int minimax(Board board, bool isMaximizing) {
  if (checkWin(board, 'O'))
    return 10;
  if (checkWin(board, 'X'))
    return -10;
  if (isDraw(board))
    return 0;

  if (isMaximizing) {
    int best = numeric_limits<int>::min();
    for (int i = 0; i < 9; i++) {
      if (board[i] == ' ') {
        board[i] = 'O';
        best = max(best, minimax(board, false));
        board[i] = ' ';
      }
    }
    return best;
  } else {
    int best = numeric_limits<int>::max();
    for (int i = 0; i < 9; i++) {
      if (board[i] == ' ') {
        board[i] = 'X';
        best = min(best, minimax(board, true));
        board[i] = ' ';
      }
    }
    return best;
  }
}

int bestMove(Board board) {
  int bestVal = numeric_limits<int>::min();
  int move = -1;
  for (int i = 0; i < 9; i++) {
    if (board[i] == ' ') {
      board[i] = 'O';
      int val = minimax(board, false);
      board[i] = ' ';
      if (val > bestVal) {
        bestVal = val;
        move = i;
      }
    }
  }
  return move;
}

int getPlayerInput(const Board &board) {
  int position;
  while (true) {
    cout << "Your move (1-9): ";
    cin >> position;
    if (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid input.\n";
      continue;
    }
    position--;
    if (position < 0 || position > 8) {
      cout << "Out of range.\n";
      continue;
    }
    if (board[position] != ' ') {
      cout << "Cell taken.\n";
      continue;
    }
    return position;
  }
}

void playVsAI() {
  Board board;
  board.fill(' ');

  cout << "\n=== Player (X) vs AI (O) ===\n";
  cout << "Board postition: \n 1 | 2 | 3\n 4 | 5 | 6\n 7 | 8 | 9\n";

  while (true) {
    printBoard(board);

    // Player turn
    int postition = getPlayerInput(board);
    board[postition] = 'X';
    if (checkWin(board, 'X')) {
      printBoard(board);
      cout << "You win!\n";
      return;
    }
    if (isDraw(board)) {
      printBoard(board);
      cout << "Draw\n";
      return;
    }

    // AI turn
    cout << "AI is thinking...\n";
    int ai = bestMove(board);
    board[ai] = 'O';
    cout << "AI played position " << (ai + 1) << "\n";
    if (checkWin(board, 'O')) {
      printBoard(board);
      cout << "AI win\n";
      return;
    }
    if (isDraw(board)) {
      printBoard(board);
      cout << "Draw!\n";
      return;
    }
  }
}

void playVsHuman() {
  Board board;
  board.fill(' ');
  char current = 'X';

  cout << "\n=== Player (X) Vs Player (O) ===\n";
  cout << "Board position: \n 1 | 2 | 3\n 4 | 5 | 6\n 7 | 8 | 9\n";

  while (true) {
    printBoard(board);
    cout << "Player " << current << "'s turn.\n";
    int position = getPlayerInput(board);
    board[position] = current;

    if (checkWin(board, 'X')) {
      printBoard(board);
      cout << "Player " << current << " wins\n";
      return;
    }

    if (isDraw(board)) {
      printBoard(board);
      cout << "Draw.\n";
      return;
    }

    current = (current == 'X') ? 'O' : 'X';
  }
}

int main() {
  cout << "=== Tic Tac Toe ===\n";

  while (true) {
    cout << "\n1. vs AI\n2. vs Human\n3. Quit\nChoice: ";
    int choice;
    cin >> choice;

    if (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }

    if (choice == 1)
      playVsAI();
    if (choice == 2)
      playVsHuman();
    else if (choice == 3)
      break;
  }

  return 0;
}
