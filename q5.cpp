#include <bits/stdc++.h>
using namespace std;

// q . Buy and sell stock
// dynamic programming q this is
// imagine u have an array : {1,7,4,5,6,3}
// these elements are the prices of the sotckes on each day
// the indices to these elements are the dates pointing to prices of sotckes on that day
// so basically on 1st day price of the sotck is 1rs
// on the 2nd, price is 7 rs
// and so on
// u are to buy and sell stocks on a paritcular day inorder to maximize profit
// here profit will be maximized when u buy at
// #1 u cannot sell before u buy (obvvvv gurl)
// #2 buying and selling can only be done once

int buyAndSellStocksB(vector<int> &a)
{
    int n = a.size();
    int p = 0;
    int mp = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            p = a[i] - a[j - 1];

            if (p > 0)
            {
                mp = max(p, mp);
            }
        }
    }

    return mp;

    // Time: O(n²) — brute force (fine for small n, like < 10⁴)
    // Space: O(1)
}

int buyAndSellStocksO(vector<int> &a)

{
    int n = a.size();

    int maxProfit = 0;
    int mini = a[0];

    for (int i = 1; i < n; i++)
    {
        int currSell = a[i] - mini;
        maxProfit = max(maxProfit, currSell);
        mini = min(mini, a[i]);
    }

    return maxProfit;
}

int main()
{
    vector<int> a = {1, 1, 1, 1, 1, 1, 1, 10};

    int m = buyAndSellStocksO(a);

    cout << "The ans : " << m;
}
