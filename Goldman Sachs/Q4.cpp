// https://practice.geeksforgeeks.org/problems/run-length-encoding/1/

string encode(string src)
{     
    string s = "";
    char prev = src[0];
    int count = 0;
    for(int i = 0; i < src.size(); i++){
        if(src[i] != prev){
            s += prev;
            s += to_string(count);
            count = 0;
            prev = src[i];
        }
        if(src[i] == prev)  count++;
    }
    s += prev;
    s += to_string(count);
    return s;
}