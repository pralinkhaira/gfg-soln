//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {

       string str1="",str2="",str3="",str4="";
       bool chk1=false,chk2=false,chk3=false;
       for(int i=0;i<str.size();i++){
           if(str[i]==' ') continue;
           if(str[i]=='/' && chk1 == false) {
               chk1 = true;
               continue;
           }
           if(chk1 == false) str1+=str[i];
           if(str[i] == ',') {
               chk2 = true;
                continue;
               
           }
           if(chk1 == true && chk2 == false) str2+= str[i];
           if(chk2 == true && str[i]== '/'){ 
               chk3 = true;
               continue;
           }
           if(chk2 == true && chk3 == false) str3+= str[i];
           if(chk3 == true) str4+=str[i];
       }
       
      int a,b,c,d;
      a = stoi(str1);
      b = stoi(str2);
      c= stoi(str3);
      d = stoi(str4);
      if(a*d > c*b) return str1+"/"+str2;
      else if(a*d == c*b) return "equal";
      else return str3+"/"+str4;
    }
};

//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends