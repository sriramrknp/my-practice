#include<bits/stdc++.h>
using namespace std;

string append_p(string s, string t, string p, char vai, int in, int travs)
{
    // if(in >= s.size())
    // {
    //     reverse(t.begin(), t.end());
    //     p += t;
    //     return p;
    // }
    int i;
    for (i = travs; i < s.size(); i++)
    {
        if (s[i] == vai)
        {
            if (t.empty())
            {
                p += s[i];
                travs = i + 1;
                in = i + 1;
            }
            else
            {
                if (s[i] < t[t.size() - 1])
                {
                    p += s[i];
                    travs = i + 1;
                    in = i + 1;
                }
                else
                {
                    p += t[t.size() - 1];
                    t.erase(t.begin() + t.size() - 1);
                    travs = i;
                    in = i;
                }
            }
            break;
        }
        else
        {
            t += s[i];
        }
    }

    if (travs >= s.size())
    {
        reverse(t.begin(), t.end());
        p += t;
        return p;
    }

    char temp = '{';
    for (int j = in; j < s.size(); j++)
    {
        if (s[j] >= vai && s[j] < temp)
        {
            temp = s[j];
            in = j;
        }
    }
    vai = temp;
    if (!t.empty())
    {
        while (t[t.size() - 1] <= temp)
        {
            p += t[t.size() - 1];
            t.erase(t.begin() + t.size() - 1);
            if (t.empty())
                break;
        }
    }

    return append_p(s, t, p, vai, in, travs);
}
    string robotWithString(string s)
    {
        string t = "", p = "";
        int ind, in = 0, travs = 0;
        char vai = '{';

        for (auto i : s)
        {
            if (i < vai)
                vai = i;
        }

        return append_p(s, t, p, vai, in, travs);
    }

    int main()
    {
        string s;
        cin >> s;
        cout<<robotWithString(s);
    }