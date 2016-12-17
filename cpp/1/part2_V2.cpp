#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <set>
#include <vector>

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

int run(int& xx, int& yy){
    timestamp_t t0 = get_timestamp();
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
    } else {
        cout << "Can not open file";
    }
}

int main(){
    int xx;
    int yy;
    int counts = 10000;
    double secs;
    double ave = 0.0;
    timestamp_t t0 = get_timestamp();
    timestamp_t t1 = get_timestamp();
    for (int i = 0; i < counts; ++i){
        xx = 0;
        yy = 0;
        t0 = get_timestamp();
        run(xx, yy);
        t1 = get_timestamp();
        secs = (t1 - t0) / 1000000.0L;
        ave += secs;
    }
    // output solution
    cout << "x: " << xx << endl;
    cout << "y: " << yy << endl;
    cout << "Distance: " << abs(xx) + abs(yy) << endl;
    ave = ave/counts;
    cout << ave << " seconds" << endl;
}
