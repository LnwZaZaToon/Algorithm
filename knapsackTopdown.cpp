#include <iostream>
#include <vector>
#include <cstring> // สำหรับ memset()

using namespace std;

// Memoization table
int dp[101][10001]; // กำหนดขนาดให้มากพอ เช่น n <= 100, k <= 10^4

// ฟังก์ชันหาจำนวนสินค้ามากที่สุดที่สามารถซื้อได้ด้วยเงิน w
int maxItems(int i, int w, vector<int>& price) {
    // Base case: ไม่มีสินค้าให้เลือก หรือเงินหมด
    if (i < 0 || w == 0) return 0;

    // ถ้าคำนวณค่า dp[i][w] ไปแล้ว
    if (dp[i][w] != -1) return dp[i][w];

    // ไม่ซื้อสินค้าชิ้นที่ i
    int notTake = maxItems(i - 1, w, price);

    // ซื้อสินค้าชิ้นที่ i ถ้าเงินพอ
    int take = 0;
    if (w >= price[i]) {
        take = maxItems(i - 1, w - price[i], price) + 1;
    }

    // เก็บค่าลง memo table และคืนค่าที่มากที่สุด
    return dp[i][w] = max(notTake, take);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> price(n);
    
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }

    // เตรียม memo table โดยกำหนดค่าเริ่มต้นเป็น -1
    memset(dp, -1, sizeof(dp));

    // คำนวณจำนวนสินค้าที่มากที่สุด
    cout << maxItems(n - 1, k, price) << endl;

    return 0;
}

