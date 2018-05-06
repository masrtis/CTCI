// Q: a pet shelter has a strict FIFO policy. You may request the oldest dog,
// the oldest cat, or the oldest animal. Implement a data structure that mirrors
// this

#include <forward_list>
#include <stdexcept>
enum animalType
{
    cat,
    dog,
};

struct animal
{
    animalType type;
    std::string name;
    animal( animalType T, std::string n )
    {
        type = T;
        name = n;
    }
};

// The idea here will be to add animals at the tail and pop them at the head.
class AnimalList
{
private:
    std::forward_list< animal > m_list;

    // forward_list doesn't keep track of the tail node, so we'll have to do
    // that.
    std::forward_list< animal >::iterator m_tail;

    animal dequeueType( animalType T )
    {
        if( m_list.front().type == T )
            return dequeueAny();

        std::forward_list< animal >::iterator scout = m_list.begin();
        std::forward_list< animal >::iterator follow = scout;
        ++scout;

        std::forward_list< animal >::iterator end = m_list.end();
        while( scout->type != T )
        {
            if( scout == end )
                throw std::runtime_error( "" );
            ++scout;
            ++follow;
        }
        if( scout == m_tail )
        {
            m_tail = follow;
        }
        animal temp = *scout;
        m_list.erase_after( follow );
        return temp;
    }

public:
    AnimalList() { m_tail = m_list.begin(); }
    void enqueue( const animal &a )
    {
        // add one to back
        if( m_list.empty() )
        {
            m_list.push_front( a );
            m_tail =
                m_list.begin(); // needed to prevent from adding elements at 2nd
                                // from front after list has been drained
        }
        else
        {
            m_tail = m_list.insert_after( m_tail, a );
        }
    }

    animal dequeueAny()
    {
        if( m_list.empty() )
            throw std::runtime_error( "" );
        animal temp = m_list.front();
        m_list.pop_front();
        return temp;
    }

    animal dequeueCat() { return dequeueType( cat ); }

    animal dequeueDog() { return dequeueType( dog ); }

    bool empty() { return m_list.empty(); }
};

#include <iostream>
using namespace std;
int main()
{
    AnimalList AL;
    AL.enqueue( animal( dog, "dennis" ) );
    AL.enqueue( animal( dog, "david" ) );
    AL.enqueue( animal( dog, "darwin" ) );
    AL.enqueue( animal( cat, "cathy" ) );

    cout << ( AL.dequeueCat().name == "cathy" ) << endl;

    AL.enqueue( animal( dog, "drake" ) );

    cout << ( AL.dequeueAny().name == "dennis" ) << endl;
    cout << ( AL.dequeueDog().name == "david" ) << endl;
    cout << ( AL.dequeueDog().name == "darwin" ) << endl;
    AL.dequeueAny();
    cout << AL.empty() << endl;
    getchar();
    return 0;
}