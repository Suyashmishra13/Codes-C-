#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int MAXIMUM = 151;

int main()
{
    ifstream inFile("revegetate.in");
    ofstream outFile("revegetate.out");

    int grassA[MAXIMUM];
    int grassB[MAXIMUM];

    // stores the identity of adjacent vertices
    int G[MAXIMUM] = {0};

    int n, m;
    inFile >> n >> m;

    for (int x = 0; x < m; x++)
    {
        inFile >> grassA[x] >> grassB[x];

        // put the smaller in A, the larger in B
        if (grassA[x] > grassB[x])
        {
            swap(grassA[x], grassB[x]);
        }
    }

    for (int i = 1; i <= n; i++)
    { // for each vertex
        int j;
        for (j = 1; j <= 4; j++)
        { // check which colors are free
            bool ok = true;
            for (int k = 0; k < m; k++)
            {
                if (grassB[k] == i && G[grassA[k]] == j)
                {
                    ok = false;
                }
            }
            if (ok)
            {
                break;
            }
        }
        G[i] = j;
        outFile << j;
    }
    outFile << endl;

    inFile.close();
    outFile.close();

    return 0;
}
