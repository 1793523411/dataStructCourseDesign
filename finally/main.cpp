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
    cout << "�򵥵�ְ������ϵͳ--�γ����" << endl;
    while (1)
    {
        cout << "--------`-1`.��ʾ���г�Ա-----------------------------------------------" << endl;
        cout << "--------1.ע��Ա��id��ע����Ϻ�Ĭ�ϰ������ֵ�����洢���ļ��У�--------" << endl;
        cout << "--------2.����������ѯԱ����Ϣ------------------------------------------" << endl;
        cout << "--------3.����ְ���ѯԱ����Ϣ------------------------------------------" << endl;
        cout << "--------4.��idɾ��Ա����Ϣ----------------------------------------------" << endl;
        cout << "--------5.������ɾ��Ա����Ϣ--------------------------------------------" << endl;
        cout << "--------6.�������������------------------------------------------------" << endl;
        cout << "--------7.����ͽ�������------------------------------------------------" << endl;
        cout << "--------8.�޸�Ա����Ϣ--------------------------------------------------" << endl;
        cout << "--------9.�������ֵ�������----------------------------------------------" << endl;
        cout << "--------10.�������ֵ併����---------------------------------------------" << endl;
        cout << "--------11.������������-------------------------------------------------" << endl;
        cout << "--------0.�˳�----------------------------------------------------------" << endl;
        cout << endl;
        cout << "����������ѡ��Ĺ��ܣ�" << endl;
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
            cout << "�������------------------" << endl;
            cout << "�Ƿ���ʾ�����������ݣ�(1.��/0.��)";
            int x;
            cin >> x;
            if (x == 1)
            {
                head->show_all(head);
                cout << "�������------------------" << endl;
            }
            else
            {
                cout << "�������------------------" << endl;
            }
            break;
        }
        case 7:
        {
            head->sort_down(head);
            head->write(head);
            cout << "�������------------------" << endl;
            cout << "�Ƿ���ʾ�����������ݣ�(1.��/0.��)";
            int x;
            cin >> x;
            if (x == 1)
            {
                head->show_all(head);
                cout << "�������------------------" << endl;
            }
            else
            {
                cout << "�������------------------" << endl;
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
            cout << "�������------------------" << endl;
            cout << "�Ƿ���ʾ�����������ݣ�(1.��/0.��)";
            int x;
            cin >> x;
            if (x == 1)
            {
                head->show_all(head);
                cout << "�������------------------" << endl;
            }
            else
            {
                cout << "�������------------------" << endl;
            }
            break;
        }
        case 10:
        {
            head->sort_ndown(head);
            head->write(head);
            cout << "�������------------------" << endl;
            cout << "�Ƿ���ʾ�����������ݣ�(1.��/0.��)";
            int x;
            cin >> x;
            if (x == 1)
            {
                head->show_all(head);
                cout << "�������------------------" << endl;
            }
            else
            {
                cout << "�������------------------" << endl;
            }
            break;
        }
        case 11:
        {
            head->hahaha(head);
            head->write(head);
            cout << "�����������" << endl;
            break;
        }
        case 0:
        {
            char sign;
            cout << "�Ƿ�Ҫ�˳���y/n��?";
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
                cout << "��������ȷ��ָ��" << endl;
                continue;
            }
        }
        default:
            cout << "��������ȷ��ָ��" << endl;
        }
    }
    //system("chcp 65001");
}
