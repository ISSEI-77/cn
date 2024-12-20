#include<stdio.h>
#include<string.h>

void character_stuffing(char* data,char flag, char escape,char* stuffed);
void character_unstuffing(char* stuffed,char flag, char escape,char* unstuffed);
void bit_stuffing(char *data,char* stuffed);
void bit_unstuffing(char *stuffed,char* unstuffed);
void character_count_framing(char* data,char* framed);
void character_count_deframing(char* framed,char* deframed);

int main(){
    char data[] = "venky|bkl";
    char flag = '|';
    char escape = '/';

    char stuffed[256],unstuffed[256];

    printf("Character Stuffing\n");
    character_stuffing(data,flag,escape,stuffed);
    printf("Character stuffed %s\n",stuffed);
    character_unstuffing(stuffed,flag,escape,unstuffed);
    printf("Character unstuffed %s\n\n",unstuffed);

    char binary_data[] = "111110";
    char bit_stuffed[256],bit_unstuffed[256];

    printf("Bit Stuffing\n");
    bit_stuffing(binary_data,bit_stuffed);
    printf("Bit stuffed %s\n",bit_stuffed);
    bit_unstuffing(bit_stuffed,bit_unstuffed);
    printf("Bit unstuffed %s\n\n",bit_unstuffed);

    char count_data[]="BLANKSPACE";
    char framed[256],deframed[256];
    character_count_framing(count_data,framed);
    printf("Character count\n");
    printf("Character count framing : %s\n",framed);
    character_count_deframing(framed,deframed);
    printf("Character count deframing : %s\n",deframed);
    return 0;
}

void character_stuffing(char* data,char flag, char escape,char* stuffed){
    int j = 0;
    stuffed[j++] = flag;

    for(int i = 0;data[i]!= '\0';i++){
        if(data[i] == escape || data[i]== flag){
            stuffed[j++] = escape;
        }
        stuffed[j++] = data[i];
    }
    stuffed[j++] = flag;
    stuffed[j]= '\0';
}

void character_unstuffing(char* stuffed,char flag,char escape,char* unstuffed){
    int j =0;
    for(int i =0;stuffed[i]!='\0';i++){
        if(stuffed[i]== flag || stuffed[i] == escape){
            i++;
        }
        unstuffed[j++] = stuffed[i];
    }
    unstuffed[j]='\0';
}

void bit_stuffing(char *data,char* stuffed){
    int count = 0;
    int j =0;
    for(int i = 0;data[i]!= '\0';i++){
        stuffed[j++] = data[i];
        if(data[i]=='1'){
            count++;
            if(count == 5){
                stuffed[j++] = '0';
                count=0;
            }
        }else{
            count = 0;
        }
    }
    stuffed[j] = '\0';
}

void bit_unstuffing(char *stuffed,char *unstuffed){
    int count = 0;
    int j = 0;
    for(int i = 0;stuffed[i]!='\0';i++){
        unstuffed[j++] = stuffed[i];
        if(stuffed[i] == '1'){
            count++;
            if(count==5){
                i++;
                count=0;
            }
        }else{
            count = 0;
        }
    }
    unstuffed[j] = '\0';
}

void character_count_framing(char* data,char* framed){
    int length = strlen(data);
    sprintf(framed,"%02d%s",length,data);
}

void character_count_deframing(char* framed,char* deframed){
    int length;
    sscanf(framed,"%02d",&length);
    strncpy(deframed,framed+2,length);
    deframed[length] = '\0';
}
