#include "Boggle.h"
#include "grid.h"
#include "shuffle.h"
#include <string>
#include "string"
#include "strlib.h"
#include "bogglegui.h"

// letters on all 6 sides of every cube
static string CUBES[16] = {
    "AAEEGN", "ABBJOO", "ACHOPS", "AFFKPS",
    "AOOTTW", "CIMOTU", "DEILRX", "DELRVY",
    "DISTTY", "EEGHNW", "EEINSU", "EHRTVW",
    "EIOSST", "ELRTTY", "HIMNQU", "HLNNRZ"
};

// letters on every cube in 5x5 "Big Boggle" version (extension)
static string BIG_BOGGLE_CUBES[25] = {
   "AAAFRS", "AAEEEE", "AAFIRS", "ADENNN", "AEEEEM",
   "AEEGMU", "AEGMNN", "AFIRSY", "BJKQXZ", "CCNSTW",
   "CEIILT", "CEILPT", "CEIPST", "DDLNOR", "DDHNOT",
   "DHHLOR", "DHLNOR", "EIIITT", "EMOTTT", "ENSSSU",
   "FIPRSY", "GORRVW", "HIPRRY", "NOOTUW", "OOOTTU"
};

Boggle::Boggle(Lexicon& dictionary, string boardText) {

    dict = dictionary;
    board.resize(4,4);

    int index = 0;

    if (boardText.empty()) { //random
        for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 4; col++) {
                board[row][col] = shuffle(CUBES[index])[0];
                index++;
            }
        }

        shuffle(board);

    } else {

        for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 4; col++) {
                board[row][col] = boardText[index];
                index++;
            }
        }
    }
}


void Boggle::addScore(string word, Player player) {
    int score = word.size() - 3;

    if (player == HUMAN) {
        humanScore+=score;
        BoggleGUI::setScore(humanScore,BoggleGUI::HUMAN);
    } else {
        computerScore+=score;
        BoggleGUI::setScore(computerScore,BoggleGUI::COMPUTER);
    }

}


Vector<Tuple > Boggle::getNeighbours(int row, int col) {
    Vector<Tuple> avail;

    //east
    if (inBounds(row,col+1)) {
        Tuple east (0,1);
        avail.add(east);
    }
    //southeast
    if (inBounds(row+1,col+1)) {
        Tuple southEast (1,1);
        avail.add(southEast);
    }

    //northwest
    if (inBounds(row-1,col-1)) {
        Tuple northEast (-1,-1);
        avail.add(northEast);
    }

    //southhwest
    if (inBounds(row+1,col-1)) {
        Tuple southWest (1,-1);
        avail.add(southWest);
    }

    //northeast
    if (inBounds(row-1,col+1)) {
        Tuple northEast (-1,1);
        avail.add(northEast);
    }

    //west
    if (inBounds(row, col-1)) {
        Tuple west (0,-1);
        avail.add(west);
    }

    //south
    if (inBounds(row+1,col)) {
        Tuple south (1,0);
        avail.add(south);
    }

    //north
    if (inBounds(row-1,col)) {
        Tuple north (-1,0);
        avail.add(north);
    }

    return avail;
}

Grid<char> Boggle::getBoard() const {
    return board;
}

Lexicon Boggle::getLexicon() const {
    return dict;
}

Set<string> Boggle::getHumanFound() const {
    return humanFound;
}

char Boggle::getLetter(int row, int col) const {
    return board[row][col];
}

int Boggle::getScoreHuman() const{
    return humanScore;
}

int Boggle::getScoreComputer() const{
    return computerScore;
}

void Boggle::addHumanFoundWord(string word) {
    humanFound.add(word);
}


bool Boggle::inBounds(int row, int col) {

    if ((row > -1) && (row < 4 ) && (col > -1) && (col <  4) ) {
        return true;

    } else {
        return false;
    }

}

bool Boggle::checkWord(string word) {

    word = toLowerCase(word);
    if ( (!humanFound.contains(word)) && (word.size()>3) && (dict.contains(word)) ) {
        return true;
    }
    return false;
}

bool Boggle::helperHumanWordSearch(string word, int row, int col, Grid<bool>& visited) {

    if (word.empty()) {
        return true;

    } else {

        if (getLetter(row,col) == word[0]) {

            // choose a  cube
            if (!visited[row][col]) {
                    visited[row][col] = true;
                    //BoggleGUI::setHighlighted(row,col);

                //explore, for all available positions around current cube
                for (Tuple dir : getNeighbours(row,col)) {
                    char c = word[0];
                    bool found = helperHumanWordSearch(word.erase(0,1), row+dir.row, col+dir.col, visited);
                    if (found) {
                        return true;
                    }

                    //un-choose
                    visited[row+dir.row][col+dir.col] = false;
                    word.insert(0,1,c);
                }
            }
        }
    }

    return false;
}

bool Boggle::humanWordSearch(string word) {

    word = toUpperCase(word);

    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            Grid<bool> visited (4, 4, false);
            bool possible = helperHumanWordSearch(word, row, col, visited);
            if (possible) {
                return true;
            }
        }
    }
    return false;
}


void Boggle::computerWordSearchHelper(string prefix, Set<string>& result,int row, int col, Grid<bool>& visited ) {

    if ((checkWord(prefix)) && (!result.contains(prefix))) {
        result.add(prefix);
        addScore(prefix,COMPUTER);
        BoggleGUI::recordWord(prefix, BoggleGUI::COMPUTER);
        computerWordSearchHelper(prefix, result, row, col, visited);

    } else {

        if (dict.containsPrefix(prefix)) {
            // choose a  cube
            if (!visited[row][col]) {
                visited[row][col] = true;

                for (Tuple dir : getNeighbours(row,col)) {
                    int x = row+dir.row;
                    int y = col+dir.col;
                    if (!visited[x][y]) {
                        char toBeAdded = getLetter(x,y);
                        prefix+=toBeAdded;
                        computerWordSearchHelper(prefix, result, row+dir.row, col+dir.col, visited);
                        prefix.erase(prefix.size()-1,1);
                    }
                }
                visited[row][col] = false;
            }
        }
    }
}

Set<string> Boggle::computerWordSearch() {
    //check found by human
    Set<string> result;
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            string start;
            start+=getLetter(row,col);
            Grid<bool> visited (4, 4, false);
            computerWordSearchHelper(start, result,row,col, visited);
        }
    }
    cout << result<< endl;
    return result;
}

ostream& operator<<(ostream& out, Boggle& boggle) {
    out << boggle.board.toString2D();
    return out;
}
