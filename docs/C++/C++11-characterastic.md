<center><font size = 45>C++11</font></center>

  1.所有的STL容器支持初始化列表。   std::vector<int> v = { 1, 2, 3 };
  2.自定义calss支持初始化列表。    //？
  3.auto 类型推导关键词
  4.统一的初始化方法          Uniform Initialization //？
  5.新的遍历方式,对 容器或者数组 遍历使用
    for(aoto i: a){}
  6.nullptr的存在，实际是 为0的值和NULL一样是等于0，但是在函数发生重载的时候编译器可以知道是调用的那个函数。
    void funC(int a)
    void funC(int* a)
  7.对枚举做了一个强类型枚举 
    因为原来的枚举有两个缺点
      \1. 不同的枚举类型但是名字起一样会编译报错。
        enum Dir{
          left,Right
        };
        enum Pos{
          left,Right
        };
      \2. 不同的枚举类型可以判断
        if(dir == pos){}  //dir和pos分类是两种枚举，但是这里可以判断，不合理
    所以引入了强类型枚举 但是使用的时候要加入 Direction::Left。
      enum class Dir{
        Left,Right
      }
      enum class{
        Left,Right
      }
      auto a = Direction::Left;
      auto b = Answer::Right;
      if (a == b) //编译报错 ，因为不是同一个类型
  8.显式重写 override 
  9.lambda表达式
  auto add = [](int a, int b) { return a + b; };
  std::cout << add(1, 2) << std::endl;  
  捕获
    [a](){}
    [a,&b](){}
    [=]    全部值捕获
    [&]    全部是引用捕获
   这里注意 
    1.捕获时机
    int i = 1;
    auto f = [=]() { std::cout << i << std::endl; };    // i=1 因为 i 传递进来是一个值
    auto f = [&]() { std::cout << i << std::endl; };    // i=2 因为 i 是引用进来的
    i = 2;
    2.生命周期
    std::function<void()> GetLambda() {
      int i = 1;
      return [&]() { std::cout << i << std::endl; };
    }

​    auto f = GetLambda();
​    f(); // 输出 -858993460 之类的乱码
  10.delete关键字
​    用于删除构造函数
​    class A {        //以前版本
​    private:
​      A();
​    };
​    class A {        //11版本
​    public:
​      A() = delete;
​    };
  11.默认构造函数 default
​    因为在有其他的构造函数的时候是不会有默认构造的，但是程序员希望有默认的时候可以写成是 下面这个
​    class A {
​    public:
​      A(int i) {}
​      A() = default;    
​    };
​    当然 A(){}也是也可以的
​    但用default意图更加明确，编译器也可以相应地做优化
  12.常量表达式(constexpr) 
​    在编译期就可以计算出结果的表达式。
​     对constexpr函数的基本要求：
​      常量表达式函数必须有返回值（不可以是void函数）  常量表达式函数体中只能有一条语句，且该语句必须是return语句。（可以使用?:、递归）但不产生实际代码的语句可以在常量表达式函数中使用，如static_assert,using,typedef等（这条规定在C++14中大幅放松）
​      return语句中，不能使用非常量表达式的变量、函数，且return的表达式也要是常量表达式
​      常量表达式函数在使用前，必须有定义。（普通函数在被调用前只要有函数声明就够了，不一定有定义）
​    与const的本质区别
​      const主要用于表达“对接口的写权限控制”，
​      constexpr的主要功能则是让更多的运算可以在编译期完成，并能保证表达式在语义上是类型安全的。
  13.字符串字面量
​    R"( )" 这样的形式来写入的字符串是原样的字符串。
​    // 一个raw string，'\'不会被转义处理。因此，"\n"表示两个字符：字符反斜杠 和 字母n。
​    std::string strone = R"(First line.\nSecond line.\nEnd of message.\n)";
​    auto xml = R"(<root>
​      <item value="1">
​      <item value="2">
​    </root>)";//这样的写***吧里面的内容原样的输入