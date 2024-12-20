#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<stdbool.h>

#define Window_size 4
#define loss_probablity 30
#define Total_frames 10

void sliding_window_protocol();
bool send_frame(int);
bool receive_ack(int);

int main(){
    srand(time(NULL));

    printf("Initializing Sliding Window with GO Back N protocol...\n");
    sliding_window_protocol();

    return 0;
}

void sliding_window_protocol(){
    int base = 0;
    int acknowledgements = 0;
    int next_frame = 0;

    while(acknowledgements < Total_frames){
        while(next_frame < base + Window_size && next_frame < Total_frames){
            if(send_frame(next_frame)){
                next_frame++;
            } else {
                break;
            }
        }

        for(int i = base; i < next_frame; i++){
            if(receive_ack(i)){
                base++;
                acknowledgements++;
            } else {
                printf("Retransmitting the frame %d for being lost acknowledgment\n", base);
                next_frame = base;
                break;
            }
        }
    }
    printf("\nALL FRAMES SENT SUCCESSFULLY\n");
}

bool send_frame(int frame){
    int random = rand() % 100;
    if(random < loss_probablity){
        printf("Frame %d lost during transmission\n", frame);
        return false;
    }
    printf("Frame %d sent successfully\n", frame);
    return true;
}

bool receive_ack(int frame){
    int random = rand() % 100;
    if(random < loss_probablity){
        printf("Frame %d acknowledgment is lost\n", frame);
        return false;
    }
    printf("Frame %d acknowledged successfully\n", frame);
    return true;
}
