#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
using namespace std;


void binRecurse(vector<short>&v, int num)
{
    if(num == 0){return;}
    int temp = num % 2;
    v.push_back(temp);
    binRecurse(v, num/2);
}
void printVec(vector<short>&v, ofstream &output)
{
    for(int i = v.size(); i >= 0; i--)
    {
        output << v[i];
    }
    output << endl;
}

int main(int argc, char const *argv[])
{
    srand(time(0));
    vector<short>v;
    ofstream output("binary.txt");
    for(int i = 0; i < rand() % 10 + 2;i++)
    {
     int num = rand() % 100;
     binRecurse(v, num);
     output << num << " in binary is 0b";
     printVec(v, output);
     output << endl;
     v.clear();
    }
    return 0;
}
