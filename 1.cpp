#include <bits/stdc++.h>
using namespace std;

struct Item
{
    string id;
    double v;
    double w;
    double perKgV;
};

bool comp(Item i1, Item i2)
{


    if (i1.perKgV > i2.perKgV)
    {

        return true;
    }
    else
    {

        return false;
    }
}

/* 
4 
silver-dust 300 4
gold-dust 2000 8
salt 80 10
sugar 89 10
2 
15 15
------------------------------------

4
silver-dust 300 4
gold-dust 2000 8
salt 80 10
sugar 89 10
4
8 10 6 10
 */

double fractional_knapsack(
    Item items[], int n, double W)
{
    sort(items, items + n, comp);

    double res = 0;
    for (int i = 0; i < n; i++)
    {
        if (W > 0 && items[i].w > 0)
        {

            if (items[i].w <= W)
            {
                cout << "Taking " << items[i].id << ":  " << items[i].w << "kg " << items[i].perKgV * items[i].w << " taka" << endl;
                res += items[i].perKgV * items[i].w;
                W -= items[i].w;
                items[i].w = 0;
            }
            else
            {

                int rem = W;

                res += rem * items[i].perKgV;
                cout << "Taking " << items[i].id << ":  " << rem << "kg " << rem * items[i].perKgV << " taka" << endl;
                items[i].w -= W;
                W = 0;
            }
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    Item items[n];
    double v, w;

    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        cin >> v >> w;
        double div = v / w;
        Item item;
        item.perKgV = div;
        item.v = v;
        item.w = w;
        item.id = name;

        items[i] = item;
    }

    int k;
    cin >> k;
    double W[k];
    int cnt = 0;

    for (int i = 0; i < k; i++)
    {
        cin >> W[i];
        double profit = fractional_knapsack(items, n, W[i]);
        cout << "Thief " << i + 1 << "  profit: " << profit << " taka" << endl << endl;
        if (profit > 0)
        {
            cnt++;
        }
    }
    cout << "Total " << cnt << " thieves stole from the warehouse." << endl;

    cout << endl;
    if (items[n - 1].w > 0)
    {

        cout << "Still following items are left" << endl;

        for (int i = 0; i < n; i++)
        {
            if (items[i].w > 0)
            {

                cout << items[i].id << ":  " << items[i].w << "kg " << items[i].w * items[i].perKgV << " taka" << endl;
            }
        }
        cout << endl;
    }
}
