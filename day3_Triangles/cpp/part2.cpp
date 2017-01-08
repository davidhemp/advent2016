#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

#include <sys/time.h>
typedef unsigned long long timestamp_t;

static timestamp_t
get_timestamp ()
{
  struct timeval now;
  gettimeofday (&now, NULL);
  return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
}

int main(){
    using namespace std;
    timestamp_t t0 = get_timestamp();
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
    timestamp_t t1 = get_timestamp();
    double secs = (t1 - t0) / 1000000.0L;
    cout << secs << " seconds" <<endl;
}
