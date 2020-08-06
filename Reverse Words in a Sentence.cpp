// In this code, We have to reverse the whole string but not the words.

//We take loop run till the length of the string.
//We check if the string char is equal to the space.
//If it is equal then we reverse the word run till the all the word are reversed.
//After simply we reverse the whole string.



#include <iostream>
#include<bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include<queue>
#include<unordered_map>
#define ll long long

using namespace std;
vector<string>v;

void solve(string& s)
{
    int start=0;

    for(int i=0;i<s.size();i++)
    {
        if(s[i] == ' ')
        {
            reverse(s.begin() + start,s.begin() + i);
            start = i+1;
        }
    }

    reverse(s.begin() + start,s.end());

    reverse(s.begin(),s.end());

}

int main()
{
    string s = "i like this program very much";
    solve(s);
    cout << s;
    return 0;
}
