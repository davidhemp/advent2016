#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
// 74532 characters

using namespace std;
using namespace std::chrono;

void run(){
    ifstream inFile("input.txt");
    if(inFile.is_open()){
        string line;
        string builtString = "";
        string numString;
        string appendString;
        int numChars = 0;
        int numRepeats = 0;
        int rtn = 0;
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
        cout << rtn << " characters, ignoring whitespace and returns" << endl;
    }
}

int main()
{
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    run();
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>( t2 - t1 ).count();

    cout << duration << endl;
    return 0;
}
