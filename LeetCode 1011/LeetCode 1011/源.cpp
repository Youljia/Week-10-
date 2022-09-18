#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (ship_days(weights, mid) > days)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
    int ship_days(vector<int>& weights, int x)
    {
        int days = 0;
        int cur = 0;
        for (int i = 0; i < weights.size(); ++i)
        {
            if (cur + weights[i] <= x)
                cur += weights[i];
            else
            {
                days++;
                cur = weights[i];
            }
        }
        days++;
        return days;
    }
};

int main()
{
    vector<int> v{ 1,2,3,1,1 };
    Solution s;
    cout << s.shipWithinDays(v, 4) << endl;
    return 0;
}