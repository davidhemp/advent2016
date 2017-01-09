#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <chrono>

using namespace std;
using namespace std::chrono;

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

void run(){
    int num = 0;
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
        cout << num << endl;
        txtFile.close();
    }
}

int main()
{
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    run();
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>( t2 - t1 ).count();

    cout << duration << endl;
    return 0;
}
