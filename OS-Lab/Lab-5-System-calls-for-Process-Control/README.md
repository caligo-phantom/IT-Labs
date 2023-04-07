# Lab-5-System-Calls-for-Process-Control

## Executing a C Program on UNIX Platform
```
siddh@Siddharth-PC:~/OS-Lab/Lab-5-System-calls-for-Process-Control$ gcc -o Hello-World Hello-World.c
siddh@Siddharth-PC:~/OS-Lab/Lab-5-System-calls-for-Process-Control$ ./Hello-World
Hello, world!
```

## Use of System Call in C Programming

### fork()
Imagine you are playing with your favorite toy car, and suddenly you want to create a copy of it so that your friend can play with it too. That's what fork() does in C programming!

When a program runs fork(), it creates a copy of itself, just like you created a copy of your toy car. This copy is called a "child" process, and it can do things on its own, just like you and your friend can play with your toy cars separately.

The original program is called the "parent" process, and it continues running as usual. So now you have two processes, the parent and the child, just like you and your friend each have your own toy car to play with.

Each process can do different things and use different parts of the computer's memory, so they don't interfere with each other. And just like you and your friend can play with your toy cars in different ways, the parent and child processes can do different things too!

That's the basic idea of fork() – it creates a copy of a program, so that two processes can run independently and do different things.
```c
#include <stdio.h>
#include <unistd.h>

int main() {
  int pid = fork();
  
  if (pid == 0) {
    printf("Hello from the child process!\n");
  } else {
    printf("Hello from the parent process!\n");
  }
  
  return 0;
}
```
The code creates two processes, just like you and your friend playing with your toy cars separately.

The fork() function creates a copy of the original program, just like you creating a copy of your toy car.

Then, the if-else statement checks if the current process is the parent or the child process. It's like you checking if you're playing with your own toy car or your friend is playing with the copy.

If the process is the child, it prints "Hello from the child process!" to the screen. This is like you saying "Hi, I'm playing with my toy car!" to your friend.

If the process is the parent, it prints "Hello from the parent process!" to the screen. This is like you saying "Hi, I'm playing with my toy car!" to yourself.

Then, the program ends and the two processes stop running. Just like you and your friend stop playing with your toy cars when it's time to go home.

### wait()
Imagine you're playing a game with your friends and you need to wait for them to finish their turns before you can take yours. That's what wait() does in C programming!

When a program runs wait(), it waits for one of its child processes to finish before continuing. This is like you waiting for your friend to finish their turn before you take yours.

Just like in a game, if you take your turn before your friend finishes, things might get messy and you might mess up the game! So wait() makes sure that everything runs smoothly by waiting for the child process to finish first.

When the child process is done, wait() returns a value that tells the program whether the child process finished successfully or not. It's like your friend telling you whether they won the game or not after they finish their turn.

That's the basic idea of wait() – it makes sure that everything runs smoothly by waiting for child processes to finish before continuing, just like you wait for your friends to finish their turns in a game!
```c
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  int pid = fork();
  
  if (pid == 0) {
    printf("Hello from the child process!\n");
  } else {
    printf("Hello from the parent process!\n");
    wait(NULL);
    printf("Child process has finished!\n");
  }
  
  return 0;
}
```
The code creates two processes, just like you and your friend playing a game.

The fork() function creates a copy of the original program, just like you creating a copy of the game for your friend to play.

Then, the if-else statement checks if the current process is the parent or the child process. It's like you checking if you're playing the game or your friend is playing the copy.

If the process is the child, it prints "Hello from the child process!" to the screen. This is like your friend saying "Hi, I'm playing the game!" when they start playing.

If the process is the parent, it prints "Hello from the parent process!" to the screen. This is like you saying "Hi, I'm playing the game!" when you start playing.

Then, the program calls wait(NULL) which waits for the child process to finish before continuing. This is like you waiting for your friend to finish their turn before you take yours.

When the child process is done, the program prints "Child process has finished!" to the screen. This is like your friend telling you "I'm done playing the game now!" when they finish their turn.

Finally, the program ends and the two processes stop running. Just like you and your friend stop playing the game when it's time to go home.

### exec*
#### execl()
execl() is a function in C programming that helps a program start a new process, kind of like when you open a new toy to play with.

When a program calls execl(), it starts a new process that runs a different program, just like when you open a new toy to play with that's different from the one you were playing with before.

The new program that execl() starts takes the place of the old program, just like when you put away your old toy and start playing with the new one instead.

