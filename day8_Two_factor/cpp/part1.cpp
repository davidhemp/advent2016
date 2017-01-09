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

void run(){
    ifstream txtFile("input.txt");
    if(txtFile.is_open()){
        int num = 0;
        int x;
        int y;
        string line;
        string section;
        smatch match;
        vector<vector<int>> grid(6, vector<int>(50, 0));
        regex rectRGX("rect (\\d+)x(\\d+)");
        regex rotateRGX("rotate (column|row) (x|y)=(\\d+) by (\\d+)");
        int tempInt;
        while(txtFile.good()){
                // Line editting
                getline(txtFile, line);
                if (regex_match (line, match, rectRGX)){
                    x = stoi(match.str(1));
                    y = stoi(match.str(2));
                    for (int i = 0; i < x; i++){
                        for (int j = 0; j < y; j++){
                            grid[j][i] = 1;
                        }
                    }
                } else if (regex_match (line, match, rotateRGX)){
                    if (match.str(1).compare("column") == 0){
                        x = stoi(match.str(3));
                        int n = 0;
                        while (n < stoi(match.str(4))){
                            tempInt = grid[5][x];
                            for (int i = 4; i > -1; --i){
                                grid[i+1][x] = grid[i][x];
                            }
                            grid[0][x] = tempInt;
                            n++;
                        }
                    }
                    if (match.str(1).compare("row") == 0){
                        y = stoi(match.str(3));
                        int n = 0;
                        while (n < stoi(match.str(4))){
                            int t_count = 0;
                            tempInt = grid[y][49];
                            for (int i = 48; i > -1; --i){
                                grid[y][i+1] = grid[y][i];
                            }
                            grid[y][0] = tempInt;
                            n++;
                        }
                    }
                }
                section = "";
            }
        txtFile.close();
        for (int i = 0; i < 6; i++){
            for (int j = 0; j < 50; j++){
                if (grid[i][j] == 1){
                    cout << "A";
                    num++;
                } else {
                    cout << " ";
                }
            }
        cout << endl;
        }
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
