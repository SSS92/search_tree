#include <node.hpp>
#include <iostream>

Node::Node(int v)
    :value(v), left(NULL), right(NULL) 
{  
}

int Node::get_value() const
{
    return value;
}

void Node::set_value(int v)
{
    value = v;
}

Node* Node::get_left() const
{
    return left;
}

void Node::set_left(Node* l)
{
    left = l;
}

Node* Node::get_right() const
{
    return right;
}

void Node::set_right(Node* r)
{
    right = r;
}









