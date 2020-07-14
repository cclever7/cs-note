<center><font size = 50>缓存预取</font></center>

## 概念

预取技术是一种通过预测将要访问的数据并将其提前读取到缓存中，从而对上层隐藏数据从磁盘中的读取时间，最终达到缓解磁盘 IO 读取效率不高的问题。

关键问题：

1. 缓存污染：当预取数据替换更有用的预取数据或需求分页数据
2. 预取浪费：当预取数据被提前从缓存中移除时发生

其它问题：存储系统的应用与存储系统之间的 IO 接口非常的简单，使得存储应用只能执行按照一定单位的读取或者写入的操作，而不能提供访问模式或者访问语义相关的信息。只能利用空间的局部性，顺序性以及循环引用等简单的方法来提升存储系统的性能

## 缓存预取级别分类

**预取算法基本都离不开利用数据访问的局部性特征，对历史访问数据的分析，数据在磁盘中的分布等等**。这些因素，是一个预取算法好坏的关键。

#### 通用预取

当下比较主流的通用缓存预取算法有：固定预取算法、顺序预取算法、基于应用暗示的预取算法以及基于数据挖掘的预取算法。

#### 文件级预取

1. 文件级缓存预取算法是 NEXUS 算法，集群服务器的响应能力，是一种基于加权图数据结构实现的预取算法。NEXUS 预取算法预取的数据对象是元数据，

[1]Peng G, Zhu Y, Hong J, et al. Nexus: A Novel Weighted-Graph-Based Prefetching Algorithm for Metadata Servers in Petabyte-Scale Storage Systems.In IEEE International Symposium on Cluster Computing & the Grid. 2006

#### 块级预取

块级预取技术与文件预取技术的区别是预取的粒度不同，相较于文件级预取， 块级预取的粒度更小，预取出错对缓存造成的影响也会小很多。目前，对块级预取的研究有基于顺序的预取，有基于挖掘频繁子序列的预取，也有基于数据访问时空关系的预取。

## 块级缓存预取分类

#### 固定预取算法

只需指定当前访问内容后的 n 个数据即可。

缺点：预取比较固化，对缓存造成污染，增加对磁盘读取的压力，预取的效率比较低，影响系统的性能。

#### 顺序预取算法

**分类**：

1. 同步顺序预取：只能在一次Miss时进行预取
2. 异步顺序预取：它也可以在一次Hit时进行预取

**概念**：类似于固定预取算法，为连续存储I/O请求数据的数据生成预取请求。但是还将根据磁盘数据访问特性，自动的调整预取数量，更加灵活

**组成**：序列检测模块、预取模块、缓存模块。**（三个组成部分具体分析及相关论文在（TaP论文）中)）**

1. **序列检测模块：**负责检测当前访问流的特征是否为顺序流，给预取模块提供预取指令。

   当一个I/O请求在缓存中Miss时，序列检测模块被激活。大多数当前的预取技术使用缓存来跟踪地址，或基于缓存中以前的访问模式来预测未来的访问。一些技术使用离线信息，并且需要知道未来的数据访问模式来进行预取（OPT）。其它还将使用CaP技术

2. **预取模块预取模块：**根据序列检测模块的指令完成预取工作

3. **缓存模块组成：**缓存模块则将预取的内容放入缓存

#### 应用暗示的预取算法

将基于上层程序的提示完成预取工作, 需要提供给上层应用一个接口用于传达预取数据指令。像视频、音频、数据备份和恢复等很多应用其 I/O基本是顺序的，而 Web 应用其访问是基于链接的分枝访问，数据库应用经常需要进行随机访问。

特点：预取算法预取准确率较高，但需要提供给上层应用一个接口，系统支持度较低

#### 基于数据挖掘的预取算法

通过对历史数据访问的分析，挖掘出数据潜在的关系，从而实现预取。

#### 其它预取方法（主要是深度学习）

基于深度学习挖掘存储块的相关性

## 固定预取算法

只需指定当前访问内容后的 n 个数据即可。

## 顺序预取算法

1. 基于顺序的预取算法主要有 STEP，它主要是为了解决多个应用同时运行产生的交叉顺序流问题。该算法通过在运行时维护多个顺序流，在复杂的访问流中找到暗藏的顺序访问，从而提升顺序预取的效率。

