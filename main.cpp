#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace chrono;

int main() {
    int n;

    ifstream inA("A.txt");
    ifstream inB("B.txt");

    if (!inA.is_open() || !inB.is_open()) {
        cout << "Cannot open A.txt or B.txt" << endl;
        return 1;
    }

    inA >> n;
    inB >> n;

    vector<vector<double>> mat1(n, vector<double>(n));
    vector<vector<double>> mat2(n, vector<double>(n));
    vector<vector<double>> res(n, vector<double>(n, 0.0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            inA >> mat1[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            inB >> mat2[i][j];

    inA.close();
    inB.close();

    auto t1 = high_resolution_clock::now();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                res[i][j] += mat1[i][k] * mat2[k][j];

    auto t2 = high_resolution_clock::now();
    double tsec = duration_cast<microseconds>(t2 - t1).count() / 1e6;

    ofstream outC("C.txt");
    outC << n << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            outC << fixed << setprecision(15) << res[i][j] << " ";
        outC << endl;
    }
    outC.close();

    long long ops = 2LL * n * n * n;

    cout << "Size: " << n << "x" << n << endl;
    cout << "Operations: " << ops << endl;
    cout << "Time: " << tsec << " sec" << endl;
    cout << "GFLOPS: " << (ops / 1e9) / tsec << endl;

    cout << "Verification:" << endl;
    system("python verify.py");

    return 0;
}