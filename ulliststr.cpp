#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val)
{
  if(empty())
  {
    Item* newItem = new Item();
    head_ = tail_ = newItem;
    newItem->val[0] = val;
    newItem->last++;
    size_++;
  }
  else if(tail_->last == ARRSIZE)
  {
    Item* newItem = new Item();
    tail_->next = newItem;
    newItem->prev = tail_;
    tail_ = newItem;
    newItem->val[0] = val;
    newItem->first = 0;   
    newItem->last++;
    size_++;
  }
  else
  {
    tail_->val[tail_->last] = val;
    tail_->last++;
    size_++;
  }

  return;
}

void ULListStr::push_front(const std::string & val)
{
  if(empty())
  {
    Item* newItem = new Item();
    head_ = tail_ = newItem;
    newItem->val[0] = val;
    newItem->last = 1;
    newItem->first = 0;
    size_++;
  }
  else if(head_->first == 0)
  {
    Item* newItem = new Item();
    newItem->val[ARRSIZE -1] = val;
    newItem->first = ARRSIZE - 1;
    newItem->last = ARRSIZE;
    newItem->next = head_;
    head_->prev = newItem;
    head_ = newItem;
    size_++;
  }
  else{
    head_->first--;
    head_->val[head_->first] = val;
    size_++;

  }
  return;
}

std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last-1];
}


std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}

void ULListStr::pop_back()
{
  tail_->last--;
  size_--;

  if(tail_->last == tail_->first)
  {
    Item* temp = tail_;
    tail_ = tail_->prev;
    if(tail_ != nullptr)
    {
      tail_->next = nullptr;
    }
    else
    {
      head_ = nullptr;
    }
    delete temp;
  }
}

void ULListStr::pop_front()
{
  head_->first += 1;
  if(head_->first == head_->last)
  {
    Item* temp = head_;
    head_ = head_->next;
    if(head_ != nullptr)
    {
      head_->prev = nullptr;
    }
    else
    {
      tail_ = nullptr;
    }
    delete temp;
  }
  size_--;
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if(size_ <= loc)
  {
    return NULL;
  }

  Item* current = head_;
  size_t i = 0;
  size_t pos = current->first;
  std::string* retVal = & (current->val[pos]);

  while(i < loc)
  {
    if(pos >= 9)
    {
      current = current->next;
      pos = 0;
    }
    else{
      pos++;
    }
    retVal = & (current->val[pos]);
    i++;
  }
  return retVal;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
