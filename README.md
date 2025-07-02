# CS50: Introduction to Computer Science

This repository contains code created while taking [**CS50 Introduction to Computer Science**](https://pll.harvard.edu/course/cs50-introduction-computer-science) course by Harvard's OpenCourseWare and this is the year 2025 version.
Some programs were written by me from scratch, others would have help functions or would have TODO comments put in place for me to implement the functionality required.

## Set of problems Week 1 - Intro to C

First week of the course covers: Introduction to C with a few simple problems: Hello-World, Hello-It's me, Mario and Credit.

### Mario (less)

The task was to implement a program in C that recreates that pyramid, using hashes (#) for bricks, as in the below:

```
           #
          ##
         ###
        ####
       #####
      ######
     #######
    ########
```

The user is to be prompted for an int for the pyramid’s actual height, so that the program can also output shorter pyramids like the below:

```
    #
    ##
    ###
    ####
```

Re-prompting the user, again and again as needed, if their input is not greater than 0 or not an int altogether.

### Credit

The task was to implement a program in C that checks the validity of a given credit card number using Luhn’s Algorithm:
Most cards use an algorithm invented by Hans Peter Luhn of IBM. According to Luhn’s algorithm, one can determine if a credit card number is (syntactically) valid as follows:

1. Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
2. Add the sum to the sum of the digits that weren’t multiplied by 2.
3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
4. That’s kind of confusing, so let’s try an example with David’s Visa: 4003600000000014.

So the program prompts the user for a credit card number and then reports (via printf) whether it is a valid American Express, MasterCard, or Visa card number, per the definitions of each’s format herein.

## Set of problems Week 2 - Arrays in C

### Scrabble

The task was to create a program in C that determines the winner of a short Scrabble-like game. The program prompts for input twice: once for “Player 1” to input their word and once for “Player 2” to input their word. Then, depending on which player scores the most points, the program either prints “Player 1 wins!”, “Player 2 wins!”, or “Tie!” (in the event the two players score equal points). For example:

```
$ make scrabble
$ ./scrabble
Player 1: Question?
Player 2: Question!
Tie!
$ ./scrabble
Player 1: red
Player 2: wheelbarrow
Player 2 wins!
$ ./scrabble
Player 1: COMPUTER
Player 2: science
Player 1 wins!
```

### Readability

The task was to implement a program that calculates the approximate grade level needed to comprehend some text. The program prints as output “Grade X” where “X” is the grade level computed, rounded to the nearest integer. If the grade level is 16 or higher (equivalent to or greater than a senior undergraduate reading level), the program outputs “Grade 16+” instead of giving the exact index number. If the grade level is less than 1, the program outputs “Before Grade 1”.

### Caesar

Unencrypted text is generally called plaintext. Encrypted text is generally called ciphertext. And the secret used is called a key.
The task was to write a program that enables the user to encrypt messages using Caesar’s cipher. At the time the user executes the program, they should decide, by providing a command-line argument, what the key should be in the secret message they’ll provide at runtime. We shouldn’t necessarily assume that the user’s key is going to be a number; though you may assume that, if it is a number, it will be a positive integer. Example:

```
Usage: ./caesar key
$ ./caesar 13
plaintext: Hi there!
ciphertext: Uv gurer!
$ ./caesar 26
plaintext: This is CS50.
ciphertext: This is CS50.
```

## Set of problems Week 3 - Algorithms

This week's lecture explained 3 types of basic algorithms used to sort through data:

1. Selection sort iterates through the unsorted portions of a list, selecting the smallest element each time and moving it to its correct location.
2. Bubble sort compares pairs of adjacent values one at a time and swaps them if they are in the incorrect order. This continues until the list is sorted.
3. Merge sort recursively divides the list into two repeatedly and then merges the smaller lists back into a larger one in the correct order.

### Plurality

Context: “plurality vote” (also known as “first-past-the-post” or “winner take all”): every voter gets to vote for one candidate. At the end of the election, whichever candidate has the greatest number of votes is declared the winner of the election.

This task was about completing the TODO tasks to make the program functional (therefore only the code blocks after the TODO are what I wrote for the task). Example of how the program should behave:

```
$ ./plurality Alice Bob Charlie
Number of voters: 3
Vote: Alice
Vote: Alice
Vote: Bob
Alice
$ ./plurality Alice Bob Charlie
Number of voters: 3
Vote: David
Invalid vote.
Vote: Alice
Vote: Alice
Alice
```

### Runoff

Context: The runoff system. In an instant runoff election, voters can rank as many candidates as they wish. If any candidate has a majority (more than 50%) of the first preference votes, that candidate is declared the winner of the election.

If no candidate has more than 50% of the vote, then an “instant runoff” occurs. The candidate who received the fewest number of votes is eliminated from the election, and anyone who originally chose that candidate as their first preference now has their second preference considered. Why do it this way? Effectively, this simulates what would have happened if the least popular candidate had not been in the election to begin with.

The process repeats: if no candidate has a majority of the votes, the last place candidate is eliminated, and anyone who voted for them will instead vote for their next preference (who hasn’t themselves already been eliminated). Once a candidate has a majority, that candidate is declared the winner.

The task was to implement a runoff program in C.

### Tideman (file added but problem not solved.)
