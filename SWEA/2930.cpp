#include<iostream>

using namespace std;

int N, hsize, heap[100001];

void insert(int item) {
	int index = ++hsize;
	while (index != 1 && item > heap[index / 2]) {
		heap[index] = heap[index / 2];
		index /= 2;
	}
	heap[index] = item;
}

int remove() {
	if (hsize == 0)	return -1;
	int ret = heap[1];
	int last = heap[hsize--];
	int parent = 1, child = 2;
	while (child <= hsize) {
		if (child < hsize && heap[child] < heap[child + 1]) {
			child++;
		}
		if (heap[child] < last)	break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = last;
	return ret;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		hsize = 0;
		int order;
		cout << "#" << test_case << " ";
		for (int i = 0; i < N; i++) {
			cin >> order;
			if (order == 2)
				cout << remove() << ' ';
			else
			{
				int num;
				cin >> num;
				insert(num);
			}
		}


		for (int i = 0; i <= N; i++)	heap[i] = 0;

		cout << "\n";

	}
	return 0;
}