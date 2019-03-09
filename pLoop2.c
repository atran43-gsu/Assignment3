#include <stdio.h>
2. #include <omp.h>
3. #include <stdlib.h>
4. int main(int argc, char** argv) {
5. const int REPS = 16;
6. printf("\n");
7. if (argc > 1) {
8. omp_set_num_threads( atoi(argv[1]) );
9. }
10. #pragma omp parallel for schedule(static,1)
11. for (int i = 0; i < REPS; i++) {
12. int id = omp_get_thread_num();
13. printf("Thread %d performed iteration %d\n", id, i);
14. }
15. /*
16. printf("\n---\n\n");
17. #pragma omp parallel
18. {
19. int id = omp_get_thread_num();
20. int numThreads = omp_get_num_threads();
21. for (int i = id; i < REPS; i += numThreads) {
22. printf("Thread %d performed iteration %d\n",
a. id, i);
23. }
24. }
25. */
26. printf("\n");
27. return 0;
28. }
