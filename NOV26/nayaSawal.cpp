#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int x;
        cin >> x;
        int y = 2;
        int ans = 0;

        while (x > 0)
        {
            int p = 1;
            while (p * y <= x)
            {
                p *= y;
            }
            x -= p;
            ans++;
        }
        cout << ans << endl;
    }

    return 0;
}