<h2><a href="https://www.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1?page=1&status=unsolved&sortBy=submissions">Two sum -Pairs with 0 Sum</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 14pt;">Given an integer array&nbsp;<strong>arr</strong>, return all the&nbsp;<strong>unique&nbsp;</strong>pairs [arr[i], arr[j]] such that<strong>&nbsp;i != j </strong>and<strong> arr[i] + arr[j] == 0.</strong></span></p>
<p><span style="font-size: 14pt;">Note: The pairs must be returned in&nbsp;<strong>sorted&nbsp;</strong>order, the&nbsp;solution array<strong> </strong>should also be&nbsp;<strong>sorted</strong>, and the answer must not contain any&nbsp;<strong>duplicate&nbsp;</strong>pairs.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr = [-1, 0, 1, 2, -1, -4]
<strong>Output: </strong>[[-1, 1]]<strong>
Explanation: </strong>arr[0] + arr[2] = (-1)+ 1 = 0.
arr[2] + arr[4] = 1 + (-1) = 0.
The distinct pair are [-1,1].</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr = [6, 1, 8, 0, 4, -9, -1, -10, -6, -5]
<strong>Output: </strong>[[-6, 6],[-1, 1]]<strong>
Explanation: </strong>The distinct pairs are [-1, 1] and [-6, 6].</span></pre>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(n log n)<br><strong>Expected Auxiliary Space:</strong> O(n).</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:<br></strong>3 &lt;= arr.size &lt;= 10<sup>5</sup><br>-10<sup>5</sup> &lt;= arr[i] &lt;= 10<sup>5</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Flipkart</code>&nbsp;<code>Accolite</code>&nbsp;<code>Amazon</code>&nbsp;<code>FactSet</code>&nbsp;<code>Hike</code>&nbsp;<code>MakeMyTrip</code>&nbsp;<code>Goldman Sachs</code>&nbsp;<code>Adobe</code>&nbsp;<code>Salesforce</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Sorting</code>&nbsp;<code>two-pointer-algorithm</code>&nbsp;