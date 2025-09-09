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


int main(int argc, char* argv[]) // argument count (argc), argument vector (argv)
{
    int size = 0; // tracking array size
    int capacity = 5; // starting with a 5 element capacity, that will grow
    int* sArray = new int[capacity]; // dynamic array initialization

    string line;

    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " <input.txt> <output.txt>\n";
        return 1;
    }

    ifstream in_file(argv[1]); // open input stream command line
    ofstream out_file(argv[2]); // open output stream command line

    


    // checking for fail to open
    if (!in_file) {
        cout << "ERROR: Input file has failed to open\n";
        return 1;
    }
    else {
        while (getline(in_file, line)) {
            cout << line << endl; // temporary: outputting scores in input.txt
            /*
            RUN FUNCTIONS HERE
            */
        }
    }

    in_file.close();
    delete [] sArray;
    return 0;
}


void resizable_mechanism(int*& sArray, int& size, int& capacity) {

}

//Count the total number of scores in input.txt
/*void total_scores() {
    int size = size;

    for (int i = 0; i < size; ++i) {
        
    }
} */

//Find the highest and lowest scores in input.txt || maybe need 2 seperate functions for this
//void highest_score(){}

//void lowest_score(){}

//Compute the average score in input.txt
//void compute_average(){}

//Count how many scores are above average and how many are below average || maybe need 2 seperate functions for this
//void above_average(){}

//void below_average(){}



