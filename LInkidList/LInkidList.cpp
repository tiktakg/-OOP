#include <iostream>
#include <string.h>
#include <windows.h>

#define show(text) std::cout << text << std::endl;

// !создать список
// добавить в список
// !удолить из списка 
// !почистить список

struct node
{
    std::string str;
    node* next;

    node(std::string _str) 
    {
        str = _str;  
    }
};

struct list
{
    node* head = nullptr;
    node* first;
    node* last;
   
    void enterNode(std::string _str)
    {
        node* _node = new node(_str);

        if (head == nullptr)
        {
            head = _node;
            first = _node;
            last = _node;
            return;
        } 

        first->next = _node;
        last = _node;
        first = _node;
 
    }

    void addNode( std::string _str, std::string checkstr )
    {
        node* newNode = new node(_str);

        node* firstNode = head;
        node* nowNode = nullptr;
        node* lastNode = nullptr;

        while (1)
        {
            nowNode = firstNode->next;
            lastNode = nowNode->next;

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

            if (nowNode == last)
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
            else if (_str == lastNode->str and lastNode == last)
            {
                last = nowNode;
                delete(lastNode);
                break;
            }

            if (lastNode == last)
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

        while (1)
        {
            node* nowNode = headNode;
            headNode = headNode->next;
            delete(nowNode);
            
            if (headNode == last)
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
          
            if (_node == last)
                break;
            else
                _node = _node->next;
        }  
    }

    void checkNode(std::string _str)
    {
        node* p = head;

        while (1)
        {
            if(_str == p->str)
                std::cout << p->str << std::endl;

            if (p == last)
                break;
            else
                p = p->next;
        }
    }
};

int main()
{
    list list;
    list.enterNode("1");
    list.enterNode("2");
    list.enterNode("3");
    list.enterNode("4");
    list.enterNode("5");
    list.enterNode("6");
    list.enterNode("7");
    list.enterNode("8");
    list.enterNode("9");

    list.printList();

    list.addNode("123", "1");

    //system("Pause");
    //system("cls");

    //list.printList();

    //system("Pause");
    //system("cls");

    list.deleteNode("11");
    system("Pause");

    list.printList();
}
