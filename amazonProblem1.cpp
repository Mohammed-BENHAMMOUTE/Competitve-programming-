#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll maxTransferRate(vector<int>& throughput, ll pipelineCount) {
    int n = throughput.size();
    sort(throughput.begin(), throughput.end(), greater<int>());

    vector<ll> prefixSum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + throughput[i];
    }

    ll left = 2, right = (ll)throughput[0] * 2;
    ll threshold = 0;

    while (left <= right) {
        ll mid = (left + right) / 2;
        ll count = 0;
        int j = n - 1;

        for (int i = 0; i < n; ++i) {
            while (j >= 0 && throughput[i] + throughput[j] < mid) {
                --j;
            }
            count += (j + 1);
            if (j < 0) break;
        }

        if (count >= pipelineCount) {
            threshold = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    ll total = 0;
    ll count = 0;
    int j = n - 1;

    for (int i = 0; i < n; ++i) {
        while (j >= 0 && throughput[i] + throughput[j] < threshold) {
            --j;
        }
        if (j >= 0) {
            total += prefixSum[j + 1] + (ll)throughput[i] * (j + 1);
            count += (j + 1);
        } else {
            break;
        };
    };

    if (count > pipelineCount) {
        total -= (count - pipelineCount) * threshold;
    }

    return total;
}

int main() {
    int n;
    ll pipelineCount;
    cin >> n >> pipelineCount;
    vector<int> throughput(n);

    for (int i = 0; i < n; ++i) {
        cin >> throughput[i];
    }

    cout << maxTransferRate(throughput, pipelineCount) << endl;
    return 0;
}