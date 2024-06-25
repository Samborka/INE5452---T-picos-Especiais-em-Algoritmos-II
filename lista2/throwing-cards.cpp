#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void simulateGame(int n) {
  queue<int> deck;
  vector<int> discardedCards;

  // Initialize the deck
  for (int i = 1; i <= n; i++) {
    deck.push(i);
  }

  while (deck.size() >= 2) {
    // Discard the top card
    discardedCards.push_back(deck.front());
    deck.pop();

    // Move the new top card to the bottom
    int newTopCard = deck.front();
    deck.pop();
    deck.push(newTopCard);
  }

  cout << "Discarded cards:";
  for (int i = 0; i < discardedCards.size(); i++) {
    cout << " " << discardedCards[i];
    if (i != discardedCards.size() - 1) {
      cout << ",";
    }
  }
  cout << endl;

  cout << "Remaining card: " << deck.front() << endl;
}

int main() {
  int n;
  while (cin >> n && n != 0) {
    simulateGame(n);
  }
  return 0;
}