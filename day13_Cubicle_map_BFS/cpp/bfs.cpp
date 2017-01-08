#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <bitset>

using namespace std;

char wallCheck(int& x, int& y, int& favNum){
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

int printFloor(vector<char> floorPlan){
    int end = 5;
    printf(" ");
    for (int j = 0; j < 1; ++j){
        for (int i = 0; i < end; ++i){
            printf(" %d", i);
        }
    }
    printf("\n");
    for (int i = 0; i < end; ++i){
        printf("%d", i);
        for (int j = 0; j < end; ++j){
            printf(" %c", floorPlan[i*end + j]);
        }
        printf("\n");
    }
}

int main(){
    // Generate map
    int favNum = 10;
    vector<char> floorPlan;
    int end = 5;
    for (int j = 0; j < end; ++j){
        for(int i = 0; i < end; ++i){
            floorPlan.push_back(wallCheck(i, j, favNum));
        }
    }
    // BFS to find shortest path
    int position = 2 + end;
    list<list<int>> paths;
    list<int> queue;
    queue.push_back(position);
    while (queue.size() > 0){
        paths.push_back(queue);
        for (list<int> path : paths){
            queue.erase(queue.begin());
            // cout << path.begin();
        }

    }
    printf("(%02d, %02d)\n", position%end-1,position/end);
    // print floor plan
    printFloor(floorPlan);
}
