#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#define left (now<<1)
#define right ((now<<1)+1)
#define mid ((l+r)>>1)
#define fst first
#define snd second
#define sfn scanf("%d",&n)
#define sfnm scanf("%d%d",&n,&m)
#define sft scanf("%d",&t)
#define pfans printf("%d\n",ans)
using namespace std;
typedef long long lint;

struct node {
	lint next[2];
};

lint t, n, m, len;
node tree[4000010];

void insertTree(lint now, lint num) {
	for (lint i = 32; i >= 0; --i) {
		lint v = ((num >> i) & 1);
		if (tree[now].next[v] == -1) {
			tree[now].next[v] = ++len;
		}
		now = tree[now].next[v];
	}
}

lint getAns(lint now, lint num) {
	lint re = 0;
	for (lint i = 32; i >= 0; --i) {
		lint v = ((num >> i) & 1);
		v = !v;
		if (tree[now].next[v] != -1) {
			re = (re << 1);
			re = (re | v);
			now = tree[now].next[v];
		}
		else {
			re = (re << 1);
			v = !v;
			re = (re | v);
			now = tree[now].next[v];
		}
	}
	return re;
}
int main() {
	lint ca = 0;
	scanf("%d", &t);
	while (t--) {
		++ca;
		scanf("%I64d%I64d", &n, &m);
		len = 1;
		memset(tree, -1, sizeof(tree));
		for (lint i = 1; i <= n; ++i) {
			lint num;
			scanf("%I64d", &num);
			insertTree(1, num);
		}
		printf("Case #%I64d:\n", ca);
		for (int i = 1; i <= m; ++i) {
			lint num, ans;
			scanf("%I64d", &num);
			ans = getAns(1, num);
			printf("%I64d\n", ans);
		}
	}
	return 0;
}