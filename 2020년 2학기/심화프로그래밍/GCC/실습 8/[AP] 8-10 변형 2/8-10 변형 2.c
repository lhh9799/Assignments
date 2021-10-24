#include <stdio.h>

int find_min(int a, int b, int c) {
	int min;

	if((a > b) && (b > c))
		min = c;
	if((a > b) && (b < c))
		min = b;
	if((a < b) && (a < c))
		min = a;

	return min;
}

int origingcd(int x, int y) {
	if(y == 0)
		return x;
	else
		return origingcd(y, x%y);
}

int find_num(int gcd, int k) {
	int i, result = -1, pos = 0;

	for(i=gcd; i>0; i--) {
		if(gcd % i == 0) {
			pos++;
		}
		if(pos == k) {
			result = i;
			break;
		}
	}
	return result;
}

int gcd(int min, int a, int b, int c, int k) {
	int gcd, result, param1 = 1, param2 = 1;

	a %= min;	b %= min;	c %= min;

	if(a == 0 && b == 0 && c == 0) {gcd = min;}
	else if(a == 0)	{param1 = b; param2 = c; gcd = origingcd(param1,param2);}
	else if(b == 0)	{param1 = a; param2 = c; gcd = origingcd(param1,param2);}
	else if(c == 0)	{param1 = a; param2 = b; gcd = origingcd(param1,param2);}

	result = find_num(gcd, k);

	return result;
}

int main() {
	int a, b, c, k, min;

	scanf("%d %d %d %d", &a, &b, &c, &k);
	min = find_min(a, b, c);
	printf("%d", gcd(min, a, b, c, k));

	return 0;
}