The execl() function takes a few arguments, including the path to the program that you want to start, and any command-line arguments that the program needs. It's like telling your mom or dad the name of the new toy you want to play with and any special instructions for how to play with it.

That's a basic explanation of execl() – it helps a program start a new process that runs a different program, kind of like when you open a new toy to play with!
```c
#include <stdio.h>
#include <unistd.h>

int main() {
  printf("Hello from the original program!\n");
  
  execl("/bin/echo", "echo", "Hello from the new program!", NULL);
  
  return 0;
}
```
The program starts by printing "Hello from the original program!" to the screen. This is like you playing with a toy and saying "Hi!" to your mom or dad.

Then, the program calls execl(). This function starts a new program that runs the echo command from the terminal. This is like your mom or dad bringing you a new toy to play with, and telling you how to play with it.

The execl() function takes a few arguments. The first argument is the path to the program that you want to start. In this case, it's /bin/echo, which is the location of the echo command on a Linux system.

The second argument is the name of the program that you want to start. In this case, it's "echo", which is the name of the command that we want to run.

The third argument is any command-line arguments that the program needs. In this case, it's "Hello from the new program!", which is the message that we want to print to the screen.

The last argument is NULL, which tells the program that we're not passing any more arguments to the execl() function.

After the execl() function is called, the old program is replaced by the new program that we started. This is like putting away your old toy and playing with the new one instead.

The new program runs the echo command, which prints "Hello from the new program!" to the screen. This is like playing with your new toy and showing your mom or dad what you can do with it.

Finally, the program ends and the new process stops running. This is like putting away your toy when it's time to go to bed.

#### execv()
execv() is a function in C programming that helps a program start a new process, just like execl().

However, unlike execl(), execv() allows you to pass an array of arguments to the new process as a single argument. It's like if you were giving your mom or dad a basket of toys instead of telling them about each toy one by one.

The first argument of execv() is the path to the program that you want to start, and the second argument is an array of strings that represent the arguments to the new program. It's like telling your mom or dad the name of the new toy you want to play with, and giving them a basket of toys to play with too.

When execv() is called, the new program replaces the old program, just like with execl(). And just like with execl(), the new program can be a completely different program than the old one.

That's a basic explanation of execv() – it helps a program start a new process and pass an array of arguments to the new process, just like giving your mom or dad a basket of toys to play with!
```c
#include <stdio.h>
#include <unistd.h>

int main() {
  printf("Hello from the original program!\n");

  char *args[] = {"echo", "Hello from the new program!", NULL};
  execv("/bin/echo", args);

  return 0;
}
```
The program starts by printing "Hello from the original program!" to the screen. This is like you playing with a toy and saying "Hi!" to your mom or dad.

Then, the program declares an array of strings called args. This is like you picking out a basket of toys to play with.

The first element of the args array is "echo", which is the name of the program that we want to start. This is like telling your mom or dad which toy you want to play with.

The second element of the args array is "Hello from the new program!", which is the message that we want to print to the screen. This is like telling your mom or dad what you want to do with the toy.

The last element of the args array is NULL, which tells the program that we're done passing arguments to the execv() function. This is like putting away the basket of toys when you're done playing with them.

After that, the program calls execv(). This function starts a new program that runs the echo command from the terminal, passing the args array as arguments. This is like your mom or dad bringing you a basket of toys to play with and telling you how to play with them.

The first argument of execv() is the path to the program that we want to start. In this case, it's /bin/echo, which is the location of the echo command on a Linux system.

The second argument of execv() is the args array that we declared earlier. This is like giving your mom or dad the basket of toys to play with.

When execv() is called, the new program replaces the old program, just like with execl(). And just like with execl(), the new program can be a completely different program than the old one.

The new program runs the echo command, which prints "Hello from the new program!" to the screen. This is like playing with your new toy and showing your mom or dad what you can do with it.

Finally, the program ends and the new process stops running. This is like putting away your toy when it's time to go to bed.

#### execle()
execle() is another function in C programming that helps a program start a new process, just like execl() and execv().

But unlike those functions, execle() allows you to pass the environment variables of the new process as a separate argument. Environment variables are like a list of instructions for the new process to follow, kind of like a recipe for baking cookies.

The first argument of execle() is the path to the program that you want to start, and the second argument is the environment list for the new program. It's like giving your mom or dad a recipe for the new toy you want to play with, along with a basket of toys to play with.

