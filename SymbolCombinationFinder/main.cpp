/*
Based of one of the question in ICPC Russia 2022 contest
Takes 2 inputs
    1. combination of numbers seperated by space
    2. value to acheive

Then programme checks if this value (second input) can be achieved by any combination of arthmetic symbols placed between given numbers (first input)

currently not integrating brackets part of question
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>


//gets input of 'double' type
void SetSingleDoubleInput(double& givenDouble, std::string invitation);

//sets element of vector of double type
void SetManyDoubleInput(std::vector<double>& givenVector, std::string invitation);

//breaks given string to vectors
std::vector<std::string> SplitStringBySpace(std::string givenString);

//checks if text is numeric
bool IsNumeric(std::string givenString);

//makes all possible combinations of 0 to 3
void GenerateSymbolCombinations(std::vector<std::vector<int>>& givenDynamicArray, unsigned int numberOfSymbols);

//Calculates expression with brackets, wrapper for primitive
double Arithmeticator(std::vector<double>& numberCombination, std::vector<int> symbolCombination, std::vector<unsigned int> bracketsCombination);

//Calculates result of given expression
double ArithmeticatorPrimitive(std::vector<double> numberCombination, std::vector<int> symbolCombination);


int main()
{
    //initializing variables
    std::vector<std::vector<int>> symbolCombinations;   //dynamic array to store all combinations of arthmetic symbols
    std::vector<double> numberCombination;              //dynamic array to store number combinations
    double targettedValue;                              //value user wants to get
    //think of someway to store answer and its expression

    
    //getting user inputs
    SetManyDoubleInput(numberCombination, "Enter combination of numbers with spaces in between: ");
    SetSingleDoubleInput(targettedValue, "Enter the targetted value: ");
    
    //generating automated inputs
    GenerateSymbolCombinations(symbolCombinations, numberCombination.size());
    

    //calculations
    for (unsigned int i = 0; i < symbolCombinations.size(); i++) {

    }

    //end
    std::string dummyString;
    std::cout << "\nPress Enter to close programme...";
    std::getline(std::cin, dummyString);

    return 0;
}


//gets input of 'double' type
void SetSingleDoubleInput(double& givenDouble, std::string invitation)
{
    while (true) {
        std::string testString;
        std::cout << invitation;
        
        std::getline(std::cin, testString);
        std::cin.clear();
        std::cin.ignore();

        if (IsNumeric(testString)) {
            givenDouble = std::stod(testString);
            break;
        }
        else {
            std::cout << "\tError: >" << testString << "< isn't numeric input\n\n";
        }
    }
}

//sets element of vector of double type
void SetManyDoubleInput(std::vector<double>& givenVector, std::string invitation)
{
    while (true) {
        std::string testString;                 //string for user inputs
        std::vector<std::string> stringVector;  //vector to store pieces of string
        givenVector.clear();                    //clearing vector from any previous input attempts

        //input handling
        std::cout << invitation;
        std::getline(std::cin, testString);
        std::cin.clear();
        std::cin.ignore();

        //breaking string by spaces
        stringVector = SplitStringBySpace(testString);
        
        //checking if there are 2 or more candidates to be returned
        if(stringVector.size() > 1){
            //adding values to double vector
            for (unsigned int i = 0; i < stringVector.size(); i++) {
                if (IsNumeric(stringVector[i])) {
                    givenVector.push_back(std::stod(stringVector[i]));
                }
                else {
                    std::cout << "\tError: In given input >" << testString << "<, >" << stringVector[i] << "< isn't numeric input\n\n";
                    break;
                }
            }
        }
        else {
            std::cout << "\tError: In given input >" << testString << "< too few number combinations\n\n";
        }

        //stopping function if successful conversion
        if (givenVector.size() == stringVector.size()) {
            break;
        }
    }
}

//breaks given string to vectors
std::vector<std::string> SplitStringBySpace(std::string givenString)
{
    std::string stringPiece = "";           //string to store char until encountering space char
    std::vector<std::string> resultVector;  //vector to be returned

    //for loop that mostly stores everything to vector 
    for (unsigned int i = 0; i < givenString.size(); i++) {
        //checking if encountered space char, then storing everything written in stringPiece to a vector and resetting stringPiece 
        if (givenString[i] == ' ') {
            resultVector.push_back(stringPiece);
            stringPiece = "";
        }
        //adding char to stringPiece
        else {
            stringPiece += givenString[i];
        }
    }

    //edge case, if string didn't have space after last string piece
    if (stringPiece != "") {
        resultVector.push_back(stringPiece);
        stringPiece = "";
    }

    return resultVector;
}

//checks if text is numeric
bool IsNumeric(std::string givenString)
{
    if (givenString[givenString.size() - 1] == '.') {
        return false;
    }

    unsigned int pointCounter = 0;    //counter for points

    //checking if any char is illegal
    for (unsigned int i = 0; i < givenString.size(); i++) {
        switch (givenString[i]) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            continue;

        case '.':
            pointCounter++;
            continue;

        default:
            return false;
        }

        //checking if point char is repeated more than once
        if (pointCounter > 1) {
            return false;
        }
    }

    return true;
}

/*
generates all possible combination for '+', '-', '*' & '/' ('0', '1', '2' & '3')
any number of symbols can be generated
symbols are generated by iterating over base 4
*/
void GenerateSymbolCombinations(std::vector<std::vector<int>>& givenDynamicArray, const unsigned int numberOfSymbols)
{
    //inititalizing array with already set 0 value across all elements
    std::vector<int> preSet;

    //generating preset of required size, every element is treated as a bit of base 4
    for (unsigned int i = 0; i < numberOfSymbols; i++) {
        preSet.push_back(0);
    }


    //generating 'symbols'
    for (unsigned int i = 0; i < std::pow(4, numberOfSymbols); i++) {
        givenDynamicArray.push_back(preSet);

        preSet[numberOfSymbols - 1] += 1;
        
        /*
        checking to see if any of the bits have reached 4, if they have then resetting them to 0 and increasing next bit by 1
        */
        for (unsigned int j = numberOfSymbols - 1; j > 0; j--) {
            if (preSet[j] == 4) {
                preSet[j] = 0;
                preSet[j - 1] += 1;
            }
        }
    }
}

/*
Calculates result of given numbersand symbols
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
