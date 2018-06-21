#ifndef NODE_HPP
#define NODE_HPP

class Node               
{                        
    private:                   
         int value;       
         Node* left;      
         Node* right;     
    
    public:
        Node(int v = 0);  
        
        int get_value() const;

        void set_value(int v);

        Node* get_left() const;

        void set_left(Node* l);

        Node* get_right() const;

        void set_right(Node* r); 
};                       
#endif
