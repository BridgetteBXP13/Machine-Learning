/***********************************************************
 * data_exploration.cpp
 * Author: Bridgette Bryant                         9/9/2022
 * 
 * Purpose: 
 * The purpose of the program was to review C++ and create a 
 * few simple functions. It processes a file named 
 * ‘Boston.csv’. It has 506 entries by default and only two 
 * columns, RM for average number of Rooms per Dwelling and 
 * MEDV for Median Value of Owner-Occupied Homes in $1000’s.
 *  It was creating on Windows using VS Code and MinGW-w64 
 * g++ compiler. It displays the sum, mean, median, range, 
 * covariance, and correlation of the data. You run the 
 * program using the terminal ‘./data_exploration’ after 
 * building it.
 * 
 * Input: 
 * The Boston.csv, a data file with 2 columns the first is
 *  RM for average number of Rooms per Dwelling and MEDV 
 * for Median Value of Owner-Occupied Homes in $1000’s. It 
 * takes no other input, the spreadsheet may be adjusted, 
 * however, if changed layout/context wise it will make the
 *  program fail or become useless with its output. 
 * 
 * Output:
 * Data Exploration> ./data_exploration
 * Opening file 'Boston.csv'.    
 * Reading line 1
 * heading: rm,medv
 * new length 506
 * Closing file 'Boston.csv'.    
 * Number of records: 506        
 * 
 * Stats for rm
 * Sum: 3180.03
 * Mean: 6.28463
 * Median: 6.209
 * Range:  Low: 3.561, High: 8.78
 * 
 * Stats for medv
 * Sum: 11401.6
 * Mean: 22.5328
 * Median: 21.2
 * Range:  Low: 5, High: 50      
 * 
 * Covariance = 4.49345      
 * 
 * Correlation = 0.69536
 * 
 * Program exiting...
 * 
 * Functions:
 * 
 * main: This function takes the basic arguments from the
 *  terminal but doesn’t do anything with them. It uses 
 * an input file stream to read the ‘Boston.csv’ line by 
 * line, filling up two double type vectors for RM and 
 * MEDV. It verifies the file can be opened and will 
 * continue reading until the last line, if it cannot be 
 * opened the program will print an error message and 
 * return -1. Then it will close the file. It will tell 
 * the user when it is reading, the heading of the given 
 * file, the number of observations read, and when it is 
 * closing the file. It will then give the display shown 
 * above for the stats by calling the print_stats function
 *  for RM and MEDV. Then it will print the covariance 
 * with the covar function and print the correlation with 
 * the cor function. Then it will exit the program and 
 * return 0 on a successful end. 
 * find_sum: This function takes a double type vector and 
 * adds all of the values together and then returns the 
 * sum as a double type.
 * find_mean: This function takes a double type vector and
 *  calls the find_sum function, divides it by two, and 
 * returns the mean as a double type.
 * find_median: This function takes a double type vector, 
 * then sorts it in increasing order, then it will take the 
 * middle element, subtracting 1 from the vector’s size is 
 * odd, and returns the median as a double type.
 * find_range: This function takes a double type vector, it
 *  creates another double type vector with size 2. It will 
 * hold the minimum and maximum from the given vector. It 
 * finds the minimum and sets it as the first value of the 
 * range vector, then it finds the maximum and sets it as 
 * the second value of the range vector. The function then 
 * returns the range vector.
 * covar: This function takes the RM vector and MEDV vector, 
 * then calculates the covariance between the RM and MEDV 
 * data using the find_mean function. It then returns the 
 * calculated covariance as a double.
 * cor: This function takes the RM vector and MEDV vector, 
 * then calculates the correlation between the RM and MEDV 
 * data using the find_mean function. It then returns the 
 * calculated correlation as a double.
 * print_stats: This function takes a double type vector and 
 * prints the sum, using the find_sum function. Prints the 
 * mean, using the find_mean function. Prints the median, 
 * using the find_median function. Prints the range, low 
 * then high, using the find_range function. This function
 *  doesn’t return anything.
 * 
 * *********************************************************/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

double find_sum(vector<double>);                    // function to find the sum of a numeric vector
double find_mean(vector<double>);                   // function to find the mean of a numeric vector
double find_median(vector<double>);                 // function to find the median of a numeric vector
vector<double> find_range(vector<double>);          // function to find the range of a numeric vector
double covar(vector<double>, vector<double>);       // function to compute the covariance between rm and medv
double cor(vector<double>, vector<double>);         // function to compute the correlation between rm and medv
void print_stats(vector<double>);                   // function to prints the stats of the given numeric vector

