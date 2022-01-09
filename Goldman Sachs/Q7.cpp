// https://practice.geeksforgeeks.org/problems/find-the-position-of-m-th-item1723/1/

class Solution {
  public:
    int findPosition(int N , int M , int K) {
        if((K+(M%N)-1)%N == 0)  return N;
        return (K+(M%N)-1)%N;
    }
};
