#include<stdio.h>
#include<string.h>

void encrypt(char*);
void decrypt(char*);

int main(){
    char text[100];

    printf("Enter the text you want to Encrypt : ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Original Text : %s\n", text);
    encrypt(text);
    printf("Encrypted : %s\n", text);
    decrypt(text);
    printf("Decrypted : %s\n", text);
    return 0;
}

void encrypt(char* text){
    for(int i = 0; text[i] != '\0'; i++){
        text[i] = text[i] + 1;
    }
}

void decrypt(char* text){
    for(int i = 0; text[i] != 0; i++){
        text[i] = text[i] - 1;
    }
}
