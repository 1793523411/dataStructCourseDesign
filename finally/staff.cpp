#include <iostream>
#include <string>
#include <fstream>
//#include <ctime>
#include <sstream>
#include <cstdlib>
#include <ctime>
#define random(a, b) (rand() % (b - a + 1) + a)
#include "staff.h"

using namespace std;

void staff::registeration(class staff *head)
{
    staff *t = new staff;
    staff *q = new staff;
    q = head;
    t = head->next;
    int count2 = 1;
    while (head->next != NULL)
    {
        head = head->next;
    }
    staff *newnode = new staff;
    head->next = newnode;
    cout << "������Ա��id" << endl;
    cout << "id: " << endl;
    string id;
    // cin >> id;
    //cin >> newnode->employee_number;
    while (count2 == 1)
    {
        cin >> id;
        count2 = 0;
        while (t != NULL)
        {
            if (t->employee_number == id)
            {
                // cout << "��id��Ա�Ѵ���" << endl;
                count2 = 1;
            }
            t = t->next;
        }
        if (count2 == 1)
        {
            cout << "��id��Ա�Ѵ���,����������" << endl;
        }
        else
        {
            cout << "��ӳɹ�" << endl;
        }
        t = q;
    }
    newnode->employee_number = id;

    cout << "ְ������: " << endl;
    cin >> newnode->name;

    cout << "ְ������: " << endl;
    while (cin >> newnode->age)
    {
        if (newnode->age > 100 || newnode->age == 100 || newnode->age < 0 || newnode->age == 0)
        {
            cout << "�����������е㲻̫��������������" << endl;
        }
        else
        {
            break;
        }
    }

    cout << "ְ����������: " << endl;
    cout << "�����·�" << endl;
    string month;
    cin >> month;
    cout << "��������" << endl;
    string day;
    cin >> day;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    stringstream s;
    s << 1900 + ltm->tm_year - newnode->age;
    string year = s.str();
    s.str("");

    s << ltm->tm_mon;
    string monthh = s.str();
    s.str("");

    s << ltm->tm_mday;
    string dayy = s.str();
    //cout << year << "-" << month << endl;
    string str;
    str = year + "-" + month + "-" + day;
    cout << "����֮��Ϊ(����������������Ŷ��):" << endl;
    //cout<<str<<endl;
    newnode->birth = str;
    cout << str << endl;

    //string str;
    //strcat(str, year);

    //cin >> newnode->birth;

    cout << "ְ��ѧ��: " << endl;
    cout << "----------------------------" << endl;
    cout << "��ѡ��ѧ��" << endl;
    cout << "1.�о���" << endl;
    cout << "2.������" << endl;
    cout << "3.ר����" << endl;
    cout << "4.Сѧ��" << endl;
    cout << "----------------------------" << endl;
    int num_study;

    int nn = 1;
    while (nn == 1)
    {
        cin >> num_study;
        switch (num_study)
        {
        case 1:
        {
            newnode->study = "�о���";
            cout << "�о���" << endl;
            nn = 0;
            break;
        }
        case 2:
        {
            newnode->study = "������";
            cout << "������" << endl;
            nn = 0;
            break;
        }
        case 3:
        {
            newnode->study = "ר����";
            cout << "ר����" << endl;
            nn = 0;
            break;
        }
        case 4:
        {
            newnode->study = "Сѧ��";
            cout << "Сѧ��" << endl;
            nn = 0;
            break;
        }
        default:
        {
            // newnode->study = "�о���";
            cout << "������������ȷ�����" << endl;
            continue;
        }
        }
    }

    //cin >> newnode->study;
    cout << "ְ����������(Ϊ��ǰ����ִ�е�ʱ��): " << endl;

    //time_t now = time(0);
    //tm *ltm = localtime(&now);
    //char *dt = ctime(&now);
    //work = dt;
    //stringstream s;
    s << 1900 + ltm->tm_year;
    string year1 = s.str();
    s.str("");

    s << ltm->tm_mon;
    string month1 = s.str();
    s.str("");

    s << ltm->tm_mday;
    string day1 = s.str();
    s.str("");

    s << ltm->tm_hour;
    string hour = s.str();
    s.str("");

    s << ltm->tm_min;
    string min = s.str();
    s.str("");

    s << ltm->tm_sec;
    string sec = s.str();

    string dt = year + "-" + month + "-" + day + "-" + hour + "��" + min + "��" + sec;
    newnode->work = dt;

    //newnode->work = "/"+dt+"/";
    cout << "��ǰʱ��Ϊ��ʱ���ѱ���ʽ���洢����" << endl;
    cout
        << 1900 + ltm->tm_year << "��" << ltm->tm_mon << "��" << ltm->tm_mday << "��"
        << "--" << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
    //cin >> newnode->work;

    cout << "ְ���Ա�: " << endl;

    int sex1;
    cout << "��ѡ���Ա�:1.��\t2.Ů" << endl;
    int ss = 1;
    while (ss == 1)
    {
        // ss=0;
        cin >> sex1;
        switch (sex1)
        {
        case 1:
        {
            newnode->sex = "��";
            ss = 0;
            break;
        }
        case 2:
        {
            newnode->sex = "Ů";
            ss = 0;
            break;
        }
        default:
        {
            cout << "ѡ�����,������ѡ��" << endl;
            continue;
        }
        }
    }

    //cin >> newnode->sex;
    cout << "ְ��סַ: " << endl;
    cin >> newnode->address;
    cout << "ְ��ְ��: " << endl;
    cin >> newnode->department;
    cout << "ְ���绰: " << endl;
    while (cin >> newnode->phone)
    {
        if (((newnode->phone).length()) != 11)
        {
            cout << "������ĵ绰�����ʽ����(��׼Ϊ11λ)������������" << endl;
        }
        else
        {
            break;
        }
    }
}

