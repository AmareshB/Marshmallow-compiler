//
// Created by Balachandar on 12-04-2018.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

class MyClass {
    int p;
public:
    MyClass() { p = 42; }
    MyClass( int q ) { p = q; }
    int getp() const { return p; }
    void changeState( int pp ) { p = pp; }
};

bool operator <( const MyClass& x1, const MyClass& x2 ) {
    return x1.getp() < x2.getp();
}
bool operator ==( const MyClass& x1, const MyClass& x2 ) {
    return x1.getp() == x2.getp();
}

void print( vector<MyClass> );

void print1(list<MyClass> list);

/*
int main()
{
    vector<MyClass> vec;
    list<MyClass> lis;
    MyClass x1( 2 );
    MyClass x2( 3 );
    MyClass x3( 5 );
    vec.push_back( x1 );
    vec.push_back( x3 );
    vec.push_back( x2 );
    lis.push_back(x1);
    print(vec);
    lis.push_back( x3 );
    lis.push_back( x2 );
    x2.changeState( 1000 );
    print(vec);
    print1(lis);

    //vector elements initialized by MyClass's no-arg      constructor:
   */
/* vector<MyClass> vec_2( 5 );
    print( vec_2 );
    vec_2.resize( 7 );
    print( vec_2 );

    //uninitialized increase in the vector capacity:
    vec_2.reserve( 10 );
    cout << vec_2.capacity() << endl;
    print ( vec_2 );

    cout << vec_2[ 8 ].getp() << endl;

    vec_2[0] = MyClass(12);
    vec_2[1] = MyClass(36);
    vec_2[2] = MyClass(3);
    vec_2[3] = MyClass(56);
    vec_2[4] = MyClass(2);

    sort( vec_2.begin(), vec_2.end() );

    print( vec_2 );

    vec_2.clear();
    print( vec_2 );
    cout << vec_2.capacity() << endl;
*//*

    return 0;
}
*/

void print1(list<MyClass> v) {
    cout << "\nvector size is: " << v.size() << endl;
    list<MyClass>::iterator p = v.begin();
    while ( p != v.end() )
        cout << (*p++).getp() << "  ";
    cout << endl << endl;

}

void print( vector<MyClass> v ) {
    cout << "\nvector size is: " << v.size() << endl;
    vector<MyClass>::iterator p = v.begin();
    while ( p != v.end() )
        cout << (*p++).getp() << "  ";
    cout << endl << endl;
}


