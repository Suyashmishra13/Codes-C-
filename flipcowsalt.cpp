#include <bits/stdc++.h>

using namespace std;

ifstream fin("cowtip.in");
ofstream fout("cowtip.out");

//Count # of largest rectangles of tipped cows after flip

vector<string> flip(vector<string> arr, int x, int y){
  for(int i = 0; i <= x; i++){
    for(int j = 0; j<= y; j++){
      arr[i][j]=(arr[i][j]=='1'?'0':'1');
    }
  }
  return arr;
}

bool yes(vector<string> arr, int n){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(arr[i][j] == '1') return false;
    }
  }
  return true;
}

int main() {
  int n;
  fin >> n;
  vector<string> arr;
  for(int i = 0; i < n; i++){
    string x; fin >> x; arr.push_back(x);
  }
  int answer = 0;
  bool check = yes(arr, n);
    for(int i = n-1; i >= 0; i--){
      if(check) break;
      for(int j = n-1; j >=0; j--){
        if(arr[i][j] == '1'){ 
          vector<string> newarr = flip(arr, i, j); answer++;
          arr = newarr;
        }
        check = yes(arr, n);
        if(check) break;
      }
    }
  fout << answer;
}