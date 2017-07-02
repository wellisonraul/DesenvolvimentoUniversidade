#ifndef mystring_h
#define mystring_h

int mystrlen(char *s);
int mystrcmp(char *s1, char *s2);
int mystrncmp(char *s1, char *s2, int n);
char *mystrcat(char *s1, char *s2);
char *mystrncat(char *s1,  char *s2, int n);
char *mystrcpy(char *s1, char *s2);
char *mystrncpy(char *s1, char *s2, int n);
char *mystrdup(char *s);

#endif
