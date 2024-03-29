  // Matthew Holzem CPSC Section 08
  #include <iostream>
  #include <stdlib.h>
  #include <fstream>
  #include <string>

  using namespace std;

  const int ROWS = 22;
  const int COLS = 80;
  const int BOARD_ROWS(20);
  const int BOARD_COLS(78);
  const char LIVE = 'X';
  const char DEAD = '.';
  char NewBoard[ROWS][COLS];
  char quit;

  void NextState(char board[][COLS]);
  bool MakeArray(string filename, char board[][COLS]);
  void SwitchBoard (char board[][COLS]);
  void GameBoard(char board[][COLS]);


  int main() {
    char board [ROWS][COLS];
    for (int l = 0; l<20; l++) {
      NextState(board);
      GameBoard(board);
      SwitchBoard(board);
    }
    char q;
    cin >> q;
    return 0;
  }

  bool MakeArray(string filename, char board[][COLS]) {
    ifstream myfile;
    myfile.open (filename.c_str());
    if (!myfile) return true;
    for (int r=0; r<ROWS; r++) {
      for (int c=0; c<COLS; c++) {
        myfile>>board[r][c];
      }
    }
    myfile.close();
    return false;
  }

  void GameBoard (char board[][COLS]) {
    for (int r=1; r<=ROWS-2; r++) {
      for (int c=1; c<=COLS-2; c++) {
        cout<<board[r][c];
      }
      cout<<endl;
    }
    cout<<endl;
  }

  void NextState (char board[][COLS]) {
    for (int r=0; r<ROWS; r++) {
      for (int c=0; c<COLS; c++) {
        int LiveCnt=0;
        if (board[r-1][c-1]==LIVE) {
          LiveCnt++;
        }
        if (board[r-1][c]==LIVE) {
          LiveCnt++;
        }

        if (board[r-1][c+1]==LIVE) {
          LiveCnt++;
        }
        if (board[r][c-1]==LIVE) {
          LiveCnt++;
        }
        if (board[r][c+1]==LIVE) {
          LiveCnt++;
        }
        if (board[r+1][c-1]==LIVE) {
          LiveCnt++;
        }
        if (board[r+1][c+1]==LIVE) {
          LiveCnt++;
        }
        NewBoard[r][c] = DEAD;
        if (board[r][c] == LIVE && LiveCnt < 2) {
          NewBoard[r][c]=DEAD;
        }
        else if (board[r][c]==LIVE && (LiveCnt==2)) {
          NewBoard[r][c]=LIVE;
        }
        else if (board[r][c]==LIVE && LiveCnt>3 ) {
          NewBoard[r][c]=DEAD;
        }
        else if (board[r][c]==DEAD) {
          NewBoard[r][c]=LIVE;
        }
      }
    }
  }

  void SwitchBoard(char board[][COLS]) {
    for (int r=0; r<ROWS; r++) {
      for (int c=0; c<COLS; c++) {
        board[r][c]=NewBoard[r][c];
      }
    }
  }
