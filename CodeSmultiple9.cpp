/*
 * GoldenR.cpp
 *
 *  Created on: Oct 1, 2015
 *      Author: suroy7
 */

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


#define N 10000
//#define DIV_64 0x1999999999999999A
#define MAX (100 << 1)

using namespace std;
typedef unsigned int uint;
typedef unsigned long int ulong_i;


template <typename T>
inline void print(vector<T> & vec) {
	for(const auto &tmp:vec) cout<< tmp << ' ' << endl;
	cout << endl;
}


template<typename T>
inline T mulX(T val,T times){

	T xtime = 0;

	while (times != 0)
	{
		if (times & 1)
		{
			xtime += val;
		}
		val <<= 1;
		times >>= 1;
	}

	//cout << " ## Print mulX value " << xtime << endl;
	return xtime;
}
#if 0
template<typename T>
inline ulong_i divide10(T dividend) {
	ulong_i divisor = (ulong_i)0x1999999999999999A;
	return (ulong_i) ((divisor * dividend) >> 64);
}

template<typename T>
inline T myAdd(T m, T n)
{
	T carry = m & n;
	T result = m ^ n;
	while(carry != 0)
	{
		T shiftcarry = carry << 1;
		carry = result & shiftcarry;
		result ^= shiftcarry;
	}

	return result;
}
#endif

template <typename T>
inline T digitSum(T number){

	vector<uint> sum;
	T sumN = 0;

	for( ; number != 0; )
	{
		sum.push_back(number%10);
		number /= 10;//= divide10(number);
		//cout << " ## Print div " << number << endl;
	}

	for(const auto &tmp:sum) sumN += tmp;//sumN = myAdd(sumN,tmp);
	//cout << sumN << endl;

	return sumN;
}

template<typename T>
T sumR(T numT){
	T nineM = 0, tmpM = 0;
	for(int i =0; i < 50 ;) {
		if ( ( nineM = numT - mulX((uint)9,(uint)++i )) > (numT >> 2)   )
		{
          cout << "!!!!!!!!!!!  numT nineM I numT>>2 " << numT << ' ' << nineM << ' ' << i << ' '<< (numT >> 2)<< endl;
			if ( digitSum(nineM) != digitSum(numT))
				cout << "################" << endl;
			else if (tmpM < nineM)
				tmpM = nineM;
			else
				tmpM = nineM;

		}
		else
		{
			cout << "!!!!! Previous Num is greater" << tmpM<< endl ;
			return tmpM;
		}
	}
	cout << "@@@@@@@@@@@@@ tmpM " << tmpM << endl ;
	return tmpM;
}


int main(int argc, char** argv)
{

	vector<uint> goldenN;
	uint input = 0,num = 0, numT = 0, finalS = 0;
	string line = "";

	cout << "\n Enter numbers in range 0 < A <= 120 AND  0 < N <= 10^4 : " << endl;
	getline( cin, line);
	istringstream stream(line);
	stream >> input >> num;

	if( (0 >= input ) || (input > 120) || ( 0 >= num) || ( num > N) ) {
		cout << "# Samples not in range : RE-ENTER RANGE : 0 < A <= 120 AND  0 < N <= 10^4" << endl;
	}
	else {
		cout << "A and N : " << input << ' ' << num << endl;

		goldenN.push_back(input);
		numT = (input << 2);

		for(int i=1; i <= 7 ;i++ )
		{
				finalS =sumR(numT);
				goldenN.push_back(finalS);
				numT = finalS << 2;
				cout << "@@@@@@@@@ Finals numT I : "<< finalS << ' ' << numT << ' '<< i << endl;
		}
		print(goldenN);
		cout << goldenN[num-1] <<endl;
	} // end else

return 0;

}





