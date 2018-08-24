
#include<cstdio>

#include<cstring>

#include<cmath>

#include<iostream>

#include<algorithm>

using namespace std;

int t;

long long n, a, b;



long long gcd(long long a, long long b)

{

	if (b == 0)

		return a;

	else

		return gcd(b, a%b);

}

long long lcm(long long a, long long b)

{

	return a / gcd(a, b)*b;

}



long long slove(long long a, long long b, long long n)

{



	long long now = 0;

	long long ans = 0;

	long long tmp;

	long long x = 0, y = 0;

	while (now<n)

	{



		tmp = min(a - x, b - y);

		if (now + tmp>n) tmp = n - now;

		ans += tmp * abs(x - y);

		x = (x + tmp) % a;

		y = (y + tmp) % b;

		now += tmp;

		//cout<<tmp<<"~~"<<x<<"~"<<y<<"~"<<ans<<endl;

	}

	return ans;



}



int main()

{

	cin >> t;

	while (t--)

	{

		cin >> n >> a >> b;

		long long ans;

		long long l = lcm(a, b);

		if (l >= n)

			ans = slove(a, b, n);

		else

			ans = slove(a, b, l)*(n / l) + slove(a, b, n%l);

		cout << ans << endl;

	}

	return 0;

}