class Combinatorics
{
public:
    typedef long long ll;
    const int M = 1e9 + 7;
    const int N = 3005;
    vector<ll> fact, invFact;

    ll mod(ll x) { return ((x % M + M) % M); }
    ll add(ll a, ll b) { return mod(a + b); }
    ll mul(ll a, ll b) { return mod(a * b); }

    ll modPow(ll a, ll b)
    {
        ll ans = 1;
        while (b)
        {
            if (b & 1)
                ans = mul(ans, a);
            a = mul(a, a);
            b >>= 1;
        }
        return ans;
    }

    ll inv(ll x) { return modPow(x, M - 2); }
    ll modSub(ll a, ll b) { return mod(a - b); }
    ll modDiv(ll a, ll b) { return mul(a, inv(b)); }

    Combinatorics()
    {
        fact.resize(N, 1);
        invFact.resize(N, 1);
        precalc();
    }

    void precalc()
    {
        for (int i = 1; i < N; i++)
            fact[i] = mul(fact[i - 1], i);

        invFact[N - 1] = inv(fact[N - 1]);
        for (int i = N - 2; i >= 0; i--)
            invFact[i] = mul(invFact[i + 1], i + 1);
    }

    ll nCr(ll n, ll r)
    {
        if (r > n || r < 0)
            return 0;
        return mul(fact[n], mul(invFact[r], invFact[n - r]));
    }

    ll nPr(ll n, ll r)
    {
        if (r > n || r < 0)
            return 0;
        return mul(fact[n], invFact[n - r]);
    }

    ll factorial(ll r)
    {
        if (r < 0)
            return 0;
        return fact[r];
    }

    ll inverse_factorial(ll r)
    {
        if (r < 0)
            return 0;
        return invFact[r];
    }

    ll find_rank(const string &s)
    {
        int n = s.size();
        vector<int> freq(26, 0);
        
        for (char c : s) freq[c - 'a']++;
        
        ll rank = 1;
        
        for (int i = 0; i < n; i++)
        {
            for (char ch = 'a'; ch < s[i]; ch++)
            {
                int idx = ch - 'a';
                if (freq[idx] == 0) continue;
                
                freq[idx]--;
                
                ll numerator = factorial(n - i - 1);
                ll denominator = 1;
                
                for (int c = 0; c < 26; c++)
                {
                    if (freq[c] > 0)
                        denominator = mul(denominator, factorial(freq[c]));
                }
                
                ll contribution = modDiv(numerator, denominator);
                rank = add(rank, contribution);
                
                freq[idx]++;
            }
            
            freq[s[i] - 'a']--;
        }
        
        return rank;
    }
};

class Solution {
public:
    int MOD = 1e9+7;
    int makeStringSorted(string s) {
        Combinatorics comb; 
        long long rank = comb.find_rank(s);  
        long long ans = (rank - 1) % MOD;
        return ans;
    }
};