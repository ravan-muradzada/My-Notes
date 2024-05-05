#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll a, b, c;
    cin >> a >> b >> c;
    ll n = b - a;
    vector<ll> dp(n);
    
    if ((a + 1) % c == 0){
        dp[0] = 0;
        dp[1] = 1;
    }else if ((a + 2) % c == 0){
        dp[0] = 1;
        dp[1] = 0;
    }else{
        dp[0] = dp[1] = 1;
    }
    
    
    for (ll i = 2; i < n; ++i){
        if (i % c == 0){
            dp[i] = 0;
        }else if ((i - 1) % c == 0){
            dp[i] = dp[i - 2] + 1;
        }else if ((i - 2) % c == 0){
            dp[i] = dp[i - 1] + 1;
        }else{
            dp[i] = min(dp[i - 1], dp[i - 2]) + 1;
        }
    }

    cout << dp.back();
    
    
    
    
    return 0;
}
