#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <fstream>

#include <chrono>
using namespace std;
using namespace std::chrono;

void function(){
    int x = 0;
    int y = 0;
    int coords[4] = {0, 0, 0, 0};
    signed int currentDirection = 0;
    std::string stepString;
    string line;
    string move;
    ifstream f ("input.txt");
    if (f.is_open()){
        while(getline(f, line)){
            stringstream ssin(line);
            while(ssin.good()){
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
                move = move.substr(1, move.size());
                coords[currentDirection] += stoi(move);
            }
        }
        x = coords[1] - coords[3];
        y = coords[0] - coords[2];
        f.close();
        printf("x: %i\ny: %i\n", x, y);
        printf("Distance: %i\n", abs(x) + abs(y));
    } else {
        printf("Can not open file\n");
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
