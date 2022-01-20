
#include <string>

#include "binary_heap.h"
#include "queue.h"
#include "Stack.h"
#include "vector.h"
#include <iostream>
#include "Person.h"

/*
Person test();

Person test() {
    Person* emily= new Person(18, "emily",12345);
    return *emily;
}
*/
/*
Person& changeName (Person& obj) {

    //cannot return
    cout << "changing name " << endl;
    obj.name = "hello";
    return obj;

}
*/
//#include "Hash_map_1.h"
//#include "Hash_map_2.h"
#include "my_union_find_1.h"
//#include "binary_heap_v2.h"
#include "binary_search_tree.h"
int main()
{
    //TODO:
    //hash table and binary seach tree need some tuning
    //avl tttree and balanced binary search trees


    binary_search_tree<int> bst;

    bst.insert(12);
    bst.insert(2);
    bst.insert(22);

    //bst.insert

    for (int i = 0; i < 10; i++) {

        bst.insert((i * i + 6 * i + 19) % 19);
    }
    std::cout << "finished" << std::endl;


    /*

    Binary_Heap_v2<int> heap;


    for (int i = 0; i < 10; i++) {
        int val = (i * i + 6 * i + 19) % 24;
        heap.insert(val);
    }


    heap.iterate();//mwahahahahah it works
    cout << "ending " << endl;
    /*
    my_vector<int> vector_testing;
    vector_testing.push_back(12);
    vector_testing.push_back(1);
    vector_testing.push_back(13);
    vector_testing.push_back(2);
    vector_testing.iterate();

    cout << vector_testing[2] << endl;

    vector_testing[2] = 4;

    cout << vector_testing[2] << endl;
    vector_testing
    /*
    Binary_Heap_v2<int> heap_test;
    heap_test.insert(12);
    */
    //my_union_find<int> temp(4);
  //  temp._union();


    /*

    unordered_map<int, Person> hash_map(2);
    hash_map.insert(12, Person(19, "Sasha", 12345));

    /*

    Binary_Heap<int> heap(8);
    heap.insert(12);
    heap.insert(4);
    heap.insert(222);

    heap.insert(0);
    heap.insert(-9);
    heap.insert(12);
    heap.insert(6);

    heap.insert(24);
    heap.insert(48);


    heap.poll();

    heap.remove(6);

    cout << "ended" << endl;

    //so when doing object = object they are copied and a new one is created
    //such as Person Maria(12, "maria", 12345);
    //Person temp = Maria
    /*
    Person Maria(12, "maria", 12345);
    //Person temp = Maria;

    Maria = Maria;

    //temp.greeting();
    //temp.name = "angela";
    //temp.greeting();

    Maria.greeting();

    Person temp = changeName(Maria);
    Maria.greeting();

    //Person passedPerson = test();
    temp.greeting();
    temp.name = "temp";
    temp.greeting();
    Maria.greeting();
    //need to touch on pass by value and return by value of objects and copy constructor


    /*




    std::cout << "the count is " << heap.getCount() << std::endl;
    /*
    test value(4);

    //int poo = value.getTemp();
    //poo = 5;
    std::cout << "inside main  " << value.getTemp() << endl;
    value.printTemp();
    */
    //std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
