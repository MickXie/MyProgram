/******************************************************************************

UCSC C++ For C Programmers, Part B
https://www.coursera.org/learn/c-plus-plus-b/lecture/dqNKI/1-5-example-poker-probability

*******************************************************************************/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
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
    pips(int val) : v(val) { assert(v > 0 && v < 14); } // 點數
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
    os << "pips: " << c.v << ", suit: " << c.s << endl;
    return os;
}

void init_deck(vector<card> &d)
{
    int i;
    for (i = 1; i < 14; i++)
    {
        card c(suit::SPADE, i);
        d[i - 1] = c;
        // cout << i << " ";
    }
    // cout << endl;
    for (i = 1; i < 14; i++)
    {
        card c(suit::HEART, i);
        d[i + 12] = c;
        // cout << i << " ";
    }
    // cout << endl;
    for (i = 1; i < 14; i++)
    {
        card c(suit::DIAMOND, i);
        d[i + 25] = c;
        // cout << i << " ";
    }
    // cout << endl;
    for (i = 1; i < 14; i++)
    {
        card c(suit::CLUB, i);
        d[i + 38] = c;
        // cout << i << " ";
    }
    // cout << endl;
}

void print(vector<card> &deck)
{
    for (auto p = deck.begin(); p != deck.end(); ++p)
    { // for (auto card_val: deck) cout << card_val
        cout << *p;
    }
    cout << endl;
}

bool is_flush(vector<card> &hand)
{
    suit s = hand[0].get_suit();
    for (auto p = hand.begin(); p != hand.end(); ++p)
    {
        if (s != p->get_suit())
        {
            return false;
        }
    }
    return true;
}

bool is_straight(vector<card> &hand)
{
    sort(hand.begin(), hand.end(), [](const card &a, const card &b)
         { return (a.get_pips()).get_pips() < (b.get_pips()).get_pips(); });
    // cin >> seed;
    // print(hand);

    int pips_v[5];
    int i = 0;
    for (auto p = hand.begin(); p != hand.end(); ++p)
    {
        pips_v[i++] = (p->get_pips()).get_pips();
    }
    // sort(pips_v, pips_v+5);
    if (pips_v[0] != 1)
    { // not ACE
        return (pips_v[0] == pips_v[1] - 1 && pips_v[1] == pips_v[2] - 1) && (pips_v[2] == pips_v[3] - 1 && pips_v[3] == pips_v[4] - 1);
    }
    else
    {
        return (pips_v[0] == pips_v[1] - 1 && pips_v[1] == pips_v[2] - 1) && (pips_v[2] == pips_v[3] - 1 && pips_v[3] == pips_v[4] - 1) || (pips_v[1] == 10) && (pips_v[2] == 11) && (pips_v[3] == 12) && (pips_v[4] == 13);
    }
}

bool is_straight_flush(vector<card> &hand)
{
    return is_flush(hand) && is_straight(hand);
}

int pairing(vector<card> &hand, int t)
{
    map<int, int> deck;
    // int deck[13] = {};
    for (const auto &it : hand)
    {
        deck[static_cast<int>(it.get_pips().get_pips()) - 1]++;
    }
    int cnt = 0;
    for (auto it : deck)
    {
        if (it.second == t)
        {
            cnt++;
        }
    }
    return cnt;
}

bool is_full_house(vector<card> &hand)
{
    return pairing(hand, 3) && pairing(hand, 2);
}

bool is_four_kind(vector<card> &hand)
{
    return pairing(hand, 4);
}

bool is_three_kind(vector<card> &hand)
{
    return pairing(hand, 3);
}

bool is_one_pair(vector<card> &hand)
{
    return pairing(hand, 2);
}

bool is_two_pair(vector<card> &hand)
{
    return pairing(hand, 2) == 2;
}

int main()
{
    int flush_count = 0;
    int str_count = 0;
    int str_flush_count = 0;
    int full_house_count = 0;
    int four_kind_count = 0;
    int three_kind_count = 0;
    int one_pair_couut = 0;
    int two_pair_couut = 0;

    int num_shuffles = 10000;
    ;
    int seed = 10;
    cout << "How many shuffles? ";
    cin >> num_shuffles;
    cout << "set the seed ";
    cin >> seed;
    vector<card> deck(52);
    srand(seed);
    init_deck(deck);
    for (int loop = 0; loop < num_shuffles; ++loop)
    {
        random_shuffle(deck.begin(), deck.end()); // STL algorithm again!
        vector<card> hand(5);
        int i = 0;
        for (auto p = deck.begin(); i < 5; ++p)
        {
            hand[i++] = *p;
        }

        if (is_flush(hand))
        {
            flush_count++;
        }
        if (is_straight(hand))
        {
            str_count++;
        }
        if (is_straight_flush(hand))
        {
            str_flush_count++;
        }
        if (is_full_house(hand))
        {
            full_house_count++;
        }
        if (is_four_kind(hand))
        {
            four_kind_count++;
        }
        if (is_three_kind(hand))
        {
            three_kind_count++;
        }
        if (is_one_pair(hand))
        {
            one_pair_couut++;
        }
        if (is_two_pair(hand))
        {
            two_pair_couut++;
        }
    }

    cout << "\nStraight Flushes: " << str_flush_count << " out of " << num_shuffles << endl;
    cout << "Four of a Kind: " << four_kind_count << " out of " << num_shuffles << endl;
    cout << "Full House: " << full_house_count << " out of " << num_shuffles << endl;
    cout << "Flushes: " << flush_count << " out of " << num_shuffles << endl;
    cout << "Straights: " << str_count << " out of " << num_shuffles << endl;
    cout << "Three of a kind: " << three_kind_count << " out of " << num_shuffles << endl;
    cout << "Two Pair: " << two_pair_couut << " out of " << num_shuffles << endl;
    cout << "One Pair: " << one_pair_couut << " out of " << num_shuffles << endl;

    return 0;
}
