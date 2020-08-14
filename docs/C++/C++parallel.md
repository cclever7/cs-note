<center><font size = 45>C++并发</font></center>

## 基本概念

1. **并发**：同一时间段，多个任务都在执行 (单位时间内不一定同时执行)，宏观上同时执行

2. **并行**：单位时间内，多个任务同时执行

3. **进程**

   进程是程序的一次执行过程，是系统运行程序的基本单位，因此进程是动态的。系统运行一个程序即是一个进程从创建，运行到消亡的过程。

4. **线程**

   线程与进程相似，但线程是一个比进程更小的执行单位。一个进程在其执行的过程中可以产生多个线程。与进程不同的是同类的多个线程共享进程的资源

5. **上下文切换**

   CPU 采取的策略是为每个线程分配时间片并轮转的形式。当一个线程的时间片用完的时候就会重新处于就绪状态让给其他线程使用，这个过程就属于一次上下文切换。概括来说就是：当前任务在执行完 CPU 时间片切换到另一个任务之前会先保存自己的状态，以便下次再切换回这个任务时，可以再加载这个任务的状态。**任务从保存到再加载的过程就是一次上下文切换**。

##### 线程与进程的区别

线程是进程划分成的更小的运行单位。线程和进程最大的不同在于基本上各进程是独立的，而各线程则不一定，因为同一进程中的线程极有可能会相互影响。线程执行开销小，但不利于资源的管理和保护；而进程正相反



## C++多线程相关支持

C++11 新标准中引入了五个头文件来支持多线程编程，它们分别是 `<atomic>, <thread>, <mutex>, <condition_variable>` 和 `<future>`。

<img src="medium/image-20200814171948633.png" alt="image-20200814171948633" style="zoom: 67%;" />

1. `<thread>`：该头文件主要声明了 `std::thread` 类，另外 `std::this_thread` 命名空间也在该头文件中。
2. `<future>`：该头文件主要声明了 `std::promise`, `std::package_task` 两个 Provider 类，以及 `std::future` 和 `std::shared_future` 两个 Future 类，另外还有一些与之相关的类型和函数，`std::async()` 函数就声明在此头文件中。
3. `<atomic>`：该头文主要声明了两个类, `std::atomic` 和 `std::atomic_flag`，另外还声明了一套 C 风格的原子类型和与 C 兼容的原子操作的函数。
4. `<mutex>`：该头文件主要声明了**与互斥量(Mutex)相关的类**，包括 `std::mutex_*` 一系列类，`std::lock_guard`, `std::unique_lock`, 以及其他的类型和函数。
5. `<condition_variable>`：该头文件主要声明了与条件变量相关的类，包括 `std::condition_variable` 和 `std::condition_variable_any`。



## 线程的生命周期状态



#### 线程的通信



#### 线程死锁

线程死锁描述的是这样一种情况：多个线程同时被阻塞，它们中的一个或者全部都在等待某个资源被释放。由于线程被无限期地阻塞，因此程序不可能正常终止。如下图所示，线程 A 持有资源 2，线程 B 持有资源 1，他们同时都想申请对方的资源，所以这两个线程就会互相等待而进入死锁状态。

![image-20200807174031905](D:\git\docs\C++\medium\image-20200807174031905.png)

## thread

`std::thread` **代表了一个线程对象，** 在 `<thread>` 头文件中声明。`<thread>` 头文件主要声明了 `std::thread` 类，另外在 `std::this_thread` 命名空间中声明了 `get_id`，`yield`， 等辅助函数，本章稍微会详细介绍 `std::thread` 类及相关函数。

#### 构造函数

| 默认构造函数 (1)           | thread() noexcept;                                           |
| -------------------------- | ------------------------------------------------------------ |
| 初始化构造函数 (2)         | template <class Fn, class... Args> explicit thread(Fn&& fn, Args&&... args); |
| 拷贝构造函数 [deleted] (3) | thread(const thread&) = delete;                              |
| Move 构造函数 (4)          | thread(thread&& x) noexcept;                                 |

1. 默认构造函数(1)，创建一个空的 `std::thread` 执行对象。
2. 初始化构造函数(2)，创建一个 `std::thread` 对象，该 `std::thread` 对象可被 `joinable`，新产生的线程会调用 `fn` 函数，该函数的参数由 `args` 给出。
3. 拷贝构造函数(被禁用)(3)，意味着 `std::thread` 对象不可拷贝构造。
4. Move 构造函数(4)，move 构造函数(move 语义是 C++11 新出现的概念，详见附录)，调用成功之后 `x` 不代表任何 `std::thread` 执行对象。

#### 其它函数

1. `get_id`：得到当前线程ID
2. `join`：调用该函数会阻塞当前线程，直到由 `*this` 所标示的线程执行完毕才返回。
3. `yield`: 当前线程放弃执行，操作系统调度另一线程继续执行。
4. `sleep`：`sleep_until` 以及 `sleep_for` 线程休眠至某个指定的时刻，该线程才被重新唤醒。
5. `swap`: 交换两个线程对象所代表的底层句柄。
6. `detach`: 将当前线程对象所代表的执行实例与该线程对象分离，使得线程的执行可以单独进行。一旦线程执行完毕，它所分配的资源将会被释放



## Mutex 互斥量

#### 互斥量与信号量

