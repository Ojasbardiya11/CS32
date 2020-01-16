//
//  Sequence.cpp
//  Assignment2
//
//  Created by Ojas Bardiya on 4/23/19.
//  Copyright © 2019 Ojas bardiya. All rights reserved.
//

#include <iostream>
#include "Sequence.h"

Sequence::Sequence() : mSize(0) //creates a dummy node such that the pointers point towards themselves
{
    head = new Node;
    head->mNext = head;
    head->mPrevious = head;
}

Sequence::Sequence (const Sequence& other)
{
    mSize = other.size();
    head = new Node;            // creates a dummy Node
    head->mNext = head;
    head->mPrevious = head;
    Node* ptr = other.head->mNext;   // create a pointer that points towards the first Node
    while (ptr != other.head)  // loop through the sequence
    {
        Node* temp = new Node;      // create another pointer
        temp->mVar = ptr ->mVar;    // place in the value of the current node into the pointer
        temp->mNext = head;         // make it point towards head
        temp->mPrevious = head->mPrevious;  //make it also point towards the last node
        head->mPrevious->mNext = temp;   //previous node points towards the pointer
        head->mPrevious = temp;          // head's previous points towards the pointer
        ptr = ptr->mNext;   // move on to the next node
    }
}

Sequence::~Sequence()
{
  while ( head->mNext != head)
  {
      Node* ptr = head->mPrevious;
      ptr->mPrevious->mNext = head;
      head->mPrevious = ptr->mPrevious;
      delete ptr;
  }
  delete head;
}

Sequence& Sequence::operator=(const Sequence& rhs)
{
    if (this != &rhs)
    {
        Sequence tempseq(rhs);
        swap(tempseq);
    }
    return *this;
}

bool Sequence::empty() const
{
    bool value = false;
    if (mSize == 0)
    {
        value = true;
    }
    return (value);
}

int Sequence::size() const
{
    return (mSize);
}

int Sequence::insert(int pos, const ItemType& value)
{
    if (pos < 0 || pos > size() )
    {
        return (-1);
    }
    else if (pos == size())
    {
        Node* ptr = head->mPrevious; //create a new node that points towards the last node
        Node* temp = new Node;      // create another node
        temp->mVar = value;         //set the value of temp
        temp->mNext = head;         // new Node (temp) points to head
        temp->mPrevious = ptr;       //new Node points to p
        head->mPrevious = temp;     // head points to new Node
        ptr->mNext = temp;        // node before new Node (p) points to temp
        mSize = mSize + 1;
    }
    else if ( pos >= 0 && pos < size())
    {
        Node* ptr = head->mNext;
        Node* temp = new Node;
        for (int i = 0; i < pos; i++)  // loop through the sequence until the desired poistion is reached
        {
            ptr = ptr->mNext;
        }
        temp->mVar = value;        // set the value of temp
        temp->mNext = ptr;         //  new Node (temp) points to p
        temp->mPrevious = ptr->mPrevious;   //new Node points to node before p
        ptr->mPrevious->mNext = temp;   // node before p points to temp
        ptr->mPrevious = temp;          //p points to new Node
        mSize = mSize + 1;
    }
    return (pos);
}

int Sequence::insert(const ItemType& value)
{
    int position = 0;
    if (empty())
    {
        Node* temp = new Node; //create a new Node
        temp->mVar = value;
        temp->mPrevious = head;  // make temp point to head
        temp->mNext = head;
        head->mNext = temp;
        head->mPrevious = temp;
        mSize = mSize + 1;
        return 0;
    }
    else
    {
        int i = 0;
        Node* ptr = head->mNext;
        while ( i < size())
        {
            if (value <= ptr->mVar)
            {
                position = i;
                break;
            }
            ptr = ptr->mNext;
            i++;
            if ( i == size())
            {
                position = size();
            }
        }
    }
    insert(position, value);
    return (position);
}

