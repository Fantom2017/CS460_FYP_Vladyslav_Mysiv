#include <bits\stdc++.h>

using namespace std;

constexpr int a = 500;
constexpr int b = 600;
constexpr int N = 50;
constexpr int alpha_ = 2;
constexpr int beta_ = 5;
constexpr int p = 1019;
constexpr int n = p-1;
vector<int> S {2,4,8,16,32};

int f(int x){
    return S[x%S.size()];
}

int modPow(long long x, long long n, int p) {
    // computes x^n mod p
        long long res = 1;
        x = x % p;
        while (n > 0){
            if (n % 2 == 1) res = (res * x) % p;
            x = (x * x % p);
            n = n/2;
        }
        return res;
    }

int main(){
    long long x = modPow(alpha_, b, p);
    long long d = 0;
    for (int i = 1; i < N; i++){
        long long jump = f(x);
        x = (x * modPow(alpha_, jump, p)) % p;
        d = d + jump;
    }

    long long y = beta_;
    long long dj = 0;
    long long gamma_;
    while (true){
        if (y == x){
            gamma_ = (((b + d - dj) % n) + n) % n;
            cout << gamma_ << endl;
            return 0;
        }
        if (dj > (b-a+d)){
            cout << "Failed to find x\n";
            return 1;
        }
        long long jump = f(y);
        y = (y * modPow(alpha_, jump, p)) % p;
        dj = dj + jump;
    }
}