1. **互斥量**

   `Mutex` **又称互斥量**也称之为互斥锁，用来保证在任一时刻只能有一个线程访问该对象，每个线程在对资源操作前都尝试先加锁，成功加锁才能操作，操作结束后解锁，C++11 中与` Mutex `**相关的类（包括锁类型）和函数**都声明在 `<mutex>` 头文件中

2. **信号量**

   **互斥量用于线程的互斥**，**信号量用于线程的同步。**信号量是指在互斥的基础上（大多数情况），通过其它机制实现访问者对资源的有序访问。在大多数情况下，同步已经实现了互斥，特别是所有写入资源的情况必定是互斥的。少数情况是指可以允许多个访问者同时访问资源，因此**互斥量值只能为0/1，信号量值可以为非负整数**

#### Mutex 系列类

1. `std::mutex`

   最基本的 Mutex 类，该类提供了最基本的上锁和解锁操作。同时，基本的互斥量不允许某个线程在已获得互斥量的情况下重复对该互斥量进行上锁操作，所以重复上锁将会导致死锁（结果通常未定义的）。

2. `std::recursive_mutex`

   递归 Mutex 类，与 `std::mutex` 功能基本相同，但是允许互斥量的拥有者（通常是某个线程）重复对该互斥量进行上锁操作而不会产生死锁，但必须保证上锁和解锁的次数相同。

3. `std::time_mutex`

   定时 Mutex 类，与 `std::mutex` 功能基本相同，但是提供了两个额外的定时上锁操作，`try_lock_for` 和 `try_lock_until`，即某个线程在规定的时间内对互斥量进行上锁操作，如果在规定的时间内获得了锁则返回 `true`, 超时则返回 `false`，在本章后面的内容中我会介绍`try_lock_for` 和 `try_lock_until`两个上锁函数之间细微的差异。

4. `std::recursive_timed_mutex`

   定时递归 Mutex 类，既提供了重复上锁功能，又提供了定时上锁的特性（即在规定的时间内没有获得锁则返回 `false`），相当于 `std::recursive_mutex` 和 `std::time_mutex` 的组合。

#### Lock 类

，C++11 标准中定义了两种与互斥量相关的 RAII（资源获取即初始化）技术。（RAII：Resource Acquisition Is Initialization，资源获取即初始化，参见维基百科中与 [RAII](http://en.wikipedia.org/wiki/Resource_Acquisition_Is_Initialization) 相关的定义）

1. `std::lock_guard`，与 Mutex RAII 相关，方便线程对互斥量上锁。
2. `std::unique_lock`，与 Mutex RAII 相关，方便线程对互斥量上锁，但提供了更好的上锁和解锁控制。

- 其他类型

  1. `std::once_flag`，`call_once` 辅助函数会使用到该类型的对象。
  2. `std::adopt_lock_t`，一个空的标记类，定义如下：`struct adopt_lock_t {};`，该类型的常量对象`adopt_lock`（`adopt_lock` 是一个常量对象，定义如下：`constexpr adopt_lock_t adopt_lock {};`，`constexpr` 是 C++11 中的新关键字） 通常作为参数传入给 `unique_lock` 或 `lock_guard` 的构造函数。
  3. `std::defer_lock_t`，一个空的标记类，定义如下：`struct defer_lock_t {};`，该类型的常量对象`defer_lock`（`defer_lock` 是一个常量对象，定义如下：`constexpr defer_lock_t defer_lock {};`） 通常作为参数传入给`unique_lock` 或 `lock_guard` 的构造函数。。
  4. `std::try_to_lock_t`，一个空的标记类，定义如下：`struct try_to_lock_t {};`，该类型的常量对象`try_to_lock`（`try_to_lock` 是一个常量对象，定义如下：`constexpr try_to_lock_t try_to_lock {};`） 通常作为参数传入给`unique_lock` 或 `lock_guard` 的构造函数。。

  

#### 辅助函数

1. `std::try_lock`，尝试同时对多个互斥量上锁。
2. `std::lock`，同时对多个互斥量上锁。
3. `std::call_once`，如果多个线程需要同时调用某个函数，`call_once` 可以保证多个线程对该函数只调用一次



# 条件变量与线程同步

- `<condition_variable>` 头文件中的类及相关函数的介绍。
- `std::condition_variable` 与 Pthread 线程库中的 `pthread_cond_t` 类型的对比，包括两者编程接口的差异及其他细节。
- 利用条件变量 `std::condition_variable` 进行线程同步的应用实例。



## <future\>头文件摘要

C++11 标准中与异步任务系相关的类型主要是以下四种 `std::promise`，`std::packaged_task`（`std::promise`，`std::packaged_task` 也称为异步任务的提供者 Provider，此外 `std::async` 也可以作为异步任务的提供者，不过 `std::async` 并不是类，而是函数，本章后面会详细介绍异步任务的提供者 Provider），`std::future`，`std::shared_future`。另外 `<future>` 中还定义一些辅助的类，例如： `std::future_error`，`std::future_errc`，`std::status`，`std::launch`。





## \<atomic\>头文件摘要

- 什么是原子类型，原子类型的适用场景。
- C++11 标准中 `<atomic>` 头文件中的类及相关函数的介绍。
- 利用原子变量 `std::atomic` 进行线程同步的应用实例。



## 内存模型



## 并发数据结构



## 应用场景

#### 生产者消费者模型

```c++

```



