int LinearSearch (T M[], int N, 
T X){
int k = 0;
while (M[k] != X && k < N)
k++;
if (k < N) return (k);
return (-1);
}
