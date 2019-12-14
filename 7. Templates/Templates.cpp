// Templates.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
#include "Queue.h"
using namespace std;

template<typename T>
void Print(vector<T> vec)
{
    for( auto const& value : vec )
        cout << value << '\n';
    cout << endl;
}

template<typename T>
void Sort(vector<T>& vec) 
{
    vector<T> tempVec = vec;

    for( int i = 1; i < tempVec.size(); ++i )
    {
        int i2 = i;
        while( tempVec[i2 - 1] > tempVec[i2] )
        {
            T tempVal = tempVec[i2 - 1];
            tempVec[i2 - 1] = tempVec[i2];
            tempVec[i2] = tempVal;

            i2--;
            if( i2 < 1 )
                break;
        }
    }

    vec = tempVec;
}

int main()
{
    // Template Functions
    vector<string> colours{"red", "green", "white", "blue", "orange", "green", "orange", "black", "purple"};
    vector<int> numbers{3, 180, 1, -15};

    Print(colours);
    Sort(colours);
    Print(colours);
    
    Print(numbers);
    Sort(numbers);
    Print(numbers);

    // Template Class
    Queue<string>* colourQueue = new Queue<string>(colours);
    cout << colourQueue->Size() << '\n';
    colourQueue->Put("Safron");
    cout << colourQueue->Size() << '\n';
    cout << colourQueue->Get() << '\n';
    cout << endl;

    Queue<int>* numberQueue = new Queue<int>(numbers);
    cout << numberQueue->Size() << '\n';
    numberQueue->Put(300);
    cout << numberQueue->Size() << '\n';
    cout << numberQueue->Get() << '\n';
    cout << endl;

    return 0;
}
