#include <iostream>
#include <vector>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<long long> M(N);
    long long psums = 0;
    long long ans = 0;
    M[psums] = 1;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        psums += a;
        // Remember to account for negative sums
        // if(M.find((psums%N + N)%N) !=)
        ans += (M[(psums % N + N) % N]);
        M[(psums % N + N) % N]++;
    }
    // New Logic Will need to think more on this!
    // long long ans = 0;
    // for (long long x : M)
    // {
    //     ans += x * (x - 1) / 2;
    // }
    cout << ans << endl;
}