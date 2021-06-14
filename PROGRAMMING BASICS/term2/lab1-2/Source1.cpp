#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <fstream>

using namespace std;
// ��������� � � ����(����������)
struct Student
{
    string surname;
    string birthDate;
    int groupNumber = 0;
    int physicsMark = 0;
    int mathMark = 0;
    int informaticsMark = 0;
    int chemistryMark = 0;
    double average = 0;
};

ifstream data_input;
ofstream data_output;

Student arr[100];

void PrintStudentInformation(int index)
{
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    for (int i = 0; i < index; i++)
    {
        cout << "\n������� � " << i + 1 << "\n������� - " << arr[i].surname << "\n����� ������ - " << arr[i].groupNumber << "\n���� �������� - "
            << arr[i].birthDate << "\n������ �� ���������� - " << arr[i].mathMark << "\n������ �� ����������� - " << arr[i].informaticsMark
            << "\n������ �� ������ - " << arr[i].physicsMark << "\n������ �� ����� - " << arr[i].physicsMark << "\n������� ���� - " << arr[i].average << endl;


    }
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}
int CreateAndFillStudentsArray(int n, int startIndex)
{
    if (startIndex + n > 100)
    {
        cout << "Overflow exception\n";
        throw exception();
    }

    data_output.open("data.txt", ios_base::app);
    for (int i = startIndex; i < n + startIndex; i++)
    {
        cout << "������� ������� " << i + 1 << "-��� ��������:";
        cin >> arr[i].surname;
        cout << "������� ���� �������� " << i + 1 << "-��� ��������:";
        cin >> arr[i].birthDate;
        cout << "������� ����� ������ " << i + 1 << "-��� ��������:";
        cin >> arr[i].groupNumber;
        cout << "������� ������ �� ���������� " << i + 1 << "-��� ��������:";
        cin >> arr[i].mathMark;
        cout << "������� ������ �� ������ " << i + 1 << "-��� ��������:";
        cin >> arr[i].physicsMark;
        cout << "������� ������ �� ����������� " << i + 1 << "-��� ��������:";
        cin >> arr[i].informaticsMark;
        cout << "������� ������ �� ����� " << i + 1 << "-��� ��������:";
        cin >> arr[i].chemistryMark;
        arr[i].average = (static_cast<double>(arr[i].chemistryMark) + arr[i].physicsMark + arr[i].informaticsMark + arr[i].mathMark) / 4;
        data_output << arr[i].surname << " " << arr[i].birthDate << " " << arr[i].groupNumber << " " << arr[i].mathMark << " " << arr[i].physicsMark << " "
            << arr[i].informaticsMark << " " << arr[i].chemistryMark << " " << arr[i].average;
        data_output << endl;
    }

    data_output.close();
    return n;
}

void clearfile()
{
    data_output.open("data.txt", ofstream::out | ofstream::trunc);
    data_output.close();
}

