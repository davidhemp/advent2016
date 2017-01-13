#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <openssl/md5.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Disc{
public:
    Disc(int start, int no_positions);
    int position(int& time);
    int start;
    int no_positions;
private:
};

Disc::Disc(int start, int no_positions):
            start(start), no_positions(no_positions){
};

int Disc::position(int& time){
    return (time+start)%no_positions;
};

void run(){
    ifstream txtFile("input.txt");
    if(txtFile.is_open()){
        string line;
        smatch match;
        vector<Disc> tower;
        while(txtFile.good()){
            getline(txtFile, line);
            regex rgx("Disc #(\\d+) has (\\d+) positions; at time=0, it is at position (\\d+)");
            if (regex_search (line, match, rgx)){
                Disc d(stoi(match[3]), stoi(match[2]));
                tower.push_back(d);
            }
        }
        txtFile.close();
        int height = 0;
        height = tower.size();
        int time = 0;
        while (height > 0){
            time++;
            for (auto d : tower){
                if (d.position(time) != 0){
                    height = tower.size();
                    break;
                } else {
                    height--;
                    time++;
                }
            }
        }
        cout << (time - tower.size() - 1) << endl;
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
