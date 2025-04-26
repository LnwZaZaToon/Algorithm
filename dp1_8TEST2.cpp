#include <iostream>
#include <vector>
#include <cstring> // ����Ѻ memset
using namespace std;

int n, k;
vector<int> prices;
vector<vector<int>> dp;

int solve(int i, int remaining_k) {
    // ���͹���ش recursive
    if (remaining_k == 0) return 0; // �Թ���
    if (i >= n) return 0; // ����Թ���

    // ��Ҽ��Ѿ��١�ӹǳ�������㹵��ҧ dp
    if (dp[i][remaining_k] != -1) return dp[i][remaining_k];

    int max_items = 0;

    // ǹ�ٻ���;Ԩ�ó��Թ��ҷ���������� i �֧ n-1
    for (int j = i; j < n; j++) {
        if (prices[j] <= remaining_k) {
            // �����Թ��� j ��������ӹǹ�Թ���
            int take = 1 + solve(j + 1, remaining_k - prices[j]);
            // �ѻവ����٧�ش
            max_items = max(max_items, take);
        }
    }

    // �纼��Ѿ��㹵��ҧ dp
    return dp[i][remaining_k] = max_items;
}

int main() {
    // �Ѻ�����Ź����
    cin >> n >> k;
    prices.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    // ������鹵��ҧ dp ���� -1 (�ѧ���ӹǳ)
    dp.assign(n, vector<int>(k + 1, -1));

    // ���¡�ѧ��ѹ solve ����ʴ����Ѿ��
    cout << solve(0, k) << endl;
    
    	for(int i = 0 ; i< dp.size() ; i++){
			for(int j = 0 ; j < dp[i].size() ; j++){
			cout<< dp[i][j] <<" ";
		}
		cout<<endl;
	}

    return 0;
}
