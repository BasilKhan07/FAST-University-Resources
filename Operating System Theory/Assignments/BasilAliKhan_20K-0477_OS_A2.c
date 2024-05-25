#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h> 

sem_t northLane;
sem_t eastLane;

int north, east;

void *intersectionN(void *num){
    int number = *(int *)num;
    sleep(5);
    sem_wait(&northLane);
    printf("Car %d going from north to south\n", number);
    sleep(2);
    printf("Car %d has crossed the lane\n", number);
    sleep(1);
    sem_post(&eastLane);
}
void *intersectionE(void *num){
    int number = *(int *)num;
    sleep(5);
    sem_wait(&eastLane);
    printf("Car %d going from east to west\n", number);
    sleep(2);
    printf("Car %d has crossed the lane\n", number);
    sleep(1);
    sem_post(&northLane);
    
}

int main(){
    sem_init(&northLane, 0, 3);
    sem_init(&eastLane, 0, 3);
    printf("Input number of cars in north lane: ");
    scanf("%d", &north);
    printf("Input number of cars in east lane: ");
    scanf("%d", &east);

    pthread_t n_car[north];
    pthread_t e_car[east];

    int northCars[north];
    int eastCars[east];
    for(int i=1; i<=north; i++){
        northCars[i] = i;
    }
    for(int i=1; i<=east; i++){
        eastCars[i] = i;
    }

    for(int i=0; i<north; i++){
        pthread_create(&n_car[i], NULL, intersectionN, (void *)&northCars[i]); 
    }

    for(int i=0; i<east; i++){
        pthread_create(&e_car[i], NULL, intersectionE, (void *)&eastCars[i]);
    }

    for(int i=0; i<north; i++){
        pthread_join(n_car[i], NULL);
    }
    printf("\nCars in north lane have passed!\n");
    for(int i=0; i<east; i++){
        pthread_join(e_car[i], NULL);
    }
    printf("\nCars in east lane have passed!\n");

    return 0;
}
