#include "Sorted_List.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


void Sorted_List::insert(int const& value)
{
    if(is_empty())
    {
        first = new node;
        first->data=value;
        first->next=nullptr;
    } else if(first->data > value)
    {
        node* temp = new node;
        temp->data = value;
        temp->next = first;
        first = temp;   
    } else if (first->next == nullptr && first->data < value)
    {
        first->next = new node;
        first->next->data = value;
        first->next->next = nullptr;
    } else
    {
       insert(value, first->next);   
    }   
    ++list_size;
}

void Sorted_List::insert(int const& value, node* curr)
{
    if(curr->data < value && curr->next==nullptr)
    {
        curr->next = new node;
        curr->next->data = value;
        curr->next->next = nullptr;
    }else if(curr->data < value && curr->next->data > value)
    {
        node* temp = new node;
        temp->data = value;
        temp->next = curr->next;
        curr->next = temp;
    }else
    {
        insert(value, curr->next);   
    }
}

 void const Sorted_List::print()
{
    //string p;
    if(is_empty())
    {
        cout << "The list is empty!";
    } else if(first->next != nullptr)
    {
        cout << first->data << ' ';
        //p += to_string((first->data)+ ' ');
        print(first->next);
    } else 
    {
        //p += to_string((first->data)+ ' ');
        cout << first->data << ' ';
        
    }
}

void const Sorted_List::print(node* curr)
{
    cout << curr->data << ' ';
    if(curr->next != nullptr)
    {
        print(curr->next);
    }
}

void Sorted_List::remove_value(int const& value)
{  
    node* temp = first;
    while(temp->next != nullptr || list_size == 1)
    {
        if(temp->data == value)
        {
            first = temp->next;
            delete(temp);
            --list_size;
            break;

        } else if(temp->next->data == value && temp->next->next == nullptr) {        
            delete(temp->next);
            temp->next = nullptr;
            --list_size;
            break;
        }
        else if(temp->next->data == value)
        {
            node* temp2 = temp->next;
            temp->next = temp2->next;
            temp2->next = nullptr;
            delete(temp2);
            --list_size;
            break;
        }
        else if(temp->data == value && list_size == 1)
        {
            delete(temp);
        }
        temp = temp->next;
    }
}

bool const Sorted_List::is_empty()
{
    if (first == nullptr) 
    {
        return true;
    } else
    {
        return false;
    }
    
}

int const& Sorted_List::size()
{
    return list_size;
}

Sorted_List::~Sorted_List()
{
    while(first!=nullptr)
    {
        node* temp{first};
        first=first->next;
        delete(temp);       
    }
}

//Deep constructor
Sorted_List::Sorted_List(Sorted_List& other)
{
    first = nullptr;
    node* temp{other.first};
    node* curr;
    if(temp != nullptr){
        first = new node();
        first->data = temp->data;
        curr = first;
        temp = temp->next;
        ++list_size;
        while(temp != nullptr)
        {
            curr->next = new node();
            curr = curr->next;
            curr->data = temp->data;
            temp = temp->next;
            ++list_size;
        }
    }
}

//Deep copy
Sorted_List& Sorted_List::operator =(Sorted_List& other)
{
    new(this) Sorted_List{other};
    return *this;
}

//Move operator
Sorted_List& Sorted_List::operator=(Sorted_List && other)
{
    clean();
    first = other.first;
    other.first = nullptr;
    return *this; 
}

//Move constructor
Sorted_List::Sorted_List(Sorted_List && other)
{
    first = other.first;
    other.first = nullptr;
}

void const Sorted_List::clean()
{
    while(first != nullptr)
    {
        remove_value(first->data);
    }
}