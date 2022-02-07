//  https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/

class Solution {
public:
    bool winnerOfGame(string c) {
        int a = 0,b =0;
        for(int i = 1 ; i < c.length()-1 ; i++){
		// Counting the number of 'AAA' & 'BBB'
            if( c[i] == 'A' && c[i-1] == 'A' && c[i+1] == 'A'  ){
                a++;
            }else if(c[i] == 'B' && c[i-1] == 'B' && c[i+1] == 'B' ){
                b++;
            }
        }
        if(a>b){
            return true;
        }
        return false;
    }
};