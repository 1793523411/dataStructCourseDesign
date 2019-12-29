# 职工管理管理系统--课程设计

## fstream的使用

+ ofstream 	该数据类型表示输出文件流，用于创建文件并向文件写入信息。
  
+ ifstream 	该数据类型表示输入文件流，用于从文件读取信息。
  
+ fstream 	该数据类型通常表示文件流，且同时具有 ofstream 和 ifstream 两种功能，这意味着它可以创建文件，向文件写入信息，从文件读取信息。

**要在 C++ 中进行文件处理，必须在 C++ 源代码文件中包含头文件 <iostream> 和 <fstream>。**


### 打开文件

在从文件读取信息或者向文件写入信息之前，必须先打开文件。ofstream 和 fstream 对象都可以用来打开文件进行写操作，如果只需要打开文件进行读操作，则使用 ifstream 对象。

下面是 open() 函数的标准语法，open() 函数是 fstream、ifstream 和 ofstream 对象的一个成员。

`void open(const char *filename, ios::openmode mode);`

在这里，open() 成员函数的第一参数指定要打开的文件的名称和位置，第二个参数定义文件被打开的模式。
模式标志 	描述

ios::app ----	追加模式。所有写入都追加到文件末尾。

ios::ate ----	文件打开后定位到文件末尾。

ios::in ----	打开文件用于读取。

ios::out ----	打开文件用于写入。

ios::trunc 	如果该文件已经存在，其内容将在打开文件之前被截断，即把文件长度设为 0。


您可以把以上两种或两种以上的模式结合使用。例如，如果您想要以写入模式打开文件，并希望截断文件，以防文件已存在，那么您可以使用下面的语法：

```c+++
ofstream outfile;
outfile.open("file.dat", ios::out | ios::trunc );
```

类似地，您如果想要打开一个文件用于读写，可以使用下面的语法：

```c++
ifstream  afile;
afile.open("file.dat", ios::out | ios::in );
```

### 关闭文件

当 C++ 程序终止时，它会自动关闭刷新所有流，释放所有分配的内存，并关闭所有打开的文件。但程序员应该养成一个好习惯，在程序终止前关闭所有打开的文件。

下面是 close() 函数的标准语法，close() 函数是 fstream、ifstream 和 ofstream 对象的一个成员。

`void close();`

### 写入文件

在 C++ 编程中，我们使用流插入运算符（ << ）向文件写入信息，就像使用该运算符输出信息到屏幕上一样。唯一不同的是，在这里您使用的是 ofstream 或 fstream 对象，而不是 cout 对象。
### 读取文件

在 C++ 编程中，我们使用流提取运算符（ >> ）从文件读取信息，就像使用该运算符从键盘输入信息一样。唯一不同的是，在这里您使用的是 ifstream 或 fstream 对象，而不是 cin 对象。

## 读取 & 写入实例

下面的 C++ 程序以读写模式打开一个文件。在向文件 afile.dat 写入用户输入的信息之后，程序从文件读取信息，并将其输出到屏幕上：
实例

```c++
#include <fstream>
#include <iostream>
using namespace std;
 
int main ()
{
    
   char data[100];
 
   // 以写模式打开文件
   ofstream outfile;
   outfile.open("afile.dat");
 
   cout << "Writing to the file" << endl;
   cout << "Enter your name: "; 
   cin.getline(data, 100);
 
   // 向文件写入用户输入的数据
   outfile << data << endl;
 
   cout << "Enter your age: "; 
   cin >> data;
   cin.ignore();
   
   // 再次向文件写入用户输入的数据
   outfile << data << endl;
 
   // 关闭打开的文件
   outfile.close();
 
   // 以读模式打开文件
   ifstream infile; 
   infile.open("afile.dat"); 
 
   cout << "Reading from the file" << endl; 
   infile >> data; 
 
   // 在屏幕上写入数据
   cout << data << endl;
   
   // 再次从文件读取数据，并显示它
   infile >> data; 
   cout << data << endl; 
 
   // 关闭打开的文件
   infile.close();
 
   return 0;
}

```
当上面的代码被编译和执行时，它会产生下列输入和输出：

```
$./a.out
Writing to the file
Enter your name: Zara
Enter your age: 9
Reading from the file
Zara
9
```

上面的实例中使用了 cin 对象的附加函数，比如 getline()函数从外部读取一行，ignore() 函数会忽略掉之前读语句留下的多余字符。

### 文件位置指针

istream 和 ostream 都提供了用于重新定位文件位置指针的成员函数。这些成员函数包括关于 istream 的 seekg（"seek get"）和关于 ostream 的 seekp（"seek put"）。

seekg 和 seekp 的参数通常是一个长整型。第二个参数可以用于指定查找方向。查找方向可以是 ios::beg（默认的，从流的开头开始定位），也可以是 ios::cur（从流的当前位置开始定位），也可以是 ios::end（从流的末尾开始定位）。

