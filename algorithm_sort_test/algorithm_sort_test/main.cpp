//
//  main.cpp
//  algorithm_sort_test
//
//  Created by younghun joo on 2018. 10. 24..
//  Copyright © 2018년 younghun joo. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>

using namespace std;

void Print(int *arr)
{
    cout << "arr[i] : ";
    for(int i=0; i<10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Print1(vector<int> &v)
{
    cout << "vector : ";
    for(int i=0; i<10; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int arr[10] = {3,7,2,4,1,0,9,8,5,6};
    Print(arr); // 정렬 전 출력
    sort(arr,arr+10);
    Print(arr); // 정렬 후 출력
    
    srand((int)time(NULL));
    
    vector<int> v;
    int n = 10;
    
    for(int i=0; i<n; i++)
    {
        v.push_back(rand()%10);
    }
    Print1(v);
    sort(v.begin(),v.end(),greater<int>()); // 내림차순
    Print1(v);
    
    
    return 0;
}
