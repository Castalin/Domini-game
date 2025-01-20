#ifndef I_FINDOPTIMAL_H
#define I_FINDOPTIMAL_H

//interface for strategy pattern
// we may implement many AI with different algorithms of finding optimal

class I_findOptimal
{
public:
    I_findOptimal();
    virtual ~I_findOptimal();

    virtual void findOptimal() = 0;
};

#endif // I_FINDOPTIMAL_H
