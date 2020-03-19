#include <bits/stdc++.h>
using namespace std;
void random_test_generator(int n_min, int n_max, int value_min, int value_max) {
    random_device seed_gen;
    mt19937_64 rnd(seed_gen());

    uniform_int_distribution<int> dist_N(n_min, n_max), dist_A(value_min, value_max);
    int N = dist_N(rnd);
    int M = dist_N(rnd);
    ofstream outputfile;
    outputfile.open("../../../etc/input.txt", ios::trunc);
    if (!outputfile) {
        cout << "file not found!" << endl;
    }
    string writeText = "";
    vector<int> A(M);
    for (int i = 0; i < M; i++)
        A[i] = dist_A(rnd);

    sort(A.begin(), A.end());

    writeText += to_string(N) + " " + to_string(M) + '\n';
    for (int i = 0; i < N; i++)
        writeText += to_string(A[i]) + " \n"[i == N - 1];
    outputfile << writeText;
}

int main() {
    random_test_generator(1, 10, 1, 100000);
}