void staff::show_all(class staff *head)
{
    cout << "(*^��^*)(*^��^*)(*^��^*)(*^��^*)(*^��^*)" << endl;
    int i = 0;
    if (head->next == NULL)
    {
        cout << "һ����ԱҲû�У�������һ����~~~" << endl;
    }
    else
    {
        while (head->next != NULL)
        {
            i++;
            cout << i << "."
                 << "id��";
            cout << head->next->employee_number << '\t';

            cout << "���֣�";
            cout << head->next->name << '\t';

            cout << "�Ա�";
            cout << head->next->sex << '\t';

            cout << "���䣺";
            cout << head->next->age << '\t';

            cout << "ѧ����";
            cout << head->next->study << '\t';

            cout << "�������£�";
            cout << head->next->birth << '\t';

            cout << "�������£�";
            cout << head->next->work << '\t';

            cout << "סַ��";
            cout << head->next->address << '\t';

            cout << "ְ��";
            cout << head->next->department << '\t';

            cout << "�绰��";
            cout << head->next->phone << endl;
            head = head->next;
        }
    }
    cout << "(*^��^*)(*^��^*)(*^��^*)(*^��^*)(*^��^*)" << endl;
}

void staff::query_name(class staff *t)
{
    string n;
    cout << "������Ҫ���ҵ�ְ������" << endl;
    cin >> n;
    int count = 0;
    while (t->next != NULL)
    {
        if (t->next->name == n)
        {
            cout << "id��";
            cout << t->next->employee_number << '\t';

            cout << "���֣�";
            cout << t->next->name << '\t';

            cout << "�Ա�";
            cout << t->next->sex << '\t';

            cout << "���䣺";
            cout << t->next->age << '\t';

            cout << "ѧ����";
            cout << t->next->study << '\t';

            cout << "�������£�";
            cout << t->next->birth << '\t';

            cout << "�������£�";
            cout << t->next->work << '\t';

            cout << "סַ��";
            cout << t->next->address << '\t';

            cout << "ְ��";
            cout << t->next->department << '\t';

            cout << "�绰��";
            cout << t->next->phone << endl;
            count++;
        }
        t = t->next;
    }
    if (count == 0)
    {
        cout << "���޴��ˣ�����ѡ��" << endl;
    }
}

