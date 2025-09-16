#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// defining functions at the top for main
void resizable_mechanism(int*& sArray, int& size, int& capacity);
void load_scores(ifstream& in_file, int*& sArray, int& size, int& capacity);
int total_scores(int size);
int highest_score(const int* sArray, int size);
int lowest_score(const int* sArray, int size);
double compute_average(const int* sArray, int size);
int above_average(const int* sArray, int size, double average);
int below_average(const int* sArray, int size, double average);

int main(int argc, char* argv[]) // argument count (argc), argument vector (argv)
{
    int size = 0; // tracking array size
    int capacity = 5; // starting with a 5 element capacity, that will grow
    int* sArray = new int[capacity]; // dynamic array initialization

    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " <input.txt> <output.txt>\n";
        return 1;
    }

    ifstream in_file(argv[1]); // open input stream command line
    ofstream out_file(argv[2]); // open output stream command line

    // checking for fail to open input.txt
    if (!in_file) {
        cout << "ERROR: Input file has failed to open!\n";
        delete[] sArray; // exit case | delete array preventing memory leaks
        return 1;
    }

    // checking for fail to open output.txt
    if (!out_file) {
        cout << "ERROR: Output file has failed to open!\n";
        in_file.close();
        delete[] sArray; // exit case | delete array preventing memory leaks
        return 1;
    }

    // after loading scores, the array and it's elements will get filled and ready for multi function use
    load_scores(in_file, sArray, size, capacity); // call on load_scores(); first

    if (size == 0) { // checks if size == 0, exists program and outputs "no scores"
        out_file << "Number of scores: 0" << endl;
        in_file.close();
        out_file.close();
        delete[] sArray;
        return 0;
    }
    else {
        double average = compute_average(sArray, size); // defining average at the top for above_average(), below_average() use.
        out_file << "Number of scores: " << total_scores(size) << endl;
        out_file << "Highest: " << highest_score(sArray, size) << endl;
        out_file << "Lowest: " << lowest_score(sArray, size) << endl;
        out_file << "Average: " << fixed << setprecision(1) << average << endl; // average defined above
        out_file << "Above average: " << above_average(sArray, size, average) << endl;
        out_file << "Below average: " << below_average(sArray, size, average) << endl;
    }

    in_file.close(); // close input file
    out_file.close(); // close output file
    delete [] sArray; // delete array
    return 0;
}

// No printing. No stats. No opening/closing files. Returns when EOF reached.
// Only function that reads the file input.txt || Only function that will resize, using resizable_mechanism
// Loads all scores, if the size of the array is the same as capacity it will execute the resizable_mechanism function
void load_scores(ifstream& in_file, int*& sArray, int& size, int& capacity) {
    // read the scores as numbers(tokens), not text lines.
    int v; // loop value
    
    while (in_file >> v) {
        if (size == capacity) {
            resizable_mechanism(sArray, size, capacity);
        }
        // append: write at logical end, address arr + size | pointer arithmetic
        *(sArray + size) = v;
        ++size;
    }
}
// currently only grows, needs to append a value, this function scales the array making room for all scores inside input.exe
void resizable_mechanism(int*& sArray, int& size, int& capacity) {
    int newCapacity = (capacity * 2); // double capacity for new capacity
    int* newArray = new int[newCapacity];

    // copying existing elements below
    int* source = sArray;
    int* destination = newArray;
    int* end = sArray + size;
    while (source != end) {
        *destination++ = *source++;
    }

    // delete old array
    delete[] sArray; 

    sArray = newArray;
    capacity = newCapacity;
    //*(arrSize + );
}

// All functions below never resize | only read the array/size | does not call load_scores(), only the array that's filled
int total_scores(int size) { 
    return size;
}

// Finds the highest score within the array holding input.txt scores
int highest_score(const int* sArray, int size) {
    int highestNum = *sArray; // starting from first element
    for (int i = 0; i < size; i++) {
        if (*(sArray + i) > highestNum) { // derefrencing and reading each value to compare/check if it's greater
            highestNum = *(sArray + i); // storing the absolute highest value in the array
        }
    }
    return highestNum; // return the highest number
}

// Finds the lowest score within the array holding input.txt scores | similar syntax to highest_score() func
int lowest_score(const int* sArray, int size) {
    int lowestNum = *sArray; // starting from first element
    for (int i = 0; i < size; i++) {
        if (*(sArray + i) < lowestNum) { // dereferencing and reading each value to compare/check if it's less
            lowestNum = *(sArray + i); // storing the absolute lowest value in the array in highestNum
        }
    }
    return lowestNum; // return the highest number
} 

// Computes the average score in the array holding scores
double compute_average(const int* sArray, int size) {
    double sum = 0; // had set to double instead of int to prevent truncation
    double average;
    for (int i = 0; i < size; i++) {
        sum += *(sArray + i); // dereference and add each element value to sum
    }
    average = sum / size; // divide sum by the size of the array
    return average; // return the computed average
}

// Counts how many scores are above average
int above_average(const int* sArray, int size, double average) {
    int aboveCount = 0;
    for (int i = 0; i < size; i++) {
        aboveCount += (*(sArray + i) > average); // cleaner fix than running an if statement instead
    }
    return aboveCount; // returns the amount of scores above average
}

// Counts how many scores are below average
int below_average(const int* sArray, int size, double average) {
    int belowCount = 0;
    for (int i = 0; i < size; i++) {
        belowCount += (*(sArray + i) < average); // cleaner fix than running an if statement instead
    }
    return belowCount; // returns the amount of scores below average
}