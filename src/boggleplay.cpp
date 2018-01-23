#include "lexicon.h"
#include "Boggle.h"
#include "simpio.h"
#include "set.h"
#include <cctype>
#include "bogglegui.h"

void printScore(int humanRes, int compRes) {
    if (compRes > humanRes) {
        string msg = "Ha ha ha, I destroyed you. Better luck next time, puny human!";
        cout << msg <<endl;
        BoggleGUI::setStatusMessage(msg);
    } else {
        string msg = "WOW, you defeated me! Congratulations!";
        cout << msg <<endl;
        BoggleGUI::setStatusMessage(msg);
    }
}

bool isValid(string input) {

    if (input.length()!=16) {
        return false;
    }

    for (char c : input) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}

void computersTurn(Boggle& board) {
    cout <<"My turn!"<<endl;
    BoggleGUI::setStatusMessage("My turn!");
    board.computerWordSearch();
    cout<< "My score: " << board.getScoreComputer()<<endl;
}

void humansTurn (Boggle& board) {
    cout<<"It's your turn!"<<endl;
    BoggleGUI::setStatusMessage("It's your turn!");

    while (true) {
        cout<<board<<endl;
        string word = getLine("Type a word (or Enter to stop)");

        if (word=="") {
            break;

        } else {

            if (board.checkWord(word) && (!board.getHumanFound().contains(word)) && (board.getLexicon().contains(word)) && (board.humanWordSearch(word))) {
                word = toUpperCase(word);
                board.addHumanFoundWord(word);
                board.addScore(word, HUMAN);
                BoggleGUI::recordWord(word, BoggleGUI::HUMAN);

            }
            cout<< "Your words (" << board.getHumanFound().size()<<"): "<< board.getHumanFound() << endl;
            cout<< "Your score: " << board.getScoreHuman()<<endl;
        }
    }

}

void playOneGame(Lexicon& dictionary) {

    BoggleGUI::initialize(4,4);
    string final;

    if (getYesOrNo("Do you want to generate a random board? (Y/N)? ")) {

        Boggle boggle(dictionary, final);
        Grid<char> setup = boggle.getBoard();

        for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 4; col++) {
                BoggleGUI::labelCube(row,col,setup[row][col]);

            }
        }

        humansTurn (boggle);
        computersTurn(boggle);
        printScore(boggle.getScoreHuman(),boggle.getScoreComputer());

    } else {

        while (true) {

            final = getLine("Enter a string of 16 characters, representing the cubes from left to right, top to bottom");

            if (isValid(final)) {
                final = toUpperCase(final);
                break;
            }
        }

        BoggleGUI::labelAllCubes(final);
        Boggle boggle(dictionary, final);
        humansTurn (boggle);
        computersTurn(boggle);
        printScore(boggle.getScoreHuman(),boggle.getScoreComputer());
    }
}
