/*
 * LongPath.cpp
 *
 *  Created on: Sep 30, 2015
 *      Author: suroy7
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <sstream>


#define ISLAND 1000000000
#define CASE 100000

using namespace std;
typedef unsigned int uint;


template <typename T>
inline void print(vector<T> & vec) {
	for(const auto &tmp:vec) cout<< tmp << ' ' << endl;
    cout << endl;
}

template<typename T>
inline T msd(T val){
	uint msd = 0;
	while ( val >>= 1) {
		    msd++;
	}
return msd;
}

template<typename T>
inline T setBit(T val){
	uint bit = 0;
	bit = (( (uint)1 << val) - 1);
return bit;
}

int main(int argc, char** argv)
{

vector<uint> islandsN;
vector<uint> longPath;

uint num = 0;
uint numV = 0;
string line = "";

cin >> num;

if((1 <= num ) && (num <= CASE)) {

	//cout << "\n Enter numbers in range 2 < 1000000000 each : " << endl;
	  do
	  {
		  getline( cin, line);
		  istringstream stream(line);
		  if((stream >> numV) && ((2 <= numV) && (numV <= ISLAND) ))
			  islandsN.push_back(numV);
	  }while( num-- != 0 );

} else {
	cout << "Case Number is not in range 1 ≤ T ≤ 10^5 " << endl;
}

for (vector<uint>::iterator it=islandsN.begin(); it != islandsN.end(); ++it)
	longPath.push_back(setBit(msd(*it)+1));

print(longPath);

return 0;

}