void staff::query_depart(class staff *t)
{
    string n;
    cout << "�������ѯ��ְ��ְ��" << endl;
    cin >> n;
    int count = 0;
    while (t->next != NULL)
    {
        if (t->next->department == n)
        {
            cout << "id��";
            cout << t->next->employee_number << '\t';

            cout << "���֣�";
            cout << t->next->name << '\t';

            cout << "�Ա�";
            cout << t->next->sex << '\t';

            cout << "���䣺";
            cout << t->next->age << '\t';

            cout << "ѧ����";
            cout << t->next->study << '\t';

            cout << "�������£�";
            cout << t->next->birth << '\t';

            cout << "�������£�";
            cout << t->next->work << '\t';

            cout << "סַ��";
            cout << t->next->address << '\t';

            cout << "ְ��";
            cout << t->next->department << '\t';

            cout << "�绰��";
            cout << t->next->phone << endl;
            count++;
        }
        t = t->next;
    }
    if (count == 0)
    {
        cout << "���޴��ˣ�����ѡ��" << endl;
    }
}

void staff::delete_num(class staff *t)
{
    string n;
    cout << "����Ҫɾ����ְ���˺�" << endl;
    cin >> n;
    int count = 0;
    while (t->next != NULL)
    {
        if (t->next->employee_number == n)
        {
            staff *temp = t->next;
            t->next = t->next->next;
            delete temp;
            temp = NULL;
            cout << "ɾ���ɹ�" << endl;
            count++;
            break;
        }
        t = t->next;
    }
    if (count == 0)
    {
        cout << "���޴��ˣ�����ѡ��" << endl;
    }
}

void staff::delete_name(class staff *t)
{
    string n;
    cout << "����������ɾ��ְ��������:" << endl;
    cin >> n;
    int count = 0;
    while (t->next != NULL)
    {
        if (t->next->name == n)
        {
            staff *temp = t->next;
            t->next = t->next->next;
            delete temp;
            temp = NULL;
            cout << "ɾ���ɹ���" << endl;
            count++;
            break;
        }
        t = t->next;
    }
    if (count == 0)
    {
        cout << "���޴��ˣ�����ѡ��" << endl;
    }
}

void staff::update(class staff *head)
{
    int num = 0;
    cout << "++++++++1.�޸�Աid+++++++++++++++++" << endl;
    cout << "++++++++2.�޸�Ա������+++++++++++++" << endl;
    cout << "++++++++3.�޸�Ա������+++++++++++++" << endl;
    cout << "++++++++4.�޸�Ա���Ա�+++++++++++++" << endl;
    cout << "++++++++5.�޸�Ա��סַ+++++++++++++" << endl;
    cout << "++++++++6.�޸�Ա��ְ��+++++++++++++" << endl;
    cout << "++++++++7.�޸�Ա���绰+++++++++++++" << endl;
    cout << "++++++++8.�޸�Ա����������+++++++++" << endl;
    cout << "++++++++9.�޸�Ա��ѧ��+++++++++++++" << endl;
    cout << "++++++++10.�޸�ȫ��++++++++++++++++" << endl;
    cout << "++++++++0.������һҳ+++++++++++++++" << endl;
    cin >> num;
    switch (num)
    {
    case 1:
        update_num(head);
        break;
    case 2:
        update_name(head);
        break;
    case 3:
        update_age(head);
        break;
    case 4:
        update_sex(head);
        break;
    case 5:
        update_address(head);
        break;
    case 6:
        update_depart(head);
        break;
    case 7:
        update_phone(head);
        break;
    case 10:
        update_all(head);
        break;
    case 9:
        update_study(head);
        break;
    case 8:
        update_work(head);
        break;
    case 0:
        break;
    default:
        cout << "������������ȷ��ָ�" << endl;
    }
}

