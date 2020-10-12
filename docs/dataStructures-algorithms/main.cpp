// 牛客网 —— 名企高频面试题题解

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    explicit ListNode(int val) : val(val), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

/*
 * NC1
 */
string solve(string s, string t) {
    // write code here
    int len = max(s.size(), t.size());
}

/*
 * NC2
 */

/*
 * NC3
 */
ListNode *detectCycle(ListNode *head) {
    if(!head)
        return nullptr;
    map<ListNode *, int> mp;
    ListNode *p = head;
    while(p) {
        auto itor = mp.find(p);
        if(itor == mp.end()) {
            mp.insert(make_pair(p, 1));
        } else {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}
/*
 * NC4
 * map寻找是否存在重复
 */
bool hasCycle(ListNode *head) {
    if(head == nullptr)
        return false;
    map<ListNode *, int> mp;
    ListNode *p = head;
    while(p) {
        auto itor = mp.find(p);
        if(itor == mp.end())
            mp.insert(make_pair(p, 1));
        else
            return true;
        p = p->next;
    }
    return false;
}


void orders(TreeNode *root, vector<vector<int>> &v) {
    if(root) {
        v[0].push_back(root->val);
        if(root->left)
            orders(root->left, v);
        v[1].push_back(root->val);
        if(root->right)
            orders(root->right, v);
        v[2].push_back(root->val);
    }
}

/*
 * NC5
 */

/*
 * NC6
 */

/*
 * NC7
 */


/*
 * NC19
 * 简单一维动态规划
 */
int maxsumofSubarray(vector<int>& arr) {
    // write code here
    if(arr.size() == 0)
        return 0;
    vector<int> dp(arr.size());
    dp[0] = arr[0];
    int max = 1 << 31;
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] > dp[i-1] + arr[i]) {
            dp[i] = arr[i];
        } else {
            dp[i] = dp[i-1] + arr[i];
        }
        max = dp[i] > max ? dp[i] : max;
    }
    return max;
}

/*
 * NC20
 */

/*
 * NC21
 */

/*
 * NC22
 * 从后往前算法
 */
void merge(int A[], int m, int B[], int n) {
    while(m > 0 && n > 0) {
        if (A[m - 1] > B[n - 1]) {
            A[m + n - 1] = A[m - 1];
            m--;
        } else {
            A[m + n - 1] = B[n - 1];
            n--;
        }
    }
    while(n > 0) {
        A[m+n-1] = B[n-1];
        n--;
    }
}

/*
 * NC24
 */

/*
 * NC25
 */

/*
 * NC26
 */

/*
 * NC27
 */

/*
 * NC28
 */

/*
 * NC29
 */

/*
 * NC30
 */
int minNumberdisappered(vector<int>& arr) {
    // write code here
    if(arr.empty())
        return 1;
    int sz = arr.size();
    vector<int> res(sz);
    for(int i = 0; i < sz; i++) {
        if(arr[i] > 0 && arr[i] < sz){
            res[arr[i] - 1] = arr[i];
        }
    }
    for(int i = 0; i < sz; i++) {
        if(res[i] != i + 1)
            return i + 1;
    }
    return sz + 1;
}

/*
 * NC33
 */
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // write code here

}

/*
 * NC45
 * 递归解法
 */
vector<vector<int> > threeOrders(TreeNode* root) {
    // write code here
    vector<vector<int>> res;
    vector<int> pre_res, mid_res, next_res;
    res.push_back(pre_res);
    res.push_back(mid_res);
    res.push_back(next_res);
    orders(root, res);
    return res;
}

/*
 * NC53
 * 快慢指针
 */
ListNode* removeNthFromEnd(ListNode* head, int n) {
    // write code here
    if(!head)
        return nullptr;
    ListNode *nhead = new ListNode(0);
    nhead->next = head;
    ListNode *slow = head, *fast = head, *pre = nhead;
    while(n-- > 0)
        fast = fast->next;
    while(fast) {
        fast = fast->next;
        slow = slow->next;
        pre = pre->next;
    }
    pre->next = slow->next;
    return nhead->next;
}

/*
 * NC78
 */
ListNode* ReverseList(ListNode* pHead) {
    if(pHead == nullptr)
        return nullptr;
    ListNode *nhead = new ListNode(0);
    nhead->next = pHead;
    ListNode *left = nhead, *right = pHead, *curr = pHead->next;
    right->next = nullptr;
    while(curr) {
        ListNode *next = curr->next;
        left->next = curr;
        curr->next = right;
        right = curr;

        curr = next;
    }
    return nhead->next;
}

/*
 * NC91
 */
vector<int> LIS(vector<int>& arr) {
    // write code here

}


void set(int k, int key, int value, vector<int> &lru_v, map<int, int> &lru_mp) {
    auto itor = lru_mp.find(key);
    if(itor == lru_mp.end()) {
        if(lru_v.size() >= k) {
            int key = lru_v[0];
            lru_v.erase(lru_v.begin());
            lru_mp.erase(key);
        }
        lru_v.push_back(key);
        lru_mp.insert(make_pair(key, value));
    } else {
        itor->second = value;
        int idx = 0;
        for(; idx < lru_v.size(); idx++) {
            if(key == lru_v[idx])
                break;
        }
        lru_v.erase(lru_v.begin() + idx);
        lru_v.push_back(key);
    }
}

int get(int key, vector<int> &lru_v, map<int, int> &lru_mp) {
    auto itor = lru_mp.find(key);
    if(itor != lru_mp.end()) {
        int res = itor->second;
        int idx = 0;
        for(; idx < lru_v.size(); idx++) {
            if(key == lru_v[idx])
                break;
        }
        lru_v.erase(lru_v.begin() + idx);
        lru_v.push_back(key);
        return res;
    }
    else
        return -1;
}
/*
 * NC93
 */
vector<int> LRU(vector<vector<int> >& operators, int k) {
    // write code here
    vector<int> lru_v, res;
    map<int, int> lru_mp;
    for(int i = 0; i < operators.size(); i++) {
        int opt = operators[i][0], key = operators[i][1];
        if(opt == 1) {
            set(k, key, operators[i][2], lru_v, lru_mp);
        } else {
            res.push_back(get(key, lru_v, lru_mp));
        }
    }
    return res;
}


/*
 * NC100
 */
int atoi(const char *str) {

}

// NC103
string solve(string str) {
    // write code here
    if(str.empty())
        return nullptr;
    string s = "";
    for(int i = str.size() - 1; i >= 0; i--) {
        s.push_back(str[i]);
    }
    return s;
}

// NC105
int upper_bound_(int n, int v, vector<int>& a) {
    // write code here
    if(a.size() == 0)
        return 1;
    int start = 0, end = n - 1;
    while(start < end) {
        int mid = (start + end) / 2;
        if(a[mid] < v) {
            start = mid + 1;
        } else if(a[mid] > v){
            end = mid - 1;
        } else {
            while(a[mid] == v) {
                mid--;
            }
            return mid + 2;
        }
    }
    return n;
}

int main() {
    vector<int> v = {1, -2, 3, 5, -2, 6, -1};
    cout << maxsumofSubarray(v);
    return 0;
}