//
//  main.cpp
//  5 Change Return
//
//  Created by Greg Salvesen on 11/17/16.
//  Copyright © 2016 DVS. All rights reserved.
//

#include <iostream>
#include <cmath>

int main(int argc, const char * argv[]) {
    std::cout << "This program will calculate the amount of change you can expect given a cost of items and amount handed over." << std::endl;
    
    float itemCost = 0.0;
    float amountGiven = 0.0;
    
    std::cout << "Enter the cost of the items purchased: ";
    std::cin >> itemCost;
    std::cout << "Enter how much was handed to the cashier: ";
    std::cin >> amountGiven;
    
    float change = floor(((amountGiven - itemCost) * 100) + 0.5) / 100;
    
    if(change < 0) {
        std::cout << "You haven't given enough! You still owe $" << (change * -1) << "." << std::endl;
    } else if(change == 0) {
        std::cout << "No change necessary, you paid the exact amount." << std::endl;
    } else {
        std::cout << "You're owed $" << change << " in change." << std::endl;
    }
    
    return 0;
}