void staff::update_num(class staff *head)
{
    staff *t = new staff;
    staff *q = new staff;
    q = head;
    t = head->next;
    int count2 = 1;
    int count = 0;
    cout << "����Ҫ�޸ĵĶ����id" << endl;

    while (count == 0)
    {
        cout << "������Ҫ�޸ĵĶ���id:";
        string id;
        cin >> id;

        while (head->next != NULL)
        {
            if (id == head->next->employee_number)
            {
                count = 1;
                while (count2 == 1)
                {
                    cout << "�������޸ĺ��id:";
                    cin >> id;
                    count2 = 0;
                    while (t != NULL)
                    {
                        if (t->employee_number == id)
                        {
                            // cout << "��id��Ա�Ѵ���" << endl;
                            count2 = 1;
                        }
                        t = t->next;
                    }
                    if (count2 == 1)
                    {
                        cout << "��id��Ա�Ѵ���,����������" << endl;
                    }
                    else
                    {
                        cout << "�޸ĳɹ�" << endl;
                        head->next->employee_number = id;
                        break;
                    }
                    t = q;
                }

                //cout << "�޸ĳɹ�" << endl;
            }
            head = head->next;
            // if (count2 == 0)
            // {
            //     break;
            // }
        }
        if (count == 0)
        {
            cout << "���˴��ˣ�����ѡ��" << endl;
        }
        head = q;
    }
}

void staff::update_name(class staff *head)
{
    staff *q = new staff;
    q = head;
    cout << "����Ҫ�޸Ķ����id��" << endl;
    int count = 0;
    string temp;

    while (count == 0)
    {
        cin >> temp;
        while (head->next != NULL)
        {
            if (temp == head->next->employee_number)
            {
                count = 1;
                cout << "���������֣�" << endl;
                string temp2;
                cin >> temp2;
                head->next->name = temp2;
                cout << "�޸ĳɹ�" << endl;
                break;
            }
            head = head->next;
        }
        if (count == 0)
        {
            cout << "���޴��ˣ�����ѡ��" << endl;
        }
        head = q;
    }
}
void staff::update_age(class staff *head)
{
    staff *q = new staff;
    q = head;
    cout << "����Ҫ�޸Ķ����id��" << endl;
    int count = 0;
    string temp;

    while (count == 0)
    {
        cin >> temp;
        while (head->next != NULL)
        {
            if (temp == head->next->employee_number)
            {
                count = 1;
                cout << "���������䣺" << endl;
                int temp2;
                while (cin >> temp2)
                {
                    if (temp2 > 100 || temp2 == 100 || temp2 < 0 || temp2 == 0)
                    {
                        cout << "�����������е㲻̫��������������" << endl;
                    }
                    else
                    {
                        break;
                    }
                }
                head->next->age = temp2;
                cout << "�޸ĳɹ�" << endl;
                break;
            }
            head = head->next;
        }
        if (count == 0)
        {
            cout << "���޴��ˣ�����ѡ��" << endl;
        }
        head = q;
    }
}

void staff::update_sex(class staff *head)
{
    staff *q = new staff;
    q = head;
    cout << "����Ҫ�޸Ķ����id��" << endl;
    int count = 0;
    string temp;

    while (count == 0)
    {
        cin >> temp;
        while (head->next != NULL)
        {
            if (temp == head->next->employee_number)
            {
                count = 1;
                int sex1;
                cout << "��ѡ���Ա�:1.��\t2.Ů\t3.����" << endl;
                int ss = 1;
                while (ss == 1)
                {
                    cin >> sex1;
                    switch (sex1)
                    {
                    case 1:
                    {
                        head->next->sex = "��";
                        ss = 0;
                        break;
                    }
                    case 2:
                    {
                        head->next->sex = "Ů";
                        ss = 0;
                        break;
                    }
                    case 3:
                    {
                        head->next->sex = "����";
                        ss = 0;
                        break;
                    }
                    default:
                    {
                        cout << "ѡ�����,�����½���ѡ��" << endl;
                        continue;
                    }
                    }
                }
                if (ss == 0)
                {
                    cout << "�޸ĳɹ�" << endl;
                    break;
                }
                //head->next->sex = temp2;
            }
            head = head->next;
        }
        if (count == 0)
        {
            cout << "���޴��ˣ�����ѡ��" << endl;
        }
        head = q;
    }
}

