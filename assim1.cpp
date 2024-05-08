#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    cout << "ENTER THE STRING : ";
    cin >> s;

    cout << "XOR" << endl;

    // cout << (char)127 << endl;

    for (auto it : s)
    {
        cout << (char)(it ^ 127) << endl;
    }

    cout << endl;

    cout << "AND" << endl;

    for (auto it : s)
    {
        cout << (char)(it & 127) << endl;
    }

    cout << endl;

    cout << "OR" << endl;

    for (auto it : s)
    {
        cout << (char)(it | 127) << endl;
    }

    cout << endl;
}