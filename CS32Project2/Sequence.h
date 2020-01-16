//
//  Header.h
//  Assignment2
//
//  Created by Ojas Bardiya on 4/23/19.
//  Copyright © 2019 Ojas bardiya. All rights reserved.
//

#ifndef SEQUENCE_h
#define SEQUENCE_h

#include <string>

using ItemType = std::string;

class Sequence
{
    public:
    Sequence();
    Sequence(const Sequence& other);             // copy constructor
    Sequence& operator= (const Sequence& rhs); //assignment operator
    ~Sequence();                                 //destructor
    bool empty() const;
    int size() const;
    int insert(int pos, const ItemType& value);
    int insert(const ItemType& value);
    bool erase(int pos);
    int remove(const ItemType& value);
    bool get(int pos, ItemType& value) const;
    bool set(int pos, const ItemType& value);
    int find(const ItemType& value) const;
    void swap(Sequence& other);
    
    private:
    struct Node
    {
        ItemType mVar;
        Node* mNext;
        Node* mPrevious;
    };
    
    int mSize;
    Node* head; // head pointer
};

#endif /* Sequence_h */

int subsequence(const Sequence& seq1, const Sequence& seq2);
void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result);
