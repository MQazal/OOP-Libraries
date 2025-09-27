#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cctype>
using namespace std;

// String Library Project - 13/9/2025 - Course#10 - Developer: Mr.Key47

// * each method will serve two purposes:
// 1- Object Purpose: it is called by normal object as non-static method to update object's variable
// by void() procedure
// 
// 2- Class Level Purpose: it is called on class level without instantiate a normal object as
// static method.
// 
// * to create a custom = property
// 	__declspec(property(put = set_property(), get = get_property())) property identifier;
// set_property() -> identifier = value;
// get_property() -> cout << identifier;


class clsInterface
{
	virtual short GetStringLength() = 0;
	virtual void PrintEachWord() = 0;
	virtual bool IsNumberInRange(int Number, int From, int To) = 0;
	virtual short GetASCII(char Letter) = 0;
	virtual char GetLetterByASCII(short ASCIIValue) = 0;
	virtual void GenerateRangeOfLetters(char StartLetter, char EndLetter) = 0;
	virtual bool IsSmallLetter(char Letter) = 0;
	virtual bool IsCapitalLetter(char Letter) = 0;
	virtual bool IsPunctLetter(char Letter) = 0;
	virtual char Convert_Small_LetterToCapital(char SmallLetter) = 0;
	virtual char Convert_Capital_LetterToSmall(char CapitalLetter) = 0;
	/*virtual string MyLowerAllString() = 0;
	virtual string MyUpperAllString() = 0;
	virtual string MyRemoveSpecificLetter(string Text, char LetterToRemove) = 0;*/
	virtual string My_substr(string Text, short StartIndex, short NumberOfLetters) = 0;
	virtual string My_clear(string Text) = 0;
	virtual short ConvertDigitLetterToDigit(char DigitLetter) = 0;
	virtual int SumDigitsByRecursion(int Number) = 0;
};


