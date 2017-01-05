#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#include <algorithm>
#include <map>
//Why can't you string switch!! lol


using namespace std;


struct point{
    int x;
    int y;
};

bool checkForWall(int& x, int& y){
    int favNum = 1352;
    unsigned long productSum = x*x + 3*x + 2*x*y + y + y*y + favNum;
    bitset<16> bitSet{productSum};
    int count = bitSet.count();
    if (count % 2 == 0 && x > -1 && y > -1){
        return true;
    }else {
        return false;
    }
}

vector<point> adj(int x, int y){
    vector<vector<int>> moves {{x+1, y}, {x-1, y}, {x, y+1}, {x, y-1}};
    vector<point> allowedMoves;
    point p = {0, 0};
    for (vector<int> move : moves){
        if (checkForWall(move[0], move[1]) == true){
            p = {move[0], move[1]};
            allowedMoves.push_back(p);
        }
    }
    return allowedMoves;
}

int main(){
    point s = {1, 1};
    vector<point> frontier;
    frontier.push_back(s);

    map<int, int> level;
    level[s.x + s.y*100] = 0;

    vector<point> next;
    int i = 1;
    while(i < 51){
        next.clear();
        for (point p : frontier){
            vector<point> adjPoints = adj(p.x, p.y);
            for (point a : adjPoints){
                auto it = level.find(a.x+a.y*100);
                if (it == level.end()){
                    level[a.x+a.y*100] = i;
                    next.push_back(a);
                } else {
                }
            }
        }
        frontier = next;
        i++;
    }
    printf("%i\n", level.size());
}
