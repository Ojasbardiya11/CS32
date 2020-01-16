//
//  main.cpp
//  Homework4part4
//
//  Created by Ojas Bardiya on 5/27/19.
//  Copyright © 2019 Ojas bardiya. All rights reserved.
//

void listAll(const Domain* d, string path) // two-parameter overload
{
    
    if (d->subdomains().empty())
    {
        cout << path << endl;
        return;
    }
    for (vector<Domain*>::const_iterator it = d->subdomains().begin(); it != d->subdomains().end(); it++)
    {
        if (path != "")
        {
            listAll(*it, (*it)->label() + "." + path);
            
        }
        else
        {
            listAll(*it, (*it)->label() + path);
        }
    }
}
