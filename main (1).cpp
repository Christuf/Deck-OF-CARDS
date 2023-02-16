#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

class Card {
public:
    Card(char r, char s) : rank(r), suit(s) {}
    char rank;
    char suit;
};

class Deck {
public:
    Deck() {
        for (char s : {'C', 'D', 'H', 'S'}) {
            for (char r : {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'}) {
                cards.push_back(Card(r, s));
            }
        }
    }
    void shuffle() {
        random_device rd;
        mt19937 g(rd());
        std::shuffle(cards.begin(), cards.end(), g);
    }
    Card draw() {
        Card c = cards.back();
        cards.pop_back();
        return c;
    }
    vector<Card> cards;
};

int main() {
    Deck d;
    d.shuffle();
    vector<vector<Card>> hands(2);
    for (int i = 0; i < 5; ++i) {
        for (auto& hand : hands) {
            hand.push_back(d.draw());
        }
    }
    // Print out the hands for testing purposes.
    for (auto& hand : hands) {
        for (auto& card : hand) {
            cout << card.rank << card.suit << " ";
        }
        cout << endl;
    }
    return 0;
}

