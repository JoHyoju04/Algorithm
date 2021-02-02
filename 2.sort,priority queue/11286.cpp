#include <iostream>
#include <cstdlib>
using namespace std;
int N, hsize, heap[100000] = { 0, };
bool compare(int a, int b) {
	if (abs(a) == abs(b))	return a < b;
	else return abs(a) < abs(b);
}
void insert(int item) {
	int index = ++hsize;
	while (index != 1 && compare(item, heap[index / 2])) {
		heap[index] = heap[index / 2];
		index /= 2;
	}
	heap[index] = item;

}
int remove() {
	if (hsize == 0)	return 0;
	int ret = heap[1];
	int last = heap[hsize--];
	int parent = 1, child = 2;
	while (child <= hsize) {
		if (child < hsize && compare(heap[child + 1], heap[child])) {
			child++;
		}
		if (compare(last, heap[child])) {
			break;
		}
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = last;
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int num;
	cin >> N;
	hsize = 0;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num == 0)
			cout << remove() << '\n';
		else
			insert(num);
	}

}