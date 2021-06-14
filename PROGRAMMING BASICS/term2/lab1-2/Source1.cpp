#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <fstream>

using namespace std;
// структура и её поля(переменные)
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
        cout << "\nСтудент № " << i + 1 << "\nФамилия - " << arr[i].surname << "\nНомер группы - " << arr[i].groupNumber << "\nДата рождения - "
            << arr[i].birthDate << "\nОценка по математике - " << arr[i].mathMark << "\nОценка по информатике - " << arr[i].informaticsMark
            << "\nОценка по физике - " << arr[i].physicsMark << "\nОценка по химии - " << arr[i].physicsMark << "\nСредний балл - " << arr[i].average << endl;


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
        cout << "Введите фамилию " << i + 1 << "-ого студента:";
        cin >> arr[i].surname;
        cout << "Введите дату рождения " << i + 1 << "-ого студента:";
        cin >> arr[i].birthDate;
        cout << "Введите номер группы " << i + 1 << "-ого студента:";
        cin >> arr[i].groupNumber;
        cout << "Введите оценку по математике " << i + 1 << "-ого студента:";
        cin >> arr[i].mathMark;
        cout << "Введите оценку по физике " << i + 1 << "-ого студента:";
        cin >> arr[i].physicsMark;
        cout << "Введите оценку по информатике " << i + 1 << "-ого студента:";
        cin >> arr[i].informaticsMark;
        cout << "Введите оценку по химии " << i + 1 << "-ого студента:";
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
    // изменение кодировки ввода-вывода
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    bool exit = false;
    int index = 0;
    int choice;
    do
    {
        cout << "1 - Создание.\n";
        cout << "2 - Просмотр.\n";
        cout << "3 - Редактирование данных в файле.\n";
        cout << "4 - Сортировка(индивидуальное задание).\n";
        cout << "5 - Очистка содержимого файла и массива объектов структур.\n";
        cout << "6 - Выход.\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            // тут создаются объекты структур и имеется возможность добавлять объекты структур
            int n;
            cout << "Введите кол-во студентов:";
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
                    cout << "Нет студентов в массиве объектов структуры!\n";
                    break;
                }
                PrintStudentInformation(index);
                cout << "Для редактирования доступно " << index << " студент(ов) \nВыберите номер студента\t";
                int number;
                cin >> number;
                if (number > index)
                {
                    cout << "Номер введен некорректно!\n";
                    break;
                }
                int choiceOfParam;
                cout << "Параметр для изменения:\n1 - Фамилия;\n2 - Дата рождения;\n3 - Номер группы;\n4 - Оценка по математике;\n5 - Оценка по физике;\n6 - Оценка по информатике;\n7 - Оценка по химии;\n8 - Без изменений\n";
                cin >> choiceOfParam;
                switch (choiceOfParam)
                {
                case 1:
                    cout << "Введите фамилию " << number << "-ого студента:";
                    cin >> arr[number - 1].surname;
                    break;
                case 2:
                    cout << "Введите дату рождения " << number << "-ого студента:";
                    cin >> arr[number - 1].birthDate;
                    break;
                case 3:
                    cout << "Введите номер группы " << number << "-ого студента:";
                    cin >> arr[number - 1].groupNumber;
                    break;
                case 4:
                    cout << "Введите оценку по математике " << number << "-ого студента:";
                    cin >> arr[number - 1].mathMark;
                    arr[number - 1].average = (static_cast<double>(arr[number - 1].chemistryMark) + arr[number - 1].informaticsMark + arr[number - 1].physicsMark
                        + arr[number - 1].mathMark) / 4;
                    break;
                case 5:
                    cout << "Введите оценку по физике " << number << "-ого студента:";
                    cin >> arr[number - 1].physicsMark;
                    arr[number - 1].average = (static_cast<double>(arr[number - 1].chemistryMark) + arr[number - 1].informaticsMark + arr[number - 1].physicsMark
                        + arr[number - 1].mathMark) / 4;
                    break;
                case 6:
                    cout << "Введите оценку по информатике " << number << "-ого студента:";
                    cin >> arr[number - 1].informaticsMark;
                    arr[number - 1].average = (static_cast<double>(arr[number - 1].chemistryMark) + arr[number - 1].informaticsMark + arr[number - 1].physicsMark
                        + arr[number - 1].mathMark) / 4;
                    break;
                case 7:
                    cout << "Введите оценку по химии " << number << "-ого студента:";
                    cin >> arr[number - 1].chemistryMark;
                    arr[number - 1].average = (static_cast<double>(arr[number - 1].chemistryMark) + arr[number - 1].informaticsMark + arr[number - 1].physicsMark
                        + arr[number - 1].mathMark) / 4;
                    break;
                default:
                    break;
                }

                cout << "Продолжить? y/n\t";
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
                cout << "\nСтудент номер " << i + 1 << "\nФамилия - " << arr[i].surname << "\nНомер группы - " << arr[i].groupNumber << "\nДата рождения - "
                    << arr[i].birthDate << "\nОценка по математике - " << arr[i].mathMark << "\nОценка по информатике - " << arr[i].informaticsMark
                    << "\nОценка по физике - " << arr[i].physicsMark << "\nОценка по химии - " << arr[i].physicsMark << "\nСредний балл - " << arr[i].average << endl;
            }
            data_input.close();
            break;
        case 4:
            data_output.open("data.txt", ios_base::app);
            data_output << "Студенты сдавшие сессию на 8, 9 и 10:";
            data_output << endl;
            // Распечатать анкетные данные студентов, сдавших сессию на 8, 9 и 10.
            // вывожу их в файл и на экран
            for (int i = 0; i < index; i++)
            {
                if (arr[i].mathMark < 8 || arr[i].physicsMark < 8 || arr[i].informaticsMark < 8 || arr[i].chemistryMark < 8)
                {
                    continue;
                }
                data_output << arr[i].surname << " " << arr[i].birthDate << " " << arr[i].groupNumber << " " << arr[i].mathMark
                    << " " << arr[i].physicsMark << " " << arr[i].informaticsMark << " " << arr[i].chemistryMark << " " << arr[i].average;
                data_output << endl;
                cout << "\nФамилия - " << arr[i].surname << "\nНомер группы - " << arr[i].groupNumber << "\nДата рождения - "
                    << arr[i].birthDate << "\nОценка по математике - " << arr[i].mathMark << "\nОценка по информатике - " << arr[i].informaticsMark
                    << "\nОценка по физике - " << arr[i].physicsMark << "\nОценка по химии - " << arr[i].physicsMark << "\nСредний балл - " << arr[i].average << endl;

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