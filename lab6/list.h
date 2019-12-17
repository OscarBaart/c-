#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include <string>

//using Data = std::string;

template<class T>
class List
{
public:
  List();
  ~List() { delete first; }

  void insert(T const& d);
  
  List(List const&);
  List(List&&); 
  List& operator=(List const&);
  List& operator=(List&&);
    
private:

  class Link
  {
  public:
    Link(Data const& d, Link* n)
      : data(d), next(n) {}
    ~Link() { delete next; }
    
    friend List;

    static Link* clone(Link const*);
    
  private:
    
    T data;
    Link* next;
  };
  
  Link* first;
  
public:

  using value_type = Data;

  // Suitable place to add things...
  class templateIterator
  {
    friend List;

    public:
        bool operator==(templateIterator const& other) const;
        bool operator!=(templateIterator const& other) const;
        T& operator*() const;
        T& operator->() const;

    private:  
  }
  templateIterator begin() const;
  templateIterator end() const;
  
};

#include "list.tcc"
#endif
