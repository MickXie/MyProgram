#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <map>

using namespace std;

enum pips
{
    two = 2,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king,
    ace
};
enum suit
{
    clubs,
    diamonds,
    hearts,
    spades
};

struct card
{
    pips p;
    suit s;
};

// 初始化一副52張牌
void init_deck(vector<card> &deck)
{
    deck.clear();
    for (int s = clubs; s <= spades; ++s)
    {
        for (int p = two; p <= ace; ++p)
        {
            deck.push_back(card{static_cast<pips>(p), static_cast<suit>(s)});
        }
    }
}

// 判斷是否為 Flush（同花）
bool is_flush(vector<card> &hand)
{
    suit first_suit = hand[0].s;
    for (auto &c : hand)
    {
        if (c.s != first_suit)
            return false;
    }
    return true;
}

// 判斷是否為 Straight（順子）
bool is_straight(vector<card> &hand)
{
    vector<int> values;
    for (auto &c : hand)
        values.push_back(c.p);
    sort(values.begin(), values.end());
    for (int i = 1; i < values.size(); ++i)
    {
        if (values[i] != values[i - 1] + 1)
            return false;
    }
    return true;
}

// 判斷是否為 Straight Flush（同花順）
bool is_straight_flush(vector<card> &hand)
{
    return is_flush(hand) && is_straight(hand);
}

// 配對統計某張數出現次數是否為 n
bool pairing(vector<card> &hand, int n)
{
    map<int, int> counter;
    for (auto &c : hand)
        counter[c.p]++;
    for (auto &kv : counter)
    {
        if (kv.second == n)
            return true;
    }
    return false;
}

// 判斷是否為 Four of a Kind（四條）
bool is_four_kind(vector<card> &hand)
{
    return pairing(hand, 4);
}

// 判斷是否為 Three of a Kind（三條）
bool is_three_kind(vector<card> &hand)
{
    return pairing(hand, 3);
}

// 判斷是否為 One Pair（一對）
bool is_one_pair(vector<card> &hand)
{
    map<int, int> counter;
    int pairs = 0;
    for (auto &c : hand)
        counter[c.p]++;
    for (auto &kv : counter)
    {
        if (kv.second == 2)
            pairs++;
    }
    return pairs == 1;
}

// 判斷是否為 Two Pair（兩對）
bool is_two_pair(vector<card> &hand)
{
    map<int, int> counter;
    int pairs = 0;
    for (auto &c : hand)
        counter[c.p]++;
    for (auto &kv : counter)
    {
        if (kv.second == 2)
            pairs++;
    }
    return pairs == 2;
}

// ✅ 判斷是否為 Full House（葫蘆）
bool is_full_house(vector<card> &hand)
{
    map<int, int> counter;
    for (auto &c : hand)
        counter[c.p]++;

    bool has_three = false, has_two = false;
    for (auto &kv : counter)
    {
        if (kv.second == 3)
            has_three = true;
        else if (kv.second == 2)
            has_two = true;
    }

    return has_three && has_two;
}

// 主程式：模擬1000次發牌
int main()
{
    srand(time(0));
    vector<card> deck;
    init_deck(deck);

    int flush_count = 0;
    int straight_count = 0;
    int straight_flush_count = 0;
    int fullhouse_count = 0;

    for (int i = 0; i < 1000; ++i)
    {
        random_shuffle(deck.begin(), deck.end());
        vector<card> hand(deck.begin(), deck.begin() + 5);

        if (is_flush(hand))
            flush_count++;
        if (is_straight(hand))
            straight_count++;
        if (is_straight_flush(hand))
            straight_flush_count++;
        if (is_full_house(hand))
            fullhouse_count++;
    }

    cout << "Flushes: " << flush_count << " out of 1000" << endl;
    cout << "Straights: " << straight_count << " out of 1000" << endl;
    cout << "Straight Flushes: " << straight_flush_count << " out of 1000" << endl;
    cout << "Fullhouses: " << fullhouse_count << " out of 1000" << endl;

    return 0;
}
