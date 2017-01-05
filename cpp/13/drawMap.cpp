#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
//Why can't you string switch!! lol


using namespace std;

char run(int& x, int& y, int& favNum){
    unsigned long productSum = x*x + 3*x + 2*x*y + y + y*y + favNum;
    bitset<16> bitSet{productSum};
    int count = bitSet.count();
    char rtn = '#';
    if (count % 2 == 0){
        rtn = '.';
    }
    if (x == 31 && y == 39){
        rtn = '0';
    }
    return rtn;
}

int main(){
    int favNum = 1352;
    vector<vector<char>> floorMap;
    vector<char> row;
    int end = 40;
    for (int j = 0; j < end; ++j){
        row.clear();
        for(int i = 0; i < end; ++i){
            row.push_back(run(i, j, favNum));
        }
        floorMap.push_back(row);
    }
    vector<int> position(2,0);
    cout << "   ";
    for (int j = 0; j < 1; ++j){
        for (int i = 0; i < 10; ++i){
            cout << i;
        }
    }
    cout << endl;
    int i = 0;
    for (auto v : floorMap){
        printf("%02d ", i);
        i++;
        for (auto c : v){
            cout << c;
        }
        cout << endl;
    }
}
