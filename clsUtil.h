#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "clsDate.h"
using namespace std;

// Utility Library - 30/9/2025 - Developer: Mr.Key47

class clsUtil
{
public:
    struct stTime
    {
        short Hour = 0;
        short Minute = 0;
        short Second = 0;
    };

    static void ResetScreen()
    {
        system("cls");
        system("color 0F");
    }

    enum enCharType { Small_Letter = 1, Capital_Letter = 2, Digit = 3, MixLetters = 4 };

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

    static float GetFractionPart(float Number)
    {
        return Number - (int)Number;
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

    static bool IsNumber1GraterThanNumber2(int Number1, int Number2)
    {
        return Number1 > Number2;
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
        clsDate::SwapDates(Date1, Date2);
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

    static int RandomNumber(int From, int To)
    {
        return rand() % (To - From + 1) + From;
    }

    static void Srand()
    {
        srand((unsigned)time(NULL));
    }

    static short AndOperator(short Number1, short Number2)
    {
        return Number1 & Number2;
    }

    static stTime getTime()
    {
        stTime Time;
        time_t now = time(0);
        tm* localTime = localtime(&now);
        Time.Hour = localTime->tm_hour;
        Time.Minute = localTime->tm_min;
        Time.Second = localTime->tm_sec;
        return Time;
    }

    static string TimeToString(stTime Time)
    {
        return to_string(Time.Hour) + ':' + to_string(Time.Minute) + ':' + to_string(Time.Second);
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
        return char(Letter1) == char(Letter2);
    }

    static bool CharToBoolean(char UserAnswer, char ExpectedAnswer, char AnotherAnswer = ' ')
    {
        return AreLettersEqual(UserAnswer, ExpectedAnswer) || AreLettersEqual(UserAnswer, AnotherAnswer);
    }

    static bool StringToBoolean(string UserAnswer, string ExpectedAnswer)
    {
        return UserAnswer == ExpectedAnswer;
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
        for (short i = 0; i <= Length - 1; i++)
        {
            cout << "\nElement[" << i + 1 << "]: ";
            cin >> Array[i];
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

    static void FillArrayWithRandomNumbers(int Array[100], int& Length, short StartRange, short EndRange)
    {
        Length = ReadPositiveNumber("Please enter how many elements do you want to store in array? 0 to 100: ");
        for (int i = 0; i < Length; i++)
        {
            Array[i] = RandomNumber(StartRange, EndRange);
        }
    }

    static int MaxNumber(int Array[100], int Length)
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

    static int MinNumber(int Array[100], int Length)
    {
        int Min = Array[0];
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

    static short GetIndex(int Array[100], int Length, int NumberToSearch)
    {
        for (int i = 0; i <= Length - 1; i++)
        {
            if (Array[i] == NumberToSearch)
                return i;
        }
        return -1;
    }

    static bool IsNumberExist(int Array[100], int Length, int NumberToSearch)
    {
        return GetIndex(Array, Length, NumberToSearch) != -1;
    }

    static short GetLastIndex(int Array[100], int Length, int NumberToSearch)
    {
        for (short i = Length - 1; i >= 0; i--)
        {
            if (Array[i] == NumberToSearch)
                return i;
        }
        return -1;
    }

    static void AddElementToArray(int Number, int Array[], int& ArrayLength)
    {
        ++ArrayLength;
        Array[ArrayLength - 1] = Number;
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

    static void FillArrayWithRandomWords(string Array[100], int& Length, enCharType Char, short LettersNumber)
    {
        Length = clsUtil::ReadPositiveNumber("Please enter how many words do you want to store in array? 0 to 100: ");
        for (short i = 0; i < Length; i++)
        {
            Array[i] = GenerateWord(Char, LettersNumber);
        }
    }

    static void FillArrayWithRandomKeys(string Array[100], int& Length, enCharType Char)
    {
        Length = clsUtil::ReadPositiveNumber(" Please enter how many keys do you want to store in array? 0 to 100: ");
        for (short i = 0; i < Length; i++)
        {
            Array[i] = GenerateKey(Char);
        }
    }

    static void FillSimiDynamicArray(int Array[], int& ArrayLength)
    {
        bool SureToAdd = true;
        do
        {
            clsUtil::AddElementToArray(clsUtil::ReadNumber("Enter a Number: "), Array, ArrayLength);
            SureToAdd = clsUtil::StringToBoolean(ReadText("Do you want to add another number, Yes/No: "), "Yes");
        } while (SureToAdd);
    }

    // Matrix Algorithms

    static void FillMatrix(short Matrix[3][3], short Rows, short Columns)
    {
        // Nested Loop 1: Rows
        // Nested Loop 2: Columns (each Row will face its Columns)
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Columns; j++)
            {
                cout << "\nEnter element of [" << i + 1 << "][" << j + 1 << "]: ";
                cin >> Matrix[i][j];
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
        // Note: row's value is changed, but column's value is fixed.
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
                if (IsPositiveNumber(Matrix[i][j]) || IsNegativeNumber(Matrix[i][j]))
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

    static short GetIndex(short Matrix[3][3], short Rows, short Columns, short NumberToSearch)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Columns; j++)
            {
                if (Matrix[i][j] == NumberToSearch)
                    return i;
            }
        }
        return -1;
    }

    static bool IsNumberExist(short Matrix[3][3], short Rows, short Columns, short NumberToSearch)
    {
        return GetIndex(Matrix, Rows, Columns, NumberToSearch) != -1;
    }

    static void PrintIntersectedNumbers(short Matrix1[3][3], short Matrix2[3][3], short Rows, short Columns)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Columns; j++)
            {
                if (IsNumberExist(Matrix2, Rows, Columns, Matrix1[i][j]))
                    cout << setw(3) << Matrix1[i][j] << "     ";
            }
        }
    }

    static short MaxNumber(short Matrix[3][3], short Rows, short Columns)
    {
        short Max = 0;
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

    static short MinNumber(short Matrix[3][3], short Rows, short Columns)
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

    // String Algorithms

    static string ReadText(string Message)
    {
        string Text;
        cout << Message;
        getline(cin, Text);
        return Text;
    }

    static string GetFullString(string Word1, string Word2)
    {
        return Word1 + Word2;
    }

    static string GetFullString(string Word1, string Word2, string Word3, string Word4)
    {
        return Word1 + Word2 + Word3 + Word4;
    }

    static string GetFullString(string Word1, string Word2, string Word3, string Word4, string Word5, string Word6)
    {
        return Word1 + Word2 + Word3 + Word4 + Word5 + Word6;
    }

    static string GetFullString(string Word1, string Word2, string Word3, string Word4, string Word5, string Word6, string Word7, string Word8 = "")
    {
        return Word1 + Word2 + Word3 + Word4 + Word5 + Word6 + Word7 + Word8;
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
        switch (Char)
        {
        case enCharType::Small_Letter:
            return GetLetter(clsUtil::RandomNumber(97, 122));

        case enCharType::Capital_Letter:
            return GetLetter(clsUtil::RandomNumber(65, 90));

        case enCharType::Digit:
            return GetLetter(clsUtil::RandomNumber(48, 57));

        default:
            return GetRandomCharacter(enCharType(clsUtil::RandomNumber(1, 3)));
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
        return clsUtil::IsNumberInRange(GetASCII(Letter), 'a', 'z');
    }

    static bool IsCapitalLetter(char Letter)
    {
        return clsUtil::IsNumberInRange(GetASCII(Letter), 'A', 'Z');
    }

    static bool IsPunctLetter(char Letter)
    {
        return clsUtil::IsNumberInRange(GetASCII(Letter), '!', '~');
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

    static string NumberToText(int Number)
    {
        if (Number == 0)
            return "";

        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
           "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
            "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
            return  arr[Number] + " ";
        }

        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return  arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 199)
            return  "One Hundred " + NumberToText(Number % 100);

        if (Number >= 200 && Number <= 999)
            return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);

        if (Number >= 1000 && Number <= 1999)
            return  "One Thousand " + NumberToText(Number % 1000);

        if (Number >= 2000 && Number <= 999999)
            return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);

        if (Number >= 1000000 && Number <= 1999999)
            return  "One Million " + NumberToText(Number % 1000000);

        if (Number >= 2000000 && Number <= 999999999)
            return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);