void staff::update_study(class staff *head)
{
    staff *q = new staff;
    q = head;
    cout << "����Ҫ�޸Ķ����id��" << endl;
    int count = 0;
    string temp;

    while (count == 0)
    {
        cin >> temp;
        while (head->next != NULL)
        {
            if (temp == head->next->employee_number)
            {
                count = 1;
                cout << "������ѧ����" << endl;
                cout << "----------------------------" << endl;
                cout << "��ѡ��ѧ��" << endl;
                cout << "1.�о���" << endl;
                cout << "2.������" << endl;
                cout << "3.ר����" << endl;
                cout << "4.Сѧ��" << endl;
                cout << "----------------------------" << endl;
                int num_study;

                int mm = 1;
                while (mm == 1)
                {
                    cin >> num_study;
                    switch (num_study)
                    {
                    case 1:
                    {
                        head->next->study = "�о���";
                        cout << "�о���" << endl;
                        mm = 0;
                        break;
                    }
                    case 2:
                    {
                        head->next->study = "������";
                        cout << "������" << endl;
                        mm = 0;
                        break;
                    }
                    case 3:
                    {
                        head->next->study = "ר����";
                        cout << "ר����" << endl;
                        mm = 0;
                        break;
                    }
                    case 4:
                    {
                        head->next->study = "Сѧ��";
                        cout << "Сѧ��" << endl;
                        mm = 0;
                        break;
                    }
                    default:
                    {
                        // newnode->study = "�о���";
                        cout << "��������ȷ�����" << endl;
                        continue;
                    }
                    }
                }

                //head->next->study = temp2;
                cout << "�޸ĳɹ�" << endl;
                break;
            }
            head = head->next;
        }
        if (count == 0)
        {
            cout << "���޴��ˣ�����ѡ��" << endl;
        }
        head = q;
    }
}

void staff::update_work(class staff *head)
{
    staff *q = new staff;
    q = head;
    cout << "����Ҫ�޸Ķ����id��" << endl;
    int count = 0;
    string temp;

    while (count == 0)
    {
        cin >> temp;
        while (head->next != NULL)
        {
            if (temp == head->next->employee_number)
            {
                count = 1;
                cout << "�Ƿ���¹���ʱ��(y/n)";
                char ch;
                cin >> ch;
                if (ch = 'y')
                {
                    cout << "�¹�������Ϊ��" << endl;
                    stringstream s;
                    time_t now = time(0);
                    tm *ltm = localtime(&now);
                    s << 1900 + ltm->tm_year;
                    string year1 = s.str();
                    s.str("");

                    s << ltm->tm_mon;
                    string month1 = s.str();
                    s.str("");

                    s << ltm->tm_mday;
                    string day1 = s.str();
                    s.str("");

                    s << ltm->tm_hour;
                    string hour = s.str();
                    s.str("");

                    s << ltm->tm_min;
                    string min = s.str();
                    s.str("");

                    s << ltm->tm_sec;
                    string sec = s.str();

                    string dt = year1 + "-" + month1 + "-" + day1 + "-" + hour + "��" + min + "��" + sec;
                    head->next->work = dt;

                    //newnode->work = "/"+dt+"/";
                    cout << "��ǰʱ��Ϊ��ʱ���ѱ���ʽ���洢����" << endl;
                    cout
                        << 1900 + ltm->tm_year << "��" << ltm->tm_mon << "��" << ltm->tm_mday << "��"
                        << "--" << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
                    cout << "�޸ĳɹ�" << endl;
                    break;
                }
                else
                {
                    break;
                }
            }
            head = head->next;
        }
        if (count == 0)
        {
            cout << "���޴��ˣ�����ѡ��" << endl;
        }
        head = q;
    }
}

void staff::update_address(class staff *head)
{
    staff *q = new staff;
    q = head;
    cout << "����Ҫ�޸Ķ����id��" << endl;
    int count = 0;
    string temp;

    while (count = 0)
    {
        cin >> temp;
        while (head->next != NULL)
        {
            if (temp == head->next->employee_number)
            {
                count = 1;
                cout << "������סַ��" << endl;
                string temp2;
                cin >> temp2;
                head->next->address = temp2;
                cout << "�޸ĳɹ�" << endl;
                break;
            }
            head = head->next;
        }
        if (count == 0)
        {
            cout << "���޴��ˣ�����ѡ��" << endl;
        }
        head = q;
    }
}

