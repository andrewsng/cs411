#include <iostream>
using std::cout;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <map>
using std::map;
#include <algorithm>
using std::sort;


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

    map<string, int> frequencies{};
    for (const auto &comb : combinations)
    {
        string result{};
        vector<Card> hand = comb;
        sort(hand.begin(), hand.end(), [](const Card &a, const Card &b) { return a.value < b.value; });
        const Card &c1 = hand[0];
        const Card &c2 = hand[1];
        const Card &c3 = hand[2];
        bool straight = false;
        bool flush = false;
        if (c1.suit == c2.suit && c2.suit == c3.suit)
        {
            flush = true;
        }
        if (c1.value == c2.value - 1 && c1.value == c3.value - 2)
        {
            straight = true;
        }
        if (c1.value == 1 && c2.value == 12 && c3.value == 13)
        {
            straight = true;
        }
        if (straight && flush)
        {
            result = "Straight Flush";
        }
        else if (c1.value == c2.value && c2.value == c3.value)
        {
            result = "Three of a Kind";
        }
        else if (straight)
        {
            result = "Straight";
        }
        else if (flush)
        {
            result = "Flush";
        }
        else if (c1.value == c2.value || c2.value == c3.value || c1.value == c3.value)
        {
            result = "Pair";
        }
        else
        {
            result = "High Card";
        }
        frequencies[result] += 1;
    }
    for (const auto &[k, v] : frequencies)
    {
        std::cout << k << " - " << v << "\n";
    }
}
