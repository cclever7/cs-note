<center><font size = 45>STL</font></center>

## 基本概念

STL(Standard Template Library,**标准模板库**)，STL 从广义上分为: **容器，算法， 迭代器**，**容器**和**算法**之间通过**迭代器**进行无缝连接。

#### 组件

1. **容器**

   STL**容器**就是将运用**最广泛的一些数据结构**实现出来，常用的数据结构：数组, 链表,树, 栈, 队列, 集合, 映射表等

   **容器分类：**

   - **序列式容器**：强调值的排序，序列式容器中的每个元素均有固定的位置。 

   - **关联式容器**：二叉树结构，各元素之间没有严格的物理上的顺序关系

2. **算法**

   - 质变算法：是指运算过程中会更改区间内的元素的内容。例如拷贝，替换，删除等等
   - 非质变算法：是指运算过程中不会更改区间内的元素内容，例如查找、计数、遍历、寻找极值等等

3. **迭代器**

   提供一种方法，使之能够依序寻访某个容器所含的各个元素。每个容器都有自己专属的迭代器，迭代器使用非常类似于指针

   **迭代器种类：**输入迭代器，输出迭代器，前向迭代器，**双向迭代器，随机访问迭代器**

4. **仿函数**：行为类似函数，可作为算法的某种策略。

5. **适配器**：一种用来修饰容器或者仿函数或迭代器接口的东西

6. **空间配置器**：负责空间的配置与管理。



## 常用容器

| 容器               | 底层数据结构      | 时间复杂度                                                | 有无序 | 可不可重复 | 其他                                                         |
| ------------------ | ----------------- | --------------------------------------------------------- | ------ | ---------- | ------------------------------------------------------------ |
| array              | 数组              | 随机读改 O(1)                                             | 无序   | 可重复     | 支持随机访问                                                 |
| vector             | 数组              | 随机读改、尾部插入、尾部删除 O(1) 头部插入、头部删除 O(n) | 无序   | 可重复     | 支持随机访问                                                 |
| deque              | 双端队列          | 头尾插入、头尾删除 O(1)                                   | 无序   | 可重复     | 一个中央控制器 + 多个缓冲区，支持首尾快速增删，支持随机访问  |
| forward_list       | 单向链表          | 插入、删除 O(1)                                           | 无序   | 可重复     | 不支持随机访问                                               |
| list               | 双向链表          | 插入、删除 O(1)                                           | 无序   | 可重复     | 不支持随机访问                                               |
| stack              | deque / list      | 顶部插入、顶部删除 O(1)                                   | 无序   | 可重复     | deque 或 list 封闭头端开口，不用 vector 的原因应该是容量大小有限制，扩容耗时 |
| queue              | deque / list      | 尾部插入、头部删除 O(1)                                   | 无序   | 可重复     | deque 或 list 封闭头端开口，不用 vector 的原因应该是容量大小有限制，扩容耗时 |
| priority_queue     | vector + max-heap | 插入、删除 O(log2n)                                       | 有序   | 可重复     | vector容器+heap处理规则                                      |
| set                | 红黑树            | 插入、删除、查找 O(log2n)                                 | 有序   | 不可重复   |                                                              |
| multiset           | 红黑树            | 插入、删除、查找 O(log2n)                                 | 有序   | 可重复     |                                                              |
| map                | 红黑树            | 插入、删除、查找 O(log2n)                                 | 有序   | 不可重复   |                                                              |
| multimap           | 红黑树            | 插入、删除、查找 O(log2n)                                 | 有序   | 可重复     |                                                              |
| unordered_set      | 哈希表            | 插入、删除、查找 O(1) 最差 O(n)                           | 无序   | 不可重复   |                                                              |
| unordered_multiset | 哈希表            | 插入、删除、查找 O(1) 最差 O(n)                           | 无序   | 可重复     |                                                              |
| unordered_map      | 哈希表            | 插入、删除、查找 O(1) 最差 O(n)                           | 无序   | 不可重复   |                                                              |
| unordered_multimap | 哈希表            | 插入、删除、查找 O(1) 最差 O(n)                           | 无序   | 可重复     |                                                              |

