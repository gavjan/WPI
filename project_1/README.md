
Compile:
```
gcc -std=c11 -pedantic -Wall -Wextra -Werror -fstack-protector-strong -g pal.c -o pal
```

Run:
```
valgrind -q ./pal
```
