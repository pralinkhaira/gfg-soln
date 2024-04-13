<h2><a href="https://www.geeksforgeeks.org/problems/count-the-number-of-subarrays/17page=1&difficulty-Hard&sortBy-difficulty">Count the number of subarrays</a></h2><h3>Difficulty Level : Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an array <strong>A[]</strong> of <strong>N</strong>&nbsp;integers and a range<strong>(L</strong>,&nbsp;<strong>R)</strong>.<strong>&nbsp;</strong>The task is to find the number of subarrays having sum in the range L to R (inclusive).</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N = 3, L = 3, R = 8
A[] = {1, 4, 6}
<strong>Output:</strong> 
3
<strong>Explanation: 
</strong>The subarrays are [1,4], [4] and [6]
</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 4, L = 4, R = 13
A[] = {2, 3, 5, 8}
<strong>Output: 
</strong>6
<strong>Explanation: 
</strong>The subarrays are [2,3], [2,3,5], 
[3,5],[5], [5,8] and [8]
</span></pre>

<p><span style="font-size:18px"><strong>Your Task:&nbsp;</strong><br>
You don't need to read input or print anything. Complete the function<strong>&nbsp;countSubarray( )</strong>&nbsp;which takes the integer&nbsp;<strong>N</strong>&nbsp;, the array&nbsp;<strong>A[],</strong>&nbsp;the integer<strong>&nbsp;L</strong>&nbsp;and the integer <strong>R</strong> as input parameters and returns the number of subarays.&nbsp;</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N&nbsp;≤&nbsp;10<sup>6</sup><br>
1 ≤ A[]&nbsp;≤ 10<sup>9</sup><br>
1 ≤ L&nbsp;≤ R&nbsp;≤ 10<sup>15</sup></span></p>
</div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>sliding-window</code>&nbsp;<code>Arrays</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;