void staff::update_depart(class staff *head)
{
    staff *q = new staff;
    q = head;
    cout << "����Ҫ�޸Ķ����id��" << endl;
    int count = 0;
    string temp;

    while (count == 0)
    {
        cin >> temp;
        while (head->next != NULL)
        {
            if (temp == head->next->employee_number)
            {
                count = 1;
                cout << "������ְ��" << endl;
                string temp2;
                cin >> temp2;
                head->next->department = temp2;
                cout << "�޸ĳɹ�" << endl;
                break;
            }
            head = head->next;
        }
        if (count == 0)
        {
            cout << "���޴��ˣ�����ѡ��" << endl;
        }
        head = q;
    }
}

void staff::update_phone(class staff *head)
{
    staff *q = new staff;
    q = head;
    cout << "����Ҫ�޸Ķ����id��" << endl;
    int count = 0;
    string temp;

    while (count == 0)
    {
        cin >> temp;
        while (head->next != NULL)
        {
            if (temp == head->next->employee_number)
            {
                count = 1;
                cout << "�����µ绰��" << endl;
                string temp2;
                while (cin >> temp2)
                {
                    if (((temp2).length()) != 11)
                    {
                        cout << "������ĵ绰�����ʽ���ԣ�����������" << endl;
                    }
                    else
                    {
                        break;
                    }
                }
                head->next->phone = temp2;
                cout << "�޸ĳɹ�" << endl;
                break;
            }
            head = head->next;
        }
        if (count == 0)
        {
            cout << "���޴��ˣ�����ѡ��" << endl;
        }
        head = q;
    }
}

