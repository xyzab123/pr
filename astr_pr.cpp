#include <bits/stdc++.h>
using namespace std;
bool flag = 0;
const int n = 3;
map<vector<vector<int>>, bool> mp;
int diff(vector<vector<int>> initial, vector<vector<int>> final)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (initial[i][j] != final[i][j])
                cnt++;
        }
    }
    return cnt;
}

void print(vector<vector<int>> state)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << state[i][j] << " ";
        }
        cout << endl;
    }
}

void astar(vector<vector<int>> initial, vector<vector<int>> final, int height)
{
    vector<pair<int, vector<vector<int>>>> all;
    // print(initial);
    if (flag)
        return;
    if (diff(initial, final) == 0)
    {
        flag = 1;
        cout << endl
             << height << endl;
        return;
    }
    int ii = 0, jj = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (initial[i][j] == 0)
            {
                ii = i, jj = j;
                break;
            }
        }
    }

    if (ii - 1 >= 0)
    {
        swap(initial[ii][jj], initial[ii - 1][jj]);
        if (mp.count(initial) == 0)
        {
            mp[initial] = 1;
            all.push_back({diff(initial, final) + height, initial});
        }
        swap(initial[ii][jj], initial[ii - 1][jj]);
    }
    if (jj - 1 >= 0)
    {
        swap(initial[ii][jj], initial[ii][jj - 1]);
        if (mp.count(initial) == 0)
        {
            mp[initial] = 1;
            all.push_back({diff(initial, final) + height, initial});
        }
        swap(initial[ii][jj], initial[ii][jj - 1]);
    }
    if (ii + 1 < n)
    {
        swap(initial[ii][jj], initial[ii + 1][jj]);
        if (mp.count(initial) == 0)
        {
            mp[initial] = 1;
            all.push_back({diff(initial, final) + height, initial});
        }
        swap(initial[ii][jj], initial[ii + 1][jj]);
    }
    if (jj + 1 < n)
    {
        swap(initial[ii][jj], initial[ii][jj + 1]);
        if (mp.count(initial) == 0)
        {
            mp[initial] = 1;
            all.push_back({diff(initial, final) + height, initial});
        }
        swap(initial[ii][jj], initial[ii][jj + 1]);
    }

    sort(all.begin(), all.end());
    cout << endl;
    print(all[0].second);
    cout << "h=" << all[0].first << "   g=" << height + 1 << "  f=" << all[0].first + height + 1;
    cout << endl;
    for (auto it : all)
    {
        astar(it.second, final, height + 1);
    }
}

int main()
{
    vector<vector<int>> initial = {{1, 0, 2}, {3, 4, 5}, {6, 7, 8}};
    vector<vector<int>> final = {{1, 4, 2}, {3, 7, 5}, {6, 8, 0}};
    astar(initial, final, 0);
}