```c++
文件位置指针是一个整数值，指定了从文件的起始位置到指针所在位置的字节数。下面是关于定位 "get" 文件位置指针的实例：
// 定位到 fileObject 的第 n 个字节（假设是 ios::beg）
fileObject.seekg( n );
 
// 把文件的读指针从 fileObject 当前位置向后移 n 个字节
fileObject.seekg( n, ios::cur );
 
// 把文件的读指针从 fileObject 末尾往回移 n 个字节
fileObject.seekg( n, ios::end );
 
// 定位到 fileObject 的末尾
fileObject.seekg( 0, ios::end );

```


## C++ 字符串

+ C++ 提供了以下两种类型的字符串表示形式：
    - C 风格字符串
    - C++ 引入的 string 类类型

### C 风格字符串

C 风格的字符串起源于 C 语言，并在 C++ 中继续得到支持。字符串实际上是使用 null 字符 '\0' 终止的一维字符数组。因此，一个以 null 结尾的字符串，包含了组成字符串的字符。

下面的声明和初始化创建了一个 "Hello" 字符串。由于在数组的末尾存储了空字符，所以字符数组的大小比单词 "Hello" 的字符数多一个。

char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

依据数组初始化规则，您可以把上面的语句写成以下语句：

char greeting[] = "Hello";

### C/C++ 中定义的字符串

不需要把 null 字符放在字符串常量的末尾。C++ 编译器会在初始化数组时，自动把 '\0' 放在字符串的末尾


实例

```c++
#include <iostream>
 
using namespace std;
 
int main ()
{
   char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
 
   cout << "Greeting message: ";
   cout << greeting << endl;
 
   return 0;
}

```

当上面的代码被编译和执行时，它会产生下列结果：

`Greeting message: Hello`

C++ 中有大量的函数用来操作以 null 结尾的字符串：

strcpy(s1, s2);----复制字符串 s2 到字符串 s1。

strcat(s1, s2);----连接字符串 s2 到字符串 s1 的末尾。

strlen(s1);----返回字符串 s1 的长度。

strcmp(s1, s2);----如果 s1 和 s2 是相同的，则返回 0；如果 s1<s2 则返回值小于 0；如果 s1>s2 则返回值大于 0。

strchr(s1, ch);----返回一个指针，指向字符串 s1 中字符 ch 的第一次出现的位置。

strstr(s1, s2);----返回一个指针，指向字符串 s1 中字符串 s2 的第一次出现的位置。



### C++ 中的 String 类

C++ 标准库提供了 string 类类型，支持上述所有的操作，另外还增加了其他更多的功能。我们将学习 C++ 标准库中的这个类，现在让我们先来看看下面这个实例：

现在您可能还无法透彻地理解这个实例，因为到目前为止我们还没有讨论类和对象。所以现在您可以只是粗略地看下这个实例，等理解了面向对象的概念之后再回头来理解这个实例。

实例

```c++
#include <iostream>
#include <string>
 
using namespace std;
 
int main ()
{
   string str1 = "Hello";
   string str2 = "World";
   string str3;
   int  len ;
 
   // 复制 str1 到 str3
   str3 = str1;
   cout << "str3 : " << str3 << endl;
 
   // 连接 str1 和 str2
   str3 = str1 + str2;
   cout << "str1 + str2 : " << str3 << endl;
 
   // 连接后，str3 的总长度
   len = str3.size();
   cout << "str3.size() :  " << len << endl;
 
   return 0;
}
```

当上面的代码被编译和执行时，它会产生下列结果：

```
str3 : Hello
str1 + str2 : HelloWorld
str3.size() :  10
```

## 排序的实现

排序使用的选择排序，采用的存储方式为链式结构，根据对象的age进行排序参考的代码为运用链表进行选择排序，参考的代码如下：

这段代码为实验课上所写代码
```c++
void LinkedListSelectSort(LinkList head){
    LinkList save,r,p,q,s; //list指向头结点
        save = head;
        while(save->next){
                q = save->next;
                r=q;
                p=q->next;
                while(p){
                    if (p->data < q->data) //寻找值最小结点与其前驱结点
                    {
                        s = r;
                        q=p;
                    }
                    r = p;
                    p=p->next;
                }
                if (q!=save->next) //若最小结点不是第一个未排序结点
                {
                    s->next = q->next;
                    q->next = save->next;
                    save->next = q;
                } //将最小结点与前面一个链结点交换位置
                save = q;
        }
}
```

根据定义的对象进行适当的修改，即可实现升序与降序。
因为每次执行while函数是会进行文件的读，排序结束是也会对文件进行写，所以test.txt里的内容也会跟着改变；

## 加入一些判断

1：加入对年纪的判断，确保输入的年纪在正确范围内
2：加入对电话号码的判断，保证格式正确


