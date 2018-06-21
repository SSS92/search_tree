#include <node.hpp>
#include <tree.hpp>
#include <iostream>
#include <cassert>
#include <stdexcept>

Tree::Tree()
{
    root = NULL;
}

Tree::Tree(const Tree& t)
    :root(NULL)
{
    if (NULL != t.root) {
        int v = t.root->get_value();
        Node* n = new Node(v);
        assert(NULL != n);
        root = n;
        copy_tree(root, t.root);
    }
}

void Tree::copy_tree(Node* c, Node* f)
{
    Node* l = f->get_left();
    if (NULL != l) {
        Node* n = new Node(l->get_value());
        assert(NULL != n);
        c->set_left(n);
        copy_tree(n, l);
    }
    
    Node* r = f->get_right();
    if (NULL != r) {
        Node * n = new Node(r->get_value());
        assert(NULL != n);
        c->set_right(n);
        copy_tree(n, r);
    }
}

void Tree::insert(int v)
{
    if (NULL == root) {
        root = new Node(v);
    } else {
        insert_node(root, v); 
    }
}

void Tree::insert_node(Node* n, int v)
{
    if (v > n->get_value()) {
        if (NULL == n->get_right()) {
            Node* r = new Node(v);
            n->set_right(r);
        } else {
            insert_node(n->get_right(), v);
        }
    } else {
        if (NULL == n->get_left()) {
            Node* l = new Node(v);
            n->set_left(l);
        } else {
            insert_node(n->get_left(), v);
        }
    }     
}

Node* Tree::get_node(int v, Node* n)
{   
    if (!n) {
        return NULL;        
    }
    int nv = n->get_value();
    if (nv == v) {
        return n;
    }
    if (nv > v) {
       return get_node(v, n->get_left());
    }
    return get_node(v, n->get_right());
}

Node* Tree::find_parent(Node* n, int v)
{
    if (!n) {
        return NULL;
    }
    int nv = n->get_value();
    if (nv == v) {
        return NULL;
    }
    if (nv > v) {
        if (!(n->get_left())) {
            return NULL;
        }
        if (n->get_left()->get_value() == v) {
            return n;
        }
        return find_parent(n->get_left(), v);
    }

    if (!(n->get_right())) {
        return NULL;
    }
    if (n->get_right()->get_value() == v) {
        return n;
    }
    return find_parent(n->get_right(), v);
}

void Tree::remove_leaf(Node* n, int v)
{
    Node* p = find_parent(n, v);
    if (n->get_value() > p->get_value()) {
        p->set_right(NULL);
    } else {
        p->set_left(NULL);
    }
    delete n; 
}

void Tree::remove_scn(Node* n, int v)
{
    Node* p = find_parent(n, v);
    if (n->get_value() > p->get_value()) {
        if (n->get_left()) {
            p->set_right(n->get_left());
        } else {
            p->set_right(n->get_right());
        } 
    } else {
        if (n->get_left()) {
            p->set_left(n->get_left());
        } else {
            p->set_left(n->get_right());
        } 
    }
    delete n;
}

void Tree::remove_node(Node* n) 
{
    Node* t = n->get_right();
    while (t->get_left()) {
        t = t->get_left();
    }
    n->set_value(t->get_value());
    Node* p = find_parent(n->get_right(), t->get_value());
    if (t->get_right()) {
        p->set_left(t->get_right());
        delete t;
        return;
    }
    p->set_left(NULL);
    delete t;
}

bool Tree::remove(int v)
{
    Node* n = get_node(v, root);
    if (!n) {
        return false;
    }
    Node* nl = n->get_left();
    Node* nr = n->get_right();
    if (!nl && !nr) {
        remove_leaf(n, v);
        return true;
    }
    if ((!nl && nr) || (!nr && nl)) {
        remove_scn(n, v);
        return true;
    }
    remove_node(n);
    return true;
}   

bool Tree::search(int v) const
{
	if(!root) {
		return false;
	}
	return search(root,v);
}

bool Tree::search(Node* r, int v) const
{
	if(!r){
		return false;
	}
	int s = r->get_value();

	if(v == s) {
		return true;
	}

	if(v > s) {
		return search(r->get_right(), v);
	}
	return search(r->get_left(),v);
}

int Tree::get_heigth(int v)
{
    Node* n = get_node(v, root);
    if (NULL == n) {
        return 0;
    }
    Node* nl = n->get_left();
    Node* nr = n->get_right();
    int l = nl?get_heigth(nl->get_value()):0;
    int r = nr?get_heigth(nr->get_value()):0;
    int max = (r > l)? r:l;
    return 1 + max;
}

void Tree::print() const
{
	if(!root) {
		std::cout << "The tree is empty" << std::endl;
		return;
	}
	print(root);
}

void Tree::print(Node* r) const
{
	if(r){
		std::cout << r->get_value() << std::endl;
		print(r->get_left());
		print(r->get_right());
	}
}

Tree& Tree::operator=(const Tree& t)
{  
    root = NULL;
    if (NULL != t.root) {
        int v = t.root->get_value();
        Node* n = new Node(v);
        assert(NULL != n);
        root = n;
        copy_tree(root, t.root);
    } 
    return *this;
}

Tree::~Tree()
{
	if(root){
		delete_tree(root);
	}
}

void Tree::delete_tree(Node* r)
{
	if(r->get_left()) {
		delete_tree(r->get_left());
	}
	if(r->get_right()) {
		delete_tree(r->get_right());
	}
	delete root;
}
