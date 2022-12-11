#include <iostream>
using std::cout;
#include <vector>
using std::vector;


enum class Suit
{
    Clubs,
    Diamonds,
    Hearts,
    Spades,
};


struct Card
{
    int value{};
    Suit suit{};
};


int main()
{
    const int suitSize = 13;
    const int deckSize = suitSize * 4;
    vector<Card> cards(deckSize);
    std::cout << cards.size() << "\n";
    for (int suitNum = 0; suitNum < 4; ++suitNum)
    {
        Suit suit{};
        switch (suitNum)
        {
            case 0: suit = Suit::Clubs;    break;
            case 1: suit = Suit::Diamonds; break;
            case 2: suit = Suit::Hearts;   break;
            case 3: suit = Suit::Spades;   break;
        }
        for (int i = suitSize * suitNum; i < suitSize * (suitNum + 1); ++i)
        {
            cards[i] = Card{ (i % suitSize) + 1, suit };
        }
    }

    vector<vector<Card>> combinations{};
    size_t handSize = 3;
    vector<Card> comb(handSize);
    for (size_t min1 = 0; min1 < deckSize; ++min1)
    {
        comb[0] = cards[min1];
        for (size_t min2 = min1 + 1; min2 < deckSize; ++min2)
        {
            comb[1] = cards[min2];
            for (size_t min3 = min2 + 1; min3 < deckSize; ++min3)
            {
                comb[2] = cards[min3];
                combinations.push_back(comb);
            }
        }
    }
    std::cout << "# combinations: " << combinations.size() << "\n";
    for (const auto &comb : combinations)
    {
        for (const auto &card : comb)
        {
            char s{};
            switch (card.suit)
            {
                case Suit::Clubs:    s = 'C'; break;
                case Suit::Diamonds: s = 'D'; break;
                case Suit::Hearts:   s = 'H'; break;
                case Suit::Spades:   s = 'S'; break;
            }
            std::cout << card.value << s << ",";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}
