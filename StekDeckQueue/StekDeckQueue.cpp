#include <iostream>
#include <string>
#include <windows.h>



struct Queue
{
private:

	struct Node
	{
		std::string str;
		Node* next;

		Node(std::string _str):next(nullptr)
		{
			str = _str;
		}
	};

	Node* lastNode = nullptr;

	void enterNode(std::string _str)
	{
		Node* node = new Node(_str);

		if (lastNode != nullptr)
			node->next = lastNode;

		lastNode = node;
		
	}

	
	void deleteLastNode()
	{
		if (lastNode != nullptr)
		{
			Node*  _node = lastNode->next;
			delete(lastNode);
			lastNode = _node;
		}
		else
			std::cout << "List is note created\n";
	
	}

	void printAndDeleteAllList()
	{
		if (lastNode == nullptr)
			std::cout << "List is note created\n";

		while (lastNode != nullptr)
		{
			Node* _node = lastNode->next;
			std::cout << lastNode->str << std::endl;
			delete(lastNode);
			lastNode = _node;
		}
	}

	void PrintLastNode()
	{
		
		if (lastNode != nullptr)
			std::cout << lastNode->str << std::endl;
		else
			std::cout << "List is note created\n";
		
	}

	std::string enterData(std::string text)
	{
		std::string data;
		std::cout << text;
		std::cin >> data;
		return data;
	}

public:
	void menu(Queue list)
	{
		int number;
		std::string data, bettenData;


		system("cls");

		std::cout << "Choose a number:\n";
		std::cout << "1 - enter a node to end of list or create list\n";
		std::cout << "2 - Print last node \n";
		std::cout << "3 - delete last node\n";
		std::cout << "4 - Print all node and delete \n";
		std::cout << "5 - exit\n";

		std::cin >> number;

		switch (number)
		{
		case 1:
			list.enterNode(enterData("Write a date for node\n"));
			break;

		case 2:
			list.PrintLastNode();
			break;

		case 3:
			list.deleteLastNode();
			break;

		case 4:
			list.printAndDeleteAllList();
			break;

		case 5:
			return;
			break;
		}

		system("Pause");
		menu(list);
	}
};


//struct Deck
//{
//	struct node
//	{
//		std::string str;
//		node* next;
//
//		node(std::string _str)
//		{
//			str = _str;
//			next = nullptr;
//		}
//	};
//
//	node* head = nullptr;
//	node* first;
//
//
//	void enterNode(std::string _str)
//	{
//		node* _node = new node(_str);
//
//		if (head == nullptr)
//		{
//			head = _node;
//			first = _node;
//			return;
//		}
//
//		first->next = _node;
//		first = _node;
//
//	}
//
//	void addNode(std::string _str, std::string checkstr)
//	{
//		node* newNode = new node(_str);
//		node* firstNode = head;
//		node* nowNode = nullptr;
//
//		if (head == nullptr)
//		{
//			std::cout << "List is note created\n";
//			return;
//		}
//		else if (checkstr == firstNode->str)
//		{
//			head = newNode;
//			newNode->next = firstNode;
//			return;
//		}
//
//
//		while (firstNode->next != nullptr)
//		{
//			nowNode = firstNode->next;
//
//			if (checkstr == nowNode->str)
//			{
//				firstNode->next = newNode;
//				newNode->next = nowNode;
//				break;
//			}
//
//			firstNode = firstNode->next;
//		}
//	}
//
//	void deleteNode(std::string _str)
//	{
//		node* firstNode = head;
//		node* nowNode = nullptr;
//		node* lastNode = nullptr;
//
//		if (head == nullptr)
//		{
//			std::cout << "List is note created\n";
//			return;
//		}
//		else if (_str == firstNode->str)
//		{
//			nowNode = firstNode->next;
//			head = nowNode;
//			delete(firstNode);
//			return;
//		}
//
//		while (firstNode != nullptr)
//		{
//			nowNode = firstNode->next;
//			lastNode = nowNode->next;
//
//			if (_str == nowNode->str)
//			{
//				delete(nowNode);
//				firstNode->next = lastNode;
//				break;
//			}
//			else if (_str == lastNode->str and lastNode->next == nullptr)
//			{
//				nowNode->next = nullptr;
//				delete(lastNode);
//				break;
//			}
//
//
//			firstNode = firstNode->next;
//		}
//
//
//
//	}
//
//	void deleteList()
//	{
//		node* headNode = head;
//
//		if (head == nullptr)
//		{
//			std::cout << "List is note created\n";
//			return;
//		}
//
//		while (headNode != nullptr)
//		{
//			node* nowNode = headNode;
//			headNode = headNode->next;
//			delete(nowNode);
//		}
//		head = nullptr;
//	}
//
//	void printList()
//	{
//
//		node* _node = head;
//
//		if (head == nullptr)
//		{
//			std::cout << "List is empty\n";
//			return;
//		}
//
//		while (_node != nullptr)
//		{
//			std::cout << _node->str << std::endl;
//
//			_node = _node->next;
//		}
//	}
//
//
//	void checkNode(std::string _str)
//	{
//		node* node = head;
//
//		if (head == nullptr)
//		{
//			std::cout << "List is note created\n";
//			return;
//		}
//
//		while (node != nullptr)
//		{
//			if (_str == node->str)
//				std::cout << node->str << std::endl;
//
//			node = node->next;
//		}
// }
// //std::string enterData(std::string text)
//{
//	std::string data;
//	std::cout << text;
//	std::cin >> data;
//	return data;
//}
// //void menu(Deck list)
//{
//	int number;
//	std::string data, bettenData;
//
//
//	system("cls");
//
//	std::cout << "Choose a number:\n";
//	std::cout << "1 - enter a node to end of list or create list\n";
//	std::cout << "2 - enter a node to between node\n";
//	std::cout << "3 - delete a node\n";
//	std::cout << "4 - check a node\n";
//	std::cout << "5 - check all node\n";
//	std::cout << "6 - delete all node\n";
//	std::cout << "7 - exit\n";
//
//	std::cin >> number;
//
//
//
//	switch (number)
//	{
//	case 1:
//		list.enterNode(enterData("Write a date for node\n"));
//		break;
//
//	case 2:
//		list.addNode(enterData("Write a date for node\n"), enterData("Write the node before create a node\n"));
//		break;
//
//	case 3:
//		list.deleteNode(enterData("Write a node for delete\n"));
//		break;
//
//	case 4:
//		list.checkNode(enterData("Write node for check\n"));
//		break;
//
//	case 5:
//		list.printList();
//		break;
//
//	case 6:
//		list.deleteList();
//		break;
//
//	case 7:
//		return;
//		break;
//	}
//
//	system("Pause");
//	menu(list);
//
//}
//
//};
//	}
////


