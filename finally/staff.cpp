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
    cout << "请输入员工id" << endl;
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
                // cout << "该id成员已存在" << endl;
                count2 = 1;
            }
            t = t->next;
        }
        if (count2 == 1)
        {
            cout << "该id成员已存在,请重新输入" << endl;
        }
        else
        {
            cout << "添加成功" << endl;
        }
        t = q;
    }
    newnode->employee_number = id;

    cout << "职工姓名: " << endl;
    cin >> newnode->name;

    cout << "职工年龄: " << endl;
    while (cin >> newnode->age)
    {
        if (newnode->age > 100 || newnode->age == 100 || newnode->age < 0 || newnode->age == 0)
        {
            cout << "您输入的年纪有点不太合理，请重新输入" << endl;
        }
        else
        {
            break;
        }
    }

    cout << "职工出生年月: " << endl;
    cout << "输入月份" << endl;
    string month;
    cin >> month;
    cout << "输入日子" << endl;
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
    cout << "出生之年为(根据年龄计算出来的哦！):" << endl;
    //cout<<str<<endl;
    newnode->birth = str;
    cout << str << endl;

    //string str;
    //strcat(str, year);

    //cin >> newnode->birth;

    cout << "职工学历: " << endl;
    cout << "----------------------------" << endl;
    cout << "请选择学历" << endl;
    cout << "1.研究生" << endl;
    cout << "2.本科生" << endl;
    cout << "3.专科生" << endl;
    cout << "4.小学生" << endl;
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
            newnode->study = "研究生";
            cout << "研究生" << endl;
            nn = 0;
            break;
        }
        case 2:
        {
            newnode->study = "本科生";
            cout << "本科生" << endl;
            nn = 0;
            break;
        }
        case 3:
        {
            newnode->study = "专科生";
            cout << "专科生" << endl;
            nn = 0;
            break;
        }
        case 4:
        {
            newnode->study = "小学生";
            cout << "小学生" << endl;
            nn = 0;
            break;
        }
        default:
        {
            // newnode->study = "研究生";
            cout << "请重新输入正确的序号" << endl;
            continue;
        }
        }
    }

    //cin >> newnode->study;
    cout << "职工工作年月(为当前程序执行的时间): " << endl;

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

    string dt = year + "-" + month + "-" + day + "-" + hour + "：" + min + "：" + sec;
    newnode->work = dt;

    //newnode->work = "/"+dt+"/";
    cout << "当前时间为（时间已被格式化存储）：" << endl;
    cout
        << 1900 + ltm->tm_year << "年" << ltm->tm_mon << "月" << ltm->tm_mday << "日"
        << "--" << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
    //cin >> newnode->work;

    cout << "职工性别: " << endl;

    int sex1;
    cout << "请选择性别:1.男\t2.女" << endl;
    int ss = 1;
    while (ss == 1)
    {
        // ss=0;
        cin >> sex1;
        switch (sex1)
        {
        case 1:
        {
            newnode->sex = "男";
            ss = 0;
            break;
        }
        case 2:
        {
            newnode->sex = "女";
            ss = 0;
            break;
        }
        default:
        {
            cout << "选择错误,请重新选择" << endl;
            continue;
        }
        }
    }

    //cin >> newnode->sex;
    cout << "职工住址: " << endl;
    cin >> newnode->address;
    cout << "职工职务: " << endl;
    cin >> newnode->department;
    cout << "职工电话: " << endl;
    while (cin >> newnode->phone)
    {
        if (((newnode->phone).length()) != 11)
        {
            cout << "你输入的电话号码格式不对(标准为11位)，请重新输入" << endl;
        }
        else
        {
            break;
        }
    }
}

