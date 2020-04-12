
Compile:
```
gcc -std=c11 -pedantic -Wall -Wextra -Werror -fstack-protector-strong -g same.c -o same
```

Run:
```
valgrind -q ./same
```
