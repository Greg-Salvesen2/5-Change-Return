//
//  main.cpp
//  5 Change Return
//
//  Created by Greg Salvesen on 11/17/16.
//  Copyright © 2016 DVS. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>

float roundToHundredths(float num) {
    return floor((num * 100) + 0.5) / 100;
}

// Formats the change needed properly and generates a string.
std::string formatChangeLog(std::vector<int> changeBreakdown) {
    std::vector<std::string> changeNames = std::vector<std::string>({"$100 bill", "$50 bill", "$20 bill", "$10 bill", "$5 bill", "$1 bill", "quarter", "dime", "nickel", "penny"});
    
    std::string finalString = "";
    bool printed = false;
    for(int i = 0; i < changeBreakdown.size(); i++) {
        if(changeBreakdown[i] != 0) {
            std::stringstream changeStr;
            changeStr << changeBreakdown[i];
            if(printed) {
                finalString += ", ";
            }
            if(i == 9) {
                if(changeBreakdown[i] == 1) {
                    finalString += changeStr.str() + " penny";
                } else if(changeBreakdown[i] > 1) {
                    finalString += changeStr.str() + " pennies";
                }
            } else {
                finalString += changeStr.str() + " " + changeNames[i];
                if(changeBreakdown[i] > 1) {
                    finalString += "s";
                }
            }
            printed = true;
        }
    }
    
    return  finalString;
}

// Calculates the amount of each type of bill and coin the customer can expect, and returns it as a vector
std::vector<int> properChange(float changeNeeded) {
    // Initialize the change vector, and the denominations vector, which keeps track of the different denominations that can be given back to the customer
    int changeInCents = int(changeNeeded * 100);
    std::vector<int> change = std::vector<int>(10);
    
    std::vector<int> denomination = std::vector<int>({10000, 5000, 2000, 1000, 500, 100, 25, 10, 5, 1});
    
    int curDenom = 0;
    
    
    // While the change needed is greater than 0 we take away the greatest denomination that's less than or equal to the change needed and increase the amount of change of that type.
    while(changeInCents > 0) {
        if(changeInCents >= denomination[curDenom]) {
            int denomCount = changeInCents / denomination[curDenom];
            change[curDenom] = denomCount;
            changeInCents -= denomination[curDenom] * denomCount;
        }
        curDenom++;
    }
    
    return change;
}

int main(int argc, const char * argv[]) {
    std::cout << "This program will calculate the amount of change you can expect given a cost of items and amount handed over." << std::endl;
    
    float itemCost = 0.0;
    float amountGiven = 0.0;
    
    std::cout << "Enter the cost of the items purchased: ";
    std::cin >> itemCost;
    std::cout << "Enter how much was handed to the cashier: ";
    std::cin >> amountGiven;
    
    // Converts the change to a float rounded to the nearest hundredth
    float change = roundToHundredths(amountGiven - itemCost);
    
    if(change < 0) {
        // If the user offers a value less than the value needed
        std::cout << "You haven't given enough! You still owe $" << (change * -1) << "." << std::endl;
    } else if(change == 0) {
        // If the user offers exact change
        std::cout << "No change necessary, you paid the exact amount." << std::endl;
    } else {
        // If the user is owed change
        std::cout << "You're owed $" << change << " in change." << std::endl;
        
        std::vector<int> changeBreakdown = properChange(change);
        
        std::cout << "You should be given " << formatChangeLog(changeBreakdown) << "." << std::endl;
    }
    
    return 0;
}
