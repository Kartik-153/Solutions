/**
 *  जय सिया राम
**/

#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define rep(i, a, n) for (int i = a; i < n; i++)
#define all(p) p.begin(), p.end()
#define double long double
#define que_max priority_queue<int>
#define print(a)          \
    for (auto x : a)      \
        cout << x << " "; \
    cout << endl;
#define print1(a)    \
    for (auto x : a) \
        cout << x.F << " " << x.S << endl;
#define mod 1000000007

string one(int num)
{
    switch (num)
    {
    case 1:
        return "One";
    case 2:
        return "Two";
    case 3:
        return "Three";
    case 4:
        return "Four";
    case 5:
        return "Five";
    case 6:
        return "Six";
    case 7:
        return "Seven";
    case 8:
        return "Eight";
    case 9:
        return "Nine";
    }
    return "";
}

string twoLessThan20(int num)
{
    switch (num)
    {
    case 10:
        return "Ten";
    case 11:
        return "Eleven";
    case 12:
        return "Twelve";
    case 13:
        return "Thirteen";
    case 14:
        return "Fourteen";
    case 15:
        return "Fifteen";
    case 16:
        return "Sixteen";
    case 17:
        return "Seventeen";
    case 18:
        return "Eighteen";
    case 19:
        return "Nineteen";
    }
    return "";
}

string ten(int num)
{
    switch (num)
    {
    case 2:
        return "Twenty";
    case 3:
        return "Thirty";
    case 4:
        return "Forty";
    case 5:
        return "Fifty";
    case 6:
        return "Sixty";
    case 7:
        return "Seventy";
    case 8:
        return "Eighty";
    case 9:
        return "Ninety";
    }
    return "";
}

string two(int num)
{
    if (num == 0)
        return "";
    else if (num < 10)
        return one(num);
    else if (num < 20)
        return twoLessThan20(num);
    else
    {
        int tenner = num / 10;
        int rest = num - tenner * 10;
        if (rest != 0)
            return ten(tenner) + " " + one(rest);
        else
            return ten(tenner);
    }
}

string three(int num)
{
    int hundred = num / 100;
    int rest = num - hundred * 100;
    string res = "";
    if (hundred * rest != 0)
        res = one(hundred) + " Hundred " + two(rest);
    else if ((hundred == 0) && (rest != 0))
        res = two(rest);
    else if ((hundred != 0) && (rest == 0))
        res = one(hundred) + " Hundred";
    return res;
}

string numberToWords(int num)
{
    if (num == 0)
        return "Zero";

    int crore = num / 10000000;
    int lakh = (num - crore * 10000000) / 100000;
    int thousand = (num - crore * 10000000 - lakh * 100000) / 1000;
    int rest = num - crore * 10000000 - lakh * 100000 - thousand * 1000;

    string result = "";
    if (crore != 0)
        result = three(crore) + " Crore";
    if (lakh != 0)
    {
        if (result.size() != 0)
            result += " ";
        result += three(lakh) + " Lakh";
    }
    if (thousand != 0)
    {
        if (result.size() != 0)
            result += " ";
        result += three(thousand) + " Thousand";
    }
    if (rest != 0)
    {
        if (result.size() != 0)
            result += " ";
        result += three(rest);
    }
    return result;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n = 0;
        cin >> n;
        cout << numberToWords(n) << endl;
    }
    return 0;
}
