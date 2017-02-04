#include <iostream>
#include <vector>

using namespace std;

struct bot{
    int number;
    vector<int> chips;
    bot *low;
    bot *high;
};

int main(){
    vector<bot> bots(10);
    bots[1].high = &bots[0];
    bots[0].high = &bots[2];
    bots[1].number = 69;
    cout << bots[1].high->number << endl;
    cout << bots[0].high->number << endl;
}