## array

array 是固定大小的顺序容器，它们保存了一个以严格的线性顺序排列的特定数量的元素。

| 方法                         | 含义                                                         |
| ---------------------------- | ------------------------------------------------------------ |
| begin                        | 返回指向数组容器中第一个元素的迭代器                         |
| end                          | 返回指向数组容器中最后一个元素之后的理论元素的迭代器         |
| rbegin                       | 返回指向数组容器中最后一个元素的反向迭代器                   |
| rend                         | 返回一个反向迭代器，指向数组中第一个元素之前的理论元素       |
| cbegin                       | 返回指向数组容器中第一个元素的常量迭代器（const_iterator）   |
| cend                         | 返回指向数组容器中最后一个元素之后的理论元素的常量迭代器（const_iterator） |
| crbegin                      | 返回指向数组容器中最后一个元素的常量反向迭代器（const_reverse_iterator） |
| crend                        | 返回指向数组中第一个元素之前的理论元素的常量反向迭代器（const_reverse_iterator） |
| size                         | 返回数组容器中元素的数量                                     |
| max_size                     | 返回数组容器可容纳的最大元素数                               |
| empty                        | 返回一个布尔值，指示数组容器是否为空                         |
| operator[]                   | 返回容器中第 n（参数）个位置的元素的引用                     |
| at                           | 返回容器中第 n（参数）个位置的元素的引用                     |
| front                        | 返回对容器中第一个元素的引用                                 |
| back                         | 返回对容器中最后一个元素的引用                               |
| data                         | 返回指向容器中第一个元素的指针                               |
| fill                         | 用 val（参数）填充数组所有元素                               |
| swap                         | 通过 x（参数）的内容交换数组的内容                           |
| get（array）                 | 形如 `std::get<0>(myarray)`；传入一个数组容器，返回指定位置元素的引用 |
| relational operators (array) | 形如 `arrayA > arrayB`；依此比较数组每个元素的大小关系       |

## vector

vector 是表示可以改变大小的数组的序列容器。

| 方法                          | 含义                                                         |
| ----------------------------- | ------------------------------------------------------------ |
| vector                        | 构造函数                                                     |
| ~vector                       | 析构函数，销毁容器对象                                       |
| operator=                     | 将新内容分配给容器，替换其当前内容，并相应地修改其大小       |
| begin                         | 返回指向容器中第一个元素的迭代器                             |
| end                           | 返回指向容器中最后一个元素之后的理论元素的迭代器             |
| rbegin                        | 返回指向容器中最后一个元素的反向迭代器                       |
| rend                          | 返回一个反向迭代器，指向中第一个元素之前的理论元素           |
| cbegin                        | 返回指向容器中第一个元素的常量迭代器（const_iterator）       |
| cend                          | 返回指向容器中最后一个元素之后的理论元素的常量迭代器（const_iterator） |
| crbegin                       | 返回指向容器中最后一个元素的常量反向迭代器（const_reverse_iterator） |
| crend                         | 返回指向容器中第一个元素之前的理论元素的常量反向迭代器（const_reverse_iterator） |
| size                          | 返回容器中元素的数量                                         |
| max_size                      | 返回容器可容纳的最大元素数                                   |
| resize                        | 调整容器的大小，使其包含 n（参数）个元素                     |
| capacity                      | 返回当前为 vector 分配的存储空间（容量）的大小               |
| empty                         | 返回 vector 是否为空                                         |
| reserve                       | 请求 vector 容量至少足以包含 n（参数）个元素                 |
| shrink_to_fit                 | 要求容器减小其 capacity（容量）以适应其 size（元素数量）     |
| operator[]                    | 返回容器中第 n（参数）个位置的元素的引用                     |
| at                            | 返回容器中第 n（参数）个位置的元素的引用                     |
| front                         | 返回对容器中第一个元素的引用                                 |
| back                          | 返回对容器中最后一个元素的引用                               |
| data                          | 返回指向容器中第一个元素的指针                               |
| assign                        | 将新内容分配给 vector，替换其当前内容，并相应地修改其 size   |
| push_back                     | 在容器的最后一个元素之后添加一个新元素                       |
| pop_back                      | 删除容器中的最后一个元素，有效地将容器 size 减少一个         |
| insert                        | 通过在指定位置的元素之前插入新元素来扩展该容器，通过插入元素的数量有效地增加容器大小 |
| erase                         | 从 vector 中删除单个元素（`position`）或一系列元素（`[first，last)`），这有效地减少了被去除的元素的数量，从而破坏了容器的大小 |
| swap                          | 通过 x（参数）的内容交换容器的内容，x 是另一个类型相同、size 可能不同的 vector 对象 |
| clear                         | 从 vector 中删除所有的元素（被销毁），留下 size 为 0 的容器  |
| emplace                       | 通过在 position（参数）位置处插入新元素 args（参数）来扩展容器 |
| emplace_back                  | 在 vector 的末尾插入一个新的元素，紧跟在当前的最后一个元素之后 |
| get_allocator                 | 返回与vector关联的构造器对象的副本                           |
| swap(vector)                  | 容器 x（参数）的内容与容器 y（参数）的内容交换。两个容器对象都必须是相同的类型（相同的模板参数），尽管大小可能不同 |
| relational operators (vector) | 形如 `vectorA > vectorB`；依此比较每个元素的大小关系         |

