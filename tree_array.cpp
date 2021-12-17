#include<iostream>
using namespace std;


const int N = 900;
int a[N+1];
int tree[N+1];

//最低为的1的数大小
inline int lowbit(int x) {
	return (x & (-x));
}
//a[k]+v
//单点修改 复杂度logN
void add(int k, int v) {
	while (k <= N) {
		tree[k] += v;
		k += lowbit(k);
	}
}
//前缀和
int getsum(int x) {
	int sum = 0;
	while (x) {
		sum += tree[x];
		x = x - lowbit(x);
	}
	return sum;
}

//建树
//每一个上一层为 i+lowbit(i);
void ini() {
	tree[0] = 0;
	for (int i = 1; i <= N; ++i) {
		tree[i] += a[i];
		int j = i + lowbit(i);
		if (j <= N) tree[j] += tree[i];
	}
}