map<string, int> mp;

int Solution::isScramble(const string a, const string b)
{
    string key = a + " " + b;

    if (mp.find(key) != mp.end())
        return mp[key];

    if (a == b)
        return true;

    if (a.length() <= 1)
        return false;

    int n = a.length();

    for (int i = 1; i <= n - 1; i++)
    {
        string A1 = a.substr(0, i);
        string A2 = a.substr(i, n - i);
        string B11 = b.substr(0, i);
        string B12 = b.substr(i, n - i);
        string B21 = b.substr(0, n - i);
        string B22 = b.substr(n - i, i);

        int cont1 = mp[A1 + " " + B11] = (mp.find(A1 + " " + B11) != mp.end() ? mp[A1 + " " + B11] : isScramble(A1, B11));
        int cont2 = mp[A2 + " " + B12] = (mp.find(A2 + " " + B12) != mp.end() ? mp[A2 + " " + B12] : isScramble(A2, B12));
        int cont3 = mp[A1 + " " + B22] = (mp.find(A1 + " " + B22) != mp.end() ? mp[A1 + " " + B22] : isScramble(A1, B22));
        int cont4 = mp[A2 + " " + B21] = (mp.find(A2 + " " + B21) != mp.end() ? mp[A2 + " " + B21] : isScramble(A2, B21));
        if (
            (cont1 && cont2) ||
            (cont3 && cont4))
        {
            return mp[key] = true;
        }
    }
    return mp[key] = false;
}