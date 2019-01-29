#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define MySqare1(x) ((x)*(x))
#define MySqare2(x) x*x
#define mySpace endl << "+++++++++++++++++++++++++++++++++++++" << endl
#define o(str) cout << str;

int countBit (int bitNumber){
    int suma=0;

    while (bitNumber!=0){
        if (bitNumber&0b1)
            suma++;
        bitNumber=bitNumber>>1;
    }
    return suma;
}

int factorial(int n){
    int suma = 1;
    for (int i=1;i<n+1;i++)
        suma*=i;
    return suma;
}

int findNumberInTable(int* tab, int valueToSearch){
    int x=*tab, index=0;
    while (valueToSearch!=x){
        index=x;
        x=*(tab+index);
    }
    return index;
}

int gapLenght(int number){
    int helpVariable=number&0b01;
    int length=0;
    int longestLength=0;

    while (0==(number&0b01))
        number=number>>1;

    while (0b0!=number){
        helpVariable = number&0b01;
        if (helpVariable==1){
            length=0;
        } else {
            length++;
            if (length>longestLength)
                longestLength=length;
        }
        number=number>>1;
    }
    return longestLength;
}

int oddOccurenceInArray(int A[], int N){
    int helpVal=0;
    for (int i=0;i<N;i++)
        helpVal=helpVal^A[i];
    return helpVal;
}

vector<int> cyclicRotation(vector<int> &A, int K){
    if (0==A.size())
        return A;

    vector<int> res = A;
    int N = A.size();

    if (K>=N){
        K%=N;
    }

    for (int i=0;i<N;i++){
        if((N-K+i)>=N){
            res[i]=A[-K+i];
        } else
            res[i]=A[N-K+i];
    }

    for (int i=0;i<N;i++)
        A[i]=res[i];

    return A;
    /*
    // Inne rozwiazania:

    rotate(A.begin(), A.begin()+N-K, A.end());
    res[(i+k)%K]=A[i];

    */
    /*
    // Roziwazanie dla struktury / tablicy
    int helpTab[N];
    struct Results * res;
    if (K>=N){
        K%=N;
    }

    for (int i=0;i<N;i++){
        if((N-K+i)>=N){
            helpTab[i]=A[-K+i];
        } else
            helpTab[i]=A[N-K+i];
    }

    for (int i=0;i<N;i++)
        res->A[i]=helpTab[i];

    return res;
    */
}

int frogJump (int X, int Y, int D){
    int numberOfJumps = ceil((Y-X)/(double)D);
    return numberOfJumps;
}

int permMissingElem (vector<int> &A){
    double sum1toN = ((A.size()+1)*(A.size()+2))/2;
    int sumVector = 0;
    for (vector<int>::iterator it=A.begin();it!=A.end();it++)
        sumVector+=*it;
    return ((int)sum1toN-sumVector);

    // Inne rozwiazania:
    /*
    int sumVector = 0;
    for (int i=0;i<A.size();i++)
       sumVector=sumVector^A[i]^(i+1);
    return sumVector^(A.size()+1);
    */
}

int tapeEquilibrium (vector<int> &A){
    int allVecElemSum = 0, leftEleSum=0, index =0;
    for (vector<int>::iterator it = A.begin();it!=A.end();it++)
        allVecElemSum+=*it;
    while (leftEleSum<((int)allVecElemSum/2)){
        leftEleSum+=A[index];
        index++;
    }
    return abs(leftEleSum-(allVecElemSum-leftEleSum));
}

int permCheck(vector<int> &A){
    int vectorElementsSum = 0;
    int helpTab[A.size()];
    int sumFrom1ToN = (A.size()*(A.size()+1))/2;

    for (int i=0;i<A.size();i++)
        helpTab[i]=0;

    for (vector<int>::iterator it=A.begin();it!=A.end();it++){
        if(helpTab[*it-1]==1)
            return 0;
        helpTab[*it-1]=1;
        vectorElementsSum+=*it;
    }

    if (vectorElementsSum==sumFrom1ToN)
        return 1;
    else return 0;
}

