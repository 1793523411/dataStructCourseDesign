#include <iostream>
#include <string>
#include <fstream>

/*
*定义一个类
*/
class staff
{
private:
    std::string employee_number;
    std::string name;
    int age;
    std::string sex;
    std::string study;
    std::string birth;
    std::string work;
    std::string address;
    std::string department;
    std::string phone;
    class staff *next;

public:
    staff() : next(NULL) {}
    void registeration(class staff *head);
    void query_name(class staff *t);
    void query_depart(class staff *t);
    void delete_num(class staff *t);
    void delete_name(class staff *t);
    void show_all(class staff *head);
    void update(class staff *head);
    void update_num(class staff *head);
    void update_name(class staff *head);
    void update_age(class staff *head);
    void update_sex(class staff *head);
    void update_study(class staff *head);
    void update_birth(class staff *head);
    void update_work(class staff *head);
    void update_address(class staff *head);
    void update_depart(class staff *head);
    void update_phone(class staff *head);
    void update_all(class staff *head);
    void sort_up(class staff *head);
    void sort_down(class staff *head);
    void sort_nup(class staff *head);
    void sort_ndown(class staff *head);
    int read(class staff *head);
    void hahaha(class staff *head);
    void write(class staff *t);
};
