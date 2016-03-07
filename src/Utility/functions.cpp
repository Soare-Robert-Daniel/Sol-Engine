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


//############################ GEOMETRY & 2D SPACE {COLLISIONS,DISTANCES} ######################

// ---------------------POINT
struct point2D
{
    int x,y;
    point2D(){}
    point2D(int a,int b)
    {
        x = a;
        y = b;
    }
};
vector <point2D> pointPath;

// --------------------RECT
double dist(point2D a,point2D b)
{
    return ( sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y)*1.0)  );
}
struct Rect
{
  int x,y,width,height,minX,minY,maxX,maxY,p,area;
 
  point2D origin,v[4];
  Rect(){}
  Rect(int a,int b, int swidth, int sheight)
  {
      x = a  + width/2;
      y = b + height/2;
      width = swidth;
      height = sheight;
      minX = a;
      minY = b;
      maxX = a  + width;
      maxY = b + height;
      p = 2*(width + height);
      area = width * height;
      /*
       *  (minX,minY)   width
       *     .................
       *     .               .               
       *     .               .
       *     .     (x,y)     . height      
       *     .               .
             .               .
       *     ................. 
       *                    (maxX,maxY)
       */
       v[0].x = minX;
       v[0].y= minY;
       
       v[1].x = maxX;
       v[1].y= minY;
       
       v[2].x = minX;
       v[2].y= maxY;
       
       v[3].x = maxX;
       v[3].y= maxY;
       
       origin.x = x;
       origin.y = y;
       
  }  
};

int area(point2D a, point2D b)
{
    return ( abs(a.x - b.x) * abs(a.y - b.y) );
}
bool collisions(Rect a, Rect b)
{
    int s = 0;
    for(int i = 0; i < 4; ++i)
    {
        s = area(b.v[i],a.v[0]) + area(b.v[i],a.v[1]) + area(b.v[i],a.v[2]) + area(b.v[i],a.v[3]);
        if( s == a.area)
            return true;
    }
    return false;
}
bool collisionsPoint(Rect a, point2D b)
{
    
    if(
        area(b,a.v[0]) + area(b,a.v[1]) + area(b,a.v[2]) + area(b,a.v[3]) <= a.area
    )
        return true;
    
    return false;
}


// -------------------------- CIRCLE
struct Circle
{
    int x, y,  r;
    point2D origin;
    Circle(){}
    Circle(int a, int b, int radius)
    {
        x = a;
        y = b;
        r = radius;
        origin.x = x;
        origin.y = y;
    }
};
bool collisions(Circle a, Circle b)
{
    if(dist(a.origin,b.origin) <= (a.r + b.r))
        return true;
    return false;
}
bool collisionsPoint(Circle a, point2D b)
{
    if(dist(a.origin,b) <= a.r) 
        return true;
    return false;
}

//-------------------------------------------------------

int main(int argc, char **argv)
{
	LogEvent("double: ",21321.21321,1);
  LogEvent("string: ","uirheirhiehrihre",1);
  LogEvent("stuff ", logPow(2.5,3),1);
  return 0;
}
