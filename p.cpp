#include<iostream>

using namespace std;


int main()
{
   int n;
   cin >> n;
    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    bool ans=0;
    int index=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] == k)
        {
            ans=1;
            index = i+1;
            break;
        }
    }

    if(ans)
    {
        cout << index <<endl;
    }else{
        cout << "-1" <<endl;
    }
    return 0;
}
