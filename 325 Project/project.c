#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

#define LIMIT 5 // process limit

int flag = 0; // count of number of thread

pthread_mutex_t mutex; // mutex to provide mutual exclusion

sem_t z; // semaphore for updating flag value n times
sem_t ksem; // semaphore for updating flag value

// function to synchronize threads
void *thread(void *keyword)
{
    sem_wait(&z); // lock semaphore

    if(flag >= LIMIT)
    {
        printf("\n\tSearch is on wait for keyword: %s ...\n", keyword); // processes on wait
    }

    // counting semaphore
    sem_wait(&ksem); // entry section
    flag++; // increment value
    printf("\n\tSearch has started for keyword: %s\n", keyword); // started processes

    pthread_mutex_lock(&mutex); // locks mutex
    usleep(3);
    printf("\n\tSearching for keyword: %s\n", keyword); // start searching

    // print movie titles
    output(keyword, pthread_self()); // pthread_self() get current thread id

    printf("\n\tSearching for keyword: %s has finished.\n\n\n", keyword);

    pthread_mutex_unlock(&mutex); // unlocks mutex
    sem_post(&ksem); // exit section

    flag = 0; // initialize flag to 0 to continue searching until program exits
}

// function to print movie title
void output(char str[], int id)
{
    if(str[0] == 'h' && str[1] == 'a' && str[2] == 'r' && str[3] == 'r' && str[4] == 'y') //harry
    {
        printf("\n\t\t\t---------");
        printf("\n\t\tMatches found for %s\n\n", str);

        printf("\n\t\tName: HARRY POTTER AND THE DEATHLY HALLOWS: PART 2\n");
        printf("\t\tDirector: David Yates\n");
        printf("\t\tRelease Date: Jul 15, 2011\n");
        printf("\t\tRating: 8.3\n");

        printf("\n\t\tName: HARRY POTTER AND THE DEATHLY HALLOWS: PART 1\n");
        printf("\t\tDirector: David Yates\n");
        printf("\t\tRelease Date: Nov 19, 2010\n");
        printf("\t\tRating: 7.1\n");

        printf("\n\t\tName: HARRY POTTER AND THE HALF-BLOOD PRINCE\n");
        printf("\t\tDirector: David Yates\n");
        printf("\t\tRelease Date: Jul 15, 2009\n");
        printf("\t\tRating: 7.1\n");

        printf("\t\t\t---------\n");
    }
    else if(str[0] == 's' && str[1] == 'p' && str[2] == 'i' && str[3] == 'd' && str[4] == 'e' && str[5] == 'r') //spider
    {
        printf("\n\t\t\t---------");
        printf("\n\t\tMatches found for %s\n\n", str);

        printf("\n\t\tName: SPIDER-MAN: INTO THE SPIDER-VERSE\n");
        printf("\t\tDirector: Bob Persichetti, Peter Ramsey, Rodney Rothman\n");
        printf("\t\tRelease Date: Dec 14, 2018\n");
        printf("\t\tRating: 8.8\n");

        printf("\n\t\tName: SPIDER-MAN: NO WAY HOME\n");
        printf("\t\tDirector: Jon Watts\n");
        printf("\t\tRelease Date: Dec 17, 2021\n");
        printf("\t\tRating: 7.9\n");

        printf("\n\t\tName: SPIDER-MAN: FAR FROM HOME\n");
        printf("\t\tDirector: Jon Watts\n");
        printf("\t\tRelease Date: Jul 2, 2019\n");
        printf("\t\tRating: 7.4\n");

        printf("\t\t\t---------\n");
    }
    else if(str[0] == 'f' && str[1] == 'a' && str[2] == 's' && str[3] == 't') //fast
    {
        printf("\n\t\t\t---------");
        printf("\n\t\tMatches found for %s\n\n", str);

        printf("\n\t\tName: FAST & FURIOUS PRESENTS: HOBBS & SHAW\n");
        printf("\t\tDirector: David Leitch\n");
        printf("\t\tRelease Date: Aug 2, 2019\n");
        printf("\t\tRating: 6.1\n");

        printf("\n\t\tName: FAST & FURIOUS 6\n");
        printf("\t\tDirector: Justin Lin\n");
        printf("\t\tRelease Date: May 24, 2013\n");
        printf("\t\tRating: 6.1\n");

        printf("\t\t\t---------\n");
    }
    else if(str[0] == 'g' && str[1] == 'a' && str[2] == 'm' && str[3] == 'e' && str[4] == 's') //games
    {
        printf("\n\t\t\t---------");
        printf("\n\t\tMatches found for %s\n\n", str);

        printf("\n\t\tName: THE HUNGER GAMES: CATCHING FIRE\n");
        printf("\t\tDirector: Francis Lawrence\n");
        printf("\t\tRelease Date: Nov 22, 2013\n");
        printf("\t\tRating: 7.6\n");

        printf("\n\t\tName: THE HUNGER GAMES: MOCKINGJAY, PART 2\n");
        printf("\t\tDirector: Francis Lawrence\n");
        printf("\t\tRelease Date: Nov 20, 2015\n");
        printf("\t\tRating: 6.5\n");

        printf("\n\t\tName: THE HUNGER GAMES: MOCKINGJAY, PART 1\n");
        printf("\t\tDirector: Francis Lawrence\n");
        printf("\t\tRelease Date: Nov 21, 2014\n");
        printf("\t\tRating: 6.3\n");

        printf("\t\t\t---------\n");
    }
    else if(str[0] == 'd' && str[1] == 'o' && str[2] == 'c' && str[3] == 't' && str[4] == 'o' && str[5] == 'r') //doctor
    {
        printf("\n\t\t\t---------");
        printf("\n\t\tMatches found for %s\n\n", str);

        printf("\n\t\tName: DOCTOR STRANGE\n");
        printf("\t\tDirector: Kevin Feige\n");
        printf("\t\tRelease Date: Nov 4, 2016\n");
        printf("\t\tRating: 7.3\n");

        printf("\n\t\tName: DOCTOR STRANGE IN THE MULTIVERSE OF MADNESS\n");
        printf("\t\tDirector: Kevin Feige\n");
        printf("\t\tRelease Date: May 6, 2022\n");
        printf("\t\tRating: 6.5\n");

        printf("\t\t\t---------\n");
    }
    else if(str[0] == 'f' && str[1] == 'i' && str[2] == 'n' && str[3] == 'a' && str[4] == 'l') //final
    {
        printf("\n\t\t\t---------");
        printf("\n\t\tMatches found for %s\n\n", str);

        printf("\n\t\tName: FINAL DESTINATION 5\n");
        printf("\t\tDirector: Steven Quale\n");
        printf("\t\tRelease Date: Aug 12, 2011\n");
        printf("\t\tRating: 5.9\n");

        printf("\n\t\tName: FINAL DESTINATION 3\n");
        printf("\t\tDirector: James Wong\n");
        printf("\t\tRelease Date: Feb 10, 2006\n");
        printf("\t\tRating: 5.1\n");

        printf("\t\t\t---------\n");
    }
    else
    {
        printf("\n\t\tNo matches found for %s!\n\n\n", str);
    }
}

