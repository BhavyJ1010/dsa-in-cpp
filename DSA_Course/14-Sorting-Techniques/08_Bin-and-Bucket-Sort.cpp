
#include <iostream>
#include <vector>
using namespace std;

// Bin Sort for non-negative integers within a known range.
void BinSort(int A[], int n, int max){

    int *bin = new int[max+1];

    for(int i=0; i<=max; i++){
        bin[i] = 0;
    }

    // Place each element into its corresponding bin.
    for(int i=0; i<n; i++){
        bin[A[i]]++;
    }

    // Collect elements in sorted order.
    int j = 0;

    for(int i=0; i<=max; i++){
        while(bin[i] > 0){
            A[j++] = i;
            bin[i]--;
        }
    }

    delete[] bin;
}

// Insertion Sort for sorting individual buckets.
void InsertionSort(vector<float>& bucket){

    for(int i=1; i<bucket.size(); i++){

        float x = bucket[i];
        int j = i-1;

        while(j>=0 && bucket[j]>x){
            bucket[j+1] = bucket[j];
            j--;
        }

        bucket[j+1] = x;
    }
}

// Bucket Sort for values in the range [0, 1).
void BucketSort(float A[], int n){

    vector<float> *bucket = new vector<float>[n];

    // Distribute elements into buckets.
    for(int i=0; i<n; i++){

        int index = n*A[i];

        bucket[index].push_back(A[i]);
    }

    // Sort individual buckets.
    for(int i=0; i<n; i++){
        InsertionSort(bucket[i]);
    }

    // Combine all buckets.
    int j = 0;

    for(int i=0; i<n; i++){
        for(int k=0; k<bucket[i].size(); k++){
            A[j++] = bucket[i][k];
        }
    }

    delete[] bucket;
}

int main(){

    int A[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(A)/sizeof(A[0]);

    cout << "Bin Sort: ";

    BinSort(A, n, 8);

    for(int i=0; i<n; i++){
        cout << A[i] << " ";
    }

    cout << endl;


    float B[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    int m = sizeof(B)/sizeof(B[0]);

    cout << "Bucket Sort: ";

    BucketSort(B, m);

    for(int i=0; i<m; i++){
        cout << B[i] << " ";
    }

    cout << endl;

    return 0;
}
