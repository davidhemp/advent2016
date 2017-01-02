#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>

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

int run(int& num){
    string line;
    string section;
    int x;
    int y;
    ifstream txtFile("input.txt");
    smatch match;
    int tempInt;
    if(txtFile.is_open()){
        vector<vector<int>> grid(6, vector<int>(50, 0));
        regex rectRGX("rect (\\d+)x(\\d+)");
        regex rotateRGX("rotate (column|row) (x|y)=(\\d+) by (\\d+)");
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


int main(){
    int num = 0;
    int counts = 1;
    timestamp_t t0 = get_timestamp();
    timestamp_t t1 = get_timestamp();
    double secs = 0;
    double ave = 0;
    for (int i = 0; i < counts; ++i){
        num = 0;
        t0 = get_timestamp();
        run(num);
        t1 = get_timestamp();
        secs = (t1 - t0) / 1000000.0L;
        ave += secs;
    }
    ave = ave/counts;
    cout << ave << " seconds" <<endl;
    //output solution
    cout << num << endl;
}
