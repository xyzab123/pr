#include <bits/stdc++.h>
using namespace std;

void df(string s, string key)
{
    vector<string> v;
    int ii = 0;
    string temp = "";
    for (auto it : s)
    {
        ii++;
        temp += it;

        if (ii == key.size())
        {
            v.push_back(temp);
            temp = "";
            ii = 0;
        }
    }
    if (temp != "")
        v.push_back(temp);

    vector<pair<char, int>> vp;
    for (int i = 0; i < key.size(); i++)
    {
        vp.push_back({key[i], i});
    }

    sort(vp.begin(), vp.end());

    string ans = "";
    int k = 0;

    for (auto i = 0; i < v.size(); i++)
    {
        string temp = key;
        int j = 0;
        for (auto itt : vp)
        {
            temp[itt.second] = v[i][j];
            j++;
        }

        for (auto it : temp)
        {
            if (it != '#')
                ans += it;
        }
    }

    cout << "DECRYPTED TEXT : " << ans << endl;
}

void f(string s, string key)
{

    vector<string> v;
    int ii = 0;
    string temp = "";
    for (auto it : s)
    {
        ii++;
        temp += it;

        if (ii == key.size())
        {
            v.push_back(temp);
            temp = "";
            ii = 0;
        }
    }
    if (temp != "")
        v.push_back(temp);

    vector<pair<char, int>> vp;
    for (int i = 0; i < key.size(); i++)
    {
        vp.push_back({key[i], i});
    }

    sort(vp.begin(), vp.end());

    string ans = "";

    for (auto it : v)
    {
        for (auto itt : vp)
        {
            if (it.size() > itt.second)
                ans += it[itt.second];
            else
            {
                ans += '#';
            }
        }
    }

    cout << "ENCRYPTED TEXT : " << ans << endl;

    df(ans, key);
}

int main()
{
    string s, key;

    cout << "ENTER THE STRING : ";
    cin >> s;

    cout << "ENTER THE KEY : ";

    cin >> key;

    f(s, key);
}