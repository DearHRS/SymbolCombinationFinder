/*
used for testing c++ behavior
*/


#include <iostream>
#include <vector>
#include <string>


/*

*/
void BracketGenerator();


/*
Calculates result of given numbers, symbols and brackets

recursive wrapper function, break brackets into smaller 
experssions and calls ArithmeticatorPrimitive when no more brackets left
*/
double Arthmeticator(std::vector<double> numberCombination, std::vector<int> symbolCombination, std::vector<int> bracketCombination) {

}


/*
Calculates result of given numbers and symbols
checks if there are any multiplication or division signs
    if there are then calculates them first, gets rid of the used symbol and reduces 1 space for number vector

remaining is addition and subtraction which are done by for loop

returns first element of numberVector, all calculations are stored in 0th element
*/
double ArithmeticatorPrimitive(std::vector<double> numberCombination, std::vector<int> symbolCombination) {
    /*
    calculating all multiplications and divisions, and getting rid of not required elements
    */
    bool isMultiDiv = true;     //bool to force loop that calculates and checks if multiplication and division in symbols
    while (isMultiDiv) {
        for (unsigned int i = 0; i < symbolCombination.size() && isMultiDiv; i++) {
            if (i == (symbolCombination.size() - 1)) {
                isMultiDiv = false;
            }
            if (symbolCombination[i] == 2 || symbolCombination[i] == 3) {
                if (symbolCombination[i] == 2) {
                    numberCombination[i] *= numberCombination[i + 1];
                }
                else {
                    numberCombination[i] /= numberCombination[i + 1];
                }

                //getting rid of elements that got used up in calculations already
                symbolCombination.erase(symbolCombination.begin() + i);
                numberCombination.erase(numberCombination.begin() + (i + 1));

                break;
            }
        }
    }

    //calculating rest of addition and subtractions
    for (unsigned int i = 0; i < symbolCombination.size(); i++) {
        if (symbolCombination[i] == 0) {
            numberCombination[0] += numberCombination[i + 1];
        }
        else {
            numberCombination[0] -= numberCombination[i + 1];
        }
    }

    return numberCombination[0];
}

int main(){
    std::vector<double> numberVector = {2, 2, 2, 2, 2, 2};
    std::vector<int> symbolVector = {1, 2, 2, 3, 3};

    for (unsigned int i = 0; i < symbolVector.size(); i++) {
        std::cout << numberVector[i];
        switch (symbolVector[i]){
        case 0:
            std::cout << " + ";
            break;
        case 1:
            std::cout << " - ";
            break;
        case 2:
            std::cout << " * ";
            break;
        case 3:
            std::cout << " / ";
            break;
        }
    }
    std::cout << numberVector[numberVector.size() - 1] << " = " << ArithmeticatorPrimitive(numberVector, symbolVector);

    return 0;
}