void staff::show_all(class staff *head)
{
    cout << "(*^▽^*)(*^▽^*)(*^▽^*)(*^▽^*)(*^▽^*)" << endl;
    int i = 0;
    if (head->next == NULL)
    {
        cout << "一个成员也没有，来加入一个吧~~~" << endl;
    }
    else
    {
        while (head->next != NULL)
        {
            i++;
            cout << i << "."
                 << "id：";
            cout << head->next->employee_number << '\t';

            cout << "名字：";
            cout << head->next->name << '\t';

            cout << "性别：";
            cout << head->next->sex << '\t';

            cout << "年龄：";
            cout << head->next->age << '\t';

            cout << "学历：";
            cout << head->next->study << '\t';

            cout << "出生年月：";
            cout << head->next->birth << '\t';

            cout << "工作年月：";
            cout << head->next->work << '\t';

            cout << "住址：";
            cout << head->next->address << '\t';

            cout << "职务：";
            cout << head->next->department << '\t';

            cout << "电话：";
            cout << head->next->phone << endl;
            head = head->next;
        }
    }
    cout << "(*^▽^*)(*^▽^*)(*^▽^*)(*^▽^*)(*^▽^*)" << endl;
}

void staff::query_name(class staff *t)
{
    string n;
    cout << "输入想要查找的职工姓名" << endl;
    cin >> n;
    int count = 0;
    while (t->next != NULL)
    {
        if (t->next->name == n)
        {
            cout << "id：";
            cout << t->next->employee_number << '\t';

            cout << "名字：";
            cout << t->next->name << '\t';

            cout << "性别：";
            cout << t->next->sex << '\t';

            cout << "年龄：";
            cout << t->next->age << '\t';

            cout << "学历：";
            cout << t->next->study << '\t';

            cout << "出生年月：";
            cout << t->next->birth << '\t';

            cout << "工作年月：";
            cout << t->next->work << '\t';

            cout << "住址：";
            cout << t->next->address << '\t';

            cout << "职务：";
            cout << t->next->department << '\t';

            cout << "电话：";
            cout << t->next->phone << endl;
            count++;
        }
        t = t->next;
    }
    if (count == 0)
    {
        cout << "查无此人，重新选择" << endl;
    }
}

void staff::query_depart(class staff *t)
{
    string n;
    cout << "请输入查询的职工职务" << endl;
    cin >> n;
    int count = 0;
    while (t->next != NULL)
    {
        if (t->next->department == n)
        {
            cout << "id：";
            cout << t->next->employee_number << '\t';

            cout << "名字：";
            cout << t->next->name << '\t';

            cout << "性别：";
            cout << t->next->sex << '\t';

            cout << "年龄：";
            cout << t->next->age << '\t';

            cout << "学历：";
            cout << t->next->study << '\t';

            cout << "出生年月：";
            cout << t->next->birth << '\t';

            cout << "工作年月：";
            cout << t->next->work << '\t';

            cout << "住址：";
            cout << t->next->address << '\t';

            cout << "职务：";
            cout << t->next->department << '\t';

            cout << "电话：";
            cout << t->next->phone << endl;
            count++;
        }
        t = t->next;
    }
    if (count == 0)
    {
        cout << "查无此人，重新选择" << endl;
    }
}

void staff::delete_num(class staff *t)
{
    string n;
    cout << "输入要删除的职工账号" << endl;
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
            cout << "删除成功" << endl;
            count++;
            break;
        }
        t = t->next;
    }
    if (count == 0)
    {
        cout << "查无此人，重新选择" << endl;
    }
}

void staff::delete_name(class staff *t)
{
    string n;
    cout << "请输入你想删除职工的姓名:" << endl;
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
            cout << "删除成功！" << endl;
            count++;
            break;
        }
        t = t->next;
    }
    if (count == 0)
    {
        cout << "查无此人，重新选择！" << endl;
    }
}