bool Sequence::erase(int pos)
{
    bool value = false;
    if (pos < 0 || pos >= size())
    {
        return (value);
    }
    else
    {
        Node* ptr = head->mNext;
        for ( int i = 0; i < pos; i++)
        {
            ptr = ptr->mNext;
        }
        Node* temp = ptr;
        ptr->mPrevious->mNext = temp->mNext;
        ptr->mNext->mPrevious = temp->mPrevious;
        delete temp;
        mSize = mSize - 1;
        value = true;
    }
    return (value);
}

int Sequence::remove(const ItemType& value)
{
    int numberRemoved = 0;
    Node* ptr;
    for (ptr = head->mNext; ptr != head; ptr = ptr->mNext)
    {
        if (ptr->mVar == value)
        {
            Node* temp = ptr;
            ptr->mPrevious->mNext = temp->mNext;
            ptr->mNext->mPrevious = temp->mPrevious;
            delete temp;
            numberRemoved = numberRemoved + 1;
            mSize = mSize - 1;
        }
    }
    return (numberRemoved);
}

bool Sequence::get(int pos, ItemType& value) const
{
    bool checker = false;
    if (pos < 0 || pos >= size())
    {
        return (checker);
    }
    else
    {
        Node* ptr = head->mNext;
        int i = 0;
        while (i < pos)
        {
            ptr = ptr->mNext;
            i++;
        }
        value = ptr->mVar;
        checker = true;
    }
    return (checker);
}

bool Sequence::set(int pos, const ItemType& value)
{
    bool checker = false;
    if ( pos < 0 || pos >= size())
    {
        return (checker);
    }
    else
    {
        Node* ptr = head->mNext;
        int i = 0;
        while (i < pos)
        {
            ptr = ptr->mNext;
            i++;
        }
        ptr->mVar = value;
        checker = true;
    }
    return (checker);
}

int Sequence::find(const ItemType& value) const
{
    int position = 0;
    Node* ptr = head->mNext;
    for ( int i = 0; i < size(); i++)
    {
        if (ptr->mVar == value)
        {
            position = i;
            return (position);
        }
        ptr = ptr->mNext;
    }
    return -1;
}

void Sequence::swap(Sequence& other)
{
    Node* temp = other.head; //swapping the pointers
    other.head = this->head;
    this->head = temp;
    
    int tempSize = other.mSize;  //swapping the sizes
    other.mSize = this->mSize;
    mSize = tempSize;
}

void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result)
{
    int count = 0;
    int position1 = 0;
    int position2 = 0;
    ItemType var1, var2;
    Sequence temp(result); // prevents aliasing
    while (!temp.empty()) // erases all the items in temp result currently
    {
        temp.erase(0);
    }
    if (seq1.size() == 0 )
    {
        temp = seq1;
    }
    if (seq2.size() == 0)
    {
        temp = seq2;
    }
    while (position1 != seq1.size() || position2 != seq2.size())
    {
        if (seq1.get(position1, var1))
        {
            seq1.get(position1, var1);
            temp.insert(count, var1);
            position1 = position1 + 1;
            count = count + 1;
        }
        
        if (seq2.get(position2, var2))
        {
            seq2.get(position2, var2);
            temp.insert(count, var2);
            position2 = position2 + 1;
            count = count + 1;
        }
    }
   
    result = temp;
}

int subsequence(const Sequence& seq1, const Sequence& seq2)
{
    int start = 0;
    ItemType val1, val2;
    bool issubSequence = false;
    if (seq2.size() > seq1.size())
    {
        return -1;
    }
    if (seq2.size() == 0)
    {
        return -1;
    }
    for (int i = 0; i < seq1.size(); i++)
    {
        seq1.get(i, val1);
        seq2.get(0, val2);
        if (val1 == val2)
        {
            start = i;
            int j = 0;
            int currentStart = i;
            while ( j < seq2.size())
            {
                seq2.get(j, val2);
                seq1.get(currentStart, val1);
                issubSequence = true;
                if (val1 != val2)
                {
                    issubSequence = false;
                    break;
                }
                j++;
                currentStart++;
            }
            if (issubSequence == true)
            {
                return (start);
            }
        }
    }
    return -1;
}




