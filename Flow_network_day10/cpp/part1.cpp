#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>
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

struct bot{
    int number;
    vector<int> chips;
    int high;
    int low;
};

int run(int& num){
    ifstream txtFile("testinput.txt");
    if(txtFile.is_open()){
        vector<bot> bots(220);
        for (int i =0; i<220; ++i){
            bots[i].number = i;
        }
        string line;
        smatch match;
        regex straightRGX("value (\\d+) goes to bot (\\d+)");
        regex conditionalRGX("bot (\\d+) gives low to (output|bot) (\\d+) and high to (output|bot) (\\d+)");
        while(txtFile.good()){
                // Line editting
                getline(txtFile, line);
                if (regex_match (line, match, straightRGX)){
                    cout << match[1] << " goes to " << match[2] << endl;
                } else if (regex_match (line, match, conditionalRGX)){
                    if (match[2].compare("bot") == 0){
                        bots[stoi(match[1])].high = stoi(match[3]);
                        bots[stoi(match[1])].low = stoi(match[4]);
                    }

                }
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