int main()
{
    int choice; // menu choice

    while(1)
    {
        printf("\t\t\t\t\t-------Movie Ratings Problem-------\n\t\t\t\t\t\t\tMenu");
        printf("\n\t1. Search Movies by Keywords\n\t2. Exit\n");

        printf("\n\tEnter your choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            int n; // number of keywords
            printf("\n\tAvailable keywords: Harry, Spider, Fast, Games, Doctor, Final\n");
            printf("\n\tEnter the number of searching keywords: ");
            scanf("%d", &n);

            pthread_t key[n]; // n number of threads
            char arr[n][100]; // keyword array

            pthread_mutex_init(&mutex, NULL); // mutex initialization
            sem_init(&z, 0, 0); // semaphore initialized to 0
            sem_init(&ksem, 0, LIMIT); // semaphore initialized to 5

            printf("\n\tEnter your keywords: \n");

            for(int i = 0; i < n; i++)
            {
                printf("\tKeyword %d: ", i + 1);
                scanf("%s", arr[i]);

                pthread_create(&key[i], NULL, thread, (void *)&arr[i]); // create threads
                getchar();
            }

            for(int i = 0; i < n; i++)
            {
                sem_post(&z); // signal semaphore to update flag value
            }

            for(int i = 0; i < n; i++)
            {
                pthread_join(key[i], NULL); // waiting for threads to terminate
            }

            printf("\n\tAll threads have finished its search\n\n\n");

            pthread_mutex_destroy(&mutex); // destroy mutex
            sem_destroy(&z); // destroy semaphore
            sem_destroy(&ksem);
        }
        else if(choice == 2)
        {
            exit(0);
        }
        else
        {
            printf("\n\tTry Again!\n\n\n");
        }
    }
}
