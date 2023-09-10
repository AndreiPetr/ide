#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void shiftRight(vector<int>& array) {
    int lastElement = array.back();
    for (int i = array.size() - 1; i > 0; i--) {
        array[i] = array[i - 1];
    }
    array[0] = lastElement;
}

void shiftLeft(vector<int>& array) {
    int firstElement = array[0];
    for (int i = 0; i < array.size() - 1; i++) {
        array[i] = array[i + 1];
    }
    array[array.size() - 1] = firstElement;
}

int main() {
    ifstream inputFile("in.txt");
    ofstream outputFile("out.txt");

    int n, m;
    inputFile >> n;
    vector<int> arrayN(n);
    for (int i = 0; i < n; i++) {
        inputFile >> arrayN[i];
    }

    inputFile >> m;
    vector<int> arrayM(m);
    for (int i = 0; i < m; i++) {
        inputFile >> arrayM[i];
    }

    shiftRight(arrayM);
    shiftLeft(arrayN);

    outputFile << m << endl;
    for (int i = 0; i < m; i++) {
        outputFile << arrayM[i] << " ";
    }
    outputFile << endl;

    outputFile << n << endl;
    for (int i = 0; i < n; i++) {
        outputFile << arrayN[i] << " ";
    }
    outputFile << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}