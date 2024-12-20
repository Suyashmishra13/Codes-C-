
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main()
{
    freopen("cownomics.in","r",stdin);
    freopen("cownomics.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int ans = 0;
    vector<vector<char>> spotinfo(2*n,vector<char>(m));
    for(int i=0; i<2*n; i++){
        for(int j=0; j<m; j++){
            cin>>spotinfo[i][j];
        }
    }
    for(int i=0; i<m; i++){
        for(int j=i+1; j<m; j++){
            for(int k=j+1; k<m; k++){
                int p = 1;
                unordered_set<string> geneinfo;
                for(int l=0; l<n; l++){
                    string genes1(1,spotinfo[l][i]);
                    genes1+= spotinfo[l][j] + spotinfo[l][k];
                    string genes2(1,spotinfo[l][i]);
                    genes2+= spotinfo[l][k] + spotinfo[l][j];
                    string genes3(1,spotinfo[l][j]);
                    genes3+= spotinfo[l][i] + spotinfo[l][k];
                    string genes4(1,spotinfo[l][j]);
                    genes4+= spotinfo[l][k] + spotinfo[l][i];
                    string genes5(1,spotinfo[l][k]);
                    genes5+= spotinfo[l][j] + spotinfo[l][i];
                    string genes6(1,spotinfo[l][k]);
                    genes6+= spotinfo[l][i] + spotinfo[l][j];
                    geneinfo.insert(genes1);
                    geneinfo.insert(genes2);
                    geneinfo.insert(genes3);
                    geneinfo.insert(genes4);
                    geneinfo.insert(genes5);
                    geneinfo.insert(genes6);
                }
                for(int l=n; l<2*n; l++){
                    string genes1(1,spotinfo[l][i]);
                    genes1+= spotinfo[l][j] + spotinfo[l][k];
                    string genes2(1,spotinfo[l][i]);
                    genes2+= spotinfo[l][k] + spotinfo[l][j];
                    string genes3(1,spotinfo[l][j]);
                    genes3+= spotinfo[l][i] + spotinfo[l][k];
                    string genes4(1,spotinfo[l][j]);
                    genes4+= spotinfo[l][k] + spotinfo[l][i];
                    string genes5(1,spotinfo[l][k]);
                    genes5+= spotinfo[l][j] + spotinfo[l][i];
                    string genes6(1,spotinfo[l][k]);
                    genes6+= spotinfo[l][i] + spotinfo[l][j];
                    // geneinfo.insert(genes1);
                    // geneinfo.insert(genes2);
                    // geneinfo.insert(genes3);
                    // geneinfo.insert(genes4);
                    // geneinfo.insert(genes5);
                    // geneinfo.insert(genes6);
                    if(geneinfo.count(genes1) > 0){
                        p = 0; break;
                    }
                    if(geneinfo.count(genes2) > 0){
                        p = 0; break;
                    }
                    if(geneinfo.count(genes3) > 0){
                        p = 0; break;
                    }
                    if(geneinfo.count(genes4) > 0){
                        p = 0; break;
                    }
                    if(geneinfo.count(genes5) > 0){
                        p = 0; break;
                    }
                    if(geneinfo.count(genes6) > 0){
                        p = 0; break;
                    }
                }
                if(p){
                    ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
