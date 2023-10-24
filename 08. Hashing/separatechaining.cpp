#include "SeparateChaining.h"
#include <iostream>
using namespace std;


/**
 * Internal method to test if a positive number is prime.
 * Not an efficient algorithm.
 */
bool isPrime(int n) {
    if(n == 2 || n == 3)
        return true;

    if(n == 1 || n % 2 == 0)
        return false;

    for(int i = 3; i * i <= n; i += 2)
        if(n % i == 0)
            return false;
    return true;
}

/**
 * Internal method to return a prime number at least as large as n.
 * Assumes n > 0.
 */
int nextPrime(int n) {
    if(n % 2 == 0)
        ++n;
    
    for(; !isPrime(n); n += 2);
    
    return n;
}

/**
 * A hash routine for string objects.
 */
unsigned int hash(const string & key) {
    unsigned int  hashVal = 0;
    for(int i = 0; i < key.size(); i++) {
        hashVal = 37 * hashVal + key[i];
    }

    return hashVal;
}

/**
 * A hash routine for ints.
 */
unsigned int hash(int key) {
    return key;
}

/**
 * HashTable Function Definitions 
 */

template <typename HashedObj>
void HashTable<HashedObj>::rehash() {
    vector<list<HashedObj> > oldLists = theLists;

    // Create new double-sized, empty table
    theLists.resize(nextPrime(2 * theLists.size()));
    makeEmpty();
    currentSize = 0;
    for (int i = 0; i < oldLists.size();i++) {
        while (oldLists[i].size()) {
            insert(oldLists[i].front());
            oldLists[i].pop_front();
        }
    }
}

template <typename HashedObj>
unsigned int HashTable<HashedObj>::myhash(const HashedObj & x) const {
    static hash<HashedObj> hf;
    return hf(x) % theLists.size();
}


template <typename HashedObj>
bool HashTable<HashedObj>::contains(const HashedObj & x) const {
    const list<HashedObj> & whichList = theLists[myhash(x)];
    return find(whichList.begin(), whichList.end(), x) != whichList.end();
}

template <typename HashedObj>
void HashTable<HashedObj>::makeEmpty() {
    for (int i = 0 ; i < theLists.size(); i++) {
        theLists[i].clear();
    }
    currentSize = 0;
}

template <typename HashedObj>
bool HashTable<HashedObj>::insert(const HashedObj & x) {
    list<HashedObj> & whichList = theLists[myhash(x)];
    if (find(whichList.begin(), whichList.end(), x) != whichList.end())
        return false;
    whichList.push_back(x);

    if(++currentSize > theLists.size())
        rehash();

    return true;
}

template <typename HashedObj>
bool HashTable<HashedObj>::remove(const HashedObj & x) {

    list<HashedObj> & whichList = theLists[myhash(x)];
    typename list<HashedObj>::iterator itr = find(whichList.begin(), whichList.end(), x);

    if(itr == end(whichList))
        return false;

    whichList.erase(itr);
    --currentSize;
    return true;
}


