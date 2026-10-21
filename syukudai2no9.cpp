 #include <iostream>
#include <string>

class SmartPhone {
private:
    // メンバ変数（属性）
    std::string modelName; // 機種名
    int batteryLevel;      // バッテリー残量 (%)

public:
    // 引数付きコンストラクタ
    SmartPhone(std::string model, int battery) {
        modelName = model;
        if (battery > 100) batteryLevel = 100;
        else if (battery < 0) batteryLevel = 0;
        else batteryLevel = battery;
    }

    // メンバ関数1：アプリを使う（バッテリーを消費する）
    void useApp(std::string appName) {
        if (batteryLevel <= 0) {
            std::cout << "画面がつきません。充電してください。\n";
            return;
        }
        batteryLevel -= 10;
        if (batteryLevel < 0) batteryLevel = 0;

        std::cout << modelName << "で「" << appName << "」を開きました。";
        std::cout << "（残量: " << batteryLevel << "%）\n";
    }

    // メンバ関数2：充電する（バッテリーを回復する）【追加】
    void charge(int amount) {
        batteryLevel += amount;
        if (batteryLevel > 100) batteryLevel = 100; // 100%を超えないようにする

        std::cout << modelName << "を " << amount << "% 充電しました。";
        std::cout << "（残量: " << batteryLevel << "%）\n";
    }

    // メンバ関数3：状態を表示する
    void showStatus() {
        std::cout << "\n--- スマホの状態 ---\n";
        std::cout << "機種名: " << modelName << "\n";
        std::cout << "バッテリー残量: " << batteryLevel << "%\n";
        std::cout << "--------------------\n\n";
    }
};

int main() {
    // 引数付きコンストラクタでインスタンス生成
    SmartPhone myPhone("MyPhone 15 Pro", 20);

    myPhone.showStatus();  // 最初は 20%
    myPhone.useApp("YouTube"); // 使用して 10% に減少

    myPhone.charge(50);    // 50% 充電して 60% に回復
    myPhone.showStatus();  // 現在の状態を表示

    return 0;
}