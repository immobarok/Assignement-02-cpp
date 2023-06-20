#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{


    /* Output check
    20
    10
    8
    2 4 5 8 12 14 16 19
    ------------------------------
    25
    10
    5
    2 4 5 8 12  
     */
    int d, m, n;
    cout << "Enter input:" << endl;
    cin >> d >> m >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    int dis = 0;
    int cur = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <=d)
        {
            dis += a[i] - cur;
            cur = a[i];
            if (dis > m)
            {
                cout << "stop at gas station " << i << "( " << a[i - 1] << " miles )" << endl;
                dis = 0;
                i--;
                cur = a[i];
            }
        }
    }
}
