#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (eating_time(piles, mid) > h)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }

    int eating_time(vector<int>& piles, int k)
    {
        int time = 0;
        for (int i = 0; i < piles.size(); ++i)
            time += piles[i] / k + (piles[i] % k ? 1 : 0);
        return time;
    }
};