#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// To perform AND query
int and_query(int i, int j) {
    cout << "and " << i << " " << j << endl;
    fflush(stdout);
    int result;
    cin >> result;
    return result;
}

// To perform OR query
int or_query(int i, int j) {
    cout << "or " << i << " " << j << endl;
    fflush(stdout);
    int result;
    cin >> result;
    return result;
}

int main()
{
    int n,k;
    cin>>n>>k;
    // Ask initial AND and OR queries between first three elements
    int AND_12 = and_query(1, 2);
    int OR_12  = or_query(1, 2);
    int AND_13 = and_query(1, 3);
    int OR_13  = or_query(1, 3);
    int AND_23 = and_query(2, 3);
    int OR_23  = or_query(2, 3);

    // Calculate the sums
    /*Property:a+b=(a&b)+(a|b)
    proof: 
    i) 0&0 + 0|0 = 0+0=0
    ii) 1&1 + 1|1=1+1=2
    iii) 1&0 + 1|0=0+1=1
    Therefore the property holds true for 0 and 1
    Now consider 2 numbers in decimal format(not necessarily 0 or 1) which are expressed as powers of 2
        a=2^m(Am)+2^m-1(Am-1)..(Ao),
        b=2^m(Bm)+2^m-1(Bm-1)..(Bo)
        where Ai and Bi E {0,1} for all i E [0,m]
        a&b + a|b = 2^m(Am&Bm + Am|Bm)+2^m-1(Am-1&Bm-1 + Am-1|Bm-1)..(Ao&Bo + Ao|Bo)
        By our calculation performed above, Ai&Bi + Ai|Bi=Ai+Bi
        Hence (a&b)+(a|b)=a+b
    */
    int SUM_12 = AND_12 + OR_12;
    int SUM_13 = AND_13 + OR_13;
    int SUM_23 = AND_23 + OR_23;
    /*
    Now we get 3 linear eqn to solve for a1,a2,a3
    i)sum12=a1+a2
    ii)sum23=a1+a3
    iii)sum13=a2+a3 
    sum12+sum23+sum31=2(a1+a2+a3)
    **(sum12+sum23+sum31)/2 - (a2+a3)=a1**
    */ 
    int a1 = (SUM_12 + SUM_13 - SUM_23) / 2; 
    // solve for the rest
    int a2 = SUM_12 - a1;
    int a3 = SUM_13 - a1;

    // now we are building the unknown array
    vector<int> arr(n);
    arr[0] = a1;
    arr[1] = a2;
    arr[2] = a3;

     // Determine the rest of the array by asking questions
    for (int i = 4; i <= n; ++i) {
        // we can use any of the known a1,a2,a3. I am using a1 here
        int AND_i1 = and_query(1, i);
        int OR_i1  = or_query(1, i);
        // a1 is known, so we can calculate the unknown element from the sum !
        arr[i-1] = (AND_i1 + OR_i1) - a1;
    }
    // maxm of 2*n questions were asked i.e. one & and | for each element of the array
    // Sort the array to find the k-th smallest element()
    sort(arr.begin(), arr.end());

    // Output the k-th smallest element
    cout << "finish " << arr[k-1] << endl;
    fflush(stdout);
    return 0;
}