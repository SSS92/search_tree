#ifndef TREE_HPP
#define TREE_HPP

/**
 *@brief Tree consisting of a collection of nodes 
 which together represent a structure called tree
 */
class Tree
{
    protected:
        Node* root;

        void copy_tree(Node* c, Node* f);
        void insert_node(Node* n, int v);
        Node* get_node(int v, Node* n);
        Node* find_parent(Node* n, int v);
        void remove_leaf(Node* n, int v);
        void remove_scn(Node* n, int v);
        void remove_node(Node* n);
        bool search(Node* r, int v) const;
        void delete_tree(Node* r); 
        void print(Node* r) const;

    public:

        /**
         *@brief Creates new node which initialized by given value,
         and initialize Tree with created node.
         @param value to init node
         */ 
        Tree();

        /**
         *@brief Tree's default constructor
         */ 
        Tree(const Tree& t);

        /**
         *@brief Adds new node(initialized by second param) to the list
         by index, if index is > than count: index = count
         *@param index where will be added a new node
         *@param value to init new node
         *@return true - if a new node added successfuly,
         false - otherwise
         */
        void insert(int v);

        /**
         *@brief Removes a node from list by index
         *@param index of element which will be remove
         *@return true if index is valid, false otherwise
         */
        bool remove(int v);

        /**
         *@brief Returns an first element index which value
         is equal to param, if doesn't exist returns -1
         *@param value to search element
         *@return -1 - if not found, index of the element otherwise 
         */
        bool search(int v) const;

        /**
         *@brief Returns Node's heigth
         *@return list's size
         */
        int get_heigth(int v);

        /**
         *@brief Prints the list 
         */
        void print() const;

        /**
         *@brief Assingment operator for Tree type
         *@param Tree type element
         *@return returns an address of Tree type element
         */
        Tree& operator=(const Tree& t);

        /**
         *@brief Deletes all allocated memories
         */
        ~Tree();

};
#endif
