//reduction.c
1. #include <stdio.h> // printf()
2. #include <omp.h> // OpenMP
3. #include <stdlib.h> // rand()
4. void initialize(int* a, int n);
5. int sequentialSum(int* a, int n);
6. int parallelSum(int* a, int n);
7. #define SIZE 1000000
8. int main(int argc, char** argv) {
9. int array[SIZE];
10. if (argc > 1) {
11. omp_set_num_threads( atoi(argv[1]) );
12. }
13. initialize(array, SIZE);
14. printf("\nSequential sum: \t%d\nParallel sum: \t%d\n\n",
15. sequentialSum(array, SIZE),
16. parallelSum(array, SIZE) );
17. return 0;
18. }
19. /* fill array with random values */
20. void initialize(int* a, int n) {
21. int i;
22. for (i = 0; i < n; i++) {
23. a[i] = rand() % 1000;
24. }
25. }
26. /* sum the array sequentially */
27. int sequentialSum(int* a, int n) {
28. int sum = 0;
29. int i;
30. for (i = 0; i < n; i++) {
31. sum += a[i];
32. }
33. return sum;
34. }
35. /* sum the array using multiple threads */
36. int parallelSum(int* a, int n) {
37. int sum = 0;
38. int i;
39. // #pragma omp parallel for // reduction(+:sum)
40. for (i = 0; i < n; i++) {
41. sum += a[i];
42. }
43. return sum;
44. }
