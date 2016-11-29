/*
 * This class represents vertex in a graph.
 * The node maintains a value (that is type is T).
 * the operators of the Node depends on the operators of its value.
*/

#ifndef EX1_POINT_H
#define EX1_POINT_H

#include <iostream>

using namespace std;

template <class T> class Node;

template <class T>
class Node {
    T value;
public:
    Node(T value);
    //nodes comparison according to their values
    virtual bool operator==( Node<T> &other);
    //definition of ordering relation between Nodes in order to enable
    //data structures (like Map) to maintain them efficiently.
    //(the exact ordering relation, that we defined, doesn't matter)
    virtual bool operator<(const Node<T> &other) const;
    //return the value is maintained in the node
    T getValue();
};

template <class T>
Node<T>::Node(T value) : value(value) { }

template <class T>
bool Node<T>::operator==(Node<T> &other) {
    return (this->value == other.value);
}

template <class T>
bool Node<T>::operator<(const Node<T> &other) const {
    return (this->value < other.value);
}

template <class T>
T Node<T>::getValue() {
    return this->value;
}


#endif //EX1_POINT_H
