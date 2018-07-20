# doCirculant UDP
The following repository contains C code for the docirculant() function, implemented using UDP in C.

###### Executing the code
Once you have made sure that you have the build-essential package installed, change your working directory to the location of this repository.

In your command line, run the commands below to build & compile each of the C programs:

For the client:

```
gcc client.c -o client
```

For the server:

```
gcc server.c -o server
```

The above commands will create executable objects called <em>client</em> & <em>server</em>. To execute the objects file in your command line, run the commands below:

First, the server:

```
./server
```

Then, the client:

```
./client localhost 60000
```

### Notes
The following programms were developed for the Network & Distributed Programming lecture.
