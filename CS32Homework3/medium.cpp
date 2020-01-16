//
//  main.cpp
//  Homework3part1
//
//  Created by Ojas Bardiya on 5/10/19.
//  Copyright © 2019 Ojas bardiya. All rights reserved.
//

class Medium    //base class
{
    public:
    Medium(string id);                  // constructor
    string id() const;                // non-virtual
    virtual string connect() const = 0;        // pure virtual
    virtual string transmit(string s) const; // virtual
    virtual ~Medium();                   // destructor
    
    private:
    string m_id;
};

class Phone : public Medium
{
    public:
    Phone(string number, CallType r);
    virtual string connect() const;
    virtual string transmit(string s) const;
    virtual ~Phone();
    
    private:
    CallType m_Calltype;
};

class TwitterAccount : public Medium
{
    public:
    TwitterAccount(string account);
    virtual string connect() const;
    virtual ~TwitterAccount();
};

class EmailAccount : public Medium
{
    public:
    EmailAccount(string accountname);
    virtual string connect() const;
    virtual ~EmailAccount();
};


Medium::Medium(string id) : m_id(id)
{

}

string Medium::id() const
{
    return m_id;
}

string Medium::transmit(string s) const
{
    return ("text: " + s);
}

Medium::~Medium()
{
    
}

Phone::Phone(string number, CallType r) : Medium(number), m_Calltype(r)
{
   
}

string Phone::connect() const
{
    return ("Call");
}

string Phone::transmit(string s) const
{
    if (m_Calltype == VOICE)
    {
        return ("voice: " + s);
    }
    else
    {
        return("text: " + s);
    }
}

Phone::~Phone()
{
    cout << "Destroying the phone " << Medium::id() << "." << endl;
}

TwitterAccount::TwitterAccount(string account) : Medium(account)
{
    
}

string TwitterAccount::connect() const
{
    return ("Tweet");
}


TwitterAccount::~TwitterAccount()
{
    cout << "Destroying the Twitter account " << Medium::id() << "." << endl;
}

EmailAccount::EmailAccount(string accountname) : Medium(accountname)
{
    
}

string EmailAccount::connect() const
{
    return ("Email");
}


EmailAccount::~EmailAccount()
{
    cout <<"Destroying the email account " << Medium::id() << "." << endl;
}



