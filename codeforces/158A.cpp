#include <iostream>
#include<vector>
using namespace std;

int main()
{
    int n,k,count=0;
    cin >> n >> k;
    vector<int> v(n,0);
    for (int i = 0; i < n;i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++)
    {
        if((v[i] >= v[k-1]) && (v[i] > 0))
            count++;
    }
    cout << count;
}