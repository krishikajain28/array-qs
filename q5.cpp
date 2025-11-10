#include <bits/stdc++.h>
using namespace std;

// q1.1 Buy and sell stock
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

int buyAndSellStocks1B(vector<int> &a)
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

int buyAndSellStocks1O(vector<int> &a)

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

// q1.2
// same q but here u r allowed to buy and sell stocks as many times as u want
// whihc means if array is: {7 1 5 3 6 4}
// u have to collect maxprofit of it
// but rule one more added
// you buy buy buy and then sel sell sell
// u hvtohbuy sell buy sell and like that

int buyAndSellStocks2B(vector<int> &a)
{
    n = a.size();

    for (int i = 0; i < n; i++)
    {
        if (a[i] > a[i + 1])
        {
        }
    }
}

int main()
{
    vector<int> a = {1, 1, 1, 1, 1, 1, 1, 10};

    int m = buyAndSellStocksO(a);

    cout << "The ans : " << m;
}