## deque

deque（['dek]）（双端队列）是double-ended queue 的一个不规则缩写。deque是具有动态大小的序列容器，可以在两端（前端或后端）扩展或收缩。

| 方法          | 含义                                                         |
| ------------- | ------------------------------------------------------------ |
| deque         | 构造函数                                                     |
| push_back     | 在当前的最后一个元素之后 ，在 deque 容器的末尾添加一个新元素 |
| push_front    | 在 deque 容器的开始位置插入一个新的元素，位于当前的第一个元素之前 |
| pop_back      | 删除 deque 容器中的最后一个元素，有效地将容器大小减少一个    |
| pop_front     | 删除 deque 容器中的第一个元素，有效地减小其大小              |
| emplace_front | 在 deque 的开头插入一个新的元素，就在其当前的第一个元素之前  |
| emplace_back  | 在 deque 的末尾插入一个新的元素，紧跟在当前的最后一个元素之后 |

## forward_list

forward_list（单向链表）是序列容器，允许在序列中的任何地方进行恒定的时间插入和擦除操作。

| 方法          | 含义                                                |
| ------------- | --------------------------------------------------- |
| forward_list  | 返回指向容器中第一个元素之前的位置的迭代器          |
| cbefore_begin | 返回指向容器中第一个元素之前的位置的 const_iterator |

## list

list，双向链表，是序列容器，允许在序列中的任何地方进行常数时间插入和擦除操作，并在两个方向上进行迭代。

## stack

stack 是一种容器适配器，用于在LIFO（后进先出）的操作，其中元素仅从容器的一端插入和提取。

## queue

queue 是一种容器适配器，用于在FIFO（先入先出）的操作，其中元素插入到容器的一端并从另一端提取。

## priority_queue



## set

set 是按照特定顺序存储唯一元素的容器。

## multiset



## map

map 是关联容器，按照特定顺序存储由 key value (键值) 和 mapped value (映射值) 组合形成的元素。

| 方法        | 含义                                                         |
| ----------- | ------------------------------------------------------------ |
| map         | 构造函数                                                     |
| begin       | 返回引用容器中第一个元素的迭代器                             |
| key_comp    | 返回容器用于比较键的比较对象的副本                           |
| value_comp  | 返回可用于比较两个元素的比较对象，以获取第一个元素的键是否在第二个元素之前 |
| find        | 在容器中搜索具有等于 k（参数）的键的元素，如果找到则返回一个迭代器，否则返回 map::end 的迭代器 |
| count       | 在容器中搜索具有等于 k（参数）的键的元素，并返回匹配的数量   |
| lower_bound | 返回一个非递减序列 `[first, last)`（参数）中的第一个大于等于值 val（参数）的位置的迭代器 |
| upper_bound | 返回一个非递减序列 `[first, last)`（参数）中第一个大于 val（参数）的位置的迭代器 |
| equal_range | 获取相同元素的范围，返回包含容器中所有具有与 k（参数）等价的键的元素的范围边界（`pair< map<char,int>::iterator, map<char,int>::iterator >`） |

## multimap



## unordered_set



## unordered_multiset



## unordered_map



## unordered_multimap



## tuple

元组是一个能够容纳元素集合的对象。每个元素可以是不同的类型。



## pair

这个类把一对值（values）结合在一起，这些值可能是不同的类型（T1 和 T2）。每个值可以被公有的成员变量first、second访问。













## 函数对象

### 4.1 函数对象

#### 4.1.1 函数对象概念

**概念：**

- 重载**函数调用操作符**的类，其对象常称为**函数对象**
- **函数对象**使用重载的()时，行为类似函数调用，也叫**仿函数**



**本质：**

函数对象(仿函数)是一个**类**，不是一个函数



#### 4.1.2  函数对象使用

**特点：**

- 函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
- 函数对象超出普通函数的概念，函数对象可以有自己的状态
- 函数对象可以作为参数传递





**示例:**

```
 #include <string>
 
 //1、函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
 class MyAdd
 {
 public :
     int operator()(int v1,int v2)
     {
         return v1 + v2;
     }
 };
 
 void test01()
 {
     MyAdd myAdd;
     cout << myAdd(10, 10) << endl;
 }
 
 //2、函数对象可以有自己的状态
 class MyPrint
 {
 public:
     MyPrint()
     {
         count = 0;
     }
     void operator()(string test)
     {
         cout << test << endl;
         count++; //统计使用次数
     }
 
     int count; //内部自己的状态
 };
 void test02()
 {
     MyPrint myPrint;
     myPrint("hello world");
     myPrint("hello world");
     myPrint("hello world");
     cout << "myPrint调用次数为： " << myPrint.count << endl;
 }
 
 //3、函数对象可以作为参数传递
 void doPrint(MyPrint &mp , string test)
 {
     mp(test);
 }
 
 void test03()
 {
     MyPrint myPrint;
     doPrint(myPrint, "Hello C++");
 }
 
 int main() {
 
     //test01();
     //test02();
     test03();
 
     system("pause");
 
     return 0;
 }
```

总结：

- 仿函数写法非常灵活，可以作为参数进行传递。













### 4.2  谓词

#### 4.2.1 谓词概念



**概念：**

- 返回bool类型的仿函数称为**谓词**
- 如果operator()接受一个参数，那么叫做一元谓词
- 如果operator()接受两个参数，那么叫做二元谓词





#### 4.2.2 一元谓词

**示例：**

```
 #include <vector>
 #include <algorithm>
 
 //1.一元谓词
 struct GreaterFive{
     bool operator()(int val) {
         return val > 5;
     }
 };
 
 void test01() {
 
     vector<int> v;
     for (int i = 0; i < 10; i++)
     {
         v.push_back(i);
     }
 
     vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
     if (it == v.end()) {
         cout << "没找到!" << endl;
     }
     else {
         cout << "找到:" << *it << endl;
     }
 
 }
 
 int main() {
 
     test01();
 
     system("pause");
 
     return 0;
 }
```

总结：参数只有一个的谓词，称为一元谓词











#### 4.2.3 二元谓词

**示例：**

```
 #include <vector>
 #include <algorithm>
 //二元谓词
 class MyCompare
 {
 public:
     bool operator()(int num1, int num2)
     {
         return num1 > num2;
     }
 };
 
 void test01()
 {
     vector<int> v;
     v.push_back(10);
     v.push_back(40);
     v.push_back(20);
     v.push_back(30);
     v.push_back(50);
 
     //默认从小到大
     sort(v.begin(), v.end());
     for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
     {
         cout << *it << " ";
     }
     cout << endl;
     cout << "----------------------------" << endl;
 
     //使用函数对象改变算法策略，排序从大到小
     sort(v.begin(), v.end(), MyCompare());
     for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
     {
         cout << *it << " ";
     }
     cout << endl;
 }
 
 int main() {
 
     test01();
 
     system("pause");
 
     return 0;
 }
```

总结：参数只有两个的谓词，称为二元谓词

















### 4.3 内建函数对象

#### 4.3.1 内建函数对象意义

**概念：**

- STL内建了一些函数对象



**分类:**

- 算术仿函数
- 关系仿函数
- 逻辑仿函数

**用法：**

- 这些仿函数所产生的对象，用法和一般函数完全相同
- 使用内建函数对象，需要引入头文件 `#include<functional>`







#### 4.3.2 算术仿函数

**功能描述：**

- 实现四则运算
- 其中negate是一元运算，其他都是二元运算



**仿函数原型：**

- `template<class T> T plus<T>`                //加法仿函数
- `template<class T> T minus<T>`              //减法仿函数
- `template<class T> T multiplies<T>`    //乘法仿函数
- `template<class T> T divides<T>`         //除法仿函数
- `template<class T> T modulus<T>`         //取模仿函数
- `template<class T> T negate<T>`           //取反仿函数



**示例：**

```
 #include <functional>
 //negate
 void test01()
 {
     negate<int> n;
     cout << n(50) << endl;
 }
 
 //plus
 void test02()
 {
     plus<int> p;
     cout << p(10, 20) << endl;
 }
 
 int main() {
 
     test01();
     test02();
 
     system("pause");
 
     return 0;
 }
```

总结：使用内建函数对象时，需要引入头文件 `#include <functional>`









#### 4.3.3 关系仿函数

**功能描述：**

- 实现关系对比



**仿函数原型：**

- `template<class T> bool equal_to<T>`                    //等于
- `template<class T> bool not_equal_to<T>`            //不等于
- `template<class T> bool greater<T>`                      //大于
- `template<class T> bool greater_equal<T>`          //大于等于
- `template<class T> bool less<T>`                           //小于
- `template<class T> bool less_equal<T>`               //小于等于



**示例：**

```
 #include <functional>
 #include <vector>
 #include <algorithm>
 
 class MyCompare
 {
 public:
     bool operator()(int v1,int v2)
     {
         return v1 > v2;
     }
 };
 void test01()
 {
     vector<int> v;
 
     v.push_back(10);
     v.push_back(30);
     v.push_back(50);
     v.push_back(40);
     v.push_back(20);
 
     for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
         cout << *it << " ";
     }
     cout << endl;
 
     //自己实现仿函数
     //sort(v.begin(), v.end(), MyCompare());
     //STL内建仿函数  大于仿函数
     sort(v.begin(), v.end(), greater<int>());
 
     for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
         cout << *it << " ";
     }
     cout << endl;
 }
 
 int main() {
 
     test01();
 
     system("pause");
 
     return 0;
 }
```

总结：关系仿函数中最常用的就是greater<>大于











#### 4.3.4 逻辑仿函数

**功能描述：**

- 实现逻辑运算



**函数原型：**

- `template<class T> bool logical_and<T>`              //逻辑与
- `template<class T> bool logical_or<T>`                //逻辑或
- `template<class T> bool logical_not<T>`              //逻辑非



**示例：**

```
 #include <vector>
 #include <functional>
 #include <algorithm>
 void test01()
 {
     vector<bool> v;
     v.push_back(true);
     v.push_back(false);
     v.push_back(true);
     v.push_back(false);
 
     for (vector<bool>::iterator it = v.begin();it!= v.end();it++)
     {
         cout << *it << " ";
     }
     cout << endl;
 
     //逻辑非  将v容器搬运到v2中，并执行逻辑非运算
     vector<bool> v2;
     v2.resize(v.size());
     transform(v.begin(), v.end(),  v2.begin(), logical_not<bool>());
     for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
     {
         cout << *it << " ";
     }
     cout << endl;
 }
 
 int main() {
 
     test01();
 
     system("pause");
 
     return 0;
 }
```

总结：逻辑仿函数实际应用较少，了解即可

