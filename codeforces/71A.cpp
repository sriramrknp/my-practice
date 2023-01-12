#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        int sze = s.size();
        if (sze > 10)
            cout << (s[0] + to_string(sze - 2) + s[sze - 1]);
        else
            cout << s;
    }
}