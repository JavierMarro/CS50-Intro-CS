# CS50: Introduction to Computer Science

This repository contains code created while taking [**CS50 Introduction to Computer Science**](https://pll.harvard.edu/course/cs50-introduction-computer-science) course by Harvard's OpenCourseWare and this is the year 2025 version.
Some programs were fully written by me from scratch (Week 1 and 2), others would have helper functions or would have TODO comments put in place for me to implement the functionality required (Week 3, 4 and 5), and therefore I can, and will, only claim authorship of the code written by me in those TODO blocks.

1. [Week 1 - Intro to C](#set-of-problems-week-1---intro-to-C)
2. [Week 2 - Arrays in C](#set-of-problems-week-2---arrays-in-C)
3. [Week 3 - Algorithms](#set-of-problems-week-3---algorithms)
4. [Week 4 - Memory](#set-of-problems-week-4---memory)
5. [Week 5 - Data Structures](#set-of-problems-week-5---data-structures)

## Set of problems Week 1 - Intro to C

First week of the course covers: Introduction to C with a few simple problems: Hello-World, Hello-It's me, Mario and Credit.
Link to lecture on Youtube: [CS50x 2025 - Lecture 1 - C](https://www.youtube.com/watch?v=89cbCbWrM4U)

- [Mario (less)](https://cs50.harvard.edu/x/2025/psets/1/mario/less/)

The task was to fully implement a program in C that recreates that pyramid, using hashes (#) for bricks, as in the below:

```
           #
          ##
         ###
        ####
```

Re-prompting the user, again and again as needed, if their input is not greater than 0 or not an int altogether.

- [Credit](https://cs50.harvard.edu/x/2025/psets/1/credit/)

The task was to fully implement a program in C that checks the validity of a given credit card number using Luhn’s Algorithm:
Most cards use an algorithm invented by Hans Peter Luhn of IBM. According to Luhn’s algorithm, one can determine if a credit card number is (syntactically) valid as follows:

1. Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
2. Add the sum to the sum of the digits that weren’t multiplied by 2.
3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
4. That’s kind of confusing, so let’s try an example with David’s Visa: 4003600000000014.

So the program prompts the user for a credit card number and then reports (via printf) whether it is a valid American Express, MasterCard, or Visa card number, per the definitions of each’s format herein.

## Set of problems Week 2 - Arrays in C

Looking at compilers, arrays and how some modern methods work under the hood in low level languages like C.
Link to lecture on Youtube: [CS50x 2025 - Lecture 2 - Arrays](https://www.youtube.com/watch?v=Y8qnryVy5sQ)

- [Scrabble](https://cs50.harvard.edu/x/2025/psets/2/scrabble/)

The task was to create a program in C that determines the winner of a short Scrabble-like game. The program prompts for input twice: once for “Player 1” to input their word and once for “Player 2” to input their word. Then, depending on which player scores the most points, the program either prints “Player 1 wins!”, “Player 2 wins!”, or “Tie!” (in the event the two players score equal points). For example:

```
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

- [Readability](https://cs50.harvard.edu/x/2025/psets/2/readability/)

The task was to fully write a program that calculates the approximate grade level needed to comprehend some text. The program prints as output “Grade X” where “X” is the grade level computed, rounded to the nearest integer. If the grade level is 16 or higher (equivalent to or greater than a senior undergraduate reading level), the program outputs “Grade 16+” instead of giving the exact index number. If the grade level is less than 1, the program outputs “Before Grade 1”.

- [Caesar](http://cs50.harvard.edu/x/2025/psets/2/caesar/)

The task was to fully write a program that enables the user to encrypt messages using Caesar’s cipher.
Unencrypted text is generally called plaintext. Encrypted text is generally called ciphertext. And the secret used is called a key.
At the time the user executes the program, they should decide, by providing a command-line argument, what the key should be in the secret message they’ll provide at runtime. We shouldn’t necessarily assume that the user’s key is going to be a number; though you may assume that, if it is a number, it will be a positive integer. Example:

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

Link to lecture on Youtube: [CS50x 2025 - Lecture 3 - Algorithms](https://www.youtube.com/watch?v=iCx3zwK8Ms8)
**This week's lecture explained 4 types of basic algorithms used to sort through data:**

1. **Linear search** iterates across the array from left to right, searching for a specified element.
2. **Selection sort** iterates through the unsorted portions of a list, selecting the smallest element each time and moving it to its correct location.
3. **Bubble sort** compares pairs of adjacent values one at a time and swaps them if they are in the incorrect order. This continues until the list is sorted.
4. **Merge sort** recursively divides the list into two repeatedly and then merges the smaller lists back into a larger one in the correct order.

- [Plurality](https://cs50.harvard.edu/x/2025/psets/3/plurality/)

Context: “plurality vote” (also known as “first-past-the-post” or “winner take all”): every voter gets to vote for one candidate. At the end of the election, whichever candidate has the greatest number of votes is declared the winner of the election.

This task was about **completing the TODO functions** to make the program functional (therefore only the code blocks after the TODO are what I wrote for the task). Example of how the program behaves:

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

- [Runoff](https://cs50.harvard.edu/x/2025/psets/3/runoff/)

Context: The runoff system. In an instant runoff election, voters can rank as many candidates as they wish. If any candidate has a majority (more than 50%) of the first preference votes, that candidate is declared the winner of the election.

If no candidate has more than 50% of the vote, then an “instant runoff” occurs. The candidate who received the fewest number of votes is eliminated from the election, and anyone who originally chose that candidate as their first preference now has their second preference considered. Why do it this way? Effectively, this simulates what would have happened if the least popular candidate had not been in the election to begin with.

The process repeats: if no candidate has a majority of the votes, the last place candidate is eliminated, and anyone who voted for them will instead vote for their next preference (who hasn’t themselves already been eliminated). Once a candidate has a majority, that candidate is declared the winner.

The task was to **complete the TODO functions** of a runoff program in C.

- [Tideman (file added but TODO tasks not completed.)](https://cs50.harvard.edu/x/2025/psets/3/tideman/)

## Set of problems Week 4 - Memory

**This week was spent looking at different concepts like the using pointers (file pointers), defining custom types, dynamic memory allocation, malloc and avoiding leaking memory, call stacks...**
Link to lecture on Youtube: [CS50x 2025 - Lecture 4 - Memory](https://www.youtube.com/watch?v=kcRdFGbzR1I)

- [Filter (less)](https://cs50.harvard.edu/x/2025/psets/4/filter/less/)
  Program written to apply filters (blur, grayscale, sepia, reflection) to BMPs. More detailed information about traversing and modifying images in the link above.

- [Volume](https://cs50.harvard.edu/x/2025/psets/4/volume/)
  TODO tasks completed which allows to modify the volume on an audio file. More detailed information about traversing and modifying wav files in the link above.

- [Recover](https://cs50.harvard.edu/x/2025/psets/4/recover/)
  TODO tasks completed to recover JPEGs from a memory card. More information in the link above.

## Set of problems Week 5 - Data Structures

**Week to explore the use of algorithms traversing through data structures with singly or doubly linked lists, queues, hash tables and tries.**
Link to lecture on Youtube: [CS50x 2025 - Lecture 5 - Data Structures](https://www.youtube.com/watch?v=aV8LlSmd1E8)

Theoretically, on input of size n, an algorithm with a running time of n is “asymptotically equivalent,” in terms of O, to an algorithm with a running time of 2n. When describing the running time of an algorithm, we typically focus on the dominant (i.e., most impactful) term (i.e., n in this case, since n could be much larger than 2). In the real world, though, the fact of the matter is that 2n feels twice as slow as n.

- [Inheritance](https://cs50.harvard.edu/x/2025/psets/5/inheritance/)

Context: A person’s blood type is determined by two alleles (i.e., different forms of a gene). The three possible alleles are A, B, and O, of which each person has two (possibly the same, possibly different). Each of a child’s parents randomly passes one of their two blood type alleles to their child. The possible blood type combinations, then, are: OO, OA, OB, AO, AA, AB, BO, BA, and BB.

For example, if one parent has blood type AO and the other parent has blood type BB, then the child’s possible blood types would be AB and OB, depending on which allele is received from each parent. Similarly, if one parent has blood type AO and the other OB, then the child’s possible blood types would be AO, OB, AB, and OO.

The task was to simulate the inheritance of blood types for each member of a family **completing the TODO tasks** in a program in C.

- [Speller](https://cs50.harvard.edu/x/2025/psets/5/speller/)

This assignment had very **defined TODO tasks** for me to complete in a file called dictionary.c.
The challenge was to implement, in order: load, hash, size, check, and unload as efficiently as possible using a hash table in such a way that TIME IN load, TIME IN check, TIME IN size, and TIME IN unload are all minimized. To be sure, it’s not obvious what it even means to be minimized, inasmuch as these benchmarks will certainly vary as you feed speller different values for dictionary and for text. But therein lies the challenge, if not the fun, of this problem.
Quote from the task: "This problem is your chance to design. Although we invite you to minimize space, your ultimate enemy is time."

## Set of problems Week 9 - Flask

**Week to explore the use of the framework Flask (based on Python) combined with web programming (HTML & CSS) to create web apps.**
Link to lecture on Youtube: [CS50x 2025 - Lecture 9 - Flask](https://www.youtube.com/watch?v=1r-dFbPQ7Z8)

- [Birthdays](https://cs50.harvard.edu/x/psets/9/birthdays/)

The task was to create a web application to keep track of friends’ birthdays by **completing the TODO tasks** unifying the code produced in several files.

The TODO tasks involved html manipulation, creating a form for users to submit and adding a loop that would fetch the data from the database. The SQLite database with all birthdays hasn't been uploaded to this repo.

The app.py contained the start of a Flask web application. The application has one route (/) that accepts both POST requests (after the if) and GET requests (after the else). The TODO tasks involved fetching, inserting new data, and displaying the data from the db.

- [Finance](https://cs50.harvard.edu/x/psets/9/finance/)

This assignment had very **defined and extensive TODO tasks** for me to complete in a file called app.py, and all code produced within those endpoints was my solution to the task:

```py
@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    return apology("TODO")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    return apology("TODO")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
```

The challenge was to implement, in order: register, quote, sell endpoints for C$50 Finance, a web app via which you can manage portfolios of stocks. Not only will this tool allow the user to check real stocks’ prices and portfolios’ values, it will also let the user “buy” and “sell” stocks by querying for stocks’ prices.

Context regarding the code that was given by CS50:
After configuring Flask, notice how this file disables caching of responses (provided you’re in debugging mode, which you are by default in your code50 codespace), lest you make a change to some file but your browser not notice. Notice next how it configures Jinja with a custom “filter,” usd, a function (defined in helpers.py) that will make it easier to format values as US dollars (USD). It then further configures Flask to store sessions on the local filesystem (i.e., disk) as opposed to storing them inside of (digitally signed) cookies, which is Flask’s default. The file then configures CS50’s SQL module to use finance.db.

Thereafter are a whole bunch of routes, only two of which are fully implemented: login and logout. Read through the implementation of login first. Notice how it uses db.execute (from CS50’s library) to query finance.db. And notice how it uses check_password_hash to compare hashes of users’ passwords. Also notice how login “remembers” that a user is logged in by storing his or her user_id, an INTEGER, in session. That way, any of this file’s routes can check which user, if any, is logged in. Finally, notice how once the user has successfully logged in, login will redirect to "/", taking the user to their home page. Meanwhile, notice how logout simply clears session, effectively logging a user out.

Notice how most routes are “decorated” with @login_required (a function defined in helpers.py too). That decorator ensures that, if a user tries to visit any of those routes, he or she will first be redirected to login so as to log in.

Notice too how most routes support GET and POST. Even so, most of them (for now!) simply return an “apology,” since they’re not yet implemented.

## Certificate of completion

![Javier Martinez Romera CS50 Certificate](https://i.ibb.co/VYNYn5BX/CS50x-JMR-A4.png "CS50: Introduction to Computer Science Certificate")
