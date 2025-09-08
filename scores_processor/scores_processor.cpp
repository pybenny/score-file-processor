#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
Program Requirements
1. Command-Line Arguments
    o The program must accept two file names as command-line arguments:
        ./scores_processor input.txt output.txt
    o input.txt: Contains student scores (one per line).
    o output.txt: The program should write the processed results here.
2. File Input (Streams)
    o Read all scores from input.txt.
    o Use dynamic memory allocation (pointers) to store the scores in an array
    (you do not know the number of scores beforehand).
        o Tip: Use the array resizable mechanism you implemented in Programming Assignment 01.
    o Stop reading when EOF (End Of File) is reached.
3. Processing (Pointer-based)
Implement the following:
    o Count the total number of scores.
    o Find the highest and lowest score.
    o Compute the average score.
    o Count how many scores are above average and how many are below average.
4. File Output (Streams)
    o Example output.txt:
    Number of scores: 20
    Highest: 98
    Lowest: 45
    Average: 72.3
    Above average: 9
    Below average: 11
5. Memory Management
    o Free all dynamically allocated memory before exiting.
Constraints
    • All array operations must use pointers/pointer arithmetic (no [] indexing).
    • You must use command-line arguments for file names (no hardcoding).
    • Handle errors:
        o Example: If input.txt does not exist, print an error and exit.
*/

//void total_scores();


int main()
{
    string file = "input.txt";
    ifstream in_file(file);

    // checking for fail to open
    if (!in_file) {

    }
    else {

    }


}

// Processing (Pointer-based) Below:

//Count the total number of scores in input.txt
//void total_scores(){}

//Find the highest and lowest scores in input.txt || maybe need 2 seperate functions for this
//void highest_and_lowest(){}

//Compute the average score in input.txt
//void compute_average(){}

//Count how many scores are above average and how many are below average || maybe need 2 seperate functions for this
//void above_below_average(){}