struct Stack
{
	struct node
	{
		std::string str;
		node* next;

		node(std::string _str)
		{
			str = _str;
			next = nullptr;
		}
	};

	node* last = nullptr;
	node* first;


	void enterNode(std::string _str)
	{
		node* _node = new node(_str);

		if (last == nullptr)
		{
			last = _node;
			first = _node;
			return;
		}
		last = _node;
		first->next = _node;
		first = _node;

	}

	void addNode(std::string _str, std::string checkstr)
	{
		node* newNode = new node(_str);
		node* firstNode = last;
		node* nowNode = nullptr;

		if (last == nullptr)
		{
			std::cout << "List is note created\n";
			return;
		}
		else if (checkstr == firstNode->str)
		{
			last = newNode;
			newNode->next = firstNode;
			return;
		}


		while (firstNode->next != nullptr)
		{
			nowNode = firstNode->next;

			if (checkstr == nowNode->str)
			{
				firstNode->next = newNode;
				newNode->next = nowNode;
				break;
			}

			firstNode = firstNode->next;
		}
	}

	void deleteNode(std::string _str)
	{
		node* firstNode = last;
		node* nowNode = nullptr;
		node* lastNode = nullptr;

		if (last == nullptr)
		{
			std::cout << "List is note created\n";
			return;
		}
		else if (_str == firstNode->str)
		{
			nowNode = firstNode->next;
			last = nowNode;
			delete(firstNode);
			return;
		}

		while (firstNode != nullptr)
		{
			nowNode = firstNode->next;
			lastNode = nowNode->next;

			if (_str == nowNode->str)
			{
				delete(nowNode);
				firstNode->next = lastNode;
				break;
			}
			else if (_str == lastNode->str and lastNode->next == nullptr)
			{
				nowNode->next = nullptr;
				delete(lastNode);
				break;
			}


			firstNode = firstNode->next;
		}



	}

	void deleteList()
	{
		node* headNode = last;

		if (last == nullptr)
		{
			std::cout << "List is note created\n";
			return;
		}

		while (headNode != nullptr)
		{
			node* nowNode = headNode;
			headNode = headNode->next;
			delete(nowNode);
		}
		last = nullptr;
	}

	void printList()
	{

		node* _node = last;

		if (last == nullptr)
		{
			std::cout << "List is empty\n";
			return;
		}

		while (_node != nullptr)
		{
			std::cout << _node->str << std::endl;

			_node = _node->next;
		}
	}


	void checkNode(std::string _str)
	{
		node* node = last;

		if (last == nullptr)
		{
			std::cout << "List is note created\n";
			return;
		}

		while (node != nullptr)
		{
			if (_str == node->str)
				std::cout << node->str << std::endl;

			node = node->next;
		}
	}

	std::string enterData(std::string text)
	{
		std::string data;
		std::cout << text;
		std::cin >> data;
		return data;
	}

	void menu(Stack list)
	{
		int number;
		std::string data, bettenData;


		system("cls");

		std::cout << "Choose a number:\n";
		std::cout << "1 - enter a node to end of list or create list\n";
		std::cout << "3 - delete a node\n";
		std::cout << "4 - check a node\n";
		std::cout << "5 - check all node\n";
		std::cout << "6 - delete all node\n";
		std::cout << "7 - exit\n";

		std::cin >> number;



		switch (number)
		{
		case 1:
			list.enterNode(enterData("Write a date for node\n"));
			break;

		case 3:
			list.deleteNode(enterData("Write a node for delete\n"));
			break;

		case 4:
			list.checkNode(enterData("Write node for check\n"));
			break;

		case 5:
			list.printList();
			break;

		case 6:
			list.deleteList();
			break;

		case 7:
			return;
			break;
		}

		system("Pause");
		menu(list);

	}
};




int main()
{
	Queue qu;
	qu.menu(qu);

}
