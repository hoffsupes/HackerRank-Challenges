#include <bits/stdc++.h>
#include <cctype>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {

    int c = 0,u = 0,d = 0, vals = 0;
    for(int i = 0; i < s.length(); i++)
    {
     if( char(tolower(s[i])) == 'd' )   
     {
         d--;
         c++;
     }
     else if( char(tolower(s[i])) == 'u' )   
     {
         u++;
         c++;
     }
        if( (i!=0) && (u+d == 0) )
        {
            u = 0;
            d = 0;
            
            int m = 0,v = 0;
        
            for (int j = i - (c-1); j <= i-(c/2); j++ )
            {
            if(char(tolower(s[j])) == 'u'){m++;} else{m--;}    
            }
            
            for (int j = i-(c/2)+1; j <= i; j++ )
            {
            if(char(tolower(s[j])) == 'u'){v++;} else{v--;}
            }
            
            if ((v - m) > 0)
            {
             vals++;   
            }
            c = 0;
            
        }
    }
    
return vals;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
