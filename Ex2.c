#include <stdio.h>
int compare_arrays(int arr1[], int arr2[], int size){
	int i = 0;
	for(i = 0; i < size; ++i){
		if (arr1[i] != arr2[i])
			return 0;
		}
	return 1;}
int main(){
	int n, i;
	int x[n];
	int y[n];
	printf("\nDo dai cua 2 mang so nguyen la: ");
	scanf("%d",&n);
	int S[n];
	for (i=0;i<n;i++){
		printf("\nSo thu %d cua mang 1: ", i+1);
		scanf("%d",&x[i]);
	}
	for (i=0;i<n;i++){
		printf("\nSo thu %d cua mang 2: ", i+1);
		scanf("%d",&y[i]);
	}
	if (compare_arrays(x, y, n)){
		printf("YES");
	}
	else{
		printf("NO");
	}
}