[1] Liang S, Jiang S, Zhang X. STEP: Sequentiality and thrashing detection based prefetching to improve performance of networked storage servers.In 27th International Conference on Distributed Computing Systems (ICDCS'07). IEEE, 2007: 64-64

## 应用暗示的预取算法

1. 该文章提出了一种根据用户偏好来选择预取数据的预取算法。即由用户暗示的透明信息预取方法（TIP），TIP 可以根据用户提供的访问方式在适当的时候发出异步的预取指令，指令内容由用户的暗示确定。 这类算法增加了一个能够提供给上层应用接口的模块， 应用通过此模块告知预取模块相应的信息。 

[1]Patterson R H , Gibson G A , Satyanarayanan M . A status report on research in transparent informed prefetching.In ACM SIGOPS Operating Systems Review, 1993, 27(2):21-34

## 基于数据挖掘的预取算法

1. 通过使用频繁的序列挖掘，可以获得所有访问流中的频繁子序列。而子序列表示涉及的块经常出现一起访问。这些频繁的子序列其实是数据访问的相关性一种体现。C-Miner 就是通过统计频繁子序列的方法找到数据块之间的相关性，并通过考虑子序列之间的距离将其转化为关联规则，最终用于缓存预取以及数据的布局优化。
2. DiskSeen 预取算法是基于数据访问时空关系的一种预取算法。DiskSeen 通过跟踪磁盘块的位置和访问时间，分析它们的时空关系，最终提高磁盘访问和整体的顺序性。

[1] Li Z, Chen Z, Srinivasan S M, et al. C-Miner: Mining Block Correlations in Storage Systems .In Usenix Conference on File & Storage Technologies,2004

[2] Ding X , Jiang S , Chen F , et al. DiskSeen: Exploiting Disk Layout and Access History to Enhance I/O Prefetch. Proceedings of the 2007 USENIX Annual Technical Conference, June 17-22, 2007, Santa Clara, CA, USA. USENIX Association, 2007

## 其它预取方法（主要是深度学习）

1. 基于深度学习挖掘数据块相关性的代表算法是 Block2Vec。该算法来源于自然语言处理中的 Word2Vec技术。核心原理是，通过将历史数据访问序列按照时间间隔分段之后，使用 CBOW 模型]或者 Skip-Gram 模型计算出每个数据块的向量表示。得到的向量就是块的相关性的一种表达，通过计算向量之间的距离来推断数据块相关的程度，最终也可以用于数据块的预测与存储数据的布局优化。

[1]Dai D, Bao F S, Zhou J, et al. Block2Vec: A Deep Learning Strategy on Mining Block Correlations in Storage Systems.In International Conference on Parallel Processing Workshops. 2016

## 其它论文

| 编号 | 会议/时间 | 论文题目                                                     | 研究对象       | 研究方法                                                     | 结论 | 其它                                 |
| ---- | --------- | ------------------------------------------------------------ | -------------- | ------------------------------------------------------------ | ---- | ------------------------------------ |
| 1    |           | Sequential prefetch cache sizing for maximal hit rate        | 预取缓存的大小 | 构建预取缓存大小的模型和评估了缓存大小对顺序预取技术性能的影响 |      | 第一篇系统地解决存储预取缓存大小问题 |
| *2   |           | TaP: Table-based Prefetching for Storage Caches Mingju       | 顺序预取       | 使用一个TaP（请求地址表）记录请求地址，来检测I/O工作负载中的顺序访问模式，并动态地确定最优预取缓存的大小。当到达的I/O请求在预取缓存中丢失时，TaP技术搜索TaP表以检查这个新请求的地址是否连续。如果是，TaP将这个I/O请求标记为属于一个顺序流并激活预取，否则TaP技术将把这个请求的地址插入到TaP表中。 |      |                                      |
| 3    |           | SARC: Sequential Prefetching in Adaptive Replacement Cache   | 顺序预取       | 1. 修了连续预取与缓存集成时异常<br />2. 设计了自调优、低开销、简单实现、本地自适应的新型缓存管理策略SARC，该策略动态地、自适应地在顺序和随机流之间划分缓存空间，以减少读取失误。 |      | 未搜索其引用                         |
| 4    |           | AMP: Adaptive Multi-stream Prefetching in a Shared Cache Binny | 顺序预取       | 结合固定、顺序预取。定义了四类预取算法:固定同步(FS)、固定异步(FA)、自适应同步(AS)和自适应异步(AA)。AA类是最有效的方法该算法可以在每个流的基础上调整预取度和触发距离，以响应不断变化的工作负载，这篇文章提供了一个称为AMP的简单实现，它可以相应地进行调整，在任何顺序工作负载和缓存大小的情况下都能获得接近最佳的性能。 |      | 未搜索其引用                         |



















