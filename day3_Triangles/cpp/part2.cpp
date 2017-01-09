#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

void function(){
    string line;
    string item;
    std::vector<std::vector<int>> values(3, std::vector<int> (3,0));
    int count = 0;
    int n = 0;
    ifstream f ("input.txt");
    if (f.is_open()){
        int j = 0;
        while(getline(f, line)){
            std::stringstream ssin(line);
            for (int i = 0; i < 3; i++){
                ssin >> item;
                values[i][j] = stoi(item);
            }
            j++;
            if (j > 2){
                for (int i = 0; i < 3; i++){
                    sort(values[i].begin(), values[i].end());
                    if(values[i][0] + values[i][1] > values[i][2]){
                        count++;
                    }
                }
                j = 0;
            }
        }
        f.close();
    } else {
        cout << "Can not open file";
    }
    cout << count << endl;
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
