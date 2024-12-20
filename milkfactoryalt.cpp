#include <iostream>
#include <vector>
using namespace std;
int main(){
    freopen("factory.in","r",stdin);
    freopen("factory.out","w",stdout); 

    int n;
    cin>>n;
    vector<int> indeg(n,0);
    vector<int> outdeg(n,0);
    for(int i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        outdeg[--a]++;
        indeg[--b]++;
    }  
    int ans = 0;
    int count = 0;
    for(int i=0; i<n; i++){
        if(count && outdeg[i] == 0){
            ans = -1;
            break;
        }
        if(outdeg[i] == 0 && indeg[i] > 0){
            ans = i+1;
            count++;
        }
    }
    cout<<ans<<endl;
    return 0;

}