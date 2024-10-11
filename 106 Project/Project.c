#include <stdio.h>
#include <stdlib.h> // for rand() function
#include <time.h> // for clock_t, clock(), CLOCKS_PER_SEC

int adjacency_matrix[5000][5000]; //defining randomly generated directed graph matrix size

int main()
{
    float time = 0.0; // to store the execution time of code

    int n, initial_vertex, terminal_vertex; // here n is for vertex
    scanf("%d", &n); // scanning the value of n
    printf("Vertex = %d\n", n);

    clock_t begin = clock(); // clock tick per second start to count exact run time

    for(initial_vertex = 0; initial_vertex < n; initial_vertex++)
    {
        for(terminal_vertex = 0; terminal_vertex < n; terminal_vertex++)
        {
            adjacency_matrix[initial_vertex][terminal_vertex] = (rand() % 2); //using rand function to fill the matrix randomly where %2 is used to put only 0 and 1
        }
    }

    int total_indegree = 0, total_outdegree = 0;

    for(initial_vertex = 0; initial_vertex < n; initial_vertex++)
    {
        for(terminal_vertex = 0; terminal_vertex < n; terminal_vertex++)
        {
            total_outdegree += adjacency_matrix[initial_vertex][terminal_vertex]; // summation of each row
        }
    }

    for(initial_vertex = 0; initial_vertex < n; initial_vertex++)
    {
        for(terminal_vertex = 0; terminal_vertex < n; terminal_vertex++)
        {
            total_indegree += adjacency_matrix[terminal_vertex][initial_vertex]; // summation of each column
        }
    }

    int flag = 0;

    if(total_indegree == total_outdegree) // checking summation of in-degrees and out-degrees are equal
    {
        flag = 1;
    }

    clock_t end = clock(); // clock tick per second end
    // calculating elapsed time by finding difference (end - begin)
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time += (float)(end - begin) / CLOCKS_PER_SEC;
    time = time * 1000000000; // converting second to ns
    printf("Time elapsed = %.2f ns\n", time);

    if(flag == 1) // printing result
    {
        printf("Sum of in-degrees and sum of out-degrees are equal");
    }
    else
    {
        printf("Sum of in-degrees and sum of out-degrees are not equal");
    }
    return 0;
}
