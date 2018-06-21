#include <node.hpp>
#include <tree.hpp>
#include <iostream>


int main()
{
	Tree* t = new Tree();
	t->insert(21); 
	t->insert(10); 
	t->insert(33); 
	t->insert(7); 
	t->insert(14); 
	t->insert(11); 
	t->insert(19);
	t->insert(12);
	t->insert(27);
	t->insert(37);
	t->insert(34);
	t->insert(35);
	std::cout << "\nprint after inserting\n";
	t->print();
	std::cout << "\nend of print\n\n\n";
	std::cout << t->search(7) << std::endl;
	std::cout << t->search(99) << std::endl;
	
    std::cout << "12's height: " << t->get_heigth(21) << std::endl;

	t->remove(10);
	std::cout << "12's height: " << t->get_heigth(21) << std::endl; 
	std::cout << "\n\n\nprint after deleting\n";
	t->print();
	std::cout << "\nend of print\n\n\n";
	return 0;
}

