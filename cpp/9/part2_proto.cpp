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

int run(int& rtn){
    ifstream inFile("testinput2.txt");
    ifstream outFile("testoutput2.txt");
    if(inFile.is_open() && outFile.is_open()){
        string testLine;
        string compareLine;
        int rtn = 0;
        int fails = 0;
        int passes = 0;
        string numString;
        int numChars = 0;
        int numRepeats = 0;
        while(inFile.good(), outFile.good()){
                // Line editting
                getline(inFile, testLine);
                getline(outFile, compareLine);
                int i = 0;
                while (i < testLine.size()){
                    if (testLine[i] == '('){
                        numString = "";
                        i++;
                        while (testLine[i] != 'x'){
                            numString += testLine[i];
                            i++;
                        }
                        numChars = stoi(numString);
                        numString = "";
                        i++;
                        while (testLine[i] != ')'){
                            numString += testLine[i];
                            i++;
                        }
                        numRepeats = stoi(numString);
                        i++;
                        rtn += numChars*numRepeats
                    } else {
                        rtn++;
                        i++;
                    }
                }
                rtn += builtString.size();
                if (builtString.compare(compareLine) == 0){
                    cout << "PASS | ";
                    ++passes;
                } else {
                    cout << "FAIL | ";
                    ++fails;
                }
                cout << compareLine;
                for (int i=compareLine.size(); i < 18; i++){
                    cout << " ";
                }
                cout << " |  " << builtString << endl;
            }
        inFile.close();
        outFile.close();
        if (rtn == 57){
            cout << "Final length PASSED: ";
            passes++;
        } else {
            cout << "Final length FAILED: ";
            fails++;
        }
        cout << rtn << " vs 57" << endl;

        if (fails > 0){
            cout << "Test FAILED" << endl;
        } else {
            cout << "Test PASSED" << endl;
        }
        cout << "Assertions failed: " << fails << endl;
        cout << "Assertions passed: " << passes << endl;
    }
}

int main(){
    int rtn = 0;
    int counts = 1;
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
