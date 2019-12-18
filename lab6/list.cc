#include <algorithm>
#include <iostream>

#include "list.h"

void List::insert(Data const& d)
{
  first = new Link(d, first);
}

//-----------------------------------------------------//
// Important copy and assignment stuff
List::Link*
List::Link::clone(Link const* dolly)
{
  if ( dolly != nullptr )
    return new Link(dolly->data, clone(dolly->next));
  else
    return nullptr;
}

List::List() : first(nullptr)
{
  std::clog << "***Default construction" << std::endl;
}

List::List(List const& l)
{
  std::clog << "***Copy construction" << std::endl;
  first = Link::clone(l.first);
}

List::List(List&& l)
{
  std::clog << "***Move construction" << std::endl;
  first = l.first;
  l.first = nullptr;
}

List& List::operator=(List const& rhs)
{
  std::clog << "***Copy assignment" << std::endl;
  if (&rhs != this)
  {
    List copy(rhs);
    std::swap(first, copy.first);
  }
  return *this;
}

List& List::operator=(List&& rhs)
{
  std::clog << "***Move assignment" << std::endl;
  if (&rhs != this)
  {
    std::swap(first, rhs.first);
  }
  return *this;
}

// Iteration functions below

template <class T>
T& List<T>::tempIterator::operator*() const {
    return current->data;
}

template <class T>
T& List<T>::tempIterator::operator->() const {
    return current->data;
}

template <class T>
void List<T>::tempIterator::setCurrent(Link* _value) {
    current = _value;
}

template <class T>
typename List<T>::tempIterator& List<T>::tempIterator::operator++() {
    current = current->next;
    return *this;
}

template <class T>
bool List<T>::tempIterator::operator==(tempIterator const& other) const {
    return other.current = current;
}

template <class T>
bool List<T>::tempIterator::operator!=(tempIterator const& other) const {
    return other.current != current;
}

template <class T>
typename List<T>::tempIterator List<T>::begin() const {
    return tempIterator(first);
}

template <class T>
typename List<T>::tempIterator List<T>::end() const {
    return tempIterator(nullptr);
}

template <class T>
std::ostream& operator<<(std::ostream& os, const List<T>& list) {
    for (auto i : list) {
        os << i << " ";
    }
    return os;
}