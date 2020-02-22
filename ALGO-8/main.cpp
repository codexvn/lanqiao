#include <iostream>

#define max(a, b) a > b ? a : b;
using namespace std;
struct node {
    int l; //范围开始
    int r;//范围结束
    int maxvalue;//最大值
    int sum;//总和
} a[1000000];

void init(int left, int right, int i) {  //初始化线段树
    a[i].l = left;
    a[i].r = right;
    a[i].maxvalue = 0;
    a[i].sum = 0;
    if (left != right) {
        int mid = (left + right) / 2;
        init(left, mid, 2 * i);
        init(mid + 1, right, 2 * i + 1);
    }
}

void insert(int i, int j, int value) { //插入数据
    if (a[i].l == a[i].r) { //如果遍历到了叶子节点就存储数据，此时a[i].l==a[i].r==j
        a[i].maxvalue = value;
        a[i].sum = value;
        return;
    }
    int mid = (a[i].l + a[i].r) / 2;
    if (j <= mid)  //插入的点在左子树的范围还是右子树的范围
        insert(2 * i, j, value);   //j是不变的，用于保存插入的第几个元素
    else
        insert(2 * i + 1, j, value);
    a[i].maxvalue = max(a[2 * i].maxvalue, a[2 * i + 1].maxvalue);    //直接在节点处保存节点代表范围内最大的数
    a[i].sum = a[2 * i].sum + a[2 * i + 1].sum;     //保存范围内数的总和
    //当根节点i从1开始时，左子树在完全2叉树中的下标为2*i,右子树为2*i+1
    //当根节点i从0开始时，左子树在完全2叉树中的下标为2*i+1,右子树为2*i+2
}

int find_sum(int i, int x, int y) { //i:当前节点下标   x,y:范围  x-y
    //static int count = 0;
    //count++;
    //cout << a[i].l << " " << a[i].r << " " << x << " " << y << " " << count << endl;
    if (x == a[i].l && y == a[i].r)   //假如遍历到叶子节点则可以直接返回这个节点的值，因为此时
        return a[i].sum;
    else if (a[i].l > y or a[i].r < x)
        return 0;
    else if (x <= a[i].l and y >= a[i].r)
        return a[i].sum;
    int mid = (a[i].l + a[i].r) / 2, sum = 0;
    if (mid >= x)
        sum += find_sum(2 * i, x, y);
    if (mid + 1 <= y)
        sum += find_sum(2 * i + 1, x, y);
    return sum;
}

int find_max(int i, int x, int y) {
   // static int count = 0;
   // count++;
  //  cout << a[i].l << " " << a[i].r << " " << x << " " << y << " " << count << endl;
    if (x == a[i].l && y == a[i].r) {
        return a[i].maxvalue;
    } else if (a[i].l > y or a[i].r < x)
        return 0;
    else if (x <= a[i].l and y >= a[i].r)
        return a[i].maxvalue;
    int mid = (a[i].l + a[i].r) / 2, max = 0;
    if (mid >= x){
        int max_L=find_max(2 * i , x, y);
        max=max<max_L?max_L:max;
    }
    if (mid + 1 <= y){
        int max_R=find_max(2 * i+1 , x, y);
        max=max<max_R?max_R:max;
    }
    return max;
}

int main() {
    int n, m;
    cin >> n >> m;
    init(1, n, 1);
    int value;
    for (int j = 1; j <= n; j++) {
        cin >> value;
        insert(1, j, value);
    }
    for (int k = 0; k < m; k++) {
        int p, x, y;
        cin >> p >> x >> y;
        if (p == 1)
            insert(1, x, y);
        if (p == 2)
            cout << find_sum(1, x, y) << endl;
        if (p == 3)
            cout << find_max(1, x, y) << endl;
    }
    return 0;
}