#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

enum class suit : short
{
    SPADE,
    HEART,
    DIAMOND,
    CLUB
};

class pips
{
public:
    pips(int val) : v(val) { assert(v > 0 && v < 14); }
    friend ostream &operator<<(ostream &out, const pips &p);
    int get_pips() const { return v; }

private:
    int v;
};

class card
{
public:
    card() : s(suit::SPADE), v(1) {}
    card(suit st, pips pv) : s(st), v(pv) {}
    friend ostream &operator<<(ostream &out, const card &c);
    suit get_suit() const { return s; }
    pips get_pips() const { return v; }

private:
    suit s;
    pips v;
};

ostream &operator<<(ostream &os, const suit &s)
{
    os << static_cast<std::underlying_type<suit>::type>(s);
    return os;
}

ostream &operator<<(ostream &os, const pips &p)
{
    os << p.v;
    return os;
}

ostream &operator<<(ostream &os, const card &c)
{
    os << "pips: " << c.v << ", suit: " << c.s;
    return os;
}

void init_deck(vector<card> &d)
{
    for (int i = 1; i < 14; i++)
    {
        d[i - 1] = card(suit::SPADE, i);
    }
    for (int i = 1; i < 14; i++)
    {
        d[i + 12] = card(suit::HEART, i);
    }
    for (int i = 1; i < 14; i++)
    {
        d[i + 25] = card(suit::DIAMOND, i);
    }
    for (int i = 1; i < 14; i++)
    {
        d[i + 38] = card(suit::CLUB, i);
    }
}

bool is_flush(vector<card> &hand)
{
    suit s = hand[0].get_suit();
    for (auto &c : hand)
    {
        if (s != c.get_suit())
            return false;
    }
    return true;
}

bool is_straight(vector<card> &hand)
{
    vector<int> pips;
    for (auto &c : hand)
    {
        pips.push_back(c.get_pips().get_pips());
    }
    sort(pips.begin(), pips.end());

    // 處理A-2-3-4-5的特殊情況
    if (pips == vector<int>{1, 2, 3, 4, 5})
    {
        return true;
    }

    // 檢查普通順子
    for (size_t i = 1; i < pips.size(); ++i)
    {
        if (pips[i] != pips[i - 1] + 1)
        {
            return false;
        }
    }
    return true;
}

bool is_straight_flush(vector<card> &hand)
{
    return is_flush(hand) && is_straight(hand);
}

bool is_four_of_a_kind(vector<card> &hand)
{
    vector<int> pips;
    for (auto &c : hand)
    {
        pips.push_back(c.get_pips().get_pips());
    }
    sort(pips.begin(), pips.end());

    // 檢查前四張或後四張是否相同
    return (pips[0] == pips[1] && pips[1] == pips[2] && pips[2] == pips[3]) ||
           (pips[1] == pips[2] && pips[2] == pips[3] && pips[3] == pips[4]);
}

bool is_full_house(vector<card> &hand)
{
    vector<int> pips;
    for (auto &c : hand)
    {
        pips.push_back(c.get_pips().get_pips());
    }
    sort(pips.begin(), pips.end());

    // 兩種情況：3+2或2+3
    return (pips[0] == pips[1] && pips[1] == pips[2] && pips[3] == pips[4]) ||
           (pips[0] == pips[1] && pips[2] == pips[3] && pips[3] == pips[4]);
}

bool is_three_of_a_kind(vector<card> &hand)
{
    vector<int> pips;
    for (auto &c : hand)
    {
        pips.push_back(c.get_pips().get_pips());
    }
    sort(pips.begin(), pips.end());

    // 檢查三張相同的情況
    for (int i = 0; i <= 2; ++i)
    {
        if (pips[i] == pips[i + 1] && pips[i + 1] == pips[i + 2])
        {
            // 確保不是葫蘆
            if ((i == 0 && pips[3] != pips[4]) ||
                (i == 1 && pips[0] != pips[4]) ||
                (i == 2 && pips[0] != pips[1]))
            {
                return true;
            }
        }
    }
    return false;
}

bool is_two_pair(vector<card> &hand)
{
    vector<int> pips;
    for (auto &c : hand)
    {
        pips.push_back(c.get_pips().get_pips());
    }
    sort(pips.begin(), pips.end());

    // 檢查兩對的情況
    int pair_count = 0;
    for (int i = 0; i < 4; ++i)
    {
        if (pips[i] == pips[i + 1])
        {
            pair_count++;
            i++; // 跳過下一張牌
        }
    }
    return pair_count == 2;
}

bool is_one_pair(vector<card> &hand)
{
    vector<int> pips;
    for (auto &c : hand)
    {
        pips.push_back(c.get_pips().get_pips());
    }
    sort(pips.begin(), pips.end());

    // 檢查只有一對的情況
    int pair_count = 0;
    for (int i = 0; i < 4; ++i)
    {
        if (pips[i] == pips[i + 1])
        {
            pair_count++;
            i++; // 跳過下一張牌
        }
    }
    return pair_count == 1 && !is_two_pair(hand) && !is_three_of_a_kind(hand) &&
           !is_full_house(hand) && !is_four_of_a_kind(hand);
}

string classify_hand(vector<card> &hand)
{
    if (is_straight_flush(hand))
        return "Straight Flush";
    if (is_four_of_a_kind(hand))
        return "Four of a Kind";
    if (is_full_house(hand))
        return "Full House";
    if (is_flush(hand))
        return "Flush";
    if (is_straight(hand))
        return "Straight";
    if (is_three_of_a_kind(hand))
        return "Three of a Kind";
    if (is_two_pair(hand))
        return "Two Pair";
    if (is_one_pair(hand))
        return "One Pair";
    return "High Card";
}

int main()
{
    int M, S;
    cin >> M >> S;

    srand(S); // 使用輸入的種子值

    vector<card> deck(52);
    init_deck(deck);

    // 使用map存儲各牌型計數
    map<string, int> hand_counts = {
        {"Straight Flush", 0},
        {"Four of a Kind", 0},
        {"Full House", 0},
        {"Flush", 0},
        {"Straight", 0},
        {"Three of a Kind", 0},
        {"Two Pair", 0},
        {"One Pair", 0},
        {"High Card", 0}};

    for (int i = 0; i < M; ++i)
    {
        random_shuffle(deck.begin(), deck.end());
        vector<card> hand(5);
        for (int j = 0; j < 5; ++j)
        {
            hand[j] = deck[j];
        }

        string hand_type = classify_hand(hand);
        hand_counts[hand_type]++;
    }

    // 按照指定順序輸出結果
    cout << "Straight Flush: " << hand_counts["Straight Flush"] << endl;
    cout << "Four of a Kind: " << hand_counts["Four of a Kind"] << endl;
    cout << "Full House: " << hand_counts["Full House"] << endl;
    cout << "Flush: " << hand_counts["Flush"] << endl;
    cout << "Straight: " << hand_counts["Straight"] << endl;
    cout << "Three of a Kind: " << hand_counts["Three of a Kind"] << endl;
    cout << "Two Pair: " << hand_counts["Two Pair"] << endl;
    cout << "One Pair: " << hand_counts["One Pair"] << endl;

    return 0;
}