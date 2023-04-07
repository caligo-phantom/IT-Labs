# Lab-6-Process-Scheduling

## CPU Scheduler
Imagine you are playing with a bunch of toys and you have a few friends who also want to play with the toys. But there's only one toy at a time that can be used. So, you take turns playing with the toy - you play with it for a little bit, and then your friend gets a turn. This is what a CPU scheduler does, but instead of toys, it's for the computer's processor. The CPU scheduler is like a game organizer who makes sure that every process that wants to use the processor gets a turn to use it. It switches between the different processes so fast that it looks like they are all using the processor at the same time, even though it's actually sharing the processor's time. This way, everyone gets a chance to use the processor and get their work done!

## Problem Description and Algorithm

##  Round Robin Scheduling (RR)
Round Robin Scheduling (RR) is a way to share a toy with your friends. Let's say you have a toy car and three friends want to play with it.

With Round Robin, each friend gets to play with the car for a little bit, then they have to give it to the next friend in line. This keeps happening over and over again, so each friend gets a fair turn with the toy car.

In computer terms, Round Robin is a way to share the computer's CPU (Central Processing Unit) among different programs that want to use it. Each program gets a small amount of time to use the CPU, and then it has to give the CPU to the next program in line. This keeps happening over and over again, so each program gets a fair turn to use the CPU.

Just like you and your friends get to share the toy car fairly with Round Robin, computer programs get to share the CPU fairly too!

## Shortest Job First (SJF)
Okay, imagine you have some toys that you want to play with, but they are all different sizes and shapes. The shortest toys are easier and faster to play with than the longer ones, right?

Shortest Job First (SJF) scheduling is kind of like that. When the computer has a bunch of tasks that need to be done, it looks at how long each task will take to finish (like how big each toy is). Then it picks the task that will take the shortest amount of time to finish (the smallest toy) and starts working on it. Once that task is finished, the computer picks the next shortest task and starts working on it, and so on.

Just like how it's faster to play with the shortest toys first, SJF scheduling helps the computer get things done faster by starting with the shortest task first.

## Priority Scheduling
Imagine you are playing a game with your friends, and there are different levels of difficulty. Some levels are very easy, while others are very hard and require a lot of skills to beat. In the same way, the computer has to do different tasks, and some tasks are more important than others.

With priority scheduling, the computer decides which task to do next based on their priority level. Just like in the game, the computer will try to complete the most important tasks first, before moving on to less important ones.

Each task is assigned a priority level, which can be high, medium, or low. The computer will start by completing all the high priority tasks, then move on to the medium priority tasks, and finally to the low priority tasks.

In this way, priority scheduling ensures that the most important tasks are completed first, which can be very helpful when the computer has a lot of work to do and needs to manage its time effectively.

## Pre-emptive Shortest Job First (SJF)
Pre-emptive Shortest Job First (SJF) is a type of scheduling that tries to make sure that the shortest job gets done first.

Imagine you are a teacher with many students who want to ask you questions. Each student has a question they want to ask you, and some questions are easier than others. Some students have really short questions, and some have really long questions that take a lot of time to answer.

Now imagine you want to answer all of the questions as quickly as possible. Pre-emptive SJF works by answering the shortest question first, no matter which student asked it.

But, what happens if a student with a longer question asks you something while you're in the middle of answering a shorter question? Pre-emptive SJF allows you to stop answering the current question and start answering the new, shorter question first. This way, you can always be answering the shortest question that's currently available to you.

So, pre-emptive SJF is a way to make sure that you're always working on the shortest task you can at any given time.

## Non-Preemptive Priority Scheduling
Non-preemptive priority scheduling is like organizing a birthday party where the guest who is most important gets to eat first, then the next important guest, and so on. This means that if someone more important arrives at the party while someone else is eating, the new guest has to wait until the current guest finishes their meal.

In computer terms, this means that the process with the highest priority will be selected to run first and will use the CPU until it is finished or it yields the CPU voluntarily. Other processes with lower priority have to wait until the current process with higher priority is finished before they can be run. This way, the most important tasks are completed first, but it can cause some tasks with lower priority to wait longer, which can cause delays in completing those tasks.