int frogRiverOne(int x, vector<int> &A){    // x = distance
    int seconds=0, path=0;
    int helpTab[x];
    for (int i=0;i<x;i++)
        helpTab[i]=0;

    for (vector<int>::iterator it=A.begin();it!=A.end();it++){
        seconds++;
        helpTab[*it-1]=1;
        for (int i=0;i<x;i++)
            path += helpTab[i];
        if (path==x)
            return seconds;
        else{
            path=0;
        }
    }
    return -1;
}

int missingInteger(vector<int> &A){
    //returnNumber=1;
    vector<int> B = A;
    sort(B.begin(),B.end());
    B.erase( unique(B.begin(), B.end()), B.end());
    vector<int>::iterator it = B.begin();

//    while (*it==returnNumber){
//        it++;
//        returnNumber++;
//    }
//    return returnNumber;

    for (int i=1;i<B.size()+1;i++){
        if (*it!=i)
            return i;
        else
            it++;
    }
    return *it+1;
}

int main()
{
    //Zadanie H2
    int intTab[] = {100, 200, 300};
    int * intPointer = intTab;
    cout << *(++intPointer) << endl;
    cout << *(intPointer++) << endl;
    cout << *(intPointer+1);

    //Makra - zadanie H3
    int intVal = 2;
    cout << mySpace << MySqare1(intVal+1) << endl;
    cout << MySqare2(intVal+1) << endl;
    o("MyString");
    cout << mySpace;

    //Zliczanie bitow w liczbie - Zadanie H4
    cout << "Number of bits: " << countBit(0b1001);
    cout << mySpace;

    // Zadania codlity
    // 1
    cout << "Factorial: " << factorial(5);
    cout << mySpace;

    // 2
    int intTab2[] = {2,1,3,4,5,-1};
    cout << "Index of specific value: " << findNumberInTable(intTab2, -1);
    cout << mySpace;

    // 3
    int number = 17;
    cout << "Number: " << number << " Binary: " << bitset<8>(number) << " Biggest gap: " << gapLenght(number) << mySpace;

    // 4
    int intTab3[]={9,3,10,3,10,9,7};
    cout << "Odd number in array: " << oddOccurenceInArray(intTab3,7) << mySpace;

    // 5
    vector<int> intTab4;
    for (int i=1;i<6;i++)
        intTab4.push_back(i);   // 1,2,3,4,5

    cyclicRotation(intTab4,3);
    cout << "After rotation: ";
    for (int i=0;i<intTab4.size();i++)
        cout << intTab4[i] << " ";
    cout << mySpace;

    // 6
    cout << "Number of jumps: " << frogJump(10,85,30);
    cout << mySpace;

    //7
    vector<int> intTab5;
    for (int i=1;i<6;i++)
        intTab5.push_back(i);   // 1,2,3,4,5
    intTab5.erase(intTab5.begin()+3);
    cout << "Missing element: " << permMissingElem(intTab5);
    cout << mySpace;

    //8
    vector<int> intTab6 = {3,1,2,4,3};
    cout << "Minimal difference between array values: " << tapeEquilibrium(intTab6);
    cout << mySpace;

    //9
    vector<int> intTab7 = {3,2,1,4};
    vector<int> intTab8 = {4,1,2};
    cout << "Array 1 is permutation: " << permCheck(intTab7) << endl;
    cout << "Array 2 is permutation: " << permCheck(intTab8);
    cout << mySpace;

    //10
    vector<int> intTab9 = {1,3,1,4,2,3,5,4};
    cout << "Frog will jump to other side in X moves (-1 if its impossible to cross): " << frogRiverOne(5, intTab9);
    cout << mySpace;

    //11
    vector<int> intTab10 = {1,3,6,4,1,2};
    cout << "Smallest missing integer is: " << missingInteger(intTab10);
    cout << mySpace;
}
