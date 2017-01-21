#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

void function(){
    int num_tri = 0;
    string line;
    ifstream f ("input.txt");
    vector<int> values(3, 0);
    if (f.is_open()){
        while(getline(f, line)){
            cout << line << endl;
        }
        f.close();
        cout << num_tri << endl;
    } else {
        cout << "Can not open file";
    }
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
