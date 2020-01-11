#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include <string>


//using Data = std::string;

template<class T>
class List
{
public:
  explicit List();
  ~List() { delete first; }

  void insert(T const& d);
  
  explicit List(List const&);
  explicit List(List&&); 
  List<T>& operator=(List const&);
  List<T>& operator=(List&&);
    
private:

  class Link
  {
  public:
    explicit Link(T const& d, Link* n)
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

  using value_type = T;

  // Suitable place to add things...
  class tempIterator
  {
    friend List;

    public:
        tempIterator& operator++();
        bool operator==(tempIterator const& other) const;
        bool operator!=(tempIterator const& other) const;
        T& operator*() ;
        T& operator->();

    private: 
     tempIterator(Link* curr) : current(curr) {}
    Link* current;
    void setCurr(Link* data); 
  };
  tempIterator begin();
  tempIterator end() ;

  template <class T_EXT>
  friend std::ostream& operator<<(std::ostream&, List<T_EXT> &);
  typedef tempIterator  Iterator;
  
};

#include "list.tcc"
#endif
