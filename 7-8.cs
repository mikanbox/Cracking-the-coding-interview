using System;

public class Cell {
    public int id; // -1 ,0 ,1 white / empty / black

    public bool isEmpty() {
        return false;
    }

    
}


public class Board {
    private vector<vector<Cell>> cells;

    public Board (){
        // pieces
    }

    private void PutInitialPieces() {

    }

    public bool PutPiece(int x, int y) {

        // if cells[x][y].isEmpty();
        // isFlippable
        // cells[x][y].putPiece()
    }

    private bool isFlippable() {

    }


    public int GetAmountofPieces() {

    }


    public bool isPuttable() {

    }
}




public class Player {
    private bool _isWhite;

    public (int, int) InputPiecePosition() {
        int x, y;

        return (x, y);
    }
}

public class Othello {
    private Board _board;
    private vector<Player> _players;
    private int _turn = 0;

    private int _playernum = 2;



    public void main() {
        _board = new Board();

        while(!isGameEnd()) {
            PutPiece(_players[_turn % _playernum]._isWhite);
            _turn++;
        }

        GetWinnerPlayer();
    }


    public void PutPiece(Player player) {
        (int x, int y) = player.InputPiecePosition();
        _board.PutPiece(x, y);
    }

    public void GetWinnerPlayer() {
        // GetAmountofPieces()
    }

    private bool isGameEnd() {
        
    }
}




