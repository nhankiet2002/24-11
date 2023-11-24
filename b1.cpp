#include <iostream>
using namespace std; 
class cong {
private:
    int A;
    int B;

public:
    cong(int a, int b) : A(a), B(b) {}
    int add() const {
        return A + B;
    }
};

int main() {
    int A, B;
    cin >> A;
    cin >> B;
    cong tong(A, B);
    int sum = tong.add();
	cout  << sum << endl;
    return 0;
}


