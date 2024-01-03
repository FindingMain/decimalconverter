// converts decimal value to binary, octaganol, or hexadecimal value //
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // print errors if number of arguments is not three // 
    if( argc  == 1 ) printf("No flag detected\n");
    if( argc  == 2 ) printf("No number to convert detected\n");
    if( argc  >= 4 ) printf("Too many values\n");
    // exit prematurely if so //
    if( argc  != 3 ) exit(0);
    // initialize flag, decimal, and converted values
    char flag[6];
    int count, decimal;
    char converted[1000];
    sscanf(argv[1], "%5s", flag);
    count = sscanf(argv[2], "%d", &decimal);
    // check for valid flags, check that decimal value was provided, run conversion functions
    void itob(), itoo(), itoh(), reverse();
    if     ( strcmp(flag, "--bin") == 0 || strcmp(flag, "-b") == 0 ) {
        if ( count ) itob(decimal, converted);
        else {
            printf("No base 10 value provided");
            exit(0);
        }
    }
    else if( strcmp(flag, "--oct") == 0 || strcmp(flag, "-o") == 0 ) {
        if ( count ) itoo(decimal, converted);
        else {
            printf("No base 10 value provided");
            exit(0);
        }
    }
    else if( strcmp(flag, "--hex") == 0 || strcmp(flag, "-h") == 0 ) {
        if ( count ) itoh(decimal, converted);
        else {
            printf("No base 10 value provided");
            exit(0);
        }
    }
    else {
        printf("No valid flag detected");
        exit(0);
    }
    // print converted value
    printf("%s\n", converted);
}

void reverse(char t[]) {
    int i, j, len;
    char tmp;
    len = strlen(t);
    for(i=0, j=len-1;;i++,j--) {
        if (j<i) break;
        tmp = t[i];
        t[i] = t[j];
        t[j] = tmp;
    }
    return;
}

void itob(int n, char s[]) {
     int i;
     for( i = 0; n; n /= 2, i++) {
        s[i] = ( n % 2 == 0 ) ? '0' : '1';
     }

     s[i] = 0;
     void reverse();
     reverse(s);
}

void itoo(int n, char s[]) {
    int i;
    for( i = 0; n; n /= 8, i++ ) {
            int mod = n % 8;
            s[i] = ( n / 8 == 0 ) ? n + 48 : mod + 48;
    }

    s[i] = 0;
    void reverse();
    reverse(s);
}

void itoh(int n, char s[]){
    int i;
  
  	for( i = 0; n; n /= 16, i++ ) {
      	int mod = n % 16;
    	if ( n / 16 == 0 ) s[i] = ( n <= 9) ? 48 + n : 87 + n;
      	else s[i] = ( mod <= 9) ? 48 + mod : 87 + mod;
    }
  	s[i] = '\0';
   	void reverse();
    reverse(s);
}