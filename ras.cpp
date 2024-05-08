#include <bits/stdc++.h>
using namespace std;
#define double long double

int main()
{
    double p = 13, q = 29;
    double n = p * q, phi = (p - 1) * (q - 1);

    double e = 2;

    while (e < phi)
    {
        int temp = __gcd((int)e, (int)phi);
        if (temp != 1)
            e++;
        else
            break;
    }
    cout << e << endl;

    double einverse = 1 / e;

    double d = fmod(einverse, phi);

    // cout<<enc<<" "<<dec;
    string s;
    getline(cin, s);

    // cin>>s;

    string ec = "", de = "";

    for (auto it : s)
    {
        double mess1 = (int)it;

        double enc = pow(mess1, e);

        double dec = pow(enc, d);
        enc = fmod(enc, n);
        dec = fmod(dec, n);

        ec += (char)enc;
        de += (char)dec;
    }

    cout << ec << " " << de;
}