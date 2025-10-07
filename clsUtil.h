#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "clsDate.h"
using namespace std;

// Utility Library - 30/9/2025 - Course#11 - Developer: Mr.Key47


class clsUtil
{
public:
    static enum enCharType { Small_Letter = 1, Capital_Letter = 2, Digit = 3, MixLetters = 4 };

    static void ResetScreen()
    {
        system("cls");
        system("color 0F");
    }

    // Numbers Algorithms
	
	 static float ReadNumber(string Message)
    {
        float Number = 0;
        cout << Message;
        cin >> Number;
        return Number;
    }

    static float ReadPositiveNumber(string Message)
    {
        float Number = 0;
        do
        {
            cout << Message;
            cin >> Number;
        } while (Number <= 0);
        return Number;
    }

    static float ReadNumberInRange(string InputMessage, int From, int To)
    {
        float Number = 0;
        bool ValidNumber;
        do
        {
            cout << InputMessage;
            cin >> Number;
            ValidNumber = IsNumberInRange(Number, From, To);
        } while (!ValidNumber);
        return Number;
    }

    static bool IsIntegerNumber(float Number)
    {
        return Number == round(Number);
        // only one case is true: number is integer -> 2 or with fraction 0 -> 2.0
    }

    static bool IsDecimalNumber(float Number)
    {
        return Number != round(Number);
        /*
        2 != round(2) false -> 2 == 2
        2.2 != round(2.2) true -> 2.2 != 2
        2.5 != round(2.5) true -> 2.5 != 3
        */
    }

    static bool IsPositiveNumber(short Number)
    {
        return Number > 0;
    }

    static bool IsNegativeNumber(short Number)
    {
        return Number < 0;
    }

    static bool IsZero(short Number)
    {
        return Number == 0;
    }

    static bool IsOddNumber(short Number)
    {
        return Number % 2 != 0;
    }

    static bool IsEvenNumber(short Number)
    {
        return Number % 2 == 0;
    }

    static bool IsPerfectNumber(int Number)
    {
        int Sum = 0;
        for (int i = 1; i < Number; i++)
        {
            if (Number % i == 0)
                Sum += i;
        }
        return Number == Sum;
    }

    static bool IsPalindromeNumber(int Number)
    {
        return Number == ReverseNumber(Number);
    }

    static bool IsNumberInRange(int Number, int From, int To)
    {
        return (Number >= From && Number <= To);
    }

    static void GenerateBasicMultiplicationTables()
    {
        for (short i = 1; i <= 10; i++)
        {
            cout << "Multiplication Table of " << i << ":\n";
            for (short j = 1; j <= 10; j++)
            {
                cout << i << " * " << j << " = " << i * j << endl;
            }
            cout << "------------------\n";
        }
    }

    static void GenerateMultiplicationTableForNumber(short Number)
    {
        cout << "Multiplication Table of " << Number << ":\n";
        for (short i = 1; i <= 10; i++)
        {
            cout << Number << " * " << i << " = " << Number * i << endl;
        }
    }

    static bool IsNumberInRange(int Number, int From, int To)
    {
        return (Number >= From && Number <= To);
    }

    static void Swap(int& Num1, int& Num2)
    {
        int Temp = Num1;
        Num1 = Num2;
        Num2 = Temp;
    }

    static void Swap(double& Num1, double& Num2)
    {
        int Temp = Num1;
        Num1 = Num2;
        Num2 = Temp;
    }

    static void Swap(clsDate Date1, clsDate Date2)
    {
        //Swap(clsDate::DateToString(Date1), clsDate::DateToString(Date2));
        clsDate::SwapDates(Date1, Date2);
    }

    static bool IsPerfectNumber(int Number)
    {
        int Sum = 0;
        for (int i = 1; i < Number; i++)
        {
            if (Number % i == 0)
                Sum += i;
        }
        return Number == Sum;
    }
    
