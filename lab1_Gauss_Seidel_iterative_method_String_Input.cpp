#include <bits/stdc++.h>
using namespace std;
int sss(string s, int i, int j)
{
    int a = 0, f = 0;
    if (s[i] == '-')
    {
        f = 1;
        i++;
    }
    if (s[i] == '+')
    {
        f = 0;
        i++;
    }
    if (s[i] == '=')
    {
        i++;
        if (s[i] == '-')
        {
            f = 1;
            i++;
        }
        if (s[i] == '+')
        {
            f = 0;
            i++;
        }
    }

    for (; i < j; i++)
    {
        a *= 10;
        a += (s[i] - '0');
    }
    if (f)
        return (a * (-1));
    else
        return a;
}
void num(string s, int &a, int &b, int &c, int &d)
{
    int i = 0, j;
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    for (j = 0; j < s.size(); j++)
    {
        if (s[j] == 'x')
        {
            a = sss(s, i, j);
            i = j + 1;
            j++;
            break;
        }
    }
    for (; j < s.size(); j++)
    {
        if (s[j] == 'y')
        {
            b = sss(s, i, j);
            i = j + 1;
            j++;
            break;
        }
    }
    for (; j < s.size(); j++)
    {
        if (s[j] == 'z')
        {
            c = sss(s, i, j);
            i = j + 1;
            j++;
            break;
        }
    }
    for (; j < s.size(); j++)
    {
        if (s[j] == 'u')
        {
            d = sss(s, i, j);
            i = j + 1;
            j++;
            break;
        }
    }
}
int main()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int tt = 0;
    s1.push_back('u');
    s2.push_back('u');
    s3.push_back('u');
    int a1, b1, c1, d1, a2, b2, c2, d2, a3, b3, c3, d3;
    num(s1, a1, b1, c1, d1);
    num(s2, a2, b2, c2, d2);
    num(s3, a3, b3, c3, d3);
    // cin>>a1>>b1>>c1>>d1>>a2>>b2>>c2>>d2>>a3>>b3>>c3>>d3;
    double x = 9, x1 = 0, y = 9, y1 = 0, z = 9, z1 = 0;
    while (abs(x - x1) > 0.0001 || abs(y - y1) > 0.0001 || abs(z - z1) > 0.0001)
    {
        tt++;
        x = x1;
        y = y1;
        z = z1;
        x1 = (d1 - b1 * y - c1 * z) / a1;
        y1 = (d2 - a2 * x - c2 * z) / b2;
        z1 = (d3 - a3 * x - b3 * y) / c3;
    }
    cout << x1 << ' ' << y1 << ' ' << z1 << ' ' << tt << endl;
    // cout<<"hhh";
    return 0;
}
