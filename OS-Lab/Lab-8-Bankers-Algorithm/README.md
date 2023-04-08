# Lab-8-Bankers-Algorithm

## Deadlock
Have you ever tried to share your toys with your friend but both of you wanted to play with the same toy at the same time? That's like a deadlock.

A deadlock happens when two or more people or processes get stuck waiting for each other to do something, but they can't do it because they are all waiting for someone else to do something first. It's like a big traffic jam where all the cars are stuck and no one can move because everyone is waiting for someone else to move first.

Just like how you and your friend need to talk and agree on who gets to play with the toy first, computer programs also need to communicate and agree on who gets to use a shared resource first to avoid getting stuck in a deadlock.

## Deadlock Avoidance
Deadlock avoidance is a way to prevent a situation where two or more people or things are waiting for each other and no one can move forward. Imagine you and your friend both want to play with the same toy, but there is only one toy. You both reach for the toy at the same time and get stuck, waiting for the other to let go. Deadlock avoidance means that you think ahead and try to avoid this situation by making sure that only one person gets the toy at a time.

## Banker's Algorithm
The Banker's Algorithm is like playing a game with your friends where you need to borrow some toys from them. Each friend has a certain number of toys and they want to make sure they don't run out of toys for themselves. You want to borrow some toys, but you don't want to ask for too many toys because you don't want to make your friends upset or make them run out of toys.

So, before you start asking for toys, you have to tell your friends how many toys you need and which types of toys you need. Then, your friends will check if they have enough toys for themselves and for you. If they don't have enough toys, they will tell you to wait until they get more toys or until some other friend returns their toys.

Once your friends check if they have enough toys for everyone, they will start giving you some toys one by one, but they will make sure to keep some toys for themselves so that they don't run out of toys. This way, everyone can share their toys without anyone running out of them or getting upset.

### Safety Algorithm
Imagine you are playing with your friends and you want to build a tower with your toys. But you only have a few toys, and your friends also want to use some toys to build their towers. You don't want to give away all of your toys and be left with none, so you need to make sure that you have enough toys to build your own tower.

The Safety Algorithm is like a way to make sure that everyone has enough toys to build their own tower before they start building. Before anyone starts building, they tell their friends how many toys they need to build their tower. Then, a grown-up who is watching the game (like a computer) makes sure that there are enough toys for everyone to build their towers.

If there aren't enough toys for everyone, the grown-up won't let anyone build their towers yet. They will wait until more toys are available. This way, everyone can build their own tower and everyone is happy.

The Safety Algorithm is like this game because it helps make sure that everyone can get what they need without anyone being left out. The grown-up in the game is like the computer, which makes sure that everyone can use the things they need (in the case of the computer, it's making sure everyone has enough resources to do their work).

### Resource-Request Algorithm
Imagine you are playing with your toys and your friend wants to play with your favorite toy car. You don't want to give it to your friend just yet because you are still playing with it. Your friend can wait for a little while until you finish playing with it and give it to them.

The resource-request algorithm is like this situation. Sometimes, multiple programs running on a computer may need to use the same resources, like the printer or the internet. If one program is using the resource, another program may need to wait until the resource is free to use.

To avoid deadlock, the resource-request algorithm checks if granting the resource to the requesting program will lead to a safe state or not. If it will lead to a safe state, the resource is granted to the requesting program. Otherwise, the program needs to wait for the resource to become available.

Just like your friend waiting for you to finish playing with your toy car, the program requesting the resource needs to wait for the resource to become available. This helps to ensure that all programs can eventually access the resources they need without causing problems or getting stuck.