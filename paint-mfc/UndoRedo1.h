#ifndef _UNDOREDO1_H_
#define _UNDOREDO1_H_
#include <stack>
using namespace std;

template <class T>
class UndoRedo
{
public:
  UndoRedo(); 
  UndoRedo(const UndoRedo &); 
  ~UndoRedo();
  void addNew(const T&); 
  void Delete();
  void DeleteR();
  const T& top() const; 
  bool uIsEmpty() const; 
  bool rIsEmpty() const;
  void DeleteAll(); 
private:
stack<T> undo;
stack<T> redo;
};

#endif