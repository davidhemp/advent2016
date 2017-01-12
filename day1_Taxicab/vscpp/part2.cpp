#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <set>
#include <vector>

#include <chrono>
using namespace std::chrono;
using namespace std;

void function(){
    int xx;
    int yy;
    int coords[4] = {0, 0, 0, 0};
    signed int currentDirection = 0;
    vector<int> step (2,0);
    set <vector <int>> positions;
    int setLength = 0;
    string line;
    string move;
    int distance;
    int crossing;
    int run = 1;
    ifstream f ("input.txt");
    if (f.is_open()){
        while(getline(f, line)){
            stringstream ssin(line);
            while(run == 1){
                ssin >> move;
                if(move[0] == 'L'){
                        --currentDirection;
                        if (currentDirection < 0){
                            currentDirection = 3;
                        }
                } else {
                        ++currentDirection;
                        if (currentDirection > 3){
                            currentDirection = 0;
                        }
                }
                distance = stoi(move.substr(1, move.size()));
                for (int i = 0; i < distance; i++){
                    coords[currentDirection] += 1;
                    step[0] = coords[1] - coords[3];
                    step[1] = coords[0] - coords[2];
                    positions.insert(step);
                    if (positions.size() > setLength){
                        setLength = positions.size();
                    } else {
                        if(run == 1){
                            xx = step[0];
                            yy = step[1];
                            run = 0;
                        }
                    }
                }
            }
        }
        f.close();
        cout << "x: " << xx << endl;
        cout << "y: " << yy << endl;
        cout << "Distance: " << abs(xx) + abs(yy) << endl;
    } else {
        cout << "Can not open file";
    }
}


int main()
{
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    function();
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>( t2 - t1 ).count();

    cout << duration << endl;
    return 0;
}
