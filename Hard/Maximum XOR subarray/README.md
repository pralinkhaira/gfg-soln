<h2><a href="https://www.geeksforgeeks.org/problems/maximum-xor-subarray--141631/1?page=4&difficulty=Hard&sortBy=submissions">Maximum XOR subarray</a></h2><h3>Difficulty Level : Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an array <strong>arr[]&nbsp;</strong>of size,&nbsp;<strong>N.</strong>&nbsp;Find the subarray with maximum XOR</span>. <span style="font-size: 18px;">A subarray is a contiguous part of the array.</span></p>
<p><br><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input</strong></span>:
<span style="font-size: 18px;">N = 4
arr[] = {1,2,3,4}
<strong>Output:</strong>&nbsp;7
<strong>Explanation</strong>: 
The subarray {3,4} has maximum xor 
value equal to 7.<br><br></span></pre>
<p style="font-family: sans-serif; font-size: medium; white-space: normal;"><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input</strong>:
N = 3
arr[] = {1,4,3}
<strong>Output:</strong>&nbsp;7
<strong>Explanation</strong>: 
 There are 6 possible subarrays:
 subarray            XOR value
 [1]                     1
 [4]                     4
 [3]                     3
 [1, 4]                  5 (1^4)
 [4, 3]                  7 (4^3)
 [1, 4, 3]               6 (1^4^3)

 [4, 3] subarray has maximum XOR value. So, return 7.</span></pre>
<p><span style="font-size: 18px;"><strong>Your Task:&nbsp;&nbsp;</strong><br>You don't need to read input or print anything. Your task is to complete the function <strong>maxSubarrayXOR()</strong>&nbsp;which takes the array arr[], its size N<strong> </strong>as input parameters&nbsp;and returns the maximum xor of any subarray.</span><br>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(N)<br><strong>Expected Auxiliary Space:</strong> O(N)</span><br><br>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= N &lt;= 10<sup>5</sup></span><br><span style="font-size: 18px;">1<sup> </sup>&lt;= arr[i] &lt;= 10<sup>5</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Microsoft</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Trie</code>&nbsp;<code>Advanced Data Structure</code>&nbsp;