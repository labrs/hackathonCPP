/*
 * test.cpp
 *
 *  Created on: Sep 29, 2015
 *      Author: suroy7
 */

#include <iostream> //std
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <sstream>

using namespace std;

template <typename T>
void print(vector<T> & vec) {
	cout << " # Vector Elements:" << endl;
	for(const auto &tmp:vec) std::cout<< tmp << ' ' << endl;
    cout << endl;
}

template <typename T>
T revN(T number){

	T reverse=0;
	for( ; number!= 0 ; )
	   {
	      reverse = reverse * 10;
	      reverse = reverse + number%10;
	      number = number/10;
	   }
	return reverse;
}

int main(int argc, char** argv)
{

vector<int> numbers;
vector<int> revstr;
int i=0; int num =0;
unsigned int numV=0, sumRev = 0;
string line = "";

cout << "\n Enter the Number of Cases < 10000: ";
cin >> num;

if(num < 10000) {

	 cout << "\n Enter the numbers < 5000 each : " << endl;
	  while(i++ <=num )
	  {

		  getline( cin, line);
		  std::istringstream stream(line);
		  while(stream >> numV && (numV < 5000)) //Extract integers from line
			  numbers.push_back(numV);
	  }

	  for (std::vector<int>::iterator it=numbers.begin(); it!=numbers.end(); ++it)
		*it = revN(*it);
	  numV = numbers.size();


	  for(i = 0; i < (int)numV; i += 2){
		  sumRev = numbers[i] + numbers[i+1];
		  revstr.push_back(revN(sumRev));
		  sumRev = 0;
		  }

	  //print(numbers);
	  print(revstr);

} else {
	cout << "Case Number is greater than 10000" << endl;
}

return 0;

}


