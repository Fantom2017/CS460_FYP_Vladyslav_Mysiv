#include <bits/stdc++.h>

using namespace std;

vector<int> deck {1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,5,5,5,5,5,5,5,5,5,5,5,5};
vector<int> deck_extended {1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,5,5,5,5,5,5,5,5,5,5,5,5, 1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,5,5,5,5,5,5,5,5,5,5,5,5};
vector<int> deck_long_jumps {2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,11,11,11,11,12,12,12,12,13,13,13,13,14,14,14,14};

bool trick(int seed, vector<int> deck_cur){
    shuffle(deck_cur.begin(), deck_cur.end(), default_random_engine(seed));

    srand(time(NULL));
    int user = rand() % 10;

    while (user < deck_cur.size()){
        user = user + deck_cur[user];
    }

    int magician = 0;
    while (magician < deck_cur.size()){
        magician = magician + deck_cur[magician];
    }

    return user == magician;
}

int main(int argc, char* argv[]){
    int res = 0;
    vector<int> deck_select;
    // 0 for deck, 1 for deck_extended, 2 for deck_long_jumps
    if (argc == 1) {
        return 1;
    }
    if (argv[1][0] == '0'){
        deck_select = deck;
    } else if (argv[1][0] == '1'){
        deck_select = deck_extended;
    } else if (argv[1][0] == '2'){
        deck_select = deck_long_jumps;
    } else {
        cout << "Param need to be 0, 1 or 2";
        return 0;
    }
    for (int i = 0; i < 1e6; i++){
        res += trick(i, deck_select);
    }
    cout << res/1e6;
}