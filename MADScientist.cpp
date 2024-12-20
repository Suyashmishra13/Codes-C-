
#include <iostream>
using namespace std;
int main()
{
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);
    int n;
    cin>>n;
    string A;
    string B;
    cin>>A>>B;
    int count = 0;
    for(int i=0; i<n; i++){
        if(A[i] != B[i]){
            count++;
            while(A[i] != B[i]) i++;
            if(i >= n) break;
        }
    }
    cout<<count<<endl;
    return 0;
}
