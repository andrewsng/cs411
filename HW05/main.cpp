#include <iostream>
using std::cout;
#include <vector>
using std::vector;


int main()
{
    size_t deckSize = 5;
    vector<int> cards(deckSize);
    std::cout << cards.size() << "\n";
    for (size_t i = 0; i < cards.size(); ++i)
    {
        cards[i] = i + 1;
    }

    vector<vector<int>> combinations{};
    size_t handSize = 3;
    vector<int> comb(handSize);
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
    for (const auto &comb : combinations)
    {
        for (const auto &card : comb)
        {
            std::cout << card;
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}