void staff::update_all(class staff *head)
{
    staff *t = new staff;
    staff *q = new staff;
    q = head;
    t = head->next;
    int count2 = 1;
    cout << "����Ҫ�޸ĵĶ����id" << endl;
    cout << "������Ҫ�޸ĵĶ���id:";
    int tmp;
    int count = 0;
    string temp;

    while (count == 0)
    {
        cin >> temp;
        while (head->next != NULL)
        {
            if (temp == head->next->employee_number)
            {
                count = 1;
                while (count2 == 1)
                {
                    cout << "�������޸ĺ��id:";
                    cin >> temp;
                    count2 = 0;
                    while (t != NULL)
                    {
                        if (t->employee_number == temp)
                        {
                            // cout << "��id��Ա�Ѵ���" << endl;
                            count2 = 1;
                        }
                        t = t->next;
                    }
                    if (count2 == 1)
                    {
                        cout << "��id��Ա�Ѵ���,����������" << endl;
                    }
                    else
                    {
                        cout << "�޸ĳɹ�" << endl;
                        head->next->employee_number = temp;
                        break;
                    }
                    t = q;
                }

                cout << "���������֣�" << endl;
                cin >> temp;
                head->next->name = temp;

                int sex1;
                cout << "��ѡ���Ա�:1.��\t2.Ů\t3.����" << endl;
                int ss = 1;
                while (ss == 1)
                {
                    cin >> sex1;
                    switch (sex1)
                    {
                    case 1:
                    {
                        head->next->sex = "��";
                        ss = 0;
                        break;
                    }
                    case 2:
                    {
                        head->next->sex = "Ů";
                        ss = 0;
                        break;
                    }
                    case 3:
                    {
                        head->next->sex = "����";
                        ss = 0;
                        break;
                    }
                    default:
                    {
                        cout << "ѡ�����,�����½���ѡ��" << endl;
                        continue;
                    }
                    }
                }
                if (ss == 0)
                {
                    cout << "�޸ĳɹ�" << endl;
                    //break;
                }
                //head->next->sex = temp;
                cout << "���������" << endl;
                while (cin >> tmp)
                {
                    if (tmp > 100 || tmp == 100 || tmp < 0 || tmp == 0)
                    {
                        cout << "�����������е㲻̫��������������" << endl;
                    }
                    else
                    {
                        break;
                    }
                }
                head->next->age = tmp;

                cout << "������ѧ����" << endl;
                cout << "----------------------------" << endl;
                cout << "��ѡ��ѧ��" << endl;
                cout << "1.�о���" << endl;
                cout << "2.������" << endl;
                cout << "3.ר����" << endl;
                cout << "4.Сѧ��" << endl;
                cout << "----------------------------" << endl;
                int num_study;
                int dd = 1;
                while (dd == 1)
                {
                    cin >> num_study;
                    switch (num_study)
                    {
                    case 1:
                    {
                        head->next->study = "�о���";
                        cout << "�о���" << endl;
                        head->next->study = "�о���";
                        dd = 0;
                        break;
                    }
                    case 2:
                    {
                        head->next->study = "������";
                        cout << "������" << endl;
                        head->next->study = "������";
                        dd = 0;
                        break;
                    }
                    case 3:
                    {
                        head->next->study = "ר����";
                        cout << "ר����" << endl;
                        head->next->study = "ר����";
                        dd = 0;
                        break;
                    }
                    case 4:
                    {
                        head->next->study = "Сѧ��";
                        cout << "Сѧ��" << endl;
                        head->next->study = "Сѧ��";
                        dd = 0;
                        break;
                    }
                    default:
                    {
                        // newnode->study = "�о���";
                        cout << "��������ȷ�����" << endl;
                        continue;
                    }
                    }
                }

                cout << "�����¹������£�" << endl;
                cout << "�Ƿ���¹���ʱ��(y/n)";
                char ch;
                cin >> ch;
                if (ch = 'y')
                {
                    cout << "�¹�������Ϊ��";
                    stringstream s;
                    time_t now = time(0);
                    tm *ltm = localtime(&now);
                    s << 1900 + ltm->tm_year;
                    string year1 = s.str();
                    s.str("");

                    s << ltm->tm_mon;
                    string month1 = s.str();
                    s.str("");

                    s << ltm->tm_mday;
                    string day1 = s.str();
                    s.str("");

                    s << ltm->tm_hour;
                    string hour = s.str();
                    s.str("");

                    s << ltm->tm_min;
                    string min = s.str();
                    s.str("");

                    s << ltm->tm_sec;
                    string sec = s.str();

                    string dt = year1 + "-" + month1 + "-" + day1 + "-" + hour + "��" + min + "��" + sec;
                    head->next->work = dt;

                    //newnode->work = "/"+dt+"/";
                    cout << "��ǰʱ��Ϊ��ʱ���ѱ���ʽ���洢����" << endl;
                    cout
                        << 1900 + ltm->tm_year << "��" << ltm->tm_mon << "��" << ltm->tm_mday << "��"
                        << "--" << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
                    cout << "�޸ĳɹ�" << endl;
                    //break;
                }
                else
                {
                    //break;
                }
                head->next->work = tmp;

                cout << "������סַ��" << endl;
                cin >> temp;
                head->next->address = temp;

                cout << "������ְ��" << endl;
                cin >> temp;
                head->next->department = temp;

                cout << "�����µ绰��" << endl;
                while (cin >> head->next->phone)
                {
                    if (((head->next->phone).length()) != 11)
                    {
                        cout << "������ĵ绰�����ʽ���ԣ�����������" << endl;
                    }
                    else
                    {
                        break;
                    }
                }
                head->next->phone = temp;
                cout << "�޸ĳɹ�" << endl;
                break;
            }
            head = head->next;
        }
        if (count == 0)
        {
            cout << "���޴��ˣ�����ѡ��" << endl;
        }
        head = q;
    }
}

void staff::sort_up(class staff *head)
{
    class staff *temp, *r, *p, *q, *s;
    temp = head;
    while (temp->next != NULL)
    {
        q = temp->next;
        r = q;
        p = q->next;
        while (p)
        {
            if (p->age < q->age)
            {
                s = r;
                q = p;
            }
            r = p;
            p = p->next;
        }
        if (q != temp->next)
        {
            s->next = q->next;
            q->next = temp->next;
            temp->next = q;
        }
        temp = q;
    }
}

void staff::sort_down(class staff *head)
{
    class staff *temp, *r, *p, *q, *s;
    temp = head;
    while (temp->next != NULL)
    {
        q = temp->next;
        r = q;
        p = q->next;
        while (p)
        {
            if (p->age > q->age)
            {
                s = r;
                q = p;
            }
            r = p;
            p = p->next;
        }
        if (q != temp->next)
        {
            s->next = q->next;
            q->next = temp->next;
            temp->next = q;
        }
        temp = q;
    }
}