int main()
{
    // ��������� ��������� �����-������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    bool exit = false;
    int index = 0;
    int choice;
    do
    {
        cout << "1 - ��������.\n";
        cout << "2 - ��������.\n";
        cout << "3 - �������������� ������ � �����.\n";
        cout << "4 - ����������(�������������� �������).\n";
        cout << "5 - ������� ����������� ����� � ������� �������� ��������.\n";
        cout << "6 - �����.\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            // ��� ��������� ������� �������� � ������� ����������� ��������� ������� ��������
            int n;
            cout << "������� ���-�� ���������:";
            cin >> n;
            index = CreateAndFillStudentsArray(n, index);
            break;
        case 2:
            PrintStudentInformation(index);
            break;
        case 3:
            do
            {
                if (index == 0)
                {
                    cout << "��� ��������� � ������� �������� ���������!\n";
                    break;
                }
                PrintStudentInformation(index);
                cout << "��� �������������� �������� " << index << " �������(��) \n�������� ����� ��������\t";
                int number;
                cin >> number;
                if (number > index)
                {
                    cout << "����� ������ �����������!\n";
                    break;
                }
                int choiceOfParam;
                cout << "�������� ��� ���������:\n1 - �������;\n2 - ���� ��������;\n3 - ����� ������;\n4 - ������ �� ����������;\n5 - ������ �� ������;\n6 - ������ �� �����������;\n7 - ������ �� �����;\n8 - ��� ���������\n";
                cin >> choiceOfParam;
                switch (choiceOfParam)
                {
                case 1:
                    cout << "������� ������� " << number << "-��� ��������:";
                    cin >> arr[number - 1].surname;
                    break;
                case 2:
                    cout << "������� ���� �������� " << number << "-��� ��������:";
                    cin >> arr[number - 1].birthDate;
                    break;
                case 3:
                    cout << "������� ����� ������ " << number << "-��� ��������:";
                    cin >> arr[number - 1].groupNumber;
                    break;
                case 4:
                    cout << "������� ������ �� ���������� " << number << "-��� ��������:";
                    cin >> arr[number - 1].mathMark;
                    arr[number - 1].average = (static_cast<double>(arr[number - 1].chemistryMark) + arr[number - 1].informaticsMark + arr[number - 1].physicsMark
                        + arr[number - 1].mathMark) / 4;
                    break;
                case 5:
                    cout << "������� ������ �� ������ " << number << "-��� ��������:";
                    cin >> arr[number - 1].physicsMark;
                    arr[number - 1].average = (static_cast<double>(arr[number - 1].chemistryMark) + arr[number - 1].informaticsMark + arr[number - 1].physicsMark
                        + arr[number - 1].mathMark) / 4;
                    break;
                case 6:
                    cout << "������� ������ �� ����������� " << number << "-��� ��������:";
                    cin >> arr[number - 1].informaticsMark;
                    arr[number - 1].average = (static_cast<double>(arr[number - 1].chemistryMark) + arr[number - 1].informaticsMark + arr[number - 1].physicsMark
                        + arr[number - 1].mathMark) / 4;
                    break;
                case 7:
                    cout << "������� ������ �� ����� " << number << "-��� ��������:";
                    cin >> arr[number - 1].chemistryMark;
                    arr[number - 1].average = (static_cast<double>(arr[number - 1].chemistryMark) + arr[number - 1].informaticsMark + arr[number - 1].physicsMark
                        + arr[number - 1].mathMark) / 4;
                    break;
                default:
                    break;
                }

                cout << "����������? y/n\t";
                char s;
                cin >> s;
                if (s == 'n')
                {
                    break;
                }

            } while (true);
            clearfile();
            data_output.open("data.txt", ios_base::app);
            for (int i = 0; i < index; i++)
            {
                arr[i].average = (static_cast<double>(arr[i].chemistryMark) + arr[i].physicsMark + arr[i].informaticsMark + arr[i].mathMark) / 4;
                data_output << arr[i].surname << " " << arr[i].birthDate << " " << arr[i].groupNumber << " " << arr[i].mathMark << " " << arr[i].physicsMark << " "
                    << arr[i].informaticsMark << " " << arr[i].chemistryMark << " " << arr[i].average;
                data_output << endl;
                cout << "\n������� ����� " << i + 1 << "\n������� - " << arr[i].surname << "\n����� ������ - " << arr[i].groupNumber << "\n���� �������� - "
                    << arr[i].birthDate << "\n������ �� ���������� - " << arr[i].mathMark << "\n������ �� ����������� - " << arr[i].informaticsMark
                    << "\n������ �� ������ - " << arr[i].physicsMark << "\n������ �� ����� - " << arr[i].physicsMark << "\n������� ���� - " << arr[i].average << endl;
            }
            data_input.close();
            break;
        case 4:
            data_output.open("data.txt", ios_base::app);
            data_output << "�������� ������� ������ �� 8, 9 � 10:";
            data_output << endl;
            // ����������� �������� ������ ���������, ������� ������ �� 8, 9 � 10.
            // ������ �� � ���� � �� �����
            for (int i = 0; i < index; i++)
            {
                if (arr[i].mathMark < 8 || arr[i].physicsMark < 8 || arr[i].informaticsMark < 8 || arr[i].chemistryMark < 8)
                {
                    continue;
                }
                data_output << arr[i].surname << " " << arr[i].birthDate << " " << arr[i].groupNumber << " " << arr[i].mathMark
                    << " " << arr[i].physicsMark << " " << arr[i].informaticsMark << " " << arr[i].chemistryMark << " " << arr[i].average;
                data_output << endl;
                cout << "\n������� - " << arr[i].surname << "\n����� ������ - " << arr[i].groupNumber << "\n���� �������� - "
                    << arr[i].birthDate << "\n������ �� ���������� - " << arr[i].mathMark << "\n������ �� ����������� - " << arr[i].informaticsMark
                    << "\n������ �� ������ - " << arr[i].physicsMark << "\n������ �� ����� - " << arr[i].physicsMark << "\n������� ���� - " << arr[i].average << endl;

            }
            data_output.close();
            break;
        case 5:
            index = 0;
            clearfile();
            break;
        case 6:
            exit = true;
            clearfile();
            break;
        default:
            break;
        }

    } while (!exit);

}