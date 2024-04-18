<h2><a href="https://www.geeksforgeeks.org/problems/sid-and-his-prime-money5736/1?page=9&difficulty=Hard&sortBy=submissions">Sid and his prime money</a></h2><h3>Difficulty Level : Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Sid is a superior salesperson. So he gets a task from his boss. The task is that he will be given some number of products say k (All the products are same) and he has to travel N&nbsp;cities [1...N] to sell them. The main objective of the task is that he has to try to sell the product at higher price than previous city. For example if he sells a product at 100 Rs in one city then he has to try to sell the next product greater than 100 Rs in the next city and so on.<br>
He travels all the cities and write down all the selling amounts. Now He wants to calculate maximum number of cities in which he could follow this increasing trend. And the maximum total prime money he could make in those cities. Help him in&nbsp; finding this.<br>
<strong>Note :</strong> Number of products will always be equal to number of cities. </span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N = 9
A[] = {4, 2, 3, 5, 1, 6, 7, 8, 9}
<strong>Output:</strong>
5 7
<strong>Explanation:</strong>
5 cities are maximum number of 
cities in which the trend 
followed, And  amount in those 
cities were 1, 6, 7, 8, 9. 
Out of  these  amounts only 
7 is prime money.</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N = 10
A[] = {2, 3, 5, 7, 4, 1, 6, 5, 4, 8}
<strong>Output:</strong>
4 17
<strong>Explanation:</strong>
4 cities are maximum number of 
cities in which the trend 
followed, And  amount in those 
cities were 2, 3, 5, 7. 
Out of  these amounts, maximum
total prime money is 2+3+5+7=17.</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 3:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N = 5
A[] = {2, 2, 2, 2, 2}
<strong>Output:</strong>
1 2
<strong>Explanation:</strong>
He was successful in one city 
only, And maximum total prime 
money is 2.
</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function <strong>primeMoney()</strong>&nbsp;which takes the array <strong>A[]</strong> and its size <strong>N </strong>as inputs and returns the maximum number of cities and maximum total prime money as a pair. </span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N. sqrt(N))<br>
<strong>Expected Auxiliary Space:</strong> O(N)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>5</sup><br>
1 ≤ A[i] ≤ 10<sup>5 </sup></span></p>
</div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Mathematical</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;