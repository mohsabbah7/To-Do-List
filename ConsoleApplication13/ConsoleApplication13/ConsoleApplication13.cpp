#include <iostream>
#include <windows.h>
#include <string>
#include <cstring>
using namespace std;

void print_tasks(string tasks[], int task_count)
{
    cout << "Tasks To Do: " << endl;
    cout << "-------------------------------------------" << endl;
    for (int i = 0; i < task_count; i++)
    {
        cout << "Task " << i << " : " << tasks[i] << endl;
    }
    cout << "-------------------------------------------" << endl;
}





int main()
{
    system("color D");
    string tasks[10] = { "" };
    //counter var -> know how many tasks we have
    int task_count = 0;

    int option = -1;
    while (option != 0)
    {
        system("cls");
        //we will make menu here
        cout << "\n";
        cout << "*************************************************"<< endl;
        cout << "                ***To Do List***                " << endl;
        cout << "*************************************************" << endl;
        cout << "| 1 - To Add New Task                            |" << endl;
        cout << "| 2 - To View Tasks                              |" << endl;
        cout << "| 3 - Delete The Tasks                           |" << endl;
        cout << "| 0 - Termenate The Program                      |" << endl;
        cout << "*************************************************" << endl;
        cin >> option;

        switch (option)
        {
        case 1:
        {
            if (task_count > 9)
            {
                cout << "```Task List Is Full```" << endl;
            }
            else
            {
                cout << "Enter A New Task: " << endl;
                cin.ignore();
                getline(cin, tasks[task_count]);
                task_count++;
            }
            break;
        }
        case 2:
            system("cls");
            if (task_count == 0)
            {
                cout << "\n***No Tasks To Show ***\n" << endl;
            }
            else
            {
                print_tasks(tasks, task_count);
            }
            system("pause");
            break;

        case 3:
        {
            system("cls");
            print_tasks(tasks, task_count);
            int del_task = 0;
            cout << "Enter A Task To Delete: ";
            cin >> del_task;

            if (del_task < 0 || del_task > 9)
            {
                cout << "You Entered Invalid Task, Try Again" << endl;
                break;
            }
            for (int i = del_task; i < task_count; i++)
            {
                tasks[i] = tasks[i + 1];

            }
            task_count = task_count - 1;
            break;
        }
        case 0:
            cout << "Terminating the Program" << endl;
            break;
        default:
            cout << "You entered Invalid Value!" << endl;
        }

    }


    return 0;
}
