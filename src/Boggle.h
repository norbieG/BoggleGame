#ifndef _boggle_h
#define _boggle_h

#include <iostream>
#include <string>
#include "lexicon.h"
#include "grid.h"
#include "Boggle.h"
using namespace std;

enum Player { HUMAN, COMPUTER };

struct Tuple {
    int row;
    int col;

    //constructor
    Tuple (int r = 0, int c =0) {
        row = r;
        col = c;
    }
};


class Boggle {
public:
    Boggle(Lexicon& dictionary, string boardText = "");

    char getLetter(int row, int col) const;
    bool checkWord(string word);
    bool humanWordSearch(string word);
    Set<string> computerWordSearch();
    int getScoreHuman() const;
    int getScoreComputer() const;
    bool helperHumanWordSearch(string word, int row, int col, Grid<bool>& visited);
    bool inBounds(int row, int col);
    void addHumanFoundWord(string word);
    Set<string> getHumanFound() const;
    Lexicon getLexicon() const;
    Vector<Tuple> getNeighbours(int row, int col);
    void computerWordSearchHelper(string prefix, Set<string>& result,int row, int col, Grid<bool>& visited );
    void addScore(string word, Player player);
    Grid<char> getBoard() const;


    // TODO: add any other member functions/variables necessary
    friend ostream& operator<<(ostream& out, Boggle& boggle);


private:
    // TODO: add any other member functions/variables necessary
    Grid<char> board;
    Lexicon dict;
    Set<string> humanFound;
    Set<string> computerFound;
    int humanScore = 0;
    int computerScore = 0;

};

#endif // _boggle_h
