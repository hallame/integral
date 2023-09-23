#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

bool t = true;
int n = 1;

double  myFun(double x){                                        //given function
   return (x-1)* sin(x);
}

double Left_Rect(double a, double b, int n){                    //the method of left rectangles
   double h = (b-a)/n, sum = 0;
   for(int i = 0; i <= n-1; i++){                               //we go through the cycle from 0 to n-1 and count the areas of the rectangles and add them
       sum+= h* myFun(a+i*h);
   }
   return sum;                                                  //we return the amount of areas
}

double Right_Rect(double a, double b, int n){                   //the right rectangle method
   double h = (b-a)/n, sum = 0;
   for(int i = 1; i <= n; i++){                                 //we go through the cycle from 1 to n and count the areas of the rectangles and add them up
       sum+= h* myFun(a+i*h);
   }
   return sum;
}

double Trapezoid(double a, double b, int n){                    //trapezoid method
   double h = (b-a)/n, sum =  myFun(a) +  myFun(b);             //initially, we set the value of sum to the sum of the  myFuns at the start and end points
   for(int i = 1; i <= n-1; i++){                               //we go through the cycle and count the value of the  myFun at each point, and multiply by 2, and add them
       sum+= 2* myFun(a+i*h);
   }
   sum *= h/2;                                                  //we multiply sum value by step et divide by 2
   return sum;                                                  //returning the received value
}

double Simpson(double a, double b, int n){                       //Simpson 's method
   double h = (b-a)/n, sum =  myFun(a) +  myFun(b);              //initially, we set the value of sum to the sum of the  myFuns at the start and end points
   for(int i = 1; i <= n-1; i++){                                //we go through the cycle and count the value of the  myFun at each point, and multiply by 2 if i is even or by 4 if i is odd, and add
       if(i%2 == 1){
           sum+= 4* myFun(a+i*h);
       }
       else{
           sum+= 2* myFun(a+i*h);
       }
   }
   sum *= h/3;                                                   //multiply the value of sum by a step and divide by 3
   return sum;
}

void print(int n, double a, double b, double i){                 // function for comparing the analytical value of the integral with approximate
   cout << setprecision(6) << n << setw(10);
   cout << i << setw(10);
   cout << Left_Rect(a,b,n) << setw(10);
   cout << Right_Rect(a,b,n) << setw(10);
   cout << Trapezoid(a,b,n) << setw(10);
   cout << Simpson(a,b,n) << setprecision(10) << endl;
}

void Min_Left(double a, double b, double i){                     //we find the minimum value of n at which the error will be less than 0.001
   //bool t = true;
   //int n = 1;

   do{                                                           //we go through the cycle until the error is less than 0.001
       if(abs(i - Left_Rect(a,b,n)) >= 0.001){
           n+=1;
       }
       else t = false;
   } while (t);
   cout << " Calculating the minimum value of N for the left rectangle method: " << endl;
   cout << (n - 2) << setw(20) << i << setw(20) << Left_Rect(a,b,n-2) << setw(20) << abs(i - Left_Rect(a,b,n-2)) << endl;
   cout << (n - 1) << setw(20) << i << setw(20) << Left_Rect(a,b,n-2) << setw(20) << abs(i - Left_Rect(a,b,n-1)) << endl;
   cout << n << setw(20) << i << setw(20) << Left_Rect(a,b,n) << setw(20) << abs(i - Left_Rect(a,b,n)) << endl;
   cout << (n + 1) << setw(20) << i << setw(20) << Left_Rect(a,b,n+1) << setw(20) << abs(i - Left_Rect(a,b,n+1)) << endl<< endl;
}

