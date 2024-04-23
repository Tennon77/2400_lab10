#include <iomanip> 
#include <iostream> 
#include <fstream>  
using namespace std;    

/**
 *  Function:   findMin
 *              finds min val in array
 */
double findMin(double array[]);

/**
 *  Function:   findMax
 *              finds max value in array
 */
double findMax(double array[]);

/**
 *  Function:   findIndex
 *              finds element a value is stored in
 */
int findIndex(double array[], double key);



int main (){
    // variable declaration
    double prices[6];
    string parts[6];
    ifstream data1;
    ifstream data2;
    int maxIndex;
    int minIndex;
    double max;
    double min;
    int i = 0;
    double temporary_holder1;
    string temporary_holder2;

    // opens files plus error checks
    data1.open("data1.txt");
    if (data1.fail()){
        cout << "Error opening the file" << endl;
        exit(0);
    }
    data2.open("data2.txt");
    if (data2.fail()){
        cout << "Error opening file" << endl;
        exit(0);
    }

    // move data from input file to the prices array
    while (!data1.eof()){
        data1 >> temporary_holder1;
        prices[i] = temporary_holder1;
        i++;
    }
    i = 0;
    while (!data2.eof()){
        data2 >> temporary_holder2;
        parts[i] = temporary_holder2;
        i++;
    }

    // calling functions and assigning their return value to max and min variables 
    max = findMax(prices);
    min = findMin(prices);
    maxIndex = findIndex(prices, max);
    minIndex = findIndex(prices, min);

    // output
    cout << "The most expensive part is: " << parts[maxIndex] << " ($" << fixed << setprecision(2) << max << ")" << endl;
    cout << "The least expensive part is: " << parts[minIndex] << " ($" << fixed << setprecision(2) << min << ")" << endl;

    data1.close();
    data2.close();
}

double findMin(double array[]){
    double min;
    int i = 0;
    min = array[0];
    while (i < 6){
        if (array[i] < min){
            min = array[i];
        }
        i++;
    }
    return min;
}

double findMax(double array[]){
    double max;
    int i = 0;
    max = array[0];
    while (i < 6){
        if (array[i] > max){
            max = array[i];
        }
        i++;
    }
    return max;
}

int findIndex(double array[], double key){
    int i = 0;
    while (i < 6){
        if (array[i] == key){
            return i;
        }
        i++;
    }
}
