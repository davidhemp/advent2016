#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <set>
#include <chrono>

using namespace std;
using namespace std::chrono;
void function(){
    vector<char> finalWord (8, '-');
    //load data
    vector<vector<char>> letters(8, vector<char> (1000, '-'));
    set <char> buildSet;
    vector<set <char>> letterSets(8, buildSet);
    string line;
    ifstream f ("input.txt");
    int n = 0;
    if (f.is_open()){
        while(getline(f, line)){
            for (int i = 0; i < line.size(); ++i){
                letters[i][n] = line[i];
                letterSets[i].insert(line[i]);
            }
            n++;
        }
    }
    f.close();
    //find most common in each line
    int counts_old = 1000;
    int counts_new = 0;
    for (int i = 0; i < 8; ++i){
        for (auto it = letterSets[i].begin(); it != letterSets[i].end(); ++it){
            counts_new = count( letters[i].begin(),
                                letters[i].end(),
                                *it);
            if (counts_new < counts_old){
                finalWord[i]  = *it;
                counts_old = counts_new;
            }
        }
        counts_old = 1000;
    }
    // output solution
    for (int i = 0; i < 8; ++i){
        cout << finalWord[i];
    }
    cout << endl;
}

int main()
{
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    function();
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>( t2 - t1 ).count();

    cout << duration << endl;
    return 0;
}
