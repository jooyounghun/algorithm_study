//
//  main.cpp
//  map_test
//
//  Created by younghun joo on 2018. 10. 24..
//  Copyright © 2018년 younghun joo. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    map<string, int> m;
    
    m.insert(make_pair("a",1));
    m.insert(make_pair("b",2));
    
    m["f"] = 6;
    
    if(!m.empty())
    {
        cout << "m size: " << m.size() << endl;
        
    }
    
    m.erase("b");
    m.erase(m.find("f"));
    
    cout << "m size: " << m.size() << endl;
    
    cout << "a : " << m.find("a")->second << endl;
        
    
    cout << "a count : " << m.count("a") << endl;
        
    
    cout << "traverse" << endl;
    
    for(auto it = m.begin(); it!=m.end(); it++)
    {
        cout << "key : " << it->first << " " << "value : " << it->second << endl;
    }
    
    return 0;
}
