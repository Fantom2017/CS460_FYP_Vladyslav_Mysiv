#include <bits\stdc++.h>

using namespace std;

constexpr int n = 1018;
constexpr int N = n+1;
constexpr int alpha_ = 2;
constexpr int beta_ = 5;

tuple<int, int, int> nextTuple(int x, int a, int b) noexcept {
    switch (x % 3){
        case 0:
            return {(x*x) % N, (a*2) % n, (b*2) % n};
        case 1:
            return {(x*alpha_) % N, (a+1) % n, b};
        case 2:
            return {(x*beta_) % N, a, (b+1) % n};
    }
    return {0, 0, 0};
}

int main(){
    tuple<int, int, int> tortoise = {1, 0, 0};
    tuple<int, int, int> hare = tortoise;
    cout << "  i     x   a   b    x'  a'  b' \n";
    cout << " ------------------------------ \n";
    for (int i = 1; i < n; i++){
        tortoise = nextTuple(get<0>(tortoise), get<1>(tortoise), get<2>(tortoise));
        tuple<int, int, int> temp = nextTuple(get<0>(hare), get<1>(hare), get<2>(hare));
        hare = nextTuple(get<0>(temp), get<1>(temp), get<2>(temp));
        cout << i << " " <<
        get<0>(tortoise) << " " << get<1>(tortoise) << " " << get<2>(tortoise) << " " <<
        get<0>(hare) << " " << get<1>(hare) << " " << get<2>(hare) << endl;
        if (get<0>(tortoise) == get<0>(hare)) break;
    }
    int numerator = get<1>(tortoise) - get<1>(hare);
    int denominator = get<2>(hare) - get<2>(tortoise);
    numerator = ((numerator % n) + n) % n;
    denominator = ((denominator % n) + n) % n;
    int gamma_ = numerator/denominator;
    cout << gamma_ << endl;
}