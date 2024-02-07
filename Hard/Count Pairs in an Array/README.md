<h2><a href="https://www.geeksforgeeks.org/problems/count-pairs-in-an-array4145/1?page=5&difficulty=Hard&sortBy=submissions">Count Pairs in an Array</a></h2><h3>Difficulty Level : Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an array of integers arr[0..n-1], count all pairs (<strong>arr[i]</strong>,<strong> arr[j]</strong>) in it&nbsp;such that <strong>i*arr[i]</strong> &gt; <strong>j*arr[j]</strong>,<br>
and <strong>0 ≤ i &lt; j &lt; n</strong>.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input :</strong>
arr[] = {5, 0, 10, 2, 4, 1, 6}
<strong>Output :</strong>
5
<strong>Explanation :</strong>
Pairs which hold condition i*arr[i] &gt; j*arr[j] are
(10, 2) (10, 4) (10, 1) (2, 1) (4, 1)</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input :</strong>
arr[] = {8, 4, 2, 1}
<strong>Output :</strong>
2</span>
</pre>

<p>&nbsp;</p>

<p><br>
<span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>countPairs()</strong>&nbsp;which takes the array <strong>A[]</strong> and its size <strong>N</strong><strong> </strong>as inputs and returns the required result.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity: </strong>O(N. log(N))<br>
<strong>Expected Auxiliary Space: </strong>O(N. log(N))</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1<strong> ≤</strong> N <strong>≤ </strong>10<sup>5</sup><br>
1 <strong>≤ </strong>A[ ] <strong>≤ </strong>10<sup>3</sup></span></p>

<p>&nbsp;</p>

<p>&nbsp;</p>
</div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Data Structures</code>&nbsp;