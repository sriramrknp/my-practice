#include<bits/stdc++.h>
using namespace std;

vector<int> func(vector<int> data, int x)
{
    vector<vector<int> > inter;
    vector<int> temp;
    bool first = true;
    cout << "ans";
    for (int i = 0; i <= (data.size() - 1); i++)
    {
        if (abs(data[i] - data[i + 1]) <= x)
        {
            temp.push_back(data[i]);
            first = false;
        }
        else{
            if(temp.size() > 0)
                temp.push_back(data[i]);
            if(temp.size() > 0){
                inter.push_back(temp);
                i--;
            }
            temp.clear();
        }
    }

    int max = -1;
    int ind = 0;
    for (int i = 0; i < inter.size(); i++)
    {
        if(inter[i].size() > max)
        {
            max = inter[i].size();
            ind = i;
        }
    }
    cout << "ans";
    vector<int> ans;
    for (int i = 0; i < inter[ind].size(); i++)
    {
        ans.push_back(inter[ind][i]);
    }
    return ans;
}

int main()
{
    vector<int> data;
    data.push_back(8);
    data.push_back(1);
    data.push_back(3);
    data.push_back(11);
    data.push_back(5);
    data.push_back(18);
    data.push_back(18);
    data.push_back(1);
    data.push_back(14);
    data.push_back(11);
    // data.push_back(2);
    // data.push_back(2);
    // data.push_back(2);

    int x;
    cin >> x;
    vector<int> ans;
   
    ans = func(data, x);
    cout << "Final \n";
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << '\n';
}



