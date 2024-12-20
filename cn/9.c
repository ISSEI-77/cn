#include<stdio.h>

#define BUFFER_SIZE 10

void insert_frame(int[], int*, int);
void display_buffer(int[], int*);

int main(){
    int count = 0, frame_number, buffer[BUFFER_SIZE];

    while(1){
        printf("Enter your frame number (0 to Quit): ");
        scanf("%d", &frame_number);
        if(frame_number == 0){
            break;
        }
        insert_frame(buffer, &count, frame_number);
        display_buffer(buffer, &count);
    }
    return 0;
}

void insert_frame(int buffer[], int* count, int frame_number){
    if(*count >= BUFFER_SIZE){
        printf("BUFFER IS FULL, CAN'T INSERT MORE FRAMES\n");
        return;
    }
    int i = (*count) - 1;

    while(i >= 0 && buffer[i] > frame_number){
        buffer[i + 1] = buffer[i];
        i--;
    }
    buffer[i + 1] = frame_number;
    (*count)++;
}

void display_buffer(int buffer[], int* count){
    printf("Current Frames in BUFFER: ");
    for(int i = 0; i < (*count); i++){
        printf("%d ", buffer[i]);
    }
    printf("\n");
}
