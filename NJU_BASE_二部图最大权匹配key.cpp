#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<vector>
#include<cstdlib>
#define lson (rt<<1),L,M
#define rson (rt<<1|1),M+1,R
#define M ((L+R)>>1)
#define cl(a,b) memset(a,b,sizeof(a));
#define LL long long
#define P pair<int,int>
#define X first
#define Y second
#define pb push_back
#define fread(zcc)  freopen(zcc,"r",stdin)
#define fwrite(zcc) freopen(zcc,"w",stdout)
using namespace std;
const int maxn = 505;
const int inf = 9999999;

int w[maxn][maxn];
int linker[maxn], lx[maxn], ly[maxn], slack[maxn];
bool visx[maxn], visy[maxn];
int nx, ny;
bool dfs(int x) {
	visx[x] = true;
	for (int y = 0; y<ny; y++) {
		if (visy[y])continue;
		int tmp = lx[x] + ly[y] - w[x][y];
		if (tmp == 0) {
			visy[y] = true;
			if (linker[y] == -1 || dfs(linker[y])) {
				linker[y] = x;
				return true;
			}
		}
		else if (slack[y]>tmp) {
			slack[y] = tmp;
		}
	}
	return false;
}

int km() {
	cl(linker, -1);
	cl(ly, 0);
	for (int i = 0; i<nx; i++) {
		lx[i] = -inf;
		for (int j = 0; j<ny; j++)if (w[i][j]>lx[i]) {
			lx[i] = w[i][j];
		}
	}
	for (int x = 0; x<nx; x++) {
		fill(slack, slack + ny + 1, inf);
		while (true) {
			cl(visx, false);
			cl(visy, false);
			if (dfs(x))break;

			int d = inf;
			for (int i = 0; i<ny; i++)if (!visy[i] && slack[i]<d) {
				d = slack[i];
			}
			for (int i = 0; i<nx; i++)if (visx[i]) {
				lx[i] -= d;
			}
			for (int i = 0; i<ny; i++)if (visy[i])ly[i] += d;
			else slack[i] -= d;
		}
	}
	int ans = 0;
	for (int i = 0; i<ny; i++)if (linker[i] != -1) {
		ans += w[linker[i]][i];
	}
	return ans;
}
int a[maxn];
inline int abs(int x) { return x<0 ? -x : x; }
int main() {
	int n;
	while (~scanf("%d", &n)) {
		for (int i = 0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++) {
				w[i][j] = -inf;//初始化权值
			}
		}
		nx = ny = 0;
		for (int i = 0; i<n; i++)if (a[i]>1) {
			for (int j = 1; j<a[i]; j++) {//多出来的都要移动
				for (int k = 0; k<n; k++)if (a[k] == 0) {
					w[nx][k] = -min(abs(i - k), n - abs(i - k));
				}
				nx++;
			}
		}
		ny = n;

		printf("%d\n", -km());
	}
	return 0;
}
