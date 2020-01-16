//
//  Scorelist.cpp
//  CS32_code1
//
//  Created by Ojas Bardiya on 4/16/19.
//  Copyright © 2019 Ojas bardiya. All rights reserved.
//

#include "Scorelist.h"
#include <iostream>
#include <limits>

ScoreList::ScoreList()
{
    
}

bool ScoreList::add(unsigned long score)
{
    bool value = false;
    if ( score < 0 || score > 100)
    {
        return (value);
    }
    else
    {
        m_sequence.insert(score);
        value = true;
    }
    return (value);
}

bool ScoreList::remove(unsigned long score)
{
    bool value = m_sequence.erase(m_sequence.find(score));
    if (value)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int ScoreList::size() const
{
    return (m_sequence.size());
}

unsigned long ScoreList::minimum() const
{
    bool value = m_sequence.empty();
    unsigned long var1 = 0;
    m_sequence.get(0, var1);
    unsigned long minimumScore = var1;
    if (value)
    {
        return NO_SCORE;
    }
    else
    {
        for ( int i = 0; i < size(); i++)
        {
            unsigned long var2;
            m_sequence.get(i, var2);
            if (var2 < var1)
            {
                minimumScore = var2;
                var1 = var2;
            }
        }
    }
    return (minimumScore);
}

unsigned long ScoreList::maximum() const
{
    bool value = m_sequence.empty();
    unsigned long var1 = 0;
    m_sequence.get(0, var1);
    unsigned long maximumScore = var1;
    if (value)
    {
        return NO_SCORE;
    }
    else
    {
        for ( int i = 0; i < size(); i++)
        {
            unsigned long var2;
            m_sequence.get(i, var2);
            if (var2 > var1)
            {
                maximumScore = var2;
                var1 = var2;
            }
        }
    }
    return (maximumScore);
}
