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
void load_scores(ifstream& in_file, int*& sArray, int& size, int& capacity);
void resizable_mechanism(int*& sArray, int& size, int& capacity)


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
        delete[] sArray; // exit case | delete array preventing memory leaks
        return 1;
    }
    else {
        // after loading scores, the array and it's elements will be filled and ready for multi function use
        load_scores(in_file, sArray, size, capacity); // call on load_scores(); first
        // call all other statistical functions: total, min, max, by using the values stored in the array obtained by load_scores
        // call on compute average
        // call on count_above and count_below USING compute_average function within both of those two functions
        // write all of the lines to out_file after calling on functions above
        cout << sArray;
    }

    in_file.close(); // close input file
    out_file.close(); // close output file
    delete [] sArray; // delete array
    return 0;
}

// No printing. No stats. No opening/closing files. Returns when EOF reached.
// only function that reads the file input.txt
// only function that will resize, using resizable_mechanism
// Loads all scores, if the size of the array is the same as capacity it will execute the resizable_mechanism function
void load_scores(ifstream& in_file, int*& sArray, int& size, int& capacity) {
    // TEMPORARY: might need the file input ifstream code somewhere here? maybe not
    // read the scores as numbers(tokens), not text lines.

    // TEMP: NEED to implement appending here...
    if (size == capacity) {
        resizable_mechanism(sArray, size, capacity);
        // double and pointer copy here
        // append: write at logical end, address arr + size | pointer arithmetic
    }
    ++size; // ++size;
}
// currently only grows, needs to append a value, this function scales the array making room for all scores inside input.exe
void resizable_mechanism(int*& sArray, int& size, int& capacity) {
    int newCapacity = (capacity * 2); 
    int* newArray = new int[newCapacity];

    // copy existing elements
    int* source = sArray;
    int* destination = newArray;
    int* end = sArray + size;
    while (source != end) {
        *destination++ = *source++;
    }

    // then delete the old array
    delete[] sArray; 

    sArray = newArray;
    capacity = newCapacity;
    //*(arrSize + );
}

// iterates through the array that was filled by load_scores() func, and gives the total int size; amount of values in that array
/*void total_scores() { // never resize, never read the file | only read the array | does not call load_scores, only the array that's filled
    int size = size;

    for (int i = 0; i < size; ++i) {
        
    }
} */

//Find the highest and lowest scores in input.txt || maybe need 2 seperate functions for this
//void highest_score(){} // never resize, never read the file | only read the array | does not call load_scores, only the array that's filled

//void lowest_score(){} // never resize, never read the file | only read the array | does not call load_scores, only the array that's filled

//Compute the average score in input.txt
//void compute_average(){} // never resize, never read the file | only read the array | does not call load_scores, only the array that's filled

//Count how many scores are above average and how many are below average || maybe need 2 seperate functions for this
//void above_average(){} // never resize, never read the file | only read the array | does not call load_scores, only the array that's filled

//void below_average(){} // never resize, never read the file | only read the array | does not call load_scores, only the array that's filled
