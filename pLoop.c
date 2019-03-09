1. #include <stdio.h> // printf()
2. #include <stdlib.h> // atoi()
3. #include <omp.h> // OpenMP
4. int main(int argc, char** argv) {
5. const int REPS = 16;
6. printf("\n");
7. if (argc > 1) {
8. omp_set_num_threads( atoi(argv[1]) );
9. }
10. #pragma omp parallel for
11. for (int i = 0; i < REPS; i++) {
12. int id = omp_get_thread_num();
13. printf("Thread %d performed iteration %d\n", id, i);
14. }
15. printf("\n");
16. return 0;
17. }
