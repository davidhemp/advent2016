#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

bool bab(string t_str, vector<string> &data){
    if (t_str[0] == t_str[2] && t_str[0] != t_str[1]){
        stringstream ssin;
        ssin << t_str[1] << t_str[0] << t_str[1]; //build inverse
        //search everyother string which should be the out of bracket strings
        for(int j = 0; j < data.size()  ; j += 2){
            for (int i = 0; i < data[j].size()-2; ++i){
                if (ssin.str().compare(data[j].substr(i, 3)) == 0){
                    return true;
                }
            }
        }
    }
    return false;
}

bool aba(string &insideString, vector<string> &data){
    bool rtn = false;
    int i = 0;
    while (i < insideString.size()-2){
        if (bab(insideString.substr(i, 3), data)){
            return true;
        }
        ++i;
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
                vector<string> data;
                char *str = &line[0u];
                char * pch;
                pch = strtok (str,"[]");
                while (pch != NULL){
                    data.push_back(pch);
                    pch = strtok (NULL, "[]");
                }
                for(auto it=data.begin()+1; it<data.end();it+=2){
                    if(aba(*it, data)){
                        num++;
                    }
                }
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
