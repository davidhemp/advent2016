#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <locale>
#include <chrono>

using namespace std;
using namespace std::chrono;

int runLine(string& line, map<string, int>& regs, int& cursor){
    string command;
    string fromReg;
    string toReg;
    stringstream ssin(line);
    // for (auto elem : regs){
    //     cout << elem.first << ": " << elem.second << endl;
    // }
    // cout << "------" << endl;

    ssin >> command;
    if (command.compare("cpy") == 0){
        ssin >> fromReg;
        ssin >> toReg;
        if(isdigit(fromReg[0])){
            regs[toReg] = stoi(fromReg);
        } else {
            regs[toReg] = regs[fromReg];
        }
    } else if (command.compare("inc") == 0){
        ssin >> toReg;
        regs[toReg]++;
    } else if (command.compare("dec") == 0){
        ssin >> toReg;
        regs[toReg]--;
    } else if (command.compare("jnz") == 0){
        ssin >> fromReg;
        ssin >> toReg;
        int test = 0;
        if(isdigit(fromReg[0])){
            test = stoi(fromReg);
        } else {
            test = regs[fromReg];
        }
        if (test != 0){
            int incr = stoi(toReg);
            cursor += incr -1;
        }
    }
}

void run(){
    ifstream txtFile("input.txt");
    if(txtFile.is_open()){
        string line;
        vector<string> program;
        while(txtFile.good()){
            getline(txtFile, line);
            program.push_back(line);
        }
        int cursor = 0;
        map<string, int> regs;
        regs["a"] = 0;
        regs["b"] = 0;
        regs["c"] = 1;
        regs["d"] = 0;
        while (cursor < program.size()){
            // cout << cursor+1 << endl;
            runLine(program[cursor], regs, cursor);
            cursor++;
        }
        txtFile.close();
        cout << regs["a"] << endl;
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
