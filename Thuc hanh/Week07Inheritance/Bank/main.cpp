#include"Bank.h"

int main() {
    auto accounts = getAllAccountsV2();

    for (auto& account : accounts) {
        std::cout << account.name() << " can withdraw " << account.withdraw(70000) << std::endl;
    }
    return 0;
}