void staff::update(class staff *head)
{
    int num = 0;
    cout << "++++++++1.修改员id+++++++++++++++++" << endl;
    cout << "++++++++2.修改员工姓名+++++++++++++" << endl;
    cout << "++++++++3.修改员工年龄+++++++++++++" << endl;
    cout << "++++++++4.修改员工性别+++++++++++++" << endl;
    cout << "++++++++5.修改员工住址+++++++++++++" << endl;
    cout << "++++++++6.修改员工职务+++++++++++++" << endl;
    cout << "++++++++7.修改员工电话+++++++++++++" << endl;
    cout << "++++++++8.修改员工工作年月+++++++++" << endl;
    cout << "++++++++9.修改员工学历+++++++++++++" << endl;
    cout << "++++++++10.修改全部++++++++++++++++" << endl;
    cout << "++++++++0.返回上一页+++++++++++++++" << endl;
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
        cout << "请重新输入正确的指令！" << endl;
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
    cout << "输入要修改的对象的id" << endl;

    while (count == 0)
    {
        cout << "请输入要修改的对象id:";
        string id;
        cin >> id;

        while (head->next != NULL)
        {
            if (id == head->next->employee_number)
            {
                count = 1;
                while (count2 == 1)
                {
                    cout << "请输入修改后的id:";
                    cin >> id;
                    count2 = 0;
                    while (t != NULL)
                    {
                        if (t->employee_number == id)
                        {
                            // cout << "该id成员已存在" << endl;
                            count2 = 1;
                        }
                        t = t->next;
                    }
                    if (count2 == 1)
                    {
                        cout << "该id成员已存在,请重新输入" << endl;
                    }
                    else
                    {
                        cout << "修改成功" << endl;
                        head->next->employee_number = id;
                        break;
                    }
                    t = q;
                }

                //cout << "修改成功" << endl;
            }
            head = head->next;
            // if (count2 == 0)
            // {
            //     break;
            // }
        }
        if (count == 0)
        {
            cout << "查人此人，重新选择" << endl;
        }
        head = q;
    }
}

void staff::update_name(class staff *head)
{
    staff *q = new staff;
    q = head;
    cout << "输入要修改对象的id：" << endl;
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
                cout << "输入新名字：" << endl;
                string temp2;
                cin >> temp2;
                head->next->name = temp2;
                cout << "修改成功" << endl;
                break;
            }
            head = head->next;
        }
        if (count == 0)
        {
            cout << "查无此人，重新选择" << endl;
        }
        head = q;
    }
}
void staff::update_age(class staff *head)
{
    staff *q = new staff;
    q = head;
    cout << "输入要修改对象的id：" << endl;
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
                cout << "输入新年龄：" << endl;
                int temp2;
                while (cin >> temp2)
                {
                    if (temp2 > 100 || temp2 == 100 || temp2 < 0 || temp2 == 0)
                    {
                        cout << "您输入的年纪有点不太合理，请重新输入" << endl;
                    }
                    else
                    {
                        break;
                    }
                }
                head->next->age = temp2;
                cout << "修改成功" << endl;
                break;
            }
            head = head->next;
        }
        if (count == 0)
        {
            cout << "查无此人，重新选择" << endl;
        }
        head = q;
    }
}

void staff::update_sex(class staff *head)
{
    staff *q = new staff;
    q = head;
    cout << "输入要修改对象的id：" << endl;
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
                cout << "请选择性别:1.男\t2.女\t3.人妖" << endl;
                int ss = 1;
                while (ss == 1)
                {
                    cin >> sex1;
                    switch (sex1)
                    {
                    case 1:
                    {
                        head->next->sex = "男";
                        ss = 0;
                        break;
                    }
                    case 2:
                    {
                        head->next->sex = "女";
                        ss = 0;
                        break;
                    }
                    case 3:
                    {
                        head->next->sex = "人妖";
                        ss = 0;
                        break;
                    }
                    default:
                    {
                        cout << "选择错误,请重新进行选择" << endl;
                        continue;
                    }
                    }
                }
                if (ss == 0)
                {
                    cout << "修改成功" << endl;
                    break;
                }
                //head->next->sex = temp2;
            }
            head = head->next;
        }
        if (count == 0)
        {
            cout << "查无此人，重新选择" << endl;
        }
        head = q;
    }
}

