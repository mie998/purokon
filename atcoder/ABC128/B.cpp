#include <bits/stdc++.h>
using namespace std;

typedef tuple<string, int, int> P;

bool pairCompare(const P &firstElof, const P &secondElof) {
    if (get<0>(firstElof) == get<0>(secondElof))
        return get<1>(firstElof) > get<1>(secondElof);
    else
        return get<0>(firstElof) < get<0>(secondElof);
}

int main() {
    int n;
    cin >> n;
    vector<P> vec;
    string s;
    int p;
    for (int i = 1; i <= n; i++) {
        cin >> s >> p;
        vec.push_back(P(s, p, i));
    }
    sort(vec.begin(), vec.end(), pairCompare);
    for (int i = 0; i < vec.size(); i++) {
        cout << get<2>(vec[i]) << endl;
    }
}
