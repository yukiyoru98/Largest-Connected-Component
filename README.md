# Largest-Connected-Component
## Problem 
### Source: Bulgarian National Olympiad in Informatics 2003<br />
### Submitter: Ivaylo Riskov
### Description
There is a town with N citizens. It is known that some pairs of people are friends. According to the famous saying that “The friends of my friends are my friends, too” it follows that if A and B are friends and B and C are friends then A and C are friends, too.<br />
Count how many people there are in the largest group of friends.
## Input
Input consists of several datasets.<br />
The first line of the input consists of a line with the number of test cases to follow.<br />
The first line of each dataset contains the numbers N and M, where N is the number of town's citizens (1≤N≤30000) and M is the number of pairs of people (0≤M≤500000), which are known to be friends.<br />
Each of the following M lines consists of two integers A and B (1≤A≤N, 1≤B≤N, A≠B) which describe that A and B are friends. There could be repetitions among the given pairs.<br />
* Sample Input<br />
  >2<br />
3 2<br />
1 2<br />
2 3<br />
10 12<br />
1 2<br />
3 1<br />
3 4<br />
5 4<br />
3 5<br />
4 6<br />
5 2<br />
2 1<br />
7 10<br />
1 2<br />
9 10<br />
8 9<br />
## Output
The output for each test case should contain one number denoting how many people there are in the largest group of friends.
* Sample Output<br />
  >3<br />
6


