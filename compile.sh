gcc compiler.c -o comp
cat $1 | ./comp > $1.c
gcc $1.c 
