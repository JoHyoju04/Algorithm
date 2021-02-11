#include <iostream>
#define MAX_SIZE 500001
using namespace std;
int rear = -1, front = -1;
int arr[MAX_SIZE] = { 0, };
void enqueue(int n) {
    rear = (rear + 1) % (MAX_SIZE - 1);
    arr[rear] = n;
}
int dequeue() {
    front = (front + 1) % (MAX_SIZE - 1);
    return arr[front];
}
int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)   enqueue(i);
    while (rear != front + 1) {
        dequeue();
        enqueue(dequeue());
    }
    cout << arr[rear];
    return 0;
}