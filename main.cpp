#include <iostream>
#include <stdlib.h>
#include <cmath>
#include "function.h"

int main(){

    const double pi = 3.14159;

    const int recLength = 50000, recWieth = 50000;
    const double center[] = {recLength / 2, recWieth / 2};
    const double radius = recLength / 2;
    double randomPosition_X, randomPosition_Y;
    double distance;

    double insideCircle = 0, outsideCircle = 0;

    double piGuess;
    int i = 0;

    while(true){
        randomPosition_X = rand() % recLength;
        randomPosition_Y = rand() % recWieth;

        distance = checkDistanceFromCenter(randomPosition_X, randomPosition_Y, center[0], center[1]);

        if (distance > radius){
            outsideCircle++;
        } else{
            insideCircle++;
        }

        piGuess = 4 * (insideCircle / (outsideCircle + insideCircle));
    
        i++;
        
        if (i == 10000000){
            std::cout << piGuess << std::endl;
            i = 0;
        }

        if (piGuess == pi){
            std::cout << "Done";
            break;
        }
    }

    return 1;
}

double checkDistanceFromCenter(double random_x, double random_y, double center_x, double center_y){
    // d = sqrt((x2 - x1)^2 + (y2 - y1)^2)
    double distance = sqrt(pow(random_x - center_x, 2) + pow(random_y - center_y,2));

    return distance;
}