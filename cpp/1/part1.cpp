#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

int main(){
    int coords[4] = {0, 0, 0, 0};
    signed int currentDirection = 0;
    std::string inputString = "L1, R3, R1, L5, L2, L5, R4, L2, R2, R2, L2, R1, L5, R3, L4, L1, L2, R3, R5, L2, R5, L1, R2, L5, R4, R2, R2, L1, L1, R1, L3, L1, R1, L3, R5, R3, R3, L4, R4, L2, L4, R1, R1, L193, R2, L1, R54, R1, L1, R71, L4, R3, R191, R3, R2, L4, R3, R2, L2, L4, L5, R4, R1, L2, L2, L3, L2, L1, R4, R1, R5, R3, L5, R3, R4, L2, R3, L1, L3, L3, L5, L1, L3, L3, L1, R3, L3, L2, R1, L3, L1, R5, R4, R3, R2, R3, L1, L2, R4, L3, R1, L1, L1, R5, R2, R4, R5, L1, L1, R1, L2, L4, R3, L1, L3, R5, R4, R3, R3, L2, R2, L1, R4, R2, L3, L4, L2, R2, R2, L4, R3, R5, L2, R2, R4, R5, L2, L3, L2, R5, L4, L2, R3, L5, R2, L1, R1, R3, R3, L5, L2, L2, R5,";
    std::string dictionsStringList[160];
    std::string stepString;
    std::stringstream ssin(inputString);
    int i = 0;
    while (ssin.good()){
        ssin >> dictionsStringList[i];
        ++i;
    }
    for (int j = 0; j < i; j++){
        if(dictionsStringList[j][0] == 'L'){
                --currentDirection;
                if (currentDirection < 0){
                    currentDirection = 3;
                }
        } else {
                ++currentDirection;
                if (currentDirection > 3){
                    currentDirection = 0;
                }
        }

        int move = std::stoi(dictionsStringList[j].erase(0,1));
        coords[currentDirection] += move;
    }
    int x = coords[1] - coords[3];
    int y = coords[0] - coords[2];
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    std::cout << "Distance: " << abs(x) + abs(y) << std::endl;
}
