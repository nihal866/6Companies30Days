//  https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1/?company[]=Walmart&company[]=Walmart&page=1&query=company[]Walmartpage1company[]Walmart

class Solution{
public: 
   long long int M =  1e9+7;
   long long power(int x,int n)
   {
       if(n==0) return 1;
       long long res = power(x,n/2);
       if(n%2==0)
           return ((res%M)*(res%M))%M;
       else
       {
           long long temp = ((res%M)*(res%M))%M;
           return ((temp%M)*(x%M))%M;
       }
   }
};