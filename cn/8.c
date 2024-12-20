#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> // to use sleep() function in Linux/mac OS

#define MAX_CAPACITY 9
#define LEAK_RATE 2

int bucket_count = 0; // Number of packets currently in the bucket

void arrive_packet(int);
void leak_packets();

int main(){
    int packet_size;

    printf("\nSIMULATION OF LEAKY BUCKET ALGORITHM\n\n");
    printf("Max bucket capacity : %d\n", MAX_CAPACITY);
    printf("Leak rate of the bucket per second : %d\n\n", LEAK_RATE);

    while(1){
        printf("Enter your packet size (0 to end program) : ");
        scanf("%d", &packet_size);

        if(packet_size == 0){
            break;
        }

        arrive_packet(packet_size);
        sleep(1);
        leak_packets();
    }
    return 0;
}

void arrive_packet(int packet_size){
    if(bucket_count + packet_size <= MAX_CAPACITY){
        bucket_count = bucket_count + packet_size;
        printf("Packet arrived, current bucket size : %d\n", bucket_count);
    } else {
        printf("Packet Discarded, due to OVERFLOW!\n");
    }
}

void leak_packets(){
    if(bucket_count > 0){
        bucket_count = bucket_count - LEAK_RATE;
        if(bucket_count < 0){
            bucket_count = 0;
        }
        printf("Bucket Leaked! Current Bucket size : %d\n", bucket_count);
    } else {
        printf("Bucket Empty! No packets to Leak!\n");
    }
}
