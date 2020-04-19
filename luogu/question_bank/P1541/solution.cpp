#include <iostream>
#define N 400
#define M 4
using namespace std;
int n, m, a[N], s[M];
int dp[40][40][40][40];

int main() {
    cin >> n >> m;
    for (int i=0; i<n; ++i) cin >> a[i];
    int ii;
    for (int i=0; i<m; ++i) cin >> ii, ++s[ii];
    dp[0][0][0][0] = a[0];
    int maxx, now;
    for (int s0=0; s0<=s[0]; ++s0)
        for (int s1=0; s1<=s[1]; ++s1)
            for (int s2=0; s2<=s[2]; ++s2)
                for (int s3=0; s3<=s[3]; ++s3) {
                    if (s0 + s1 + s2 + s3 == 0) continue;
                    maxx = 0; now = s0*1 + s1*2 + s2*3 + s3*4;
                    if (0<s0) maxx = max(maxx, dp[s0-1][s1][s2][s3]+a[now]);
                    if (0<s1) maxx = max(maxx, dp[s0][s1-1][s2][s3]+a[now]);
                    if (0<s2) maxx = max(maxx, dp[s0][s1][s2-1][s3]+a[now]);
                    if (0<s3) maxx = max(maxx, dp[s0][s1][s2][s3-1]+a[now]);
                    dp[s0][s1][s2][s3] = maxx;
                }
    cout << dp[s[0]][s[1]][s[2]][s[3]] << endl;
    return 0;
}
