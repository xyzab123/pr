#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<vector<int>>> v(n + 1);

    for (int i = 0; i < m; i++)
    {
        int q, p, wt;
        cin >> p >> q >> wt;
        v[p].push_back({q, wt});
        v[q].push_back({p, wt});
    }

    set<vector<int>> st;
    st.insert({0, 1, 0});

    vector<int> dis(n + 1, INT_MAX);
    dis[1] = 0;
    while (!st.empty())
    {
        auto it = *st.begin();
        int wt = it[0];
        int p = it[1];
        int q = it[2];

        st.erase(st.begin());

        for (auto child : v[p])
        {
            if (dis[child[0]] >= child[1] + wt)
            {
                dis[child[0]] = child[1] + wt;
                st.insert({dis[child[0]], child[0], p});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << "<->" << dis[i] << " ";
    }
    cout << endl;
}