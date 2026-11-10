#include <bits\stdc++.h>

using namespace std;

int gcd(int a, int b){
    if (a == 0) return b;
    if (b == 0) return a;
    if (a == b) return a;
    if (a > b) return gcd(a-b, b);
    return gcd(a, b - a);
}

int g(int x){
    return (x*x+1);
}

int main(){
    int n;
    int x;
    cout << "input n and x" << endl;
    //Examples: use x = 2, and n either 10403 or 8051
    cin >> n >> x;
    int d = 1;
    int x1 = x;
    int x2 = x;
    while (d == 1){
        x1 = g(x1)%n; //tortoise
        x2 = g(g(x2)%n)%n; //hare
        d = gcd(abs(x1-x2), n);
        cout << x1 << " " << x2 << " " << d << endl;
    }
    if (d == n){
        cout << "failed to find, try another x\n";
    }
    else{
        cout << "The value of first factor is " << d << endl;
    }
}