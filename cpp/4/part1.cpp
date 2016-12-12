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

int main(){
    using namespace std;
    timestamp_t t0 = get_timestamp();
    string line;
    string item;
    int count = 0;
    ifstream f ("input.txt");
    if (f.is_open()){
        while(getline(f, line)){
            vector<int> values;
            std::stringstream ssin(line);
            while (ssin.good()){
                ssin >> item;
                values.push_back(stoi(item));
            }
            sort(values.begin(), values.end());
            if (values[0] + values[1] > values[2]){
                count++;
            }
        }
        f.close();
    } else {
        cout << "Can not open file";
    }
    cout << count << endl;
    timestamp_t t1 = get_timestamp();
    double secs = (t1 - t0) / 1000000.0L;
    cout << secs << " seconds" <<endl;
}
