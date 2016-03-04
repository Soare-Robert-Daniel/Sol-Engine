#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <ostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <math.h>
using namespace std;
// ###################### DEBUG TOOLS ######################
template <class T>
void LogEvent(string s,T var,bool newLine = false)
{
    ostringstream os;
    os << var;
    cout << s << os.str();
    if(newLine)
        cout << endl;
}
//----------------------------------------------------------

//##################### UTILITY FUNCTIONS ################

//*****************************
/*

	#Idea used:
    	  { (x * x)^ n/2   ,  n is even
    f(x) ={
    	  { x * (x*x)^ (n-1)/2 , n is odd

	Obs: x * (x*x)^ (n-1)/2 = x * x ^ (n-1)
*/

template <class T>
T logPow( T x, int n) // n - power , x - base
{
    if( n == 0)
        return 1;
    else
        if(n == 1)
            return x;
    if( n % 2 == 0)
        return (logPow( x , n/2 )  * logPow( x , n/2)) ;
    return x * logPow( x , n-1 ) ;
}

//*****************************

template <class T>
T min3 (T a, T b, T c)
{
	return ( (a < b? a : b) < c ? (a < b? a : b) : c); 
}

template <class T>
T max3 (T a, T b, T c)
{
	return ( (a > b? a : b) > c ? (a > b? a : b) : c); 
}

//*****************************
//-------------------------------------------------------

int main(int argc, char **argv)
{
	LogEvent("double: ",21321.21321,1);
  LogEvent("string: ","uirheirhiehrihre",1);
  LogEvent("stuff ", logPow(2.5,3),1);
  return 0;
}