void staff::update_study(class staff *head)
{
    staff *q = new staff;
    q = head;
    cout << "输入要修改对象的id：" << endl;
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
                cout << "输入新学历：" << endl;
                cout << "----------------------------" << endl;
                cout << "请选择学历" << endl;
                cout << "1.研究生" << endl;
                cout << "2.本科生" << endl;
                cout << "3.专科生" << endl;
                cout << "4.小学生" << endl;
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
                        head->next->study = "研究生";
                        cout << "研究生" << endl;
                        mm = 0;
                        break;
                    }
                    case 2:
                    {
                        head->next->study = "本科生";
                        cout << "本科生" << endl;
                        mm = 0;
                        break;
                    }
                    case 3:
                    {
                        head->next->study = "专科生";
                        cout << "专科生" << endl;
                        mm = 0;
                        break;
                    }
                    case 4:
                    {
                        head->next->study = "小学生";
                        cout << "小学生" << endl;
                        mm = 0;
                        break;
                    }
                    default:
                    {
                        // newnode->study = "研究生";
                        cout << "请输入正确的序号" << endl;
                        continue;
                    }
                    }
                }

                //head->next->study = temp2;
                cout << "修改成功" << endl;
                break;
            }
            head = head->next;
        }
        if (count == 0)
        {
            cout << "查无此人，重新选择" << endl;
        }
        head = q;
    }
}

void staff::update_work(class staff *head)
{
    staff *q = new staff;
    q = head;
    cout << "输入要修改对象的id：" << endl;
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
                cout << "是否更新工作时间(y/n)";
                char ch;
                cin >> ch;
                if (ch = 'y')
                {
                    cout << "新工作年月为：" << endl;
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

                    string dt = year1 + "-" + month1 + "-" + day1 + "-" + hour + "：" + min + "：" + sec;
                    head->next->work = dt;

                    //newnode->work = "/"+dt+"/";
                    cout << "当前时间为（时间已被格式化存储）：" << endl;
                    cout
                        << 1900 + ltm->tm_year << "年" << ltm->tm_mon << "月" << ltm->tm_mday << "日"
                        << "--" << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
                    cout << "修改成功" << endl;
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
            cout << "查无此人，重新选择" << endl;
        }
        head = q;
    }
}

void staff::update_address(class staff *head)
{
    staff *q = new staff;
    q = head;
    cout << "输入要修改对象的id：" << endl;
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
                cout << "输入新住址：" << endl;
                string temp2;
                cin >> temp2;
                head->next->address = temp2;
                cout << "修改成功" << endl;
                break;
            }
            head = head->next;
        }
        if (count == 0)
        {
            cout << "查无此人，重新选择" << endl;
        }
        head = q;
    }
}

void staff::update_depart(class staff *head)
{
    staff *q = new staff;
    q = head;
    cout << "输入要修改对象的id：" << endl;
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
                cout << "输入新职务：" << endl;
                string temp2;
                cin >> temp2;
                head->next->department = temp2;
                cout << "修改成功" << endl;
                break;
            }
            head = head->next;
        }
        if (count == 0)
        {
            cout << "查无此人，重新选择" << endl;
        }
        head = q;
    }
}

