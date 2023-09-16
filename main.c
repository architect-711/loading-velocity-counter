#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PACKAGE_SIZE 86016.0f
#define BYTES_IN_GIGABYTE 1024
#define SECONDS_IN_HOUR 3600    
#define COMMA_DELIMITER "."
#define TIME_ELAPSED_QUESTION "How much has been elapsed? hh.mm.ss : "
#define DATA_DOWNLOADED_QUESTION "How much data has been downloaded? gb.mb : "

float T, v;
int s, t;
char raw_t[20], raw_s[20];

void count_t()
{
    char *token = strtok(raw_t, COMMA_DELIMITER);
    t += atoi(token) * 3600;

    token = strtok(NULL, COMMA_DELIMITER);
    t += atoi(token) * 60;

    token = strtok(NULL, COMMA_DELIMITER);
    t += atoi(token);
}

void count_s()
{
    char *token = strtok(raw_s, COMMA_DELIMITER);
    s = atoi(token) * BYTES_IN_GIGABYTE;

    token = strtok(NULL, COMMA_DELIMITER);
    s += atoi(token);
}

void interview()
{
    printf(TIME_ELAPSED_QUESTION);
    gets(raw_t);

    printf(DATA_DOWNLOADED_QUESTION);
    gets(raw_s);
}

void count_T()
{
    v = (float) s / (float) t;
    T = PACKAGE_SIZE / v / 3600.0;
}

int main()
{
    interview();
    count_s();
    count_t();
    count_T();

    printf("Time left: %.1fh | velocity: %.1fmb/s | data loaded came: %dmb | time elapsed: %ds", T, v, s, t);
}