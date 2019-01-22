#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void displayVector (vector<int> A) {
    cout << endl;

//    for (int i=0;i<A.size();i++)
//        cout << A[i] << " ";
//    cout << endl << endl;

    for (vector<int>::iterator it = A.begin(); it != A.end(); it++)
        cout << *it << ' ';
    cout << endl << endl;
}


int main()
{
    vector<int> vecInt;
    for (int i=0;i<10;i++)
        vecInt.push_back(i+1);

    cout << "Original vector: " << endl;
    displayVector(vecInt);

    cout << "Shift right by 1: " << endl;
    rotate(vecInt.begin(),vecInt.begin()+1,vecInt.end());
    displayVector(vecInt);

    cout << "Shift left by 1: " << endl;
    rotate(vecInt.rbegin(),vecInt.rbegin()+1,vecInt.rend());
    displayVector(vecInt);

    cout << "Shift left by 1 (other method): " << endl;
    rotate(vecInt.begin(),vecInt.begin()+vecInt.size()-1,vecInt.end());
    displayVector(vecInt);

    cout << "Remove \"8\" from vector: " << endl;
    vecInt.erase(remove(vecInt.begin(), vecInt.end(), 8), vecInt.end());
    displayVector(vecInt);
}
