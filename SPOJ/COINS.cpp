#include <bits/stdc++.h>

using namespace std;

map<long long int, long long int> m;

long long int dp(long long int x){
	long long int ans, temp, sum;
	if(m.find(x) != m.end())
		return m[x];

	if(x < 2)
		ans = x;

	else {
		ans = x;
		sum = 0;

		temp = dp(x/2);
		if(temp > x/2)
			sum += temp;
		else
			sum += x/2;

		temp = dp(x/3);
		if(temp > x/3)
			sum += temp;
		else
			sum += x/3;

		temp = dp(x/4);
		if(temp > x/4)
			sum += temp;
		else
			sum += x/4;

		if(sum > ans)
			ans = sum;
	}

	m[x] = ans;
	return ans;
}

int main(){
	long long int x;
	while(scanf("%lld", &x) != EOF){
		printf("%lld\n", dp(x));
	}
	return 0;
}