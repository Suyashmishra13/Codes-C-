#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
#include <bits/stdc++.h>
using std::cout;
using std::endl;
using std::pair;
using std::queue;
using std::vector;

/** @return the squared distance between 2 points */
int dist_sq(const pair<int, int> &p1, const pair<int, int> &p2)
{
    int dx = p1.first - p2.first;
    int dy = p1.second - p2.second;
    return dx * dx + dy * dy;
}

/** @return if all cows are reachable with the given power level */
bool all_reachable(int power, const vector<pair<int, int>> &cows)
{
    int start = 0;
    queue<int> frontier;
    frontier.push(start);
    vector<bool> reached(cows.size());
    reached[start] = true;
    while (!frontier.empty())
    {
        int curr = frontier.front();
        frontier.pop();
        for (int c = 0; c < cows.size(); c++)
        {
            if (!reached[c] && dist_sq(cows[curr], cows[c]) <= power)
            {
                frontier.push(c);
                reached[c] = true;
            }
        }
    }

    for (bool c : reached)
    {
        if (!c)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::ifstream read("moocast.in");
    int cow_num;
    read >> cow_num;
    vector<pair<int, int>> cows(cow_num);
    for (pair<int, int> &c : cows)
    {
        read >> c.first >> c.second;
    }

    // Binary search to find the minimum power level needed
    int lo = 0;
    int hi = INT_MAX;
    int valid = -1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (all_reachable(mid, cows))
        {
            valid = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    std::ofstream("moocast.out") << valid << endl;
}