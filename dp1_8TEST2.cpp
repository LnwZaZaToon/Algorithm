#include <iostream>
#include <vector>
#include <cstring> // สำหรับ memset
using namespace std;

int n, k;
vector<int> prices;
vector<vector<int>> dp;

int solve(int i, int remaining_k) {
    // เงื่อนไขหยุด recursive
    if (remaining_k == 0) return 0; // เงินหมด
    if (i >= n) return 0; // หมดสินค้า

    // ถ้าผลลัพธ์ถูกคำนวณไว้แล้วในตาราง dp
    if (dp[i][remaining_k] != -1) return dp[i][remaining_k];

    int max_items = 0;

    // วนลูปเพื่อพิจารณาสินค้าทั้งหมดตั้งแต่ i ถึง n-1
    for (int j = i; j < n; j++) {
        if (prices[j] <= remaining_k) {
            // ซื้อสินค้า j และเพิ่มจำนวนสินค้า
            int take = 1 + solve(j + 1, remaining_k - prices[j]);
            // อัปเดตค่าสูงสุด
            max_items = max(max_items, take);
        }
    }

    // เก็บผลลัพธ์ในตาราง dp
    return dp[i][remaining_k] = max_items;
}

int main() {
    // รับข้อมูลนำเข้า
    cin >> n >> k;
    prices.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    // เริ่มต้นตาราง dp ด้วย -1 (ยังไม่คำนวณ)
    dp.assign(n, vector<int>(k + 1, -1));

    // เรียกฟังก์ชัน solve และแสดงผลลัพธ์
    cout << solve(0, k) << endl;
    
    	for(int i = 0 ; i< dp.size() ; i++){
			for(int j = 0 ; j < dp[i].size() ; j++){
			cout<< dp[i][j] <<" ";
		}
		cout<<endl;
	}

    return 0;
}
