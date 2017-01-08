#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>

#include <sys/time.h>
typedef unsigned long long timestamp_t;

static timestamp_t
get_timestamp ()
{
  struct timeval now;
  gettimeofday (&now, NULL);
  return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
}

using namespace std;
int run(vector<char>& finalWord){
    //load data
    vector<vector<char>> letters(8, vector<char> (1000, '-'));
    string line;
    ifstream f ("input.txt");
    int n = 0;
    if (f.is_open()){
        while(getline(f, line)){
            for (int i = 0; i < line.size(); ++i){
                letters[i][n] = line[i];
            }
            n++;
        }
    }
    f.close();
    //find most common in each line
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    int counts_old = 0;
    int counts_new = 0;
    for (int i = 0; i < 8; ++i){
        for (int j = 0; j < 26; ++j){
            counts_new = count( letters[i].begin(),
                                letters[i].end(),
                                alphabet[j]);
            if (counts_new > counts_old){
                finalWord[i]  = alphabet[j];
                counts_old = counts_new;
            }
        }
        counts_old = 0;
    }
}

int main(){
    vector<char> finalWord (8, '-');
    int counts = 1000;
    double secs;
    double ave = 0.0;
    timestamp_t t0 = get_timestamp();
    timestamp_t t1 = get_timestamp();
    for (int i = 0; i < counts; ++i){
        t0 = get_timestamp();
        run(finalWord);
        t1 = get_timestamp();
        secs = (t1 - t0) / 1000000.0L;
        ave += secs;
    }
    ave = ave/counts;
    //output solution
    for (int i = 0; i < 8; ++i){
        cout << finalWord[i];
    }
    cout << endl;
    cout << ave << " seconds" <<endl;
}
