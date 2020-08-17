<center><font size = 45>C++11新特性</font></center>

#### 所有STL容器支持初始化列表

例如： `std::vector<int> v = { 1, 2, 3 }`



#### 自定义class支持初始化列表

```c++
class A {
public:
    A(const std::initializer_list<int> &items) : m_items(items){
        
    }
private:
    std::vector<int> m_items;
};
int main() {
    A a1 = {1, 2, 3};
}
```



#### forEach遍历方式

对容器或者数组可以使用`forEach`遍历， `for(auto i: a){}`



#### nullptr

传统 C++ 会把 `NULL`、`0 `视为同一种东西，这取决于编译器如何定义 `NULL`，有些编译器会将` NULL`定义为` ((void*)0)`，有些则会直接将其定义为 `0`，因此C++11 引入了` nullptr` 关键字，专门用来区分空指针与`0`



#### decltype

`decltype`关键字是为解决`auto`关键字只能对变量进行类型推导的缺陷。用法与`sizeof`类似：`decltype(x + y) z;`



#### auto

 自动推导类型，` Map<int, int>::iterator itor = mmap.find();`

1. `auto`声明的变量必须要初始化，否则编译器不能判断变量的类型。
2. `auto`不能被声明为返回值，`auto`不能作为形参，`auto`不能被修饰为模板参数



#### lambda表达式

`lambda`表达式是匿名函数，可以认为是一个可执行体`functor`，语法：`[捕获区](参数区){代码区};`

```c++
auto add = [](int a, int b) { return a + b; };
std::cout << add(1, 2) << std::endl; 
```

##### 捕获

捕获即为将一些变量展开使得为`lambda`内部可见 

- `[a,&b]`其中 `a` 以复制捕获而 `b` 以引用捕获。

- `[this] `以引用捕获当前对象`(*this)`

- `[&] `以引用捕获所有用于 `lambda` 体内的自动变量，并以引用捕获当前对象，若存在

   `auto f = [&]() { std::cout << i << std::endl; }; `

- `[=] `以复制捕获所有用于 `lambda` 体内的自动变量，并以引用捕获当前对象，若存在

   `auto f = [=]() { std::cout << i << std::endl; }; `

- `[]` 不捕获，大部分情况下不捕获就可以了



#### 正则表达式

正则表达式描述了一种字符串匹配的模式。一般使用正则表达式主要是实现下面三个需求： 

1. 检查一个串是否包含某种形式的子串； 
2. 将匹配的子串替换；
3. 从某个串中取出符合条件的子串。

  

#### 统一的初始化方法       

可以统一使用大括号`{}`进行初始化。对构造函数的选择的优先级如下

```c++
class A {
public:
    A(const std::initializer_list<int> &items) : m_items(items){
    }
    
    A(int age) : age(age) {
    }
private:
    std::vector<int> m_items;
    int age;
};
int main() {
    A a{5};
}
```



#### 默认构造函数 `default`

有其他的构造函数的时候是不会有默认构造的，但是程序员希望有默认的时候可以写成是`A() = default; `当然 `A(){}`也是也可以的



#### 对枚举做了一个强类型枚举 

原来的枚举有两个缺点，因此引入了强类型枚举，使用的时候要加入 `Dir::Left`

1. 不同的枚举类型但是名字起一样会编译报错。

   ```c++
   enum Dir{
       left,Right
   };
   enum Pos{
       left,Right
   };
   ```

2. 不同的枚举类型可以判断

   ```c++
    if(dir == pos){}  //dir和pos分类是两种枚举，但是这里可以判断，不合理
   ```



#### 显式重写 `override`和`final`

1. 显示重写`override`：`void fun() override {}`
2. 显示重写`final`：`virtual void fun() final {}`



#### `delete`关键字

`delete`关键字放在函数后面，表示函数不能被调用 。`A() = delete;`



#### 智能指针

1. `auto_ptr`（c++98的方案，cpp11已经抛弃）

   采用所有权模式。`p2 = p1`，`p2`剥夺`p1`的所有权当程序运行时访问`p1`将会报错。因此其存在潜在的内存崩溃问题

2. `unique_ptr`（替换`auto_ptr`）

   实现独占式拥有或严格拥有概念，保证同一时间内只有一个智能指针可以指向该对象。

3. `shared_ptr`

   实现共享式拥有概念。多个智能指针可以指向相同对象，该对象和其相关资源会在“最后一个引用被销毁”时候释放。它使用计数机制来表明资源被几个指针共享，使用`use_count()`来查看资源的所有者个数。该引用计数的内存在堆上分配。当新增一个时引用计数加1，当过期时引用计数减一。只有引用计数为0时，智能指针才会自动释放引用的内存资源。当两个对象相互使用一个`shared_ptr`成员变量指向对方，会造成循环引用，使引用计数失效导致**内存泄漏**。使用`weak_ptr`解决

4. `weak_ptr`

   是一种不控制对象生命周期的智能指针, 它指向一个 `shared_ptr` 管理的对象. 进行该对象的内存管理的是那个强引用的` shared_ptr`， `weak_ptr`只是提供了对管理对象的一个访问手段。`weak_ptr` 设计的目的是为配合 `shared_ptr` 而引入的一种智能指针来协助`shared_ptr` 工作, 它只可以从一个 `shared_ptr` 或另一个 `weak_ptr `对象构造, 它的构造和析构不会引起引用记数的增加或减少。`weak_ptr`是用来解决`shared_ptr`相互引用时的死锁问题,如果说两个`shared_ptr`相互引用,那么这两个指针的引用计数永远不可能下降为0,资源永远不会释放。它是对对象的一种弱引用，不会增加对象的引用计数，和`shared_ptr`之间可以相互转化，`shared_ptr`可以直接赋值给它，它可以通过调用`lock函数`来获得`shared_ptr`



#### tuple

`std::pair<std::string,int>`的扩展版，可以当做一个通用的结构体来使用

```c++
void fun() {
    std::tuple<int, std::string, char> t(2, "foo", 'a')
}
```



#### 语言级线程支持

[链接](./c++parallel)



#### T&& 右值引用 std::move

透彻讲解右值引用、移动语义、完美转发链接：https://www.jianshu.com/p/d19fc8447eaa

右值引用出现之前我们只能用const引用来关联临时对象（右值）所以我们不能修临时对象的内容，右值引用的出现就让我们可以取得临时对象的控制权，终于可以修改临时对象了！