The following arguments to execle() are the command-line arguments to the new process, just like with execl().

When execle() is called, the new program replaces the old program, just like with execl() and execv(). And just like with those functions, the new program can be a completely different program than the old one.

That's a basic explanation of execle() – it helps a program start a new process and pass environment variables to the new process, just like giving your mom or dad a recipe for a new toy to play with!
```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  printf("Hello from the original program!\n");

  char *env[] = {"MESSAGE=Hello from the new program!", NULL};
  execle("/usr/bin/env", "env", NULL, env);

  return 0;
}
```
The program starts by printing "Hello from the original program!" to the screen. This is like you playing with a toy and saying "Hi!" to your mom or dad.

Then, the program declares an array of strings called env. This is like you picking out a basket of toys to play with.

The first element of the env array is "MESSAGE=Hello from the new program!", which is an environment variable that we want to set. This is like telling your mom or dad which toy you want to play with and what you want to do with it.

The last element of the env array is NULL, which tells the program that we're done passing environment variables to the execle() function. This is like putting away the basket of toys when you're done playing with them.

After that, the program calls execle(). This function starts a new program that runs the env command from the terminal, passing the env array as environment variables. This is like your mom or dad bringing you a basket of toys to play with and telling you how to play with them.

The first argument of execle() is the path to the program that we want to start. In this case, it's /usr/bin/env, which is the location of the env command on a Linux system.

The second argument of execle() is the name of the command that we want to run, which is env. This is like telling your mom or dad what kind of toy you want to play with.

The third argument of execle() is NULL, which means that we're not passing any command-line arguments to the new process. This is like not needing to tell your mom or dad anything else about the toy you want to play with.

The fourth argument of execle() is the env array that we declared earlier. This is like giving your mom or dad the basket of toys to play with.

When execle() is called, the new program replaces the old program, just like with execl() and execv(). And just like with those functions, the new program can be a completely different program than the old one.

The new program runs the env command, which sets an environment variable called MESSAGE to "Hello from the new program!". This is like following the recipe for the new toy that you want to play with.

Finally, the program ends and the new process stops running. This is like putting away your toy when it's time to go to bed.

#### execve()
execve() is a function in C programming that's used to run another program from within a program.

Imagine you have a bunch of different toys to play with. Each toy is like a different program that your computer can run. Sometimes, you might want to stop playing with one toy and switch to another toy. That's kind of like what execve() does - it lets your program stop running and start running a different program instead.

When you use execve(), you have to tell it which program you want to run. This is like telling your mom or dad which toy you want to play with next. You also have to give execve() some information about the program you want to run, like where it's located and any special settings or preferences it needs to run correctly. This is like telling your mom or dad where to find the toy and how to set it up.

When you call execve(), your program stops running and the new program starts running instead. It's kind of like stopping playing with one toy and starting to play with another toy. Once the new program is running, it does whatever it's programmed to do, and your original program is done. It's like your original toy is put away and you're just playing with the new toy now.

execve() is a powerful tool that lets programs interact with each other and work together. It's like if you were playing with one toy and your friend was playing with another toy, but then you decided to play together and use both toys at the same time. You could each do different things with your toys, but you're still playing together and having fun. That's kind of what execve() lets programs do - they can work together and do different things, but they're still part of the same computer program.
```c
#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = {"ls", "-l", NULL};
    execve("/bin/ls", args, NULL);
    printf("This won't be printed\n");
    return 0;
}
```
Imagine you're playing with your toys, and you want to switch to playing with a different toy. You tell your mom or dad that you want to switch to playing with the toy car, and they go get it for you. That's kind of like what this program does - it tells the computer to switch from running the original program to running a different program.

In this program, the toy car is the ls command. The program sets up an array called args that tells execve() what command to run and any arguments that command needs. It's like telling your mom or dad what toy you want to play with and how to set it up.

Then, the program calls execve() with the location of the ls command and the args array. This is like telling your mom or dad to go get the toy car and set it up for you. Once execve() is called, the current program stops running and the ls command starts running instead. It's like you stop playing with one toy and start playing with the toy car instead.

Finally, the program prints out a message, but this message won't actually be printed because execve() doesn't return unless there's an error. It's like you saying "I'm done playing with this toy now" after you've already started playing with the toy car. You're not really done with it until you stop playing with the car and go do something else.

#### execlp()
Imagine that you're playing a game of hide and seek with your friends, and you need to go find them. You know that they're playing somewhere in the park, but you're not sure exactly where.