void staff::update_phone(class staff *head)
{
    staff *q = new staff;
    q = head;
    cout << "输入要修改对象的id：" << endl;
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
                cout << "输入新电话：" << endl;
                string temp2;
                while (cin >> temp2)
                {
                    if (((temp2).length()) != 11)
                    {
                        cout << "你输入的电话号码格式不对，请重新输入" << endl;
                    }
                    else
                    {
                        break;
                    }
                }
                head->next->phone = temp2;
                cout << "修改成功" << endl;
                break;
            }
            head = head->next;
        }
        if (count == 0)
        {
            cout << "查无此人，重新选择" << endl;
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
    cout << "输入要修改的对象的id" << endl;
    cout << "请输入要修改的对象id:";
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
                    cout << "请输入修改后的id:";
                    cin >> temp;
                    count2 = 0;
                    while (t != NULL)
                    {
                        if (t->employee_number == temp)
                        {
                            // cout << "该id成员已存在" << endl;
                            count2 = 1;
                        }
                        t = t->next;
                    }
                    if (count2 == 1)
                    {
                        cout << "该id成员已存在,请重新输入" << endl;
                    }
                    else
                    {
                        cout << "修改成功" << endl;
                        head->next->employee_number = temp;
                        break;
                    }
                    t = q;
                }

                cout << "输入新名字：" << endl;
                cin >> temp;
                head->next->name = temp;

                int sex1;
                cout << "请选择性别:1.男\t2.女\t3.人妖" << endl;
                int ss = 1;
                while (ss == 1)
                {
                    cin >> sex1;
                    switch (sex1)
                    {
                    case 1:
                    {
                        head->next->sex = "男";
                        ss = 0;
                        break;
                    }
                    case 2:
                    {
                        head->next->sex = "女";
                        ss = 0;
                        break;
                    }
                    case 3:
                    {
                        head->next->sex = "人妖";
                        ss = 0;
                        break;
                    }
                    default:
                    {
                        cout << "选择错误,请重新进行选择" << endl;
                        continue;
                    }
                    }
                }
                if (ss == 0)
                {
                    cout << "修改成功" << endl;
                    //break;
                }
                //head->next->sex = temp;
                cout << "请输入年纪" << endl;
                while (cin >> tmp)
                {
                    if (tmp > 100 || tmp == 100 || tmp < 0 || tmp == 0)
                    {
                        cout << "您输入的年纪有点不太合理，请重新输入" << endl;
                    }
                    else
                    {
                        break;
                    }
                }
                head->next->age = tmp;

                cout << "输入新学历：" << endl;
                cout << "----------------------------" << endl;
                cout << "请选择学历" << endl;
                cout << "1.研究生" << endl;
                cout << "2.本科生" << endl;
                cout << "3.专科生" << endl;
                cout << "4.小学生" << endl;
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
                        head->next->study = "研究生";
                        cout << "研究生" << endl;
                        head->next->study = "研究生";
                        dd = 0;
                        break;
                    }
                    case 2:
                    {
                        head->next->study = "本科生";
                        cout << "本科生" << endl;
                        head->next->study = "本科生";
                        dd = 0;
                        break;
                    }
                    case 3:
                    {
                        head->next->study = "专科生";
                        cout << "专科生" << endl;
                        head->next->study = "专科生";
                        dd = 0;
                        break;
                    }
                    case 4:
                    {
                        head->next->study = "小学生";
                        cout << "小学生" << endl;
                        head->next->study = "小学生";
                        dd = 0;
                        break;
                    }
                    default:
                    {
                        // newnode->study = "研究生";
                        cout << "请输入正确的序号" << endl;
                        continue;
                    }
                    }
                }

                cout << "更新新工作年月：" << endl;
                cout << "是否更新工作时间(y/n)";
                char ch;
                cin >> ch;
                if (ch = 'y')
                {
                    cout << "新工作年月为：";
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

                    string dt = year1 + "-" + month1 + "-" + day1 + "-" + hour + "：" + min + "：" + sec;
                    head->next->work = dt;

                    //newnode->work = "/"+dt+"/";
                    cout << "当前时间为（时间已被格式化存储）：" << endl;
                    cout
                        << 1900 + ltm->tm_year << "年" << ltm->tm_mon << "月" << ltm->tm_mday << "日"
                        << "--" << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
                    cout << "修改成功" << endl;
                    //break;
                }
                else
                {
                    //break;
                }
                head->next->work = tmp;

                cout << "输入新住址：" << endl;
                cin >> temp;
                head->next->address = temp;

                cout << "输入新职务：" << endl;
                cin >> temp;
                head->next->department = temp;

                cout << "输入新电话：" << endl;
                while (cin >> head->next->phone)
                {
                    if (((head->next->phone).length()) != 11)
                    {
                        cout << "你输入的电话号码格式不对，请重新输入" << endl;
                    }
                    else
                    {
                        break;
                    }
                }
                head->next->phone = temp;
                cout << "修改成功" << endl;
                break;
            }
            head = head->next;
        }
        if (count == 0)
        {
            cout << "查无此人，重新选择" << endl;
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
    cout << "输入数量" << endl;
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
        t->sex = "女";
        outfile << t->sex << '\t';
        t->age = random(1, 100);
        outfile << t->age << '\t';
        t->study = "本科生";
        outfile << t->study << '\t';
        t->birth = "2000-10-1";
        outfile << t->birth << '\t';
        t->work = "2000-6-15-9：20：3";
        outfile << t->work << '\t';
        t->address = "竹七343";
        outfile << t->address << '\t';
        t->department = "学生";
        outfile << t->department << '\t';
        t->phone = "15670880671";
        outfile << t->phone << endl;
        i++;
        //t = t->next;
        head = q;
    }
    outfile.close();
}
