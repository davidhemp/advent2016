#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

// 74532 characters

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

int run(int& rtn){
    ifstream inFile("input.txt");
    if(inFile.is_open()){
        string line;
        string builtString = "";
        string numString;
        string appendString;
        int numChars = 0;
        int numRepeats = 0;
        while(inFile.good()){
                getline(inFile, line);
                builtString = "";
                int i = 0;
                while (i < line.size()){
                    if (line[i] == '('){
                        numString = "";
                        i++;
                        while (line[i] != 'x'){
                            numString += line[i];
                            i++;
                        }
                        numChars = stoi(numString);
                        numString = "";
                        i++;
                        while (line[i] != ')'){
                            numString += line[i];
                            i++;
                        }
                        numRepeats = stoi(numString);
                        i++;
                        appendString = "";
                        for (int j = 0; j < numChars; ++j){
                            appendString += line[i];
                            i++;
                        }
                        for (int j = 0; j < numRepeats; ++j){
                            builtString += appendString;
                        }
                    } else {
                        builtString += line[i];
                        i++;
                    }
                }
                rtn += builtString.size();
            }
        inFile.close();
    }
}

int main(){
    int rtn = 0;
    int counts = 10000;
    timestamp_t t0 = get_timestamp();
    timestamp_t t1 = get_timestamp();
    double secs = 0;
    double ave = 0;
    for (int i = 0; i < counts; ++i){
        rtn = 0;
        t0 = get_timestamp();
        run(rtn);
        t1 = get_timestamp();
        secs = (t1 - t0) / 1000000.0L;
        ave += secs;
    }
    ave = ave/counts;
    cout << ave << " seconds" <<endl;
    //output solution
    cout << rtn << " characters, ignoring whitespace and returns" << endl;
}
