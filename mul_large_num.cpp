#include<bits/stdc++.h>
using namespace std;
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        if(num1.size() > num2.size())
        {
            string temp;
            temp = num2;
            num2 = num1;
            num1 = temp;
        }
        int bal = 0, j=num1.size() - 1;
        int mul1, mul2;
        string ans = "";
        int sze = 500;
        vector<vector<int> > v(sze, vector<int>(sze,0));
        
        int ind = sze-1, ind1 = 0;
        int large=0;

        while(j >= 0){
            mul1 = (int)(num1[j] - '0');
            for(int i=(num2.size()-1);i >= 0;i--)
            {
                mul2 = (int)(num2[i] - '0');
                int mul = (mul1*mul2) + bal;
                if(i == 0)
                {
                    v[ind1][ind] = mul%10;
                    ind--;
                    v[ind1][ind] = mul/10;
                    bal = 0;
                }
                else if((mul/10) == 0)
                {
                    v[ind1][ind] = mul%10;
                    bal = 0;
                }
                else{
                    bal = mul/10;
                    v[ind1][ind] = mul%10;
                }
                ind--;
            }
            large = ind;
            bal = 0;
            ind1++;
            ind = sze - ind1 - 1;
            bal = 0;
            j--;
        }
        bal = 0;
        ind = 0;
        int ind2 = 0;
        
        vector<int> v1;
        for (int i = sze - 1; i > (large); i--)
        {
            int temp=0;
            for (int j = sze - 1; j >= 0; j--)
            {
                temp += v[j][i];
            }
            temp += bal;
            int mul = temp;
            bal = mul/10;
            v1.push_back(mul%10);
            ind++;
        }
        for (auto i : v1)
            ans += to_string(i);
        return ans;
    }


    int main()
    {
        string num1, num2;
        num1 = "54";
        num2 = "11";
        string ans;
        ans = multiply(num1, num2);
        reverse(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        if (ans[0] == '0')
        {
            for (int i = 0; i < ans.size();i++)
            {
                if (ans[i] != '0'){
                    for (int j = i; j < ans.size();j++)
                    {
                        cout << ans[j];
                    }
                    cout << '\n';
                    break;
                }
            }
        }
        else{
            for (int i = 0; i < ans.size(); i++)
            {
                if (ans[i] != '0')
                {
                    for (int j = i; j < ans.size(); j++)
                    {
                        cout << ans[j];
                    }
                    cout << '\n';
                    break;
                }
            }
        }
    }