<h2><a href="https://www.geeksforgeeks.org/problems/circle-of-strings4530/1?page=2&difficulty=Hard&sortBy=submissions">Circle of strings</a></h2><h3>Difficulty Level : Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an array of lowercase strings <strong>A[] </strong>of size<strong> N</strong>, determine if the strings can be chained together to form a circle.<br>A string <strong>X </strong>can be chained together with another string <strong>Y </strong>if the last character of <strong>X </strong>is same as first character of <strong>Y. </strong>If every string of the array can be chained with exactly two strings of the array(one with the first character and second with the last character of the string), it will form a circle.</span></p>
<p><span style="font-size: 18px;"><strong>For example</strong>, for the array&nbsp;arr[] = {"for", "geek", "rig", "kaf"} the answer will be Yes as the given strings can be chained as&nbsp;"for", "rig", "geek"&nbsp;and "kaf"</span></p>
<p><br><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong>
N = 3
A[] = { "abc", "bcd", "cdf" }
<strong>Output:</strong>
0
<strong>Explaination:</strong>
These strings can't form a circle 
because no string has 'd'at the starting index.</span></pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong>
N = 4
A[] = { "ab" , "bc", "cd", "da" }
<strong>Output:</strong>
1
<strong>Explaination:</strong>
These strings can form a circle 
of strings.</span></pre>
<p><br><span style="font-size: 18px;"><strong>Your Task:</strong><br>You don't need to read input or print output. Your task is to complete the function <strong>isCircle()</strong> which takes the length of the array <strong>N</strong> and the array <strong>A</strong> as input parameters and returns <strong>1</strong> if we can form a circle or <strong>0</strong> if we cannot.</span></p>
<p><br><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(N)<br><strong>Expected Auxiliary Space:</strong> O(N)</span></p>
<p><br><span style="font-size: 18px;"><strong>Constraints:</strong>&nbsp;<br>1 ≤ N ≤ 10<sup>4</sup><br>1 ≤ Length of&nbsp;strings ≤ 20</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Flipkart</code>&nbsp;<code>Accolite</code>&nbsp;<code>Microsoft</code>&nbsp;<code>FactSet</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Graph</code>&nbsp;<code>Data Structures</code>&nbsp;