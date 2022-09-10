#include <iostream>
#include <algorithm>
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

    cout << "Number of records: " << numObservations << endl;

    cout << "\nStats for rm" << endl;
    cout << "print_stats(rm) to-do" << endl;

    cout << "rm sum: " << find_sum(rm) << endl;
    cout << "rm mean: " << find_mean(rm) << endl;
    cout << "rm median: " << find_median(rm) << endl;
    cout << "rm range: " << endl;
    vector<double> rm_range = find_range(rm);
    cout << "\t low: " << rm_range.at(0) << ", high: " << rm_range.at(1) << endl;

    cout << "\nStats for medv" << endl;
    cout << "print_stats(medv) to-do" << endl;

    cout << "medv sum: " << find_sum(medv) << endl;
    cout << "medv mean: " << find_mean(medv) << endl;
    cout << "medv median: " << find_median(medv) << endl;
    cout << "medv range: " << endl;
    vector<double> medv_range = find_range(medv);
    cout << "\t low: " << medv_range.at(0) << ", high: " << medv_range.at(1) << endl;

    find_sum(medv);

    cout << "\n Covariance = " << " covar(rm, medv) to-do" << endl;
    
    cout << "\n Correlation = " << " cor(rm, medv) to-do" << endl;

    cout << "\nProgram exiting...";

    return 0;

    }

// function to find the sum of a numeric vector
double find_sum(vector<double> v) {
    double sum = 0; // The sum of the vector
    // Traverse through the whole vector adding the sum
    for(int i = 0; i < v.size(); i++) {
        sum =+ v.at(i);
    }

    // Return the sum
    return sum;
}

// function to find the mean of a numeric vector
double find_mean(vector<double> v) {
    // Get the sum of given vector and divide it by 2, return the value as the mean
    return (find_sum(v))/2;
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
    // 
    return 1;
}       

// function to compute the correlation between rm and medv
double cor(vector<double> v_rm, vector<double> v_medv);         

// function to prints the stats of the given numeric vector
void print_stats(vector<double> v);                   