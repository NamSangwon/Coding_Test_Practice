#include <iostream>

using namespace std;

int main(){
    // float X & double O
    // float 자료형은 double과 비교했을 때 매우 부정확해서, 소숫점이 7자리수 가량만 되도 오차가 나기 시작. 
    // 특별한 상황이 아니면 알고리즘 문제해결에서 사용하지 않을 것을 권합니다.
    double a = 0, b = 0;

    cin >> a >> b;

    // 10^-9 이하의 오차를 허용
    cout.precision(12);
    cout << fixed;

    cout << a / b << endl;
}