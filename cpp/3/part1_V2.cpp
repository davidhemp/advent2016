#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

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
int run(int& num_tri){
    string line;
    string item;
    ifstream f ("input.txt");
    vector<int> values(3, 0);
    if (f.is_open()){
        while(getline(f, line)){
            std::stringstream ssin(line);
            for (int i = 0; i < 3; i++){
                ssin >> item;
                values[i] = stoi(item);
            }
            sort(values.begin(), values.end());
            if (values[0] + values[1] > values[2]){
                num_tri++;
            }
        }
        f.close();
    } else {
        cout << "Can not open file";
    }
}

int main(){
    int num_tri = 0;
    int counts = 1000;
    double secs;
    double ave = 0.0;
    timestamp_t t0 = get_timestamp();
    timestamp_t t1 = get_timestamp();
    for (int i = 0; i < counts; ++i){
        num_tri = 0;
        t0 = get_timestamp();
        run(num_tri);
        t1 = get_timestamp();
        secs = (t1 - t0) / 1000000.0L;
        ave += secs;
    }
    // output solution
    cout << num_tri << endl;
    ave = ave/counts;
    cout << ave << " seconds" <<endl;
}
