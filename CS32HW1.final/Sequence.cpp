//
//  Sequence.cpp
//  CS32_code1
//
//  Created by Ojas Bardiya on 4/14/19.
//  Copyright © 2019 Ojas bardiya. All rights reserved.
//

#include "Sequence.h"
#include <iostream>

Sequence::Sequence()
{
    m_Size = 0;
}

bool Sequence::empty() const
{
    bool value = true;
    if (m_Size != 0)
    {
        value = false;
    }
    return (value);
}

int Sequence::size() const
{
    return (m_Size);
}

int Sequence::insert(int pos, const ItemType& value)
{
    int k = 0;
    if (pos < 0 || pos > size() || size() >= DEFAULT_MAX_ITEMS )
    {
        k = -1;
    }
    else
    {
        m_Size = m_Size + 1;
        if ( pos == size())
        {
            m_arr[size() - 1] = value;
        }
        else
        {
            for (int i = size() - 1; i > pos; i--)
            {
                m_arr[i] = m_arr[ i - 1];
            }
            m_arr[pos] = value;
            k = pos;
        }
    }
    return (k);
}

int Sequence::insert(const ItemType& value)
{
    int k = 0;
    int position = 0;
    if ( size() >= DEFAULT_MAX_ITEMS)
    {
        k = -1;
    }
    else
    {
        for ( int i = 0; i < size(); i++)
        {
            if ( value <= m_arr[i])
            {
                position = i;
                break;
            }
            else
            {
                position = size();
            }
        }
        m_Size = m_Size + 1;
        if (position == size())
        {
            m_arr[size() - 1] = value;
            k = position;
        }
        else if (position < size())
        {
            for ( int j = size() - 1; j > position; j--)
            {
                m_arr[j] = m_arr[j - 1];
            }
            m_arr[position] = value;
            k = position;
        }
    }
    return (k);
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
        for ( int i = pos; i < size() - 1; i++)
        {
            m_arr[i] = m_arr[i + 1];
        }
        m_Size--;
        value = true;
    }
    return (value);
}

int Sequence::remove(const ItemType& value)
{
    int count = 0;
    for ( int i = 0; i < size(); i++)
    {
        if (m_arr[i] == value)
        {
            count = count + 1;
            for (int j = i; j < size() - 1; j++)
            {
                m_arr[j] = m_arr[j + 1];
            }
            m_Size--;
            i--; // this is to make sure the next item isn't the same as the one just eliminated.
        }
    }
    return (count);
}

bool Sequence::get(int pos, ItemType& value) const
{
    bool var = false;
    if (pos < 0 || pos >= size())
    {
        return (var);
    }
    else
    {
        value = m_arr[pos];
        var = true;
    }
    return (var);
}

bool Sequence::set(int pos, const ItemType& value)
{
    bool var = false;
    if (pos < 0 || pos >= size())
    {
        return (var);
    }
    else
    {
        m_arr[pos] = value;
        var = true;
    }
    return (var);
}

int Sequence::find(const ItemType& value) const
{
    int position = 0;
    for ( int i = 0; i < size(); i++)
    {
        if (m_arr[i] == value)
        {
            position = i;
            return (position);
        }
        else
        {
            position = -1;
        }
    }
    return (position);
}

void Sequence::swap(Sequence& other)
{
    ItemType temp_arr[DEFAULT_MAX_ITEMS];
    int temp_size = DEFAULT_MAX_ITEMS;
    
    for ( int i = 0; i < m_Size; i++)
    {
        temp_arr[i] = m_arr[i]; // puts the contents of this sequence into temp_arr
    }
    temp_size = m_Size;
    
    m_Size = other.size();
    for ( int j = 0; j < other.size(); j++)
    {
        m_arr[j] = other.m_arr[j]; // puts the contents of other into this sequence
    }
    
    other.m_Size = temp_size;
    for (int k = 0; k < temp_size; k++)
    {
        other.m_arr[k] = temp_arr[k]; // the contents of temp_arr, which are identical to that of this sequence's original contents are put into other.
    }
}
