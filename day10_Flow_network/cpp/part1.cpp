#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>
#include <chrono>
//Why can't you string switch!! lol

using namespace std;
using namespace std::chrono;
struct bot{
    int number;
    vector<int> chips;
    int high;
    int low;
};

int run(){
    ifstream txtFile("testinput.txt");
    if(txtFile.is_open()){
        int num = 0;
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

int main()
{
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    run();
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>( t2 - t1 ).count();

    cout << duration << endl;
    return 0;
}
