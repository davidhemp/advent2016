#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
//Why can't you string switch!! lol

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
    ifstream txtFile("testinput.txt");
    string line;
    if(txtFile.is_open()){
        while(txtFile.good()){
            // Line editting
            getline(txtFile, line);
            stringstream ssin(line);
        }
        txtFile.close();
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
