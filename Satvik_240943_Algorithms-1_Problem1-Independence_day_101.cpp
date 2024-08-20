#include <iostream>
using namespace std;

int main() {
	int T;
    cin >> T;
    while(T--) {
        int A, B, C;
        cin >> A >> B >> C;
		/* 
		Key observation:
		i)If the most frequent color has more strips than 
		the total of the other two colors combined plus 1, 
		it will be impossible to arrange them without 
		adjacent strips of the same color.
		ii) So we just need to check if the 
		difference between the most frequent 
		color and the sum of the other two colors is at most 1.
		*/

        int max_strip = max({A, B, C});
        int sum_of_others = A + B + C - max_strip;
        if(max_strip <= sum_of_others + 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
