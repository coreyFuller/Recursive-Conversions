#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;


void calculate(vector<char>&hex, int num)
{
  int temp = 0;
  if(num == 0){return;}
  temp = num  % 16;
    if (temp < 10){hex.push_back(temp + 48);}
    else {hex.push_back(temp + 55);}
  calculate(hex, num/16);
}

void printVec(vector<char>&hex, ofstream &output)
{
  for(int i = hex.size(); i >= 0; i--)
  {
     output << hex[i];
  }
  output << endl;
}

int main(int argc, char * argv[]) {

  srand(time(0));
  ofstream output("hexadecimal.txt");
  vector<char>hex;
  
  for(int i = 0; i < rand() % 10 + 2; i++)
  {
  int num = rand() % 10000;
  calculate(hex, num);
  output << num << " in hexadecimal is: 0x";
  printVec(hex, output);
  output << endl;
  hex.clear();
  }
  return 0;
}
