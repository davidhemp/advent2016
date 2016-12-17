#include <iostream>
#include <string>
#include <fstream>
#include <regex>

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

bool search(string testString){
    for (int i = 0; i < testString.size()-3; ++i){
        if (testString[i] == testString[i+3]
            && testString[i+1] == testString[i+2]
            && testString[i] != testString[i+1]
            && testString[i+2] != testString[i+3]
        ){
            return true;
        }
    }
    return false;
}

int run(int& num){
    string line;
    ifstream txtFile("input.txt");
    smatch match;
    if(txtFile.is_open()){
        while(txtFile.good()){
                getline(txtFile, line);
                regex rgx("(.*?)\\[(.*?)\\](.*?)$");
                if (regex_search(line, match, rgx)){
                    // cout << "beep ";
                    if (!search(match[2])){
                        // cout << "boop ";
                        if (search(match[1]) || search(match[3])){
                            // cout << "bang ";
                            // cout << line;
                            num++;
                        }
                    }
                }
                // cout << endl;
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
    cout << endl;
    cout << ave << " seconds" <<endl;
    //output solution
    cout << num << endl;
}
