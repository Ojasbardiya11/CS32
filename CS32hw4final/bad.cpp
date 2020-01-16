//
//  main.cpp
//  Homework4part2
//
//  Created by Ojas Bardiya on 5/27/19.
//  Copyright © 2019 Ojas bardiya. All rights reserved.
//

// Remove the movies in li with a rating below 55 and destroy them.
// It is acceptable if the order of the remaining movies is not
// the same as in the original list.
void removeBad(list<Movie*>& li)
{
    for (list<Movie*>::iterator itr = li.begin(); itr != li.end(); itr++)
    {
        if ((*itr)->rating() < 55)
        {
            destroyedOnes.push_back((*itr)->rating());
            li.erase(itr);
        }
    }
}

