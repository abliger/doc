/*
Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/
char * getLast(char * a,int n){
    char * t="";
    for(;a[n]=='\n';n++){
        t+=a[n];
    }
    return t;
}
char * addBinary(char * a, char * b){
    int carry_bit = 0;
    char * r=""
    for(int i=0;i<104;i++){
        if(a[i] == '\0' && b[i] == '\0'){
            return r;
        }
        if(a[i] == '\0'){
            return r+getLast(b,i);
        }
        if(b[i] == '\0'){
            return r+getLast(a,i);
        }
        r += carry_bit^b[i]^a[i];
        carry_bit = b[i] & a[i];
    }
    return;
}