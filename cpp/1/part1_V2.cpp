#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <fstream>

#include <sys/time.h>
typedef unsigned long long timestamp_t;

static timestamp_t
get_timestamp ()
{
  struct timeval now;
  gettimeofday (&now, NULL);
  return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
}
using namespace std;

int run(int& x, int& y){
    timestamp_t t0 = get_timestamp();
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
    } else {
        cout << "Can not open file";
    }
}

int main(){
    int x;
    int y;
    int counts = 10000;
    double secs;
    double ave = 0.0;
    timestamp_t t0 = get_timestamp();
    timestamp_t t1 = get_timestamp();
    for (int i = 0; i < counts; ++i){
        x = 0;
        y = 0;
        t0 = get_timestamp();
        run(x, y);
        t1 = get_timestamp();
        secs = (t1 - t0) / 1000000.0L;
        ave += secs;
    }
    // output solution
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    cout << "Distance: " << abs(x) + abs(y) << endl;
    ave = ave/counts;
    cout << ave << " seconds" << endl;
}
