#include <iostream>
#include <string>
#include <fstream>

#include "staff.cpp"
//#include "staff.h"

using namespace std;

int main()
{
    staff *head = new staff;
    head->read(head);
    string temp;
    cout << "简单的职工管理系统--课程设计" << endl;
    while (1)
    {
        cout << "--------`-1`.显示所有成员-----------------------------------------------" << endl;
        cout << "--------1.注册员工id（注册完毕后默认按名字字典升序存储在文件中）--------" << endl;
        cout << "--------2.按照姓名查询员工信息------------------------------------------" << endl;
        cout << "--------3.按照职务查询员工信息------------------------------------------" << endl;
        cout << "--------4.按id删除员工信息----------------------------------------------" << endl;
        cout << "--------5.按姓名删除员工信息--------------------------------------------" << endl;
        cout << "--------6.按年纪升序排列------------------------------------------------" << endl;
        cout << "--------7.按年纪降序排列------------------------------------------------" << endl;
        cout << "--------8.修改员工信息--------------------------------------------------" << endl;
        cout << "--------9.按名字字典升排序----------------------------------------------" << endl;
        cout << "--------10.按名字字典降排序---------------------------------------------" << endl;
        cout << "--------11.生成排序数据-------------------------------------------------" << endl;
        cout << "--------0.退出----------------------------------------------------------" << endl;
        cout << endl;
        cout << "请输入你想选择的功能：" << endl;
        int number;
        cin >> number;
        switch (number)
        {
        case -1:
        {
            head->show_all(head);
            break;
        }
        case 1:
        {
            head->registeration(head);
            head->sort_nup(head);
            head->write(head);
            break;
        }
        case 2:
        {
            head->query_name(head);
            break;
        }
        case 3:
        {
            head->query_depart(head);
            break;
        }
        case 4:
        {
            head->delete_num(head);
            head->write(head);
            break;
        }
        case 5:
        {
            head->delete_name(head);
            head->write(head);
            break;
        }
        case 6:
        {
            head->sort_up(head);
            head->write(head);
            cout << "排序完成------------------" << endl;
            cout << "是否显示排序过后的数据：(1.是/0.否)";
            int x;
            cin >> x;
            if (x == 1)
            {
                head->show_all(head);
                cout << "排序完成------------------" << endl;
            }
            else
            {
                cout << "排序完成------------------" << endl;
            }
            break;
        }
        case 7:
        {
            head->sort_down(head);
            head->write(head);
            cout << "排序完成------------------" << endl;
            cout << "是否显示排序过后的数据：(1.是/0.否)";
            int x;
            cin >> x;
            if (x == 1)
            {
                head->show_all(head);
                cout << "排序完成------------------" << endl;
            }
            else
            {
                cout << "排序完成------------------" << endl;
            }
            break;
        }
        case 8:
        {
            head->update(head);
            head->sort_nup(head);
            head->write(head);
            break;
        }
        case 9:
        {
            head->sort_nup(head);
            head->write(head);
            cout << "排序完成------------------" << endl;
            cout << "是否显示排序过后的数据：(1.是/0.否)";
            int x;
            cin >> x;
            if (x == 1)
            {
                head->show_all(head);
                cout << "排序完成------------------" << endl;
            }
            else
            {
                cout << "排序完成------------------" << endl;
            }
            break;
        }
        case 10:
        {
            head->sort_ndown(head);
            head->write(head);
            cout << "排序完成------------------" << endl;
            cout << "是否显示排序过后的数据：(1.是/0.否)";
            int x;
            cin >> x;
            if (x == 1)
            {
                head->show_all(head);
                cout << "排序完成------------------" << endl;
            }
            else
            {
                cout << "排序完成------------------" << endl;
            }
            break;
        }
        case 11:
        {
            head->hahaha(head);
            head->write(head);
            cout << "数据生成完毕" << endl;
            break;
        }
        case 0:
        {
            char sign;
            cout << "是否要退出（y/n）?";
            cin >> sign;
            switch (sign)
            {
            case 'y':
            {
                head->write(head);
                return 0;
            }
            case 'n':
            {
                break;
            }
            default:
                cout << "请输入正确的指令" << endl;
                continue;
            }
        }
        default:
            cout << "请输入正确的指令" << endl;
        }
    }
    //system("chcp 65001");
}
