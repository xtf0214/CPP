    #include <bits/stdc++.h>
    using namespace std;
    const double eps = 1e-10;

    double a[101][101], b[101];

    // inline void gauss() { 
    //     int l = 1;
    //     for (int i = 1; i <= 3; i++) {
    //         for (int j = l + 1; j <= 2; j++)
    //             if (a[j][i] > a[l][i]) {
    //                 for (int k = i; k <= 3; k++)
    //                     swap(a[j][k], a[l][k]);
    //                 swap(b[j], b[l]);
    //             }
    //         if (a[l][i] < eps)
    //             continue;
    //         for (int j = 1; j <= 2; j++) {
    //             if (l == j || a[j][i] < eps)
    //                 continue;
    //             double dalte = a[j][i] / a[l][i];
    //             for (int k = i; k <= 3; k++)
    //                 a[j][k] -= a[l][k] * dalte;
    //             b[j] -= b[l] * dalte;
    //         }
    //     }
    //     for (int i = 1; i <= 3; i++)
    //         printf("%.2lf ", a[2][i]);
    //     printf(" b : %.2lf\n", b[2]);
    //     int ok = 1;
    //     for (int i = l; i <= 2; i++)
    //         if (b[i] > eps)
    //             ok = 0;
        
    //     if (ok)
    //         printf("Yes\n");
    //     else
    //         printf("No\n");
    // }

    int main() {
        // int n;
        // while (cin >> n) {
            cin >> b[1] >> b[2];
            for (int j = 1; j <= 2; j++)
                for (int i = 1; i <= 3; i++)
                    cin >> a[j][i];
            // gauss();
        // }
                return 0; 
    }