    static void PrintReversedDigits(int Number)
    {
        int Remainder = 0;
        while (Number > 0)
        {
            Remainder = Number % 10; // 1234 / 10 = 123.4 (take 4)
            Number = Number / 10; // 1234 / 10 = 123.4 (take 123)
            cout << Remainder << endl;
        }
    }

    static int SumReversedDigits(int Number)
    {
        int Remainder = 0, Sum = 0;
        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;
            Sum += Remainder;
        }
        return Sum;
    }
    
    static int ReverseNumber(int Number)
    {
        int Remainder = 0, Reverse = 0;
        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;
            Reverse = Reverse * 10 + Remainder;
        }
        return Reverse;
    }
    
    static int CountDigitFrequency(short DigitToCheck, int Number)
    {
        int Remainder = 0, FrequencyNumber = 0;
        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;
            if (DigitToCheck == Remainder)
            {
                FrequencyNumber++;
            }
        }
        return FrequencyNumber;
    }

    static void PrintAllDigitsFrequency(int Number)
    {
        for (short i = 0; i < 10; i++)
        {
            int DigitFrequency = 0;
            DigitFrequency = CountDigitFrequency(i, Number);
            if (DigitFrequency > 0)
            {
                cout << " Digit " << i << " is repeated on " << DigitFrequency << " time(s). \n";
            }
        }
    }

    static bool IsPalindromeNumber(int Number)
    {
        return Number == ReverseNumber(Number);
    }

    static int RandomNumber(int From, int To)
    {
        return rand() % (To - From + 1) + From;
    }

    static void Srand()
    {
        srand((unsigned)time(NULL));
    }

    // Patterns Algorithms

    static void PrintNumberPattern(int Number)
    {
        for (int i = 1; i <= Number; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << i;
            }
            cout << endl;
        }
    }

    static void PrintLetterPattern(int Number)
    {
        for (int i = 65; i <= 65 + Number - 1; i++)
        {
            for (int j = 1; j <= i - 65 + 1; j++)
            {
                cout << char(i);
            }
            cout << endl;
        }
    }

    static void PrintInvertedLetterPattern(int Number)
    {
        for (int i = 65 + Number - 1; i >= 65; i--)
        {
            for (int j = 1; j <= Number - (65 + Number - 1 - i); j++)
            {
                cout << char(i);
            }
            cout << endl;
        }
    }

    static void PrintInvertedNumberPattern(int Number)
    {
        for (int i = Number; i >= 1; i--)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << i;
            }
            cout << endl;
        }
    }

    static void PrintWordsFromAAAToZZZ()
    {
        string Word = "";
        for (int FirstLetter = 65; FirstLetter <= 90; FirstLetter++)
        {
            for (int SecondLetter = 65; SecondLetter <= 90; SecondLetter++)
            {
                for (int ThirdLetter = 65; ThirdLetter <= 90; ThirdLetter++)
                {
                    Word = Word + char(FirstLetter);
                    Word = Word + char(SecondLetter);
                    Word = Word + char(ThirdLetter);
                    cout << Word << endl;
                    Word = "";
                }
            }
            cout << "__________________________ \n";
        }
    }

    static void PrintPattern(char Symbol, short RowsNumber)
    {
        for (short i = 1; i <= RowsNumber; i++)
        {
            for (short j = 1; j <= i; j++)
            {
                cout << Symbol;
            }
            cout << endl;
        }
    }

    // Boolean Algorithms
	
	static char AskToPerformOperation(string Message)
    {
        char Perform;
        cout << Message;
        cin >> Perform;
        return Perform;
    }
	
    static bool AreLettersEqual(char Letter1, char Letter2)
    {
        return GetASCII(Letter1) == GetASCII(Letter2);
    }
	
    static bool CharToBoolean(char UserAnswer, char WhatToExpect, char AnotherExpectation = ' ')
    {
        return AreLettersEqual(UserAnswer, WhatToExpect) || AreLettersEqual(UserAnswer, AnotherExpectation);
    }

    static bool StringToBoolean(string UserAnswer, string WhatToExpect)
    {
        return UserAnswer == WhatToExpect;
    }

    static void Swap(bool& BooleanValue1, bool& BooleanValue2)
    {
        bool Temp = BooleanValue1;
        BooleanValue1 = BooleanValue2;
        BooleanValue2 = Temp;
    }

    // Array Algorithms

    static void FillArray(int Array[100], short& Length)
    {
        Length = ReadPositiveNumber(" Please enter how many elements do you want to store in array ? ");

        cout << "\nEnter Array Elements \n";

        for (int Counter = 0; Counter <= Length - 1; Counter++)
        {
            cout << "\nElement[" << Counter + 1 << "]: ";
            cin >> Array[Counter];
        }
    }

    static void PrintArray(int Array[100], short Length)
    {
        for (short i = 0; i < Length; i++)
        {
            cout << Array[i] << " ";
        }
    }

    static int CountNumberFrequency(int Array[1000], int Length, int NumberToCheck)
    {
        int SumFound = 0;

        for (int Counter = 0; Counter <= Length - 1; Counter++)
        {
            if (Array[Counter] == NumberToCheck)
            {
                SumFound++;
            }
        }
        return SumFound;
    }

    static void FillArrayWithRandomNumbers(int Array[100], int& Length, short StartRangeValue, short EndRangeValue)
    {
        Length = ReadPositiveNumber(" Please enter how many elements do you want to store in array? 0 to 100: ");
        for (int i = 0; i < Length; i++)
        {
            Array[i] = RandomNumber(StartRangeValue, EndRangeValue);
        }
    }

    static void FillArrayWithRandomWords(string Array[100], int& Length, enCharType Char, short LettersNumber)
    {
        Length = ReadPositiveNumber(" Please enter how many words do you want to store in array? 0 to 100: ");
        for (short i = 0; i < Length; i++)
        {
            Array[i] = GenerateWord(Char, LettersNumber);
        }
    }

    static void FillArrayWithRandomKeys(string Array[100], int& Length, enCharType Char)
    {
        Length = ReadPositiveNumber(" Please enter how many keys do you want to store in array? 0 to 100: ");
        for (short i = 0; i < Length; i++)
        {
            Array[i] = GenerateKey(Char);
        }
    }

    static int MaxElementInArray(int Array[100], int Length)
    {
        int MaxNumber = 0;

        for (int i = 0; i <= Length - 1; i++)
        {
            if (Array[i] > MaxNumber)
            {
                MaxNumber = Array[i];
            }
        }
        return MaxNumber;
    }

    static int MinNumberInArray(int Array[100], int Length)
    {
        int Min = 0;
        Min = Array[0];

        for (int i = 0; i <= Length - 1; i++)
        {
            if (Array[i] < Min)
            {
                Min = Array[i];
            }
        }
        return Min;
    }

    static int SumArrayNumbers(int Array[100], int Length)
    {
        int Sum = 0;

        for (int i = 0; i <= Length - 1; i++)
        {
            Sum += Array[i];
        }
        return Sum;
    }

    static float AverageArray(int Array[100], int Length)
    {
        return (float)SumArrayNumbers(Array, Length) / Length;
    }

    static void CopyArray(int arrSource[100], int arrDestination[100], int Length)
    {
        for (int i = 0; i <= Length - 1; i++)
        {
            arrDestination[i] = arrSource[i];
        }
    }

    static void AddTwoArrays(int Array1[100], int Array2[100], int Array3[100], int UnifiedArraysLength)
    {
        for (int i = 0; i <= UnifiedArraysLength - 1; i++)
        {
            Array3[i] = Array1[i] + Array2[i];
        }
    }

    static void ShuffleArray(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(0, arrLength - 1)], arr[RandomNumber(0, arrLength - 1)]);
        }
    }

    static void ShuffleArray(string arr[100], int arrLength)
    {
        for (short i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(0, arrLength - 1)], arr[RandomNumber(0, arrLength - 1)]);
        }
    }

    static void CopyArrayInReverseOrder(int arr1[100], int arr2[100], int arrLength)
    {
        int ReverseCounter = arrLength - 1;

        for (int i = 0; i <= arrLength - 1; i++)
        {
            arr2[i] = arr1[arrLength - 1 - i];
            /*
            * // My Solution $ MSE WAS HERE $
            arr2[i] = arr1[arrLength - ReverseCounter];
            ReverseCounter--;
            */
        }
    }

    static short FindNumberPositionInArray(int Array[100], short Length, short NumberToSearch)
    {
        for (int i = 0; i <= Length - 1; i++)
        {
            if (Array[i] == NumberToSearch)
            {
                return i;
            }
        }
        return -1;
    }

    static bool IsNumberInArray(int Array[100], int Length, int NumberToSearch)
    {
        return FindNumberPositionInArray(Array, Length, NumberToSearch) != -1;
    }

    static void AddElementToArray(int Number, int Array[], int& ArrayLength)
    {
        ++ArrayLength;
        Array[ArrayLength - 1] = Number;
    }

    static void FillSimiDynamicArray(int Array[], int& ArrayLength)
    {
        bool SureToAdd = true;
        do
        {
            AddElementToArray(ReadNumber("Enter a Number: "), Array, ArrayLength);
            SureToAdd = StringToBoolean(ReadText("Do you want to add another number, Yes/No: "), "Yes");
        } while (SureToAdd);
    }

    static void CopyArrayUsingAddArrayElement(int arrSource[100], int arrDestination[100], int arrSourceLength, int& arrDestinationLength)
    {
        for (int i = 0; i <= arrSourceLength - 1; i++)
        {
            AddElementToArray(arrSource[i], arrDestination, arrDestinationLength);
        }
    }

    static void CopyOddNumbersUsingAddArrayElement(int arrSource[100], int arrDestination[100], int arrSourceLength, int& arrDestinationLength)
    {
        for (int i = 0; i <= arrSourceLength - 1; i++)
        {
            if (arrSource[i] % 2 != 0)
            {
                AddElementToArray(arrSource[i], arrDestination, arrDestinationLength);
            }
        }
    }

    static void FillArrayManually(int arr[20], short& arrLength)
    {
        arrLength = 6;
        arr[0] = 10;
        arr[1] = 20;
        arr[2] = 30;
        arr[3] = 30;
        arr[4] = 20;
        arr[5] = 10;
    }

    static void ReverseArray(int arr1[20], int arr2[20], short arrLength)
    {
        for (int i = 0; i <= arrLength - 1; i++)
        {
            arr2[i] = arr1[arrLength - 1 - i];
        }
    }

    static bool IsPalindromeArray(int arr1[20], int arr2[20], short arrLength)
    {
        for (int i = 0; i <= arrLength - 1; i++)
        {
            if (arr1[i] == arr2[i])
                continue;
            else
                return false;
        }
        return true;
    }

    static short CountOddNumbers(int Array[100], short Length)
    {
        short OddNumbersCounter = 0;
        for (short i = 0; i < Length; i++)
        {
            if (Array[i] % 2 != 0)
                OddNumbersCounter++;
        }
        return OddNumbersCounter;
    }

    static short CountEvenNumbers(int Array[100], short Length)
    {
        short EvenNumbersCounter = 0;
        for (short i = 0; i < Length; i++)
        {
            if (Array[i] % 2 == 0)
                EvenNumbersCounter++;
        }
        return EvenNumbersCounter;
    }

    static short CountPositiveNumbers(int Array[100], short Length)
    {
        short PositiveNumbersCounter = 0;
        for (short i = 0; i < Length; i++)
        {
            if (Array[i] >= 0)
                PositiveNumbersCounter++;
        }
        return PositiveNumbersCounter;
    }

    static short CountNegativeNumbers(int Array[100], short Length)
    {
        short NegativeNumbersCounter = 0;
        for (short i = 0; i < Length; i++)
        {
            if (Array[i] < 0)
                NegativeNumbersCounter++;
        }
        return NegativeNumbersCounter;
    }

    // Matrix Algorithms

    static void FillMatrix(short Array[3][3], short Rows, short Columns)
    {
        // Nested Loop 1: Rows
        // Nested Loop 2: Columns (each Row will face its Columns)

        short Counter = 0;

        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Columns; j++)
            {
                Counter++;
                Array[i][j] = Counter;
            }
        }
    }

    static void PrintMatrix(short Array[3][3], short Rows, short Columns)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Columns; j++)
            {
                cout << setw(3) << Array[i][j] << "    ";
            }
            cout << '\n';
        }
    }

    static void FillMatrixByRandomNumbers(short Array[3][3], short Rows, short Columns)
    {
        // Nested Loop 1: Rows
        // Nested Loop 2: Columns (each Row will face its Columns)

        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Columns; j++)
            {
                Array[i][j] = RandomNumber(1, 100);
            }
        }
    }

    static int SumOfMatrixRow(short Array[3][3], short RowNumber, short Columns)
    {
        short RowSum = 0;

        for (short j = 0; j <= Columns - 1; j++)
        {
            RowSum += Array[RowNumber][j];
        }

        return RowSum;
    }

    static void FillArrayWithMatrixRowSum(short Receiver1DArray[3], short Sender2DArray[3][3], short Rows, short Columns)
    {
        for (short i = 0; i <= Rows - 1; i++)
        {
            Receiver1DArray[i] = SumOfMatrixRow(Sender2DArray, i, 3);
        }
    }

    static void PrintRowSumByArray(short Array[], short NumberOfIndexes)
    {
        for (short i = 0; i <= NumberOfIndexes - 1; i++)
        {
            cout << "\nRow [" << i + 1 << "] Sum = " << Array[i] << endl;
        }
    }

    static int SumOfMatrixColumn(short Array[3][3], short Rows, short ColumnNumber)
    {
        short ColumnSum = 0;

        for (short i = 0; i <= Rows - 1; i++)
        {
            ColumnSum += Array[i][ColumnNumber];
        }

        return ColumnSum;
    }

    static void FillArrayWithMatrixColumnSum(short Receiver1DArray[3], short Sender2DArray[3][3], short Rows, short Columns)
    {
        for (short i = 0; i < Columns; i++)
        {
            Receiver1DArray[i] = SumOfMatrixColumn(Sender2DArray, Rows, i);
            // Row Numbers are changed, but Column Number is fixed
        }
    }

    static void PrintColumnSumByArray(short Array[], short Size)
    {
        for (short i = 0; i <= Size - 1; i++)
        {
            cout << "\nColumn [" << i + 1 << "] Sum = " << Array[i] << endl;
        }
    }

    static void GetTransposedMatrix(short TransposedMatrix[3][3], short OriginalMatrix[3][3], short Rows, short Columns)
    {
        // Note: in this algorithm, the number of row is changed each time, but the number of column is fixed.
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Columns; j++)
            {
                TransposedMatrix[i][j] = OriginalMatrix[j][i];
                // [Row][Column] = [Column][Row]
            }
        }
    }

    static void MultiplyMatrix(short Matrix1[3][3], short Matrix2[3][3], short MatrixResults[3][3], short Rows, short Columns)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Columns; j++)
            {
                MatrixResults[i][j] = Matrix1[i][j] * Matrix2[i][j];
            }
        }
    }

    static void GetRowElements(short Matrix[3][3], short RowNumber, short Columns)
    {
        for (short j = 0; j < Columns; j++)
        {
            printf("%0*d    ", 2, Matrix[RowNumber][j]);
        }
    }

    static void GetColumnElements(short Matrix[3][3], short Rows, short ColumnNumber)
    {
        for (short i = 0; i < Rows; i++)
        {
            printf("%0*d    ", 2, Matrix[i][ColumnNumber]);
        }
    }

    static void GetMiddleRow(short Matrix[3][3], short Rows, short Columns)
    {
        short MiddleRow = Rows / 2;

        for (short j = 0; j < Columns; j++)
        {
            printf("%0*d    ", 2, Matrix[MiddleRow][j]);
        }
    }

    static void GetMiddleColumn(short Matrix[3][3], short Rows, short Columns)
    {
        short MiddleColumn = Columns / 2;

        for (short i = 0; i < Rows; i++)
        {
            printf("%0*d    ", 2, Matrix[i][MiddleColumn]);

        }
    }

    static int SumMatrix(short Matrix[3][3], short Rows, short Columns)
    {
        short Sum = 0;

        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Columns; j++)
            {
                Sum += Matrix[i][j];
            }
        }

        return Sum;
    }

    static bool AreEqualMatrices(short Matrix1[3][3], short Matrix2[3][3], short Rows, short Columns)
    {
        return (SumMatrix(Matrix1, 3, 3) == SumMatrix(Matrix2, 3, 3));
    }

    static bool AreTypicalMatrices(short Matrix1[3][3], short Matrix2[3][3], short Rows, short Columns)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Columns; j++)
            {
                if (Matrix1[i][j] != Matrix2[i][j])
                    return false;
            }
        }
        return true;
    }

    static bool IsIdentityMatrix(short Matrix[3][3], short Rows, short Columns)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Columns; j++)
            {
                // check diagonal matrix:
                if (i == j && Matrix[i][j] != 1)
                    return false;

                // check normal index:
                else if (i != j && Matrix[i][j])
                    return false;
            }
        }
    }

    static void FillMatrixAsScalar(short Matrix[3][3], short Rows, short Columns, short ScalarValue)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Columns; j++)
            {
                if (i == j)
                    Matrix[i][j] = ScalarValue; // Scalar index
                else
                    Matrix[i][j] = 0; // Normal index
            }
        }
    }

    static bool IsScalarMatrix(short Matrix[3][3], short Rows, short Columns)
    {
        int FirstValueInDiagonal = Matrix[0][0];

        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Columns; j++)
            {
                if (i == j && Matrix[i][j] != FirstValueInDiagonal)
                    return false;

                else if (i != j && Matrix[i][j] != 0)
                    return false;
            }
        }
        return true;
    }

    static short CountRepeatedTimes(short Matrix[3][3], short Rows, short Columns, short NumberToSearch)
    {
        short FrequencyCounter = 0;
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Columns; j++)
            {
                if (Matrix[i][j] == NumberToSearch)
                    FrequencyCounter++;
            }
        }
        return FrequencyCounter;
    }

    static short CountIntegers(short Matrix[3][3], short Rows, short Columns)
    {
        short IntegersCounter = 0;

        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Columns; j++)
            {
                if (Matrix[i][j] < 0 || Matrix[i][j] > 0)
                    IntegersCounter++;
            }
        }
        return IntegersCounter;
    }

    static bool IsSparceMatrix(short Matrix[3][3], short Rows, short Columns)
    {
        float MatrixSize = Rows * Columns;
        return (CountRepeatedTimes(Matrix, 3, 3, 0) >= ceil(MatrixSize / 2));
    }

    static bool IsElementInMatrix(short Matrix[3][3], short Rows, short Columns, short NumberToSearch)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Columns; j++)
            {
                if (Matrix[i][j] == NumberToSearch)
                    return true;
            }
        }
        return false;
    }

    static void PrintIntersectedNumbers(short Matrix1[3][3], short Matrix2[3][3], short Rows, short Columns)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Columns; j++)
            {
                if (IsElementInMatrix(Matrix2, Rows, Columns, Matrix1[i][j]))
                    cout << setw(3) << Matrix1[i][j] << "     ";
            }
        }
    }

    static short MaxElementInMatrix(short Matrix[3][3], short Rows, short Columns)
    {
        short Max = Matrix[0][0]; // assume that the first element is the maximum
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Columns; j++)
            {
                if (Matrix[i][j] > Max)
                {
                    Max = Matrix[i][j];
                }
            }
        }
        return Max;
    }

    static short MinElementInMatrix(short Matrix[3][3], short Rows, short Columns)
    {
        short Min = Matrix[0][0]; // assume that the first element is the minimum
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Columns; j++)
            {
                if (Matrix[i][j] < Min)
                {
                    Min = Matrix[i][j];
                }
            }
        }
        return Min;
    }

    static bool IsPalindromeMatrix(short Matrix[3][3], short Rows, short Columns)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Columns / 2; j++)
            {
                if (Matrix[i][j] != Matrix[i][Columns - 1 - j])
                    return false;
            }
        }
        return true;
    }

    // Strings Algorithms

    static string ReadText(string Message)
    {
        string Text;
        cout << Message;
        getline(cin, Text);
        return Text;
    }

    static void Swap(string& Text1, string& Text2)
    {
        string Temp = Text1;
        Text1 = Text2;
        Text2 = Temp;
    }

    static void Swap(char& Letter1, char& Letter2)
    {
        char Temp = Letter1;
        Letter1 = Letter2;
        Letter2 = Temp;
    }

    static bool GuessPassword(string Password)
    {
        string Word = "";
        int TryNumber = 0;
        for (int FirstLetter = 65; FirstLetter <= 90; FirstLetter++)
        {
            for (int SecondLetter = 65; SecondLetter <= 90; SecondLetter++)
            {
                for (int ThirdLetter = 65; ThirdLetter <= 90; ThirdLetter++)
                {
                    Word = Word + char(FirstLetter);
                    Word = Word + char(SecondLetter);
                    Word = Word + char(ThirdLetter);
                    TryNumber++;
                    cout << " Trial [" << TryNumber << "]:" << Word << endl;

                    if (Word == Password)
                    {
                        cout << " \n Password is " << Word << '\n';
                        cout << " \n Found after " << TryNumber << " Trail(s). \n";
                        return true;
                    }

                    Word = "";
                }
            }
        }
        return false;
    }

    static string EncryptText(string OriginalText, short EncryptionKey)
    {
        string EncryptedText = "";
        for (short i = 0; i < GetStringLength(OriginalText); i++)
        {
            EncryptedText += GetLetter(OriginalText[i] + EncryptionKey);
        }
        return EncryptedText;
    }

    static string DecryptText(string EncryptedText, short EncryptionKey)
    {
        string DecryptedText = "";
        for (short i = 0; i < GetStringLength(EncryptedText); i++)
        {
            DecryptedText += GetLetter(EncryptedText[i] - EncryptionKey);
        }
        return DecryptedText;
    }

    static char GetRandomCharacter(enCharType Char)
    {
        /*
        if (Char == enCharType::MixLetters)
        CharType = (enCharType)RandomNumber(1, 3);
        */

        switch (Char)
        {
        case enCharType::Small_Letter:
            return GetLetter(RandomNumber(97, 122));

        case enCharType::Capital_Letter:
            return GetLetter(RandomNumber(65, 90));

        case enCharType::Digit:
            return GetLetter(RandomNumber(48, 57));

        default:
            return GetRandomCharacter(enCharType(RandomNumber(1, 3)));
        }
    }

    static string GenerateWord(enCharType Char, short LettersNumber)
    {
        string Word;
        for (int i = 0; i < LettersNumber; i++)
        {
            Word += GetRandomCharacter(Char);
        }
        return Word;
    }

    static string GenerateKey(enCharType Char)
    {
        string Key;
        Key += GenerateWord(Char, 4) + '-';
        Key += GenerateWord(Char, 4) + '-';
        Key += GenerateWord(Char, 4) + '-';
        Key += GenerateWord(Char, 4);
        return Key;
    }

    static void GenerateKeys(enCharType Char, short KeysNumber)
    {
        for (short KeysCounter = 1; KeysCounter <= KeysNumber; KeysCounter++)
        {
            cout << "Key " << "[" << KeysCounter << "] : " << GenerateKey(Char) << '\n';
        }
    }

    static short GetStringLength(string Text)
    {
        short LettersCounter = 0;
        for (char& Letter : Text)
        {
            LettersCounter++;
        }
        return LettersCounter;
    }

    static void PrintEachWord(string Text, string delimiterType)
    {
        short Position = 0;
        string FullWord;
        while ((Position = Text.find(delimiterType)) != string::npos)
        {
            FullWord = Text.substr(0, Position);
            cout << FullWord << endl;
            FullWord = FullWord.erase(0, FullWord.length());
            Text = Text.erase(0, Position + delimiterType.length()); // start new word
        }
        // Print Last Word
        cout << Text << endl;
    }

    static short GetASCII(char Letter)
    {
        return Letter;
    }

    static char GetLetter(short ASCIIValue)
    {
        return ASCIIValue;
    }

    static void GenerateRangeOfLetters(char StartLetter, char EndLetter)
    {
        for (short i = StartLetter; i <= EndLetter; i++)
        {
            cout << GetLetter(i) << " | " << i << endl;
        }
    }

    static bool IsSmallLetter(char Letter)
    {
        return IsNumberInRange(GetASCII(Letter), 'a', 'z');
    }

    static bool IsCapitalLetter(char Letter)
    {
        return IsNumberInRange(GetASCII(Letter), 'A', 'Z');
    }

    static bool IsPunctLetter(char Letter)
    {
        return IsNumberInRange(GetASCII(Letter), '!', '~');
    }

    static char Convert_Small_LetterToCapital(char SmallLetter)
    {
        return SmallLetter - 32;
    }

    static char Convert_Capital_LetterToSmall(char CapitalLetter)
    {
        return CapitalLetter + 32;
    }

    static string MyLowerAllString(string Text)
    {
        string UpdatedString;
        for (short i = 0; i < GetStringLength(Text); i++)
        {
            if (IsCapitalLetter(Text[i]))
                UpdatedString += Convert_Capital_LetterToSmall(Text[i]);
            else
                UpdatedString += Text[i];
        }
        return UpdatedString;
    }

    static string MyUpperAllString(string Text)
    {
        string UpdatedString;
        for (short i = 0; i < GetStringLength(Text); i++)
        {
            if (IsSmallLetter(Text[i]))
                UpdatedString += Convert_Small_LetterToCapital(Text[i]);
            else
                UpdatedString += Text[i];
        }
        return UpdatedString;
    }

    static string MyRemoveSpecificLetter(string Text, char LetterToRemove)
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
    }

    static string My_substr(string Text, short StartIndex, short NumberOfLetters)
    {
        string Substring;
        for (short i = StartIndex; i < NumberOfLetters; i++)
        {
            Substring += Text[i];
        }
        return Substring;
    }

    static string My_clear(string Text)
    {
        return Text = "";
    }

    static string BooleanToString(bool Result, string TrueCaseString, string FalseCaseString)
    {
        return Result ? TrueCaseString : FalseCaseString;
    }

    static short ConvertDigitLetterToDigit(char DigitLetter)
    {
        return DigitLetter - '0';
    }

    static int SumDigitsByRecursion(int Number)
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

    static void Tabs(short TabsNumber)
    {
        for (short i = 1; i <= TabsNumber; i++)
        {
            cout << "\t";
        }
    }

    // File Handling Algorithms

    static void AddDataLineToFile(string FileName, string DataLine)
    {
        fstream File;
        File.open(FileName, ios::out | ios::app);

        if (File.is_open())
        {
            File << DataLine << endl;
            File.close();
        }
    }

    static void PrintDataFile(string FileName)
    {
        fstream File;
        File.open(FileName, ios::in);
        if (File.is_open())
        {
            short LineNumber = 1;
            string DataLine;
            while (getline(File, DataLine))
            {
                cout << "-Line " << LineNumber << ": " << DataLine << endl;
                ++LineNumber;
            }
            File.close();
        }
    }

    static vector <string> LoadFileToVector(string FileName)
    {
        vector <string> vFile;
        fstream File;
        File.open(FileName, ios::in);

        if (File.is_open())
        {
            string DataLine;
            while (getline(File, DataLine))
            {
                vFile.push_back(DataLine);
            }
            File.close();
        }
        return vFile;
    }
};