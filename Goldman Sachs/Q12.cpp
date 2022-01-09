// https://practice.geeksforgeeks.org/problems/squares-in-nn-chessboard1801/1

class Solution {
  public:
    long long squaresInChessBoard(long long N) {
        //  First approach
        long long prod = 0;
        for(long long i = 1; i <= N; i++){
            prod += (i*(2*(N-i+1) - 1));
        }
        return prod;

        // Second Approach: Can also be done making a N*N DP table

        // THird Approach simple mathematics algo
        return ((N * (N+1)/2) * (2*N + 1) / 3);
    }
};