int main(int argc, char** argv)
{
    ifstream inFS;  // Input file stream
    string line;
    string rm_in, medv_in;
    const int MAX_LEN = 1000;
    vector<double> rm(MAX_LEN);
    vector<double> medv(MAX_LEN);

    // Try to open file
    cout << "Opening file \'Boston.csv\'." << endl;

    inFS.open("Boston.csv");
    if (!inFS.is_open()) {
        // We couldn't open the file 'Boston.csv'
        cout << "Could not open file \'Boston.csv\'." << endl;
        return 1; // 1 indicates error
    }

    // Can now use inFS stream like cin stream
    // Boston.csv should contain two doubles

    cout << "Reading line 1" << endl;
    getline(inFS, line); // Reads the first line (Boston.csv heading)

    // echo heading
    cout << "heading: " << line << endl;
    
    // The number of observations in our data set
    int numObservations = 0;
    while (inFS.good()) {
        // Gets the rm (1st column separated by ',')
        getline(inFS, rm_in, ',');
        // Gets the medv (2nd column separated by '\n' aka newline)
        getline(inFS, medv_in, '\n');

        rm.at(numObservations) = stof(rm_in);
        medv.at(numObservations) = stof(medv_in);

        numObservations++;
    }

    // Reset the size of the input vectors to the size of observations
    rm.resize(numObservations);
    medv.resize(numObservations);

    cout << "new length " << rm.size() << endl;

    // We are finished reading the file so we will close it
    cout << "Closing file \'Boston.csv\'." << endl;
    inFS.close();

    // Print info out to the user
    cout << "Number of records: " << numObservations << endl;

    // Print the stats for rm
    cout << "\nStats for rm" << endl;
    print_stats(rm);

    // Print stats for medv
    cout << "\nStats for medv" << endl;
    print_stats(medv);

    // Print the corvariance
    cout << "\n Covariance = " << covar(rm, medv) << endl;
    // Print the correlation
    cout << "\n Correlation = " << cor(rm, medv) << endl;
    
    cout << "\nProgram exiting...";
    // Exit the program
    return 0;

    }

// function to find the sum of a numeric vector
double find_sum(vector<double> v) {
    double sum = 0; // The sum of the vector
    // Traverse through the whole vector adding the sum
    for(int i = 0; i < v.size(); i++) {
        sum += v.at(i);
    }

    // Return the sum
    return sum;
}

// function to find the mean of a numeric vector
double find_mean(vector<double> v) {
    // Get the sum of given vector and divide it by the number of instances, return the value as the mean
    return (find_sum(v))/v.size();
}

// function to find the median of a numeric vector
double find_median(vector<double> v) {
    // Arrange vector in numerical order from least to greatest
    sort(v.begin(), v.end());
    // Get the median (middle) of the sorted vector and return it
    // Make sure the size is even (can't have a num.5 index)
    if(v.size()%2 == 0) {
        // Size is even
        return v.at(v.size()/2);
    }
    else {
        // Size is odd, subtract 1 to make it even
        return v.at((v.size()-1)/2);
    }
} 

// function to find the range of a numeric vector
vector<double> find_range(vector<double> v) {
    // Set the vector to hold the range values
    vector<double> v_range(2);
    // Set the minimum range
    v_range.at(0) = *min_element(v.begin(), v.end());
   // Set the maximum range
    v_range.at(1) = *max_element(v.begin(), v.end());
    
    // Return the range vector
    return v_range;
}  

// function to compute the covariance between rm and medv
double covar(vector<double> v_rm, vector<double> v_medv)
{
    // Calculate sum of (rm instance - sum of rm) * (medv instance - sum of medv)
    double corvar_sum = 0;
    for(int i = 0; i < v_rm.size() && i < v_medv.size(); i++) {
        corvar_sum += (v_rm.at(i) - find_mean(v_rm)) * (v_medv.at(i) - find_mean(v_medv));
    }

    // Return the sum / (num of instances - 1)
    // If the size of rm and medv is the same:
    if(v_rm.size() == v_medv.size()) {
        return corvar_sum / (v_rm.size() - 1);
    } // If the size of rm is smaller than medv
    else if (v_rm.size() < v_medv.size()) {
        return corvar_sum / (v_rm.size() - 1);
    } // If the size of v_medv is smaller than rm
    else {
        return corvar_sum / (v_medv.size() - 1);
    }
    
}       

// function to compute the correlation between rm and medv
double cor(vector<double> v_rm, vector<double> v_medv) {
    // Calculate the standard deviation of v_rm and v_medv
    double v_rm_sqd = 0;
    double v_medv_sqd = 0; 
    // For each instance calculate the square of the distance to the mean
    for(int i = 0; i < v_rm.size() && i < v_medv.size(); i++) {
        v_rm_sqd += pow((v_rm.at(i) - find_mean(v_rm)), 2.0);
        v_medv_sqd += pow((v_medv.at(i) - find_mean(v_medv)), 2.0);
    }

    // Divide the calculations from above by the number of instances and take the square root
    v_rm_sqd = sqrt(v_rm_sqd/(v_rm.size() - 1));
    v_medv_sqd = sqrt(v_medv_sqd/(v_medv.size() - 1));

    // Divide the covariance by the product of the two standard deviations of rm and medv
    return (covar(v_rm, v_medv) / (v_rm_sqd * v_medv_sqd));
}         

// function to prints the stats of the given numeric vector
void print_stats(vector<double> v) {
    cout << "Sum: " << find_sum(v) << endl;
    cout << "Mean: " << find_mean(v) << endl;
    cout << "Median: " << find_median(v) << endl;
    vector<double> v_range = find_range(v);
    cout << "Range: " << " Low: " << v_range.at(0) << ", High: " << v_range.at(1) << endl;
}                   