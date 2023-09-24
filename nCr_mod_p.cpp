#define ll long long

ll myPow(ll x, int y, int p) {
    ll ans = 1; 
 
    x = x % p;
 
    while (y > 0) {
        if (y & 1) ans = (ans * x) % p;
 
        y = y >> 1;
        x = (x * x) % p;
    }
    return ans;
}
 
ll modInverse(ll n, int p) {
    return myPow(n, p - 2, p);
}
 
ll nCrModPFermat(ll n, int r, int p) {
    if (n < r)
        return 0;
    if (r == 0)
        return 1;

    ll fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
 
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}

