//
//  main.cpp
//  Stack_practice
//
//  Created by younghun joo on 2018. 10. 29..
//  Copyright © 2018년 younghun joo. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    stack<int> S;
    
    S.push(1);
    S.push(2);
    
    cout << S.top() << endl;
    
    S.pop();
    
    cout << S.top() << endl;
    
    cout << S.size() << endl;
    
    cout << S.empty() << endl;


    
    return 0;
}