void staff::sort_nup(class staff *head)
{
    //cout<<"~~~~~~~~"<<head->next->name[0]<<endl;
    //int a = (head->next->name[0]>head->next->name[1])?1:2;
    //cout<<a<<endl;
    class staff *temp, *r, *p, *q, *s;
    temp = head;
    while (temp->next != NULL)
    {
        q = temp->next;
        r = q;
        p = q->next;
        while (p)
        {
            if (p->name[0] < q->name[0])
            {
                s = r;
                q = p;
            }
            r = p;
            p = p->next;
        }
        if (q != temp->next)
        {
            s->next = q->next;
            q->next = temp->next;
            temp->next = q;
        }
        temp = q;
    }
}

void staff::sort_ndown(class staff *head)
{
    //cout<<"~~~~~~~~"<<head->next->name[0]<<endl;
    //int a = (head->next->name[0]>head->next->name[1])?1:2;
    //cout<<a<<endl;
    class staff *temp, *r, *p, *q, *s;
    temp = head;
    while (temp->next != NULL)
    {
        q = temp->next;
        r = q;
        p = q->next;
        while (p)
        {
            if (p->name[0] > q->name[0])
            {
                s = r;
                q = p;
            }
            r = p;
            p = p->next;
        }
        if (q != temp->next)
        {
            s->next = q->next;
            q->next = temp->next;
            temp->next = q;
        }
        temp = q;
    }
}

int staff::read(class staff *head)
{
    ofstream infile1;
    infile1.open("test.txt", ios::app);
    if (!infile1)
    {
        return 0;
    }
    else
    {
        infile1.close();
        ifstream infile;
        infile.open("test.txt", ios::in);
        while (!infile.eof())
        {
            staff *newnode = new staff;
            infile >> newnode->employee_number;
            if (newnode->employee_number.length() == 0)
            {
                delete newnode;
                break;
            }
            infile >> newnode->name;
            infile >> newnode->sex;
            infile >> newnode->age;
            infile >> newnode->study;
            infile >> newnode->birth;
            infile >> newnode->work;
            infile >> newnode->address;
            infile >> newnode->department;
            infile >> newnode->phone;
            head->next = newnode;
            head = head->next;
        }
        infile.close();
    }
    return 0;
}

void staff::write(class staff *t)
{
    ofstream outfile;
    outfile.open("test.txt", ios::out);
    while (t->next != NULL)
    {
        outfile << t->next->employee_number << '\t';
        outfile << t->next->name << '\t';
        outfile << t->next->sex << '\t';
        outfile << t->next->age << '\t';
        outfile << t->next->study << '\t';
        outfile << t->next->birth << '\t';
        outfile << t->next->work << '\t';
        outfile << t->next->address << '\t';
        outfile << t->next->department << '\t';
        outfile << t->next->phone << endl;
        t = t->next;
    }
    outfile.close();
}

void staff::hahaha(class staff *head)
{
    //	staff *t = new staff;
    ofstream outfile;
    staff *q = new staff;
    q = head;
    outfile.open("test.txt", ios::app);
    int num;
    int i = 0;
    cout << "��������" << endl;
    cin >> num;
    srand((unsigned)time(NULL));
    //cout<<""<endl;
    while (i < num)
    {
        //	staff *t = new staff;
        while (head->next != NULL)
        {
            head = head->next;
        }
        staff *t = new staff;
        head->next = t;
        stringstream s;
        s.str("");
        s << i;
        string min = s.str();
        t->employee_number = min;
        outfile << t->employee_number << '\t';
        t->name = "test" + min;
        outfile << t->name << '\t';
        t->sex = "Ů";
        outfile << t->sex << '\t';
        t->age = random(1, 100);
        outfile << t->age << '\t';
        t->study = "������";
        outfile << t->study << '\t';
        t->birth = "2000-10-1";
        outfile << t->birth << '\t';
        t->work = "2000-6-15-9��20��3";
        outfile << t->work << '\t';
        t->address = "����343";
        outfile << t->address << '\t';
        t->department = "ѧ��";
        outfile << t->department << '\t';
        t->phone = "15670880671";
        outfile << t->phone << endl;
        i++;
        //t = t->next;
        head = q;
    }
    outfile.close();
}
