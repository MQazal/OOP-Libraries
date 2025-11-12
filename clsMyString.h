#pragma once
#include <iostream>
#include <stack>
using namespace std;

// Undo/Redo Project - 13/11/2025 - Developer: Mr.Key47

class clsMyString
{
private:
	string _Text;

	stack <string> _Undo;

	stack <string> _Redo;

public:
	void setText(string Text)
	{
		_Text = Text;
		_Undo.push(_Text);
	}

	string getText()
	{
		return _Text;
	}

	__declspec(property(put = setText, get = getText)) string Text;

	void Redo()
	{
		if (!_Redo.empty())
		{
			_Undo.push(_Redo.top());
			_Text = _Redo.top();
			_Redo.pop();
		}
	}

	void Undo()
	{
		if (!_Undo.empty())
		{
			_Redo.push(_Undo.top());
			_Text = _Undo.top();
			_Undo.pop();
		}
	}
};