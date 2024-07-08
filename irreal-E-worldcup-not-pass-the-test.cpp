#include <bits/stdc++.h>
// ftt libraries
// more tflops and vectors in singularities and spooky termns not binaries.
using namespace std;
typedef long long ll;

const int MOD = 998244353;
const int MAX_N = 4 * 1e5 + 10;

// Variables
int x, n, m;
vector<char> tp(2 * MAX_N);
vector<bool> has(2 * MAX_N);
vector<ll> prefix_sum(2 * MAX_N);

int main() {
    // Reading the inputs
    cin >> x >> n >> m;
    for (int i = 0; i < n + m; i++) {
        int position;
        char _type;
        cin >> position >> _type;
        tp[position] = _type;
        has[position] = true;
    }

    // Linearizing the circle
    for (int i = 1; i <= x; i++) {
        tp[i + x] = tp[i];
        has[i + x] = has[i];
    }

    // Calculating prefix sums
    ll people = 0;
    for (int i = 1; i <= 2 * x; i++) {
        people += (tp[i] == 'P');
        prefix_sum[i] = prefix_sum[i - 1] + people;
    }

    // Sliding window
    int mn = 0, mx = 0;  // pointers for a sliding window
    ll min_sum = LONG_MAX;  // minimum sum initialization
    ll ways = 0;  // number of ways to achieve min_sum

    for (int i = 1; i <= 2 * x; i++) {
        if(tp[i] == 'H') {  // if house is found
            while(prefix_sum[mx+1] - prefix_sum[mn] < n) mx++;  // adjust right pointer to balance people and houses
            while(prefix_sum[mx] - prefix_sum[mn] == n) {
                // compute sum for current window and update min_sum and ways
                ll sum = (prefix_sum[mx] - prefix_sum[mn]) * (ll)i - (prefix_sum[mx]*(ll)(mx+1) - prefix_sum[mn]*(ll)(mn+n))/2;
                if(sum < min_sum) {
                    min_sum = sum;
                    ways = 0;
                }
                if(sum == min_sum) ways++;
                mn++;  // slide window to right
            }
        }
    }

    cout << min_sum % MOD << "\n" << ways % MOD << "\n";

    return 0;
}
