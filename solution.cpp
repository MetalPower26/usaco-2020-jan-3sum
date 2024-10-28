#include <bits/stdc++.h>
using namespace std;

const int MX = 105;
const int MN = 2e6 + 10;
int N, Q, arr[MX], cnt[MN];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> Q;

    int mx = 1000000;
    for(int i = 1; i <= N; i++) cin >> arr[i];

    for(int i = 1; i <= Q; i++){
        int l, r; cin >> l >> r;
        int ans = 0;
        for(int j = l; j <= r; j++){
            for(int k = j + 1; k <= r; k++){
                int val = -(arr[j] + arr[k]) + mx;
                if(0 <= val && val < MN) ans += cnt[val];
            }
            cnt[arr[j] + mx]++;
        }
        for(int j = l; j <= r; j++) cnt[arr[j] + mx]--;
        cout << ans << '\n';
    }
}