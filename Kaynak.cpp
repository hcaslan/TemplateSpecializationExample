/*
* For example, let's suppose that we have a very simple class called mycontainer 
* that can store one element of any type and that it has just one member function called increase, 
* which increases its value. But we find that when it stores an element of type char 
* it would be more convenient to have a completely different implementation with a function member uppercase, 
* so we decide to declare a class template specialization for that type:
*/

// template specialization
#include <iostream>

// class template:
template <class T>
class mycontainer {
    T element;
public:
    mycontainer(T arg) { element = arg; }
    T increase() { return ++element; }
};

// class template specialization:
template <>
class mycontainer <char> {
    char element;
public:
    mycontainer(char arg) { element = arg; }
    char uppercase()
    {
        if ((element >= 'a') && (element <= 'z'))
            element += 'A' - 'a';
        return element;
    }
};

int main() {
    mycontainer<int> myint(7);
    mycontainer<char> mychar('j');
    std::cout << myint.increase() << std::endl;
    std::cout << mychar.uppercase() << std::endl;
    return 0;
}