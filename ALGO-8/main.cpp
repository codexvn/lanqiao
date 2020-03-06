#include <iostream>

#define max(a, b) a > b ? a : b;
using namespace std;
struct node {
    int l; //��Χ��ʼ
    int r;//��Χ����
    int maxvalue;//���ֵ
    int sum;//�ܺ�
} a[1000000];

void init(int left, int right, int i) {  //��ʼ���߶���
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

void insert(int i, int j, int value) { //��������
    if (a[i].l == a[i].r) { //�����������Ҷ�ӽڵ�ʹ洢���ݣ���ʱa[i].l==a[i].r==j
        a[i].maxvalue = value;
        a[i].sum = value;
        return;
    }
    int mid = (a[i].l + a[i].r) / 2;
    if (j <= mid)  //����ĵ����������ķ�Χ�����������ķ�Χ
        insert(2 * i, j, value);   //j�ǲ���ģ����ڱ������ĵڼ���Ԫ��
    else
        insert(2 * i + 1, j, value);
    a[i].maxvalue = max(a[2 * i].maxvalue, a[2 * i + 1].maxvalue);    //ֱ���ڽڵ㴦����ڵ����Χ��������
    a[i].sum = a[2 * i].sum + a[2 * i + 1].sum;     //���淶Χ�������ܺ�
    //�����ڵ�i��1��ʼʱ������������ȫ2�����е��±�Ϊ2*i,������Ϊ2*i+1
    //�����ڵ�i��0��ʼʱ������������ȫ2�����е��±�Ϊ2*i+1,������Ϊ2*i+2
}

int find_sum(int i, int x, int y) { //i:��ǰ�ڵ��±�   x,y:��Χ  x-y
    //static int count = 0;
    //count++;
    //cout << a[i].l << " " << a[i].r << " " << x << " " << y << " " << count << endl;
    if (x == a[i].l && y == a[i].r)   //���������Ҷ�ӽڵ������ֱ�ӷ�������ڵ��ֵ����Ϊ��ʱ
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