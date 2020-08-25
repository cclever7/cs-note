<center><font size = 45>LeetCode</font></center>

## 题序

- [01~10](#01)

- [11~20](#11)

- [21~30](#21)

- [31~40](#31)

- [41~50](#41)

- [51~60](#51)

- [61~70](#61)

- [71~80](#71)

- [81~90](#81)

- [91~100](#91)

- [101~110](#101)

- [111~120](#111)

- [121~130](#121)

- [131~140](#131)

- [141~148](#141)

  

## 01

求给定二叉树的最小深度。最小深度是指树的根结点到最近叶子结点的最短路径上结点的数量。

#### 思路

1. 若节点为空则返回为0，若节点的左右节点为空则返回为1，若节点左节点或右节点为空则返回 1+ run(), 否则返回最小值 

```c++
int run(TreeNode* root) {
    if(root == nullptr)
        return 0;
    else if(root->left == nullptr && root->right == nullptr)
        return 1;
    else if(root->right == nullptr)
        return 1 + run(root->left);
    else if(root->left == nullptr)
        return 1 + run(root->right);
    else
        return 1 + min(run(root->left), run(root->right));
}
```

## 02

计算逆波兰表达式

计算逆波兰式（后缀表达式）的值，运算符仅包含"+","-","*"和"/"，被操作数可能是整数或其他表达式

#### 思路

1. 使用一个栈进行操作，碰到+-*/就取栈顶的两个元素进行操作，否则就将数进行入栈操作

```c++
    int evalRPN(vector<string>& tokens) {
        // write code here
        if(tokens.empty())
            return 0;
        stack<int> stk;
        for(auto x : tokens) {
            if(x == "+" || x == "-" || x == "/" || x == "*") {
                if(stk.size() < 2)
                    return 0;
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                int c = 0;
                if(x == "+") 
                    c = a + b;
                else if (x == "-")
                    c = b - a;
                else if (x == "*")
                    c = a * b;
                else 
                    c = b / a;
                stk.push(c);
            } else {
                stk.push(atoi(x.c_str()));
            }
        }
        return stk.top();
    }
```

## 03

#### 思路



```c++

```



## 04

在(nlogn)的时间内使用常数级空间复杂度对链表进行排序

#### 思路

1. 使用归并排序
2. 对链表需要将链表分开即找到中间节点，即使用快慢指针

```c++
 ListNode* sortList(ListNode* head) {
     // write code here
     if(!head || !head->next)
         return head;
     ListNode *p = head;
     ListNode *q = head->next;
     while(q && q->next) {
         p = p->next;
         q = q->next->next;
     }
     ListNode *left = sortList(p->next);
     p->next = nullptr;
     ListNode *right = sortList(head);
     return merge(left, right);
 }

ListNode* merge(ListNode* left, ListNode* right) {
    ListNode* head = new ListNode(0);
    ListNode *p = head;
    while(left && right) {
        if(left->val < right->val) {
            p->next = left;
            left = left->next;
        } else {
            p->next = right;
            right = right->next;
        }
        p = p->next;
    }
    if(left)
        p->next = left;
    if(right)
        p->next = right;
    return head->next;
}
```



## 05



#### 思路



```c++

```



## 06

给出一个二叉树，返回这个二叉树的后序遍历

#### 思路

1. 递归方法
2. 非递归方法，使用栈进行操作

```c++
//method 1
vector<int> res;
vector<int> postorderTraversal(TreeNode* root) {
    // write code here
    if(root != nullptr) {
        if(root->left != nullptr)
            postorderTraversal(root->left);
        if(root->right != nullptr)
            postorderTraversal(root->right);
        res.push_back(root->val);
    }
    return res;
}
//method 2
...
```

## 07

求给定的二叉树的前序遍历。

#### 思路

1. 递归方法
2. 非递归方法，使用栈进行操作

```c++
//method 1
vector<int> res;
vector<int> preorderTraversal(TreeNode* root) {
    // write code here
    if(root != nullptr) {
        res.push_back(root->val);
        if(root->left != nullptr)
            preorderTraversal(root->left);
        if(root->right != nullptr)
            preorderTraversal(root->right);
    }
    return res;
}
//method 2
...
```



## 08



#### 思路



```c++

```



## 09

将给定的单链表\ L *L*： L_0→L_1→…→L_{n-1}→L_ n*L*0→*L*1→…→*L**n*−1→*L**n*
重新排序为：L_0→L_n →L_1→L_{n-1}→L_2→L_{n-2}→…*L*0→*L**n*→*L*1→*L**n*−1→*L*2→*L**n*−2→…
要求使用原地算法，不能改变节点内部的值，需要对实际的节点进行交换。
例如：
对于给定的单链表{1,2,3,4}，将其重新排序为{1,4,2,3}.

#### 思路

1. 找到链表的中间节点
2. 将后一段链表利用头插头逆序
3. 前后两段链表各进行取一个，合并成新的链表 

```c++

```



## 10

对于一个给定的链表，返回环的入口节点，如果没有环，返回null

拓展：

你能给出不利用额外空间的解法么？

#### 思路

1. 利用map，有环时一定能够找到
2. 使用快慢指针原理，快指针比慢指针多走两步，套圈原理

```c++
//mehtod 1
ListNode *detectCycle(ListNode *head) {
    if(!head)
        return head;
    map<ListNode*, int> node_map;
    ListNode *p = head;
    while(p) {
        auto itor = node_map.find(p);
        if(itor != node_map.end()) {
            return p;
        } else {
            node_map.insert(make_pair(p, 1));
            p = p->next;
        }
    }
    return nullptr;
}
//method 2


```

## 11

判断给定的链表中是否有环，解法与第10题基本类似

扩展：你能给出不利用额外空间的解法么？

#### 思路

1. 利用map，有环时一定能够找到
2. 使用快慢指针原理，快指针比慢指针多走两步，套圈原理

```c++
//method 1
bool hasCycle(ListNode *head) {
    if(!head)
        return head;
    map<ListNode*, int> node_map;
    ListNode* p = head;
    while(p) {
        auto itor = node_map.find(p);
        if(itor != node_map.end()) {
            return true;
        } else {
            node_map.insert(make_pair(p, 1));
            p = p->next;
        }
    }
    return false;
}
//method 2

```



## 12



#### 思路



```c++

```



## 13



#### 思路



```c++

```



## 14

现在有一个整数类型的数组，数组中只有一个元素只出现一次，其余元素都出现三次。你需要找出只出现一次的元素

**注意：**你需要给出一个线性时间复杂度的算法，你能在不使用额外内存空间的情况下解决这个问题么？

#### 思路

1. Single Number的本质，就是用一个数记录每个bit出现的次数，如果一个bit出现两次就归0，这种运算采用二进制底下的位操作^是很自然的。
2. Single Number II中，如果能定义三进制底下的某种位操作，也可以达到相同的效果，Single Number II中想要记录每个bit出现的次数，一个数搞不定就加两个数，用ones来记录只出现过一次的bits，用twos来记录只出现过两次的bits，ones&twos实际上就记录了出现过三次的bits，这时候我们来模拟进行出现3次就抵消为0的操作，抹去ones和twos中都为1的bits。

```c++

```



## 15

现在有一个整数类型的数组，数组中素只有一个元素只出现一次，其余的元素都出现两次。

**注意：**你需要给出一个线性时间复杂度的算法，你能在不使用额外内存空间的情况下解决这个问题么？

#### 思路

1. 使用map来统计元素出现的次数
2. 使用异或，相等的元素进行异或得到是零，因此唯一不重复的数是数组最终异或的结果

```c++
int singleNumber(int* A, int n) {
    // write code here
    if(n == 0)
        return -1;
    int res = 0;
    for(int i = 0; i < n; i++) {
        res ^= A[i];
    }
    return res;
}
```



## 16

有N个小朋友站在一排，每个小朋友都有一个评分

你现在要按以下的规则给孩子们分糖果：

- 每个小朋友至少要分得一颗糖果
- 分数高的小朋友要他比旁边得分低的小朋友分得的糖果多

你最少要分发多少颗糖果？

#### 思路

1. 动态规划
2. 与前面的邻居比较，前向遍历权重数组ratings，如果ratings[i]>ratings[i-1]，则A[i]=A[i-1]+1；
3. 与后面的邻居比较，后向遍历权重数组ratings，如果ratings[i]>ratings[i+1]且A[i] <=A[i+1]+1，则更新A，A[i]=A[i+1]+1；
4. 对A求和即为最少需要的糖果。

```c++
int candy(vector<int>& ratings) {
    // write code here
    if(ratings.empty())
        return 0;
    int *res = new int[ratings.size()];
    for(int i = 0; i < ratings.size(); i++)
        res[i] = 1;
    for(int i = 1; i < ratings.size(); i++) {
        if(ratings[i] > ratings[i-1])
            res[i] = res[i-1] + 1;
    }
    //
    for(int i = ratings.size() - 2; i >= 0; i--) {
        if(ratings[i] > ratings[i+1] && res[i] <= res[i+1])
            res[i] = res[i+1] + 1;
    }
    int sum = 0;
    for(int i = 0; i < ratings.size(); i++) {
        sum += res[i];
    }
    return sum;
}
```



## 17



#### 思路



```c++

```



## 18



#### 思路



```c++

```



## 19



#### 思路



```c++

```



## 20



#### 思路



```c++

```



## 21



#### 思路



```c++

```



## 22

给定一个二叉树，请计算节点值之和最大的路径的节点值之和是多少。
这个路径的开始节点和结束节点可以是二叉树中的任意节点
例如：
给出以下的二叉树，
![image-20200809150905508](medium/image-20200809150905508.png)
返回的结果为6

#### 思路

1. 广度遍历， 每一层的结果等当前结果乘以10，加上下一层的左右节点的值 
2. 深度遍历，使用堆栈

```c++
//method 1
int sumNumbers(TreeNode* root) {
    // write code here
    int res = 0;
    if(root == nullptr) {
        return res; 
    }
    return preorder_traverse(root, res);
}

int preorder_traverse(TreeNode* root, int res) {
    if(root == nullptr)
        return 0;
    res = res * 10 + root->val;
    if(root->left == nullptr && root->right == nullptr)
        return res;
    return preorder_traverse(root->left, res) + preorder_traverse(root->right, res);
}

//method 2
```



## 23



#### 思路



```c++

```



## 24



#### 思路



```c++

```



## 25



#### 思路



```c++

```



## 26



#### 思路



```c++

```



## 27



#### 思路



```c++

```



## 28



#### 思路



```c++

```



## 29



#### 思路



```c++

```



## 30



#### 思路



```c++

```



## 31

给出一个三角形，计算从三角形顶部到底部的最小路径和，每一步都可以移动到下面一行相邻的数字，

例如，给出的三角形如下：

```
[↵     [2],↵    [3,4],↵   [6,5,7],↵  [4,1,8,3]↵]
```

最小的从顶部到底部的路径和是2 + 3 + 5 + 1 = 11。

注意：如果你能只用O（N）的额外的空间来完成这项工作的话，就可以得到附加分，其中N是三角形中的行总数。

#### 思路

1. 

```c++

```



## 32

给出一个索引k，返回杨辉三角的第k行

例如，k=3，

返回[1,3,3,1].

备注：

你能将你的算法优化到只使用O(k)的额外空间吗?

#### 思路

按行进行模拟，先赋入第一行的初始值， 后续的行当为起始或最终的值其为1， 其它均为res[i] = res[i] + res[i-1]

```c++
vector<int> getRow(int rowIndex) {
    // write code here
    vector<int> res= {1};
    if(rowIndex == 0)
        return res;
    for(int i = 1; i <= rowIndex; i++) {
        int row_cnt = i + 1;
        vector<int> v2(row_cnt);
        for(int j = 0; j < row_cnt; j++) {
            if(j == 0 || j == row_cnt - 1)
                v2[j] = 1;
            else
                v2[j] = res[j-1] + res[j];
        }
        res.clear();
        res.assign(v2.begin(), v2.end());
        v2.clear();
    }
    return res;
}
```

## 33

给出一个值numRows，生成杨辉三角的前numRows行

例如，给出 numRows = 5,

```
返回     [1],↵    [1,1],↵   [1,2,1],↵  [1,3,3,1],↵ [1,4,6,4,1]↵]
```

#### 思路

1. 按行进行模拟，先赋入第一行的初始值， 后续的行当为起始或最终的值其为1， 其它均为res[i] = res[i] + res[i-1]

```c++
vector<vector<int> > generate(int numRows) {
    // write code here
    vector<vector<int>> res;
    if(numRows == 0)
        return res;
    vector<int> v = {1};
    res.push_back(v);
    for(int i = 1; i < numRows; i++) {
        int rows_cnt = i + 1;
        vector<int> tmp(rows_cnt);
        for(int j = 0; j < rows_cnt; j++) {
            if(j == 0 || j == rows_cnt - 1){
                tmp[j] = 1;
            } else {
                vector<int> v = res[i-1];
                tmp[j] = v[j] + v[j-1];
            }
        }
        res.push_back(tmp);
    }
    return res;
}
```



## 34



#### 思路



```c++

```



## 35



#### 思路



```c++

```



## 36



#### 思路



```c++

```



## 37



#### 思路



```c++

```



## 38



#### 思路



```c++

```



## 39



#### 思路



```c++

```



## 40

给定一个单链表，其中的元素按升序排序，请将它转化成平衡二叉搜索树（BST）

#### 思路

此题相对于41题 ，就是需要找到链表的中间节点，此时可用快慢指针进行查找

```c++

```



## 41

给出一个升序排序的数组，将其转化为平衡二叉搜索树（BST）.

输入
[-1,0,1,2]
输出
{1,0,2,-1}

#### 思路

这道题是二分查找树的题目，要把一个有序数组转换成一颗二分查找树。从本质来看，如果把一个数组看成一棵树（也就是以中点为根，左右为左右子树，依次下去），数组就等价于一个二分查找树。所以如果要构造这棵树，那就是把中间元素转化为根，然后递归构造左右子树。
```c++
TreeNode* sortedArrayToBST(vector<int>& num) {
    // write code here
    if(num.empty())
        return nullptr;
    int left = 0, right = num.size() - 1;
    return getNode(num, left, right);
}

TreeNode* getNode(std::vector<int> num, int left, int right) {
    if(left > right)
        return nullptr;
    if(left == right)
        return new TreeNode(num[left]);
    int mid = left + (right - left + 1) / 2;
    TreeNode *root = new TreeNode(num[mid]);
    root->left = getNode(num, left, mid - 1);
    root->right = getNode(num, mid + 1, right);
    return root;
}
```



## 42

给定一个二叉树，返回该二叉树由底层到顶层的层序遍历，（从左向右，从叶子节点到根节点，一层一层的遍历）

例如：给定的二叉树是{3,9,20,#,#,15,7}, 遍历的结果是：[[15,7],[9,20],[3]]

#### 思路

1. 层序遍历采用队列的思路

```c++

```



## 43

给出一棵树的中序和后序遍历，请构造这颗二叉树

#### 思路



```c++

```



## 44

给出一棵树的前序遍历和中序遍历，请构造这颗二叉树

#### 思路



```c++

```



## 45

求给定二叉树的最大深度，最大深度是指树的根结点到最远叶子结点的最长路径上结点的数量。

#### 思路



```c++

```



## 46

给定一个二叉树，返回该二叉树的之字形层序遍历，（第一层从左向右，下一层从右向左，一直这样交替）
例如：给定的二叉树是{3,9,20,#,#,15,7},

#### 思路



```c++

```



## 47

给定一个二叉树，返回该二叉树层序遍历的结果，（从左到右，一层一层地遍历）
例如：给定的二叉树是{3,9,20,#,#,15,7},

#### 思路



```c++

```



## 48

给定一棵二叉树，判断琪是否是自身的镜像（即：是否对称）

#### 思路

1. 节点的左子树的右子树相等，且左子树的右子树等于右子树的左子树，采用递归进行求解

```c++
bool isSymmetric(TreeNode *root) {
    if(root == nullptr)
        return true;
    return method(root->left, root->right);
}

bool method(TreeNode *left, TreeNode *right) {
    if(left == nullptr && right == nullptr)
        return true;
    if(left == nullptr)
        return false;
    if(right == nullptr)
        return false;
    if(left->val == right->val) {
        return method(left->left, right->right) && method(left->right, right->left);
    }
    return false;
}

```

## 49

给出两个二叉树，请写出一个判断两个二叉树是否相等的函数。

判断两个二叉树相等的条件是：两个二叉树的结构相同，并且相同的节点上具有相同的值。

#### 思路

1. 要么p和q都为空，否则p和q的节点值相同，且其左右子树节点也相同。使用递归

```c++
bool isSameTree(TreeNode* p, TreeNode* q) {
    // write code here
    if(p == nullptr && q == nullptr)
        return true;
    if(p == nullptr)
        return false;
    if(q == nullptr)
        return false;
    if(p->val == q->val) {
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    return false;
}
```

## 50

二叉搜索树（BST）中的两个节点被错误地交换了，请在不改变树的结构的情况下恢复这棵树。

输入: [1,3,null,null,2]

  1
 /
 3
 \
  2

输出: [3,1,null,null,2]

  3
 /
 1
 \
  2

#### 思路



```c++

```



## 51



#### 思路



```c++

```



## 52



#### 思路



```c++

```



## 53



#### 思路



```c++

```



## 54



#### 思路



```c++

```



## 55



#### 思路



```c++

```



## 56



#### 思路



```c++

```



## 57



#### 思路



```c++

```



## 58



#### 思路



```c++

```



## 59



#### 思路



```c++

```



## 60



#### 思路



```c++

```

## 61

给出两个有序的整数数组 和 ，请将数组 合并到数组 中，变成一个有序的数组注意：
可以假设 数组有足够的空间存放 数组的元素， 和 中初始的元素数目分别为 和 

#### 思路

1. 由两个数据从后往前比较，不用开辟额外空间
2. 方法与“we are happy" 替换为 ”we%10are%10happy"字符串替换题类似，都是从后往前计算

```c++
void merge(int A[], int m, int B[], int n) {
    while(m > 0 && n > 0) {
        if(A[m-1] > B[n-1]) {
            A[m+n-1] = A[m-1];
            m--;
        } else {
            A[m+n-1] = B[n-1];
            n--;
        }
    }
    while(n > 0) {
        A[n - 1] = B[n - 1];
        n--;
    }
    return ;
}
```



## 62



#### 思路



```c++

```



## 63

划分链表 

给出一个链表和一个值 ，以 为参照将链表划分成两部分，使所有小于 的节点都位于大于或等于 的节点之前。
两个部分之内的节点之间要保持的原始相对顺序。
例如：
给出 1\to 4 \to 3 \to 2 \to 5 \to 21→4→3→2→5→2 和 \ x = 3 x=3,
返回 1\to 2 \to 2 \to 4 \to 3 \to 51→2→2→4→3→5.

#### 思路

1. 构建两个链表头结点，分别存放大于X的数，和小于x的数。最后再将两者进行连接即可

```C++
ListNode* partition(ListNode* head, int x) {
    // write code here
    if(!head)
    return head;
    ListNode *h1 = new ListNode(0);
    ListNode *h2 = new ListNode(0);
    ListNode *p = head, *p1 = h1, *p2 = h2;
    while(p) {
    ListNode *next = p->next;
    if(p->val < x) {
    p1->next = p;
    p1 = p1->next;
    p1->next = nullptr;
    } else {
    p2->next = p;
    p2 = p2->next;
    p2->next = nullptr;
    }
    p = next;
    }
    p1->next = h2->next;
    return h1->next;
}
```

## 64



#### 思路



```c++

```



## 65

给出n个数字，代表直方图的条高，直方图每一条的宽度为1，请计算直方图中最大矩形的面积

![image-20200811103842814](medium/image-20200811103842814.png)

#### 思路



```c++

```



## 66

给出一个升序排序的链表，删除链表中的所有重复出现的元素，只保留原链表中只出现一次的元素。
例如：
给出的链表为1 \to 2\to 3\to 3\to 4\to 4\to51→2→3→3→4→4→5, 返回1\to 2\to51→2→5.
给出的链表为1\to1 \to 1\to 2 \to 31→1→1→2→3, 返回2\to 32→3.

#### 思路

1. 构造一个新的头节点，利前驱，当前，下一节点进行操作即可

```c++
ListNode* deleteDuplicates(ListNode* head) {
    // write code here
    if(head == nullptr)
        return nullptr;
    ListNode *nhead = new ListNode(0);
    nhead->next = head;
    ListNode *p = nhead;
    while(p && p->next && p->next->next) {
        ListNode *s = p, *m = s->next, *e = m->next;
        if(m->val == e->val) {
            while(e && m->val == e->val) {
                m = m->next;
                e = e->next;    
            }
            p->next = e;
        } else {
            p = p->next;
        }
    }
    return nhead->next;
}
```

## 67



#### 思路



```c++

```



## 68



#### 思路



```c++

```



## 69



#### 思路



```c++

```



## 70



#### 思路

```c++

```



## 71



#### 思路



```c++

```



## 72



#### 思路



```c++

```



## 73



#### 思路



```c++

```



## 74



#### 思路



```c++

```



## 75



#### 思路



```c++

```



## 76



#### 思路



```c++

```



## 77



#### 思路



```c++

```



## 78



#### 思路



```c++

```



## 79



#### 思路



```c++

```



## 80

实现函数 int sqrt(int x). 计算并返回x的平方根

#### 思路

1. 使用二分法不断的进行查找，注意此题mid 应为 x / mid， 不能乘法否则会溢出

```c++
int sqrt(int x) {
    if(x == 0)
        return 0;
    int left = 1, right = x;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(mid == x / mid)
            return mid;
        else {
            if(mid < x / mid) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return right;
}
```



## 81

给定一个单词数组和长度L，将该单词数组中文本两端对齐(左边和右边)，使每一行都有L个字符。
你要在每一行中尽可能多地填充单词。在必要时填充额外的空格' '，使每行正好有L个字符。
单词之间的额外空格要尽可能均匀地分布。如果一行的空格数不能在单词之间平均分配，请在左边分配更多的空格
对于最后一行文本，它应该左对齐，并且单词之间不插入额外的空格。

例如,

单词数组为:["This", "is", "an", "example", "of", "text", "justification."]

L:16.

返回

[
   "This    is    an",
   "example  of text",
   "justification.  "
]

#### 思路



```c++

```



## 82



#### 思路



```c++

```



## 83



#### 思路



```c++

```



## 84



#### 思路



```c++

```



## 85



#### 思路



```c++

```



## 86



#### 思路



```c++

```



## 87



#### 思路



```c++

```



## 88



#### 思路



```c++

```



## 89



#### 思路



```c++

```



## 90



#### 思路



## 91



#### 思路



```c++

```



## 92



#### 思路



```c++

```



## 93



#### 思路



```c++

```



## 94



#### 思路



```c++

```



## 95



#### 思路



```c++

```



## 96



#### 思路



```c++

```



## 97



#### 思路



```c++

```



## 98



#### 思路



```c++

```



## 99



#### 思路



```c++

```



## 100

请实现函数 pow(x, n).

Implement pow(x, n).

#### 思路

 题目当然不会是一个简单的循环就能AC的，
* 首先要注意符号的问题，负数n次幂要取倒数，
* 其次是时间复杂度的问题，可通过设置一个中间变量tmp记录平方值，来折半计算，将O(n)降为O(logn)
* 当指数为偶数时，直接 tmp *= tmp 即可，当指数为奇数时，除了tmp *= tmp 外， 结果还要乘上自己一次

```c++
double pow(double x, double n) {
    double res = 1.0;
    double tmp = x;
    for(int i = (int)abs(n); i > 0; i /= 2) {
        if(i % 2 != 0)
            res *= tmp;
        tmp *= tmp;
    }
    return (n > 0 ? res : 1/res);
}
```



## 101

给出一个字符串数组，返回所有互为“换位词（anagrams）”的字符串的组合。（换位词就是包含相同字母，但字母顺序可能不同的字符串）备注：所有的输入都是小写字母

例如：

输入["tea","nat","ate","eat","tan"]

返回`[["ate", "eat","tea"],["nat","tan"]]`

#### 思路

1. 关键点是对数组每个元素即字符串进行排序，这样换位词始终为一个词

```c++

```

## 102



#### 思路



```c++

```

## 103



#### 思路



```c++

```



## 104



#### 思路



```c++

```



## 105



#### 思路



```c++

```



## 106



#### 思路



```c++

```



## 107



#### 思路



```c++

```



## 108



#### 思路



```c++

```



## 109



#### 思路



```c++

```



## 110



#### 思路



```c++

```



## 111



#### 思路



```c++

```

## 112



#### 思路



```c++

```

## 113



#### 思路



```c++

```



## 114



#### 思路



```c++

```



## 115



#### 思路



```c++

```



## 116



#### 思路



```c++

```



## 117



#### 思路



```c++

```



## 118



#### 思路



```c++

```



## 119



#### 思路



```c++

```



## 120



#### 思路



```c++

```

## 121



#### 思路



```c++

```

## 122



#### 思路



```c++

```

## 123



#### 思路



```c++

```



## 124



#### 思路



```c++

```



## 125



#### 思路



```c++

```



## 126



#### 思路



```c++

```



## 127



#### 思路



```c++

```



## 128



#### 思路



```c++

```



## 129



#### 思路



```c++

```



## 130



#### 思路



```c++

```

## 131



#### 思路



```c++

```

## 132



#### 思路



```c++

```

## 133



#### 思路



```c++

```



## 134



#### 思路



```c++

```



## 135



#### 思路



```c++

```



## 136



#### 思路



```c++

```



## 137



#### 思路



```c++

```



## 138



#### 思路



```c++

```

## 139



#### 思路



```c++

```



## 140



#### 思路



```c++

```





## 141



#### 思路



```c++

```



## 142



#### 思路



```c++

```







## 140



#### 思路



```c++

```





## 143

#### 思路



```c++

```





## 144



#### 思路



```c++

```





## 145



#### 思路



```c++

```





## 146



#### 思路



```c++

```







## 147



#### 思路



```c++

```





## 148

给出一个整数数组，请在数组中找出两个加起来等于目标值的数，

你给出的函数twoSum 需要返回这两个数字的下标（index1，index2），需要满足 index1 小于index2.。注意：下标是从1开始的

假设给出的数组中只存在唯一解

例如：

给出的数组为 {2, 7, 11, 15},目标值为9
输出 index1=1, index2=2

#### 思路

1. 

```c++

```













[#61]: 