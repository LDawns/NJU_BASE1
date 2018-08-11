#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <vector>
#include <iterator>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
const ll MAX_N = 1 << 17;
const ll INF = 0x3f3f3f3f;
P machine[MAX_N];
P task[MAX_N];
int flag[110];

bool cmp(const P &a, const P &b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first > b.first;
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	ll n, m;
	while (scanf("%lld%lld", &n, &m) != EOF) {
		memset(flag, 0, sizeof flag);//��ʼ��flag������г�ԱΪ0
		for (ll i = 0; i < n; ++i) {
			scanf("%lld%lld", &machine[i].first, &machine[i].second);
		}
		for (ll i = 0; i < m; ++i) {
			scanf("%lld%lld", &task[i].first, &task[i].second);
		}
		sort(machine, machine + n, cmp);
		sort(task, task + m, cmp);
		ll ans = 0, res = 0;
		for (ll i = 0, j = 0; i < m; ++i) {
			while (j < n && machine[j].first >= task[i].first) {
				++flag[machine[j].second];
				++j;
			}
			for (ll k = task[i].second; k <= 100; ++k) {
				if (flag[k]) {
					++res;
					--flag[k];
					ans += 500 * task[i].first + 2 * task[i].second;
					break;
				}
			}
		}
		printf("%lld %lld\n", res, ans);
	}
	return 0;
}
//̰�ĵ����ڹ�ͼ��ǣ����Ǹ��ܽ���ͱ���Ҫ����ĵ㣬Ȼ���ڴ˻�����ѡ����õĵ�
//���⣬���⻹�л���ֻ��һ��֮�ͣ�ѭ���������
//��ѭ�����
//