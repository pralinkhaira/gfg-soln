<h2><a href="https://www.geeksforgeeks.org/problems/remove-invalid-parentheses/1?page=8&difficulty=Hard&sortBy=submissions">Remove Invalid Parentheses</a></h2><h3>Difficulty Level : Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">You are given a string S that&nbsp;contains parentheses and letters. You have to&nbsp;remove the minimum number of invalid parentheses to make the input string valid.</span></p>

<p><span style="font-size:18px">Return <em>all the possible results in the sorted order.</em></span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>S = "()())()"
<strong>Output: </strong>["(())()","()()()"]
</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>S = "(a)())()"
<strong>Output:</strong>&nbsp;["(a())()","(a)()()"]
</span></pre>

<p><span style="font-size:18px"><strong>Example 3:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>S = ")("
<strong>Output: </strong>[""]

</span></pre>

<p><span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function removeInvalidParentheses() which takes the string S as an input parameter&nbsp;and returns an array of strings representing all the valid parentheses that we can form by removing the minimum number of characters from the string.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(2<sup>|S|</sup>)<br>
<strong>Expected Auxiliary Space:</strong> O(1)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= |S| &lt;= 20<br>
S consists of lowercase English letters and parentheses '(' and ')'</span></p>
</div>