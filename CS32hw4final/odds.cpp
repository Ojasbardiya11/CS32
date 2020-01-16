//
//  main.cpp
//  Homework4part3
//
//  Created by Ojas Bardiya on 5/27/19.
//  Copyright © 2019 Ojas bardiya. All rights reserved.
//.
void removeOdds(vector<int>& v)
{
    vector<int> tempVector;
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        if ((*it) % 2 == 0)
        {
            tempVector.push_back((*it));
        }
    }
    v = tempVector;
}

