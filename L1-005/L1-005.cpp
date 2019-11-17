#include <iostream>

using namespace std;
struct {
    unsigned long ID;
    int seatnum;
} Information[1000];

int main() {
    int N;
    cin >> N;
    int M[N];
    for (int i = 0; i < N; ++i) {
        unsigned long studentid, testnum, seatmum;
        cin >> studentid >> testnum >> seatmum;
        Information[testnum].seatnum = seatmum;
        Information[testnum].ID = studentid;
    }
    cin >> N;
    for (int j = 0; j < N; ++j) cin >> M[j];
    for (int k = 0; k < N; ++k) cout << Information[M[k]].ID << ' ' << Information[M[k]].seatnum << endl;
    return 0;
}