execlp() is a function in C programming that helps your computer find a program that you want to run, just like you're trying to find your friends in the park. When you call execlp(), you give it the name of the program you want to run, and it looks for that program in a list of places called the "path".

The "path" is a list of folders on your computer where the computer looks for programs to run. It's like a map of the park that you use to find your friends. If you're looking for your friends in the park, you know that they could be hiding in a lot of different places - under a tree, behind a building, etc. - so you need to check all of those places to find them.

In the same way, execlp() checks all of the folders in the "path" to find the program you want to run. Once it finds the program, it runs it for you. It's like you finding your friends and starting to play the game of hide and seek with them.
```c
#include <stdio.h>
#include <unistd.h>

int main() {
    execlp("ls", "ls", "-l", NULL);
    printf("This won't be printed\n");
    return 0;
}
```
This program uses execlp() to run the ls command, just like in the previous example with execve(). The difference is that this time, we only give the name of the command to execlp(), and it searches the "path" to find it. The "ls" argument is actually the first argument that ls takes, which is its own name. The "-l" argument is the second argument that ls takes.

Just like before, once execlp() is called, the current program stops running and the ls command starts running instead.

#### execvp()
Imagine you're playing a game of pretend, and you want to change what you're pretending to be. For example, you might be pretending to be a chef, but now you want to pretend to be a firefighter.

execvp() is a function in C programming that helps your computer change what program it's running, just like you're changing what you're pretending to be. When you call execvp(), you give it the name of the program you want to run, and it looks for that program in a list of places called the "path".

The "path" is a list of folders on your computer where the computer looks for programs to run. It's like a list of places where you keep your different costumes for when you're playing pretend. If you're pretending to be a chef, you might have your chef costume in your bedroom, and if you're pretending to be a firefighter, you might have your firefighter costume in your closet. execvp() checks all of the folders in the "path" to find the program you want to run, just like you would check all of the places where you keep your different costumes to find the right one.

Once it finds the program, execvp() runs it for you, just like when you put on your firefighter costume and start pretending to be a firefighter. The current program stops running and the new program starts running instead.
```c
#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = {"ls", "-l", NULL};
    execvp(args[0], args);
    printf("This won't be printed\n");
    return 0;
}
```
This program uses execvp() to run the ls command, just like in the previous examples with execve() and execlp(). The difference is that this time, we store the command and its arguments in an array called args. The first element of the array is the command itself, and the rest of the elements are its arguments. The NULL at the end of the array is there to indicate the end of the argument list.

When we call execvp(), we give it the first element of args as the command name, and we give args itself as the argument list. Just like before, once execvp() is called, the current program stops running and the ls command starts running instead.

### getpid()
Imagine you and your friends are all playing a game of tag. In this game, everyone has a different number to identify them, kind of like a secret code. When someone tags you, they have to call out your number to let everyone else know they got you.

In computer programming, getpid() is a function that helps your program find out its own "secret code" number, called a "process ID" or "PID" for short. A "process" is just a fancy word for a running program on your computer. Just like in the game of tag, knowing your own PID can be helpful in certain situations, like when one program needs to communicate with another program.

When you call getpid(), your program gets its own unique PID number assigned by the computer. Just like you and your friends all have different numbers, every running program on your computer has a different PID number.
```c
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("My process ID is: %d\n", getpid());
    return 0;
}
```
This program uses getpid() to print its own PID number to the screen. When the program is run, getpid() gets called and returns the PID number, which is then printed out using printf().

### getpgrp()
Imagine you and your friends are all playing a game of hide and seek, and you've decided to split into two teams. Each team has a leader who is in charge of giving orders and making sure everyone stays safe. If you want to know who the leader of your team is, you ask your teammates or look for the person who is giving orders.

In computer programming, getpgrp() is a function that helps your program find out the "leader" of your team, called the "process group leader" or "PGID" for short. A "process group" is a collection of related processes that are all working together to do the same thing. Just like in the game of hide and seek, knowing who the PGID is can be helpful in certain situations, like when one process needs to communicate with another process.

When you call getpgrp(), your program finds out the PGID of the process group it belongs to. Just like each team has a different leader, each process group has a different PGID.
```c
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("My process group leader ID is: %d\n", getpgrp());
    return 0;
}
```
This program uses getpgrp() to print the PGID of the process group it belongs to. When the program is run, getpgrp() gets called and returns the PGID, which is then printed out using printf().