class clsString : public clsInterface
{
private:
	void _PrintWelcomeMessage()
	{
		cout << "----------------------------------------------------------\n";
		cout << "Welcome in this String Class, made By Mr.Key with love (-:\n\n";
		cout << "You have already a declared string <vector>, you can access it by these methods:\n\n";
		cout << "1- AddWordToVector(word to add)\n\n2- getWordsOfVector()\n\n3- ClearVector()\n\n";
		cout << "Best of wishes.\n----------------------------------------------------------\n";
	}
	string _Text;
	char _Letter;
	string _delimiterType;
	vector <string> _vWords;
	static short _CountCapitalLetters(string Text)
	{
		short CapitalLettersCounter = 0;
		for (short i = 0; i < Text.length(); i++)
		{
			if (isupper(Text[i]))
			{
				CapitalLettersCounter++;
			}
		}
		return CapitalLettersCounter;
	}
	static short _CountSmallLetters(string Text)
	{
		short SmallLettersCounter = 0;
		for (short i = 0; i < Text.length(); i++)
		{
			if (islower(Text[i]))
			{
				SmallLettersCounter++;
			}
		}
		return SmallLettersCounter;
	}
	static short _CountPunctuationLetters(string Text)
	{
		short PunctuationLettersCounter = 0;
		for (short i = 0; i < Text.length(); i++)
		{
			if (ispunct(Text[i]))
				PunctuationLettersCounter++;
		}
		return PunctuationLettersCounter;
	}
	bool IsNumberInRange(int Number, int From, int To)
	{
		return (Number >= From) && (Number <= To);
	}

public:
	enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, PunctuationLetters = 2, AllLetters = 3 };

	clsString()
	{
		_PrintWelcomeMessage();
		_Text = "";
		_Letter = ' ';
		_delimiterType = "";
	}

	clsString(string Text, char Letter, string delimiterType)
	{
		_Text = Text;
		_Letter = Letter;
		_delimiterType = delimiterType;
	}

	void setText(string Text)
	{
		_Text = Text;
	}

	string getText()
	{
		return _Text;
	}

	__declspec(property(put = setText, get = getText)) string Text;

	void setLetter(char Letter)
	{
		_Letter = Letter;
	}

	char getLetter()
	{
		return _Letter;
	}

	__declspec(property(put = setLetter, get = getLetter)) char Letter;

	void setDelimiterType(string delimiterType)
	{
		_delimiterType = delimiterType;
	}

	string getDelimiterType()
	{
		return _delimiterType;
	}

	__declspec(property(put = setDelimiterType, get = getDelimiterType)) string delimiterType;

	void AddWordToVector(string Word)
	{
		_vWords.push_back(Word);
	}

	void getWordsOfVector()
	{
		if (_vWords.size() == 0)
			cout << "\nThere are no words to print :-(\n";
		else
		{
			for (short i = 0; i < _vWords.size(); i++)
			{
				cout << "Word#" << i + 1 << ": " << _vWords.at(i) << endl;
			}
		}
	}

	void ClearVector()
	{
		_vWords.clear();
	}

	static void PrintTextLetters(string Text)
	{
		for (short i = 0; i < Text.length(); i++)
		{
			cout << "Letter#" << i << ": " << Text[i] << endl;
		}
	}

	void PrintTextLetters()
	{
		PrintTextLetters(_Text);
	}

	static char My_at(string Text, short Index)
	{
		return Text[Index];
	}

	char My_at(short Index)
	{
		return My_at(_Text, Index);
	}

	static void PrintFirstLetterFromEachWord(string Text)
	{
		cout << "\nFirst Letters of this string:\n";
		bool IsFirstLetter = true;
		for (short i = 0; i < Text.length(); i++)
		{
			if (Text[i] != ' ' && IsFirstLetter)
			{
				cout << Text[i] << endl;
			}
			IsFirstLetter = (Text[i] == ' ' ? true : false);
		}
	}

	void PrintFirstLetterFromEachWord()
	{
		PrintFirstLetterFromEachWord(_Text);
	}

	static string UpperFirstLetterOfEachWord(string Text)
	{
		bool isFirstLetter = true;

		for (short i = 0; i < Text.length(); i++)
		{
			if (Text[i] != ' ' && isFirstLetter)
			{
				Text[i] = toupper(Text[i]);
			}
			isFirstLetter = (Text[i] == ' ' ? true : false);
		}

		return Text;
	}

	void UpperFirstLetterOfEachWord()
	{
		_Text = UpperFirstLetterOfEachWord(_Text);
	}

	static string LowerFirstLetterOfEachWord(string Text)
	{
		bool isFirstLetter = true;
		for (short i = 0; i < Text.length(); i++)
		{
			if (Text[i] != ' ' && isFirstLetter)
			{
				Text[i] = tolower(Text[i]);
			}
			isFirstLetter = (Text[i] == ' ' ? true : false);
		}
		return Text;
	}

	void LowerFirstLetterOfEachWord()
	{
		_Text = LowerFirstLetterOfEachWord(_Text);
	}

	static string UpperAllString(string Text)
	{
		for (short i = 0; i < Text.length(); i++)
		{
			Text[i] = toupper(Text[i]);
		}
		return Text;
	}

	void UpperAllString()
	{
		_Text = UpperAllString(_Text);
	}

	static string LowerAllString(string Text)
	{
		for (short i = 0; i < Text.length(); i++)
		{
			Text[i] = tolower(Text[i]);
		}
		return Text;
	}

	void LowerAllString()
	{
		_Text = LowerAllString(_Text);
	}

	static char InvertLetterCase(char Character)
	{
		return isupper(Character) ? tolower(Character) : toupper(Character);
	}

	void InvertLetterCase()
	{
		_Letter = InvertLetterCase(_Letter);
	}

	static string InvertStringLettersCase(string Text)
	{
		for (short i = 0; i < Text.length(); i++)
		{
			Text[i] = InvertLetterCase(Text[i]);
		}
		return Text;
	}

	void InvertStringLettersCase()
	{
		_Text = InvertStringLettersCase(_Text);
	}

	static short CountWords(string Text, string delimiterType)
	{
		short Position = 0;
		short WordsCounter = 0;
		while ((Position = Text.find(delimiterType)) != string::npos)
		{
			Text = Text.erase(0, Position + delimiterType.length());
			WordsCounter++;
		}
		// Last Word:
		WordsCounter++;
		return WordsCounter;
	}

	short CountWords()
	{
		return CountWords(_Text, _delimiterType);
	};

	static short CountLetters(string Text, enWhatToCount LettersType = enWhatToCount::AllLetters)
	{
		switch (LettersType)
		{
		case enWhatToCount::AllLetters:
			return Text.length();
		case enWhatToCount::CapitalLetters:
			return _CountCapitalLetters(Text);
		case enWhatToCount::SmallLetters:
			return _CountSmallLetters(Text);
		default:
			return _CountPunctuationLetters(Text);
		}
	}

	short CountLetters(enWhatToCount LettersType = enWhatToCount::AllLetters)
	{
		return CountLetters(_Text, LettersType);
	}

	static short CountTimesOfCharacter(string Text, char LetterToSearch)
	{
		short LetterToSearchCounter = 0;
		for (short i = 0; i < Text.length(); i++)
		{
			if (Text[i] == LetterToSearch)
			{
				LetterToSearchCounter++;
			}
		}
		return LetterToSearchCounter;
	}

	short CountTimesOfCharacter()
	{
		return CountTimesOfCharacter(_Text, _Letter);
	}

	static short CountSpecificLetter(string Text, char LetterToSearch, bool IsMatchCase = true)
	{
		short Counter = 0;
		for (short i = 0; i < Text.length(); i++)
		{
			if (IsMatchCase)
			{
				if (Text[i] == LetterToSearch)
					Counter++;
			}
			else
			{
				if (toupper(Text[i]) == toupper(LetterToSearch))
					Counter++;
			}
		}
		return Counter;
	}

	short CountSpecificLetter(bool IsMatchCase = true)
	{
		return CountSpecificLetter(_Text, _Letter, IsMatchCase);
	}

	static short My_find(string Text, char LetterToSearch)
	{
		for (short i = 0; i < Text.length(); i++)
		{
			if (Text[i] == LetterToSearch)
				return i;
		}
	}

	short My_find(char LetterToSearch)
	{
		return My_find(_Text, LetterToSearch);
	}

	static bool IsVowelCharacter(char Character)
	{
		Character = tolower(Character);
		return ((Character == 'a') || (Character == 'e') || (Character == 'i') || (Character == 'o') || (Character == 'u'));
	}

	bool IsVowelCharacter()
	{
		return IsVowelCharacter(_Letter);
	}

	static short CountVowels(string Text)
	{
		short VowelsCounter = 0;
		for (short i = 0; i < Text.length(); i++)
		{
			if (IsVowelCharacter(Text[i]))
				VowelsCounter++;
		}
		return VowelsCounter;
	}

	short CountVowels()
	{
		return CountVowels(_Text);
	}

	static void PrintVowelCharacters(string Text)
	{
		for (short i = 0; i < Text.length(); i++)
		{
			if (IsVowelCharacter(Text[i]))
				cout << setw(3) << Text[i] << "   ";
		}
	}

	void PrintVowelCharacters()
	{
		PrintVowelCharacters(_Text);
	}

	static vector<string> Split(string Text, string delimiterType)
	{
		vector <string> vSplitTextWords{};
		string FullWord = " ";
		short delimiterIndex = 0;

		while ((delimiterIndex = Text.find(delimiterType)) != Text.npos)
		{
			if (Text != " ")
			{
				FullWord = Text.substr(0, delimiterIndex);
				vSplitTextWords.push_back(FullWord);
			}
			Text.erase(0, delimiterIndex + delimiterType.length()); // delete from 0 to number of delimiter characters
		}

		if (Text != " ")
		{
			vSplitTextWords.push_back(Text); // push last word
		}

		return vSplitTextWords;
	}

	vector<string> Split()
	{
		return Split(_Text, _delimiterType);
	}

	static short CalculateTokensOfStringVector(vector <string> vWords)
	{
		short TokenCounter = 0;
		for (short i = 0; i < vWords.size(); i++)
		{
			if (vWords[i] != " ")
			{
				TokenCounter++;
			}
		}
		return TokenCounter;
	}

	short CalculateTokensOfStringVector()
	{
		return CalculateTokensOfStringVector(_vWords);
	}

	static void ReversedCharacters(string Text)
	{
		for (short i = Text.length() - 1; i >= 0; i--)
		{
			cout << Text[i];
		}
	}

	void ReversedCharacters()
	{
		ReversedCharacters(_Text);
	}

	static string TrimFromLeft(string Text)
	{
		for (short i = 0; i < Text.length(); i++)
		{
			if (Text[i] != ' ')
			{
				return Text.substr(i, Text.length() - 1); // i = index of before char after " "
			}
		}
	}

	void TrimFromLeft()
	{
		_Text = TrimFromLeft(_Text);
	}

	static string TrimFromRight(string Text)
	{
		for (short i = Text.length() - 1; i >= 0; i--)
		{
			if (Text[i] != ' ')
			{
				return Text.substr(0, i + 1);
			}
		}
	}

	void TrimFromRight()
	{
		_Text = TrimFromRight(_Text);
	}

	static string Trim(string Text)
	{
		return TrimFromRight(TrimFromLeft(Text));
	}

	void Trim()
	{
		_Text = Trim(_Text);
	}

	static string JoinStringByVector(vector <string> vString, string delimiterType)
	{
		string JoinedString;
		for (string& Word : vString)
		{
			JoinedString += Word + delimiterType;
		}
		return JoinedString.substr(0, JoinedString.length() - delimiterType.length());
	}

	string JoinStringByVector()
	{
		return JoinStringByVector(_vWords, _delimiterType);
	}

	string JoinString(string arrString[], short Length, string delimiterType)
	{
		string JoinedString;
		for (short i = 0; i <= Length - 1; i++)
		{
			JoinedString += arrString[i] + delimiterType;
		}
		return JoinedString.substr(0, JoinedString.length() - delimiterType.length());
	}

	static string ReverseStringWords(string Text)
	{
		vector <string> vString;
		string ReversedString;
		vString = Split(Text, " ");
		vector <string>::iterator iter; // declare iterator (pointer)
		iter = vString.end();
		while (iter != vString.begin())
		{
			iter -= 1;
			ReversedString += *iter + " "; // Concatenation
		}
		ReversedString = ReversedString.substr(0, ReversedString.length() - 1);
		return ReversedString;
	}

	void ReverseStringWords()
	{
		_Text = ReverseStringWords(_Text);
	}

	static string ReplaceWordInString(string Text, string OldWord, string NewWord, bool IsMatchCase = true)
	{
		vector <string> vString = Split(Text, " ");
		for (string& VectorWord : vString)
		{
			if (IsMatchCase)
			{
				if (VectorWord == OldWord)
				{
					VectorWord = NewWord;
				}
			}
			else
			{
				if (LowerAllString(VectorWord) == LowerAllString(OldWord))
				{
					VectorWord = NewWord;
				}
			}
		}
		return JoinStringByVector(vString, " ");
	}

	string ReplaceWordInString(string OldWord, string NewWord, bool IsMatchCase = true)
	{
		return ReplaceWordInString(_Text, OldWord, NewWord, IsMatchCase);
	}

	static string ReplaceWordInStringBuiltInFunction(string Text, string OldWord, string NewWord)
	{
		short Index = Text.find(OldWord); // get index of first OldWord's letter
		while (Index != Text.npos)
		{
			Text = Text.replace(Index, OldWord.length(), NewWord);
			Index = Text.find(OldWord);
		}
		return Text;
	}

	string ReplaceWordInStringBuiltInFunction(string OldWord, string NewWord)
	{
		return ReplaceWordInStringBuiltInFunction(_Text, OldWord, NewWord);
	}

	string RemovePunctuations(string Text)
	{
		for (short i = 0; i < Text.length(); i++)
		{
			if (ispunct(Text[i]))
			{
				Text = Text.erase(i, 1);
				i -= 1;
			}
		}
		return Text;
	}

	// * Interface / Abstract Class Implementation
	short GetStringLength()
	{
		short LettersCounter = 0;
		for (char Letter : _Text)
		{
			LettersCounter++;
		}
		return LettersCounter;
	}

	void PrintEachWord()
	{
		short Position = 0;
		string FullWord;
		while ((Position = _Text.find(_delimiterType)) != string::npos)
		{
			FullWord = _Text.substr(0, Position);
			cout << FullWord << endl;
			FullWord = FullWord.erase(0, FullWord.length());
			_Text = _Text.erase(0, Position + delimiterType.length()); // start new word
		}
		// Print Last Word
		cout << _Text << endl;
	}

	short GetASCII(char Letter)
	{
		return Letter;
	}

	char GetLetterByASCII(short ASCIIValue)
	{
		return ASCIIValue;
	}

	void GenerateRangeOfLetters(char StartLetter, char EndLetter)
	{
		for (short i = StartLetter; i <= EndLetter; i++)
		{
			cout << GetLetterByASCII(i) << " | " << i << endl;
		}
	}

	bool IsSmallLetter(char Letter)
	{
		return IsNumberInRange(GetASCII(Letter), 'a', 'z');
	}

	bool IsCapitalLetter(char Letter)
	{
		return IsNumberInRange(GetASCII(Letter), 'A', 'Z');
	}

	bool IsPunctLetter(char Letter)
	{
		return IsNumberInRange(GetASCII(Letter), '!', '~');
	}

	char Convert_Small_LetterToCapital(char SmallLetter)
	{
		return SmallLetter - 32;
	}

	char Convert_Capital_LetterToSmall(char CapitalLetter)
	{
		return CapitalLetter + 32;
	}

	/*string MyLowerAllString()
	{
		string UpdatedString;
		for (short i = 0; i < GetStringLength(); i++)
		{
			if (IsCapitalLetter(_Text[i]))
				UpdatedString += Convert_Capital_LetterToSmall(_Text[i]);
			else
				UpdatedString += _Text[i];
		}
		return UpdatedString;
	}

	string MyUpperAllString()
	{
		string UpdatedString;
		for (short i = 0; i < GetStringLength(); i++)
		{
			if (IsSmallLetter(_Text[i]))
				UpdatedString += Convert_Small_LetterToCapital(_Text[i]);
			else
				UpdatedString += Text[i];
		}
		return UpdatedString;
	}

	string MyRemoveSpecificLetter(string Text, char LetterToRemove)
	{
		for (short i = 0; i < Text[i]; i++)
		{
			if (Text[i] == LetterToRemove)
			{
				Text.erase(i, 1);
				--i;
			}
		}
		return Text;
	}*/

	string My_substr(string Text, short StartIndex, short NumberOfLetters)
	{
		string Substring;
		for (short i = StartIndex; i < NumberOfLetters; i++)
		{
			Substring += Text[i];
		}
		return Substring;
	}

	string My_clear(string Text)
	{
		return Text = "";
	}

	short ConvertDigitLetterToDigit(char DigitLetter)
	{
		return DigitLetter - '0';
	}

	int SumDigitsByRecursion(int Number)
	{
		static int Sum = 0;
		string StringNumber = to_string(Number);
		Sum += ConvertDigitLetterToDigit(StringNumber[0]);

		if (StringNumber.length() == 1)
			return Sum;
		else
		{
			StringNumber = StringNumber.erase(0, 1);
			Number = stoi(StringNumber);
			//int M = 0;
			//for (short i = 0; i < StringNumber.length(); i++)
			//{
			//	M += StringNumber[i] - '0';
			//	M *= 10;
			//}
			//Number = M;
			return SumDigitsByRecursion(Number);
		}
	}
};