void Min_Right(double a, double b, double i){                     //we find the minimum value of n at which the error will be less than 0.001
   //bool t = true;
   //int n = 1;
   do{                                                            //we go through the cycle until the error is less than 0.001
       if(abs(i - Right_Rect(a,b,n)) > 0.001){
           n+=1;
       }
       else t = false;
   } while (t);
   cout << " Calculating the minimum value of N for the right rectangle method: " << endl;
   cout << (n - 2) << setw(20) << i << setw(20) << Right_Rect(a,b,n-2) << setw(20) << abs(i - Right_Rect(a,b,n-2)) << endl;
   cout << (n - 1) << setw(20) << i << setw(20) << Right_Rect(a,b,n-2) << setw(20) << abs(i - Right_Rect(a,b,n-1)) << endl;
   cout << n << setw(20) << i << setw(20) << Right_Rect(a,b,n) << setw(20) << abs(i - Right_Rect(a,b,n)) << endl;
   cout << (n + 1) << setw(20) << i << setw(20) << Right_Rect(a,b,n+1) << setw(20) << abs(i - Right_Rect(a,b,n+1)) << endl<< endl;
}

void Min_Trapezoid(double a, double b, double i){                 //we find the minimum value of n at which the error will be less than 0.001
   //bool t = true;
   //int n = 1;
   do{                                                            //we go through the cycle until the error is less than 0.001
       if(abs(i - Trapezoid(a,b,n)) > 0.001){
           n+=1;
       }
       else t = false;
   } while (t);
   cout << "Calculating the minimum value of N for the trapezoid method: " << endl;
   cout << (n - 2) << setw(20) << i << setw(20) << Trapezoid(a,b,n-2) << setw(20) << abs(i - Trapezoid(a,b,n-2)) << endl;
   cout << (n - 1) << setw(20) << i << setw(20) << Trapezoid(a,b,n-2) << setw(20) << abs(i - Trapezoid(a,b,n-1)) << endl;
   cout << n << setw(20) << i << setw(20) << Trapezoid(a,b,n) << setw(20) << abs(i - Trapezoid(a,b,n)) << endl;
   cout << (n + 1) << setw(20) << i << setw(20) << Trapezoid(a,b,n+1) << setw(20) << abs(i - Trapezoid(a,b,n+1)) << endl<< endl;
}

void Min_Simpson(double a, double b, double i){                      //we find the minimum value of n at which the error will be less than 0.001
   //bool t = true;
   int n = 2;
   do{                                                               //we go through the cycle until the error is less than 0.001
       if(abs(i - Simpson(a,b,n)) > 0.001){
           n+=2;
       }
       else t = false;
   } while (t);
   cout << " Calculating the minimum value of N for the Simpson method: " << endl;
   cout << (n - 4) << setw(20) << i << setw(20) << Simpson(a,b,n-4) << setw(20) << abs(i - Simpson(a,b,n-2)) << endl;
   cout << (n - 2) << setw(20) << i << setw(20) << Simpson(a,b,n-2) << setw(20) << abs(i - Simpson(a,b,n-1)) << endl;
   cout << n << setw(20) << i << setw(20) << Simpson(a,b,n) << setw(20) << abs(i - Simpson(a,b,n)) << endl;
   cout << (n + 2) << setw(20) << i << setw(20) << Simpson(a,b,n+2) << setw(20) << abs(i - Simpson(a,b,n+2)) << endl<< endl;
}

int main() {
   int n;
   cout<<"Enter N: ";
   cin >> n;
   cout << endl;
   double a, b, intgrl;
   a = -1;
   b = 1;
   intgrl = 0.6023373578795135;                                                                           // exact value of integral
   cout << "Comparison of the analytical value of the integral with approximate: " << endl;
   print(n, a, b, intgrl);
   print(2*n, a, b, intgrl);
   print(5*n, a, b, intgrl);
   print(10*n, a, b, intgrl);
   cout << endl;
   Min_Left(a, b, intgrl);
   cout << endl;
   Min_Right(a, b, intgrl);
   cout << endl;
   Min_Trapezoid(a, b, intgrl);
   cout << endl;
   Min_Simpson(a, b, intgrl);
   return 0;
}