        if (Number >= 1000000000 && Number <= 1999999999)
            return  "One Billion " + NumberToText(Number % 1000000000);

        else
            return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
    }

    static short SumDigitsASCII(string Text)
    {
        short Sum = 0;
        for (short i = 0; i < Text.size(); i++)
        {
            if (clsUtil::IsNumberInRange(GetASCII(Text[i]), '0', '9'))
                Sum += GetASCII(Text[i]);
        }
        return Sum;
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

    // Vector Algorithms

    static vector <int> FillByUserInput(short Size)
    {
        vector<int> vInputs(Size); // {0 , 0 , 0 , 0 , 0}
        for (short i = 0; i < Size; i++)
        {
            cout << "\nEnter element of [" << i + 1 << "]: ";
            cin >> vInputs[i];
        }
        return vInputs;
    }

    static vector <int> FillBySequentialNumbers(short Size)
    {
        vector <int> vSequentialNumbers(Size);
        for (short i = 0; i < vSequentialNumbers.size(); i++)
        {
            vSequentialNumbers[i] = i + 1;
        }
        return vSequentialNumbers;
    }

    static vector <int> FillByRandomNumbers(short Size)
    {
        vector <int> vRandomNumbers;
        for (short i = 0; i < Size; i++)
        {
            vRandomNumbers = MyPush_back(vRandomNumbers, RandomNumber(1, 100));
        }
        return vRandomNumbers;
    }

    static vector <int> MyPush_back(vector <int> CurrentVector, int ElementToPush)
    {
        if (CurrentVector.empty())
        {
            return { ElementToPush };
        }

        vector <int> New_v(CurrentVector.size() + 1); // add new empty slot to vector at end
        for (short i = 0; i < CurrentVector.size(); i++)
        {
            New_v[i] = CurrentVector[i];
        }
        // push to new empty slot
        New_v[New_v.size() - 1] = ElementToPush;
        return New_v;
    }

    static void PrintVector(vector <int> vData)
    {
        for (short i = 0; i < vData.size(); i++)
        {
            cout << vData[i] << "    ";
        }
    }

    static void PrintVectorInReverseOrder(vector <int> vData)
    {
        for (int i = vData.size() - 1; i >= 0; i--)
        {
            cout << vData.at(i) << "    ";
        }
    }

    static void PrintVectorWithIndexes(vector <int> vData)
    {
        cout << "\nIndex\tValue\n";
        cout << "----------------\n";
        for (short i = 0; i < vData.size(); i++)
        {
            cout << "[" << i << "]\t" << vData[i] << "\n";
        }
    }

    static void MyPop_back(vector <int>& CurrentVector)
    {
        vector <int> UpdatedVector;
        if (CurrentVector.empty())
        {
            cout << "\nOops, vector is empty!\n";
            return;
        }
        for (short i = 0; i < CurrentVector.size() - 1; i++) // CurrentVector.size() - 1 == delete last slot
        {
            UpdatedVector = MyPush_back(UpdatedVector, CurrentVector[i]);
        }
        CurrentVector = UpdatedVector;
    }

    static short MySize(vector <int> vData)
    {
        short Counter = 0;
        for (short Number : vData)
        {
            Counter += 1;
        }
        return Counter;
    }

    static int MaxNumber(vector <int>& vNumbers)
    {
        int MaxNumber = 0;
        for (int& Number : vNumbers)
        {
            if (Number > MaxNumber)
                MaxNumber = Number;
        }
        return MaxNumber;
    }

    static int FindSecondMaxNumber(vector<int> vNumbers)
    {
        int Max = MaxNumber(vNumbers);
        for (int& Number : vNumbers)
        {
            if (Number > Max)
                return Number;
        }
        return Max;
    }

    static int MinNumber(vector <int>& vNumbers)
    {
        int MinNumber = vNumbers[0];
        for (int& Number : vNumbers)
        {
            if (Number < MinNumber)
                MinNumber = Number;
        }
        return MinNumber;
    }

    static short GetIndex(vector <int>& vNumbers, int NumberToSearch)
    {
        for (short i = 0; i < vNumbers.size(); i++)
        {
            if (vNumbers[i] == NumberToSearch)
                return i;
        }
        return -1;
    }

    static bool IsNumberExist(vector <int>& vNumbers, int NumberToSearch)
    {
        return GetIndex(vNumbers, NumberToSearch) != -1;
    }

    static short CountNumberFrequency(vector <int> vNumbers, int NumberToSearch)
    {
        if (IsNumberExist(vNumbers, NumberToSearch))
        {
            short FrequencyCounter = 0;
            for (int& Number : vNumbers)
            {
                if (Number == NumberToSearch)
                    FrequencyCounter++;
            }
            return FrequencyCounter;
        }
        return -1;
    }

    static short CountOddNumbers(vector <int> vNumbers)
    {
        short Counter = 0;
        for (int& Number : vNumbers)
        {
            if (IsOddNumber(Number))
                Counter++;
        }
        return Counter;
    }

    static void GetIndexesOfElement(vector <int> vNumbers, int IndexesArray[30], int ElementToSearch)
    {
        if (CountNumberFrequency(vNumbers, ElementToSearch) > 1)
        {
            short Index = 0;
            for (short i = 0; i < vNumbers.size(); i++)
            {
                if (vNumbers[i] == ElementToSearch)
                {
                    IndexesArray[Index] = i;
                    ++Index;
                }
            }
            PrintArray(IndexesArray, Index + 1);
        }
        else
            cout << "\n" << ElementToSearch << " is repeated 1 time and its index is " << GetIndex(vNumbers, ElementToSearch) << ".\n";
    }

    static int SumVector(vector <int>vNumbers)
    {
        int Sum = 0;
        for (int& Number : vNumbers)
        {
            Sum += Number;
        }
        return Sum;
    }

    static vector <int> CopyVector(vector <int>SourceVector, vector<int>& DestinationVector)
    {
        for (short i = 0; i < SourceVector.size(); i++)
        {
            DestinationVector = MyPush_back(DestinationVector, SourceVector[i]);
        }
        return DestinationVector;
    }

    static vector <int> CopyEvenNumbers(vector <int>vNumbers)
    {
        vector <int>vEvenNumbers;
        for (short i = 0; i < vNumbers.size(); i++)
        {
            if (IsEvenNumber(vNumbers[i]))
                vEvenNumbers = MyPush_back(vEvenNumbers, vNumbers[i]);
        }
        return vEvenNumbers;
    }

    static bool IsBiggestNumber(vector <int>& vNumbers, int NumberToCheck, short StartFrom = 0)
    {
        for (short i = StartFrom; i < vNumbers.size(); i++)
        {
            if (vNumbers[i] > NumberToCheck)
                return false;
        }
        return true;
    }

    static bool IsSmallestNumber(vector <int>& vNumbers, int NumberToCheck, short StartFrom = 0)
    {
        for (short i = StartFrom; i < vNumbers.size(); i++)
        {
            if (vNumbers[i] < NumberToCheck)  
                return false;
        }
        return true;
    }

    static void UpdateSpecificElement(vector <int>& vData, short Index, short NewValue)
    {
        if (IsNumberExist(vData, vData[Index]))
        {
            for (short i = 0; i < vData.size(); i++)
            {
                if (i == Index)
                {
                    vData[Index] = NewValue;
                    return;
                }
            }
        }
        cout << "\nIndex " << Index << " is not found!\n";
    }

    static vector <int> ReverseVector(vector <int> OriginalVector)
    {
        vector <int> ReversedVector;
        for (int i = OriginalVector.size() - 1; i >= 0; i--)
        {
            ReversedVector = MyPush_back(ReversedVector, OriginalVector[i]);
        }
        return ReversedVector;
    }

    static void ShuffleVector(vector <int>& vData)
    {
        for (short i = 0; i < vData.size(); i++)
        {
            Swap(vData[RandomNumber(0, vData.size() - 1)], vData[RandomNumber(0, vData.size() - 1)]);
        }
    }

    static void DeleteIndex(vector <int>& vOriginalVector, short IndexToDelete)
    {
        if (vOriginalVector.empty())
        {
            cout << "\nVector is empty!\n";
            return;
        }

        if (IndexToDelete < 0)
        {
            cout << "\nInvalid Index!\n";
            return;
        }

        else
        {
            // Shift elements to the left
            for (short i = IndexToDelete; i < vOriginalVector.size() - 1; i++)
            {
                vOriginalVector[i] = vOriginalVector[i + 1];
            }
            // Reduce vector size by 1 (remove last duplicated element)
            vOriginalVector.resize(vOriginalVector.size() - 1);
        }
    }

    static void DeleteLastIndex(vector <int>& vData)
    {
        if (!vData.empty())
            vData.resize(vData.size() - 1);
    }

    static bool AreVectorsEqual(vector <int>& Vector1, vector <int>& Vector2)
    {
        if (Vector1.size() != Vector2.size())
            return false;

        for (short i = 0; i < Vector1.size(); i++)
        {
            if (Vector1[i] != Vector2[i])
                return false;
        }
        return true;
    }

    static string ConcatenateStringFromVector(vector <string>& vWords)
    {
        string Text = "";
        for (short i = 0; i < vWords.size(); i++)
        {
            Text += vWords[i];
        }
        return Text;
    }
};