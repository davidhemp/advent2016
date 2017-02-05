#include <iostream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

string nextLevel(string &last_level, int &trap_count){
    vector<string> trap_matchs {"^^.", ".^^", "^..", "..^"};
    string withEdges = "." + last_level + ".";
    string rtn;
    for (int i=0; i < withEdges.length()-2; ++i){
        string next_tile = ".";
        for (auto s:trap_matchs){
            if (withEdges.substr(i,3).compare(s) == 0){
                next_tile = "^";
                trap_count++;
                break;
            }
        }
        rtn += next_tile;
    }
    return rtn;
}

void run(string &input_str, int &rows){
    vector<string> levels {input_str};
    int i =0;
    int trap_count = 0;
    for (auto c:input_str){
        if (c == '^'){
            trap_count++;
        }
    }
    cout << input_str.length()-trap_count << endl;
    while (levels.size() < rows){
        levels.push_back(nextLevel(levels[i], trap_count));
        ++i;
    }
    // for (auto l:levels){
    //     cout << l << endl;
    // }
    int safe_count = (levels.size()*input_str.length()) - trap_count;
    cout << safe_count << endl;
}

int main(){
    // testing, safe_Count = 38
    // string input_str = ".^^.^.^^^^";
    // int rows = 10;
    string input_str =  ".^^..^...^..^^.^^^.^^^.^^^^^^.^.^^^^.^^.^^^^^^";
    input_str += ".^...^......^...^^^..^^^.....^^^^^^^^^....^^...^^^^..^";
    int rows = 40;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    run(input_str, rows);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>( t2 - t1 ).count();

    cout << duration << endl;
}
