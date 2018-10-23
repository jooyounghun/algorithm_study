//
//  main.cpp
//  queue_test
//
//  Created by younghun joo on 2018. 10. 23..
//  Copyright © 2018년 younghun joo. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    queue<int> Q;
    /*
     queue<int> Q  //Q라는 이름의 int 요소들로 구성된 큐 선언
     
     
     
     Q.push(값)  //큐 Q에 값을 넣는다. 리턴 값이 없다.
     
     
     
     Q.pop()  //큐 Q의 front를 삭제한다. 리턴 값이 없다.
     
     
     
     Q.front()  //큐 Q의 front를 리턴한다. front는 삭제되지 않는다. (peek기능)
     
     
     
     Q.back()  //큐 Q의 back를 리턴한다. back는 삭제되지 않는다. (peek기능)
     
     
     
     Q.size()  //큐 Q의 크기(구성 요소 갯수)를 리턴한다.
     
     
     
     Q.empty()  //큐 Q가 비어있으면(요소가 없으면) 를 1(True)리턴하고 비어있지 않으면 0(False)를 리턴한다.
     
     
     
     출처: http://woodforest.tistory.com/79 [나무 숲]
     */
    
    Q.push(1);
    
    Q.push(2);
    
    for(int i=0; i<Q.size(); i++)
    {
        cout << Q.front() << endl;
        cout << Q.back() << endl;
    }
    
    Q.pop();
    
    for(int i=0; i<Q.size(); i++)
    {
        cout << Q.front() << endl;
        cout << Q.back() << endl;
    }
    Q.pop();
    cout << Q.empty() << endl;
    
    return 0;
}
