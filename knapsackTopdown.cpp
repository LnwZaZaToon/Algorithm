#include <iostream>
#include <vector>
#include <cstring> // ����Ѻ memset()

using namespace std;

// Memoization table
int dp[101][10001]; // ��˹���Ҵ����ҡ�� �� n <= 100, k <= 10^4

// �ѧ��ѹ�Ҩӹǹ�Թ����ҡ����ش�������ö����������Թ w
int maxItems(int i, int w, vector<int>& price) {
    // Base case: ������Թ���������͡ �����Թ���
    if (i < 0 || w == 0) return 0;

    // ��Ҥӹǳ��� dp[i][w] �����
    if (dp[i][w] != -1) return dp[i][w];

    // �������Թ��Ҫ�鹷�� i
    int notTake = maxItems(i - 1, w, price);

    // �����Թ��Ҫ�鹷�� i ����Թ��
    int take = 0;
    if (w >= price[i]) {
        take = maxItems(i - 1, w - price[i], price) + 1;
    }

    // �纤��ŧ memo table ��Ф׹��ҷ���ҡ����ش
    return dp[i][w] = max(notTake, take);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> price(n);
    
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }

    // ����� memo table �¡�˹������������� -1
    memset(dp, -1, sizeof(dp));

    // �ӹǳ�ӹǹ�Թ��ҷ���ҡ����ش
    cout << maxItems(n - 1, k, price) << endl;

    return 0;
}

