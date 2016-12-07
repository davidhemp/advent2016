#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <vector>

int main(){
    std::vector<int> compass (4, 0);
    signed int currentDirection = 0;
    std::vector<std::vector<int>> visted (1000, std::vector<int> (2,0));
    visted.push_back(std::vector<int> (0,0));
    std::string inputString = "L1, R3, R1, L5, L2, L5, R4, L2, R2, R2, L2, R1, L5, R3, L4, L1, L2, R3, R5, L2, R5, L1, R2, L5, R4, R2, R2, L1, L1, R1, L3, L1, R1, L3, R5, R3, R3, L4, R4, L2, L4, R1, R1, L193, R2, L1, R54, R1, L1, R71, L4, R3, R191, R3, R2, L4, R3, R2, L2, L4, L5, R4, R1, L2, L2, L3, L2, L1, R4, R1, R5, R3, L5, R3, R4, L2, R3, L1, L3, L3, L5, L1, L3, L3, L1, R3, L3, L2, R1, L3, L1, R5, R4, R3, R2, R3, L1, L2, R4, L3, R1, L1, L1, R5, R2, R4, R5, L1, L1, R1, L2, L4, R3, L1, L3, R5, R4, R3, R3, L2, R2, L1, R4, R2, L3, L4, L2, R2, R2, L4, R3, R5, L2, R2, R4, R5, L2, L3, L2, R5, L4, L2, R3, L5, R2, L1, R1, R3, R3, L5, L2, L2, R5,";
    std::string stepString;
    std::stringstream ssin(inputString);
    int l = 1;
    while (ssin.good()){
        ssin >> stepString;
        if(stepString[0] == 'L'){
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
        int move = std::stoi(stepString.erase(0,1));
        for (int i = 0; i < move; i++){
            compass[currentDirection] += 1;
            visted[l][0] = compass[1] - compass[3];
            visted[l][1] = compass[0] - compass[2];
            l++;
        }
    }
    std::vector<int> testVector(2,0);
    bool run = true;
    int flag = 1;
    for (int i = 1; i<l; i++){
        testVector = visted[i];
        for (int j = 0; j < i; j++){
            if (testVector == visted[j] && flag == 1){
                std::cout << "First crossing @ ";
                std::cout << "x: " << testVector[0] << ", ";
                std::cout << "y: "<< testVector[1] << std::endl;

                std::cout << "Distance: ";
                std::cout <<abs(testVector[0]) + abs(testVector[1]);
                std::cout << std::endl;
                flag = 0;
            }
        }
    }
    int x = compass[1] - compass[3];
    int y = compass[0] - compass[2];
    std::cout << "Final point @ ";
    std::cout << "x: " << x << ", " << "y: " << y << std::endl;
    std::cout << "Distance: " << abs(x) + abs(y) << std::endl;
}
