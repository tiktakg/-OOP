#include <iostream>
#include <string>
#include <windows.h>

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

struct list
{
    node* head = nullptr;
    node* first;

   
    void enterNode(std::string _str)
    {
        node* _node = new node(_str);

        if (head == nullptr)
        {
            head = _node;
            first = _node;
            return;
        } 

        first->next = _node;
        first = _node;
 
    }

    void addNode( std::string _str, std::string checkstr )
    {
        node* newNode = new node(_str);

        node* firstNode = head;
        node* nowNode = nullptr;

        if (head == nullptr)
        {
            std::cout << "List is note created\n";
            return;
        }

        while (1)
        {
            nowNode = firstNode->next;
          
            if (checkstr == firstNode->str)
            {
                head = newNode;
                newNode->next = firstNode;
                break;
            }
            else if (checkstr == nowNode->str)
            {
                firstNode->next = newNode;
                newNode->next = nowNode;
                break;
            }

            if (nowNode == nullptr)
            {
                std::cout << "Check node is empty" << std::endl;
                break;
            }

            firstNode = firstNode->next;
        }
    }

    void deleteNode(std::string _str)
    {
        node* firstNode = head;
        node* nowNode = nullptr;
        node* lastNode = nullptr;

        if (head == nullptr)
        {
            std::cout << "List is note created\n";
            return;
        }

        while (1)
        {
            nowNode = firstNode->next;
            lastNode = nowNode->next;

            if(_str == firstNode->str)
            {       
                nowNode = firstNode->next;
                head = nowNode;
                delete(firstNode);

                break;
            }
            else if (_str == nowNode->str)
            { 
                delete(nowNode);            
                firstNode->next = lastNode;
                break;
            }
            else if (_str == lastNode->str and lastNode->next == nullptr)
            {
                
                delete(lastNode);
                break;
            }

            if (lastNode->next == nullptr)
            {
                std::cout << "Delete node is empty" << std::endl;
                break;
            }

            firstNode = firstNode->next;
        }
    }

    void deleteList()
    {
        node* headNode = head;

        if (head == nullptr)
        {
            std::cout << "List is note created\n";
            return;
        }

        while (1)
        {
            node* nowNode = headNode;
            headNode = headNode->next;
            delete(nowNode);
            
            if (headNode == nullptr)
            {
                head = nullptr;
                break;
            }
        }
    }

    void printList() {

        node* _node = head;

        if (head == nullptr)
        {
            std::cout << "List is empty\n";
            return;
        }
        
        while (1)
        { 
            std::cout <<_node->str << std::endl;
          
            if (_node->next == nullptr)
                break;
            else
                _node = _node->next;
        }  
    }

    void checkNode(std::string _str)
    {
        node* p = head;

        if (head == nullptr)
        {
            std::cout << "List is note created\n";
            return;
        }

        while (1)
        {
            if(_str == p->str)
                std::cout << p->str << std::endl;

            if (p->next == nullptr)
                break;
            else
                p = p->next;
        }
    }

};

std::string enterData(std::string text)
{
    std::string data;
    std::cout << text;
    std::cin >> data;
    return data;
}

void menu(list list)
{
    int number;
    std::string data,bettenData;
    

    system("cls");

    std::cout << "Choose a number:\n";
    std::cout << "1 - enter a node to end of list or create list\n";
    std::cout << "2 - enter a node to between node\n";
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

        case 2:
            list.addNode(enterData("Write a date for node\n"), enterData("Write the node before create a node\n"));
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


int main()
{
    list list;
    menu(list);
 
}
