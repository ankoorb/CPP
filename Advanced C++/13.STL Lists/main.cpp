#include <iostream>
#include <list>
using namespace std;

int main() {

    // Create a list of int
    list<int> numbers;

    // Add items to list
    numbers.push_back(15);  // Adds element to the end
    numbers.push_back(6);
    numbers.push_front(7);  // Adds element to the front

//    //// Adding elements and erasing them from other positions in the list
//
//    // Create an iterator to the list that references first element of the list
//    list<int>::iterator it=numbers.begin();
//    it++;
//    // Inserting an element before 1
//    numbers.insert(it, 100);
//    cout << "Element: " << *it << endl;
//
//    // Deleting an element (deleting 100)
//    list<int>::iterator dit=numbers.begin();
//    dit++;
//    cout << "Element: " << *dit << endl;
//    dit = numbers.erase(dit);
//    cout << "Element: " << *dit << endl;

    for(list<int>::iterator it=numbers.begin(); it != numbers.end();){

//        // Inserting element before value 2
//        if(*it == 6){
//            numbers.insert(it, 5);
//        }

        // Erasing item with value 5
        if(*it == 6){
            // set iterator back to something that is valid.
            it = numbers.erase(it);

            /*
             * Iterator now in effect is incremented twice because iterator now points
             * to the item after the one that has been erased. Now in the `for()` the
             * iterator is incremented again it will skip an item, so increment the
             * iterator only if we do not erase something from it
             */

        }
        else
        {
            it++;
        }

    }



    // Iterating through the list
    // NOTE: index can not be used so need to use iterator
    for(list<int>::iterator it=numbers.begin(); it != numbers.end(); it++){
        cout << *it << endl;
    }


    return 0;
}

/*
 * #include <list>
 *
 * List - Similar to vector. Difference, items can be inserted into a list at the
 * beginning or the middle of the list where as in vectors items can only be inserted
 * at the end.
 *
 * In vector all the elements are stacked next to each other in the computers memory.
 *
 * List contains bunch of nodes which stores each element and those nodes are linked to
 * each other via pointers. So one node in the list has a pointer to the previous element
 * in the previous node and it also has pointer to the next node. 2 nodes in the list have
 * pointers to each other (doubly linked list). To traverse across the list need to get
 * pointer to next element, and so on so one can not just use index
 *
 * list iterator can use it++ or it--, i.e. we can only increment or decrement, and
 * it+=2 can not be used
 *
 * Inserting value to list. listObject.insert(iterator, value)
 *
 * When you erase items that an iterator refers to you invalidate the iterator
 *
 * Exercise: Use while loop to add or erase elements
 *
 * Exercise: Use binary files to implement saving/load of list data
 *
 */


/*
 * Iterator now in effect is incremented twice because iterator now points
 * to the item after the one that has been erased. Now in the `for()` the
 * iterator is incremented again it will skip an item, so increment the
 * iterator only if we do not erase something from it
 */