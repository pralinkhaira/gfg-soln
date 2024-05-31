<h2><a href="https://www.geeksforgeeks.org/problems/help-nobita0532/1">Odd Even Problem</a></h2><h3>Difficulty Level : Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a string <strong>s</strong>&nbsp;of&nbsp;<strong>lowercase English </strong>characters, find out whether the summation of <strong>x</strong> and&nbsp;<strong>y</strong>&nbsp;is<strong>&nbsp;<em>even</em>&nbsp;</strong>or<strong>&nbsp;<em>odd</em></strong>, where <strong><em>x</em></strong> is the count of distinct characters that occupy&nbsp;<strong>even </strong>positions in English alphabets and have <strong>even </strong>frequency, <strong><em>y</em></strong>&nbsp;is the count of distinct characters which occupy&nbsp;<strong>odd </strong>positions in English alphabets and have <strong>odd </strong>frequency.<br><strong>Note</strong>: Positive means greater than zero.</span></p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: <br></strong>s = "abbbcc"
<strong>Output:</strong> <br>ODD
<strong>Explanation: <br></strong>x = 0 and y = 1 so (x + y) is ODD. 'a' occupies 1st place(odd) in english alphabets and its frequency is odd(1), 'b' occupies 2nd place(even) but its frequency is odd(3) so it doesn't get counted and 'c' occupies 3rd place(odd) but its frequency is even(2) so it also doesn't get counted.
</span></pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: <br></strong>s = "nobitaa"
<strong>Output:</strong> <br>EVEN
<strong>Explanation:</strong>&nbsp;<br>x = 0 and y = 2 so (x + y) is EVEN.
</span></pre>
<p><span style="font-size: 18px;"><strong>Your Task: &nbsp;</strong><br>You don't need to read input or print anything. Complete the function <strong>evenOdd()&nbsp;</strong>which takes s as input parameter and returns "EVEN"&nbsp; if&nbsp; x + y is even, and returns "ODD" otherwise.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:&nbsp;</strong>O(|s|)<br><strong>Expected Auxiliary Space:&nbsp;</strong>O(1)&nbsp;</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ |s| ≤ 10<sup>5</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Hash</code>&nbsp;<code>Strings</code>&nbsp;<code>Bit Magic</code>&nbsp;<code>Data Structures</code>&nbsp;