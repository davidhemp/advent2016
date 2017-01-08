#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

#include <sys/time.h>
typedef unsigned long long timestamp_t;

static timestamp_t
get_timestamp ()
{
  struct timeval now;
  gettimeofday (&now, NULL);
  return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
}

int run(int& num){
    vector<vector<int>> chipsAndRTGs{{1,2},{1,3}};
    int elevator = 1;
    string output;
    bool safe = true;

    // Test state
    for (vector<int> pair : chipsAndRTGs){
        output = "Safe";
        safe = true;
        if(pair[0] == pair[1]){
            break;
        } else {
            for (int i = 0; i < chipsAndRTGs.size(); ++i){
                if (pair[0] == chipsAndRTGs[i][1]){
                    safe = false;
                    output = "Failed";
                }
            }
        }
        cout << pair[0] << ' ' << pair[1] << ' ' << output << endl;;
    }
}


int main(){
    int num = 0;
    int counts = 1;
    timestamp_t t0 = get_timestamp();
    timestamp_t t1 = get_timestamp();
    double secs = 0;
    double ave = 0;
    for (int i = 0; i < counts; ++i){
        num = 0;
        t0 = get_timestamp();
        run(num);
        t1 = get_timestamp();
        secs = (t1 - t0) / 1000000.0L;
        ave += secs;
    }
    ave = ave/counts;
    cout << ave << " seconds" <<endl;
    //output solution
    cout << num << endl;
}