## 实现文件分离

1.头文件中不要使用using namespace，由于c++编译的特性，由于初学还没深入了解，不做具体编译的解释
2.由于没有了命名空间，所以string定义要写成std::string
3.main.cpp中引入staff.cpp,staff.cpp中引入staff.h

main.cpp

```c++
#include <iostream>
#include <string>
#include <fstream>

#include "staff.cpp"
```

staff.cpp

```c++
#include <iostream>
#include <string>
#include <fstream>
#include "staff.h"

using namespace std;
```

这样就可以通过编译了


## 第二次上机试验

### 添加若文件里没有数据显示没有数据

### 添加退出选择功能

### 添加学历选择功能

### 添加性别选择功能，若选择错误需进行重新选择

### 添加id排除重复功能 ，输入重复的需进行重新选择

### 修改数据是所有的查找不到的会提示没有此人，并进行重新输入，直到输入的id号存在；

## 学习日期函数

C++ 标准库没有提供所谓的日期类型。C++ 继承了 C 语言用于日期和时间操作的结构和函数。为了使用日期和时间相关的函数和结构，需要在 C++ 程序中引用 <ctime> 头文件。

有四个与时间相关的类型：clock_t、time_t、size_t 和 tm。类型 clock_t、size_t 和 time_t 能够把系统时间和日期表示为某种整数。

结构类型 tm 把日期和时间以 C 结构的形式保存，tm 结构的定义如下：
```c++
struct tm {
  int tm_sec;   // 秒，正常范围从 0 到 59，但允许至 61
  int tm_min;   // 分，范围从 0 到 59
  int tm_hour;  // 小时，范围从 0 到 23
  int tm_mday;  // 一月中的第几天，范围从 1 到 31
  int tm_mon;   // 月，范围从 0 到 11
  int tm_year;  // 自 1900 年起的年数
  int tm_wday;  // 一周中的第几天，范围从 0 到 6，从星期日算起
  int tm_yday;  // 一年中的第几天，范围从 0 到 365，从 1 月 1 日算起
  int tm_isdst; // 夏令时
}

```

### 当前日期和时间

下面的实例获取当前系统的日期和时间，包括本地时间和协调世界时（UTC）。
实例
```c++
#include <iostream>
#include <ctime>
 
using namespace std;
 
int main( )
{
   // 基于当前系统的当前日期/时间
   time_t now = time(0);
   
   // 把 now 转换为字符串形式
   char* dt = ctime(&now);
 
   cout << "本地日期和时间：" << dt << endl;
 
   // 把 now 转换为 tm 结构
   tm *gmtm = gmtime(&now);
   dt = asctime(gmtm);
   cout << "UTC 日期和时间："<< dt << endl;
}

```
当上面的代码被编译和执行时，它会产生下列结果：
```

本地日期和时间：Sat Jan  8 20:07:41 2011

UTC 日期和时间：Sun Jan  9 03:07:41 2011
```

### 使用结构 tm 格式化时间

tm 结构在 C/C++ 中处理日期和时间相关的操作时，显得尤为重要。tm 结构以 C 结构的形式保存日期和时间。大多数与时间相关的函数都使用了 tm 结构。下面的实例使用了 tm 结构和各种与日期和时间相关的函数。

在练习使用结构之前，需要对 C 结构有基本的了解，并懂得如何使用箭头 -> 运算符来访问结构成员。
实例

```c++
#include <iostream>
#include <ctime>
 
using namespace std;
 
int main( )
{
   // 基于当前系统的当前日期/时间
   time_t now = time(0);
 
   cout << "1970 到目前经过秒数:" << now << endl;
 
   tm *ltm = localtime(&now);
 
   // 输出 tm 结构的各个组成部分
   cout << "年: "<< 1900 + ltm->tm_year << endl;
   cout << "月: "<< 1 + ltm->tm_mon<< endl;
   cout << "日: "<<  ltm->tm_mday << endl;
   cout << "时间: "<< ltm->tm_hour << ":";
   cout << ltm->tm_min << ":";
   cout << ltm->tm_sec << endl;
}
```

当上面的代码被编译和执行时，它会产生下列结果：

```
1970 到目前时间:1503564157
年: 2017
月: 8
日: 24
时间: 16:42:37
```
### 时间的格式化
用到了`#include <sstream>`
	```c++
     int i,j,k;
     stringstream s;//包含在sstream头文件里 
     s<<1234;
     string ch = s.str();
     cout<<ch<<endl;
     while(1);
     return 0;
	```

具体怎么用的在代码中有所体现；

### 出生日期的计算：根据年龄，月份和日子自己输入；

## 第三次实验课

### 完成名字按字典排序，整段程序默认按字典写入文件中，每次排序完毕显示排序过后的数据

### 优化了界面，增加了修改界面可以返回上一界面

## 自动生成排序数据





































