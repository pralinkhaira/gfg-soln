<h2><a href="https://www.geeksforgeeks.org/problems/combination-sum-iii--111703/1">Unique K-Number Sum</a></h2>
<h3>Difficulty Level : Medium</h3>
<hr>
<div class="problems_problem_content__Xm_eO">
<p><span style="font-size: 18px;">Given two integers <strong>n</strong> and <strong>k</strong>, the task is to find all valid combinations of <strong>k</strong> numbers that add up to <strong>n</strong> based on the following conditions:</span></p>

<p><span style="font-size: 18px;"><strong>1.</strong>&nbsp; Only numbers from the range [1, 9] are used.<br></span>
<span style="font-size: 18px;"><strong>2.</strong>&nbsp; Each number can only be used at most once.<br></span>
<span style="font-size: 18px;">Note: You can return the combinations in any order, the driver code will print them in sorted order.</span></p>

<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>

<pre><span style="font-size: 18px;"><strong>Input: </strong>n = 9, k = 3
<strong>Output: </strong>[[1, 2, 6], [1, 3, 5], [2, 3, 4]]
<strong>Explanation: </strong>There are three valid combinations of 3 numbers that sum to 9: 
[1 ,2, 6], [1, 3, 5] and [2, 3, 4].</span></pre>

<pre><span style="font-size: 18px;"><strong>Input: </strong>n = 3, k = 3
<strong>Output: </strong>[]
<strong>Explanation: </strong>It is not possible to pick 3 distinct numbers from 1 to 9 that sum to 3.</span></pre>

<p><span style="font-size: 18px;"><strong>Expected Time Complexity:&nbsp;</strong>O(2<sup>9</sup>)<br>
<strong>Expected Space Complexity:&nbsp;</strong>O(k)<br><br>
<strong>Constraints:<br></strong>1 ≤ n ≤ 50<br>1 ≤ k ≤ 9</span></p>
</div>
<br>
<p><span style=font-size:18px><strong>Topic Tags : </strong><br>
<code>Backtracking</code>&nbsp;<code>Recursion</code>&nbsp;<code>Algorithms</code></span></p>
