#include <bits/stdc++.h>
class NStack {
public:
    int *arr, *top, *start, n, s;
    NStack(int N, int S) {
        n = N, s = S;
        arr = new int[S];
        top = new int[N];
        start = new int[N];
        for (int i = 0; i < n; i++) {
            start[i] = (s / n) * i;
            top[i] = start[i] - 1;
        }
    }

    bool push(int x, int m) {
        m--;
        if (top[m] < start[m] + (s / n) - 1) {
            top[m]++;
            arr[top[m]] = x;
            return true;
        }
        return false;
    }

    int pop(int m) {
        m--;
        if (top[m] < start[m]) {
            return -1;
        }
        return arr[top[m]--];
    }
};
