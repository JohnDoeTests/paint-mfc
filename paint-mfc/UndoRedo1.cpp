#include "stdafx.h"
#include <stack>
#include "UndoRedo1.h"

template <class T>
UndoRedo<T> :: UndoRedo()
{
}

template <class T>
UndoRedo<T> :: ~UndoRedo()
{
	DeleteAll();
}

template <class T>
UndoRedo<T> :: UndoRedo(const UndoRedo &u)
{
	*this=u;
}

template <class T>
void UndoRedo<T> :: addNew(const T& ob)
{
	undo.push(ob);
}

template <class T>
void UndoRedo<T> :: Delete()
{
	T temp;
	if(!(uIsEmpty()))
	{
	temp=undo.top();
	redo.push(temp);
	undo.pop();
	}
}

template <class T>
void UndoRedo<T> :: DeleteR()
{
	T temp;
	if(!(rIsEmpty()))
	{
	temp=redo.top();
	undo.push(temp);
	redo.pop();
	}
}

template <class T>
const T& UndoRedo<T> :: top() const
{
	return redo.top();
}

template <class T>
bool UndoRedo<T> :: uIsEmpty() const
{
	return undo.empty();
}

template <class T>
bool UndoRedo<T> :: rIsEmpty() const
{
	return redo.empty();
}

template <class T>
void UndoRedo<T> :: DeleteAll()
{
	while(!(redo.empty()))
		redo.pop();
	while(!(undo.empty()))
		undo.pop();
}
