#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

/*Parameters: reference to a vector, two integers, an output file pointer)
return: none
This recursive function creates the series for a fibonacci sequence.
*/
void fibo(vector<int> &vec, int i, int series, ofstream &out);

int main(int argc, const char * argv[]) {

ofstream output("fibonacci.txt");
vector<int>vec(1,0);   // intializes the first element in the sequence 
int i = 0;
int series = stoi(argv[1]);  //converts the command line argument to an int
output << "Creating a series of " << series << " elements:" << endl;
fibo(vec, i, series, output);
return 0;

}

void fibo(vector<int> &vec, int i, int series, ofstream &out) {

    if (i < series) // exit condition for recursive call
    {
        
        if (vec.at(i) == 0) 
        {
            out << vec.at(i) << " ";
            vec.push_back(1);
            i++;
            fibo(vec, i, series, out);
        }
    
        else
        {   
            // the current element is equal to the first element plus the last
            vec.push_back(vec.at(i) + vec.at(i - 1));   
                                                      
            out << vec.at(i) << " ";                  
            i++;
            fibo(vec, i, series, out);
        }
    }
}